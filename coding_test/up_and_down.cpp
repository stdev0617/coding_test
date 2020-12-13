#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<int> sorting(vector<int> data) {
	// sort(시작점, 끝점, 정렬방법<타입>());
	// begin()과 end()는 주소를 나타낸다.
	// 참고) iterator에는 begin(), end()뿐만 아니라, insert(주소,값), erase(주소,값)이 존재한다.
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