#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int getNumberOfCases(int hour) {
	string eachHour;
	string eachMinute;
	string eachSecond;
	int cnt = 0;
	int result = 0;
	for (int i = 0; i <= hour; i++) {
		string total;
		eachHour = to_string(i);
		for (int j = 0; j < 60; j++) {
			eachMinute = to_string(j);
			for (int k = 0; k < 60; k++) {
				eachSecond = to_string(k);
				total = eachHour + eachMinute + eachSecond;
				for (int l = 0; l < total.size(); l++) {
					if (total[l] == '3') {
						cnt++;
						break;
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	printf("result: %d", getNumberOfCases(5));
	return 0;
}