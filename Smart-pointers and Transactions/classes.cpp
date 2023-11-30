#include"Header.h"
template<class F>
SmartPointer<F>::SmartPointer(F* ptr)
{
    if (!ptr)
        smartPtr = NULL;
    else
    {
        smartPtr = new Status<F>();
        smartPtr->ptr = ptr;
        smartPtr->counter = 1;
    }
}
template<class F>
SmartPointer<F>::SmartPointer() {
    smartPtrCount = 0;
    smartPtr = NULL;
}
template<class F>
SmartPointer<F>::SmartPointer(const SmartPointer& obj) :smartPtr(obj.smartPtr) {
    if (smartPtr) {
        smartPtr->counter++;
    }
}
template<class F>
SmartPointer<F>::~SmartPointer() {
    if (smartPtr)
    {
        smartPtr->counter--;
        if (smartPtr->counter == 0) {
            delete smartPtr->ptr;
            delete smartPtr;
        }
    }
}
//template<class F>
//SmartPointer<F>& SmartPointer<F>::operator=(const SmartPointer& obj) {
//    if (smartPtr) {
//        smartPtr->counter--;
//        if (smartPtr->counter == 0) {
//            delete smartPtr->ptr;
//            delete smartPtr;
//        }
//    }
//    smartPtr = obj.smartPtr;
//    if (smartPtr) {
//        smartPtr->counter++;
//    }
//    return *this;
//}
template<class F>
void SmartPointer<F>::ShowCounter() {
    cout << "Значение счётчика равно для объекта" << smartPtr << " равно " << smartPtr->counter << endl;
}
//template<class F>
//F* SmartPointer<F>::operator->() const {
//    if (smartPtr) {
//        return smartPtr->ptr;
//    }
//    else {
//        return NULL;
//    }
//}
template<class F>
Transaction<F>::Transaction() :prevState(NULL), currentState(new F) {
}
//template<class F>
//Transaction<F>::Transaction(F* currentState) {
//    prevState = NULL;
//    this->currentState = currentState;
//}
//template<class F>
//int Transaction<F>::beginTransactions(string date) {
//    delete prevState;
//    prevState = currentState;
//    currentState = new F(*prevState);
//    if (!currentState) {
//        return 0;
//    }
//    currentState->set_date(date);//продолжить делать под свою программу
//    return 1;
//}
//template<class F>
//Transaction<F>::~Transaction() {
//    delete currentState;
//    delete prevState;
//}
//template<class F>
//F* Transaction<F>::operator->()const{
//    return currentState;
//}
//template<class F>
//void Transaction<F>::deleteTransactions() {
//    if (prevState != NULL) {
//        delete currentState;
//        currentState = prevState;
//        prevState = NULL;
//    }
//}
//template<class F>
//Transaction<F>& Transaction<F>::operator=(const Transaction<F>& obj) {
//    if (this != &obj) {
//        delete currentState;
//        currentState = new F(*(obj.currentState));
//    }
//    return *this;
//}
template<class F>
void Transaction<F>::commit() {
    delete  prevState;
    prevState = NULL;
}
Comand::Comand() {
    comandName = "no name";
}
void Comand::set_comandName(string comandName) {
    this->comandName = comandName;
}
string Comand::get_comandName() {
    return comandName;
}
Comand::Comand(string comandName) {
    this->comandName = comandName;
}
Competition::Competition() {
    competitorCount = 10;
    comands = new SmartPointer<Comand>[competitorCount];
    comandPoints = new int[competitorCount];
    comandPlaces = new int[competitorCount];
    date = "00.00.0000";
}
Competition::Competition(string competitionName, string date, int competitorCount, SmartPointer<Comand>* comands, int *comandPoints, int *comandPlaces) {
    this->date = date;
    this->competitorCount = competitorCount;
    this->comands = new SmartPointer<Comand>[competitorCount];
    for (int i = 0; i < competitorCount;i++) {
        this->comands[i] = comands[i];
        this->comandPoints[i] = comandPoints[i];
        this->comandPlaces[i] = comandPlaces[i];
    }
}
Competition::Competition(const Competition& obj) {
    if (comands) {
        delete[] comands;
        delete[] comandPlaces;
    }
    this->date = obj.date;
    this->competitorCount = obj.competitorCount;
    this->competitionName = obj.competitionName;
    this->competitionsStatus = obj.competitionsStatus;
    this->comands = new SmartPointer<Comand>[competitorCount];
    this->comandPlaces = new int[competitorCount];
    for (int i = 0; i < competitorCount; i++) {
        this->comands[i] = obj.comands[i];
        this->comandPlaces[i] = obj.comandPlaces[i];
    }
}
Competition::~Competition() {
    delete[] comands;
}
void Competition::set_Places(int CompetitorCount, int* Places) {
    this->competitorCount = CompetitorCount;
    this->comandPlaces = new int[CompetitorCount];
    for (int i = 0; i < CompetitorCount; i++) {
        comandPlaces[i] = Places[i];
    }
}
void Competition::set_date(string str) {
    date = str;
    }
