#include<algorithm>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

int changeArrays(int arr1[], int arr2[], int count, int N) {
	int minVal = 0;
	int result = 0;

	// �߿�) �迭�� ��ġ�� ����ϱ� ������ arr1�� �ְ�, �������� 'arr1+�迭ũ��'�� ����������Ѵ�.
	sort(arr1, arr1+N, less<int>());
	sort(arr2, arr2+N, greater<int>());
	for (int i = 0; i < count; i++) {
		arr1[i] = arr2[i];
	}
	for (int i = 0; i < N; i++) {
		result += arr1[i];
	}
	return result;
}

int main() {
	int arr1[5] = { 1,2,5,4,3 };
	int arr2[5] = { 5,5,6,6,5 };
	int N = 5;
	int count = 3;

	cout << changeArrays(arr1, arr2, count, N) << endl;
	return 0;
}