#include <bits/stdc++.h>

using namespace std;
void make_list(list<int> &List)
{
    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }

        List.push_back(val);
    }
}

// void remove(list<int> &List)
// {
//     auto curr = List.begin();
//     while (curr != List.end())
//     {
//         auto nextPtr = next(curr);
//         if (nextPtr != List.end() && *curr == *nextPtr)
//         {
//             List.erase(nextPtr);
//         }
//         else
//         {
//             curr = nextPtr;
//         }
//     }
// }

int main()
{
    list<int> List;
    make_list(List);
    List.sort();
    // remove(List);
    List.unique();
    for (auto &i : List)
    {
        cout << i << " ";
    }

    return 0;
}