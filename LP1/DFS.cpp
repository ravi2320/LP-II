#include<iostream>
#include<vector>

using namespace std;

void DFS(vector<vector<int>> &graph, vector<bool> &visited, int node)
{
	cout << node << " ";
	visited[node] = true;

	for(int neighbor : graph[node])
	{
		if(!visited[neighbor])
			DFS(graph, visited, neighbor);
	}
}

int main()
{
	vector<vector<int>> graph{
					{1, 2},
					{0, 3, 4},
					{0, 5},
					{1},
					{1, 5},
					{2, 4}
				};

	int startNode = 0;
	vector<bool> visited(graph.size(), false);

	cout << "DFS travesing starting from node " << startNode << " : ";
	visited[startNode] = true;
	DFS(graph, visited, startNode);
	return 0;
}