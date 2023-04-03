#include <iostream>
#include <vector>
using namespace std;

int DecToBin(int num)
{
	int counter = 0;

	while (num > 0)
	{
		if (num % 2 == 1)
			counter++;
		num = num / 2;
	}

	return counter;
}

int main()
{
	vector<int> arr;
	int n;

	cin >> n;

	int sum = 0;
	int i = 1;

	for (i; sum < n; i++)
	{
		sum += DecToBin(i);
	}

	i--;
	arr.push_back(i);
	i--;

	for (i; sum != n; i--)
	{
		sum -= DecToBin(i);
		if (sum < n)
		{
			arr.push_back(i);
			sum += DecToBin(i);
		}
	}

	for (int k = i; k > 0; k--)
	{
		arr.push_back(k);
	}

	cout << arr.size() << "\n";

	for (int a = 0; a < arr.size(); a++)
	{
		cout << arr[a] << " ";
	}
}