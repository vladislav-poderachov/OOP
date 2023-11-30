#include"Header.h"
void input_check_int(string& str) {
    int i = 0;
    do {
        getline(std::cin, str);
        if (str.empty()) {
            cout << "Введите хотя бы одно число" << endl;
            continue;
        }
        for (i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                if (i == 0) {
                    continue;
                }
                else if (str[i - 1] == '0' || isdigit(str[i - 1])) {
                    cout << "Не вводите пробелы" << endl;
                    break;
                }


            }
            else if (str[i] == '-') {
                cout << "Вводите только натуральные числа" << endl;
                break;
            }
            else if (iswalpha(str[i])) {
                cout << "Вводите только числа. Никаких букв." << endl;
                break;
            }
            else if (!isdigit(str[i])) {
                cout << "Вводите только числа." << endl;
                break;
            };
        }
    } while (i < str.length() || str.empty());
}
string input_check_string() {
    string str;
    bool valid;
    do {
        getline(cin, str);
        valid = true;
        if (str.empty()) {
            cout << "Строка не может быть пустой" << endl;
            valid = false;
        }
        else if (!iswupper((unsigned char)str[0])) {
            cout << "Строка должна начинаться с большой буквы" << endl;
            valid = false;
        }
        else {
            for (int i = 1; i < str.length(); i++) {
                if (str[i] == ' ') {
                    cout << "Строка не должна содержать пробелов" << endl;
                    valid = false;
                    break;
                }
                else if (!iswalpha((unsigned char)str[i])) {
                    cout << "Строка должна состоять только из букв" << endl;
                    valid = false;
                    break;
                }
                else if (str[i] < -64 || str[i] > -1) {
                    cout << "Строка должна быть на русском языке" << endl;
                    valid = false;
                    break;
                }
                else if (iswupper((unsigned char)str[i])) {
                    cout << "Строка не должна содержать заглавных букв после первой" << endl;
                    valid = false;
                    break;
                }
            }
        }
    } while (!valid);
    return str;
}
void horizontalLine(int linelength) {
    for (int i = 0; i < linelength; i++) {
        cout <<"-";
    }
    cout << endl;
    
}
void FhorizontalLine(int linelength) {
    ofstream out;
    out.open("competitions.txt", ios::app);
        for (int i = 0; i < linelength; i++) {
            out << "-";
        }
        out << endl;
}
void input_check_date(string &date) {
    string day = "", month = "", year = "";
    int i = 0, pointCount = 0, errorCount=0;
    do {
        do {
            errorCount = 0;
            getline(std::cin, date);
            if (date.empty()) {
                cout << "Вы ничего не ввели." << endl;
                continue;
            }
            for (i = 0; i < date.length(); i++) {
                if (date[i] == '.') {
                    pointCount++;
                    continue;
                }
                if (date[i] == ' ') {
                    cout << "Не вводите пробелы" << endl;
                    errorCount = 1;
                    break;
                }               
                else if (!isdigit(date[i])) {
                    cout << "Вводите только числа." << endl;
                    errorCount = 1;
                    break;
                };
            }
            if (errorCount == 0 && pointCount !=2) {
                cout<<"Вы ввели неверное количество точек." << endl;
            }
        } while (errorCount==1|| date.empty()||pointCount!=2);
        pointCount = 0;
        for (i = 0; i < date.length(); i++) {
            if (date[i] != '.') {
                if (pointCount == 0) {
                    day += date[i];
                }
                else if (pointCount == 1) {
                    month += date[i];
                }
                else if (pointCount == 2) {
                    year += date[i];
                }
            }
            else {
                pointCount++;
            }
        }
        if (day.length() == 0 || day.length() > 2 || month.length() == 0 || month.length() > 2 || year.length() < 2 || year.length() > 4 || year.length() == 3) {
            cout << "Неправильно введена дата. Попробуйте ещё раз." << endl;
            errorCount = 1;
        }
        else {
            if (day.length() == 1) {
                day[1] = day[0];
                day[0] = '0';
            }
            if (month.length() == 1) {
                month[1] = month[0];
                month[0] = '0';
            }
            if (year.length() == 2) {
                year[3] = year[0];
                year[4] = year[1];
                year[1] = '0';
                year[0] = '2';
            }
        }
    } while (errorCount==1);
}

