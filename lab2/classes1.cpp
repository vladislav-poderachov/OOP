#include"Header1.h"
template<class F>
SmartPointer<F>::SmartPointer() {
	smartPtr = NULL;
	cout <<"Сработал конструктор " << endl;
}
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

F&SmartPointer<F>:: operator[](int index) const
{
	if (smartPtr)
	{
		return smartPtr->ptr[index];
	}
}
template<class F>
SmartPointer<F>::~SmartPointer() {
	if (smartPtr) 
	{
		smartPtr->counter--;
		if (smartPtr->counter == 0) {
			delete[] smartPtr->ptr;
			delete smartPtr;
		}
	}
}
template<class F>	
SmartPointer<F>&SmartPointer<F>::operator=(const SmartPointer& obj) {
	if (smartPtr) {
		smartPtr->counter--;
		if (smartPtr->counter == 0) {
			delete[] smartPtr->ptr;
			delete smartPtr;
		}
	}
	smartPtr = obj.smartPtr;
	if (smartPtr) {
		smartPtr->counter++;
	}
	return *this;
}

template<class F>
F* SmartPointer<F>::operator->() const {
	if (smartPtr) {
		return smartPtr->ptr;
	}
	else {
		return NULL;
	}
}	
template<class F>
void SmartPointer<F>:: ShowCounter(){
	cout << "Значение счётчика равно для объекта" << smartPtr << " равно " << smartPtr->counter << endl;
	}
template<class F>
SmartPointer<F>::SmartPointer(const SmartPointer& obj):smartPtr(obj.smartPtr) {
	if (smartPtr) {
		smartPtr->counter++;
	}
}
template<class F>
Transaction<F>::Transaction():prevState(NULL), currentState(new F) {
}
template<class F>
Transaction<F>::Transaction(F *currentState) {
	prevState = NULL;
	this->currentState = currentState;
}
template<class F>
Transaction<F>& Transaction<F>::operator=(const Transaction<F>& obj) {
	if (this != &obj) {
		delete currentState;
		currentState = new F(*(obj.currentState));
	}
	return *this;
}

template<class F>
void Transaction<F>::commit() {
	delete prevState;
	prevState = NULL;
}
template<class F>
void Transaction<F>::deleteTransactions() {
	delete prevState;
	prevState = NULL;
}
template<class F>
Transaction<F>::Transaction(const Transaction& obj):currentState(new F*(obj.currentState)), prevState(NULL) {
}
template<class F>
void Transaction<F>::beginTransactions(int day, int	month, int year) {
	delete prevState;
	prevState = currentState;
	currentState = new F(*prevState);	
	if (!currentState) {
		return 0;
	}
	currentState->set_day(day);
	currentState->set_month(month);
	currentState->set_year(year);//продолжить делать под свою программу
	return 1;
}
template<class F>
void Transaction<F>::beginTransactions(string competitionName) {
	delete prevState;
	prevState = currentState;
	currentState = new F(*prevState);
	if (!currentState) {
		return 0;
	}
	currentState->set_competitionName(competitionName);//продолжить делать под свою программу
	return 1;
}
template<class F>
Transaction<	F>::~Transaction() {
	delete[] currentState;
	delete[] prevState;	
}
template<class F>
F* Transaction<F>::operator->() const{
	return	 currentState;
}
template<class F>
F& Transaction<F>::operator[](int index)const {
    if (currentState) {
        return currentState[index];
    }
}
template<class F>
void Transaction<F>::showState(State state) {
	cout << "Состояние объекта" << endl;
	if (!state)
	{
		cout << "до начала транзакции " << endl;
	}
	else {
		cout << "после выполнения транзакции " << endl;
	}
	if (prevState) { 
		cout << "prevState = " << prevState->getNumber() << endl; 
	}
	else {
		cout << "prevState = NULL" << endl;
		cout << "currentState = " << currentState->getNumber() << endl;
	}
}
Comand::Comand() {
	comandName = "no name";
	pointCount = 0;
		place = 0;
}
void Comand::set_comandName(string comandName) {
	this->comandName = comandName;
}
string Comand::get_comandName() {
	return comandName;
}
Comand::Comand(string comandName, int pointCount, int place) {
	this->comandName = comandName;
	this->pointCount = pointCount;
	this->place = place;
}
Comand::~Comand() {
}
void Comand::set_place(int place) {
	this->place = place;
}
void Comand::set_pointCount(int pointCount) {
	this->pointCount = pointCount;
}
int Comand::get_pointCount() {
	return pointCount;
}
int Comand::get_place() {
	return place;
}
Competition::Competition() {
	day = 0;
	month = 0;
	year = 0;
	competitorCount = 10;
	comands = new SmartPointer<Comand>*[competitorCount];
}
Competition::Competition(int day, int month, int year, int competitorCount, SmartPointer<Comand> **comands) {
	this->day =day;
	this->month = month;
	this->year = year;
	this->competitorCount =competitorCount ;
	this->comands = new SmartPointer<Comand>*[competitorCount];
	for (int i = 0; i < competitorCount;i++) {
		this->comands[i] =comands[i];
	}
}
Competition::Competition(const Competition& obj) {
	this->comands = new SmartPointer<Comand>*[competitorCount];
	for (int i = 0; i < competitorCount; i++) {
		this->comands[i] = obj.comands[i];
	}
	}
