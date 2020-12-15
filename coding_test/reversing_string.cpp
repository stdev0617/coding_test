#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

// 공식 답안과 같은 원리로 처리
int reverse(string input) {
	int countZero = 0;
	int countOne = 0;
	if (input.size() == 1) {
		return 1;
	}
	for (int i = 0; i < input.size()-1; i++) {
		if (input[i] == input[i + 1]) {
			continue;
		}
		else if (input[i] == '0' && input[i + 1] == '1') {
			if (i == input.size() - 2) {
				countOne++;
			}
			countZero++;
		}
		else {
			if (i == input.size() - 2) {
				countZero++;
			}
			countOne++;
		}
	}
	if (countZero > countOne) {
		return countOne;
	}
	else {
		return countZero;
	}
}

int main() {
	string input = "10101001";
	cout << reverse(input) << endl;
	return 0;
}