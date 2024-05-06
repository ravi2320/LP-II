#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void BFS(vector<vector<int>> &graph, vector<bool> &visited, queue<int> &q)
{
	if(q.empty())
		return;

	int node = q.front();
	q.pop();
	cout << node << " ";

	for(int neighbor : graph[node])
	{
		if(!visited[neighbor])
		{
			visited[neighbor] = true;
			q.push(neighbor);
		}
	}

	BFS(graph, visited, q);
}

int main()
{
	vector<vector<int>> graph{
					{1, 2},
					{0, 3},
					{0, 5},
					{1},
					{1, 5},
					{2, 4}
				};
	
	int startNode = 0;
	
	vector<bool> visited(graph.size(), false);
	queue<int> q;
	q.push(startNode);
	visited[startNode] = true;
	cout << "BFS Traversing starting from node " << startNode << " : ";
	BFS(graph, visited, q);
	return 0;
}