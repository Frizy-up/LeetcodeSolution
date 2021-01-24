#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include  <functional>

using namespace std;

class Solution_partition {
public:

	bool check(vector<vector<int>>& matrix, int& n, int& k, int& middle)
	{
		int i = 0, j = n - 1;
		int m = 0;
		while (i <= n - 1 && j >= 0)
		{
			if (matrix[i][j] <= middle)
			{
				i += 1;
				m += (j + 1);
			}
			else
			{
				j--;
			}
		}
		return m >= k;
	}


	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		int n = matrix.size();
		if (n == 1)
		{
			return matrix[0][0];
		}
		int left = 0, right = matrix[n - 1][n - 1];
		while (left<right)
		{
			int middle = (left + right) / 2;
			if (check(matrix, n, k, middle))
			{
				right = middle;
			}
			else
			{
				left = middle + 1;
			}
		}
		return left;
	}
};


class Solution_priority_queue {
public:
	struct matElement
	{
		int val;
		int row;
		int col;
		matElement(int val, int row, int col) : val(val), row(row), col(col)
		{

		};

		bool operator > (const matElement& mat_ele) const
		{
			return this->val > mat_ele.val;
		}
	};

	struct cmp
	{
		bool operator() (const matElement& a, const matElement& b)
		{
			return a.val > b.val;
		}
	};

	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		int n = matrix.size();
		/*priority_queue<matElement, vector<matElement>, greater<matElement>> que;*/
		priority_queue<matElement, vector<matElement>, cmp> que;
		for (int i = 0; i < n; i++)
		{
			que.emplace(matrix[i][0], i, 0);
		}

		for (int j = 1; j < k; j++)
		{
			matElement tmp = que.top();
			que.pop();
			if (tmp.col < n - 1)
			{
				que.emplace(matrix[tmp.row][tmp.col + 1], tmp.row, tmp.col + 1);
			}
		}
		return que.top().val;
	}
};

//int main()
//{
//	Solution_priority_queue sl;
//	vector<vector<int>> matrix = { { 1, 5, 9 }, { 10, 11, 13 }, { 12, 13, 15 } };
//	int ret = sl.kthSmallest(matrix, 8);
//	cout << ret << endl;
//	return 0;
//}