#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int board[100][100] = { 0 };
int tail_x = 0;
int tail_y = 0;

void initBoard(vector<pair<int, int>> apples) {
	int x;
	int y;
	for (int i = 0; i < apples.size(); i++) {
		y = apples[i].first;
		x = apples[i].second;
		board[y-1][x-1] = 2;
	}
}

bool move(char dir, int cur_x, int cur_y, int N) {
	int x = cur_x;
	int y = cur_y;

	switch (dir)
	{
	case 'R':
		x++;
		break;
	case 'L':
		x--;
		break;
	case 'U':
		y--;
		break;
	case 'D':
		y++;
		break;
	}

	if (x < 0 || x >= N || y < 0 || y >= N) {
		return false;
	} else if (board[y][x] == 1) {
		return false;
	}
	else {
		if (board[y][x] == 2) {
			board[y][x] = 1;
		}
		else {
			board[y][x] = 1;
			board[tail_y][tail_x] = 0;
			switch (dir) {
			case 'R':
				tail_x++;
				break;
			case 'L':
				tail_x--;
				break;
			case 'D':
				tail_y++;
				break;
			case 'U':
				tail_y--;
				break;
			}
		}
	}
	return true;
}

int solution(char dir, queue<pair<int, char>> dirs, int x, int y, int N) {
	int time = 0;
	while (1) {
		if (!dirs.empty() && time == dirs.front().first) {
			if (dirs.front().second == 'L') {
				switch (dir) {
				case 'R':
					dir = 'U';
					break;
				case 'L':
					dir = 'D';
					break;
				case 'D':
					dir = 'R';
					break;
				case 'U':
					dir = 'L';
					break;
				}
			}
			else {
				switch (dir) {
				case 'R':
					dir = 'D';
					break;
				case 'L':
					dir = 'U';
					break;
				case 'D':
					dir = 'L';
					break;
				case 'U':
					dir = 'R';
					break;
				}
			}
			dirs.pop();
		}
		if (move(dir, x, y, N) == false) {
			return time+1;
		}
		else {
			switch (dir) {
			case 'R':
				x++;
				break;
			case 'L':
				x--;
				break;
			case 'D':
				y++;
				break;
			case 'U':
				y--;
				break;
			}
			time++;
		}
	}
}

int main() {

	// 예제 1
	int N = 6;
	vector<pair<int, int>> apples = { {3,4},{2,5},{5,3} };
	queue<pair<int, char>> dirs;
	dirs.push(make_pair(3, 'D'));
	dirs.push(make_pair(15, 'L'));
	dirs.push(make_pair(17, 'D'));

	// 예제 2
	//int N = 10;
	//vector<pair<int, int>> apples = { {1,2},{1,3},{1,4},{1,5} };
	//queue<pair<int, char>> dirs;
	//dirs.push(make_pair(8, 'D'));
	//dirs.push(make_pair(10, 'D'));
	//dirs.push(make_pair(11, 'D'));
	//dirs.push(make_pair(13, 'L'));

	// 예제3
	//int N = 10;
	//vector<pair<int, int>> apples = { {1,2},{1,3},{1,6},{1,5},{1,7} };
	//queue<pair<int, char>> dirs;
	//dirs.push(make_pair(8, 'D'));
	//dirs.push(make_pair(10, 'D'));
	//dirs.push(make_pair(11, 'D'));
	//dirs.push(make_pair(13, 'L'));
	//initBoard(apples);
	cout << solution('R', dirs, 0, 0, N) << endl;

	return 0;
}