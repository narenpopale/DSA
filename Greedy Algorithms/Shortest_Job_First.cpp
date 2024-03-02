// You have to implement the shortest job first scheduling algorithm.
// Shortest Job First is an algorithm in which the process having the smallest execution(burst) time is chosen for the next execution. 
// Here, you will implement a non - preemptive version (a process will wait till process(es) with shorter burst time executes). 
// You have to return the average waiting for the given number of processes.


// TC - O(nlogn)
// SC - O(2n)
// n - no. of proceses


#include <bits/stdc++.h>
using namespace std;


float sjf(int n, vector<int> &at, vector<int> &bt)
{
    vector<pair<int, int>> v;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++)
    {
        v.push_back({at[i], bt[i]});
    }

    sort(v.begin(), v.end());

    int waiting_time = 0;
    int current_time = v[0].first;

    pq.push({v[0].second, v[0].first});
    int i = 1;

    while (!pq.empty())
    {
        int burst_time = pq.top().first;
        int arrival_time = pq.top().second;
        pq.pop();

        waiting_time += current_time - arrival_time;
        current_time += burst_time;

        while (true)
        {
            if(i < n && current_time >= v[i].first){
                pq.push({v[i].second, v[i].first});
                i++;
            }
            else break;
        }
    }

    // Returning average waiting time for each process
    return waiting_time / (float)n;
}