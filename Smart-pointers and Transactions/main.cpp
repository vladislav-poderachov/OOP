#include"Header.h"
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string choice = "";
    SmartPointer<Comand>* comands;
    int comandsCount=10, competitionsCount=0, capacity=10;
    Transaction<Competition> **competitions=new Transaction<Competition>*[capacity];
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
            do {
                cout << "������� ����� �� 1 �� 5, ����� �������� ������������ ���� ������������, ��� ����� 6, ����� ����� ������� � ������� ����." << endl;
                cout << "1.�������� ������������ �� �������." << endl;
                cout << "2.�������� ������������ �� ����������." << endl;
                cout << "3.�������� ������������ �� ���������." << endl;
                cout << "4.�������� ������������ �� ������." << endl;
                cout << "5.�������� ������������ �� ��������." << endl;
                cout << "6.����� � ������� ����." << endl;
                input_check_int(choice);
                system("cls");
                if (competitionsCount == capacity) {
                    Transaction<Competition>** copy = new Transaction<Competition>*[capacity * 2];
                    for (int i = 0; i < capacity; i++) {
                        copy[i] = competitions[i];
                    }
                    delete[] competitions;
                    competitions = new Transaction<Competition>*[capacity * 2];
                    for (int i = 0; i < capacity; i++) {
                        competitions[i] = copy[i];
                    }
                    capacity = 2 * capacity;
                    delete[] copy;
                }
                if (stoi(choice) == 1) {
                    Competition* footbc = new FootballCompetition();
                    footbc->set_info();
                    competitions[competitionsCount] = new Transaction<Competition>(footbc);
                    competitionsCount++;
                    ofstream out;
                    out.open("competitions.txt", ios::app);
                    FhorizontalLine(206);
                    out << "|" << setw(40) << left << " �������� ������������" << "|" << " ���� ������������ " << "|" << " ������ ������������ " << "|" << " ���������� ������ " << "|" << setw(25) << left << " �������" << "|" << " �������� ����� " << "| " << setw(54) << left << "�������������� ����������" << "|" << endl;
                    out.close();
                    for (int i = 0; i < competitionsCount;i++) {
                        competitions[i]->operator->()->file();
                    }
                    
                }
                else if (stoi(choice) == 2) {
                    Competition* basketc = new BasketballCompetition();
                    basketc->set_info();
                    competitions[competitionsCount] = new Transaction<Competition>(basketc);
                    competitionsCount++;
                }
                else if (stoi(choice) == 3) {
                    Competition* voleyc = new VoleyballCompetition();
                    voleyc->set_info();
                    competitions[competitionsCount] = new Transaction<Competition>(voleyc);
                    competitionsCount++;
                }
                else if (stoi(choice) == 4) {
                    Competition* hockeyc = new HockeyCompetition();
                    hockeyc->set_info();
                    competitions[competitionsCount] = new Transaction<Competition>(hockeyc);
                    competitionsCount++;
                }
                else if (stoi(choice) == 5) {
                    Competition* chessc = new ChessCompetition();
                    chessc->set_info();
                    competitions[competitionsCount] = new Transaction<Competition>(chessc);
                    competitionsCount++;
                }
                else if (stoi(choice) == 6) {
                    break;
                }
                else {
                    cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
                }
            } while (stoi(choice)!=6);
        }
        else if (stoi(choice) == 2) {
            do {
                cout <<"������� 1, ����� �������� ���������� � ������������, ��� ����� 2, ����� ��������� � ������� ����" << endl;
                cout << "1.�������� ���������� � ������������." << endl;           
                cout << "2.����� � ������� ����." << endl;
                input_check_int(choice);
                if (stoi(choice) == 1) {
                    horizontalLine(206);
                    cout << "| " << setw(4) << left << "�" << "|" << setw(40) << left << " �������� ������������" << "|" << " ���� ������������ " << "|" << " ������ ������������ " << "|" << " ���������� ������ " << "|" << setw(25) << left << " �������" << "|" << " �������� ����� " << "| " << setw(54) << left << "�������������� ����������" << "|" << endl;
                    for (int i = 0; i < competitionsCount;i++) {
                        cout << "| " <<setw(4)<<left <<i + 1;
                        competitions[i]->operator->()->get_info();
                    }
                    do {
                        cout << "������� ����� ������������, � ������� ������ �������� ����������." << endl;
                        input_check_int(choice);
                        if (stoi(choice) > competitionsCount) {
                            cout << "������ ������������ �� ����������. ���������� ��� ���." << endl;
                        }
                        else {
                            string nullchoice="";
                            cout<<"������� ����� 0, ����� �������� ���� ������������ � ������� ��������� ����������, ��� ����� ����������� �����, ����� ������ �������� ����������." << endl;
                            input_check_int(nullchoice);
                            if (stoi(nullchoice) == 0) {
                                cout<<"������� ����� 1, ����� ���������� ����� ����, ��� ����� 2, ����� ������� �������" << endl;
                                cout<<"1.���������� ����� ����." << endl;
                                cout << "2.������� ������� ����." << endl;
                                input_check_int(nullchoice);
                                if (stoi(nullchoice) == 1) {
                                    cout<<"������� ����� ����." << endl;
                                    input_check_date(nullchoice);
                                    competitions[stoi(choice)-1]->beginTransactions(nullchoice);
                                    for (int i = 0; i < competitionsCount; i++) {
                                        competitions[i]->operator->()->file();
                                    }
                                }
                                else if (stoi(nullchoice) == 2) {
                                    competitions[stoi(choice) - 1]->deleteTransactions();
                                    for (int i = 0; i < competitionsCount; i++) {
                                        competitions[i]->operator->()->file();
                                    }
                                }
                            }
                            else {
                                competitions[stoi(choice) - 1]->operator->()->edit_info();
                                for (int i = 0; i < competitionsCount; i++) {
                                    competitions[i]->operator->()->file();
                                }
                            }
                        }
                    } while (stoi(choice) > competitionsCount);
                }
                else if (stoi(choice) == 2) {
                    break;
                }
                else {
                    cout<<"������ ������ ���. ���������� ��� ���." << endl;
                }
            } while (stoi(choice)!=2);
        }
        else if (stoi(choice) == 3) {
            do {
                cout << "������� �� ������ ����� ������������ , ������� ������ �������." << endl;
                input_check_int(choice);
                if (stoi(choice) > competitionsCount) {
                    cout << "������������ � ����� ������� ����������� � ������. ���������� ��� ���." << endl;
                }
            } while (stoi(choice)>competitionsCount);
            for (int i = stoi(choice); i < competitionsCount-1; i++) {
                competitions[i] = competitions[i + 1];
            }
            delete competitions[competitionsCount - 1];
            competitionsCount--;
        }
        else if (stoi(choice) == 4) {
            horizontalLine(206);
            cout<<"|" << setw(40) << left << " �������� ������������" << "|" << " ���� ������������ " <<"|" << " ������ ������������ " << "|" << " ���������� ������ " <<"|" << setw(25) <<left << " �������" << "|" << " �������� ����� " << "| " <<setw(54)<<left<<"�������������� ����������"<< "   |" << endl;
            horizontalLine(206);
            for (int i = 0; i < competitionsCount;i++) {
                competitions[i]->operator->()->get_info();
            }
            system("pause");
            system("cls");
 }
        else if (stoi(choice) == 5) {
            break;
        }
        else {
            cout << "������ ������ �� ����������. ���������� ��� ���." << endl;
        }
    } while (stoi(choice)!=5);
}