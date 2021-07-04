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
#include <set>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int min_prices = (pow(2,31) - 1);
        int max_profit = 0;
        for(int i=0; i<prices.size(); i++)
        {
            max_profit = max(max_profit, prices[i]-min_prices);
            if(prices[i]<min_prices)
            {
                min_prices = prices[i];
            }
        }
        return max_profit;
    }
};

int main()
{
    Solution sl;
    vector<int> prices = {10000, 9999, 8888, 7777, 555, 444, 33, 22, 1, 0, 0, 0, 0};
    int ret = sl.maxProfit(prices);
    cout << ret <<endl;
    return 0;
}