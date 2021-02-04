#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include  <functional>

using namespace std;

// bibi
// https://www.bilibili.com/video/BV1at411T75o/?spm_id_from=333.788.recommend_more_video.0
void quick_sort_recur(vector<int>&vect, int L, int R)
{
	if (L >= R) return;
	int middle = vect[L];
	int i = L, j = R;
	while (i<j)
	{
		while ((j>i) && (vect[j] >= middle)) j--;
		if (i == j)
		{
			vect[i] = middle;
			break;
		}
		else
		{
			vect[i] = vect[j];
			i++;
			if (i == j)
			{
				vect[j] = middle;
				break;
			}
		}

		while ((i<j) && (vect[i] <= middle)) i++;
		if (i == j)
		{
			vect[i] = middle;
			break;
		}
		else
		{
			vect[j] = vect[i];
			j--;
			if (i == j)
			{
				vect[i] = middle;
				break;
			}
		}
	}
	quick_sort_recur(vect, L, j-1);
	quick_sort_recur(vect, j+1, R);
}

void quick_sort(vector<int>&vect)
{
	int size = vect.size();
	if (size <= 1) return;
	quick_sort_recur(vect, 0, size - 1);
}

int main()
{
	vector<int> numbers{ 0, 1, 2, 3, -1 };
	/*vector<int> numbers{  };*/
	/*vector<int> numbers{0,0,0,0};*/
	/*vector<int> numbers{ 1, 1, 3, 3 };*/
	/*vector<int> numbers{ 3, 3, 2, 1 };*/
	/*vector<int> numbers{ 3, 2, -10, -100 };*/
	quick_sort(numbers);
	for (auto &tmp : numbers)
	{
		cout << tmp << endl;
	}

	return 0;
}