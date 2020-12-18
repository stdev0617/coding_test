#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 이번 문제를 통해서 문제를 풀기 전에 예외 케이스를 만들어두는게 좋겠다는 생각을 함.
// 지금 걸린거 보면 예외들에서 많이 걸림.
// 입력되는 양 끝단의 값에 대해 예외처리할 수 있도록 항상 신경쓰자.

int personCountPerStages[200001] = { 0, };

bool compare(pair<int,double> ahead, pair<int,double> behind) {

    // 여기 틀림.
    // 같은 경우가 있기 때문에 이것도 체크하도록 아래와 같이 함.
    if (ahead.second != behind.second) {
        return ahead.second > behind.second;
    }
    else {
        return ahead.first < behind.first;
    }
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> lists;
    int countOfStages = N;
    int clearedPeople = stages.size();
    double failRate = 0;

    for (int i = 0; i < stages.size(); i++) {
        personCountPerStages[stages[i]]++;
    }

    // 여기 틀림
    // countOfStages가 아니라 stages.size()를 사용했음. 잘못함.
    for (int i = 1; i <= countOfStages; i++) {
        // 여기도 틀림
        // clearedPeople이 0일 수 있으므로, 해당 값이 0으로 나눠지지 않도록 처리해야함.
        // 특히, 프로그래머스에서는 0 처리를 따로 안해주기 때문에 프로그래머스에서는 그렇게 처리해줘야함.
        if (clearedPeople < 0) {
            failRate = 0;
        } else {
            // 여긴 수정.
            // 나눈 값의 결과를 캐스팅 하는게 아니라 각각 캐스팅해줘야함.
            failRate = (double)personCountPerStages[i] / (double)clearedPeople;
            clearedPeople -= personCountPerStages[i];
        }
        lists.push_back(make_pair(i, failRate));
    }

    sort(lists.begin(), lists.end(), compare);

    for (int i = 0; i < countOfStages; i++) {
        // 여기도 틀림.
        // 완료된 경우에 대해 처리해줘야함.
        if (lists[i].first>N) continue;
        answer.push_back(lists[i].first);
    }
    return answer;
}
int main() {
    int N = 5;
    vector<int> stages = { 1,2,2,1,3};
    vector<int> result = solution(N, stages);
    cout << "result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] <<  ",";
    }
	return 0;
}