void Competition::set_comands(int CompetitorCount, SmartPointer<Comand>* comands) {
    this->competitorCount = CompetitorCount;
    this->comands = new SmartPointer<Comand>[CompetitorCount];
    for (int i = 0; i < competitorCount; i++) {
        this->comands[i] = comands[i];
    }
}
void Competition::set_competitionStatus(string str) {
    competitionsStatus =str;
};
string Competition::get_competitionStatus() {
    return competitionsStatus;
}
void Competition::file() {
}
string Competition::get_comand(int position) {
    return comands[position - 1]->get_comandName();
}
int Competition::get_competitorCount() {
    return competitorCount;
}
void Competition::set_competitorCount(int competitorCount) {
    this->competitorCount = competitorCount;
}
string Competition::get_date() {
    return date;
}
SmartPointer<Comand>* Competition::get_comands() {
    return comands;
}
int Competition::get_place(int position) {
    return comandPlaces[position - 1];
}
void Competition::set_competitionName(string competitionName) {
    this->competitionName = competitionName;
}
string Competition::get_competitionName() {
    return competitionName;
}
FootballCompetition::FootballCompetition() {
    goalCount = 0;
    redCardCount = 0;
}
FootballCompetition::FootballCompetition(int goalCount, int redCardCount) {
    this->goalCount = goalCount;
    this->redCardCount = redCardCount;
}
FootballCompetition::~FootballCompetition() {
}
int FootballCompetition::get_goalCount() {
    return goalCount;
}
void FootballCompetition::set_goalCount(int goalCount) {
    this->goalCount = goalCount;
}
void FootballCompetition::set_redCardCount(int redCardCount) {
    this->redCardCount = redCardCount;
}
//void FootballCompetition::file() {
//    ofstream out;
//    out.open("football_competititons.txt", ios::app);
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество красных карточек" << "|" << setw(30) << left << "Количество голов" << "|";
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl;
//    for (int j = 1; j <= get_competitorCount(); j++) {
//        if (j == 1) {
//            out << "|" << setw(15) << left << "Футбол" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_redCardCount() << "|" << setw(30) << left << get_goalCount() << "|" << endl;;
//        }
//        else {
//            out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//        }
//    }
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out.close();
//}
int FootballCompetition::get_redCardCount() {
    return redCardCount;
}
BasketballCompetition::BasketballCompetition() {
    pointCount = 0;
    reboundCount = 0;
}
BasketballCompetition::BasketballCompetition(int pointCount, int reboundCount) {
    this->pointCount = pointCount;
    this->reboundCount = reboundCount;
}
BasketballCompetition::~BasketballCompetition() {
}
void BasketballCompetition::set_pointCount(int pointCount) {
    this->pointCount = pointCount;
}
void BasketballCompetition::set_reboundCount(int reboundCount) {
    this->reboundCount = reboundCount;
}
int BasketballCompetition::get_pointCount() {
    return pointCount;
}
int BasketballCompetition::get_reboundCount() {
    return reboundCount;
}
//void BasketballCompetition::file() {
//    ofstream out;
//    out.open("basketball_competititons.txt", ios::app);
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество подборов" << "|" << setw(30) << left << "Количество очков" << "|";
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl;
//    for (int j = 1; j <= get_competitorCount(); j++) {
//        if (j == 1) {
//            out << "|" << setw(15) << left << "Баскетбол" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_reboundCount() << "|" << setw(30) << left << get_pointCount() << "|" << endl;
//        }
//        else {
//            out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//        }
//    }
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out.close();
//}
VoleyballCompetition::VoleyballCompetition() {
    pointCount = 0;
    blockCount = 0;
}
VoleyballCompetition::VoleyballCompetition(int pointCount, int blockCount) {
    this->pointCount = pointCount;
    this->blockCount = blockCount;
}
VoleyballCompetition::~VoleyballCompetition() {
}
void VoleyballCompetition::set_blockCount(int blockCount) {
    this->blockCount = blockCount;
}
void VoleyballCompetition::set_pointCount(int pointCount) {
    this->pointCount = pointCount;
}
int VoleyballCompetition::get_blockCount() {
    return blockCount;
}
int VoleyballCompetition::get_pointCount() {
    return pointCount;
}
//void VoleyballCompetition::file() {
//    ofstream out;
//    out.open("basketball_competititons.txt", ios::app);
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество блоков" << "|" << setw(30) << left << "Количество очков" << "|";
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl;
//    for (int j = 1; j <= get_competitorCount(); j++) {
//        if (j == 1) {
//            out << "|" << setw(15) << left << "Волейбол" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_blockCount() << "|" << setw(30) << left << get_pointCount() << "|" << endl;;
//        }
//        else {
//            out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//        }
//    }
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out.close();
//}
//void HockeyCompetition::file() {
//    ofstream out;
//    out.open("hockey_competititons.txt", ios::app);
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество штрафных минут" << "|" << setw(30) << left << "Количество голов" << "|";
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl;
//    for (int j = 1; j <= get_competitorCount(); j++) {
//        if (j == 1) {
//            out << "|" << setw(15) << left << "Хоккей" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_penaltyMinutes() << "|" << setw(30) << left << get_goalCount() << "|" << endl;;
//        }
//        else {
//            out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//        }
//    }
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out.close();
//}
HockeyCompetition::HockeyCompetition() {
    goalCount = 0;
    penaltyMinutes = 0;
}
HockeyCompetition::HockeyCompetition(int goalCount, int penaltyMinutes) {
    this->goalCount = goalCount;
    this->penaltyMinutes = penaltyMinutes;
}
HockeyCompetition:: ~HockeyCompetition() {
}
int HockeyCompetition::get_goalCount() {
    return goalCount;
}
void HockeyCompetition::set_goalCount(int goalCount) {
    this->goalCount = goalCount;
}
void HockeyCompetition::set_penaltyMinutes(int penalyMinutes) {
    this->penaltyMinutes = penaltyMinutes;
}
int HockeyCompetition::get_penaltyMinutes() {
    return penaltyMinutes;
}
ChessCompetition::ChessCompetition() {
    winCount = 0;
    drawCount = 0;
}
ChessCompetition::ChessCompetition(int winCount, int drawCount) {
    this->winCount = winCount;
    this->drawCount = drawCount;
}
ChessCompetition::~ChessCompetition() {

}
int ChessCompetition::get_winCount() {
    return winCount;
};
void ChessCompetition::set_drawCount(int drawCount) {
    this->drawCount = drawCount;
}
int ChessCompetition::get_drawCount() {
    return drawCount;
};
void ChessCompetition::set_winCount(int winCount) {
    this->winCount = winCount;
}
//void ChessCompetition::file() {
//    ofstream out;
//    out.open("chess_competititons.txt", ios::app);
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество ничьих" << "|" << setw(30) << left << "Количество побед" << "|";
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out << endl;
//    for (int j = 1; j <= get_competitorCount(); j++) {
//        if (j == 1) {
//            out << "|" << setw(15) << left << "Шахматы" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_drawCount() << "|" << setw(30) << left << get_winCount() << "|" << endl;;
//        }
//        else {
//            out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
//        }
//    }
//    for (int i = 0; i < 182; i++) {
//        out << "-";
//    }
//    out.close();
//}
void FootballCompetition::set_info() {
    string str = "";
    SmartPointer<Comand>* comands;
    cout << "Введите название соревнования по футболу" << endl;
    getline(cin, str);
    set_competitionName(str);
    cout << "Введите дату соревнований по футболу." << endl;
    input_check_date(str);
    set_date(str);
    do {
        cout << "Введите число от 1 до 2, чтобы выбрать статус соревнования по футболу." << endl;
        cout << "1.Планируемое соренование" << endl;
        cout << "2.Проведённое соревнование" << endl;
        input_check_int(str);
        if (stoi(str) == 1) {
            set_competitionStatus("Планируемое");
        }
        else if (stoi(str) == 2) {
            set_competitionStatus("Проведённое");
        }
        else {
            cout << "Такого выбора не существует." << endl;
        }
    } while (stoi(str) > 2);
    cout << "Введите количество команд в соревновании по футболу." << endl;
    do {
        input_check_int(str);
        if (stoi(str) < 2) {
            cout << "Количество команд должно быть не меньше двух." << endl;
        }
    } while (stoi(str) < 2);
    set_competitorCount(stoi(str));
    comands = new SmartPointer<Comand>[get_competitorCount()];
    for (int i = 0; i < get_competitorCount(); i++) {
        cout << "Введите навзвание " << i + 1 << " команды." << endl;
        getline(cin, str);
        comands[i] = SmartPointer<Comand>(new Comand(str));
    }
    set_comands(get_competitorCount(), comands);
    int* comandsPlaces = new int[get_competitorCount()];
    if (get_competitionStatus() == "Планируемое") {
        for (int i = 0; i < get_competitorCount(); i++) {
            comandsPlaces[i] = 0;
        }
        set_Places(get_competitorCount(), comandsPlaces);
    }
    else {
        int j;
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                input_check_int(str);
                if (stoi(str) > get_competitorCount()) {
                    cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                    continue;
                }
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
            comandsPlaces[i] = stoi(str);
        }
        int size = sizeof(comandsPlaces) / (comandsPlaces[0]);
        /* quickSortAscending(comandsPlaces, comands, size);*/
        cout << "Введите количество голов в соревновании по футболу." << endl;
        input_check_int(str);
        goalCount = stoi(str);
        cout << "Введите количество красных карточек в соревновании по футболу." << endl;
        input_check_int(str);
        redCardCount = stoi(str);
    }
}
void BasketballCompetition::set_info() {
    string str = "";
    SmartPointer<Comand>* comands;
    cout << "Введите название соревнования по баскетболу" << endl;
    getline(cin, str);
    set_competitionName(str);
    cout << "Введите дату соревнований по баскетболу." << endl;
    input_check_date(str);
    set_date(str);
    do {
        cout << "Введите число от 1 до 2, чтобы выбрать статус соревнования по баскетболу." << endl;
        cout << "1.Планируемое соренование" << endl;
        cout << "2.Проведённое соревнование" << endl;
        input_check_int(str);
        if (stoi(str) == 1) {
            set_competitionStatus("Планируемое");
        }
        else if (stoi(str) == 2) {
            set_competitionStatus("Проведённое");
        }
        else {
            cout << "Такого выбора не существует." << endl;
        }
    } while (stoi(str) > 2);
    cout << "Введите количество команд в соревновании по баскетболу." << endl;
    do {
        input_check_int(str);
        if (stoi(str) < 2) {
            cout << "Количество команд должно быть не меньше двух." << endl;
        }
    } while (stoi(str) < 2);
    set_competitorCount(stoi(str));
    comands = new SmartPointer<Comand>[get_competitorCount()];
    for (int i = 0; i < get_competitorCount(); i++) {
        cout << "Введите навзвание " << i + 1 << " команды." << endl;
        getline(cin, str);
        comands[i] = SmartPointer<Comand>(new Comand(str));
    }
    set_comands(get_competitorCount(), comands);
    int* comandsPlaces = new int[get_competitorCount()], * comandsPointCount = new int[get_competitorCount()];
    if (get_competitionStatus() == "Планируемое") {
        for (int i = 0; i < get_competitorCount(); i++) {
            comandsPlaces[i] = 0;
            comandsPointCount[i] = 0;
        }
    }
    else {
        int j;
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                input_check_int(str);
                if (stoi(str) > get_competitorCount()) {
                    cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                    continue;
                }
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
            comandsPlaces[i] = stoi(str);
        }
        long size = sizeof(comandsPlaces) / (comandsPlaces[0]);
        /* quickSortAscending(comandsPlaces, comands, size);*/
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите количество очков " << " команды под названием '" << comands[i].operator->()->get_comandName() << "', находящейся на " << comandsPlaces[i] << "-ом месте." << endl;
                input_check_int(str);
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
        }
    }
    cout << "Введите количество подборов в соревновании по баскетболу." << endl;
    input_check_int(str);
    reboundCount= stoi(str);
    cout << "Введите количество набранных очков в соревновании по баскетболу." << endl;
    input_check_int(str);
    pointCount = stoi(str);
}
void VoleyballCompetition::set_info() {
    string str = "";
    SmartPointer<Comand>* comands;
    cout << "Введите название соревнования по волейболу" << endl;
    getline(cin, str);
    set_competitionName(str);
    cout << "Введите дату соревнований по волейболу." << endl;
    input_check_date(str);
    set_date(str);
    do {
        cout << "Введите число от 1 до 2, чтобы выбрать статус соревнования по волейболу." << endl;
        cout << "1.Планируемое соренование" << endl;
        cout << "2.Проведённое соревнование" << endl;
        input_check_int(str);
        if (stoi(str) == 1) {
            set_competitionStatus("Планируемое");
        }
        else if (stoi(str) == 2) {
            set_competitionStatus("Проведённое");
        }
        else {
            cout << "Такого выбора не существует." << endl;
        }
    } while (stoi(str) > 2);
    cout << "Введите количество команд в соревновании по волейболу." << endl;
    do {
        input_check_int(str);
        if (stoi(str) < 2) {
            cout << "Количество команд должно быть не меньше двух." << endl;
        }
    } while (stoi(str) < 2);
    set_competitorCount(stoi(str));
    comands = new SmartPointer<Comand>[get_competitorCount()];
    for (int i = 0; i < get_competitorCount(); i++) {
        cout << "Введите навзвание " << i + 1 << " команды." << endl;
        getline(cin, str);
        comands[i] = SmartPointer<Comand>(new Comand(str));
    }
    set_comands(get_competitorCount(), comands);
    int* comandsPlaces = new int[get_competitorCount()], * comandsPointCount = new int[get_competitorCount()];
    if (get_competitionStatus() == "Планируемое") {
        for (int i = 0; i < get_competitorCount(); i++) {
            comandsPlaces[i] = 0;
            comandsPointCount[i] = 0;
        }
    }
    else {
        int j;
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                input_check_int(str);
                if (stoi(str) > get_competitorCount()) {
                    cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                    continue;
                }
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
            comandsPlaces[i] = stoi(str);
        }
        long size = sizeof(comandsPlaces) / (comandsPlaces[0]);
        /* quickSortAscending(comandsPlaces, comands, size);*/
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите количество очков " << " команды под названием '" << comands[i].operator->()->get_comandName() << "', находящейся на " << comandsPlaces[i] << "-ом месте." << endl;
                input_check_int(str);
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
        }
    }
    cout << "Введите количество набранных очков соревновании по футболу." << endl;
    input_check_int(str);
    pointCount = stoi(str);
    cout << "Введите количество блоков в соревновании по футболу." << endl;
    input_check_int(str);
    blockCount = stoi(str);
}
void HockeyCompetition::set_info() {
    string str = "";
    SmartPointer<Comand>* comands;
    cout << "Введите название соревнования по хоккею" << endl;
    getline(cin, str);
    set_competitionName(str);
    cout << "Введите дату соревнований по хоккею." << endl;
    input_check_date(str);
    set_date(str);
    do {
        cout << "Введите число от 1 до 2, чтобы выбрать статус соревнования по футболу." << endl;
        cout << "1.Планируемое соренование" << endl;
        cout << "2.Проведённое соревнование" << endl;
        input_check_int(str);
        if (stoi(str) == 1) {
            set_competitionStatus("Планируемое");
        }
        else if (stoi(str) == 2) {
            set_competitionStatus("Проведённое");
        }
        else {
            cout << "Такого выбора не существует." << endl;
        }
    } while (stoi(str) > 2);
    cout << "Введите количество команд в соревновании по хоккею." << endl;
    do {
        input_check_int(str);
        if (stoi(str) < 2) {
            cout << "Количество команд должно быть не меньше двух." << endl;
        }
    } while (stoi(str) < 2);
    set_competitorCount(stoi(str));
    comands = new SmartPointer<Comand>[get_competitorCount()];
    for (int i = 0; i < get_competitorCount(); i++) {
        cout << "Введите навзвание " << i + 1 << " команды." << endl;
        getline(cin, str);
        comands[i] = SmartPointer<Comand>(new Comand(str));
    }
    set_comands(get_competitorCount(), comands);
    int* comandsPlaces = new int[get_competitorCount()], * comandsPointCount = new int[get_competitorCount()];
    if (get_competitionStatus() == "Планируемое") {
        for (int i = 0; i < get_competitorCount(); i++) {
            comandsPlaces[i] = 0;
            comandsPointCount[i] = 0;
        }
    }
    else {
        int j;
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                input_check_int(str);
                if (stoi(str) > get_competitorCount()) {
                    cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                    continue;
                }
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
            comandsPlaces[i] = stoi(str);
        }
        long size = sizeof(comandsPlaces) / (comandsPlaces[0]);
        /* quickSortAscending(comandsPlaces, comands, size);*/
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите количество очков " << " команды под названием '" << comands[i].operator->()->get_comandName() << "', находящейся на " << comandsPlaces[i] << "-ом месте." << endl;
                input_check_int(str);
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
        }
    }
    cout << "Введите количество голов в соревновании по хоккею." << endl;
    input_check_int(str);
    goalCount = stoi(str);
    cout << "Введите количество штрафных минут в соревновании по хоккею." << endl;
    input_check_int(str);
    penaltyMinutes= stoi(str);
}
void ChessCompetition::set_info() {
    string str = "";
    SmartPointer<Comand>* comands;
    cout << "Введите название соревнования по шахматам" << endl;
    getline(cin, str);
    set_competitionName(str);
    cout << "Введите дату соревнований по шахматам." << endl;
    input_check_date(str);
    set_date(str);
    do {
        cout << "Введите число от 1 до 2, чтобы выбрать статус соревнования по шахматам." << endl;
        cout << "1.Планируемое соренование" << endl;
        cout << "2.Проведённое соревнование" << endl;
        input_check_int(str);
        if (stoi(str) == 1) {
            set_competitionStatus("Планируемое");
        }
        else if (stoi(str) == 2) {
            set_competitionStatus("Проведённое");
        }
        else {
            cout << "Такого выбора не существует." << endl;
        }
    } while (stoi(str) > 2);
    cout << "Введите количество команд в соревновании по шахматам." << endl;
    do {
        input_check_int(str);
        if (stoi(str) < 2) {
            cout << "Количество команд должно быть не меньше двух." << endl;
        }
    } while (stoi(str) < 2);
    set_competitorCount(stoi(str));
    comands = new SmartPointer<Comand>[get_competitorCount()];
    for (int i = 0; i < get_competitorCount(); i++) {
        cout << "Введите навзвание " << i + 1 << " команды." << endl;
        getline(cin, str);
        comands[i] = SmartPointer<Comand>(new Comand(str));
    }
    set_comands(get_competitorCount(), comands);
    int* comandsPlaces = new int[get_competitorCount()], * comandsPointCount = new int[get_competitorCount()];
    if (get_competitionStatus() == "Планируемое") {
        for (int i = 0; i < get_competitorCount(); i++) {
            comandsPlaces[i] = 0;
            comandsPointCount[i] = 0;
        }
    }
    else {
        int j;
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                input_check_int(str);
                if (stoi(str) > get_competitorCount()) {
                    cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                    continue;
                }
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
            comandsPlaces[i] = stoi(str);
        }
        long size = sizeof(comandsPlaces) / (comandsPlaces[0]);
        /* quickSortAscending(comandsPlaces, comands, size);*/
        for (int i = 0; i < get_competitorCount(); i++) {
            do {
                cout << "Введите количество очков " << " команды под названием '" << comands[i].operator->()->get_comandName() << "', находящейся на " << comandsPlaces[i] << "-ом месте." << endl;
                input_check_int(str);
                for (j = 0;j < i;j++) {
                    if (stoi(str) == comandsPlaces[j]) {
                        cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                        break;
                    }
                }
            } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
        }
    }
    cout << "Введите количество побед в соревновании по шахматам." << endl;
    input_check_int(str);
    winCount= stoi(str);
    cout << "Введите количество ничьих в соревновании по шахматам." << endl;
    input_check_int(str);
    drawCount= stoi(str);
}
void FootballCompetition::get_info() {
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " <<setw(28)<<left<<"Количество красных карточек=" <<setw(4)<<left<<get_redCardCount()<<" | " << setw(18) <<left<< "Количество голов=" <<setw(4)<<left << get_goalCount() << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << "  | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << "  | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }   
        }
    }
    horizontalLine(206);
}
void BasketballCompetition::get_info() {
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество подборов=" << setw(4) << left << get_reboundCount() << " | " << setw(18) << left << "Количество очков=" << setw(4) << left << get_pointCount() << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            horizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            horizontalLine(147);
        }
    }
}
void VoleyballCompetition::get_info() {
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество блоков=" << setw(4) << left << get_blockCount() << " | " << setw(18) << left << "Количество очков=" << setw(4) << left << get_pointCount() << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            horizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            horizontalLine(147);
        }
    }
}
void HockeyCompetition::get_info() {
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество штрафных минут=" << setw(4) << left << get_penaltyMinutes() << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << get_goalCount() << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            horizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            horizontalLine(147);
        }
    }
} 
void ChessCompetition::get_info() {
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество ничьих=" << setw(4) << left << get_drawCount() << " | " << setw(18) << left << "Количество побед=" << setw(4) << left << get_winCount() << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            horizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                cout << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            horizontalLine(147);
        }
    }
}
void FootballCompetition::file() {
    ofstream out;
    out.open("competitions.txt", ios::out);
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << get_redCardCount() << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << get_goalCount() << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            FhorizontalLine(206);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|"  << endl;
            }
            FhorizontalLine(206);
        }
    }
    out.close();
}
void BasketballCompetition::file() {
    ofstream out;
    out.open("competitions.txt", ios::out);
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество подборов=" << setw(4) << left << get_reboundCount() << " | " << setw(18) << left << "Количество очков=" << setw(4) << left << get_pointCount() << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            FhorizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            FhorizontalLine(147);
        }
    }
    out.close();
}
void VoleyballCompetition::file() {
    ofstream out;
    out.open("competitions.txt", ios::out);
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество блоков=" << setw(4) << left << get_blockCount() << " | " << setw(18) << left << "Количество очков=" << setw(4) << left << get_pointCount() << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            FhorizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            FhorizontalLine(147);
        }
    }
    out.close();
}
void HockeyCompetition::file() {
    ofstream out;
    out.open("ompetitions.txt", ios::out);
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                cout << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество штрафных минут=" << setw(4) << left << get_penaltyMinutes() << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << get_goalCount() << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            FhorizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            FhorizontalLine(147);
        }
    }
    out.close();
}
void ChessCompetition::file() {
    ofstream out;
    out.open("ompetitions.txt", ios::out);
    for (int i = 0; i < get_competitorCount(); i++) {
        if (i == 0) {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "| " << setw(28) << left << "Количество ничьих=" << setw(4) << left << get_drawCount() << " | " << setw(18) << left << "Количество побед=" << setw(4) << left << get_winCount() << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << get_competitionName() << "| " << setw(18) << get_date() << "| " << setw(20) << get_competitionStatus() << "| " << setw(18) << left << get_competitorCount() << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "| " << setw(28) << left << "Количество красных карточек=" << setw(4) << left << "0" << " | " << setw(18) << left << "Количество голов=" << setw(4) << left << "0" << "|" << endl;
            }
            FhorizontalLine(147);
        }
        else {
            if (get_competitionStatus() == "Проведённое") {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << get_place(i + 1) << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            else {
                out << "|" << setw(40) << left << " " << "| " << setw(18) << " " << "| " << setw(20) << " " << "| " << setw(18) << left << " " << "| " << setw(24) << left << get_comand(i + 1) << "| " << setw(15) << left << "Не определено" << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << setw(28) << left << " " << setw(4) << left << " " << " | " << setw(18) << left << " " << setw(4) << left << " " << "|" << endl;
            }
            FhorizontalLine(147);
        }
    }
    out.close();
}
void FootballCompetition::edit_info() {
    string str = "";
    static int count;
    do {
        if (get_competitionStatus() == "Проведённое") {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по футболу." << endl;
            cout << "2.Изменить состав команд в соревновании по футболу" << endl;
            cout << "3.Изменить итоговые места команд в соревновании по футболу" << endl;
            cout << "4.Изменить количество голов" << endl;
            cout << "5.Изменить количество красных карточек" << endl;
            cout << "6.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по футболу" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по футболу, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по футболу." << endl;
                    cout << "2.Добавить команду в соревнование по футболу." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        int* places = new int[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i+1);
                        }

                        horizontalLine(48);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "| "<<setw(4)<<left<<i+1<<"|" << setw(40) << left << get_comand(i + 1) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                                places[i] = places[i + 1];
                                places[i]--;
                            }                        
                            set_comands(get_competitorCount() - 1, comands);
                            set_Places(get_competitorCount(), places);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        int* places = new int[get_competitorCount()+1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }
                        cout << "Введите название новой команды по футболу." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);
                        
                        do {
                            cout << "Введите место, которое заняла новая команда" << endl;
                            input_check_int(str);
                            if (stoi(str) > get_competitorCount() + 1) {
                                cout << "Команда не могла занять такое место" << endl;
                            }
                        } while (stoi(str) > get_competitorCount() + 1);
                        for (int i = stoi(str); i < get_competitorCount(); i++) {
                            places[i]++;
                        }
                        places[get_competitorCount()] = get_competitorCount();
                        set_comands(get_competitorCount() + 1, comands);
                        set_Places(get_competitorCount(), places);
                    }
                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                int* Places = new int[get_competitorCount()];
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];                
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                    Places[i] = get_place(i+1);

                }
                int j;
                for (int i = 1; i <=get_competitorCount(); i++) {
                    do {
                        cout << "Введите место, которое заняла команда под названием" << get_comand(i) << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Команда не могла занять такое место." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                              if (stoi(str) == Places[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == Places[j]);                   
                }
                int size = sizeof(Places) / (Places[0]);
                quickSortAscending(Places, comands, size);
                set_comands(get_competitorCount(), comands);
                set_Places(get_competitorCount(), Places);
            }
            else if (stoi(str) == 4) {
                cout << "Введите новое количество голов" << endl;
                input_check_int(str);
                set_goalCount(stoi(str));
            }
            else if (stoi(str) == 5) {
                cout << "Введите новое количество красных карточек" << endl;
                input_check_int(str);
                set_redCardCount(stoi(str));
            }
            else if (stoi(str) == 6) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
        else {
        cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
        cout << "1.Изменить название соревнования по футболу." << endl;
        cout << "2.Изменить состав команд в соревновании по футболу" << endl;
        cout << "3.Завершить соревнование по футболу" << endl;
        cout << "4.Выход в главное меню" << endl;
        input_check_int(str);
        if (stoi(str) == 1) {
            cout << "Введите новое название соревнования по футболу" << endl;
            getline(cin, str);
            set_competitionName(str);
        }
        else if (stoi(str) == 2) {
            do {
                cout << "Введите число 1, чтобы удалить команду из соревнования по футболу, или число 2, чтобы добавить новую команду" << endl;
                cout << "1.Удалить команду из соревнования по футболу." << endl;
                cout << "2.Добавить команду в соревнование по футболу." << endl;
                cout << "3.Выход" << endl;
                input_check_int(str);
                system("cls");
                if (stoi(str) == 1) {
                    SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                    for (int i = 0; i < get_competitorCount(); i++) {
                        comands[i].operator->()->set_comandName(get_comand(i + 1));
                    }
                    horizontalLine(42);
                    for (int i = 1; i <=get_competitorCount(); i++) {
                        cout << "|"<<setw(40)<<left<<get_comand(i)<< "|" << endl;
                    }
                    cout<<"Введите номер команды, которую хотите удалить из соревнования." << endl;
                    input_check_int(str);
                    if (stoi(str) > get_competitorCount()) {
                        cout<<"Данной команды не существует."<< endl;
                    }
                    else {
                        for (int i = stoi(str)-1; i < get_competitorCount()-1; i++) {
                            comands[i] = comands[i + 1];
                        }
                        set_comands(get_competitorCount() - 1, comands);
                    }
                }            
                else if(stoi(str)==2){
                    SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()+1];
                    for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                    }
                    cout <<"Введите название новой команды по футболу." << endl;
                    getline(cin, str);
                    comands[get_competitorCount()].operator->()->set_comandName(str);
                    set_comands(get_competitorCount()+1, comands);
                }
               
                else if (stoi(str) == 3) {
                    break;
                }
                else {
                    cout<<"Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                }
            } while (stoi(str)!=3);
        }
        else if (stoi(str) == 3) {
                    set_competitionStatus("Проведённое");
                    int j;
                    SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                    for (int i = 0; i < get_competitorCount(); i++) {
                        comands[i].operator->()->set_comandName(get_comand(i+1));
                    }
                    int* comandsPlaces = new int[get_competitorCount()];
                    for (int i = 0; i < get_competitorCount(); i++) {
                        do {
                            cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                            input_check_int(str);
                            if (stoi(str) > get_competitorCount()) {
                                cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                                continue;
                            }
                            for (j = 0;j < i;j++) {
                                if (stoi(str) == comandsPlaces[j]) {
                                    cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                    break;
                                }
                            }
                        } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
                        comandsPlaces[i] = stoi(str);
                    }
                    
                    int size = sizeof(comandsPlaces) / (comandsPlaces[0]);
                    quickSortAscending(comandsPlaces, comands, size);
                    set_Places(get_competitorCount(), comandsPlaces);
                    set_comands(get_competitorCount(), comands);
                    cout<<"Введите количество красных карточек" << endl;
                    input_check_int(str);
                    set_redCardCount(stoi(str));
                    cout<<"Введите количество голов" << endl;
                    input_check_int(str);
                    set_goalCount(stoi(str));
                }
        else if (stoi(str) == 4) {
        break;
        }
        else {
            cout<<"Такого выбора не существует. Попробуйте ещё раз." << endl;
        }
        } 
    } while ((get_competitionStatus()=="Проведённое"&&stoi(str)!=6)||(get_competitionStatus()!= "Проведённое"&&stoi(str)!=4));
}
void BasketballCompetition::edit_info() {
    string str = "";
    static int count;
    do {
        if (get_competitionStatus() == "Проведённое") {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по баскетболу." << endl;
            cout << "2.Изменить состав команд в соревновании по баскетболу" << endl;
            cout << "3.Изменить итоговые места команд в соревновании по баскетболу" << endl;
            cout << "4.Изменить количество подборов" << endl;
            cout << "5.Изменить количество очков" << endl;
            cout << "6.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по баскетболу" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по баскетболу, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по баскетболу." << endl;
                    cout << "2.Добавить команду в соревнование по баскетболу." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        int* places = new int[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }

                        horizontalLine(48);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "| " << setw(4) << left << i + 1 << "|" << setw(40) << left << get_comand(i + 1) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                                places[i] = places[i + 1];
                                places[i]--;
                            }
                            set_comands(get_competitorCount() - 1, comands);
                            set_Places(get_competitorCount(), places);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        int* places = new int[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }
                        cout << "Введите название новой команды по баскетболу." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);

                        do {
                            cout << "Введите место, которое заняла новая команда" << endl;
                            input_check_int(str);
                            if (stoi(str) > get_competitorCount() + 1) {
                                cout << "Команда не могла занять такое место" << endl;
                            }
                        } while (stoi(str) > get_competitorCount() + 1);
                        for (int i = stoi(str); i < get_competitorCount(); i++) {
                            places[i]++;
                        }
                        places[get_competitorCount()] = get_competitorCount();
                        set_comands(get_competitorCount() + 1, comands);
                        set_Places(get_competitorCount(), places);
                    }
                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                int* Places = new int[get_competitorCount()];
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                    Places[i] = get_place(i + 1);

                }
                int j;
                for (int i = 1; i <= get_competitorCount(); i++) {
                    do {
                        cout << "Введите место, которое заняла команда под названием" << get_comand(i) << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Команда не могла занять такое место." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == Places[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == Places[j]);
                }
                int size = sizeof(Places) / (Places[0]);
                quickSortAscending(Places, comands, size);
                set_comands(get_competitorCount(), comands);
                set_Places(get_competitorCount(), Places);
            }
            else if (stoi(str) == 4) {
                cout << "Введите новое количество подборов" << endl;
                input_check_int(str);
                set_reboundCount(stoi(str));
            }
            else if (stoi(str) == 5) {
                cout << "Введите новое количество очков" << endl;
                input_check_int(str);
                set_pointCount(stoi(str));
            }
            else if (stoi(str) == 6) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
        else {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по баскетболу." << endl;
            cout << "2.Изменить состав команд в соревновании по баскетболу" << endl;
            cout << "3.Завершить соревнование по баскетболу" << endl;
            cout << "4.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по баскетболу" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по баскетболу, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по баскетболу." << endl;
                    cout << "2.Добавить команду в соревнование по баскетболу." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        horizontalLine(42);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "|" << setw(40) << left << get_comand(i) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                            }
                            set_comands(get_competitorCount() - 1, comands);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        cout << "Введите название новой команды по баскетболу." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);
                        set_comands(get_competitorCount() + 1, comands);
                    }

                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                set_competitionStatus("Проведённое");
                int j;
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                }
                int* comandsPlaces = new int[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    do {
                        cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == comandsPlaces[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
                    comandsPlaces[i] = stoi(str);
                }

                int size = sizeof(comandsPlaces) / (comandsPlaces[0]);
                quickSortAscending(comandsPlaces, comands, size);
                set_Places(get_competitorCount(), comandsPlaces);
                set_comands(get_competitorCount(), comands);
                cout << "Введите количество подборов" << endl;
                input_check_int(str);
                set_reboundCount(stoi(str));
                cout << "Введите количество очков" << endl;
                input_check_int(str);
                set_pointCount(stoi(str));
            }
            else if (stoi(str) == 4) { 
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
    } while ((get_competitionStatus() == "Проведённое" && stoi(str) != 6) || (get_competitionStatus() != "Проведённое" && stoi(str) != 4));
}
void VoleyballCompetition::edit_info() {
    string str = "";
    static int count;
    do {
        if (get_competitionStatus() == "Проведённое") {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по волейболу." << endl;
            cout << "2.Изменить состав команд в соревновании по волейболу" << endl;
            cout << "3.Изменить итоговые места команд в соревновании по волейболу" << endl;
            cout << "4.Изменить количество блоков" << endl;
            cout << "5.Изменить количество очков" << endl;
            cout << "6.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по волейболу" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по волейболу, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по волейболу." << endl;
                    cout << "2.Добавить команду в соревнование по волейболу." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        int* places = new int[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }

                        horizontalLine(48);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "| " << setw(4) << left << i + 1 << "|" << setw(40) << left << get_comand(i + 1) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                                places[i] = places[i + 1];
                                places[i]--;
                            }
                            set_comands(get_competitorCount() - 1, comands);
                            set_Places(get_competitorCount(), places);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        int* places = new int[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }
                        cout << "Введите название новой команды по волейболу." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);

                        do {
                            cout << "Введите место, которое заняла новая команда" << endl;
                            input_check_int(str);
                            if (stoi(str) > get_competitorCount() + 1) {
                                cout << "Команда не могла занять такое место" << endl;
                            }
                        } while (stoi(str) > get_competitorCount() + 1);
                        for (int i = stoi(str); i < get_competitorCount(); i++) {
                            places[i]++;
                        }
                        places[get_competitorCount()] = get_competitorCount();
                        set_comands(get_competitorCount() + 1, comands);
                        set_Places(get_competitorCount(), places);
                    }
                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                int* Places = new int[get_competitorCount()];
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                    Places[i] = get_place(i + 1);

                }
                int j;
                for (int i = 1; i <= get_competitorCount(); i++) {
                    do {
                        cout << "Введите место, которое заняла команда под названием" << get_comand(i) << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Команда не могла занять такое место." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == Places[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == Places[j]);
                }
                int size = sizeof(Places) / (Places[0]);
                quickSortAscending(Places, comands, size);
                set_comands(get_competitorCount(), comands);
                set_Places(get_competitorCount(), Places);
            }
            else if (stoi(str) == 4) {
                cout << "Введите новое количество блоков" << endl;
                input_check_int(str);
                set_blockCount(stoi(str));
            }
            else if (stoi(str) == 5) {
                cout << "Введите новое количество очков" << endl;
                input_check_int(str);
                set_pointCount(stoi(str));
            }
            else if (stoi(str) == 6) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
        else {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по волейболу." << endl;
            cout << "2.Изменить состав команд в соревновании по волейболу" << endl;
            cout << "3.Завершить соревнование по волейболу" << endl;
            cout << "4.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по волейболу" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по волейболу, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по волейболу." << endl;
                    cout << "2.Добавить команду в соревнование по волейболу." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        horizontalLine(42);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "|" << setw(40) << left << get_comand(i) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                            }
                            set_comands(get_competitorCount() - 1, comands);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        cout << "Введите название новой команды по волейболу." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);
                        set_comands(get_competitorCount() + 1, comands);
                    }

                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                set_competitionStatus("Проведённое");
                int j;
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                }
                int* comandsPlaces = new int[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    do {
                        cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == comandsPlaces[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
                    comandsPlaces[i] = stoi(str);
                }

                int size = sizeof(comandsPlaces) / (comandsPlaces[0]);
                quickSortAscending(comandsPlaces, comands, size);
                set_Places(get_competitorCount(), comandsPlaces);
                set_comands(get_competitorCount(), comands);
                cout << "Введите количество блоков" << endl;
                input_check_int(str);
                set_blockCount(stoi(str));
                cout << "Введите количество очков" << endl;
                input_check_int(str);
                set_pointCount(stoi(str));
            }
            else if (stoi(str) == 4) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
    } while ((get_competitionStatus() == "Проведённое" && stoi(str) != 6) || (get_competitionStatus() != "Проведённое" && stoi(str) != 4));

}
void HockeyCompetition::edit_info() {
    string str = "";
    static int count;
    do {
        if (get_competitionStatus() == "Проведённое") {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по хоккею." << endl;
            cout << "2.Изменить состав команд в соревновании по хоккею" << endl;
            cout << "3.Изменить итоговые места команд в соревновании по хоккею" << endl;
            cout << "4.Изменить количество штрафных минут" << endl;
            cout << "5.Изменить количество голов" << endl;
            cout << "6.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по хоккею" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по хоккею, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по хоккею." << endl;
                    cout << "2.Добавить команду в соревнование по хоккею." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        int* places = new int[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }

                        horizontalLine(48);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "| " << setw(4) << left << i + 1 << "|" << setw(40) << left << get_comand(i + 1) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                                places[i] = places[i + 1];
                                places[i]--;
                            }
                            set_comands(get_competitorCount() - 1, comands);
                            set_Places(get_competitorCount(), places);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        int* places = new int[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }
                        cout << "Введите название новой команды по хоккею." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);

                        do {
                            cout << "Введите место, которое заняла новая команда" << endl;
                            input_check_int(str);
                            if (stoi(str) > get_competitorCount() + 1) {
                                cout << "Команда не могла занять такое место" << endl;
                            }
                        } while (stoi(str) > get_competitorCount() + 1);
                        for (int i = stoi(str); i < get_competitorCount(); i++) {
                            places[i]++;
                        }
                        places[get_competitorCount()] = get_competitorCount();
                        set_comands(get_competitorCount() + 1, comands);
                        set_Places(get_competitorCount(), places);
                    }
                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                int* Places = new int[get_competitorCount()];
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                    Places[i] = get_place(i + 1);

                }
                int j;
                for (int i = 1; i <= get_competitorCount(); i++) {
                    do {
                        cout << "Введите место, которое заняла команда под названием" << get_comand(i) << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Команда не могла занять такое место." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == Places[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == Places[j]);
                }
                int size = sizeof(Places) / (Places[0]);
                quickSortAscending(Places, comands, size);
                set_comands(get_competitorCount(), comands);
                set_Places(get_competitorCount(), Places);
            }
            else if (stoi(str) == 4) {
                cout << "Введите новое количество штрафных минут" << endl;
                input_check_int(str);
                set_penaltyMinutes(stoi(str));
            }
            else if (stoi(str) == 5) {
                cout << "Введите новое количество голов" << endl;
                input_check_int(str);
                set_goalCount(stoi(str));
            }
            else if (stoi(str) == 6) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
        else {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по хоккею." << endl;
            cout << "2.Изменить состав команд в соревновании по хоккею" << endl;
            cout << "3.Завершить соревнование по хоккею" << endl;
            cout << "4.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по хоккею" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по хоккею, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по хоккею." << endl;
                    cout << "2.Добавить команду в соревнование по хоккею." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        horizontalLine(42);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "|" << setw(40) << left << get_comand(i) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                            }
                            set_comands(get_competitorCount() - 1, comands);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        cout << "Введите название новой команды по хоккею." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);
                        set_comands(get_competitorCount() + 1, comands);
                    }

                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                set_competitionStatus("Проведённое");
                int j;
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                }
                int* comandsPlaces = new int[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    do {
                        cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == comandsPlaces[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
                    comandsPlaces[i] = stoi(str);
                }

                int size = sizeof(comandsPlaces) / (comandsPlaces[0]);
                quickSortAscending(comandsPlaces, comands, size);
                set_Places(get_competitorCount(), comandsPlaces);
                set_comands(get_competitorCount(), comands);
                cout << "Введите количество штрафных минут" << endl;
                input_check_int(str);
                set_penaltyMinutes(stoi(str));
                cout << "Введите количество голов" << endl;
                input_check_int(str);
                set_goalCount(stoi(str));
            }
            else if (stoi(str) == 4) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
    } while ((get_competitionStatus() == "Проведённое" && stoi(str) != 6) || (get_competitionStatus() != "Проведённое" && stoi(str) != 4));

}
void ChessCompetition::edit_info() {
    string str = "";
    static int count;
    do {
        if (get_competitionStatus() == "Проведённое") {
            cout << "Введите число от 1 до , чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по шахматам." << endl;
            cout << "2.Изменить состав команд в соревновании по шахматам" << endl;
            cout << "3.Изменить итоговые места команд в соревновании по шахматам" << endl;
            cout << "4.Изменить количество ничьих" << endl;
            cout << "5.Изменить количество побед" << endl;
            cout << "6.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по шахматам" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по шахматам, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по шахматам." << endl;
                    cout << "2.Добавить команду в соревнование по шахматам." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        int* places = new int[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }

                        horizontalLine(48);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "| " << setw(4) << left << i + 1 << "|" << setw(40) << left << get_comand(i + 1) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                                places[i] = places[i + 1];
                                places[i]--;
                            }
                            set_comands(get_competitorCount() - 1, comands);
                            set_Places(get_competitorCount(), places);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        int* places = new int[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                            places[i] = get_place(i + 1);
                        }
                        cout << "Введите название новой команды по шахматам." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);

                        do {
                            cout << "Введите место, которое заняла новая команда" << endl;
                            input_check_int(str);
                            if (stoi(str) > get_competitorCount() + 1) {
                                cout << "Команда не могла занять такое место" << endl;
                            }
                        } while (stoi(str) > get_competitorCount() + 1);
                        for (int i = stoi(str); i < get_competitorCount(); i++) {
                            places[i]++;
                        }
                        places[get_competitorCount()] = get_competitorCount();
                        set_comands(get_competitorCount() + 1, comands);
                        set_Places(get_competitorCount(), places);
                    }
                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                int* Places = new int[get_competitorCount()];
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                    Places[i] = get_place(i + 1);

                }
                int j;
                for (int i = 1; i <= get_competitorCount(); i++) {
                    do {
                        cout << "Введите место, которое заняла команда под названием" << get_comand(i) << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Команда не могла занять такое место." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == Places[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == Places[j]);
                }
                int size = sizeof(Places) / (Places[0]);
                quickSortAscending(Places, comands, size);
                set_comands(get_competitorCount(), comands);
                set_Places(get_competitorCount(), Places);
            }
            else if (stoi(str) == 4) {
                cout << "Введите новое количество ничьих" << endl;
                input_check_int(str);
                set_drawCount(stoi(str));
            }
            else if (stoi(str) == 5) {
                cout << "Введите новое количество побед" << endl;
                input_check_int(str);
                set_winCount(stoi(str));
            }
            else if (stoi(str) == 6) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
        else {
            cout << "Введите число от 1 до 3, чтобы изменить необходимую информацию." << endl;
            cout << "1.Изменить название соревнования по шахматам." << endl;
            cout << "2.Изменить состав команд в соревновании по шахматам" << endl;
            cout << "3.Завершить соревнование по шахматам" << endl;
            cout << "4.Выход в главное меню" << endl;
            input_check_int(str);
            if (stoi(str) == 1) {
                cout << "Введите новое название соревнования по шахматам" << endl;
                getline(cin, str);
                set_competitionName(str);
            }
            else if (stoi(str) == 2) {
                do {
                    cout << "Введите число 1, чтобы удалить команду из соревнования по шахматам, или число 2, чтобы добавить новую команду" << endl;
                    cout << "1.Удалить команду из соревнования по шахматам." << endl;
                    cout << "2.Добавить команду в соревнование по шахматам." << endl;
                    cout << "3.Выход" << endl;
                    input_check_int(str);
                    system("cls");
                    if (stoi(str) == 1) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        horizontalLine(42);
                        for (int i = 1; i <= get_competitorCount(); i++) {
                            cout << "|" << setw(40) << left << get_comand(i) << "|" << endl;
                        }
                        cout << "Введите номер команды, которую хотите удалить из соревнования." << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Данной команды не существует." << endl;
                        }
                        else {
                            for (int i = stoi(str) - 1; i < get_competitorCount() - 1; i++) {
                                comands[i] = comands[i + 1];
                            }
                            set_comands(get_competitorCount() - 1, comands);
                        }
                    }
                    else if (stoi(str) == 2) {
                        SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount() + 1];
                        for (int i = 0; i < get_competitorCount(); i++) {
                            comands[i].operator->()->set_comandName(get_comand(i + 1));
                        }
                        cout << "Введите название новой команды по шахматам." << endl;
                        getline(cin, str);
                        comands[get_competitorCount()].operator->()->set_comandName(str);
                        set_comands(get_competitorCount() + 1, comands);
                    }

                    else if (stoi(str) == 3) {
                        break;
                    }
                    else {
                        cout << "Такого выбора не существует. Попробуйте ввести ещё раз." << endl;
                    }
                } while (stoi(str) != 3);
            }
            else if (stoi(str) == 3) {
                set_competitionStatus("Проведённое");
                int j;
                SmartPointer<Comand>* comands = new SmartPointer<Comand>[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    comands[i].operator->()->set_comandName(get_comand(i + 1));
                }
                int* comandsPlaces = new int[get_competitorCount()];
                for (int i = 0; i < get_competitorCount(); i++) {
                    do {
                        cout << "Введите место " << i + 1 << " команды под названием '" << comands[i].operator->()->get_comandName() << "'" << endl;
                        input_check_int(str);
                        if (stoi(str) > get_competitorCount()) {
                            cout << "Такого места в данных соревнованиях не предусмотрено. Попробуйте ещё раз." << endl;
                            continue;
                        }
                        for (j = 0;j < i;j++) {
                            if (stoi(str) == comandsPlaces[j]) {
                                cout << "Не может две и более команды занимать одно и то же место. Попробуйте ещё раз." << endl;
                                break;
                            }
                        }
                    } while (stoi(str) > get_competitorCount() || stoi(str) == comandsPlaces[j]);
                    comandsPlaces[i] = stoi(str);
                }

                int size = sizeof(comandsPlaces) / (comandsPlaces[0]);
                quickSortAscending(comandsPlaces, comands, size);
                set_Places(get_competitorCount(), comandsPlaces);
                set_comands(get_competitorCount(), comands);
                cout << "Введите количество ничьих" << endl;
                input_check_int(str);
                set_drawCount(stoi(str));
                cout << "Введите количество побед" << endl;
                input_check_int(str);
                set_winCount(stoi(str));
            }
            else if (stoi(str) == 4) {
                break;
            }
            else {
                cout << "Такого выбора не существует. Попробуйте ещё раз." << endl;
            }
        }
    } while ((get_competitionStatus() == "Проведённое" && stoi(str) != 6) || (get_competitionStatus() != "Проведённое" && stoi(str) != 4));

}