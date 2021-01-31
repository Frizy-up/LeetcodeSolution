// class Solution {
// public:
//     vector< int > vals = vector(100, -1);
//     int search(const vector<int>& nums, const int& i)
//     {
//         if(i<0)
//         {
//             return 0;
//         }
//         if(-1 != vals[i])
//         {
//             return vals[i];
//         }

//         int a = nums[i] + search(nums, i-2);
//         int b = search(nums, i-1);
//         vals[i] = max(a,b);
//         return vals[i];
//     }

//     int rob(vector<int>& nums)
//     {
//         return search(nums, nums.size()-1);
//     }
// };

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];

        vector<int> DP(nums.size()+1,0);
        DP[0] = 0;
        DP[1] = nums[0];

        for(int i=2; i<nums.size()+1; i++)
        {
            DP[i] = max(DP[i-2]+nums[i-1], DP[i-1]);
        }

        return DP[nums.size()];
    }
};