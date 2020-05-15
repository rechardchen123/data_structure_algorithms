#include <iostream>
#include <vector>

using namespace std;

void exch(std::vector<int> &a, int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void sort(std::vector<int> &a)
{
    int N = a.size();
    //确定增长量
    int h = 1;
    while (h < N / 2)
    {
        h = h * 2 + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < N; i++)
        {
            for (int j = i; j >= h; j -= h)
            {
                if (a[j - h] - a[j] > 0)
                {
                    exch(a, j - h, j);
                }
                else
                    break;
            }
        }
        //逐渐减小增长量h的值
        h = h / 2;
    }
}

int main()
{
    vector<int> a = {9, 1, 2, 5, 7, 4, 8, 6, 3, 5};
    sort(a);
    cout << "The shell sort sequence is: " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a.at(i) << " ";
    }
    return 0;
}