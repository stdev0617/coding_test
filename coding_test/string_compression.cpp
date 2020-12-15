#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

// 틀렸음. substr을 잊고있었는데, 이걸 활용해서 다시 풀어보자.
string compression(string input, int num) {
	int tmpCnt = 0;
	int cnt = 0;
	string total;
	for (int idx = 0; idx < input.length()-num; idx++) {
		string tmpStr;
		for (int pos = idx+num; pos < idx+num+num; pos++) {
			if (input[idx] == input[pos]) {
				tmpCnt++;
				tmpStr = tmpStr + input[pos];
			}
		}
			
		while (1) {
			if (num == tmpCnt) {
				cnt++;
			}
			else {
				if (cnt > 0) {
					total = total + to_string(cnt) + tmpStr;
				}
				else {
					total = total + tmpStr;
				}
				break;
			}

			idx = idx + num-1;
			tmpCnt = 0;

			for (int pos = idx; pos < num; pos++) {
				if (input[idx] == input[pos]) {
					tmpCnt++;
				}
			}
		}
		cnt = 0;
	}
	return total;
}

int main() {
	string input = "aabbaccc";
	cout << compression(input,2) << endl;
	return 0;
}