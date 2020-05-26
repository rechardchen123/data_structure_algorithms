#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue<int, 7> q;
    cout << "刚开始队列空吗?  " << q.isEmpty() << endl;
    q.push(6);
    q.push(10);
    cout << "现在还是队列空吗?  " << q.isFull() << endl;

    int b1, b2;
    q.pop(b1);
    q.pop(b2);
    cout << "队列中第一个删除的元素为:  " << b1 << endl;
    cout << "队列中第二个删除的元素为:  " << b2 << endl;

    return 0;
}