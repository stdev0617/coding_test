#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

string getResult(string input) {
	
	int leftTotal = 0;
	int rightTotal = 0;

	for (int i = 0; i < input.length()/2; i++) {
		leftTotal += input[i] - '0';
	}
	
	for (int i = input.length() / 2; i < input.length(); i++) {
		rightTotal += input[i] - '0';
	}

	if (leftTotal == rightTotal) {
		return "LUCKY";
	}
	else {
		return "READY";
	}
}

int main() {

	string input = "123402";
	cout << getResult(input) << endl;

	string input2 = "7755";
	cout << getResult(input2) << endl;
	return 0;
}