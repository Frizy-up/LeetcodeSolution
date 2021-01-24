#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include  <functional>

using  namespace std;

class Solution_topo {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<int> v;
		vector<vector<int>> graph(numCourses, v);
		vector<int> indegree(numCourses, 0);
		for (auto& node : prerequisites)
		{
			indegree[node[0]]++;
			graph[node[1]].push_back(node[0]);
		}

		queue<int> q;
		for (int i = 0; i < numCourses; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
			}
		}
		int num = 0;
		while (!q.empty())
		{
			int node = q.front();
			q.pop();
			num++;
			for (auto& n : graph[node])
			{
				indegree[n]--;
				if (indegree[n] == 0)
				{
					q.push(n);
				}
			}
		}
		return num == numCourses;

	}
};


//int main()
//{
//	///////////////////////////////////////  for auto test ////////////////////////////////////
//	cout << "------------------------     Test    -----------------------" << endl;
//	vector<int>v_test{1, 2, 3, 4};
//	for (auto &tmp : v_test)
//	{
//		tmp--;
//	}
//	for (auto &tmp : v_test)
//	{
//		cout << tmp << endl;
//	}
//	cout << "------------------------ Test Finish -----------------------" << endl;
//	///////////////////////////////////////////////////////////////////////////////////////////
//
//	Solution_topo sl;
//	vector<int> node{ 0, 1 };
//	vector<vector<int>> pre(1, node);
//	bool can_finish = sl.canFinish(2, pre);
//	cout << can_finish << endl;
//	return 0;
//}