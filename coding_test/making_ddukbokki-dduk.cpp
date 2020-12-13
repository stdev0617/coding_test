#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int finding_pos(vector<int> size, int target) {
	sort(size.begin(), size.end(), less<int>());
	int N = size[size.size() - 1];
	int begin = 0;
	while (1) {
		int mid = (begin+ N) / 2;
		int total = 0;
		for (int i = 0; i < size.size(); i++) {
			if (size[i] < mid) {
				continue;
			}
			total += (size[i] - mid);
		}
		if (total == target) {
			return mid;
		}
		else if (total < target) {
			N = mid-1;	
		}
		else {
			begin = mid+1;
		}
	}
}

int main() {
	int N = 4;
	int target = 6;
	vector<int> arr = { 19,15,10,17 };
	cout << finding_pos(arr, target);
	return 0;
}