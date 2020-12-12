#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const vector<pair<int, int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };
int board[50][50] = { -1 };
int cnt = 1;

void initBoard(int M, int N) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			board[N][M] = 0;
		}
	}
}

// 지연요인 1. map 처리를 어떻게 해야될지 몰랐음(처음에 map을 map[50][50]으로 만들려고 했는데, 인수로 안넘어감... 그리고 너무 커서 관리도 힘듦)
// 지연요인 2. tmpX에 x를 안더해줬음.(연습장에는 써놓고 안씀. 실수.)
// 지연요인 3. cnt를 findWay안에 int cnt = 1; 로 두어서 cnt가 계속 1로 초기화됐음;; 함수 밖에 선언했어야함.
// 지연요인 4. direction 처리, 즉, 왼쪽으로 도는 방법을 어떻게 처리해야할지 고민했음. 걍 순서대로 네 방향을 돌면 되는데..
// ==> 방향이 나오는 문제는 dx, dy를 줘서 풀자. 그게 방법임.
int findWay(int x, int y, int direction, vector<string> map) {
	int tmpDir;
	for (int i = 0; i < 4; i++) {
		tmpDir = direction+i;
		if (tmpDir > 3) {
			tmpDir = tmpDir - direction-1;
		}
		int tmpX = dir[tmpDir].first+x;
		int tmpY = dir[tmpDir].second+y;
		
		if (board[tmpY][tmpX] == 0 && board[tmpY][tmpX] != -1) {
			if (tmpX >= 0 && tmpX < map[0].size() && tmpY >= 0 && tmpY < map.size()) {
				if (map[tmpY][tmpX] == '0') {
					board[tmpY][tmpX] = 1;
					cnt++;
					findWay(tmpX, tmpY, tmpDir, map);
				}
			}
		}
	}
	return cnt;
}

int main() {

	vector<string> map = { "1001","1001","1101","1101" };
	board[1][1] = 1;
	cout << findWay(1, 1, 3, map);
	return 0;
}