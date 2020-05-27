#include <iostream>
#include "binaryTree.h"

using namespace std;

int main()
{
    //1.先声明二叉树，二叉树里面放的是字符变量；
    BinaryTree<char> tree;

    //2.定义树的节点；
    TreeNode<char> '加', '减', '乘', '除', a, b, c, d, e;
    加.data = '+';
    减.data = '-';
    乘.data = '*';
    除.data = '/';
    a.data = 'A';
    b.data = 'B';
    c.data = 'C';
    d.data = 'D';
    e.data = 'E';

    tree.root = &加;
    加.leftChild = &减;
    加.rightChild = &e;
    减.leftChild = &乘;
    减.rightChild = &d;
    乘.leftChild = &除;
    乘.rightChild = &c;
    除.leftChild = &a;
    除.rightChild = &b;

    cout << "前序遍历:";
    tree.PreOrder(); //前序遍历
    cout << endl;

    cout << "中序遍历:";
    tree.InOrder(); //中序遍历
    cout << endl;

    cout << "后序遍历:";
    tree.PostOrder(); //后序遍历
    cout << endl;

    cout << "层序遍历:";
    tree.LevelOrder(); //层序遍历
    cout << endl;

    system("pause");
    return 0;
}