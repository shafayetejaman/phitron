#include "my_hederfile.h"

using namespace std;

int main()
{
    vector<vector<string>> v = {{"1, 3, 5, 2, 4, 6"}};

    // auto it = find_if(v.begin(), v.end(), [](int x)
    //                   { return x == 3; });

    // if (it != v.end())
    // {
    //     // Found an even number
    //     int even = distance(v.begin(), it);
    //     print(even);
    // }
    // else
    // {
    //     print("not found");
    // }


    print(v);

    return 0;
}
