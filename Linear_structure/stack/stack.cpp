#include <iostream>
#include "stack.h"
#include "Coordinate.h"

using namespace std;

int main()
{
    MyStack<Coordinate> *pStack = new MyStack<Coordinate>(5);

    pStack->push(Coordinate(3, 5));
    pStack->push(Coordinate(7, 5));
    pStack->push(Coordinate(6, 5));
    pStack->push(Coordinate(4, 5));
    pStack->push(Coordinate(3, 5));

    pStack->stackTranverse(); //遍历栈

    Coordinate t;
    pStack->pop(t);
    cout << "弹出的t为：" << t;
    cout << "长度：" << pStack->stackLength();
    pStack->clearStack(); //清空栈
    pStack->stackTranverse();

    system("pause");
    return 0;
}