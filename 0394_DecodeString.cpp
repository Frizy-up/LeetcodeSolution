#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums)
		// {
		//     sort(nums.begin(), nums.end(), less<int>());

		//     if(nums.size() == 0) return 0;
		//     if(nums.size() == 1) return 1;

		//     int g_max = 1;
		//     int l_max = 1;
		//     for(int i=1; i<nums.size(); i++)
		//     {
		//         if(nums[i]-nums[i-1] == 1)
		//         {
		//             l_max++;
		//             g_max = max(g_max, l_max);
		//         }
		//         else if(nums[i]-nums[i-1] == 0 )
		//         {

		//         }
		//         else
		//         {
		//             l_max = 1;
		//         }
		//     }

		//     return g_max;
		// }

	{
		if (nums.size() == 0) return 0;
		unordered_set<int> set_(nums.begin(), nums.end());
		int g_max = 1;
		int l_max = 1;
		for (auto num : nums)
		{
			if (set_.count(num - 1)) continue;

			l_max = 1;
			while (set_.count(num+1) )
			{
				l_max++;
				num++;
			}
			g_max = max(g_max, l_max);
		}
		return g_max;
	}
};