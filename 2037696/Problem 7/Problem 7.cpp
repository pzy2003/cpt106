#include <iostream>
#include <vector>
#include <string>
class Product {
	std::string _id;
	std::string _name;
	int _amount;
	double _price;
public:
	Product():_amount(0),_id(""),_name(""),_price(0.0) {}
	Product(std::string m_id, std::string m_name, int m_amount, double m_price);
	std::string id() { return _id; }
	std::string name() { return _name; }
	int amount() { return _amount; }
	double price() { return _price; }
	void add_amount(int a) { _amount += a; }
};
enum Gender { MALE = 0, FEMALE };
class Person {
	std::string _name;
	std::string _mobile;
	std::string _address;
	enum Gender _gender = MALE;
public:
	Person() {};
	Person(std::string m_name, std::string m_mobile, std::string m_address, enum Gender m_gender);
	std::string name() { return _name; }
	std::string mobile() { return _mobile; }
	std::string address() { return _address; }
	enum Gender gender() { return _gender; }
};
class Customer :public Person {
	std::string _id;
	std::vector<Product> _products;
	double _capital;
public:
	Customer() { _capital = 1000; }
	Customer(std::string _id, std::string _name, std::string _mobile, std::string _address, enum Gender gender);
	std::string id() { return _id; }
	double capital() { return _capital; }
	void add_product(std::string _id, std::string _name, double _price, int _amount);
	void show_products();
	void check_products();
};
class Manager :public Person {
	int age;
	std::string title;
public:
	Manager() {};
	void add_product(std::vector<Product>& _products);
	void add_customer(std::vector<Customer>& cts);
};
class MainProcess {
	std::vector<Product> _products;
	std::vector<Customer> cts;
	Manager manager;
	Customer* now;
private:
	int page_1();
	int page_2();
	int page_3();
	int manager_method();
	void func2();
public:
	MainProcess() {};
	void process();
};

Product::Product(std::string m_id, std::string m_name, int m_amount, double m_price)
	
{
	_id = m_id;
	_name = m_name;
	_amount = m_amount;
	_price = m_price;
}

Person::Person(std::string m_name, std::string m_mobile, std::string m_address, Gender m_gender)
{
	_name = m_name;
	_mobile = m_mobile;
	_address = m_address;
	_gender = m_gender;
}
Customer::Customer(std::string _id, std::string _name, std::string _mobile, std::string _address, Gender gender)
	: Person(_name, _mobile, _address, gender), _id(_id)
{
	_capital = 1000;
}

void Customer::add_product(std::string _id, std::string _name, double _price, int _amount) {
	for (auto x : _products) {
		if (x.id() == _id) {
			x.add_amount(_amount);
			return;
		}
	}
	Product p(_id, _name, _amount, _price);
	_products.push_back(p);
}
void Customer::show_products() {
	std::string temp;
	std::cout << "please input a product _id";
	std::cin >> temp;
	if (temp != "*") {
		bool flag = true;
		for (auto x : _products) {
			if (x.id() == temp) {
				flag = false;
				std::cout << "id   name    amount    price" << std::endl;
				std::cout << x.id() << "  " << x.name() << "  " << x.amount() << "  " << x.price() << std::endl;
				break;
			}
		}
		if (flag) {
			std::cout << "No product found" << std::endl;
		}
	}
	else {
		std::cout << "id   name    amount    price" << std::endl;
		for (auto x : _products) {
			std::cout << x.id() << "  " << x.name() << "  " << x.amount() << " " << x.price() << std::endl;
		}
	}
}

void Customer::check_products() {
	double total = 0.0;
	std::cout << "_id   name    amount    price" << std::endl;
	for (auto x : _products) {
		total += x.price() * x.amount();
		std::cout << x.id() << "  " << x.name() << "  " << x.amount() << "  " << x.price() << std::endl;
	}
	std::cout << "total price:" << total << "  costom id:" << id() << "  costom name:" << name();
	std::cout << "  costom capital:" << capital() << std::endl;
}

