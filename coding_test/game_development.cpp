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

// �������� 1. map ó���� ��� �ؾߵ��� ������(ó���� map�� map[50][50]���� ������� �ߴµ�, �μ��� �ȳѾ... �׸��� �ʹ� Ŀ�� ������ ����)
// �������� 2. tmpX�� x�� �ȴ�������.(�����忡�� ����� �Ⱦ�. �Ǽ�.)
// �������� 3. cnt�� findWay�ȿ� int cnt = 1; �� �ξ cnt�� ��� 1�� �ʱ�ȭ����;; �Լ� �ۿ� �����߾����.
// �������� 4. direction ó��, ��, �������� ���� ����� ��� ó���ؾ����� �������. �� ������� �� ������ ���� �Ǵµ�..
// ==> ������ ������ ������ dx, dy�� �༭ Ǯ��. �װ� �����.
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