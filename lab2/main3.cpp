#include"Header1.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int notbroken = 0, compchoice = 0, delchoice = 0, editchoice = 0;
	string choice = "", name = "", pointCount = "", place = "", date;
	int capacity1 = 10, capacity2 = 10, capacity3 = 10, capacity4 = 10, capacity5 = 10, count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	SmartPointer<Comand> comands(new Comand[count1]);
    Transaction<FootballCompetition> football_competitions(new FootballCompetition[count1]);
    Transaction<BasketballCompetition> basketball_competitions(new BasketballCompetition[count2]);
    Transaction<VoleyballCompetition> voleyball_competitions(new VoleyballCompetition[count3]);
    Transaction<HockeyCompetition> hockey_competitions(new HockeyCompetition[count4]);
    Transaction<ChessCompetition> chess_competitions(new ChessCompetition[count5]);
	/*Transaction<FootballCompetition>** football_competitions = new Transaction<FootballCompetition>*[capacity1];
	Transaction<BasketballCompetition>** basketball_competitions = new Transaction<BasketballCompetition>*[capacity2];
	Transaction < VoleyballCompetition>** voleyball_competitions = new Transaction<VoleyballCompetition>*[capacity3];
	Transaction<ChessCompetition>** chess_competitions = new Transaction<ChessCompetition>*[capacity4];
	Transaction<HockeyCompetition>** hockey_competitions = new Transaction<HockeyCompetition>*[capacity5];
	SmartPointer<Comand>** comands = new SmartPointer<Comand>*[10];
	comands[1]->operator[](1).set_comandName("�������");
	comands[2]->operator->()->set_comandName("180+");
	comands[3]->operator->()->set_comandName("������� 7");
	comands[4]->operator->()->set_comandName("��������");
	comands[5]->operator->()->set_comandName("�����");
	comands[6]->operator->()->set_comandName("��������� ����");
	comands[7]->operator->()->set_comandName("��������");
	comands[8]->operator->()->set_comandName("����� �����");
	comands[9]->operator->()->set_comandName("������ �����");
	comands[0]->operator->()->set_comandName("����� ���������");*/
	do {
		cout << "������� ����� �� 1 �� 5" << endl;
		cout << "1.�������� ���������� � �������������" << endl;
		cout << "2.��������� ���������� � �������������" << endl;
		cout << "3.�������� ���������� � �������������" << endl;
		cout << "4.����� ���������� � �������������" << endl;
		cout << "5.�����" << endl;
		input_check_int(choice);
		system("cls");
		if (stoi(choice) == 1) {

		}
		else if (stoi(choice) == 2) {

		}
		else if (stoi(choice) == 3) {

		}
		else if (stoi(choice) == 4) {

		}
		else if (stoi(choice) == 5) {
			break;
		}
		else{
			cout<<"������ ������ �� ����������." << endl;
		}
	} while (stoi(choice)!=5);
}