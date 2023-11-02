#include"Header.h"
Product::Product() {
	name = "no name";
	price = 0;
	discountPercent = 0;
}
Product::Product(string name, float price, double discountPercent) {
	this->name = name;
	this->price = price;
	this->discountPercent = discountPercent;
};
void Product::set_name(string name) {
	this->name = name;
}
string Product:: get_name() {
	return name;
};
void Product::set_price(float price) {
	this->price = price;
}
double Product::get_price() {
	return price;
}
void Product::set_discountPercent(double discountPercent) {
	this->discountPercent = discountPercent;
}
double Product::getdiscountPercent() {
	return discountPercent;
}
double Product::getDiscountAmount() {
	return discountPercent * 0.01 * price;
};
double Product::getDiscountPrice() {
	return price - discountPercent * 0.01 * price;
};
void Product::edit_info() {
};
void  Product::printDescription() {};
Book::Book() {
	name = "no name";
	price = 0;
	discountPercent = 0;
	author = "no author";
};
Book::Book(string name, float price, double discountPercent, string author) {
	this->name = name;
	this->price = price;
	this->discountPercent = discountPercent;
	this->author = author;
}
void Book::set_author(string author) {
	this->author = author;
}
string Book::get_author() {
	return author;
}
void Book::printDescription() {
	cout << left << setw(15) << "�����" << right << setw(30) << get_name() << endl;
	cout << left << setw(15) << "���������" << right << setw(30) << get_price() <<" ���" << endl;
	cout << left << setw(15) << "������� ������" << right << setw(30) << getdiscountPercent() << "%" << endl;
	cout << left << setw(15) << "����� ������" << right << setw(30) << getDiscountAmount() << endl;
	cout << left << setw(15) << "���� �� �������" << right << setw(30) << getDiscountPrice() << endl;
};
void Book::edit_info() {
	string choice = "";
	string str = "";
	cout << "������� ����� �� 1 �� 4, ����� �������� ������ ��������" << endl;
	cout << "1.�������� �����" << endl;
	cout << "2.��������� �����" << endl;
	cout << "3.������� ������ �� �����" << endl;
	cout << "4.����� �����" << endl;
	input_check_int(choice);
	if (stoi(choice) == 1) {
		cout << "������� ����� �������� �����" << endl;
		getline(cin, str);
		set_name(str);
	}
	else if (stoi(choice) == 2) {
		cout << "������� ����� ��������� ����� (������ ������� �� ���������)" << endl;
		input_check_double(str);
		set_price(stod(str));
	}
	else if (stoi(choice) == 3) {
		cout << "������� ����� ������� ������ �� ����� (� ���������)" << endl;
		do {
			input_check_double(str);
			if (stod(str) >= 100) {
				cout << "������ �� ����� ���� 100 � ����� ���������. ������� ��� ���" << endl;
			}
		} while (stod(str) >= 100);
		set_discountPercent(stod(str));
	}
	else if (stoi(choice) == 4) {
		cout << "������� ������ ������" << endl;
		input_check_int(str);
		set_author(str);
	}
	else {
		cout << "������ ������ �� ����������" << endl;
	}
};
Movie::Movie() {
	name = "no name";
	price = 0;
	discountPercent = 0;
	year = 0;
}
Movie::Movie(string name, float price, double discountPercent, int year) {
	this->name = name;
	this->price = price;
	this->discountPercent = discountPercent;
	this->year = year;
}
void Movie::set_year(int year) {
	this->year = year;
}
int Movie::get_year() {
	return year;
};
void Movie::printDescription() {
	cout << left << setw(15) << "�����" << right << setw(30) << get_name() << endl;
	cout << left << setw(15) << "��� ��������" << right << setw(30) << get_year() << endl;
	cout << left << setw(15) << "���������" << right << setw(30) << get_price() << " ���" << endl;
	cout << left << setw(15) << "������� ������" << right << setw(30) << getdiscountPercent() << "%" << endl;
	cout << left << setw(15) << "����� ������" << right << setw(30) << getDiscountAmount() << endl;
	cout << left << setw(15) << "���� �� �������" << right << setw(30) << getDiscountPrice() << endl;
}
void Movie::edit_info() {
	string choice = "";
	string str = "";
	cout << "������� ����� �� 1 �� 4, ����� �������� ������ ��������" << endl;
	cout << "1.�������� ������" << endl;
	cout << "2.��������� ������" << endl;
	cout << "3.������� ������ �� �����" << endl;
	cout << "4.��� �������� ������" << endl;
	input_check_int(choice);
	if (stoi(choice) == 1) {
		cout << "������� ����� �������� ������" << endl;
		getline(cin, str);
		set_name(str);
	}
	else if (stoi(choice) == 2) {
		cout << "������� ����� ��������� ������ (������ ������� �� ���������)" << endl;
		input_check_double(str);
		set_price(stod(str));
	}
	else if (stoi(choice) == 3) {
		cout << "������� ����� ������� ������ �� ����� (� ���������)" << endl;
		do {
			input_check_double(str);
			if (stod(str) >= 100) {
				cout << "������ �� ����� ���� 100 � ����� ���������. ������� ��� ���" << endl;
			}
		} while (stod(str) >= 100);
		set_discountPercent(stod(str));
	}
	else if (stoi(choice) == 4) {
		cout << "������� ����� ��� �������� ������" << endl;
		do{
		input_check_int(str);
		if (stoi(str) < 1895 || stoi(str) > 2023) {
			cout << "����� �� ��� ���� ������� ������ 1895 ���� � �� ����� 2023" << endl;
		}
	} while (stoi(str) < 1895 || stoi(str) > 2023);
		set_year(stoi(str));
	}
};
Videocourse::Videocourse() {
	name = "no name";
	price = 0;
	discountPercent = 0;
	year = 0;
	author = "no author";
};
Videocourse:: Videocourse(string name, float price, double discountPercent, int year, string author) {
	this->name = name;
	this->price = price;
	this->discountPercent = discountPercent;
	this->author = author;
	this->year = year;
}
void Videocourse::printDescription() {
	cout << left << setw(15) << "���������" << right << setw(30) << get_name() << endl;
	cout << left << setw(15) << "�����" << right << setw(30) << get_author() << endl;
	cout << left << setw(15) << "��� �������" << right << setw(30) << get_year() << endl;
	cout << left << setw(15) << "���������" << right << setw(30) << get_price() << " ���" << endl;
	cout << left << setw(15) << "������� ������" << right << setw(30) << getdiscountPercent() << "%" << endl;
	cout << left << setw(15) << "����� ������" << right << setw(30) << getDiscountAmount() << endl;
	cout << left << setw(15) << "���� �� �������" << right << setw(30) << getDiscountPrice() << endl;
}
void Videocourse::edit_info() {
	string choice = "";
	string str = "";
	cout << "������� ����� �� 1 �� 5, ����� �������� ������ ��������" << endl;
	cout << "1.�������� ����������" << endl;
	cout << "2.��������� ����������" << endl;
	cout << "3.������� ������ �� ���������" << endl;
	cout << "4.����� ����������" << endl;
	cout << "5.��� ������ ����������" << endl;
	input_check_int(choice);
	if (stoi(choice) == 1) {
		cout << "������� ����� �������� ����������" << endl;
		getline(cin, str);
		set_name(str);
	}
	else if (stoi(choice) == 2) {
		cout << "������� ����� ��������� ���������� (������ ������� �� ���������)" << endl;
		input_check_double(str);
		set_price(stod(str));
	}
	else if (stoi(choice) == 3) {
		cout << "������� ����� ������� ������ �� ���������(� ���������)" << endl;
		do {
			input_check_double(str);
			set_discountPercent(stod(str));
			if (stod(str) >= 100) {
				cout<<"������� ������ �� ����� ���� 100 � �����. ������� ��� ���" << endl;
			}
		} while (stod(str)>=100);
	}
	else if (stoi(choice) == 4) {
		cout << "������� ������ ������ ����������" << endl;
		str = input_check_string();
		set_author(str);
	}
	else if (stoi(choice) == 5) {
		cout << "������� ����� ��� ������� ����������" << endl;
		do {
			input_check_int(str);
			set_year(stoi(str));
			if (stoi(str) < 1895 || stoi(str) > 2023) {
				cout << "��������� �� ��� ���� ������� ������ 1895 ���� � �� ����� 2023. ������� �����" << endl;
			}
		} while (stoi(str)<1895||stoi(str)>2023);
	}
};
