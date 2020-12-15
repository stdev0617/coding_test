#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int makeGroup(deque<int> dq) {
	int cnt = 0;
	int scary = 0;
	int persons = 0;

	while (!dq.empty() && dq.size() > dq.front()) {
		scary = dq.front();
		dq.pop_front();
		for (int i = 0; i < scary; i++) {
			dq.pop_front();
		}
		cnt++;
	}
	return cnt;
}

int main() {
	int N = 5;
	deque<int> dq = { 2,3,1,2,2 };
	sort(dq.begin(), dq.end(), less<int>());
	cout << "result: " << makeGroup(dq) << endl;
	return 0;
}