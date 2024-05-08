#include<bits/stdc++.h>

using namespace std;

class DisJoint
{
    vector<int> size, range, parent;
    public:
        DisJoint(int n){
            size.resize(n+1, 1);
            range.resize(n+1, 0);
            parent.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }
        
        int find_ulti_parent(int node){
            if(node == parent[node])
                return node;
                
            return parent[node] = find_ulti_parent(parent[node]);
        }
        
        void unionByRange(int u, int v){
            int ulp_u = find_ulti_parent(u);
            int ulp_v = find_ulti_parent(v);
            
            if(ulp_u == ulp_v)
                return;
                
            if(range[ulp_u] < range[ulp_v])
                parent[ulp_u] = ulp_v;
            else if(range[ulp_u] > range[ulp_v])
                parent[ulp_v] = ulp_u;
            else{
                parent[ulp_v] = ulp_u;
                range[ulp_u]++;
            }
        }
        
        void unionBySize(int u, int v){
            int ulp_u = find_ulti_parent(u);
            int ulp_v = find_ulti_parent(v);
            
            if(ulp_u == ulp_v)
                return;
                
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0; i<V; i++){
            for(auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, {node, adjNode}});
            }
        }
        
        DisJoint ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.find_ulti_parent(u) != ds.find_ulti_parent(v)){
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        
        return mstWt;
    }
};

int main()
{
	int v = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};

	vector<vector<int>> adj[v];
	for(auto it : edges)
	{
		vector<int> tmp;
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);
	}

	Solution obj;
	int mstWt = obj.SpanningTree(v, adj);
	cout << "The sum of all the edges weights : " << mstWt << endl;
	return 0;
}