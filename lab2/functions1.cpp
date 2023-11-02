#include"Header1.h"
void input_check_int(string& str) {
	int i = 0;
	do {
		getline(std::cin, str);
		if (str.empty()) {
			cout << "Введите хотя бы одно число" << endl;
			continue;
		}
		for (i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				if (i == 0) {
					continue;
				}
				else if (str[i - 1] == '0' || isdigit(str[i - 1])) {
					cout << "Не вводите пробелы" << endl;
					break;
				}


			}
			else if (str[i] == '-') {
				cout << "Вводите только натуральные числа" << endl;
				break;
			}
			else if (iswalpha((unsigned char)str[i])) {
				cout << "Вводите только числа. Никаких букв." << endl;
				break;
			}
			else if (!isdigit(str[i])) {
				cout << "Вводите только числа." << endl;
				break;
			};
		}
	} while (i < str.length() || str.empty());
}
string input_check_string() {
	string str;
	bool valid;
	do {
		getline(cin, str);
		valid = true;
		if (str.empty()) {
			cout << "Строка не может быть пустой" << endl;
			valid = false;
		}
		else if (!iswupper((unsigned char)str[0])) {
			cout << "Строка должна начинаться с большой буквы" << endl;
			valid = false;
		}
		else {
			for (int i = 1; i < str.length(); i++) {
				if (str[i] == ' ') {
					cout << "Строка не должна содержать пробелов" << endl;
					valid = false;
					break;
				}
				else if (!iswalpha((unsigned char)str[i])) {
					cout << "Строка должна состоять только из букв" << endl;
					valid = false;
					break;
				}
				else if (str[i] < -64 || str[i] > -1) {
					cout << "Строка должна быть на русском языке" << endl;
					valid = false;
					break;
				}
				else if (iswupper((unsigned char)str[i])) {
					cout << "Строка не должна содержать заглавных букв после первой" << endl;
					valid = false;
					break;
				}
			}
		}
	} while (!valid);
	return str;
}
void input_check_date(string& str) {
	int i = 0;
	int counter = 0;
	do {
		counter = 0;
		getline(cin, str);
		if (str.empty()) {
				cout << "Вы ничего не ввели. Попробуйте ещё раз" << endl;
				continue;
			}
		for (int i = 0;i < str.length(); i++) {
			if (str[i] == ' ') {
				cout<<"Не вводите пробелы" << endl;
				break;
		}
			else if(str[i] =='.') {
				if (counter == 3) {
					cout << "Вы ввели слишком много точек" << endl;
					break;

			}
				else if (str[i - 1] == '.') {
					cout << "Вы ввели слишком много точек вместе" << endl;
					break;
				}
				else {
					counter++;
					continue;
				}
			}
			else if(!isdigit(str[i])) {
				cout<<"Вводите только числа и точки." << endl;
				break;
			}
		}
	} while (str.empty() ||str[i]==' '||counter==3||(str[i]=='.'&&str[i - 1] == '.' )|| !isdigit(str[i]));
}