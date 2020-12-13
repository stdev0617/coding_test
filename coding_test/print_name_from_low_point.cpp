#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	// 오른쪽이 크면 오름차순, 왼쪽이 크면 내림차순
	return a.first < b.first;
}

vector<pair<int,string>> print(vector<pair<int, string>> person) {
	// 만들어진 compare를 사용할 때, 인자를 따로 입력하지 않아도 된다.
	sort(person.begin(), person.end(), compare);
	return person;
}

int main() {
	vector<pair<int, string>> data;
	data.push_back(make_pair(95, "홍길동"));
	data.push_back(make_pair(77, "이순신"));
	vector<pair<int,string>> result = print(data);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i].second << endl;
	}
	return 0;
}