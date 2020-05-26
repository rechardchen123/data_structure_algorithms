#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template <typename T>
class MyStack
{
public:
    MyStack(int size);
    ~MyStack();

    bool stackEmpty(); //判断栈是否为空

    bool stackFull(); //判断栈是否为满

    void clearStack(); //清空

    int stackLength(); //长度

    bool push(T elem); //压栈

    bool pop(T &elem); //弹栈

    bool stackTop(T &elem); //返回栈顶

    void stackTranverse(); //遍历栈

private:
    T *m_pStack; //栈顶指针
    int m_iSize; //栈的容量
    int m_iTop;  //栈顶
};

template <typename T>
MyStack<T>::MyStack(int size)
{
    m_iSize = size;
    m_pStack = new T[m_iSize];
    m_iTop = 0;
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete m_pStack;
    m_pStack = NULL;
}

template <typename T>
bool MyStack<T>::stackEmpty()
{
    return m_iTop == 0 ? true : false;
}

template <typename T>
bool MyStack<T>::stackFull()
{
    return m_iTop == m_iSize ? true : false;
}

template <typename T>
int MyStack<T>::stackLength()
{
    return m_iTop;
}

template <typename T>
void MyStack<T>::clearStack()
{
    m_iTop = 0;
}

template <typename T>
bool MyStack<T>::push(T elem)
{
    if (stackFull())
        return false;

    m_pStack[m_iTop++] = elem;
    return true;
}

template <typename T>
bool MyStack<T>::pop(T &elem)
{
    if (stackEmpty())
        return false;

    elem = m_pStack[--m_iTop];
    return true;
}

template <typename T>
bool MyStack<T>::stackTop(T &elem)
{
    if (stackEmpty())
        return false;

    elem = m_pStack[m_iTop - 1];
    return true;
}

template <typename T>
void MyStack<T>::stackTranverse()
{
    int i = 0;
    for (i = 0; i < m_iTop; i++)
    {
        cout << m_pStack[i];
    }
}

#endif