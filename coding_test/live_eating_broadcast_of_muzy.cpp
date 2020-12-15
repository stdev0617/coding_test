#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

// *** 내가 짠 코드 ***
//int solution(vector<int> food_times, long long k) {
//	int answer = 0;
//	int i = 0;
//	int foodCheck = 0;
//	while (k >= 0) {
//		if (food_times[i] == 0) {
//			int check = 0;
//			while (1) {
//				check++;
//				if (i%food_times.size() == 0) {
//					i = 0;
//				}
//				if (food_times[i] != 0) {
//					break;
//				}
//				else {
//					i++;
//				}
//				if (check == food_times.size())
//				{
//					return -1;
//				}
//			}
//		}
//		food_times[i] -= 1;
//		k--;
//		for (int p = 0; p < food_times.size(); p++) {
//			if (food_times[p] == 0) {
//				foodCheck++;
//			}
//			else {
//				break;
//			}
//		}
//		if (foodCheck == food_times.size()) {
//			return -1;
//		}
//		i++;
//		
//		if (k == 0) {
//			return i+1;
//		}
//	}
//}

// 답안
int solution(vector<int> food_times, long long k) {
	int sum = 0;
	for (int i = 0; i < food_times.size(); i++) {
		sum += food_times[i];
	}
	if (sum <= k) {
		return -1;
	}

	priority_queue<int> q;

	for (int i = 0; i < food_times.size(); i++) {
		q.push(food_times[i]);
	}
	
	int sumValue = 0;
	int previous = 0;

	int length = food_times.size();

}

int main() {
	vector<int> food_times = { 0,1,0 };
	int k = 5;
	cout << solution(food_times, k) << endl;
	return 0;
}