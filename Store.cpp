#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <utility>  
#include <time.h>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

void StringToStruct(string s, Date d)
{
	d.year += s[0] * 1000 + s[1] * 100 + s[2] * 10 + s[3];
	d.month += s[5] * 10 + s[6];
	d.day += s[8] * 10 + s[9];
}

class Product{
private: 
	string name;
	string brand;
	double price;
	double qnty;
	string eDate;
	Date expDate;
public: 
	Product(string n, string b, double p)
	{
		name = n;
		brand = b;
		price = p;
		qnty = 0.00;
	}

	void setExpDate(string eDate)
	{
		StringToStruct(eDate, expDate);
	}

	Date getExpDate()
	{
		return expDate;
	}

	string getName()
	{
		return name;
	}

	string getBrand()
	{
		return brand;
	}

	double getPrice()
	{
		return price;
	}

	void setQuantity(double q)
	{
		qnty = q;
	}

	double getQuantity()
	{
		return qnty;
	}

};

struct Clothing : public Product{
private: 
	string size;
	string color;
public:
	Clothing(string n, string b, double p, string s, string c) : Product(n, b, p)
	{
		size = s;
		color = c;
	}

	string getSize()
	{
		return size;
	}

	string getColor()
	{
		return color;
	}
};

struct Appliance : public Product {
private: 
	string model;
	string productionDate;
	double weight;
public:
	Appliance(string n, string b, double p, string m, string pD, double w) : Product(n, b, p)
	{
		model = m;
		productionDate = pD;
		weight = w;
	}

	string getModel()
	{
		return model;
	}
};


class Cashier{
public:
	Date DATOP;
	void printReceipt(vector<Product>& cart, string DateAndTimeOfPurchase){
		double total = 0.00;
		cout << DateAndTimeOfPurchase << endl<< endl;
		cout << "---Products---" << endl << endl << endl;
		for (int i = 0; i < cart.size(); i++) {
			cout << cart[i].getName() << " - " << cart[i].getBrand() << endl;
			cout << cart[i].getQuantity() << " x $" << cart[i].getPrice() << " = " << cart[i].getQuantity() * cart[i].getPrice() << endl;
			total += cart[i].getQuantity() * cart[i].getPrice();
		}
		int j = 0;
		while (j < 50)
		{
			cout << "-";
			j++;
		}

		cout << endl;
		cout << "SUBTOTAL: " << total << endl << endl;
		cout << "TOTAL: " << total << endl;
	}
};




int main()
{
	Cashier P;

	string DateAndTimeOfPurchase = "2021-06-14 12:34:56";
	Product F = { "apple", "BrandA", 1.5 };
	F.setExpDate("2021-06-14");
	Product B = { "milk", "BrandM", 0.99 };
	B.setExpDate("2022-02-02");
	Clothing C = { "t-shirt", "BrandT", 15.99, "M", "violet" };
	Appliance A = { "laptop", "BrandL", 2345, "ModelL", "2021 - 03 - 03", 1.125 };

	F.setQuantity(2.45);
	B.setQuantity(3.00);
	C.setQuantity(2.00);
	A.setQuantity(1.00);

	vector<Product> cart;
	cart.push_back(F);
	cart.push_back(B);
	cart.push_back(C);
	cart.push_back(A);

	P.printReceipt(cart, DateAndTimeOfPurchase);
	
	

	return 0;
}