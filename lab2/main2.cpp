//#include"Header1.h"
//int main() {
//	int notbroken = 0, compchoice = 0, delchoice = 0, editchoice=0;
//	string choice = "", name = "", pointCount = "", place = "", date;
//	int capacity1 = 10, capacity2 = 10, capacity3 = 10, capacity4 = 10, capacity5 = 10, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
//	Transaction<FootballCompetition>** football_competitions = new Transaction<FootballCompetition>*[capacity1];
//	Transaction<BasketballCompetition>** basketball_competitions = new Transaction<BasketballCompetition>*[capacity2];
//	Transaction < VoleyballCompetition>** voleyball_competitions = new Transaction<VoleyballCompetition>*[capacity3];
//	Transaction<ChessCompetition>** chess_competitions = new Transaction<ChessCompetition>*[capacity4];
//	Transaction<HockeyCompetition>** hockey_competitions = new Transaction<HockeyCompetition>*[capacity5];
//	SmartPointer<Comand>** comands = new SmartPointer<Comand>*[10];
//	comands[1]->operator->()->set_comandName("�������");
//	comands[2]->operator->()->set_comandName("180+");
//	comands[3]->operator->()->set_comandName("������� 7");
//	comands[4]->operator->()->set_comandName("��������");
//	comands[5]->operator->()->set_comandName("�����");
//	comands[6]->operator->()->set_comandName("��������� ����");
//	comands[7]->operator->()->set_comandName("��������");
//	comands[8]->operator->()->set_comandName("����� �����");
//	comands[9]->operator->()->set_comandName("������ �����");
//	comands[0]->operator->()->set_comandName("����� ���������");
//	do 
//	{
//		cout << "������� ����� �� 1 �� 5" << endl;
//		cout << "1.�������� ���������� � �������������" << endl;
//		cout << "2.��������� ���������� � �������������" << endl;
//		cout << "3.�������� ���������� � �������������" << endl;
//		cout << "4.����� ���������� � �������������" << endl;
//		cout << "5.�����" << endl;
//		input_check_int(choice);
//		if (notbroken = stoi(choice) == 1) {
//			do {
//				cout << "������� ����� �� 1 �� 5, ����� ������ ������� ���� ������������, ��� ������� ����� 6, ���� ������ ����� � ������� ����" << endl;
//				cout << "1.���������� ������������" << endl;
//				cout << "2.������������� ������������" << endl;
//				cout << "3.������������ ������������" << endl;
//				cout << "4.��������� ������������" << endl;
//				cout << "5.��������� ������������" << endl;
//				cout << "6.�����" << endl;
//				input_check_int(choice);
//				if (compchoice = stoi(choice) == 1) {
//					if (count1 == capacity1) {
//						Transaction<FootballCompetition>** copy = new Transaction<FootballCompetition>*[2 * capacity1];
//						for (int i = 0; i < capacity1; i++) {
//							copy[i] = football_competitions[i];
//						}
//						delete[] football_competitions;
//						football_competitions = new Transaction<FootballCompetition>*[2 * capacity1];
//						for (int i = 0; i < capacity1; i++) {
//							football_competitions[i] = copy[i];
//						}
//						capacity1 = 2 * capacity1;
//						delete[] copy;
//					}
//					cout << "������� �������� ������������" << endl;
//					getline(cin, choice);
//					football_competitions[count1]->operator->()->set_competitionName(choice);
//					cout << "������� ���� ������������" << endl;
//					input_check_date(choice);
//					football_competitions[count1]->operator->()->set_date(choice);
//					do {
//						cout << "������� ���������� ������������� ������ (�� ������ 10)" << endl;
//						input_check_int(choice);
//						if (stoi(choice) > 10) {
//							cout << "� ������������� ����� ����������� �� ����� 10 ������" << endl;
//						}
//					} while (stoi(choice) >= 10);
//					football_competitions[count1]->operator->()->set_competitorCount(stoi(choice));
//
//					int counter = 0, choices[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//					do {
//						cout << "�������� �� ������������ ������ ������������� ��� ������� 0, ���� ������ ����������." << endl;
//						for (int i = 0; i < 10; i++) {
//							if (choices[i] == 0) {
//								cout << "������� " << i + 1 << " - " << comands[i]->operator->()->get_comandName() << endl;
//							}
//						}
//						input_check_int(choice);
//						if (stoi(choice) >= 10) {
//							cout << "������� ��� ����� ������� ���" << endl;
//						}
//						else if (stoi(choice) != 0) {
//							if (choices[stoi(choice) - 1] == 1) {
//								cout << "�� ��� ������� ��� �������." << endl;
//							}
//							else {
//								counter++;
//								choices[stoi(choice)] = 1;
//							}
//						}
//						else if (counter < 2) {
//							cout << "� ������������� ������ ����������� ������� 2 �������" << endl;
//						}
//					} while (stoi(choice) != 0 && counter < 2);
//
//					football_competitions[count1]->operator->()->set_comands(10, *comands);
//					cout << "������� ���������� ������� ��������" << endl;
//					input_check_int(choice);
//					football_competitions[count1]->operator->()->set_redCardCount(stoi(choice));
//					cout << "������� ���������� �����" << endl;
//					football_competitions[count1]->operator->()->set_goalCount(stoi(choice));
//					football_competitions[count1]->operator->()->file();
//				}
//				else if (compchoice == 2) {
//					if (count2 == capacity2) {
//						Transaction<BasketballCompetition>** copy = new Transaction<BasketballCompetition>*[2 * capacity2];
//						for (int i = 0; i < capacity2; i++) {
//							copy[i] = basketball_competitions[i];
//						}
//						delete[] basketball_competitions;
//						basketball_competitions = new Transaction<BasketballCompetition>*[2 * capacity2];
//						for (int i = 0; i < capacity2; i++) {
//							basketball_competitions[i] = copy[i];
//						}
//						capacity2 = 2 * capacity2;
//						delete[] copy;
//					}
//					cout << "������� �������� ������������" << endl;
//					getline(cin, choice);
//					basketball_competitions[count2]->operator->()->set_competitionName(choice);
//					cout << "������� ���� ������������" << endl;
//					input_check_date(choice);
//					basketball_competitions[count2]->operator->()->set_date(choice);
//					do {
//						cout << "������� ���������� ������������� ������ (�� ������ 10)" << endl;
//						input_check_int(choice);
//						if (stoi(choice) > 10) {
//							cout << "� ������������� ����� ����������� �� ����� 10 ������" << endl;
//						}
//					} while (stoi(choice) >= 10);
//					basketball_competitions[count2]->operator->()->set_competitorCount(stoi(choice));
//					int counter = 0, choices[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//					do {
//						cout << "�������� �� ������������ ������ ������������� ��� ������� 0, ���� ������ ����������." << endl;
//						for (int i = 0; i < 10; i++) {
//							if (choices[i] == 0) {
//								cout << "������� " << i + 1 << " - " << comands[i]->operator->()->get_comandName() << endl;
//							}
//						}
//						input_check_int(choice);
//						if (stoi(choice) >= 10) {
//							cout << "������� ��� ����� ������� ���" << endl;
//						}
//						else if (stoi(choice) != 0) {
//							if (choices[stoi(choice) - 1] == 1) {
//								cout << "�� ��� ������� ��� �������." << endl;
//							}
//							else {
//								counter++;
//								choices[stoi(choice)] = 1;
//							}
//						}
//						else if (counter < 2) {
//							cout << "� ������������� ������ ����������� ������� 2 �������" << endl;
//						}
//					} while (stoi(choice) != 0 && counter < 2);
//
//					basketball_competitions[count2]->operator->()->set_comands(10, *comands);
//					cout << "������� ���������� ��������" << endl;
//					input_check_int(choice);
//					basketball_competitions[count2]->operator->()->set_reboundCount(stoi(choice));
//					cout << "������� ���������� �����" << endl;
//					basketball_competitions[count2]->operator->()->set_pointCount(stoi(choice));
//					basketball_competitions[count2]->operator->()->file();
//				}
//				else if (compchoice == 3) {
//					if (count3 == capacity3) {
//						Transaction<VoleyballCompetition>** copy = new Transaction<VoleyballCompetition>*[2 * capacity3];
//						for (int i = 0; i < capacity3; i++) {
//							copy[i] = voleyball_competitions[i];
//						}
//						delete[] voleyball_competitions;
//						voleyball_competitions = new Transaction<VoleyballCompetition>*[2 * capacity3];
//						for (int i = 0; i < capacity3; i++) {
//							voleyball_competitions[i] = copy[i];
//						}
//						capacity3 = 2 * capacity3;
//						delete[] copy;
//					}
//					cout << "������� �������� ������������" << endl;
//					getline(cin, choice);
//					voleyball_competitions[count3]->operator->()->set_competitionName(choice);
//					cout << "������� ���� ������������" << endl;
//					input_check_date(choice);
//					voleyball_competitions[count3]->operator->()->set_date(choice);
//					do {
//						cout << "������� ���������� ������������� ������ (�� ������ 10)" << endl;
//						input_check_int(choice);
//						if (stoi(choice) > 10) {
//							cout << "� ������������� ����� ����������� �� ����� 10 ������" << endl;
//						}
//					} while (stoi(choice) >= 10);
//					voleyball_competitions[count3]->operator->()->set_competitorCount(stoi(choice));
//
//					int counter = 0, choices[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//					do {
//						cout << "�������� �� ������������ ������ ������������� ��� ������� 0, ���� ������ ����������." << endl;
//						for (int i = 0; i < 10; i++) {
//							if (choices[i] == 0) {
//								cout << "������� " << i + 1 << " - " << comands[i]->operator->()->get_comandName() << endl;
//							}
//						}
//						input_check_int(choice);
//						if (stoi(choice) >= 10) {
//							cout << "������� ��� ����� ������� ���" << endl;
//						}
//						else if (stoi(choice) != 0) {
//							if (choices[stoi(choice) - 1] == 1) {
//								cout << "�� ��� ������� ��� �������." << endl;
//							}
//							else {
//								counter++;
//								choices[stoi(choice)] = 1;
//							}
//						}
//						else if (counter < 2) {
//							cout << "� ������������� ������ ����������� ������� 2 �������" << endl;
//						}
//					} while (stoi(choice) != 0 && counter < 2);
//
//					voleyball_competitions[count3]->operator->()->set_comands(10, *comands);
//					cout << "������� ���������� ������" << endl;
//					input_check_int(choice);
//					voleyball_competitions[count3]->operator->()->set_blockCount(stoi(choice));
//					cout << "������� ���������� �����" << endl;
//					voleyball_competitions[count3]->operator->()->set_pointCount(stoi(choice));
//					voleyball_competitions[count3]->operator->()->file();
//				}
//				else if (compchoice == 4) {
//					if (count4 == capacity4) {
//						Transaction<HockeyCompetition>** copy = new Transaction<HockeyCompetition>*[2 * capacity4];
//						for (int i = 0; i < capacity4; i++) {
//							copy[i] = hockey_competitions[i];
//						}
//						delete[] hockey_competitions;
//						hockey_competitions = new Transaction<HockeyCompetition>*[2 * capacity4];
//						for (int i = 0; i < capacity4; i++) {
//							hockey_competitions[i] = copy[i];
//						}
//						capacity4 = 2 * capacity4;
//						delete[] copy;
//					}
//					cout << "������� �������� ������������" << endl;
//					getline(cin, choice);
//					hockey_competitions[count4]->operator->()->set_competitionName(choice);
//					cout << "������� ���� ������������" << endl;
//					input_check_date(choice);
//					hockey_competitions[count4]->operator->()->set_date(choice);
//					do {
//						cout << "������� ���������� ������������� ������ (�� ������ 10)" << endl;
//						input_check_int(choice);
//						if (stoi(choice) > 10) {
//							cout << "� ������������� ����� ����������� �� ����� 10 ������" << endl;
//						}
//					} while (stoi(choice) >= 10);
//					hockey_competitions[count4]->operator->()->set_competitorCount(stoi(choice));
//
//					int counter = 0, choices[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//					do {
//						cout << "�������� �� ������������ ������ ������������� ��� ������� 0, ���� ������ ����������." << endl;
//						for (int i = 0; i < 10; i++) {
//							if (choices[i] == 0) {
//								cout << "������� " << i + 1 << " - " << comands[i]->operator->()->get_comandName() << endl;
//							}
//						}
//						input_check_int(choice);
//						if (stoi(choice) >= 10) {
//							cout << "������� ��� ����� ������� ���" << endl;
//						}
//						else if (stoi(choice) != 0) {
//							if (choices[stoi(choice) - 1] == 1) {
//								cout << "�� ��� ������� ��� �������." << endl;
//							}
//							else {
//								counter++;
//								choices[stoi(choice)] = 1;
//							}
//						}
//						else if (counter < 2) {
//							cout << "� ������������� ������ ����������� ������� 2 �������" << endl;
//						}
//					} while (stoi(choice) != 0 && counter < 2);
//
//					hockey_competitions[count4]->operator->()->set_comands(10, *comands);
//					cout << "������� ���������� �������� �����" << endl;
//					input_check_int(choice);
//					hockey_competitions[count4]->operator->()->set_penaltyMinutes(stoi(choice));
//					cout << "������� ���������� �����" << endl;
//					hockey_competitions[count4]->operator->()->set_goalCount(stoi(choice));
//					hockey_competitions[count4]->operator->()->file();
//				}
//				else if (compchoice == 5) {
//					if (count5 == capacity5) {
//						Transaction<ChessCompetition>** copy = new Transaction<ChessCompetition>*[2 * capacity5];
//						for (int i = 0; i < capacity5; i++) {
//							copy[i] = chess_competitions[i];
//						}
//						delete[] chess_competitions;
//						chess_competitions = new Transaction<ChessCompetition>*[2 * capacity5];
//						for (int i = 0; i < capacity1; i++) {
//							chess_competitions[i] = copy[i];
//						}
//						capacity5 = 2 * capacity5;
//						delete[] copy;
//					}
//					cout << "������� �������� ������������" << endl;
//					getline(cin, choice);
//					chess_competitions[count5]->operator->()->set_competitionName(choice);
//					cout << "������� ���� ������������" << endl;
//					input_check_date(choice);
//					chess_competitions[count5]->operator->()->set_date(choice);
//					do {
//						cout << "������� ���������� ������������� ������ (�� ������ 10)" << endl;
//						input_check_int(choice);
//						if (stoi(choice) > 10) {
//							cout << "� ������������� ����� ����������� �� ����� 10 ������" << endl;
//						}
//					} while (stoi(choice) >= 10);
//					chess_competitions[count5]->operator->()->set_competitorCount(stoi(choice));
//
//					int counter = 0, choices[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//					do {
//						cout << "�������� �� ������������ ������ ������������� ��� ������� 0, ���� ������ ����������." << endl;
//						for (int i = 0; i < 10; i++) {
//							if (choices[i] == 0) {
//								cout << "������� " << i + 1 << " - " << comands[i]->operator->()->get_comandName() << endl;
//							}
//						}
//						input_check_int(choice);
//						if (stoi(choice) >= 10) {
//							cout << "������� ��� ����� ������� ���" << endl;
//						}
//						else if (stoi(choice) != 0) {
//							if (choices[stoi(choice) - 1] == 1) {
//								cout << "�� ��� ������� ��� �������." << endl;
//							}
//							else {
//								counter++;
//								choices[stoi(choice)] = 1;
//							}
//						}
//						else if (counter < 2) {
//							cout << "� ������������� ������ ����������� ������� 2 �������" << endl;
//						}
//					} while (stoi(choice) != 0 && counter < 2);
//
//					chess_competitions[count5]->operator->()->set_comands(count5, *comands);
//					cout << "������� ���������� ������" << endl;
//					input_check_int(choice);
//					chess_competitions[count5]->operator->()->set_drawCount(stoi(choice));
//					cout << "������� ���������� �����" << endl;
//					chess_competitions[count5]->operator->()->set_winCount(stoi(choice));
//					chess_competitions[count5]->operator->()->file();
//				}
//				else if (compchoice == 6) {
//					break;
//				}
//				else {
//					cout << "������ ������ �� ����������" << endl;
//				}
//			} while (compchoice != 6);
//		}
//		else if (notbroken == 2) {
//		cout << "1.�������� ���������� ������������" << endl;
//		cout << "2.�������� ������������� ������������" << endl;
//		cout << "3.�������� ������������ ������������" << endl;
//		cout << "4.�������� ��������� ������������" << endl;
//		cout << "5.�������� ��������� ������������" << endl;
//		cout << "6.�����" << endl;
//		cout << "������� ����� �� 1 �� 5, ����� �������� ����������� ��� ������������, ��� ������� ����� 6, ���� ������ ����� � ������� ����" << endl;
//		input_check_int(choice);
//		system("cls");
//		if(editchoice=stoi(choice)==1){
//			if (count1 > 0) {
//				for (int i = 0; i < 193; i++) {
//					cout << "-";
//				}
//				if (count1 != 0) {
//					cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//					for (int i = 0; i < 193; i++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				for (int i = 0; i < count1;i++) {
//					for (int j = 1; j <= football_competitions[i]->operator->()->get_competitorCount(); j++) {
//						if (j == 1) {
//							cout << "|" << setw(10) << left<< i + 1 << "|" << setw(15) << left << "������" << "|" << setw(30) << left<< football_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << football_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << football_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << football_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << football_competitions[i]->operator->()->get_redCardCount() << "|" << setw(30) << left << football_competitions[i]->operator->()->get_goalCount() << "|" << endl;;
//						}
//						else {
//							cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << football_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//						}
//					}
//					for (int f = 0; f < 193; f++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				cout << endl << "������� ����� ������������, ������� ������ ��������" << endl;
//				input_check_int(choice);
//				if (delchoice = stoi(choice) > count1) {
//					cout << "������ ������������ �� ����������" << endl;
//				}
//				else {
//					cout << "1.�������� �������� ������������" << endl;
//					cout << "2.�������� ���� ���������� ������������" << endl;
//					cout << "3.�����" << endl;
//					cout << "������� ����� �� 1 �� 2 � ����������� �� ����, ��� ������ ��������" << endl;
//					input_check_int(choice);
//					if (editchoice = stoi(choice) == 1) {
//						cout<<"������� ����� �������� ������������" << endl;
//						getline(cin, name);
//						football_competitions[delchoice - 1]->beginTransactions(name);
//					}
//
//					else if (editchoice == 2) {
//						cout <<"������� ����� ���� ������������" << endl;
//						input_check_date(date);
//						string day, month, year;
//						int counter = 0;
//						for (int i = 0; i < date.size(); i++) {
//							if (date[i] != '.') {
//								if (counter == 0) {
//									day += date[i];
//								}
//								else if (counter == 1) {
//									month += date[i];
//								}
//								else if (counter == 2) {
//									year += date[i];
//								}
//							}
//							else {
//								counter++;
//							}
//						}
//						football_competitions[delchoice - 1]->beginTransactions(stoi(day), stoi(month), stoi(year));
//					}
//					else if (editchoice == 3) {
//						break;
//					}
//					else {
//						cout << "������ ������ �� ����������" << endl;
//					}
//				}
//				
//			}
//			else {
//				cout<<"�� ������ ����������� ������������ �� ���� �������" << endl;
//			}
//		}
//		else if (editchoice == 2) {
//			if (count2 > 0) {
//				for (int i = 0; i < 193; i++) {
//					cout << "-";
//				}
//				if (count2 != 0) {
//					cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//					for (int i = 0; i < 193; i++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				for (int i = 0; i < count2;i++) {
//					for (int j = 1; j <= basketball_competitions[i]->operator->()->get_competitorCount(); j++) {
//						if (j == 1) {
//							cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "���������" << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << basketball_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << basketball_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_reboundCount() << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_pointCount() << "|" << endl;;
//						}
//						else {
//							cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//						}
//					}
//					for (int f = 0; f < 193; f++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				cout << endl << "������� ����� ������������, ������� ������ ��������" << endl;
//				input_check_int(choice);
//				if (delchoice = stoi(choice) > count2) {
//					cout << "������ ������������ �� ����������" << endl;
//				}
//				else {
//					cout << "1.�������� �������� ������������" << endl;
//					cout << "2.�������� ���� ���������� ������������" << endl;
//					cout << "3.�����" << endl;
//					cout << "������� ����� �� 1 �� 2 � ����������� �� ����, ��� ������ ��������" << endl;
//					input_check_int(choice);
//					if (editchoice = stoi(choice) == 1) {
//						cout << "������� ����� �������� ������������" << endl;
//						getline(cin, name);
//						basketball_competitions[delchoice - 1]->beginTransactions(name);
//					}
//
//					else if (editchoice == 2) {
//						cout << "������� ����� ���� ������������" << endl;
//						input_check_date(date);
//						string day, month, year;
//						int counter = 0;
//						for (int i = 0; i < date.size(); i++) {
//							if (date[i] != '.') {
//								if (counter == 0) {
//									day += date[i];
//								}
//								else if (counter == 1) {
//									month += date[i];
//								}
//								else if (counter == 2) {
//									year += date[i];
//								}
//							}
//							else {
//								counter++;
//							}
//						}
//						basketball_competitions[delchoice - 1]->beginTransactions(stoi(day), stoi(month), stoi(year));
//					}
//					else if (editchoice == 3) {
//						break;
//					}
//					else {
//						cout << "������ ������ �� ����������" << endl;
//					}
//				}
//
//			}
//			else {
//				cout << "�� ������ �������������� ������������ �� ���� �������" << endl;
//			}
//		}
//		else if (editchoice == 3) {
//		if (count3 > 0) {
//			for (int i = 0; i < 193; i++) {
//				cout << "-";
//			}
//			if (count3 != 0) {
//				cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������" << "|" << setw(30) << left << "���������� �����" << "|";
//				for (int i = 0; i < 193; i++) {
//					cout << "-";
//				}
//				cout << endl;
//			}
//			for (int i = 0; i < count3;i++) {
//				for (int j = 1; j <= voleyball_competitions[i]->operator->()->get_competitorCount(); j++) {
//					if (j == 1) {
//						cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "��������" << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << voleyball_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << voleyball_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_blockCount() << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_pointCount() << "|" << endl;
//					}
//					else {
//						cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//					}
//				}
//				for (int f = 0; f < 193; f++) {
//					cout << "-";
//				}
//				cout << endl;
//			}
//			cout << endl << "������� ����� ������������, ������� ������ ��������" << endl;
//			input_check_int(choice);
//			if (delchoice = stoi(choice) > count3) {
//				cout << "������ ������������ �� ����������" << endl;
//			}
//			else {
//				cout << "1.�������� �������� ������������" << endl;
//				cout << "2.�������� ���� ���������� ������������" << endl;
//				cout << "3.�����" << endl;
//				cout << "������� ����� �� 1 �� 2 � ����������� �� ����, ��� ������ ��������" << endl;
//				input_check_int(choice);
//				if (editchoice = stoi(choice) == 1) {
//					cout << "������� ����� �������� ������������" << endl;
//					getline(cin, name);
//					voleyball_competitions[delchoice - 1]->beginTransactions(name);
//				}
//
//				else if (editchoice == 2) {
//					cout << "������� ����� ���� ������������" << endl;
//					input_check_date(date);
//					string day, month, year;
//					int counter = 0;
//					for (int i = 0; i < date.size(); i++) {
//						if (date[i] != '.') {
//							if (counter == 0) {
//								day += date[i];
//							}
//							else if (counter == 1) {
//								month += date[i];
//							}
//							else if (counter == 2) {
//								year += date[i];
//							}
//						}
//						else {
//							counter++;
//						}
//					}
//					voleyball_competitions[delchoice - 1]->beginTransactions(stoi(day), stoi(month), stoi(year));
//				}
//				else if (editchoice == 3) {
//					break;
//				}
//				else {
//					cout << "������ ������ �� ����������" << endl;
//				}
//			}
//
//		}
//		else {
//			cout << "�� ������ ������������� ������������ �� ���� �������" << endl;
//		}
//}
//		else if (editchoice == 4) {
//		if (count4 > 0) {
//			for (int i = 0; i < 193; i++) {
//				cout << "-";
//			}
//			if (count4 != 0) {
//				cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//				for (int i = 0; i < 193; i++) {
//					cout << "-";
//				}
//				cout << endl;
//			}
//			for (int i = 0; i < count4;i++) {
//				for (int j = 1; j <= hockey_competitions[i]->operator->()->get_competitorCount(); j++) {
//					if (j == 1) {
//						cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "������" << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << hockey_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << hockey_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_penaltyMinutes() << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_goalCount() << "|" << endl;
//					}
//					else {
//						cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//					}
//				}
//				for (int f = 0; f < 193; f++) {
//					cout << "-";
//				}
//				cout << endl;
//			}
//			cout << endl << "������� ����� ������������, ������� ������ ��������" << endl;
//			input_check_int(choice);
//			if (delchoice = stoi(choice) > count4) {
//				cout << "������ ������������ �� ����������" << endl;
//			}
//			else {
//				cout << "1.�������� �������� ������������" << endl;
//				cout << "2.�������� ���� ���������� ������������" << endl;
//				cout << "3.�����" << endl;
//				cout << "������� ����� �� 1 �� 2 � ����������� �� ����, ��� ������ ��������" << endl;
//				input_check_int(choice);
//				if (editchoice = stoi(choice) == 1) {
//					cout << "������� ����� �������� ������������" << endl;
//					getline(cin, name);
//					hockey_competitions[delchoice - 1]->beginTransactions(name);
//				}
//
//				else if (editchoice == 2) {
//					cout << "������� ����� ���� ������������" << endl;
//					input_check_date(date);
//					string day, month, year;
//					int counter = 0;
//					for (int i = 0; i < date.size(); i++) {
//						if (date[i] != '.') {
//							if (counter == 0) {
//								day += date[i];
//							}
//							else if (counter == 1) {
//								month += date[i];
//							}
//							else if (counter == 2) {
//								year += date[i];
//							}
//						}
//						else {
//							counter++;
//						}
//					}
//					hockey_competitions[delchoice - 1]->beginTransactions(stoi(day), stoi(month), stoi(year));
//				}
//				else if (editchoice == 3) {
//					break;
//				}
//				else {
//					cout << "������ ������ �� ����������" << endl;
//				}
//			}
//
//		}
//		else {
//			cout << "�� ������ ���������� ������������ �� ���� �������" << endl;
//		}
//}
//		else if (editchoice == 5) {
//		if (count5 > 0) {
//			for (int i = 0; i < 193; i++) {
//				cout << "-";
//			}
//			if (count5 != 0) {
//				cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//				for (int i = 0; i < 193; i++) {
//					cout << "-";
//				}
//				cout << endl;
//			}
//			for (int i = 0; i < count5;i++) {
//				for (int j = 1; j <= chess_competitions[i]->operator->()->get_competitorCount(); j++) {
//					if (j == 1) {
//						cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "�������" << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << chess_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << chess_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_drawCount() << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_winCount() << "|" << endl;
//					}
//					else {
//						cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//					}
//				}
//				for (int f = 0; f < 193; f++) {
//					cout << "-";
//				}
//				cout << endl;
//			}
//			cout << endl << "������� ����� ������������, ������� ������ ��������" << endl;
//			input_check_int(choice);
//			if (delchoice = stoi(choice) > count2) {
//				cout << "������ ������������ �� ����������" << endl;
//			}
//			else {
//				cout << "1.�������� �������� ������������" << endl;
//				cout << "2.�������� ���� ���������� ������������" << endl;
//				cout << "3.�����" << endl;
//				cout << "������� ����� �� 1 �� 2 � ����������� �� ����, ��� ������ ��������" << endl;
//				input_check_int(choice);
//				if (editchoice = stoi(choice) == 1) {
//					cout << "������� ����� �������� ������������" << endl;
//					getline(cin, name);
//					chess_competitions[delchoice - 1]->beginTransactions(name);
//				}
//
//				else if (editchoice == 2) {
//					cout << "������� ����� ���� ������������" << endl;
//					input_check_date(date);
//					string day, month, year;
//					int counter = 0;
//					for (int i = 0; i < date.size(); i++) {
//						if (date[i] != '.') {
//							if (counter == 0) {
//								day += date[i];
//							}
//							else if (counter == 1) {
//								month += date[i];
//							}
//							else if (counter == 2) {
//								year += date[i];
//							}
//						}
//						else {
//							counter++;
//						}
//					}
//					chess_competitions[delchoice - 1]->beginTransactions(stoi(day), stoi(month), stoi(year));
//				}
//				else if (editchoice == 3) {
//					break;
//				}
//				else {
//					cout << "������ ������ �� ����������" << endl;
//				}
//			}
//
//		}
//		else {
//			cout << "�� ������ ���������� ������������ �� ���� �������" << endl;
//		}
//		}
//		else if (editchoice == 6) {
//			break;
//		}
//		else{
//			cout <<"������ ������ �� ����������" << endl;
//		}
//		}
//		else if (notbroken == 3)
//		{
//			if (count1 == count2 == count3 == count4 == count5 == 0) {
//				system("cls");
//				cout << "�� ������ ������������ �� �������" << endl;
//			}
//			else {
//				cout << "1.������� ���������� ������������" << endl;
//				cout << "2.������� ������������� ������������" << endl;
//				cout << "3.������� ������������ ������������" << endl;
//				cout << "4.������� ��������� ������������" << endl;
//				cout << "5.������� ��������� ������������" << endl;
//				cout << "6.�����" << endl;
//				cout << "������� ����� �� 1 �� 5, ����� ������� ����������� ��� ������������, ��� ������� ����� 6, ���� ������ ����� � ������� ����" << endl;
//				input_check_int(choice);
//				system("cls");
//				if (delchoice = stoi(choice) == 1) {
//					if (count1 > 0) {
//						for (int i = 0; i < 193; i++) {
//							cout << "-";
//						}
//						if (count1 != 0) {
//							cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//							for (int i = 0; i < 193; i++) {
//								cout << "-";
//							}
//							cout << endl;
//						}
//						for (int i = 0; i < count1;i++) {
//							for (int j = 1; j <= football_competitions[i]->operator->()->get_competitorCount(); j++) {
//								if (j == 1) {
//									cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "������" << "|" << setw(30) << left << football_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << football_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << football_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << football_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << football_competitions[i]->operator->()->get_redCardCount() << "|" << setw(30) << left << football_competitions[i]->operator->()->get_goalCount() << "|" << endl;;
//								}
//								else {
//									cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << football_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//								}
//							}
//							for (int f = 0; f < 193; f++) {
//								cout << "-";
//							}
//							cout << endl;
//						}
//						cout << endl << "������� ����� ������������, ������� ������ �������" << endl;
//						input_check_int(choice);
//						if (delchoice = stoi(choice) > count1) {
//							cout << "������ ������������ �� ����������" << endl;
//						}
//						else {
//							delete football_competitions[delchoice - 1];
//							count1--;
//							cout << "������������ ��� ������� " << delchoice << " ���� ������� �������" << endl;
//						}
//					}
//					else {
//						cout<<"�� ������ ����������� ������������ �� ���� �������" << endl;
//					}
//				}
//				else if (delchoice == 2) {
//					if (count2 > 0) {
//						for (int i = 0; i < 193; i++) {
//							cout << "-";
//						}
//						if (count2 != 0) {
//							cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//							for (int i = 0; i < 193; i++) {
//								cout << "-";
//							}
//							cout << endl;
//						}
//						for (int i = 0; i < count2;i++) {
//							for (int j = 1; j <= basketball_competitions[i]->operator->()->get_competitorCount(); j++) {
//								if (j == 1) {
//									cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "<���������" << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << basketball_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << basketball_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_reboundCount() << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_pointCount() << "|" << endl;;
//								}
//								else {
//									cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//								}
//							}
//							for (int f = 0; f < 193; f++) {
//								cout << "-";
//							}
//							cout << endl;
//						}
//						cout << endl << "������� ����� ������������, ������� ������ �������" << endl;
//						input_check_int(choice);
//						if (delchoice = stoi(choice) > count2) {
//							cout << "������ ������������ �� ����������" << endl;
//						}
//						else {
//							delete basketball_competitions[delchoice - 1];
//							count2--;
//							cout << "������������ ��� ������� " << delchoice << " ���� ������� �������" << endl;
//						}
//					}
//					else {
//						cout << "�� ������ �������������� ������������ �� ���� �������" << endl;
//					}
//				}
//				else if (delchoice == 3) {
//					if (count3 > 0) {
//						for (int i = 0; i < 193; i++) {
//							cout << "-";
//						}
//						if (count3 != 0) {
//							cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������" << "|" << setw(30) << left << "���������� �����" << "|";
//							for (int i = 0; i < 193; i++) {
//								cout << "-";
//							}
//							cout << endl;
//						}
//						for (int i = 0; i < count3;i++) {
//							for (int j = 1; j <= voleyball_competitions[i]->operator->()->get_competitorCount(); j++) {
//								if (j == 1) {
//									cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "<��������" << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << voleyball_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << voleyball_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_pointCount() << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_pointCount() << "|" << endl;
//								}
//								else {
//									cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//								}
//							}
//							for (int f = 0; f < 193; f++) {
//								cout << "-";
//							}
//							cout << endl;
//							
//						}
//						cout << endl << "������� ����� ������������, ������� ������ �������" << endl;
//						input_check_int(choice);
//						if (delchoice = stoi(choice) > count3) {
//							cout << "������ ������������ �� ����������" << endl;
//						}
//						else {
//							delete voleyball_competitions[delchoice - 1];
//							count3--;
//							cout << "������������ ��� ������� " << delchoice << " ���� ������� �������" << endl;
//						}
//					}
//					else {
//						cout << "�� ������ ������������� ������������ �� ���� �������" << endl;
//					}
//
//				}
//				else if (delchoice == 4) {
//					if (count4 > 0) {
//						for (int i = 0; i < 193; i++) {
//							cout << "-";
//						}
//						if (count2 != 0) {
//							cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� �������� �����" << "|" << setw(30) << left << "���������� �����" << "|";
//							for (int i = 0; i < 193; i++) {
//								cout << "-";
//							}
//							cout << endl;
//						}
//						for (int i = 0; i < count4;i++) {
//							for (int j = 1; j <= hockey_competitions[i]->operator->()->get_competitorCount(); j++) {
//								if (j == 1) {
//									cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "������" << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << hockey_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << hockey_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_penaltyMinutes() << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_goalCount() << "|" << endl;;
//								}
//								else {
//									cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//								}
//							}
//							for (int f = 0; f < 193; f++) {
//								cout << "-";
//							}
//							cout << endl;
//							
//						}
//						cout << endl << "������� ����� ������������, ������� ������ �������" << endl;
//						input_check_int(choice);
//						if (delchoice = stoi(choice) > count4) {
//							cout << "������ ������������ �� ����������" << endl;
//						}
//						else {
//							delete hockey_competitions[delchoice - 1];
//							count4--;
//							cout << "������������ ��� ������� " << delchoice << " ���� ������� �������" << endl;
//						}
//					}
//					else {
//						cout << "�� ������ ���������� ������������ �� ���� �������" << endl;
//					}
//
//				}
//				else if (delchoice == 5) {
//					if (count5 > 0) {
//						for (int i = 0; i < 193; i++) {
//							cout << "-";
//						}
//						if (count5 != 0) {
//							cout << endl << "|" << setw(10) << left << "�����" << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������" << "|" << setw(30) << left << "���������� �����" << "|";
//							for (int i = 0; i < 193; i++) {
//								cout << "-";
//							}
//							cout << endl;
//						}
//						for (int i = 0; i < count5;i++) {
//							for (int j = 1; j <= chess_competitions[i]->operator->()->get_competitorCount(); j++) {
//								if (j == 1) {
//									cout << "|" << setw(10) << left << i + 1 << "|" << setw(15) << left << "<�������" << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << chess_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << chess_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_drawCount() << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_winCount() << "|" << endl;
//								}
//								else {
//									cout << "|" << setw(10) << left << "" << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//								}
//							}
//							for (int f = 0; f < 193; f++) {
//								cout << "-";
//							}
//							cout << endl;
//							
//						}
//						cout << endl << "������� ����� ������������, ������� ������ �������" << endl;
//						input_check_int(choice);
//						if (delchoice = stoi(choice) > count5) {
//							cout << "������ ������������ �� ����������" << endl;
//						}
//						else {
//							delete chess_competitions[delchoice - 1];
//							count5--;
//							cout << "������������ ��� ������� " << delchoice << " ���� ������� �������" << endl;
//						}
//					}
//					else {
//						cout << "�� ������ ���������� ������������ �� ���� �������" << endl;
//					}
//
//				}
//				else if (delchoice == 6) {
//					break;
//				}
//				else {
//					cout << "������ ������ �� ����������" << endl;
//				}
//			}
//		}
//		else if (notbroken == 4) {
//			if (count1 == count2 == count3 == count4 == count5 == 0) {
//				cout << "�� ������ ������������ �� ������� " << endl;
//			}
//			else {
//				for (int i = 0; i < 182; i++) {
//					cout << "-";
//				}
//				if (count1 != 0) {
//					cout << endl << "|" << setw(15) << left<< "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//					for (int i = 0; i < 182; i++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				for (int i = 0; i < count1;i++) {
//					for (int j = 1; j <= football_competitions[i]->operator->()->get_competitorCount(); j++) {
//						if (j == 1) {
//							cout << "|" << setw(15) << left << "������" << "|" << setw(30) << left << football_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << football_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << football_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << football_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << football_competitions[i]->operator->()->get_redCardCount() << "|" << setw(30) << left << football_competitions[i]->operator->()->get_goalCount() << "|" << endl;;
//						}
//						else {
//							cout << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << football_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//						}
//					}
//					for (int f = 0; f < 182; f++) {
//						cout << "-";
//					}
//				}
//				if (count2 != 0) {// ��������� middle �� left 
//					cout << endl << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ��������" << "|" << setw(30) << left << "���������� �����" << "|";
//					for (int i = 0; i < 182; i++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				for (int i = 0; i < count2;i++) {
//					for (int j = 1; j <= basketball_competitions[i]->operator->()->get_competitorCount(); j++) {
//						if (j == 1) {
//							cout << "|" << setw(15) << left << "���������" << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << basketball_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << basketball_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_reboundCount() << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_pointCount() << "|" << endl;;
//						}
//						else {
//							cout << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << basketball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//						}
//					}
//					for (int f = 0; f < 182; f++) {
//						cout << "-";
//					}
//				}
//				if (count3 != 0) {
//					cout << endl << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������" << "|" << setw(30) << left << "���������� �����" << "|";
//					for (int i = 0; i < 182; i++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				for (int i = 0; i < count3;i++) {
//					for (int j = 1; j <= voleyball_competitions[i]->operator->()->get_competitorCount(); j++) {
//						if (j == 1) {
//							cout << "|" << setw(15) << left << "��������" << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << voleyball_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << voleyball_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_blockCount() << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_pointCount() << "|" << endl;;
//						}
//						else {
//							cout << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << voleyball_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//						}
//					}
//					for (int f = 0; f < 182; f++) {
//						cout << "-";
//					}
//				}
//				if (count4 != 0) {
//					cout << endl << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������� �����" << "|" << setw(30) << left << "���������� �����" << "|";
//					for (int i = 0; i < 182; i++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				for (int i = 0; i < count4;i++) {
//					for (int j = 1; j <= hockey_competitions[i]->operator->()->get_competitorCount(); j++) {
//						if (j == 1) {
//							cout << "|" << setw(15) << left << "������" << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << hockey_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << hockey_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_penaltyMinutes() << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_goalCount() << "|" << endl;;
//						}
//						else {
//							cout << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << hockey_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//						}
//					}
//					for (int f = 0; f < 182; f++) {
//						cout << "-";
//					}
//				}
//				if (count5 != 0) {
//					cout << endl << "|" << setw(15) << left << "��� ������" << "|" << setw(30) << left << "�������� ������������" << "|" << setw(15) << left << "���� ����������" << "|" << setw(24) << left << "���������� ������" << "|" << setw(30) << left << "�������" << "|" << setw(30) << left << "���������� ������" << "|" << setw(30) << left << "���������� �����" << "|";
//					for (int i = 0; i < 182; i++) {
//						cout << "-";
//					}
//					cout << endl;
//				}
//				for (int i = 0; i < count5;i++) {
//					for (int j = 1; j <= chess_competitions[i]->operator->()->get_competitorCount(); j++) {
//						if (j == 1) {
//							cout << "|" << setw(15) << left << "�������" << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_competitionName() << "|" << setw(15) << left << chess_competitions[i]->operator->()->get_date() << "|" << setw(24) << left << chess_competitions[i]->operator->()->get_competitorCount() << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_drawCount() << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_winCount() << "|" << endl;;
//						}
//						else {
//							cout << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << chess_competitions[i]->operator->()->get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//						}
//					}
//					for (int f = 0; f < 182; f++) {
//						cout << "-";
//					}
//				}
//			}
//		}
//		else if (notbroken == 5) {
//			break;
//		}
//		else {
//			cout << "������ ������ �� ���������� " << endl;
//		}
//	} while (notbroken != 5);
//}