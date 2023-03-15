#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int res = 0;

        if ((n1 % 2 == 0) && (n2 % 2 == 0))
            return 0;
        else if (n1 % 2 == 0)
        {
            for (int i = 0; i < n1; i++)
                res ^= nums1[i];

            return res;
        }
        else if (n2 % 2 == 0)
        {
            for (int i = 0; i < n2; i++)
                res ^= nums2[i];

            return res;
        }
        else
        {
            for (int i = 0; i < n1; i++)
                res ^= nums1[i];

            for (int i = 0; i < n2; i++)
                res ^= nums2[i];

            return res;
        }
    }
};

int main()
{
    vector<int> arr1 = { 2,1,3 };
    vector<int> arr2 = { 10,2,5,0 };

    Solution res;
    cout << res.xorAllNums(arr1, arr2);
}