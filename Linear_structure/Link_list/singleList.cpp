#include <iostream>

using namespace std;

template <typename T>
class SingleLink {
 private:
  class Node {
   public:
    T item;      //存储数据
    Node *next;  // Node的next指针
  };

  Node *head;  //记录头结点
  int N;       //记录链表的长度

 public:
  //初始化构造函数
  SingleLink() {
    //初始化头结点
    head = new Node;
    head->item = 0;
    head->next = NULL;
    //初始化元素个数
    N = 0;
  }
  ~SingleLink() { delete head; };

  //清空链表
  void clear() {
    head->next = NULL;
    N = 0;
  }

  //获取链表的长度
  int length() { return N; }

  //判断链表是否为空
  bool isEmpty() { return N == 0; }

  //获取指定位置i处的元素
  T get(int i) {
    //通过循环从头结点开始往后找，依次找i次
    Node *n = head->next;

    for (int index = 0; index < i; index++) {
      n = n->next;
    }

    return n.item;
  }

  //向链表中添加元素t
  void insert(T t) {
    //找到当前最后的一个结点
    Node *n = head;

    while (n->next != NULL) {
      n = n->next;
    }

    //创建新结点保存元素T
    Node *newNode;
    newNode = new Node;
    newNode.item = t;
    newNode->next = NULL;

    //让当前最后一个结点指向新结点
    n->next = newNode;

    //元素的个数加1
    N++;
  }

  //向指定位置i处添加元素t
  void insert(int i, T t) {
    //找到i之前的一个结点
    Node *pre = head;

    for (int index = 0; index <= i - 1; index++) {
      pre = pre->next;
    }

    //找到i位置的 结点
    Node *curr = pre->next;

    //创建新结点，并新结点需要指向原来i位置的结点
    Node *newNode;
    newNode = new Node;
    newNode->item = t;
    newNode->next = curr;

    //原来i位置的前一个结点指向新结点即可。
    pre->next = newNode;

    N++;
  }

  //删除指定位置i处的元素，并返回被删除的元素
  T remove(int i) {
    //找到i位置的前一个结点
    Node *pre = head;

    for (int index = 0; index <= i - 1; index++) {
      pre = pre->next;
    }
    //找到i位置的结点
    Node *curr = pre->next;

    //找到i位置的下一个结点
    Node *nextNode = curr->next;

    //前一个结点指向下一个结点
    pre->next = nextNode;
    //元素个数-1
    N--;

    return curr.item;
  }

  //查找元素t在链表中第一次出现的位置
  int indexOf(T t) {
    //遍历链表依次找到每一个结点，取出item和t 比较，如果相同 则找到
    Node *n = head;

    for (int i = 0; n->next != NULL; i++) {
      n = n->next;

      if (n.item == t) {
        return i;
      }
    }

    return -1;
  }
};

int main() {
    
  return 0;
}