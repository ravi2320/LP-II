#include<bits/stdc++.h>

using namespace std;

class Solution
{
	public:
		void SelectionSort(vector<int> &arr)
		{
			int n = arr.size();
			int min;
			for(int i=0; i<n-1; i++)
			{
				min = i;
				for(int j=i+1; j<n; j++)
				{
					if(arr[min] > arr[j])
						min = j;
				}
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
};

int main()
{
	Solution obj;
	vector<int> arr = {50, 40, 30, 20, 10};
	cout << "Before Selection Sort : " << endl;
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	obj.SelectionSort(arr);
	cout << "After Selection Sort : " << endl;
	for(int i=0; i<arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}