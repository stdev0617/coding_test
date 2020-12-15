#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int calculate(vector<int> balls) {
	int cnt = 0;
	for (int i = 0; i < balls.size() - 1; i++) {
		for (int j = i + 1; j < balls.size(); j++) {
			if (balls[i] != balls[j]) {
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	vector<int> balls = { 1,2 };
	cout << calculate(balls) << endl;
	return 0;
}