#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int getMinimumDistance(vector<int> lists) {
	sort(lists.begin(), lists.end(), greater<int>());
	int middleHouse = lists.size() / 2;
	return lists[middleHouse];
}

int main() {
	vector<int> lists = { 7,5,9,3,1,2};
	cout << getMinimumDistance(lists) << endl;
	return 0;
}