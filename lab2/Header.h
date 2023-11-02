#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include <iomanip>
using namespace std;
extern void input_check_int(string &str);
extern void input_check_double(string &str);
extern string input_check_string();
class Product {
protected:
	string name;
	float price;
	double discountPercent;
public:
	Product();
	Product(string name, float price, double discountPercent);
	void set_name(string name);
	string get_name();
	void set_price(float price);
	double get_price();
	void set_discountPercent(double discountPercent);
	double getdiscountPercent();
	double getDiscountAmount();
	double getDiscountPrice();
	virtual void edit_info();
	virtual void printDescription();

};
class Book :public virtual Product {
protected:
	string author;
public:
	Book();
	Book(string name, float price, double discountPercent, string author);
	void set_author(string author);
	string get_author();
	void printDescription();
	void edit_info();
};
class Movie : public virtual Product {
protected:
	int year;
public:
	Movie();
	Movie(string name, float price, double discountPercent, int year);
	void set_year(int year);
	int get_year();
	void printDescription();
	void edit_info();
};
class Videocourse : public Book, public Movie {
	public:
	Videocourse();
	Videocourse(string name, float price, double discountPercent, int year, string author);
	void printDescription();
	void edit_info();
};
