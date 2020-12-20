#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> rotate_a_matrix_by_90_degree(vector<vector<int>> a) {
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result[j][n - i - 1] = a[i][j];
        }
    }
    return result;
}

bool check(int new_lock[][20]) {
    int lock_length = sizeof(new_lock)/sizeof(new_lock[0]);
    for (int i = lock_length; i < lock_length * 2; i++) {
        for (int j = lock_length; j < lock_length * 2; j++) {
            if (new_lock[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;

    int n = lock.size();
    int m = key.size();

    int new_lock[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_lock[i + n][j + n] = lock[i][j];
        }
    }

    for (int rotation = 0; rotation < 4; rotation++) {
        vector<vector<int>> key = rotate_a_matrix_by_90_degree(key);
        for (int x = 0; x < n * 2; x++) {
            for (int y = 0; y < n * 2; y++) {
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        new_lock[x + i][y + j] += key[i][j];
                    }
                }
                if (check(new_lock) == true) {
                    return true;
                }
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        new_lock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> key = { {0,0,0},{1,0,0},{0,1,1} };
    vector<vector<int>> lock = { {1,1,1},{1,1,0},{1,0,1} };
    cout << solution(key,lock) << endl;
	return 0;
}