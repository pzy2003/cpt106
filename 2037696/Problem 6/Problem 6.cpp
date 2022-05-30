#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class Data {
public:
	Data();
	Data(string path);
	bool save(string path);
	bool insert(double x, double y);
	bool remove(double x, double y);
	bool find(double x, double y);
	vector<double> Abscissa_data, Ordinate_data;
};
class Fitting {
public:
	Fitting() { k = 0.0; b = 0.0; };
	void calculate(Data& data);
	double get_distance(double x, double y);
	vector<double> get_distances(Data& data);
	double get_best_dot(Data& data);
	double get_worse_dot(Data& data);
	double get_se(Data& data);
	double k, y = -1.0, b;
};
int main()
{
	Data data("data.txt");
	Fitting fitting;
	double tmp_x, tmp_y;
	fitting.calculate(data);
	cout << "calculate result：(" << fitting.k << ")x-y+(" << fitting.b << ")=0" << endl;
	cout << "Please enter the point you want to find : ";
	cin >> tmp_x >> tmp_y;
	if (data.find(tmp_x, tmp_y) == true) {
		cout << "There exists this point" << endl;
	}
	else {
		cout << "There dose not exists this point" << endl;
	}
	cout << "worse distance from the file is "<<fitting.get_worse_dot(data) << endl;
	cout << "standard error is:" << fitting.get_se(data) << endl;
	cout << "Please enter a dot to remove：";
	cin >> tmp_x >> tmp_y;
	data.remove(tmp_x, tmp_y);
	cout << "Data has been saved";
	data.save("save.txt");
	return 0;
}

Data::Data()
{
}

Data::Data(string path)
{
	ifstream ifs;
	ifs.open(path, ios::in);
	if (!ifs.is_open())exit(0);
	string line, temp;
	while (getline(ifs, line)) {
		//Read the entire string line into the string stream sin
		istringstream sin(line); 
		//Data points are separated by space
		getline(sin, temp);
		Abscissa_data.push_back(stof(temp));
		getline(sin, temp);
		Ordinate_data.push_back(stof(temp));
	}
	ifs.close();
}

bool Data::save(string path)
{
	ofstream file(path);
	if (!file)
	{
		return false;
	}
	for (int i = 0; i < Abscissa_data.size(); i++) {
		file << Abscissa_data[i] << " ";
		file << Ordinate_data[i] << endl;
	}
	file.close();
	return true;
}

bool Data::insert(double x, double y)
{
	if (find(x, y) == true)return false;
	Abscissa_data.push_back(x);
	Ordinate_data.push_back(y);
	return true;
}

bool Data::remove(double x, double y)
{
	for (int i = 0; i < Abscissa_data.size(); i++) {
		if (abs(Abscissa_data[i] - x) < 0.0001 && abs(Ordinate_data[i] - y) < 0.001) {
			Abscissa_data.erase(Abscissa_data.begin() + i);
			Ordinate_data.erase(Ordinate_data.begin() + i);
			return true;
		}
	}
	return false;
}
bool Data::find(double x, double y)
{
	//Floating-point numbers have limited precision and are considered when the data is approximate
	for (int i = 0; i < Abscissa_data.size(); i++) {
		if (abs(Abscissa_data[i] - x) < 0.0001 &&
			abs(Ordinate_data[i] - y) < 0.0001) {
			return true;
		}
	}
	return false;
}

void Fitting::calculate(Data& data)
{
	int len = data.Abscissa_data.size();
	double a1 = 0, a2 = 0, b1 = 0, b2 = 0;
	for (int i = 0; i <len ; i++)
	{
		a1 += pow(data.Abscissa_data[i],2.0);
		a2 += data.Abscissa_data[i];
		b1 += pow(data.Abscissa_data[i],2.0);
		b2 += data.Ordinate_data[i];
	}
	k = (b1 *len - a2 * b2) / (a1 * len - a2 * a2);
	b = (a1 * b2 - a2 * b1) / (a1 * len - a2 * a2);
}

double Fitting::get_distance(double x, double y)
{
	double ans = 0.0;
	ans = fabs(pow(x, 2.0) + pow(y, 2.0) + b);
	ans /= sqrt(pow(x, 2.0) + pow(y, 2.0));
	return ans;
}

vector<double> Fitting::get_distances(Data& data)
{
	vector<double> ans;
	for (int i = 0; i < data.Abscissa_data.size(); ++i) {
		ans.push_back(get_distance(data.Abscissa_data[i], data.Ordinate_data[i]));
	}
	return ans;
}

double Fitting::get_best_dot(Data& data)
{
	vector<double>  distances;
	distances = get_distances(data);
	auto it = min_element(distances.begin(), distances.end());
	int idx= it - distances.begin();
	cout << "min distance piont:(" << data.Abscissa_data[idx] << "," << data.Ordinate_data[idx] << ")" << endl;
	return *it;
}

double Fitting::get_worse_dot(Data& data)
{
	vector<double>  distances;
	distances = get_distances(data);
	auto it = max_element(distances.begin(), distances.end());
	int idx = it - distances.begin();
	cout << "min distance piont:(" << data.Abscissa_data[idx] << "," << data.Ordinate_data[idx] << ")" << endl;
	return *it;
}

double Fitting::get_se(Data& data)
{
	vector<double> distances = get_distances(data);
	double mean = 0.0, std_err = 0.0;
	for (auto d : distances) {
		mean += d;
	}
	mean /= distances.size();
	for (auto d : distances) {
		std_err += pow((d - mean), 2.0);
	}
	std_err /= distances.size() - 1;
	std_err = sqrt(std_err);
	return std_err;
}

