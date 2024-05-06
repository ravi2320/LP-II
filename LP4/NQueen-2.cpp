#include<bits/stdc++.h>

using namespace std;

class Solution
{
	public:
		bool isSafe(int row, int col, vector<string> &board, int n)
		{
			int duprow = row;
			int dupcol = col;

			//checking for left col
			while(col >= 0)
			{
				if(board[row][col] == 'Q')
					return false;
				row--;
			}

			//Checking for lower Diagnol
			while(row < n && col >= 0)
			{
				if(board[row][col] == 'Q')
					return false;
				row++;
				col--;
			}

			//Checking for Upper Diagnol
			while(row >= 0 && col >= 0)
			{
				if(board[row][col] == 'Q')
					return false;
				row--;
				col--;
			}
			
			return true;
		}		

		void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> leftrow, vector<int> lowerDiagnol, vector<int> upperDiagnol, int n)
		{
			if(col == n)
			{
				ans.push_back(board);
				return;
			}

			for(int row = 0; row < n; row++)
			{
				if(isSafe(row, col, board, n))
				{
					board[row][col] = 'Q';

					solve(col+1, board, ans, leftrow, lowerDiagnol, upperDiagnol, n);

					board[row][col] = '.';
				}
			}
		}

		vector<vector<string>> solveNQueens(int n)
		{
			vector<vector<string>> ans;
			vector<string> board(n, string(n, '.'));
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