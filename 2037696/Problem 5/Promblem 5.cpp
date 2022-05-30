#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
class Circle {// represent circle information 
public:
	Circle();
	double cal_area() const;
	Circle operator+(const Circle& a);
	int x;
	int y;
	double radius;
};
void calculate_position(const Circle& a, const Circle& b);
int main() {
	int xx, yy;
	double rr;
	Circle circle1, circle2;
	cout << "Please separate the center and radius of the two circles:" << endl;
	cin >> circle1.x >> circle1.y >> circle1.radius;
	cin >> circle2.x >> circle2.y >> circle2.radius;

	calculate_position(circle1, circle2);
}

Circle::Circle() {
}

double Circle::cal_area() const
{
	return 3.14159 * radius * radius;
}

Circle Circle::operator+(const Circle& a)
{//Class overloaded operators
	Circle ret;
	ret.x = this->x;
	ret.y = this->y;
	double ar = this->cal_area() + a.cal_area();
	ret.radius = sqrt(ar / 3.1415);
	return ret;
}
void calculate_position(const Circle& a, const Circle& b) {
	//Calculate the relative positions of two circles
	double distance = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	distance -= (a.radius + b.radius);
	//Floating point numbers in the computer are not completely accurate
	if (distance > 0.001)cout << "Two circular round";
	else if (distance < -0.001)cout << "Two circular intersection";
	else cout << "Two circle tangent";
}