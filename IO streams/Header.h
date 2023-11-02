#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include <iomanip>
using namespace std;
class TrainingEquipment {
protected:
    string equipmentname;
public:
    TrainingEquipment();
    TrainingEquipment(string equipmentname);
    ~TrainingEquipment();
    void set_equipmentname(string equipmentname);
    virtual string get_equipmentname();
};
class Grip :public TrainingEquipment {
    int mass;
public:
    Grip();
    Grip(int mass);
    ~Grip();
    void set_mass(int mass);
    int get_mass();
    virtual string get_equipmentname();
};
class WeightPlate :public TrainingEquipment {
    int mass;
    float size;
public:
    WeightPlate();
    WeightPlate(int mass, float size);
    ~WeightPlate();
    void set_mass(int mass);
    int get_mass();
    float get_size();
    void set_size(float size);
    virtual string get_equipmentname();
};
//class Barbell:public TrainingEquipment {
//	Grip grip;
//	WeightPlate *weightPlates;
//	int weightPlatescount;
//public:
//	~Barbell();
//	Barbell(Grip grip, int weightPlatescount,WeightPlate *WeightPlates);
//	Barbell();
//	int get_weightPlatescount();
//	void set_weightPlates(int weightPlatescount, WeightPlate* weightPlates);
//	void get_grip();
//	void set_grip(Grip grip);
//	void get_weightPlates();
//	virtual string get_equipmentname();
//};
//class GymVisitor{
//protected:
//	string name;
//	int age;
//public:
//	GymVisitor();
//	GymVisitor(string name, int age);
//	~GymVisitor();
//	void set_name(string name);
//	void set_age(int age);
//	int get_age();
//	string get_name();
//};
//class Trainer: public GymVisitor{
//	int coachstudentscount;
//	GymVisitor *coachstudents;
//public:
//	Trainer();
//	Trainer(int coachstudentscount, GymVisitor*coachstudents);
//	~Trainer();
//	int get_coachstudentscount();
//	void set_coachstudents(int coachstudentscount, GymVisitor * coachstudents);
//	void get_coachstudents();
//};
class Gym {
    TrainingEquipment** equipment;
    int equipmentcount;
public:
    Gym();
    Gym(int equipmentcount, TrainingEquipment** equipment);
    ~Gym();
    Gym(const Gym& obj);
    void set_equipment(int equipmentcount, TrainingEquipment** equipment);
    int get_equipmentcount();
    void get_equipment();
};
void input_check_int(string& str);
void input_check_double(string& str);
string input_check_string();
void termFunc();
class Exception {
};
//class Exercise {
//	string exercisename;
//	int setcount;
//	int repeatcount;
//public:
//	~Exercise();
//	Exercise(string exercisename, int setcount, int repeatcount);
//	Exercise();
//	void set_exercisename(string exercisename);
//	string get_exercisename();
//	void set_setcount(int setcount);
//	int get_setcount();
//	void set_repeatcount(int repeatcount);
//	int get_repeatcount();
//};
class Expection {
public:
    //	void input() {
    //		cout<<"¬ведите число, которое будет " << endl;
    //		try{}
    //}
};
class SkippingRope :public TrainingEquipment {
    string rope_handle_type;
public:
    virtual string get_equipmentname();
    class Rope {
        float length;
        string material;
    public:
        Rope();
        ~Rope();
        Rope(float length, string material);
        void set_length(float length);
        float get_length();
        string get_material();
        void set_material(string material);

    };
    SkippingRope();
    SkippingRope(string rope_handle_type, float length, string material);
    ~SkippingRope();
    void set_rope_handle_type(string rope_handle_type);
    string get_rope_handle_type();
private:
    Rope rope;
};