#include <iostream>
#include <ostream>
#include <vector>
#include <map>

using namespace std;

void showMap(map<vector<int>, int> mp)
{
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		cout << "Key: ";
		for (int i = 0; i < it->first.size(); i++)
		{
			cout << it->first[i] << " ";
		}
		cout << "Value: " << it->second << endl;
	}
}

//O[(n^2) * log(n)]
class Solution {
public:
	int equalPairs(vector<vector<int>>& grid) {

		int res = 0;
		map <vector<int>, int> mp;

		for (int i = 0; i < grid.size(); i++)
		{
			mp[grid[i]]++;
		}

		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = i + 1; j < grid.size(); j++)
			{
				swap(grid[i][j], grid[j][i]);
			}

			auto it = mp.find(grid[i]);
			if (it != end(mp))
			{
				res += mp[grid[i]];
			};
		}
		return res;
	}
};

//O(n^3)
class Solution3 {
public:
	int equalPairs(vector<vector<int>>& grid) {
		int n = grid.size();
		int res = 0;
		bool temp;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp = true;
				for (int k = 0; k < n; k++) {
					if (grid[i][k] == grid[k][j]) continue;
					temp = false;
					break;
				}
				if (temp)
					res++;
			}
		}
		return res;
	}
};

int main()
{

	vector<vector<int>> matrix = { {3, 2, 1}, {1, 7, 6}, {2, 7, 7} };
	vector<vector<int>> matrix2 = { {3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2} };

	Solution res;

	cout << res.equalPairs(matrix) << endl;
	cout << res.equalPairs(matrix2) << endl;

	return 0;
}