#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int board[1000][1000] = { -1 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

// Initialize board.
void initBoard(int M, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = 0;
		}
	}
}

int solution(vector<string> map, int x, int y, int M, int N) {
	// 1. 이미 갔으면 굳이 코드를 돌리지 않는다.
	if (board[y][x] == 1 || map[y][x] == '1') {
		return 0;
	}

	// 2. 맨 처음 경유하는 경우, board를 1로 초기화 해준다.
	int cnt = 0;
	if (board[y][x] == 0 && map[y][x] == '0') {
		board[y][x] = 1;
	}

	// 3. DFS를 돌린다.
	for (int i = 0; i < 4; i++) {
		int tmpX = x + dx[i];
		int tmpY = y + dy[i];
		if (tmpX >= 0 && tmpX < M && tmpY >= 0 && tmpY < N) {
			if(map[tmpY][tmpX] == '0'){
				if (board[tmpY][tmpX] == 0) {
					solution(map, tmpX, tmpY, M, N);
					// board가 solution위에 있으면, 맨 윗줄 종료조건에 의해 다른 값이 나오므로 반드시 solution 밑에 위치한다.
					board[tmpY][tmpX] = 1;
					cnt++;
				}
			}
		}
	}
	// 4. 결과 리턴
	if (cnt == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

int main() {
	int N = 15;
	int M = 14;
	int result = 0;
	vector<string> map = {"00000111100000",
						  "11111101111110",
						  "11011101101110",
						  "11011101100000",
						  "11011111111111",
						  "11011111111100",
						  "11000000011111",
						  "01111111111111",
						  "00000000011111",
						  "01111111111000",
						  "00011111111000",
						  "00000001111000",
						  "11111111110011",
						  "11100011111111",
						  "11100011111111" };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 쭉 따라간게 있으면 result에 1이 더해지고 아니면 0이 더해진다.
			result += solution(map, j, i, M, N);
		}
	}

	cout << result << endl;
	return 0;
}