#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include  <functional>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <sstream>

using namespace std;


class Solution {
public:
	struct Node
	{
		int num;
		int zero_position;
		int steps;
		int  cost;

		string dst = "123450";

		Node(int num, int zero_position, int steps) : num(num), zero_position(zero_position), steps(steps)
		{
			setCost();
		}

		void  setCost()
		{
			// string num_string = to_string(num);
			stringstream ss;
			ss << setw(6) << setfill('0') <<num;
			string num_string = ss.str();
			int diff = 0;
			for (int i = 0; i < 6; i++)
			{
				if (num_string[i] != dst[i])
				{
					diff++;
				}
				cost = steps + diff;
			}
		}

		bool operator< (const Node& node_a) const
		{
			return cost > node_a.cost;
		}
	};

	const string dst = "123450";

	const vector< vector<int> > pos_transform{ { -1, -1, 1, 3 }, { 0, -1, 2, 4 }, { 1, -1, -1, 5 },
	{ -1, 0, 4, -1 }, { 3, 1, 5, -1 }, { 4, 2, -1, -1 } };

	int slidingPuzzle(vector< vector<int> >& board)
	{
		int num = 0;
		int zero_pos = -1;
		int steps = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				num = num * 10 + board[i][j];
				if (0 == board[i][j])
				{
					zero_pos = i * 3 + j;
				}
			}
		}
		priority_queue<Node> que;
		// queue<Node> que;
		map<string, bool> states_map;
		que.push(Node(num, zero_pos, steps));
		// string num_string = to_string(num);
		stringstream ss;
		ss << setw(6) << setfill('0') <<num;
		string num_string = ss.str();
		states_map[num_string] = true;

		while (!que.empty())
		{
			printf("###%d###\n",steps);
			Node node_tmp = que.top();
			// Node node_tmp = que.front();
			que.pop();
			num = node_tmp.num;
			zero_pos = node_tmp.zero_position;
			steps = node_tmp.steps;

			vector<int> trans = pos_transform[zero_pos];
			for (int i = 0; i < 4; i++)
			{
				if (-1 == trans[i])
				{
					continue;
				}

				// num_string = to_string(num);
				ss.str("");
				ss.clear();
				ss << setw(6) << setfill('0') <<num;
				num_string = ss.str();
				if (num_string == dst)
				{
					return steps;
				}

				char tmp = num_string[zero_pos];
				num_string[zero_pos] = num_string[trans[i]];
				num_string[trans[i]] = tmp;
				if (states_map.count(num_string))
				{
					continue;
				}
				que.push(Node(atoi(num_string.c_str()), trans[i], steps + 1));
				states_map[num_string] = true;
				printf("%s: %d, %d. ",num_string.c_str(), trans[i], steps+1);
			}
		}
		return -1;
	}
};

int main()
{
	cout <<"Test..." <<endl;

	vector< vector<int> > board{{3,2,4},{1,5,0}};
	Solution sl;
	int ret = sl.slidingPuzzle(board);

	cout << ret <<endl;


	return 0;
}