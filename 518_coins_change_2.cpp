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


using namespace std;

class Solution {
public:

    int change(int amount, vector<int>& coins)
    {
        vector< int > DP(amount+1, 0);
        DP[0] = 1;
        for(int k=0; k<coins.size(); k++)
        {
            for(int i=0; i<=amount; i++)
            {
                if(i<coins[k])
                {
                    continue;
                }
                DP[i] = DP[i] + DP[i-coins[k]];
            }
        }
        return DP[amount];
    }
};

int main()
{
    Solution sl;
    vector<int> coins{1,2,5};
    int amount = 10;
    int ret = sl.change(amount, coins);
    cout << ret <<endl;
    return 0;
}