#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> sorting(vector<int> data) {
	// sort(������, ����, ���Ĺ��<Ÿ��>());
	// begin()�� end()�� �ּҸ� ��Ÿ����.
	// ����) iterator���� begin(), end()�Ӹ� �ƴ϶�, insert(�ּ�,��), erase(�ּ�,��)�� �����Ѵ�.
	sort(data.begin(),data.end(), greater<int>());
	return data;
}

int main() {
	vector<int> data = { 15,27,12 };
	vector<int> sortingData = sorting(data);
	for (int i = 0; i < data.size(); i++) {
		cout << sortingData[i] << endl;
	}
	return 0;
}