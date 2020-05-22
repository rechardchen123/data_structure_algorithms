#include <iostream>
#include <string>

using namespace std;

template <class T> //声明一个类模板，虚拟类型名为T
class SequenceList
{

private:
    T *eles; //存储元素的数组的地址
    int N;   //记录当前顺序表中的元素个数

public:
    SequenceList(int capacity)
    {
        //初始化数组
        eles = new T[capacity];
        //初始化长度
        N = 0;
    }
    //将一个线性表置为空表
    void clear()
    {
        N = 0;
    }

    void travelSequenceList()
    {
        for (int i = 0; i < N; i++)
        {
            cout << "The number " << i + 1 << " value is:" << eles[i] << endl;
        }
    }

    //判断当前线性表是否为空表
    bool isEmpty()
    {

        return N == 0;
    }

    //获取线性表的长度
    int length()
    {
        return N;
    }

    //获取指定位置的元素
    T get(int i)
    {
        return eles[i];
    }

    //向线性表中添加元素T
    void insert(T t)
    {
        eles[N++] = t;
    }

    //在i元素处插入元素t
    void insert(int i, T t)
    {
        //先把i索引处的元素及其后面的元素依次向后移动一位
        for (int index = N - 1; index > i; index--)
        {
            eles[index] = eles[index - 1];
        }

        //再把t插入i处
        eles[i] = t;
    }

    //删除指定位置i处的元素，并返回该元素/
    T remove(int i)
    {
        //记录索引i处的值
        T current = eles[i];
        //让索引i后面的元素依次向前移动一位
        for (int index = i; index < N - 1; index++)
        {
            eles[index] = eles[index + 1];
        }
        //元素个数-1
        N--;
        return current;
    }

    //查找t元素处第一次出现的位置
    int indexOf(T t)
    {
        for (int i = 0; i < N; i++)
        {
            if (eles[i] == t)
            {
                return i;
            }
        }
        return -1;
    }

    //数组扩容, 根据参数newSize,重置eles的大小
    void resize(int newSize)
    {
        //定义一个临时数组，指向原数组
        T temp[] = eles;
        //创建新数组
        eles = new T[newSize];
        //把原数组的内容拷贝到新数组
        for (int i = 0; i < N; i++)
        {
            eles[i] = temp[i];
        }
    }
};

int main()
{
    //创建顺序表对象
    SequenceList<string> s1(3);

    //测试插入
    s1.insert("k1");
    s1.insert("k2");
    s1.insert("k3");
    s1.insert(1, "k4");
    cout << "The reuslt of insert:" << s1.get(1) << endl;

    s1.travelSequenceList();

    //测试删除
    string results = s1.remove(0);
    cout << "the reuslt after removing:" << results << endl;

    //测试清空
    s1.clear();
    cout << "the clear results:" << s1.length() << endl;
    return 0;
}