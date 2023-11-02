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
				products[0] = new Book("Трансёрфинг реальности", 49.99, 15.5, "Зеланд");
				products[1] = new Movie("Тихий дон", 10, 27.5, 1957);
				products[2] = new Videocourse("3D-моделирование", 280, 3.3, 2020, "Соловьёв");
				count = 3;
	while (stoi(choice)!=5) {	
		cout << "Выберите пункт от 1 до 5" << endl;
		cout << "1.Ввод информации" << endl;
		cout << "2.Изменение информации" << endl;
		cout << "3.Удаление информации" << endl;
		cout << "4.Вывод информации" << endl;
		cout << "5.Выход из программы" << endl;
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
					cout << "Выберите, написав число от 1 до 3,что хотите добавить или введите 4, если хотите выйти в главное меню:" << endl << "1.Книга" << endl << "2.Фильм" << endl <<"3.Видеокурс" << endl << "4.Выход" << endl;
					input_check_int(choice);
					system("cls");
					if (stoi(choice) == 1) {
						cout<<"Введите название книги" << endl;
						getline(std::cin, name);
						cout<<"Введите стоимость книги (валюту вводить не требуется)" << endl;
						input_check_double(price);
						cout<<"Введите процент скидки на книгу (в процентах)" << endl;
						do {
							input_check_double(discountPercent);
							if (stod(discountPercent) >= 100) {
								cout << "Скидка не может быть 100 и более процентов. Введите ещё раз" << endl;
							}
						} while (stod(discountPercent)>=100);
						cout << "Введите автора книги" << endl;
						author=input_check_string();
						system("cls");
						products[count] = new Book(name, stof(price), stod(discountPercent), author);
						count++;	

					}
					else if (stoi(choice) == 2) {
						cout << "Введите название фильма" << endl;
						getline(std::cin, name);
						cout << "Введите стоимость фильма (валюту вводить не требуется)" << endl;
						input_check_double(price);
						cout << "Введите процент скидки на фильм (в процентах)" << endl;
						do {
							input_check_double(discountPercent);
							if (stod(discountPercent) >= 100) {
								cout << "Скидка не может быть 100 и более процентов. Введите ещё раз" << endl;
							}
						} while (stod(discountPercent) >= 100);
						do {
							cout << "Введите год премьеры фильма" << endl;
							input_check_int(year);
							if (stoi(year) < 1895||stoi(year)>2023) {
								cout << "Фильм не мог быть выпущен раньше 1895 года и не позже 2023" << endl;
							}
						} while (stoi(year)<1895 || stoi(year) > 2023);
						system("cls");
						products[count] = new Movie(name, stof(price), stod(discountPercent), stoi(year));
						count++;
					}
					else if (stoi(choice) == 3) {
						cout << "Введите название видеокурса" << endl;
						getline(std::cin, name);
						cout<<"Введите стоимость видеокурса (валюту вводить не требуется)" << endl;
						input_check_double(price);
						cout << "Введите процент скидки на видеокурс (в процентах)" << endl;
						input_check_double(discountPercent);
						cout << "Введите автора видеокурса" << endl;
						author=input_check_string();
						do{
						cout << "Введите год выхода видеокурса" << endl;
						input_check_int(year);
						if (stoi(year) < 1895 || stoi(year) > 2023) {
							cout << "Видеокурс не мог быть выпущен раньше 1895 года и не позже 2023. Введите снова" << endl;
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
						cout <<"Такого выбора не существует." << endl;
					}
				} while (stoi(choice)!=4);
			}
		else if (stoi(choice) == 2) {
			if (count > 0) {
				for (int i = 0; i < count; i++) {
					
					products[i]->printDescription();
					cout << i + 1 << " товар"<<endl;
				}
				cout << "Введите номер продукта, в котором хотите изменить информацию" << endl;
				input_check_int(choice);
				system("cls");
				if (stoi(choice) <= count) {
					products[stoi(choice)-1]->printDescription();
					products[stoi(choice)-1]->edit_info();
					system("cls");
				}
				else {
					cout << "Товара с таким номером нет в списке" << endl;
				}
			}
			else {
				cout<<"Операция невозможна: ни одного товара не существует" << endl;
			}
		}

		else if (stoi(choice) == 3) {
			do {
				if (count > 0) {
					cout << "Введите число от 1 до 2, если хотите удалить товары, или введите 3, если хотите выйти" << endl;
					cout << "1.Удалить все товары" << endl;
					cout << "2.Удалить конкретный товар" << endl;
					cout << "3.Выход в главное меню" << endl;
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
						cout << "Введите порядковый номер товара, который хотите удалить, в списке, предложенном выше. Если хотите выйти, нажмите 0" << endl;
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
							cout << "Товар с порядковым номером " << stoi(del_choice) << " был успешно удалён" << endl;
							count--;
						}
						else {
							cout<<"Товара с таким порядковым номером нет в списке" << endl;
						}
					}
					else if (stoi(choice) == 3) {
						break;
					}
				}
				else {
					cout << "Операция невозможна: ни одного товара не существует" << endl;
				}
			} while (stoi(choice)!=3);
		}
		else if (stoi(choice) == 4) {
		if (count == 0) {
			cout<<"Операция невозможна: ни одного товара не существует" << endl;
		}
		else {
			for (int i = 0; i < count; i++) {
				cout << i + 1 << " ";
				products[i]->printDescription();
			}
			do {
				cout << "Введите 1, чтобы вернуться в главное меню" << endl;
				input_check_int(choice);
				if (stoi(choice) == 1) {
					system("cls");
				}
				else {
					cout << "Такого выбора не существует" << endl;
				}
			} while (stoi(choice) != 1);
		}
		}
		else if (stoi(choice) == 5) {
			delete[] products;
			return 0;
		}
		else {
			cout<<"Такого выбора не существует" << endl;
		}
	}
}