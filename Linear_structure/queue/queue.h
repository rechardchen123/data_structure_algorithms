#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T, int num>
class Queue
{

private:
    T arr[num];
    int front;
    int rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }

    bool isEmpty();

    bool isFull();

    bool push(const T &); //进队列

    bool pop(T &); //出队列
};

template <typename T, int num>
bool Queue<T, num>::isEmpty()
{
    return front == rear;
}

template <typename T, int num>
bool Queue<T, num>::isFull()
{
    return front == num;
}

template <typename T, int num> //进队列 判断队列是否满
bool Queue<T, num>::push(const T &a)
{
    if (isFull())
        return false;

    arr[front] = a;
    ++front;
    return true;
}

template <typename T, int num>
bool Queue<T, num>::pop(T &b)
{
    if (isEmpty())
        return false;

    b = arr[rear];
    ++rear;
    return true;
}

#endif