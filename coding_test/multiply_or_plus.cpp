#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

// 원래 답안은 1보다 작거나 같으면 더하고, 1보다 크면 곱하면 되는거임
// 처음에 그렇게 생각했으나 아래와 같이 풀어봄
int calculate(string input) {
	int result = input[0] - '0';
	int sum = 0;
	int mul = 0;
	int tmp = 0;
	for (int i = 0; i < input.size() - 1; i++) {
		sum = input[i] + input[i + 1] - '0' - '0';
		mul = (input[i] - '0') * (input[i + 1] - '0');

		if (sum > mul) {
			tmp = input[i + 1] - '0';
			result =result+ tmp;
		}
		else {
			tmp = input[i + 1] - '0';
			result = result * (tmp);
		}
	}
	return result;
}

int main() {
	string input = "02984";
	cout << calculate(input) << endl;
	return 0;
}