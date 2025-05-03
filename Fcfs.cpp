#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cout << "Enter the number of process" << endl;
    cin >> n;
    cout << "Enter the arrival time " << endl;
    vector<int> at;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        at.push_back(x);
    }
    cout << "Enter the coresponding Burst time " << endl;
    vector<int> bt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        bt.push_back(x);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({at[i], bt[i]});
    }
    vector<int> ct;

    int currtime = 0;
    for (int i = 0; i < n; i++)
    {
        if (currtime < pq.top().first)
        {
            ct.push_back(pq.top().first + pq.top().second);
            currtime = pq.top().first + pq.top().second;
        }
        else
        {
            ct.push_back(currtime + pq.top().second);
            currtime = currtime + pq.top().second;
        }
        at[i] = pq.top().first;
        bt[i] = pq.top().second;
        pq.pop();
    }
    cout << "AT       BT        CT "<< endl;
    for ( int i = 0; i<n ; i++)
        {
          cout<<at[i] << "      "<< bt[i]<< "      "<< ct[i]<<endl;

        }
    float totaltat = 0;
    for (int i = 0; i < n; i++)
    {
        totaltat += ct[i] - at[i];
    }
    cout << " the average TAT is : " << float(totaltat / n) << endl;
    float totalwt = 0;
    for (int i = 0; i < n; i++)
    {
        totalwt += ct[i] - at[i] - bt[i];
    }
    cout << " the average waiting time is :" << float(totalwt / n);
    return 0;
}