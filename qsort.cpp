#include<iostream>
#include<vector>
#include<random>
using namespace std;

void qsort(vector<int>& vec, int start, int end)
{
	if (start >= end) return;
	int i = start;
	int left = start - 1;
	int right = end + 1;
	int key = vec[rand() % (end - start + 1) + start];
	while (i < right)
	{
		if (vec[i] > key)	swap(vec[i], vec[--right]);
		else if (vec[i] == key) i++;
		else swap(vec[i++], vec[++left]);
	}
	qsort(vec, start, left);
	qsort(vec, right, end);
}
int main()
{
	vector<int> vec;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 100);
	for (int i = 0; i < 10; i++)
		vec.push_back(dis(gen));
	for (auto it : vec)
		cout << it << " ";
	cout << endl;
	qsort(vec, 0, vec.size() - 1);
	for (auto it : vec)
		cout << it << " ";
	cout << endl;
}