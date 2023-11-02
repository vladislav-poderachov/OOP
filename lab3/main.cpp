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
	equipment[2] = new SkippingRope("Пластик", 12, "Нейлон");
	int equipmentcount = 3;
	Gym gym;
	gym.set_equipment(equipmentcount, equipment);
	/*cout << "2.Удалить тренажёр из зала" << endl;*/
	/*
	cout << "3.Удалить посетителя зала" << endl;
	cout << "4.Удалить" << endl;*/
	system("pause");
	system("cls");
	while(ichoice!=5) {
	cout<<"1.Добавить в тренажёрный зал" << endl;
	cout<<"2.Исключения удаления" << endl;
	cout<<"3.Исключение изменения названия тренажёра" << endl;
	cout<<"4.Вывод информации о тренажёрном зале" << endl;
	cout<<"5.Завершить работу программы с помощью собственной фукнции завершения программы" << endl;
	cout<<"Введите число от 1 до 5 в зависимости от того, что хотите сделать." << endl;
	input_check_int(choice);
    system("cls");
	if (stoi(choice) == 1) {
		do {
			cout<<"1.Добавить ноль тренажёров в зал (исключение в конструкторе)" << endl;
			cout << "2.Добавить 100000000 тренажёров" << endl;
			cout << "3.Выход" << endl;
			input_check_int(choice);
            system("cls");
			if (stoi(choice) == 1) {
				try {
					gym =Gym(0, equipment);//ошибка с добавлением нуля тренажёров в зал
				}
				catch (exception &error) {
					cout << error.what() << endl;
					//cout<<"Исключение типа const char*. Нельзя добавить ноль тренажёров в зал. " << endl;
				}
			}
			else if (stoi(choice)== 2) {
				TrainingEquipment* eq;
				int counter = 0;
				try {
					while (1) {
						eq = new TrainingEquipment[100];//ошибка выделения памяти
						counter++;
					} 
                    delete[] eq;
                    termFunc(); 
                   
              
				}
				catch (bad_alloc exept) {
					cout << counter << endl;
					cout << "Возникло исключение " << exept.what() << endl;
                   
				} 
			}
		} while (stoi(choice) != 3);
	}
	else if (stoi(choice) == 2) {
		do {
			cout<<"1.Исключение по удалению тренажёра за пределами существующих" << endl;
			cout << "2.Исключение по сокращению тренажёров в зале в 0 раз" << endl;
			cout << "3.Выход" << endl;
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
				cout << "Введите номер тренажёра,который хотите удалить из тренажёрного зала" << endl;
				Exception e1;
				try {
					input_check_int(choice);
					if (stoi(choice) > equipmentcount) {
						throw e1;
					}
				}
				catch (Exception e1) {
					cout << "Сработал обработчик для типа объекта класса Exception" << endl;
				}
			}
			else if (stoi(choice) == 2) {
				int diskcount = 0;
				int gripcount = 0;
				int skippingropecount = 0;
				int divisor = 0;
				for (int i = 0; i < equipmentcount; i++) {
					if (equipment[i]->get_equipmentname() == "Диск") {
						diskcount++;
					}
					else if (equipment[i]->get_equipmentname() == "Гриф") {
						gripcount++;
					}
					else if (equipment[i]->get_equipmentname() == "Скакалка") {
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
						cout<<"Исключение: произошло деление на ноль." << endl;
					}
			}
			else if (stoi(choice) == 3) {
				break;
			}
			else{
				cout<<"Такого выбора не существует" << endl;
			}
		} while (stoi(choice)!=3);
	}
	else if (stoi(choice) == 3)
	{
		string newequipmentname = "";
		try {
			equipment[1]->set_equipmentname(newequipmentname);
			if (newequipmentname != equipment[1]->get_equipmentname()) {
			throw "Невозможно изменить у тренажёра название. ";
			}
		}
		catch(const char* message) {
			cout<<message<<"Сработало исключение." << endl;
		}
	}
	else if (stoi(choice) == 4)
	{
		gym.get_equipment();
	//cout<<"Введите тренажёр, о котором хотите по" << endl;
	}
	else if (stoi(choice) == 5) {
		cout<<"До свидания" << endl;
		delete[] *equipment;
		termFunc();
	}
	}
}