#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include  <functional>

using namespace std;

class Solution {
public:

	int N;
	vector<vector<string>> ret;

	void print_result(const vector<int> &indexs)
	{
		vector<string> one_ans;
		for (int i = 0; i<N; i++)
		{
			string one_row = "";
			for (int j = 0; j<N; j++)
			{
				if (indexs[i] == j)
				{
					one_row += 'Q';
				}
				else
				{
					one_row += '.';
				}
			}
			one_ans.push_back(one_row);
		}
		ret.push_back(one_ans);
	}

	bool check(const vector<int>&indexs, const vector<bool>&col_collide, const int &i, const int &j) const
	{
		bool tmp = true;
		if (col_collide[j])
		{
			tmp = false;
			printf("check (%d,%d): %d\n", i, j, tmp);
			return tmp;
		}

		for (int ii = 0; ii<i; ii++)
		{
			// Note! Error: (3,4),(0,0)  int k=4/3==1 ! return false, but should return true!!!!!!!!!!
			/*int k = abs( (j - indexs[ii]) / (i - ii) );
			printf("(%d,%d),(%d,%d),k=%d ", i, j, ii, indexs[ii], k);*/
			/*if ( k == 1 )
			{
				tmp = false;
				printf("check (%d,%d): %d\n", i,j,tmp);
				return tmp;
			}*/
			if ( abs(j - indexs[ii]) == (i - ii) )
			{
				tmp = false;
				printf("(%d,%d),(%d,%d), %d    ", i, j, ii, indexs[ii], abs(j - indexs[ii]) == (i - ii));
				printf("check (%d,%d): %d\n", i, j, tmp);
				return tmp;
			}
		}
		printf("check (%d,%d): %d\n", i, j, tmp);
		return tmp;
	}

	void solveNQueens(vector<int> indexs, vector<bool> col_collide, int i)
	{
		if (i == N)
		{
			print_result(indexs);
			return;
		}

		for (int j = 0; j<N; j++)
		{
			if (check(indexs, col_collide, i, j))
			{
				indexs[i] = j;
				col_collide[j] = true;
				solveNQueens(indexs, col_collide, i + 1);
				col_collide[j] = false;
				indexs[i] = -1;
			}
		}
	}

	vector< vector<string> > solveNQueens(int n)
	{
		N = n;
		vector<int> indexs(n, -1);
		vector<bool> col_collide(n, false);
		solveNQueens(indexs, col_collide, 0);

		return ret;
	}
};

//int main()
//{
//	int n = 5;
//	Solution sl;
//	vector<vector<string>> ret = sl.solveNQueens(n);
//	for (auto &one_ans : ret)
//	{
//		for (auto &one_row : one_ans)
//		{
//			cout << one_row << endl;
//		}
//		cout << endl;
//	}
//	
//	return 0;
//}