void Manager::add_product(std::vector<Product>& _products)
{
	std::string _id, _name;
	int _amount;
	double _price;
	std::cout << "please input product id:";
	std::cin >> _id;
	std::cout << "please input product name:";
	getline(std::cin, _name);
	getline(std::cin, _name);
	std::cout << "please input product amount:";
	std::cin >> _amount;
	std::cout << "please input product price:";
	std::cin >> _price;
	Product p(_id, _name, _amount, _price);
	_products.push_back(p);
}
void Manager::add_customer(std::vector<Customer>& cts)
{
	std::string _id, _name, _mobile, _address;
	int g;
	Gender gender = MALE;
	std::cout << "please input customer id:";
	std::cin >> _id;
	std::cout << "please input customer name:";
	std::cin >> _name;
	std::cout << "please input customer gender:";
	std::cin >> g;
	if (g == 2)gender = FEMALE;
	std::cout << "please input customer mobile:";
	std::cin >> _mobile;
	std::cout << "please input customer address:";
	std::cin >> _address;
	cts.push_back(Customer(_id, _name, _mobile, _address, gender));
}
int MainProcess::page_1()
{
	int ret;
	std::cout << "**********************" << std::endl;
	std::cout << "*1:manager           *" << std::endl;
	std::cout << "*2:custom            *" << std::endl;
	std::cout << "*3:quit              *" << std::endl;
	std::cout << "**********************" << std::endl;
	std::cout << "please input:";
	std::cin >> ret;
	return ret;
}
int MainProcess::page_2()
{
	int ret;
	std::cout << "**********************" << std::endl;
	std::cout << "*1:add product       *" << std::endl;
	std::cout << "*2:qury product      *" << std::endl;
	std::cout << "*3:add customs       *" << std::endl;
	std::cout << "*4:query customs     *" << std::endl;
	std::cout << "*5:move to parent    *" << std::endl;
	std::cout << "**********************" << std::endl;
	std::cout << "please input:";
	std::cin >> ret;
	return ret;
}
int MainProcess::page_3()
{
	int ret;
	std::cout << "**********************" << std::endl;
	std::cout << "*1:add product to cart*" << std::endl;
	std::cout << "*2:qury product in cart*" << std::endl;
	std::cout << "*3:check up          *" << std::endl;
	std::cout << "*4:move to parent    *" << std::endl;
	std::cout << "**********************" << std::endl;
	std::cout << "please input:";
	std::cin >> ret;
	return ret;
}
int MainProcess::manager_method()
{
	std::string temp;
	int opt;
	while (1) {
		opt = page_2();
		switch (opt) {
		case 1:
			while (1) {
				manager.add_product(_products);
				std::cout << "continue add another product?  1:yes  0:no";
				std::cin >> opt;
				if (opt == 0)break;
			}
			break;
		case 2:
			std::cout << "please input a product id";
			std::cin >> temp;
			if (temp != "*") {
				bool flag = true;
				for (auto x : _products) {
					if (x.id() == temp) {
						std::cout << "id   name    amount    price" << std::endl;
						std::cout << x.id() << "  " << x.name() << "  " << x.amount() << "  " << x.price() << std::endl;
						flag = false;
						break;
					}
				}
				if (flag) {
					std::cout << "No product found" << std::endl;
				}
			}
			else {
				std::cout << "id   name    amount    price" << std::endl;
				for (auto x : _products) {
					std::cout << x.id() << "  " << x.name() << "  " << x.amount() << "  " << x.price() << std::endl;
				}
			}
			break;
		case 3:
			while (1) {
				manager.add_customer(cts);
				std::cout << "continue add another custom?  1:yes  0:no";
				std::cin >> opt;
				if (opt == 0)break;
			}
			break;
		case 4:
			std::cout << "please input a custom id";
			std::cin >> temp;
			if (temp != "*") {
				bool flag = true;
				for (auto y : cts) {
					if (y.id() == temp) {
						std::cout << "id   name    mobile  gender    address" << std::endl;
						std::cout << y.id() << "  " << y.name() << "  ";
						std::cout << y.mobile() << "  " << y.gender() << "  ";
						std::cout << y.address() << std::endl;
						flag = false;
						break;
					}
				}
				if (flag) {
					std::cout << "No customer found" << std::endl;
				}
			}
			else {
				std::cout << "id   name    moblie    gender   address" << std::endl;
				for (auto y : cts) {
					std::cout << y.id() << "  " << y.name() << "  " << y.mobile() << "  ";
					std::cout << y.gender() << "  " << y.address() << std::endl;
				}
			}
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
	}
}
void MainProcess::func2()
{
	std::string custom_id;
	std::cout << "please input your custom id";
	std::cin >> custom_id;
	size_t i;
	for (i = 0; i < cts.size(); i++) {
		if (cts[i].id() == custom_id) {
			now = &cts[i];
			break;
		}
	}
	if (i == cts.size())return;
	while (1) {
		std::string p_id;
		int p_amount;
		size_t i;
		int opt = page_3();
		bool flag = false;
		switch (opt) {
		case 1:
			std::cout << "please input product id";
			std::cin >> p_id;
			std::cout << "please input  product amount";
			std::cin >> p_amount;
			for (i = 0; i < _products.size(); i++) {
				if (_products[i].id() == p_id) {
					flag = true;
					break;
				}
			}
			//正常购物
			if (flag) {
				if (_products[i].amount() < p_amount || \
					_products[i].price() * p_amount > now->capital()) {
					std::cout << "can not buy it" << std::endl;
					break;
				}
				now->add_product(_products[i].id(), _products[i].name(), _products[i].price(), p_amount);
			}
			break;
		case 2:
			now->show_products();
			break;
		case 3:
			now->check_products();
			break;
		case 4:
			return;
			break;
		default:
			break;
		}
	}
}
void MainProcess::process()
{
	int opt = 0;
	while (1) {
		opt = page_1();
		switch (opt)
		{
		case 1:
			manager_method();
			break;
		case 2:
			func2();
			break;
		case 3:
			return;
			break;
		default:
			break;
		}
	}
}


int main()
{
	MainProcess mp;
	mp.process();
	return 0;
}

