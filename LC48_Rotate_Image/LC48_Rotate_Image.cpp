#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix.size();
		int temp;
		int i = 0, j = 0;
		int end_i = (n / 2 + n % 2);
		int end_j = (n / 2);

		while (i < end_i)
		{
			while (j < end_j)
			{
				temp = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
				matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = matrix[i][j];
				matrix[i][j] = temp;
				j++;
			}
			i++;
			j = 0;
		}
	}
};

int main()
{
	vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	Solution res;
	res.rotate(matrix);
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix.size(); j++)
			cout << matrix[i][j];
		cout << endl;
	}
	
}