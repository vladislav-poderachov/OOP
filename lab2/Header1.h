#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include <iomanip>
using namespace std;
enum State{begin,  middle};
template <class F>
struct Status {
	F* ptr;
	int counter;
};
template <class F>
class SmartPointer {
	Status<F>* smartPtr;
public:
	SmartPointer();
	SmartPointer(F* ptr);
	SmartPointer(const SmartPointer& obj);
	~SmartPointer();
	SmartPointer& operator=(const SmartPointer& obj);
	F* operator->()const;
	F& operator[](int index)const;
	void ShowCounter();
};
template <class F>
class Transaction {
	F* currentState;
	F* prevState;
public:
	Transaction();
	Transaction(F *currentState);
	Transaction(const Transaction& obj);
	~Transaction();
	Transaction& operator=(const Transaction& obj);
	void showState(State state);
	void commit();
	void beginTransactions(int day, int month, int year);
	void beginTransactions(string competitionName);
	void deleteTransactions();
    F& operator[](int index)const;
	F* operator->() const;

};
class Comand {
	string comandName;
	int pointCount;
	int place;
public:
	Comand();
	Comand(string comandName, int pointCount, int place);
	~Comand();
	void set_comandName(string comandName);
	string get_comandName();
	void set_pointCount(int pointCount);
	int get_pointCount();
	void set_place(int place);
	int get_place();
};
class Competition {
	string competitionName;
	int day;
	int month;
	int year;
	int competitorCount;
	SmartPointer<Comand> comands;
public:
	Competition();
	Competition(int day, int month, int year, int competitorCount, SmartPointer<Comand> comands);
	Competition(const Competition& obj);
	~Competition();
	void set_competitionName(string competitionName);
	string get_competitionName();
	void set_day(int day);
	void set_month(int month);
	void set_year(int year);
	void set_date(string date);
	int get_day();
	int get_month();
	int get_year();
	string get_date();
	void set_competitorCount(int competitorCount);
	int get_competitorCount();
	void set_comands(int CompetitorCount, SmartPointer<Comand> comands);
	string get_comand(int position);
	virtual void file();
};
class FootballCompetition : public Competition {
	int goalCount;
	int redCardCount;
public:
	FootballCompetition();
	FootballCompetition(int goalsCount, int redCardCount);
	~FootballCompetition();
	void set_goalCount(int goalCount);
	int get_goalCount();
	void set_redCardCount(int redCardCount);
	int get_redCardCount();
	virtual void file();
};
class BasketballCompetition : public Competition {
	int pointCount;
	int reboundCount;
public:
	BasketballCompetition();
	BasketballCompetition(int pointCount, int reboundCount);
	~BasketballCompetition();
	void set_pointCount(int pointCount);
	int get_pointCount();
	void set_reboundCount(int reboundCount);
	int get_reboundCount();
	virtual void file();
};
class VoleyballCompetition : public Competition {
	int pointCount;
	int blockCount;
public:
	VoleyballCompetition();
	VoleyballCompetition(int pointCount, int blockCount);
	~VoleyballCompetition();
	void set_pointCount(int pointCount);
	void set_blockCount(int blockCount);
	int get_pointCount();
	int get_blockCount();
	virtual void file();
};
class ChessCompetition : public Competition {
	int winCount;
	int drawCount;
public:
	ChessCompetition();
	ChessCompetition(int winCount, int drawCount);
	~ChessCompetition();
	void set_winCount(int winCount);
	int get_winCount();
	void set_drawCount(int drawCount);
	int get_drawCount();
	virtual void file();
};
class HockeyCompetition : public Competition {
	int goalCount;
	int penaltyMinutes;
public:
	HockeyCompetition();
	HockeyCompetition(int goalCount, int penaltyMinutes);
	~HockeyCompetition();
	void set_goalCount(int goalCount);
	int get_goalCount();
	void set_penaltyMinutes(int penalyMinutes);
	int get_penaltyMinutes();
	virtual void file();
};
void input_check_int(string& str);
string input_check_string();
void input_check_date(string& str);