#include"Header.h"
int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string choice="0",name, author, price, discountPercent, year, del_choice="0";
	int numchoice = 0;
	Product** products=nullptr;
	int capacity = 0, count =0;	
	string addcount="", count1="";
				capacity = 10;
				products = new Product * [capacity];
				products[0] = new Book("���������� ����������", 49.99, 15.5, "������");
				products[1] = new Movie("����� ���", 10, 27.5, 1957);
				products[2] = new Videocourse("3D-�������������", 280, 3.3, 2020, "��������");
				count = 3;
	while (stoi(choice)!=5) {	
		cout << "�������� ����� �� 1 �� 5" << endl;
		cout << "1.���� ����������" << endl;
		cout << "2.��������� ����������" << endl;
		cout << "3.�������� ����������" << endl;
		cout << "4.����� ����������" << endl;
		cout << "5.����� �� ���������" << endl;
		input_check_int(choice);
		system("cls");
		if (stoi(choice) == 1) {
				if(count==capacity){
					Product **products1=new Product*[2*capacity];
					for (int i = 0; i <capacity; i++) {
						products1[i] = products[i];
					}
					delete[] products;
					products = new Product * [2*capacity];
					for (int i = 0; i < capacity; i++) {
						products[i] = products1[i];
					}
					capacity = 2 * capacity; 
				}
				do{
					system("cls");
					cout << "��������, ������� ����� �� 1 �� 3,��� ������ �������� ��� ������� 4, ���� ������ ����� � ������� ����:" << endl << "1.�����" << endl << "2.�����" << endl <<"3.���������" << endl << "4.�����" << endl;
					input_check_int(choice);
					system("cls");
					if (stoi(choice) == 1) {
						cout<<"������� �������� �����" << endl;
						getline(std::cin, name);
						cout<<"������� ��������� ����� (������ ������� �� ���������)" << endl;
						input_check_double(price);
						cout<<"������� ������� ������ �� ����� (� ���������)" << endl;
						do {
							input_check_double(discountPercent);
							if (stod(discountPercent) >= 100) {
								cout << "������ �� ����� ���� 100 � ����� ���������. ������� ��� ���" << endl;
							}
						} while (stod(discountPercent)>=100);
						cout << "������� ������ �����" << endl;
						author=input_check_string();
						system("cls");
						products[count] = new Book(name, stof(price), stod(discountPercent), author);
						count++;	

					}
					else if (stoi(choice) == 2) {
						cout << "������� �������� ������" << endl;
						getline(std::cin, name);
						cout << "������� ��������� ������ (������ ������� �� ���������)" << endl;
						input_check_double(price);
						cout << "������� ������� ������ �� ����� (� ���������)" << endl;
						do {
							input_check_double(discountPercent);
							if (stod(discountPercent) >= 100) {
								cout << "������ �� ����� ���� 100 � ����� ���������. ������� ��� ���" << endl;
							}
						} while (stod(discountPercent) >= 100);
						do {
							cout << "������� ��� �������� ������" << endl;
							input_check_int(year);
							if (stoi(year) < 1895||stoi(year)>2023) {
								cout << "����� �� ��� ���� ������� ������ 1895 ���� � �� ����� 2023" << endl;
							}
						} while (stoi(year)<1895 || stoi(year) > 2023);
						system("cls");
						products[count] = new Movie(name, stof(price), stod(discountPercent), stoi(year));
						count++;
					}
					else if (stoi(choice) == 3) {
						cout << "������� �������� ����������" << endl;
						getline(std::cin, name);
						cout<<"������� ��������� ���������� (������ ������� �� ���������)" << endl;
						input_check_double(price);
						cout << "������� ������� ������ �� ��������� (� ���������)" << endl;
						input_check_double(discountPercent);
						cout << "������� ������ ����������" << endl;
						author=input_check_string();
						do{
						cout << "������� ��� ������ ����������" << endl;
						input_check_int(year);
						if (stoi(year) < 1895 || stoi(year) > 2023) {
							cout << "��������� �� ��� ���� ������� ������ 1895 ���� � �� ����� 2023. ������� �����" << endl;
						}
					}while (stoi(year) < 1895 || stoi(year) > 2023);
						system("cls");
						products[count] = new Videocourse(name, stof(price), stod(discountPercent), stoi(year), author);
						count++;
					}
					else if (stoi(choice) == 4) {
						break;
					}
					else {
						cout <<"������ ������ �� ����������." << endl;
					}
				} while (stoi(choice)!=4);
			}
		else if (stoi(choice) == 2) {
			if (count > 0) {
				for (int i = 0; i < count; i++) {
					
					products[i]->printDescription();
					cout << i + 1 << " �����"<<endl;
				}
				cout << "������� ����� ��������, � ������� ������ �������� ����������" << endl;
				input_check_int(choice);
				system("cls");
				if (stoi(choice) <= count) {
					products[stoi(choice)-1]->printDescription();
					products[stoi(choice)-1]->edit_info();
					system("cls");
				}
				else {
					cout << "������ � ����� ������� ��� � ������" << endl;
				}
			}
			else {
				cout<<"�������� ����������: �� ������ ������ �� ����������" << endl;
			}
		}

		else if (stoi(choice) == 3) {
			do {
				if (count > 0) {
					cout << "������� ����� �� 1 �� 2, ���� ������ ������� ������, ��� ������� 3, ���� ������ �����" << endl;
					cout << "1.������� ��� ������" << endl;
					cout << "2.������� ���������� �����" << endl;
					cout << "3.����� � ������� ����" << endl;
					input_check_int(choice);
					system("cls");
					if (stoi(choice) == 1) {
						delete[] products;
						count = 0;
						break;
					}
					else if (stoi(choice) == 2) {
						for (int i = 0; i < count; i++) {
							cout << i + 1 << " ";
							products[i]->printDescription();
						}
						cout << "������� ���������� ����� ������, ������� ������ �������, � ������, ������������ ����. ���� ������ �����, ������� 0" << endl;
						input_check_int(del_choice);
						if (stoi(del_choice) == 0) {
							system("cls");
						}
						else if (stoi(del_choice) <= count) {
							if (stoi(del_choice) < count) {
								for (int i = stoi(del_choice) - 1; i < count - 1; i++) {
									products[i] = products[i + 1];
								}

							}	
							Product** new_products = new Product * [capacity - 1];
								for (int i = 0; i < count-1; i++) {
									new_products[i] = products[i];
								}
								delete[] products;
								products = new Product * [capacity-1]; 
								for (int i = 0; i < count-1; i++) {
									products[i] = new_products[i];
								}
								system("cls");
							cout << "����� � ���������� ������� " << stoi(del_choice) << " ��� ������� �����" << endl;
							count--;
						}
						else {
							cout<<"������ � ����� ���������� ������� ��� � ������" << endl;
						}
					}
					else if (stoi(choice) == 3) {
						break;
					}
				}
				else {
					cout << "�������� ����������: �� ������ ������ �� ����������" << endl;
				}
			} while (stoi(choice)!=3);
		}
		else if (stoi(choice) == 4) {
		if (count == 0) {
			cout<<"�������� ����������: �� ������ ������ �� ����������" << endl;
		}
		else {
			for (int i = 0; i < count; i++) {
				cout << i + 1 << " ";
				products[i]->printDescription();
			}
			do {
				cout << "������� 1, ����� ��������� � ������� ����" << endl;
				input_check_int(choice);
				if (stoi(choice) == 1) {
					system("cls");
				}
				else {
					cout << "������ ������ �� ����������" << endl;
				}
			} while (stoi(choice) != 1);
		}
		}
		else if (stoi(choice) == 5) {
			delete[] products;
			return 0;
		}
		else {
			cout<<"������ ������ �� ����������" << endl;
		}
	}
}