#include<bits/stdc++.h>

using namespace std;

vector<int> Dijkstra(int v, vector<vector<int>> graph[], int s)
{

    set<pair<int, int>> st;

    vector<int> dist(v, 1e9);

    st.insert({0, s});

    dist[s] = 0;

    while(!st.empty())
    {
        auto it = *(st.begin());
        int dis = it.first;
        int node = it.second;
        st.erase(it);

        for(auto it : graph[node])
        {
            int adjNode = it[0];
            int adjDis = it[1];

            if(dis + adjDis < dist[adjNode])
            {
                if(dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + adjDis;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main()
{
    int v = 3, source = 2;
    vector<vector<int>> graph[v];
    graph[0].push_back({1, 1});
    graph[0].push_back({2, 6});
    graph[1].push_back({2, 3});
    graph[1].push_back({0, 1});
    graph[2].push_back({1, 3});
    graph[2].push_back({0, 6});
    
    vector<int> res = Dijkstra(v, graph, source);

    cout << "Vertex \t Distance" << endl;
    for(int i=0; i<res.size(); i++){
        cout << i << "\t\t" << res[i] << endl;
    }
    return 0;
}