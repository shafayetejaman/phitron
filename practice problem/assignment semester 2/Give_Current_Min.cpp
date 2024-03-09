#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;

    int n;
    cin >> n;
    for (auto i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        if (query == 0)
        {
            int temp;
            cin >> temp;
            pq.push(temp);
            cout << pq.top() << endl;
        }
        else if (query == 1)
        {
            if (!pq.empty())
                cout << pq.top() << endl;
            else
                cout << "Empty" << endl;
        }
        else
        {

            if (!pq.empty())
                pq.pop();
                
            if (!pq.empty())
                cout << pq.top() << endl;
            else
                cout << "Empty" << endl;
        }
    }
    return 0;
}