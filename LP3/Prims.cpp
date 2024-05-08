#include<bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int, int>>> prims(int v, vector<vector<int>> adj[])
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<int> visited(v, 0);
    pq.push({0, {0, -1}});
    vector<pair<int, pair<int, int>>> mstEdges; // Vector to store edges of MST
    int sum = 0;
    while(!pq.empty()){

        auto it = pq.top();
        pq.pop();

        int Wt = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(visited[node] == 1)
            continue;

        visited[node] = 1;
        sum += Wt;
        
        if(parent != -1) {
            mstEdges.push_back({Wt, {parent, node}});
        }
        
        for(auto it : adj[node])
        {
            int adjNode = it[0];
            int adjwt = it[1];

            if(!visited[adjNode])
                pq.push({adjwt, {adjNode, node}});
            
        }
    }
    cout << "Total Sum of MST Edges : " << sum;
    return mstEdges;
}

int main()
{
    int v = 5;
    vector<vector<int>> adj[v];

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 1});
    adj[2].push_back({0, 1});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 2});
    adj[2].push_back({4, 2});
    adj[3].push_back({2, 2});
    adj[3].push_back({4, 1});
    adj[4].push_back({2, 2});
    adj[4].push_back({3, 1});
    
    vector<pair<int, pair<int, int>>> mstEdges = prims(v, adj);
    
    cout << "\nEdge \t Weight" << endl;
    for(auto edge : mstEdges) {
        cout << edge.second.first << " - " << edge.second.second << "\t   " << edge.first << endl;
    }
    
    return 0;
}