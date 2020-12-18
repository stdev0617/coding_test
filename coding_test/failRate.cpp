#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �̹� ������ ���ؼ� ������ Ǯ�� ���� ���� ���̽��� �����δ°� ���ڴٴ� ������ ��.
// ���� �ɸ��� ���� ���ܵ鿡�� ���� �ɸ�.
// �ԷµǴ� �� ������ ���� ���� ����ó���� �� �ֵ��� �׻� �Ű澲��.

int personCountPerStages[200001] = { 0, };

bool compare(pair<int,double> ahead, pair<int,double> behind) {

    // ���� Ʋ��.
    // ���� ��찡 �ֱ� ������ �̰͵� üũ�ϵ��� �Ʒ��� ���� ��.
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

    // ���� Ʋ��
    // countOfStages�� �ƴ϶� stages.size()�� �������. �߸���.
    for (int i = 1; i <= countOfStages; i++) {
        // ���⵵ Ʋ��
        // clearedPeople�� 0�� �� �����Ƿ�, �ش� ���� 0���� �������� �ʵ��� ó���ؾ���.
        // Ư��, ���α׷��ӽ������� 0 ó���� ���� �����ֱ� ������ ���α׷��ӽ������� �׷��� ó���������.
        if (clearedPeople < 0) {
            failRate = 0;
        } else {
            // ���� ����.
            // ���� ���� ����� ĳ���� �ϴ°� �ƴ϶� ���� ĳ�����������.
            failRate = (double)personCountPerStages[i] / (double)clearedPeople;
            clearedPeople -= personCountPerStages[i];
        }
        lists.push_back(make_pair(i, failRate));
    }

    sort(lists.begin(), lists.end(), compare);

    for (int i = 0; i < countOfStages; i++) {
        // ���⵵ Ʋ��.
        // �Ϸ�� ��쿡 ���� ó���������.
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