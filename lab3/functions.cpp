#include"h.h"
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
void input_check_double(string& str) {
	int i = 0, point_count = 0, point_position = 0;
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
			/*else if (point_count == 1) {
				if (str[i - 2] != '.' && str[i - 1] != '.') {
					cout<<"�� ������ ������� ����� ������ �� �����" << endl;
					break;
				}
			}*/
			else if (str[i] == '.') {
				if (point_count == 1) {
					break;
				}
				else
				{
					point_count++;
					string copy_string = "";
					for (int j = i + 1; j < str.length();j++) {
						copy_string += str[j];
					}
					if (copy_string.length() > 2) {
						cout << "�� ������ ������� ����� ������ �� �����" << endl;
						break;
					}
					/*if ((i + 2 != str.length() - 1&&str.length()==i+1) || (i + 1 != str.length() - 1 && str.length() == i + 2)) {
						cout << "�� ������ ������� ����� ������ �� �����" << endl;
						break;
					}*/
				}
				if (i == 0) {
					point_position++;
					continue;
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
};
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
void termFunc() {
	cout << "��������� ����������� ������� ���������� ���������" << endl;
	exit(-1);
}