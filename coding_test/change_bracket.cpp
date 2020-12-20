#include<string>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

queue<char> open;
queue<char> close;

string getResult(string input) {
	string ans ="";
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '(') {
			open.push(input[i]);
		}
		else {
			close.push(input[i]);
		}
		if (i % 2 == 1) {
			if (open.size() == close.size()) {
				
				while (!open.empty()) {
					ans += open.front();
					open.pop();
				} while (!close.empty()) {
					ans += close.front();
					close.pop();
				}
			}
		}
	}
	return ans;
}

int main() {
	string input = "()))((()";
	cout << getResult(input) << endl;
	return 0;
}