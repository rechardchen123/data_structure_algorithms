#include <iostream>
#include <vector>

using namespace std;

class Quick
{
private:
    //比较两个元素的大小
    static bool Less(int v, int w)
    {
        if (v - w < 0)
            return true;
    }

    //数组元素i，j交换位置
    static void exch(vector<int> &a, int i, int j)
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    //对数组a中从索引lo到索引hi之间的元素进行排序
    static void Sort(vector<int> &a, int lo, int hi)
    {
        //安全性校验
        if (hi <= lo)
            return;

        //需要对数组中lo索引到hi索引的元素进行分组
        int part = partition(a, lo, hi); //返回的是分组的分界值所在的索引

        //递归，让左子组有序
        Sort(a, lo, part - 1);

        //让右子组有序
        Sort(a, part + 1, hi);
    }

public:
    //对数组内的元素进行排序
    static void Sort(vector<int> &a)
    {
        int lo = 0;
        int hi = a.size() - 1;
        Sort(a, lo, hi);
    }

    //对数组中从索引lo到hi之间的元素进行分组，并返回分组界限对应的索引
    static int partition(vector<int> &a, int lo, int hi)
    {
        //确定分界值
        int key = a[lo];

        //定义两个指针，分别指向切分元素的最小索引处和最大索引处的下一个位置
        int left = lo;
        int right = hi + 1;

        //切分
        while (true)
        {

            //先从右往左扫描，移动right指针，找到一个比分界值小的元素，停止
            while (Less(key, a[--right]))
            {
                if (right == lo)
                    break;
            }

            //再从左往右扫描，移动left指针，找到一个比分界值大的元素，停止
            while (Less(a[++left], key))
            {
                if (left == hi)
                    break;
            }

            //判断left >= right, 则证明元素扫描完毕，结束循环，否则继续切分
            if (left >= right)
                break;
            else
            {
                exch(a, left, right);
            }
        }
        //交换分界值
        exch(a, lo, right);
        return right;
    }
};

int main()
{
    vector<int> a = {6, 1, 2, 7, 9, 3, 4, 5, 8};
    Quick::Sort(a); //C++中只有静态成员函数才可以直接被调用
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}