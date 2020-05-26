#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
class TwoWayLinkList
{
private:
    Node<T> *head; //记录首节点
    Node<T> *last; //记录尾结点
    int N;         //链表长度

public:
    TwoWayLinkList();

    void clear();

    int length();

    bool isEmpty();

    T getFirst(); //获取第一个元素

    T getLast();

    void insert(T t);

    void insert(int i, T t);

    T get(int i);

    void remove(int i);

    int indexOf(T t);

    ~TwoWayLinkList();
};

template <typename T>
TwoWayLinkList<T>::TwoWayLinkList()
{
    //初始化头结点和尾结点
    head = NULL;
    last = NULL;
    //初始化元素个数
    N = 0;
}

template <typename T>
TwoWayLinkList<T>::~TwoWayLinkList()
{
    Node<T> *cur = head;
    while (cur != NULL)
    {
        Node<T> *next = cur->next;
        delete cur;
        cur = next;
        if (cur ! = NULL)
        {
            next = next->next;
        }
        else
        {
            break;
        }
    }
}

template <typename T>
void TwoWayLinkList<T>::clear()
{
    head->next = NULL;
    last = NULL;
    N = 0;
}

template <typename T>
int TwoWayLinkList<T>::length()
{
    return N;
}

template <typename T>
bool TwoWayLinkList<T>::isEmpty()
{
    return N == 0;
}

template <typename T>
T TwoWayLinkList<T>::getFirst()
{
    if (isEmpty())
    {
        return NULL;
    }
    else
    {
        return head->next->data;
    }
}

template <typename T>
T TwoWayLinkList<T>::getLast()
{
    if (isEmpty())
        return NULL;
    else
    {
        return last->data;
    }
}

template <typename T>
void TwoWayLinkList<T>::insert(T t)
{
    //链表为空
    if (isEmpty())
    {
        //创建新结点
        Node<T> *newNode = new Node<T>;
        newNode->data = t;
        newNode->prev = head;
        newNode->next = NULL;

        //让新结点称为尾结点
        last = newNode;

        //让头结点指向尾结点
        head->next = last;
    }
    //如果链表不为空
    else
    {
        Node<T> *oldlast = last;
        Node<T> *newNode = new Node<T>;
        newNode->data = t;
        newNode->prev = oldlast;
        newNode->next = NULL;

        oldlast->next = newNode;
        last = newNode;
    }
    N++;
}

template <typename T>
void TwoWayLinkList<T>::insert(int i, T t)
{
    //找到i位置的前一个结点
    Node<T> *pre = head;
    for (int index = 0; index < i; index++)
    {
        pre = pre->next;
    }

    //找到i位置的结点
    Node<T> *curr = pre->next;

    //创建新结点
    Node<T> *newNode = new Node<T>;
    newNode->data = t;
    newNode->prev = pre;
    newNode->next = curr;

    //让i位置的前一个结点的下一个节点变为新结点
    pre->next = newNode;

    //让㩻的前一个结点变为新结点
    curr->next = newNode;

    //元素加1
    N++;
}

template <typename T>
T TwoWayLinkList<T>::get(int i)
{
    Node<T> *n = head->next;
    for (int index = 0; index < i; index++)
    {
        n = n->next;
    }
    return n->data;
}

template <typename T>
int TwoWayLinkList<T>::indexOf(T t)
{
    Node<T> *n = head;
    for (int i = 0; n->next != NULL; i++)
    {
        n = n->next;
        if (n->next == t)
        {
            return i;
        }
    }
    return -1;
}

template <typename T>
void TwoWayLinkList<T>::remove(int i)
{
    //找到i位置的前一个结点
    Node<T> *pre = head;
    for (int index = 0; index < i; index++)
    {
        pre = pre->next;
    }

    //找到i位置的结点
    Node<T> *curr = pre->next;
    //找到i位置的下一个结点
    Node<T> *nextNode = curr->next;

    //让i位置的前一个结点的下一个结点变成i位置的下一个结点
    pre->next = nextNode;
    //让i位置的下一个结点的上一个几点变为i位置的前一个结点
    nextNode->prev = pre;

    //元素个数--
    N--;
    return curr->data;
}
