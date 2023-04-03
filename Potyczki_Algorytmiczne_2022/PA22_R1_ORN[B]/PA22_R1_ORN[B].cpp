#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main()
{
	int n, left, right, count = 0, count2 = 0, direction = -1;
	int infp = 1000000001;
	int infm = -1000000001;

	std::string temp;

	getline(std::cin, temp);

	n = stoi(temp);

	std::vector<int> arr1, arr2;

	std::string nums;

	getline(std::cin, nums);

	std::istringstream stream(nums);

	while (getline(stream, temp, ' ')) 
		arr1.push_back(stoi(temp));

	arr2 = arr1;

	for (int i = 0; i < n - 1; i++) 
	{
		left = arr1[i];
		right = arr1[i + 1];

		if (left > right) 
		{
			if (direction == -1) 
			{
				arr1[i + 1] = infp;
				count++;
				direction = 0;
			}
			else 
			{
				direction = -1;
			}
		}
		else if (left < right) 
		{
			if (direction == 1) 
			{
				arr1[i + 1] = infm;
				count++;
				direction = 0;
			}
			else 
			{
				direction = 1;
			}
		}
		else 
		{
			if (direction == -1) 
			{
				arr1[i + 1] = infp;
				count++;
				direction = 0;
			}
			else if (direction == 1) 
			{
				arr1[i + 1] = infm;
				count++;
				direction = 0;
			}
		}
	}

	direction = 1;

	for (int i = 0; i < n - 1; i++) 
	{
		left = arr2[i];
		right = arr2[i + 1];

		if (left > right) 
		{
			if (direction == -1) 
			{
				arr2[i + 1] = infp;
				count2++;
				direction = 0;
			}
			else 
			{
				direction = -1;
			}
		}
		else if (left < right) 
		{
			if (direction == 1) 
			{
				arr2[i + 1] = infm;
				count2++;
				direction = 0;
			}
			else 
			{
				direction = 1;
			}
		}
		else 
		{
			if (direction == -1) 
			{
				arr2[i + 1] = infp;
				count2++;
				direction = 0;
			}
			else if (direction == 1) 
			{
				arr2[i + 1] = infm;
				count2++;
				direction = 0;
			}
		}
	}

	if (count > count2) 
	{
		count = count2;
	}

	std::cout << count;
}