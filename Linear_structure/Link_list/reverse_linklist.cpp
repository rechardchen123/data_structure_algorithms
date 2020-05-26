#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

void Display(Node *head)
{
    if (head == NULL)
    {
        cout << "the list is empty." << endl;
        return;
    }
    else
    {
        Node *p = head;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
    }
    cout << endl;
}

Node *ReverseList(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *cur = head;
    Node *pre = NULL;
    Node *nex = NULL;
    while (cur->next != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }

    cur->next = pre;
    return cur;
}

//创建链表

Node *Init(int num)
{
    if (num <= 0)
        return NULL;

    Node *cur = NULL;
    Node *head = NULL;
    Node *node = new Node;
    node->data = 1;
    head = cur = node;
    for (int i = 1; i < num; i++)
    {
        Node *node = new Node;
        node->data = i + 1;
        cur->next = node;
        cur = node;
    }
    cur->next = NULL;
    return head;
}

int main()
{
    Node *list = NULL;
    list = Init(10);
    Display(list);
    Node *newList = ReverseList(list);
    Display(newList);

    system("pause");
    return 0;
}