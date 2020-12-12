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
	// 1. �̹� ������ ���� �ڵ带 ������ �ʴ´�.
	if (board[y][x] == 1 || map[y][x] == '1') {
		return 0;
	}

	// 2. �� ó�� �����ϴ� ���, board�� 1�� �ʱ�ȭ ���ش�.
	int cnt = 0;
	if (board[y][x] == 0 && map[y][x] == '0') {
		board[y][x] = 1;
	}

	// 3. DFS�� ������.
	for (int i = 0; i < 4; i++) {
		int tmpX = x + dx[i];
		int tmpY = y + dy[i];
		if (tmpX >= 0 && tmpX < M && tmpY >= 0 && tmpY < N) {
			if(map[tmpY][tmpX] == '0'){
				if (board[tmpY][tmpX] == 0) {
					solution(map, tmpX, tmpY, M, N);
					// board�� solution���� ������, �� ���� �������ǿ� ���� �ٸ� ���� �����Ƿ� �ݵ�� solution �ؿ� ��ġ�Ѵ�.
					board[tmpY][tmpX] = 1;
					cnt++;
				}
			}
		}
	}
	// 4. ��� ����
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
			// �� ���󰣰� ������ result�� 1�� �������� �ƴϸ� 0�� ��������.
			result += solution(map, j, i, M, N);
		}
	}

	cout << result << endl;
	return 0;
}