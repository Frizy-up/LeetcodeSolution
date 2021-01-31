#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdio.h>
#include <string>


using namespace std;

class Solution_dp {
public:
    int inf_max = 10001;
    vector< int > memory = vector<int>(10001,-1);
    int dp(vector<int>& coins, int amount)
    {
        if(amount < 0)
        {
            return inf_max;
        }
        if(amount == 0)
        {
            return 0;
        }
        if(-1 != memory[amount])
        {
            return memory[amount];
        }

        int ret = inf_max;
        for(auto& it : coins)
        {
            int tmp = 1 + dp(coins, amount-it);
            ret = min(ret, tmp);
        }
        memory[amount] = ret;
        return ret;
    }
    int coinChange(vector<int>& coins, int amount)
    {
        int ret = dp(coins, amount);
        if(inf_max == ret)
        {
            ret = -1;
        }
        return ret;
    }
};


class Solution {
public:

    int coinChange(vector<int>& coins, int amount)
    {
        int invalid = amount+1;
        int I = amount + 1;
        vector< int > DP(I, invalid);
        DP[0] = 0;
        for(int i=0; i<I; i++)
        {
            for(int k=0; k<coins.size(); k++)
            {
                if(i<coins[k])
                {
                    continue;
                }
                DP[i] = min(DP[i], DP[i-coins[k]]+1);
            }
        }
        int ret = DP[amount];
        if(invalid == ret)
        {
            ret = -1;
        }
        return ret;
    }
};


int main()
{
    Solution sl;
    vector<int> coins{2};
    int amount = 11;
    int ret = sl.coinChange(coins, amount);
    cout << ret <<endl;
    return 0;
}