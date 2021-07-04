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

int main()
{
    int x = 0;
    cout << "(x).addr = " << &x << endl;
    cout << "(x = 1).addr = " << &(x = 1) << endl;
    cout << "(++x).addr = " << &++x << endl;
    // cout << "(x++).addr = " << &(x++) << endl;   // error
    cout << "(cout << ' ').addr=" << &(cout << ' ') << endl;


    // 字符串字面量是左值，而且是不可被更改的左值。字符串字面量并不具名，但是可以用&取地址所以也是左值。
    // 如 "hello",在c++中是 char const [6] 类型，而在c中是 char [6] 类型
    cout << "(\"hello\").addr=" << &("hello") << endl;

    return 0;
}
