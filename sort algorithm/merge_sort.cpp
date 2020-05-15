#include <iostream>
#include <vector>

using namespace std;

void Merge(std::vector<int> &a, int lo, int mid, int hi)
{
    //定义一个辅助数组
    int *assist = new int(a.size());
    int i = lo;
    int p1 = lo;
    int p2 = mid + 1;
    //遍历，移动p1指针和p2指针，找到小的值放到辅助数组中
    while (p1 <= mid && p2 <= hi)
    {
        if (a[p1] - a[p2] < 0)
        {
            assist[i++] = a[p1++];
        }
        else
        {
            assist[i++] = a[p2++];
        }
    }
    //遍历,如果p1的指针没走完，那么顺序移动p1指针，把对应元素放到辅助数组的对应索引处
    while (p1 <= mid)
    {
        assist[i++] = a[p1++];
    }
    //遍历,如果p2的指针没走完，那么顺序移动p1指针，把对应元素放到辅助数组的对应索引处
    while (p2 <= hi)
    {
        assist[i++] = a[p2++];
    }
    //把辅助数组中的元素拷贝到原数组中
    for (int index = lo; index <= hi; index++)
    {
        a[index] = assist[index];
    }
}

void Sort_1(std::vector<int> &a, int lo, int hi)
{
    //安全校验
    if (hi <= lo)
        return;
    //对lo和hi之间的数组进行分组
    int mid = lo + (hi - lo) / 2;
    //分别对每一组数进行排序,采用递归算法
    Sort_1(a, lo, mid);
    Sort_1(a, mid + 1, hi);
    //再把排号序的两个数组合并
    Merge(a, lo, mid, hi);
}

void Sort(std::vector<int> &a)
{
    //2.定义一个lo, 一个hi变量，记录最小索引和最大索引
    int lo = 0;
    int hi = a.size() - 1;
    //3.调用sort重载方法，对a数组的排序
    Sort_1(a, lo, hi);
}

void exch(std::vector<int> &a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main()
{
    vector<int> a = {8, 4, 5, 7, 1, 3, 6, 2};
    Sort(a);
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << endl;
    return 0;
}