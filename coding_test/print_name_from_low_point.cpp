#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b) {
	// �������� ũ�� ��������, ������ ũ�� ��������
	return a.first < b.first;
}

vector<pair<int,string>> print(vector<pair<int, string>> person) {
	// ������� compare�� ����� ��, ���ڸ� ���� �Է����� �ʾƵ� �ȴ�.
	sort(person.begin(), person.end(), compare);
	return person;
}

int main() {
	vector<pair<int, string>> data;
	data.push_back(make_pair(95, "ȫ�浿"));
	data.push_back(make_pair(77, "�̼���"));
	vector<pair<int,string>> result = print(data);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i].second << endl;
	}
	return 0;
}