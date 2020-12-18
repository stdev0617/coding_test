#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student {
	string name;
	int korean;
	int english;
	int math;
};

bool sortStudent(student firstStudent, student secondStudent) {
	// 왼쪽이 크면 내림차순, 오른쪽이 크면 오름차순!
	if (firstStudent.korean > secondStudent.korean) {
		return true;
	}
	else if (firstStudent.korean == secondStudent.korean) {
		if (firstStudent.english < secondStudent.english) {
			return true;
		}
		else if (firstStudent.english == secondStudent.english) {
			if (firstStudent.math > secondStudent.math) {
				return true;
			}
			else if (firstStudent.math == secondStudent.math) {
				if (firstStudent.name < secondStudent.name) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else
	{
		return false;
	}
}

vector<string> getSortedNames(vector<student> students) {
	sort(students.begin(), students.end(), sortStudent);
	vector<string> nameList;
	for (int i = 0; i < students.size(); i++) {
		nameList.push_back(students[i].name);
	}
	return nameList;
}

int main() {
	vector<student> studentList = {
		{"Junkyu",50,60,100},
		{"Sangkeun",80,60,50},
		{"Sunyoung", 80,70,100},
		{"Soong",50,60,90},
		{"Haebin",50,60,100},
		{"Kangsoo",60,80,100},
		{"Donghyuk",80,60,100},
		{"Sei",70,70,70},
		{"Wonseob",70,70,90},
		{"Sanghyun",70,70,80},
		{"nsj",80,80,80},
		{"Taewhan",50,60,90} };
	vector<string> nameList = getSortedNames(studentList);
	cout << "results: ";
	for (int i = 0; i < nameList.size(); i++) {
		if (i == nameList.size() - 1) {
			cout << nameList[i];
		}
		else {
			cout << nameList[i] << ", ";
		}
	}
	return 0;
}