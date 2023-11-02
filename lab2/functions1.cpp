#include"Header1.h"
void input_check_int(string& str) {
	int i = 0;
	do {
		getline(std::cin, str);
		if (str.empty()) {
			cout << "������� ���� �� ���� �����" << endl;
			continue;
		}
		for (i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				if (i == 0) {
					continue;
				}
				else if (str[i - 1] == '0' || isdigit(str[i - 1])) {
					cout << "�� ������� �������" << endl;
					break;
				}


			}
			else if (str[i] == '-') {
				cout << "������� ������ ����������� �����" << endl;
				break;
			}
			else if (iswalpha((unsigned char)str[i])) {
				cout << "������� ������ �����. ������� ����." << endl;
				break;
			}
			else if (!isdigit(str[i])) {
				cout << "������� ������ �����." << endl;
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
			cout << "������ �� ����� ���� ������" << endl;
			valid = false;
		}
		else if (!iswupper((unsigned char)str[0])) {
			cout << "������ ������ ���������� � ������� �����" << endl;
			valid = false;
		}
		else {
			for (int i = 1; i < str.length(); i++) {
				if (str[i] == ' ') {
					cout << "������ �� ������ ��������� ��������" << endl;
					valid = false;
					break;
				}
				else if (!iswalpha((unsigned char)str[i])) {
					cout << "������ ������ �������� ������ �� ����" << endl;
					valid = false;
					break;
				}
				else if (str[i] < -64 || str[i] > -1) {
					cout << "������ ������ ���� �� ������� �����" << endl;
					valid = false;
					break;
				}
				else if (iswupper((unsigned char)str[i])) {
					cout << "������ �� ������ ��������� ��������� ���� ����� ������" << endl;
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
				cout << "�� ������ �� �����. ���������� ��� ���" << endl;
				continue;
			}
		for (int i = 0;i < str.length(); i++) {
			if (str[i] == ' ') {
				cout<<"�� ������� �������" << endl;
				break;
		}
			else if(str[i] =='.') {
				if (counter == 3) {
					cout << "�� ����� ������� ����� �����" << endl;
					break;

			}
				else if (str[i - 1] == '.') {
					cout << "�� ����� ������� ����� ����� ������" << endl;
					break;
				}
				else {
					counter++;
					continue;
				}
			}
			else if(!isdigit(str[i])) {
				cout<<"������� ������ ����� � �����." << endl;
				break;
			}
		}
	} while (str.empty() ||str[i]==' '||counter==3||(str[i]=='.'&&str[i - 1] == '.' )|| !isdigit(str[i]));
}