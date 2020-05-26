#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

//构造结点数量为n的单向循环链表
Node *node_create(int n)
{
    Node *pRet = NULL;

    if (n != 0)
    {
        int n_idx = 1;
        Node *p_node = NULL;

        //构造n个结点
        p_node = new Node[n];
        if (p_node == NULL)
            return NULL;

        pRet = p_node;

        while (n_idx < n)
        { //构造循环链表
            //出书画链表的每个结点从1到n
            p_node->data = n_idx;
            p_node->next = p_node + 1;
            p_node = p_node->next;
            n_idx++;
        }

        p_node->data = n;
        p_node->next = pRet;
    }
    
    return pRet;
}

int main()
{
    Node *pList = NULL;
    Node *pIter = NULL;
    int n = 20; //设置总人数为20
    int m = 6;  //初始报数的上限值

    pList = node_create(n);

    //约瑟夫循环取数
    pIter = pList;

    m %= n;
    while (pIter != pIter->next)
    {
        for (int i = 1; i < m - 1; i++)
        {
            pIter = pIter->next;
        }

        cout << pIter->next->data << " ";

        //删除第m个节点
        pIter->next = pIter->next->next;
        pIter = pIter->next;
    }
    cout << pIter->data << endl;

    delete[] pList;

    return 0;
}