#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int LEN_MAX = 64;
//student information
class Student {
public:
	string stuId;
	string name;
	double mathScore,chineseScore,englishScore;
	double average;
};
bool cmp(Student x, Student y) {
	return x.average > y.average;
}
int main()
{
	Student stus[LEN_MAX];
	int n;
	double overall_grades = 0.0;
	cout << "please input numbers of students";
	cin >> n;
	cout << "please input students information"<<endl;
	for (int i = 0; i < n; i++) {
		cin >> stus[i].stuId >> stus[i].name >> stus[i].mathScore >> stus[i].chineseScore >> stus[i].englishScore;
		stus[i].average = 0.0;
		stus[i].average += stus[i].mathScore / 3;
		stus[i].average += stus[i].chineseScore / 3 ;
		stus[i].average += stus[i].englishScore / 3 ;
		overall_grades += stus[i].average / n;//Calculate the average overall grade
	}
	//sort function
	sort(stus, stus + n, cmp);
	cout << "All students are listed below in descending order:" << endl;
	for (int i = 0; i < n; i++) {
		cout << stus[i].stuId << "  " << stus[i].average << endl;
	}
	cout << "Students with below average scores are:" << endl;
	for (int i = 0; i < n; i++) {
		if (stus[i].average < overall_grades)
			cout << stus[i].stuId << "  " << stus[i].average << endl;
	}
}
