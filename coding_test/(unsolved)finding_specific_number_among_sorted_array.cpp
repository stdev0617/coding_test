#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int getSolution(vector<int> arr, int x) {
	int N = arr.size();
	int begin = 0;
	int end = 0;
	int mid = N / 2;
	int start = 0;
	int last = 0;
	while (1) {
		if (arr[mid] == x) {
			begin = mid;
			end = mid;
			while (1) {
				begin = begin - 1;
				end = end - 1;
				if (begin < 0 || end > N - 1) {
					break;
				}
				if (arr[begin] != x) {
					start = begin + 1;
				}
				if (arr[end] != x) {
					last = end - 1;
				}
			}
		}
		else {
			
		}
	}
}

int main() {
	int N = 7;
	int x = 2;
	vector<int> arr = {1,1,2,2,2,2,3};
	cout << getSolution(arr);
	return 0;
}