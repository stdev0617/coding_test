#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

// 답 틀렸음
// 다시 해볼것
int getSum(vector<int> cards) {
	deque<int> dq;
	deque<int> sumDq;
	int cardSize = cards.size() - 1;
	int ans = 0;

	sort(cards.begin(), cards.end(), less<int>());

	if (cards.size() % 2 != 0) {
		for (int i = 0; i < cards.size()-1; i++) {
			if (i != cards.size() - 1) {
				dq.push_back(cards[i]);
			}
			ans += cards[i];
		}
	}
	else {
		for (int i = 0; i < cards.size(); i++) {
			dq.push_back(cards[i]);
			ans += cards[i];
		}
	}

	while (!dq.empty()) {
		while (!dq.empty()) {
			int a = dq.front();
			dq.pop_front();
			int b = dq.front();
			dq.pop_front();
			sumDq.push_back(a + b);
		}
		while (!sumDq.empty()) {
			ans += sumDq.front();
			if (sumDq.size() == 1) {
				break;
			}
			else {
				dq.push_back(sumDq.front());
			}
			sumDq.pop_front();			
		}
	}

	return ans;
}

int main() {

	vector<int> cards = { 1,2,3,4,5,6,7,8 };
	cout << getSum(cards);
	return 0;
}