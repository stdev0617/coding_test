#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<deque>

using namespace std;

deque<pair<int, int>> q;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int board[200][200] = { -1 };

void initBoard(int M, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = 0;
		}
	}
	board[0][0] = 1;
}

int findWay(vector<string> map, int x, int y, int N, int M) {

	q.push_back(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop_front();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
				continue;
			}

			if (board[ny][nx] >= 1) {
				continue;
			}

			if (map[ny][nx] == 0) {
				continue;
			}
			board[ny][nx] = board[y][x] + 1;
			q.push_back(make_pair(nx, ny));
		}
	}
	return board[N - 1][M - 1];
}

int main() {
	int N = 5;
	int M = 6;
	vector<string> map = { "101010","111111","000001","111111","111111" };
	initBoard(M, N);
	cout << findWay(map,0,0,N,M) << endl;
	return 0;
}