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

class Solution_greed {
public:
    int maxProfit(vector<int>& prices)
    {
        int max_prf = 0;
        int min_prc = 10001;;
        for(int i=0; i<prices.size(); i++)
        {
            if(prices[i]<min_prc)
            {
                min_prc = prices[i];
                continue;
            }

            if( (i<=prices.size()-2 && prices[i+1]>prices[i]) )
            {
                continue;
            }

            if( prices[i] > min_prc )
            {
                max_prf += prices[i]-min_prc;
                min_prc = 10001;
            }
        }

        return max_prf;
    }
};


class Solution_dp {
public:
    int maxProfit(vector<int>& prices)
    {
        int L = prices.size();
        vector< vector<int> > T(L+1, vector<int>(2, 0));
        T[0][1] = -prices[0];
        for(int i=0; i<prices.size(); i++)
        {
            T[i+1][0] = max( T[i][0], T[i][1] + prices[i]);
            T[i+1][1] = max( T[i][1], T[i][0] - prices[i]);
        }

        return T[L][0];
    }
};


int main()
{
    Solution_dp sl;
    vector<int> prices = {10000, 9999, 8888, 7777, 555, 444, 33, 22, 1, 0, 0, 0, 0};
    int ret = sl.maxProfit(prices);
    cout << ret <<endl;
    return 0;
}