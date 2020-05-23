#ifndef __LINKLIST_H__
#define __LINKLIST_H__

#include "singlelist_1.h"
#include <iostream>

//LinkList 类用于维护链表
template <typename T>
class LinkList : public List<T>
{
protected:
    struct Node_t //链表中数据成员的类型定义
    {
        T value;
        Node_t *next;
    };

    mutable struct
    { //定义头结点，方便链表操作
        char reserved[sizeof(T)];
        Node_t *next;
    } m_header;

    int m_length;
    int m_step;        //链表移动的步长
    Node_t *m_current; //当前链表指向的链表结点，相当于游标和迭代器

    Node_t *position(int i) const //返回目标结点的位置
    {
        Node_t *ret = reinterpret_cast<Node_t *>(&m_header);
        for (int p = 0; p < i; p++)
        {
            ret = ret->next;
        }
        return ret;
    }

    virtual Node_t *CreateNode()
    {
        return new Node_t;
    }

    virtual void DestoryNode(Node_t *pn)
    {
        delete pn;
    }

public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
        m_step = 1;
        m_current = NULL;
    }

    bool insert(int i, const T &e)
    {
        bool ret = ((i > 0) && (i <= m_length));
        if (ret)
        {
            Node_t *node = CreateNode();
            if (node)
            {
                //定位到目标位置后
                Node_t *cur = position(i);

                node->value = e;
                node->next = cur->next;
                cur->next = node;

                ++m_length;
            }
        }
        else
        {
            throw(std::out_of_range("LinkList::insert():i of range"));
        }

        return ret;
    }

    bool insert(const T &e)
    {
        return insert(m_length, e);
    }

    bool remove(int i)
    { //删除结点
        bool ret = ((0 <= i) && (i <= m_length));
        if (ret)
        {
            Node_t *cur = position(i);
            Node_t *del = cur->next;
            cur->next = del->next;
            --m_length;
            DestoryNode(del);
        }
        return ret;
    }

    bool set(int i, const T &e)
    {
        bool ret = ((0 <= i) && (i <= m_length));
        if (ret)
        {
            position(i)->next->value = e;
        }
        return ret;
    }

    bool get(int i, T &e) const
    {
        bool ret = ((0 <= i) && (i <= m_length));
        if (ret)
        {
            e = position(i)->next->value;
        }
        return ret;
    }

    T get(int i) const
    {
        T ret;
        if (get(i, ret))
            return ret;
        else
            throw(std::out_of_range("LinkList::get(i):i of range."));
    }

    int find(const T &e) const
    {
        int ret = -1;
        int i = 0;
        Node_t *node = m_header.next;
        while (node)
        {
            if (node->value == e)
            {
                ret = i;
                break;
            }
            else
            {
                node = node->next;
                ++i;
            }
        }
        return ret;
    }

    int length() const
    {
        return m_length;
    }

    void clear()
    {
        while (m_header.next)
        {
            Node_t *del = m_header.next;
            m_header.next = del->next;
            --m_length;
            DestoryNode(del);
        }
    }

    int move(int i, int step = 1)
    {
        bool ret = ((0 <= i) && (i < m_length) && (step > 0));
        if (ret)
        {
            m_current = position(i)->next;
            m_step = step;
        }
        return ret;
    }

    bool end()
    {
        return m_current == NULL;
    }

    T current()
    {
        if (!end())
            return m_current->value;
        else
            throw(std::out_of_range("LinkList::current()"));
    }

    bool next()
    {
        int i = 0;
        while ((i < m_step) && !end())
        {
            m_current = m_current->next;
            ++i;
        }
        return i == m_step;
    }

    ~LinkList()
    {
        printf("~LinkList()\n");
        clear();
    }
};

#endif /*__LINKLIST_H__*/