Competition::~Competition() {
	delete[] comands;
}
void Competition::set_date(string str) {
	string day, month, year;
	int counter=0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '.') {
			if (counter == 0) {
				day += str[i];
			}
			else if (counter == 1) {
				month += str[i];
			}
			else if (counter == 2) {
				year += str[i];
			}
		}
		else {
			counter++;
		}
	}
	this->day = stoi(day);
	this->month = stoi(month);
	this->year = stoi(year);
}
void Competition::set_comands(int CompetitorCount, SmartPointer<Comand> **comands) {
	this->competitorCount = CompetitorCount;
	this->comands = new SmartPointer<Comand>*[CompetitorCount];
		for (int i = 0; i < competitorCount; i++){
			this->comands[i] = comands[i];
		}	
}
void Competition::file() {
}
string Competition::get_comand(int position) {
		return (*comands[position-1])->get_comandName();
}
int Competition:: get_competitorCount(){
	return competitorCount;
}
void Competition::set_competitorCount(int competitorCount){
	this->competitorCount = competitorCount;
}
string Competition::get_date() {
	string date;
	date += to_string(day);
	date += ".";
	date += to_string(month);
	date += ".";
	date += to_string(year);
	return date;
}
int Competition::get_day() {
	return day;
}
int Competition::get_year() {
	return year;
}
int Competition::get_month() {
	return month;
}
void Competition::set_day(int day) {
	this->day=day;
}
void Competition::set_month(int day) {
	this->month = month;
}
void Competition::set_year(int year) {
	this->year = year;
}
void Competition::set_competitionName(string competitionName){
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

int FootballCompetition::get_goalCount(){
	return goalCount;
}
void FootballCompetition::set_goalCount(int goalCount) {
	this->goalCount=goalCount;
}
void FootballCompetition::set_redCardCount(int redCardCount) {
	this->redCardCount = redCardCount;
}
void FootballCompetition::file() {
	ofstream out;
	out.open("football_competititons.txt", ios::app);
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out<< endl<<"|"<<setw(15)<<left<<"Вид спорта"<<"|"<<setw(30)<<left<<"Название соревнований"<<"|"<<setw(15)<<left<<"Дата проведения"<<"|"<<setw(24)<<left<<"Количество команд"<<"|"<<setw(30)<<left<<"Команды"<<"|"<<setw(30)<<left<<"Количество красных карточек"<<"|"<<setw(30)<<left<<"Количество голов"<<"|";
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl;
	for (int j = 1; j <= get_competitorCount(); j++) {
		if (j == 1) {
			out << "|" << setw(15) << left << "Футбол" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" <<setw(30)<<left<<get_redCardCount()<<"|"<<setw(30)<<left<<get_goalCount()<<"|" << endl;;
		}
		else {
			out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
		}
	}
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out.close();
}
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
void BasketballCompetition::file() {
	ofstream out;
	out.open("basketball_competititons.txt", ios::app);
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество подборов" << "|" << setw(30) << left << "Количество очков" << "|";
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl;
	for (int j = 1; j <= get_competitorCount(); j++) {
		if (j == 1) {
			out << "|" << setw(15) << left << "Баскетбол" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_reboundCount() << "|" << setw(30) << left << get_pointCount() << "|" << endl;
		}
		else {
			out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30)<<left<<"" << "|" << setw(30)<<left<<"" << "|" << endl;
		}
	}
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out.close();
}
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
void VoleyballCompetition::file() {
	ofstream out;
	out.open("basketball_competititons.txt", ios::app);
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество блоков" << "|" << setw(30) << left << "Количество очков" << "|";
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl;
	for (int j = 1; j <= get_competitorCount(); j++) {
		if (j == 1) {
			out << "|" << setw(15) << left << "Волейбол" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_blockCount() << "|" << setw(30) << left << get_pointCount() << "|" << endl;;
		}
		else {
			out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
		}
	}
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out.close();
}
void HockeyCompetition::file() {
	ofstream out;
	out.open("hockey_competititons.txt", ios::app);
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество штрафных минут" << "|" << setw(30) << left << "Количество голов" << "|";
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl;
	for (int j = 1; j <= get_competitorCount(); j++) {
		if (j == 1) {
			out << "|" << setw(15) << left << "Хоккей" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_penaltyMinutes() << "|" << setw(30) << left << get_goalCount() << "|" << endl;;
		}
		else {
			out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
		}
	}
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out.close();
}
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
void ChessCompetition::file() {
	ofstream out;
	out.open("chess_competititons.txt", ios::app);
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl << "|" << setw(15) << left << "Вид спорта" << "|" << setw(30) << left << "Название соревнований" << "|" << setw(15) << left << "Дата проведения" << "|" << setw(24) << left << "Количество команд" << "|" << setw(30) << left << "Команды" << "|" << setw(30) << left << "Количество ничьих" << "|" << setw(30) << left << "Количество побед" << "|";
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out << endl;
	for (int j = 1; j <= get_competitorCount(); j++) {
		if (j == 1) {
			out << "|" << setw(15) << left << "Шахматы" << "|" << setw(30) << left << get_competitionName() << "|" << setw(15) << left << get_date() << "|" << setw(24) << left << get_competitorCount() << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << get_drawCount() << "|" << setw(30) << left << get_winCount() << "|" << endl;;
		}
		else {
			out << "|" << setw(15) << left << "" << "|" << setw(30) << left << "" << "|" << setw(15) << left << "" << "|" << setw(24) << left << "" << "|" << setw(30) << left << get_comand(j) << "|" << setw(30) << left << "" << "|" << setw(30) << left << "" << "|" << endl;
		}
	}
	for (int i = 0; i < 182; i++) {
		out << "-";
	}
	out.close();
}