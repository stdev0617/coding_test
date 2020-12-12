#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const vector<pair<int, int>> movement = { {-2,-1},{-2,1},{2,-1},{2,1},{1,2},{1,-2},{-1,2},{-1,-2} };

int move1(string pos) {
	int x = pos[0] - 'a' + 1;
	int y = pos[1] - '0';
	int cnt = 0;
	for (int i = 0; i < movement.size(); i++) {
		int tmpX = x + movement[i].first;
		int tmpY = y + movement[i].second;
		//cout << tmpX, tmpY ;
		if (tmpX >= 1 && tmpX <= 8 && tmpY >= 1 && tmpY <= 8) {
			cnt++;
		}
	}
	
	return cnt;
}

int main() {
	cout << move1("a1") << endl;
	return 0;
}