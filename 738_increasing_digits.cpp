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
    int monotoneIncreasingDigits(int N)
    {
        string tmp = to_string(N);
        int L = tmp.length()-1;
        int c = L;
        unsigned char min_num = 255;
        for(int i=L; i>0; i--)
        {
            min_num = (min_num-tmp[i]>0 ? tmp[i] : min_num);
            if(tmp[i-1]>min_num)
            {
                c = i-1;
                min_num = tmp[c]-'1'+'0';
            }
        }

        if(c<L)
        {
            tmp[c] = tmp[c] - '1' + '0';
            for(int j=c+1; j<=L; j++)
            {
                tmp[j] = '9';
            }
        }
        int ret = atoi(tmp.c_str());
        return ret;
    }
};

int main()
{
    Solution sl;
    int ret = sl.monotoneIncreasingDigits(120);
    cout << ret <<endl;
    return ret;
}