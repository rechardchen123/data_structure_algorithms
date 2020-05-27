#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include <queue>
#include <stdlib.h>

using namespace std;

//二叉树的树节点的定义
template <class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *leftChild;
    TreeNode<T> *rightChild;
    TreeNode()
    {
        leftChild = NULL;
        rightChild = NULL;
    }
};

//二叉树这个类的详细定义
template <class T>
class BinaryTree
{
public:
    TreeNode<T> *root; //得到根节点

    //二叉树的操作
public:
    //前序遍历
    void PreOrder();
    void PreOrder(TreeNode<T> *currentNode); //函数重载

    //中序遍历
    void InOrder();
    void InOrder(TreeNode<T> *currentNode);

    //后续遍历
    void PostOrder();
    void PostOrder(TreeNode<T> *currentNode);

    //层序遍历
    void LevelOrder();
    void LevelOrder(TreeNode<T> *currentNode);

    //读取结点
    void Visit(TreeNode<T> *currentNode);
}

template <class T>
void BinaryTree<T>::Visit(TreeNode<T> *currentNode)
{
    std::cout << currentNode->data;
}

//前序遍历的实现
template <class T>
void BinaryTree<T>::PreOrder()
{
    PreOrder(root);
}

template <class T>
void BinaryTre<T>::PreOrder(TreeNode<T> *currentNode)
{
    if (currentNode)
    {
        //显示当前结点
        Visit(currentNode);

        //然后访问左节点
        preOrder(currentNode->lefChild);

        //访问右边的结点
        PreOrder(currentNode->rightChild);
    }
}

//中序遍历
template <class T>
void BinaryTree<T>::InOrder()
{
    InOrder(root);
}

template <class T>
void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)
{
    if (currentNode)
    {
        InOrder(currentNode->leftChild);
        Visit(currentNode);

        InOrder(currentNode->rightChild);
    }
}

//后序遍历
template <class T>
void BinaryTree<T>::PostOrder()
{
    PostOrder(root);
}

template <class T>
void BinaryTree<T>::PostOrder(TreeNode<T> *currentNode)
{
    if (currentNode)
    {
        PostOrder(currentNode->leftChild);
        PostOrder(currentNode->rightChild);

        Visit(currentNode);
    }
}

//层序遍历
template <class T>
void BinaryTree<T>::LevelOrder()
{
    std::queue<TreeNode<T> *> q;
    TreeNode<T> *currentNode = root;

    while (currentNode)
    {
        Visit(currentNode);
        if (currentNode->leftChild)
            q.push(currentNode->leftChild);

        if (currentNode->rightChild)
            q.push(currentNode->rightChild);

        if (q.empty())
            return;

        currentNode = q.front();

        q.pop();
    }
}

#endif