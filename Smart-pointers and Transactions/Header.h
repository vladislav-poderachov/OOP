#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include <iomanip>
using namespace std;
void input_check_int(string& str);
string input_check_string();
void input_check_date(string& str);
void horizontalLine(int linelength);
void FhorizontalLine(int linelength);
template <class F>
struct Status {
    F* ptr;
    int counter;
};
template <class F>
class SmartPointer {
    Status<F>* smartPtr;
    int smartPtrCount;
public:
    SmartPointer();
    SmartPointer(F*ptr);
    SmartPointer(const SmartPointer& obj);
    ~SmartPointer();
    SmartPointer& operator=(const SmartPointer& obj) {
        if (smartPtr) {
            smartPtr->counter--;
            if (smartPtr->counter == 0) {
                delete smartPtr->ptr;
                delete smartPtr;
            }
        }
        smartPtr = obj.smartPtr;
        if (smartPtr) {
            smartPtr->counter++;
        }
        return *this;
    }
    F* operator->()const {
        if (smartPtr) {
            return smartPtr->ptr;
        }
        else {
            return NULL;
        }
    }
    void ShowCounter();
};
template <class F>
class Transaction {
    F* currentState;
    F* prevState;
public:
    Transaction();
    Transaction(F* currentState) {
        prevState = NULL;
        this->currentState = currentState;
    }
    Transaction(const Transaction& obj);
    ~Transaction() {
        delete currentState;
        delete prevState;
    };
    Transaction& operator=(const Transaction& obj) {
        if (this != &obj) {
            delete currentState;
            currentState = new F(*(obj.currentState));
        }
        return *this;
    }
    void commit();
    int beginTransactions(string date) {
        delete prevState;
        prevState = currentState;
        currentState = new F(*prevState);
        if (!currentState) {
            return 0;
        }
        currentState->set_date(date);//продолжить делать под свою программу
        return 1;
    }
    void deleteTransactions(){
    if (prevState != NULL) {
        delete currentState;
        currentState = prevState;
        prevState = NULL;
    }
}
    F* operator->()const {
        return currentState;
    }

};
class Comand {
    string comandName;
public:
    Comand();
    Comand(string comandName);
    void set_comandName(string comandName);
    string get_comandName();
};
class Competition {
    string competitionName;
    string date;
    string competitionsStatus;
    int competitorCount;
    SmartPointer<Comand> *comands;
    int *comandPoints;
    int *comandPlaces;
public:
    Competition();
    Competition(string competitionName, string date, int competitorCount, SmartPointer<Comand>* comands, int* comandPoints, int *comandPlaces);
    Competition(const Competition& obj);
    ~Competition();
    void set_competitionName(string competitionName);
    string get_competitionName();
    void set_date(string date);
    string get_date();
    void set_Places(int CompetitorCount, int *Places);
    void set_competitorCount(int competitorCount);
    int get_competitorCount();
    void set_comands(int CompetitorCount, SmartPointer<Comand> *comands);
    string get_comand(int position);
    SmartPointer<Comand>* get_comands();
    int get_place(int position);
    virtual void set_info(){};
    virtual void get_info(){}
    virtual void file();
    virtual void edit_info(){}
    void set_competitionStatus(string str);
    string get_competitionStatus();
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
    virtual void edit_info();
    virtual void set_info();
    virtual void get_info();
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
    virtual void edit_info();
    virtual void set_info();
    virtual void get_info();
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
    virtual void edit_info();
    virtual void set_info();
    virtual void get_info();
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
    virtual void edit_info();
    virtual void set_info();
    virtual void get_info();
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
    virtual void edit_info();
    virtual void get_info();    
    virtual void set_info();
};
template<class F>
void quickSortAscending(int* array, SmartPointer<F>* comands, int N) {
    if (N <= 1) {
        return; // Base case: already sorted or empty array
    }

    int pivot = array[N / 2]; // Choose pivot element

    // Partition the array into two halves
    int i = 0, j = N - 1;
    while (i <= j) {
        while (array[i] < pivot) {
            i++;
        }
        while (array[j] > pivot) {
            j--;
        }
        if (i <= j) {
            swap(array[i], array[j]);
            SmartPointer<F> t = comands[i];
            comands[i] = comands[j];
            comands[j] = t;
            i++;
            j--;
        }
    }
    // Recursively sort the subarrays
    if (j > 0) {
        quickSortAscending(array, comands, j + 1);
    }
    if (N > i) {
        quickSortAscending(array + i, comands + i, N - i);
    }
}