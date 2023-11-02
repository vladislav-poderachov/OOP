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
	cout << left << setw(15) << "Книга" << right << setw(30) << get_name() << endl;
	cout << left << setw(15) << "Стоимость" << right << setw(30) << get_price() <<" руб" << endl;
	cout << left << setw(15) << "Процент скидки" << right << setw(30) << getdiscountPercent() << "%" << endl;
	cout << left << setw(15) << "Сумма скидки" << right << setw(30) << getDiscountAmount() << endl;
	cout << left << setw(15) << "Цена со скидкой" << right << setw(30) << getDiscountPrice() << endl;
};
void Book::edit_info() {
	string choice = "";
	string str = "";
	cout << "Введите число от 1 до 4, чтобы изменить нужный параметр" << endl;
	cout << "1.Название книги" << endl;
	cout << "2.Стоимость книги" << endl;
	cout << "3.Процент скидки на книгу" << endl;
	cout << "4.Автор книги" << endl;
	input_check_int(choice);
	if (stoi(choice) == 1) {
		cout << "Введите новое название книги" << endl;
		getline(cin, str);
		set_name(str);
	}
	else if (stoi(choice) == 2) {
		cout << "Введите новую стоимость книги (валюту вводить не требуется)" << endl;
		input_check_double(str);
		set_price(stod(str));
	}
	else if (stoi(choice) == 3) {
		cout << "Введите новый процент скидки на книгу (в процентах)" << endl;
		do {
			input_check_double(str);
			if (stod(str) >= 100) {
				cout << "Скидка не может быть 100 и более процентов. Введите ещё раз" << endl;
			}
		} while (stod(str) >= 100);
		set_discountPercent(stod(str));
	}
	else if (stoi(choice) == 4) {
		cout << "Введите нового автора" << endl;
		input_check_int(str);
		set_author(str);
	}
	else {
		cout << "Такого выбора не существует" << endl;
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
	cout << left << setw(15) << "Фильм" << right << setw(30) << get_name() << endl;
	cout << left << setw(15) << "Год премьеры" << right << setw(30) << get_year() << endl;
	cout << left << setw(15) << "Стоимость" << right << setw(30) << get_price() << " руб" << endl;
	cout << left << setw(15) << "Процент скидки" << right << setw(30) << getdiscountPercent() << "%" << endl;
	cout << left << setw(15) << "Сумма скидки" << right << setw(30) << getDiscountAmount() << endl;
	cout << left << setw(15) << "Цена со скидкой" << right << setw(30) << getDiscountPrice() << endl;
}
void Movie::edit_info() {
	string choice = "";
	string str = "";
	cout << "Введите число от 1 до 4, чтобы изменить нужный параметр" << endl;
	cout << "1.Название фильма" << endl;
	cout << "2.Стоимость фильма" << endl;
	cout << "3.Процент скидки на фильм" << endl;
	cout << "4.Год премьеры фильма" << endl;
	input_check_int(choice);
	if (stoi(choice) == 1) {
		cout << "Введите новое название фильма" << endl;
		getline(cin, str);
		set_name(str);
	}
	else if (stoi(choice) == 2) {
		cout << "Введите новую стоимость фильма (валюту вводить не требуется)" << endl;
		input_check_double(str);
		set_price(stod(str));
	}
	else if (stoi(choice) == 3) {
		cout << "Введите новый процент скидки на фильм (в процентах)" << endl;
		do {
			input_check_double(str);
			if (stod(str) >= 100) {
				cout << "Скидка не может быть 100 и более процентов. Введите ещё раз" << endl;
			}
		} while (stod(str) >= 100);
		set_discountPercent(stod(str));
	}
	else if (stoi(choice) == 4) {
		cout << "Введите новый год премьеры фильма" << endl;
		do{
		input_check_int(str);
		if (stoi(str) < 1895 || stoi(str) > 2023) {
			cout << "Фильм не мог быть выпущен раньше 1895 года и не позже 2023" << endl;
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
	cout << left << setw(15) << "Видеокурс" << right << setw(30) << get_name() << endl;
	cout << left << setw(15) << "Автор" << right << setw(30) << get_author() << endl;
	cout << left << setw(15) << "Год выпуска" << right << setw(30) << get_year() << endl;
	cout << left << setw(15) << "Стоимость" << right << setw(30) << get_price() << " руб" << endl;
	cout << left << setw(15) << "Процент скидки" << right << setw(30) << getdiscountPercent() << "%" << endl;
	cout << left << setw(15) << "Сумма скидки" << right << setw(30) << getDiscountAmount() << endl;
	cout << left << setw(15) << "Цена со скидкой" << right << setw(30) << getDiscountPrice() << endl;
}
void Videocourse::edit_info() {
	string choice = "";
	string str = "";
	cout << "Введите число от 1 до 5, чтобы изменить нужный параметр" << endl;
	cout << "1.Название видеокурса" << endl;
	cout << "2.Стоимость видеокурса" << endl;
	cout << "3.Процент скидки на видеокурс" << endl;
	cout << "4.Автор видеокурса" << endl;
	cout << "5.Год выхода видеокурса" << endl;
	input_check_int(choice);
	if (stoi(choice) == 1) {
		cout << "Введите новое название видеокурса" << endl;
		getline(cin, str);
		set_name(str);
	}
	else if (stoi(choice) == 2) {
		cout << "Введите новую стоимость видеокурса (валюту вводить не требуется)" << endl;
		input_check_double(str);
		set_price(stod(str));
	}
	else if (stoi(choice) == 3) {
		cout << "Введите новый процент скидки на видеокурс(в процентах)" << endl;
		do {
			input_check_double(str);
			set_discountPercent(stod(str));
			if (stod(str) >= 100) {
				cout<<"Процент скидки не может быть 100 и более. Введите ещё раз" << endl;
			}
		} while (stod(str)>=100);
	}
	else if (stoi(choice) == 4) {
		cout << "Введите нового автора видеокурса" << endl;
		str = input_check_string();
		set_author(str);
	}
	else if (stoi(choice) == 5) {
		cout << "Введите новый год выпуска видеокурса" << endl;
		do {
			input_check_int(str);
			set_year(stoi(str));
			if (stoi(str) < 1895 || stoi(str) > 2023) {
				cout << "Видеокурс не мог быть выпущен раньше 1895 года и не позже 2023. Введите снова" << endl;
			}
		} while (stoi(str)<1895||stoi(str)>2023);
	}
};
