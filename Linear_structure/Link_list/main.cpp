#include <iostream>
#include "Linklist_1.h"
#include "singlelist_1.h"

using namespace std;

int main(void)
{
    LinkList<int> ll;

    for (int i = 0; i < 6; ++i)
    {

        ll.insert(0, i);
    }

    for (int i = 0; i < ll.length(); i++)
    {
        cout << ll.current() << endl;
    }

    getchar();
    return 0;
}