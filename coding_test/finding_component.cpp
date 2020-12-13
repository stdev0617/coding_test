#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

bool binary_search(int arr[], int target, int N) {
	sort(arr, arr + N, less<int>());
	
	int mid = N / 2;
	if (arr[mid] == target) {
		return true;
	}
	else if (target < arr[mid]) {
		for (int i = 0; i < mid; i++) {
			if (arr[i] == target) {
				return true;
			}
		}
		return false;
	}
	else {
		for (int i = mid + 1; i < N; i++) {
			if (arr[i] == target) {
				return true;
			} 
		}
		return false;
	}
}

void printResult(int arr[], int N, int target) {
	int result = binary_search(arr, target, N);
	if (result == true) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}

int main() {
	int N = 5;
	int arr[5] = { 8,3,9,7,2 };

	printResult(arr, N, 5);
	printResult(arr, N, 7);
	printResult(arr, N, 9);
	return 0;
}