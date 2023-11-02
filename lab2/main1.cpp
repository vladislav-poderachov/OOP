//#include"Header1.h"
//int main() {
////	string choice="";
////	int capacity = 10, count=0;
////	Comand *comands;
////	Transaction<Competition> **competitions=nullptr;
////	competitions = new Transaction<Competition>*[capacity];
////	do {
////		cout <<"Введите число от 1 до 5" << endl;
////		cout << "1.Введение информации о соревнованиях" << endl;
////		cout << "2.Изменение информации о соревнованиях" << endl;
////		cout << "3.Удаление информации о соревнованиях" << endl;
////		cout << "4.Вывод информации о соревнованиях" << endl;
////		cout << "5.Выход" << endl;
////		input_check_int(choice);
////		if (stoi(choice) == 1) {
////			do {
////				cout << "Введите число от 1 до 5, чтобы ввести разного вида соревнования, или введите число 6, если хотите выйти в главное меню" << endl;
////				cout << "1.Футбольное соревнование" << endl;
////				cout << "2.Баскетбольное соревнование" << endl;
////				cout << "3.Волейбольное соревнование" << endl;
////				cout << "4.Хоккейное соревнование" << endl;
////				cout <<"5.Шахматное соревнование" << endl;
////				cout <<"6.Выход" << endl;
////				input_check_int(choice);
////				system("cls");
////				if (stoi(choice) == 1) 
////				{
////					if (count == capacity) {
////						Transaction<Competition>** copy = new Transaction<Competition> *[2 * capacity];
////						for (int i = 0; i < capacity;i++) {
////							copy[i] = competitions[i];
////						}
////						delete[] competitions;
////						competitions = new Transaction<Competition>*[2 * capacity];
////						for (int i = 0; i < capacity;i++) {
////							competitions[i] = copy[i];
////						}
////						delete[] copy;
////					}
////					cout<<"Введите название соревнований" << endl;
////					getline(cin, choice);
////					(*competitions[count])->set_competitionName(choice);
////					cout << "Введите дату соревнований" << endl;
////					input_check_date(choice);
////					cout << "Введите количество соревнующихся команд" << endl;
////					input_check_int(choice);
////					(*competitions[count])->set_competitorCount(stoi(choice));
////					cout << "Введите команды, которые участвуют" << endl;
////
////					Transaction<FootballCompetition> footb;
////					competitions[count] = Transaction<Competition>(footb);
////					comand->
////					
////					comp1.showState(State::begin);
////					
////					while (int i = stoi(choice) != 0) {
////
////						i--;
////					}
////					cout << "" << endl;
////					cout << "" << endl;
////					cout << "" << endl;
////					cout << "" << endl;
////					(*competitions[count])->set_day(stoi(choice));
////					(*competitions[count])->set_month(stoi(choice));
////					(*competitions[count])->set_year(stoi(choice));
////					
////					(*competitions[count])->set_comands(comands);
////				}
////				else if (stoi(choice) == 2) 
////				{
////
////				}
////				else if (stoi(choice) == 3) {
////				}
////				else if (stoi(choice) == 4) {
////				}
////				else if (stoi(choice) == 5) {
////
////				}
////				else if (stoi(choice) == 6) {
////
////				}
////				else {
////					cout<<"Такого выбора не существует. Попробуйте ещё раз." << endl;
////				}
////			} while (stoi(choice)!=6);
////		}
////		else if (stoi(choice) == 2) {
////			system("cls");
////		}
////		else if (stoi(choice) == 3) {
////			system("cls");
////		}
////		else if (stoi(choice) == 4) {
////			system("cls");
////			for (int i = 0; i < 100; i++) {
////				cout << "-";
////			}
////			cout << endl<<"| "<<middle<<setw(30) << "Название соревнований"<<"| "<<middle<<setw(28)<<"Дата проведения соревнований"<<"| "<<middle<<setw(23) << "Количество участников"<<"| "<<middle<<setw(15)<<"Итоги"<<" |";
////
////			for (int i = 0; i < get_competitorCount(); i++) {
////				cout<<"Название соревнований" << endl;
////				cout << "Дата проведения соревнований" << endl;
////				cout << "Количество участников" << endl;
////				cout << "" << endl;
////				cout << "" << endl;
////				cout << "" << endl;
////				cout << "" << endl;
////				cout << "" << endl;
////			}
////		}
////		else if (stoi(choice) == 5) {
////			system("cls");
////			cout << "До свидания" << endl;
////			break;
////		}
////		else {
////			system("cls");
////			cout<<"Такого выбора не существует." << endl;
////		}
////	} while (stoi(choice) != 5);
////SmartPointer<Comand> comand1=new Comand(10, 1);
////SmartPointer<Comand> comand2 = new Comand(9, 2);
////SmartPointer<Comand> comand3 = new Comand(8, 3);
////int capacity = 0;
////Transaction<FootballCompetition> comp1;
////Transaction<BasketballCompetition> comp2;
////Transaction<VoleyballCompetition> comp3;
////Transaction<ChessCompetition> comp4;
////Transaction<HockeyCompetition> comp5;
//string choice = "", name="", date;
//int capacity = 10, count=0;
//Transaction<Competition>** competitions = new Transaction<Competition>*[capacity];
//if (count == capacity) {
//	Transaction<Competition>**copy = new Transaction<Competition> *[2 * capacity];
//	for (int i = 0; i < capacity;i++) {
//		copy[i] = competitions[i];
//	}
//	delete[] competitions;
//	competitions = new Transaction<Competition>*[2 * capacity];
//	for (int i = 0; i < capacity;i++) {
//		competitions[i] = copy[i];
//	}
//	delete[] copy;
//}
//for (int i = 0; i < count; i++) {
//	getline(cin, name);
//	input_check_date(date);
//	string day, month, year;
//	for (int i = 0; i < 2; i++) {
//		day += date[i];
//	}
//	for (int i = 2; i < 4; i++) {
//		month += date[i];
//	}
//	for (int i = 4; i < 6; i++){
//		year += date[i];
//	}
//	competitions[i]->beginTransactions(name);
//	competitions[i]->beginTransactions(stoi(day), stoi(month), stoi(year));
//   }
//}