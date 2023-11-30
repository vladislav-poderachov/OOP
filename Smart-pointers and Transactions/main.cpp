#include"Header.h"
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string choice = "";
    SmartPointer<Comand>* comands;
    int comandsCount=10, competitionsCount=0, capacity=10;
    Transaction<Competition> **competitions=new Transaction<Competition>*[capacity];
    do {
        cout << "Введите число от 1 до 5" << endl;
        cout << "1.Введение информации о соревнованиях" << endl;
        cout << "2.Изменение информации о соревнованиях" << endl;
        cout << "3.Удаление информации о соревнованиях" << endl;
        cout << "4.Вывод информации о соревнованиях" << endl;
        cout << "5.Выход" << endl;
        input_check_int(choice);
        system("cls");
        if (stoi(choice) == 1) {
            do {
                cout << "Введите число от 1 до 5, чтобы добавить определённого вида соревнования, или число 6, чтобы выйти обратно в главное меню." << endl;
                cout << "1.Добавить соревнование по футболу." << endl;
                cout << "2.Добавить соревнование по баскетболу." << endl;
                cout << "3.Добавить соревнование по волейболу." << endl;
                cout << "4.Добавить соревнование по хоккею." << endl;
                cout << "5.Добавить соревнование по шахматам." << endl;
                cout << "6.Выйти в главное меню." << endl;
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
                    out << "|" << setw(40) << left << " Название соревнований" << "|" << " Дата соревнований " << "|" << " Статус соревнований " << "|" << " Количество команд " << "|" << setw(25) << left << " Команды" << "|" << " Итоговые места " << "| " << setw(54) << left << "Дополнительная информация" << "|" << endl;
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
                    cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
                }
            } while (stoi(choice)!=6);
        }
        else if (stoi(choice) == 2) {
            do {
                cout <<"Введите 1, чтобы изменить информацию в соревновании, или число 2, чтобы вернуться в главное меню" << endl;
                cout << "1.Изменить информацию о соревновании." << endl;           
                cout << "2.Выйти в главное меню." << endl;
                input_check_int(choice);
                if (stoi(choice) == 1) {
                    horizontalLine(206);
                    cout << "| " << setw(4) << left << "№" << "|" << setw(40) << left << " Название соревнований" << "|" << " Дата соревнований " << "|" << " Статус соревнований " << "|" << " Количество команд " << "|" << setw(25) << left << " Команды" << "|" << " Итоговые места " << "| " << setw(54) << left << "Дополнительная информация" << "|" << endl;
                    for (int i = 0; i < competitionsCount;i++) {
                        cout << "| " <<setw(4)<<left <<i + 1;
                        competitions[i]->operator->()->get_info();
                    }
                    do {
                        cout << "Введите номер соревнования, в котором хотите изменить информацию." << endl;
                        input_check_int(choice);
                        if (stoi(choice) > competitionsCount) {
                            cout << "Такого соревнования не существует. Попробуйте ещё раз." << endl;
                        }
                        else {
                            string nullchoice="";
                            cout<<"Введите число 0, чтобы изменить дату соревнования с помощью механизма транзакций, или любое натуральное число, чтобы просто изменить информацию." << endl;
                            input_check_int(nullchoice);
                            if (stoi(nullchoice) == 0) {
                                cout<<"Введите число 1, чтобы установить новую дату, или число 2, чтобы вернуть прежнюю" << endl;
                                cout<<"1.Установить новую дату." << endl;
                                cout << "2.Вернуть прошлую дату." << endl;
                                input_check_int(nullchoice);
                                if (stoi(nullchoice) == 1) {
                                    cout<<"Введите новую дату." << endl;
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
                    cout<<"Такого выбора нет. Попробуйте ещё раз." << endl;
                }
            } while (stoi(choice)!=2);
        }
        else if (stoi(choice) == 3) {
            do {
                cout << "Введите из списка номер соревнования , которое хотите удалить." << endl;
                input_check_int(choice);
                if (stoi(choice) > competitionsCount) {
                    cout << "Соревнование с таким номером отсутствует в списке. Попробуйте ещё раз." << endl;
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
            cout<<"|" << setw(40) << left << " Название соревнований" << "|" << " Дата соревнований " <<"|" << " Статус соревнований " << "|" << " Количество команд " <<"|" << setw(25) <<left << " Команды" << "|" << " Итоговые места " << "| " <<setw(54)<<left<<"Дополнительная информация"<< "   |" << endl;
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
            cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
        }
    } while (stoi(choice)!=5);
}