#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include  <functional>

using namespace std;

class Solution {
public:
	int M = 0, N = 0, ret = 0;

	void floodfill(vector< vector<bool> >&filled, const int &i, const int &j, const vector<vector<char>>& grid)
	{
		if ((0 <= i && i<M) && (0 <= j && j<N) && (!filled[i][j]) && ('1' == grid[i][j]))
		{
			filled[i][j] = true;
			//floodfill(filled, i - 1, j - 1, grid);
			floodfill(filled, i - 1, j, grid);
			//floodfill(filled, i - 1, j + 1, grid);
			floodfill(filled, i, j - 1, grid);
			floodfill(filled, i, j + 1, grid);
			//floodfill(filled, i + 1, j - 1, grid);
			floodfill(filled, i + 1, j, grid);
			//floodfill(filled, i + 1, j + 1, grid);
		}
	}

	int numIslands(vector<vector<char>>& grid)
	{
		M = grid.size();
		if (0 == M) return 0;
		N = grid[0].size();
		if (0 == N) return 0;
		vector< vector<bool> > filled(M, vector<bool>(N, false));
		for (int i = 0; i<M; i++)
		{
			for (int j = 0; j<N; j++)
			{
				if (!filled[i][j] && '1' == grid[i][j])
				{
					ret++;
					floodfill(filled, i, j, grid);
				}
			}
		}
		return ret;
	}
};

//int main()
//{
//	vector<vector<char>> grid{ 
//		{ '1', '1', '0', '0', '0' }, 
//		{ '1', '1', '0', '0', '0' }, 
//		{ '0', '0', '1', '0', '0' }, 
//		{ '0', '0', '0', '1', '1' } };
//	Solution sl;
//	int ret = sl.numIslands(grid);
//
//	cout << ret << endl;
//	
//	return 0;
//}