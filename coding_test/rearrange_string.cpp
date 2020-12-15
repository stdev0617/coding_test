#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

string getResult(string input) {
	string result;
	string stringTotal;
	int intSum = 0;
	for (int i = 0; i < input.length(); i++) {
		if (input[i] - '0' < 10) {
			intSum += input[i] - '0';
		}
		else {
			stringTotal += input[i];
		}
	}
	sort(stringTotal.begin(), stringTotal.end(), less<int>());
	result = stringTotal + to_string(intSum);
	return result;
}

int main() {

	string input = "K1KA5CB7";
	string input2 = "AJKDLSI412K4JSJ9D";

	cout << getResult(input) << endl;
	cout << getResult(input2) << endl;
	
	return 0;
}