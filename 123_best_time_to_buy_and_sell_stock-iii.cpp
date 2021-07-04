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

class Solution_dp {
public:
    vector< vector< vector<int> > > T;

    int maxProfit( vector<int>& prices )
    {
        int L = prices.size();
        T.resize(L+1, vector< vector<int> >(3, vector<int>(2,0)));

        T[0][0][1] = -prices[0];
        T[0][1][1] = -prices[0];
        T[0][2][1] = -prices[0];

        for(int i=0; i<L; i++)
        {
            T[i+1][1][0] = max(T[i][1][0], T[i][1][1]+prices[i]);
            T[i+1][1][1] = max(T[i][1][1], T[i][0][0]-prices[i]);
            T[i+1][2][0] = max(T[i][2][0], T[i][2][1]+prices[i]);
            T[i+1][2][1] = max(T[i][2][1], T[i][1][0]-prices[i]);
        }

        return T[L][2][0];
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