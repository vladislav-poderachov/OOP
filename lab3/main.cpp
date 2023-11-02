#include"h.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string choice = "";
	int ichoice = 0;
	int equipmentcapacity= 10;
	TrainingEquipment** equipment=new TrainingEquipment*[equipmentcapacity];
	equipment[0] = new Grip();
	equipment[0] =  new Grip(15);
	equipment[1] = new WeightPlate();	
	equipment[1] =  new WeightPlate(20, 0.36);
	equipment[2] = new SkippingRope("�������", 12, "������");
	int equipmentcount = 3;
	Gym gym;
	gym.set_equipment(equipmentcount, equipment);
	/*cout << "2.������� ������� �� ����" << endl;*/
	/*
	cout << "3.������� ���������� ����" << endl;
	cout << "4.�������" << endl;*/
	system("pause");
	system("cls");
	while(ichoice!=5) {
	cout<<"1.�������� � ���������� ���" << endl;
	cout<<"2.���������� ��������" << endl;
	cout<<"3.���������� ��������� �������� ��������" << endl;
	cout<<"4.����� ���������� � ���������� ����" << endl;
	cout<<"5.��������� ������ ��������� � ������� ����������� ������� ���������� ���������" << endl;
	cout<<"������� ����� �� 1 �� 5 � ����������� �� ����, ��� ������ �������." << endl;
	input_check_int(choice);
    system("cls");
	if (stoi(choice) == 1) {
		do {
			cout<<"1.�������� ���� ��������� � ��� (���������� � ������������)" << endl;
			cout << "2.�������� 100000000 ���������" << endl;
			cout << "3.�����" << endl;
			input_check_int(choice);
            system("cls");
			if (stoi(choice) == 1) {
				try {
					gym =Gym(0, equipment);//������ � ����������� ���� ��������� � ���
				}
				catch (exception &error) {
					cout << error.what() << endl;
					//cout<<"���������� ���� const char*. ������ �������� ���� ��������� � ���. " << endl;
				}
			}
			else if (stoi(choice)== 2) {
				TrainingEquipment* eq;
				int counter = 0;
				try {
					while (1) {
						eq = new TrainingEquipment[100];//������ ��������� ������
						counter++;
					} 
                    delete[] eq;
                    termFunc(); 
                   
              
				}
				catch (bad_alloc exept) {
					cout << counter << endl;
					cout << "�������� ���������� " << exept.what() << endl;
                   
				} 
			}
		} while (stoi(choice) != 3);
	}
	else if (stoi(choice) == 2) {
		do {
			cout<<"1.���������� �� �������� �������� �� ��������� ������������" << endl;
			cout << "2.���������� �� ���������� ��������� � ���� � 0 ���" << endl;
			cout << "3.�����" << endl;
			input_check_int(choice);
			if (stoi(choice) == 1) {
				for (int i = 0; i < 24; i++) {
					cout << "-";
				}
				cout << endl;
				for (int i = 0; i < equipmentcount; i++) {
					cout << "|" << setw(3) << left << i + 1 << "|" << setw(18) << left << equipment[i]->get_equipmentname() << "|" << endl;
				}
				for (int i = 0; i < 24; i++) {
					cout << "-";
				}
				cout << endl;
				cout << "������� ����� ��������,������� ������ ������� �� ����������� ����" << endl;
				Exception e1;
				try {
					input_check_int(choice);
					if (stoi(choice) > equipmentcount) {
						throw e1;
					}
				}
				catch (Exception e1) {
					cout << "�������� ���������� ��� ���� ������� ������ Exception" << endl;
				}
			}
			else if (stoi(choice) == 2) {
				int diskcount = 0;
				int gripcount = 0;
				int skippingropecount = 0;
				int divisor = 0;
				for (int i = 0; i < equipmentcount; i++) {
					if (equipment[i]->get_equipmentname() == "����") {
						diskcount++;
					}
					else if (equipment[i]->get_equipmentname() == "����") {
						gripcount++;
					}
					else if (equipment[i]->get_equipmentname() == "��������") {
						skippingropecount++;
					}

				}		
						try {
						equipmentcount /divisor;
						if (divisor == 0) {
							throw 1;
						}
					}
					catch (int) {
						cout<<"����������: ��������� ������� �� ����." << endl;
					}
			}
			else if (stoi(choice) == 3) {
				break;
			}
			else{
				cout<<"������ ������ �� ����������" << endl;
			}
		} while (stoi(choice)!=3);
	}
	else if (stoi(choice) == 3)
	{
		string newequipmentname = "";
		try {
			equipment[1]->set_equipmentname(newequipmentname);
			if (newequipmentname != equipment[1]->get_equipmentname()) {
			throw "���������� �������� � �������� ��������. ";
			}
		}
		catch(const char* message) {
			cout<<message<<"��������� ����������." << endl;
		}
	}
	else if (stoi(choice) == 4)
	{
		gym.get_equipment();
	//cout<<"������� �������, � ������� ������ ��" << endl;
	}
	else if (stoi(choice) == 5) {
		cout<<"�� ��������" << endl;
		delete[] *equipment;
		termFunc();
	}
	}
}