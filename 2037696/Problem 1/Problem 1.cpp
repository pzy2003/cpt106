#include <iostream>
#include <vector>
using namespace std;
#define	LEN_MAX 64
vector<int> union_Array(int a[], int lenA, int b[], int lenB) {
	int idx = 0;
	vector<int> ret(a, a + lenA);
	for (int i = 0; i < lenB; i++) {//loop
		if (find(ret.begin(), ret.end(), b[i]) == ret.end()) {
			ret.push_back(b[i]);
		}
	}
	return ret;
}
int main()
{
	int a[LEN_MAX], b[LEN_MAX];
	int lenth_a, lenth_b;
	//input
	cout << "please input lenth of the first array";
	cin >> lenth_a ;
	cout << "please input the first array";
	for (int i = 0; i < lenth_a; i++) {
		cin >> a[i];
	}
	cout << "please input lenth of the second array";
	cin >> lenth_b;
	cout << "please input the second array";
	for (int i = 0; i < lenth_b; i++) {
		cin >> b[i];
	}
	// call subfunction
	vector<int> ans = union_Array(a, lenth_a, b, lenth_b);
	cout << "the result is";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}

}


