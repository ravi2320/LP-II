#include<bits/stdc++.h>>

using namespace std;

class Solution
{
    int vertices;
    vector<vector<int>> graph;
    vector<int> color;
    int minCol;
    public:
        Solution(int v, vector<vector<int>> g, vector<int> c, int minC){
            vertices = v;
            graph = g;
            color = c;
            minCol = minC;
        }

        bool isSafe(int node, int col){
            for(int adjNode : graph[node]){
                if(color[adjNode] == col)
                    return false;
            }
            return true;
        }

        void solve(int node, int numCol){
            
            if(numCol >= minCol)
                return;

            if(node == vertices)
            {
                for(int i=0; i<vertices; i++){
                    cout << "Vertex " << i+1 << "  color ----> " << color[i] << endl; 
                }
                minCol = numCol;
                cout << "Minimum number of colors needed: " << minCol << endl;
                return;
            }

            for(int i=1; i<=numCol; i++){
                if(isSafe(node, i)){
                    color[node] = i;
                    solve(node+1, numCol);
                    color[node] = 0;
                }
            }

            color[node] = numCol + 1;
            solve(node + 1, numCol+1);
            color[node] = 0;
        }
};


int main()
{
    int v = 4, minCol = 1e9;
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
    Solution obj(v, graph, color, minCol);
    obj.solve(0, 1);
    return 0;
}