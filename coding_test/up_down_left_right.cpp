#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int size, string move) {
	int x = 1;
	int y = 1;
	vector<int> result;

	for (int i = 0; i < move.size(); i++) {

		switch (move[i])
		{
		case 'U':
			x--;
			break;
		case 'D':
			x++;
			break;
		case 'L':
			y--;
			break;
		case 'R':
			y++;
			break;
		default:
			break;
		}

		if (1 > x || size < x || 1 > y || size < y) {
			if (x < 1) x++;
			else if (x > size) x--;
			else if (y < 1) y++;
			else if (y > size) y--;
			continue;
		}
		cout << "position: " << x << "," << y << endl;
	}
	result.push_back(x);
	result.push_back(y);
	return result;
}

int main() {
	int size = 5;
	string move = "RRRUDD";
	vector<int> result = solution(size, move);
	int x = result[0];
	int y = result[1];

	printf("result x y : %d %d", x, y);
	return 0;
}