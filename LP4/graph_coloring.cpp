#include<bits/stdc++.h>

using namespace std;

bool isSafe(int node, vector<int> &color, vector<vector<int>> &graph, int col){
    for(int adjNode : graph[node]){
        if(color[adjNode] == col)
            return false;
    }
    return true;
}

bool solve(int node, vector<int> &color, vector<vector<int>> &graph, int v, int m){
    if(node == v)
        return true;

    for(int i=1; i<=m; i++){
        if(isSafe(node, color, graph, i)){
            color[node] = i;
            if(solve(node+1, color, graph, v, m))
                return true;
            color[node] = 0;
        }
    }

    return false;
}

int main()
{
    int v = 4, col = 2;
    vector<vector<int>> graph(4);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[0].push_back(3);
    graph[1].push_back(0);
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(0);
    graph[2].push_back(1);
    graph[3].push_back(0);
    graph[3].push_back(1);
    vector<int> color(v, 0);
    cout << "Can color graph by " << col << " color : " << solve(0, color, graph, v, col);
    return 0;
}