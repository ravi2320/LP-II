#include<bits/stdc++.h>

using namespace std;

class Solution
{
	public:
		void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> leftrow, vector<int> lowerDiagnol, vector<int> upperDiagnol, int n)
		{
			if(col == n)
			{
				ans.push_back(board);
				return;
			}

			for(int row = 0; row < n; row++)
			{
				if(!leftrow[row] && !lowerDiagnol[row+col] && !upperDiagnol[n-1+row-col])
				{
					board[row][col] = 'Q';
					leftrow[row] = 1;
					lowerDiagnol[row+col] = 1;
					upperDiagnol[n-1+row-col] = 1;

					solve(col+1, board, ans, leftrow, lowerDiagnol, upperDiagnol, n);

					board[row][col] = '_';
					leftrow[row] = 0;
					lowerDiagnol[row+col] = 0;
					upperDiagnol[n-1+row-col] = 0;
				}
			}
		}

		vector<vector<string>> solveNQueens(int n)
		{
			vector<vector<string>> ans;
			vector<string> board(n, string(n, '_'));
			vector<int> leftrow(n, 0);
			vector<int> lowerDiagnol(2*n-1, 0);
			vector<int> upperDiagnol(2*n-1, 0);
			solve(0, board, ans, leftrow, lowerDiagnol, upperDiagnol, n);
			return ans;
		}
};

int main()
{
	int n = 4;
	Solution obj;
	vector<vector<string>> ans = obj.solveNQueens(n);

	for(int i=0; i<ans.size(); i++)
	{
		cout << "Arrangement " << (i+1) << endl;
		for(int j = 0; j < ans[0].size(); j++)
		{
			cout << ans[i][j] << endl;
		}
		cout << endl;
	}
	return 0;
}