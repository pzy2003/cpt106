#include <iostream>
#include <string>
#include <list>
#include <algorithm>
using namespace std;
const int MAX_LEN = 64;
//student information
class Student {
public:
	string stuId,name;
	double mathScore, chineseScore, englishScore;
	double average;
};
//define a list node
class Node {
public:
	Node* next=nullptr;
	Student stu;
};
int main()
{
	int n;
	double overall_grades = 0.0;
	cout << "please input numbers of students";
	cin >> n;
	Node* head = new Node, *idx=head;
	for (int i = 0; i < n-1; i++) {
		idx->next = new Node;
		idx = idx->next;
	}
	
	cout << "please input students information" << endl;
	idx = head;
	while (idx != nullptr) {
		cin >> idx->stu.stuId >> idx->stu.name >> idx->stu.mathScore >> idx->stu.chineseScore >> idx->stu.englishScore;
		idx->stu.average = 0.0;
		idx->stu.average += idx->stu.mathScore / 3;
		idx->stu.average += idx->stu.chineseScore / 3;
		idx->stu.average += idx->stu.englishScore / 3;
		overall_grades += idx->stu.average / n;//Calculate the average overall grade
		idx = idx->next;
	}
	
	//sort (bubbleSort)
	for (int i = 0; i < n; ++i) {
		auto pre = head;
		auto cur = head->next;
		bool flag = false;
		for (int j = 0; j < n - i - 1; ++j) {
			if (cur != NULL && pre->stu.average > cur->stu.average) {
				swap(pre->stu, cur->stu);
				flag = true;
			}
			pre = pre->next;
			cur = cur->next;
		}
		if (!flag)   break;
	}

	//output
	cout << "All students are listed below in descending order:" << endl;
	idx = head;
	while (idx != nullptr) {
		cout << idx->stu.stuId << "  " << idx->stu.average << endl;
		idx = idx->next;
	}

	cout << "Students with below average scores are:" << endl;
	idx = head;
	while (idx != nullptr) {
		if (idx->stu.average < overall_grades)
			cout << idx->stu.stuId << "  " << idx->stu.average << endl;
		idx = idx->next;
	}
}

