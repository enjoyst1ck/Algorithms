#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {

		if (s[0] == '0') return 0;

		int n = s.size();
		int* res = new int[n + 1];

		res[0] = 1;
		res[1] = 1;

		for (int i = 2; i <= n; i++)
		{
			res[i] = 0;

			int cur = s[i - 1] - '0';
			int pre = s[i - 2] - '0';
			int twoDigit = 10 * pre + cur;
			if (cur != 0)
			{
				res[i] += res[i - 1];
			}
			if (twoDigit >= 10 && twoDigit <= 26)
			{
				res[i] += res[i - 2];
			}
		}
		return res[n];
	}
};

int main()
{
	string s = "3112";

	Solution res;
	cout << res.numDecodings(s);
}