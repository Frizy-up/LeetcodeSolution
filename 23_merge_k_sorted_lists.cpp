#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include  <functional>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution_priority_queue {
public:

	struct cmp{
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->val > b->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		priority_queue< ListNode*, vector<ListNode*>, cmp> q;
		ListNode head = ListNode(0);
		ListNode* phead = &head;

		for (auto &it : lists)
		{
			if (it)
			{
				q.push(it);
			}
		}

		while (!q.empty())
		{
			ListNode* tmp = q.top();
			q.pop();
			phead->next = tmp;
			phead = phead->next;
			if (tmp->next)
			{
				q.push(tmp->next);
			}
		}
		return head.next;
	}
	
};


class Solution_partition {
public:

	ListNode* merge2Lists(ListNode* list1, ListNode* list2)
	{
		if (list1==nullptr)
		{
			return list2;
		}
		if (list2 == nullptr)
		{
			return list1;
		}

		ListNode head = ListNode(0);
		ListNode* phead = &head;
		while (list1 && list2)
		{
			if (list1->val <= list2->val)
			{
				phead->next = list1;
				list1 = list1->next;
			}
			else
			{
				phead->next = list2;
				list2 = list2->next;
			}
			phead = phead->next;
		}
		phead->next = (list1 == nullptr ? list2 : list1);
		return head.next;
	}

	ListNode* mergeKlists(vector<ListNode*>& lists, int start, int end)
	{
		if (start == end) return lists[start];
		if (start > end) return nullptr;
		int mid = (start + end) / 2;
		ListNode* list1 = mergeKlists(lists, start, mid);
		ListNode* list2 = mergeKlists(lists, mid + 1, end);
		return merge2Lists(list1, list2);
	}

	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		return mergeKlists(lists, 0, lists.size() - 1);
	}

};


//int main()
//{
//	// pointer test OK!//
//	//int* a = new int(1);
//	//int* b = a;
//	//a = new int(2);
//	////////////////////
//
//
//	//[[1, 4, 5], [1, 3, 4], [2, 6]]
//	ListNode* list1 = new ListNode(1);
//	list1->next = new ListNode(4);
//	list1->next->next = new ListNode(5);
//
//	ListNode* list2 = new ListNode(1);
//	list2->next = new ListNode(3);
//	list2->next->next = new ListNode(4);
//
//	ListNode* list3 = new ListNode(2);
//	list3->next = new ListNode(6);
//
//	vector<ListNode*> vec_lists = { list1, list2, list3 };
//	Solution_partition sl;
//	ListNode* ret_list = sl.mergeKLists(vec_lists);
//
//	return 0;
//}