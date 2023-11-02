#include"h.h"
TrainingEquipment::TrainingEquipment() {
	equipmentname = "no equipmentname";
	//cout << "Сработал конструктор класса TrainingEquipment" << endl;
}
TrainingEquipment::TrainingEquipment(string equipmentname) {
	this->equipmentname = equipmentname;
}
TrainingEquipment::~TrainingEquipment() {
	cout << "Сработал деструктор класса TrainingEquipment" << endl;
}
string TrainingEquipment::get_equipmentname(){
	return "";
};
void TrainingEquipment::set_equipmentname(string equipmentname){
	this->equipmentname = equipmentname;
}
Gym::Gym() {
	equipmentcount = 10;
	equipment = new TrainingEquipment*[equipmentcount];
	cout<<"Сработал конструктор класса Gym" << endl;
}
Gym::Gym(int equipmentcount, TrainingEquipment** equipment) {
	//const char *message = "Исключение в конструкторе";
	this->equipmentcount = equipmentcount;
	if (!equipmentcount) {
		throw exception("Исключение в конструкторе");
	}
/*catch (const char* message) {
		cout << "Поймано исключение в конструкторе" << endl;
	}
	catch (...) {
		cout << "Исключение перехвачено" << endl;
	}*/
	equipment = new TrainingEquipment*[equipmentcount];
	for (int i = 0; i < equipmentcount; i++) {
		this->equipment[i] = equipment[i];
	}
}
int Gym::get_equipmentcount() {
	return equipmentcount;
}
void Gym::set_equipment(int equipmentcount, TrainingEquipment **equipment){
	if (this->equipmentcount) {
		delete[]this->equipment;
	}
	this->equipmentcount = equipmentcount;
	this->equipment = new TrainingEquipment*[equipmentcount];
	for (int i = 0; i <equipmentcount; i++) {
		this->equipment[i] = equipment[i];
}
}
Gym::Gym(const Gym& obj) {
	equipmentcount = obj.equipmentcount;
	this->equipment = new TrainingEquipment*[equipmentcount];
	for (int i = 0; i < equipmentcount; i++) {
		equipment[i] = obj.equipment[i];
	}
}
void Gym::get_equipment(){
	for (int i = 0; i < 24; i++) {
		cout<<"-" ;
	}
	cout << endl;
	for (int i = 0; i < equipmentcount; i++) {
		cout << "|" << setw(3) << left << i + 1 << "|" << setw(18) << left << equipment[i]->get_equipmentname() << "|" << endl;
}
	for (int i = 0; i < 22; i++) {
		cout << "-";
	}
	cout << endl;
}
Gym::~Gym() {
	cout << "Сработал деструктор класса Gym" << endl;
	delete[] equipment;
}
//GymVisitor::GymVisitor() {
//	age = 0;
//	name = "no name";
//	cout << "Сработал конструктор класса GymVisitor" << endl;
//}
//GymVisitor::GymVisitor(string name, int age) {
//	this->name = name;
//	this->age = age;
//}
//GymVisitor::~GymVisitor() {
//	cout << "Сработал деструктор класса GymVisitor" << endl;
//}
//int GymVisitor::get_age() {
//	return age;
//}
//string GymVisitor::get_name() {
//	return name;
//}
//void GymVisitor::set_age(int age) {
//	this->age = age;
//}
//void GymVisitor::set_name(string name){
//	this->name = name;
//}
//Trainer::Trainer() {
//	coachstudentscount = 0;
//	coachstudents = new GymVisitor[coachstudentscount];
//	cout << "Сработал конструктор класса Trainer" << endl;
//}
//Trainer::Trainer(int coachstudentscount, GymVisitor *coachstudents) {
//	if (!coachstudents) {
//		throw 1;
//
//	}
//	else {
//		this->coachstudentscount = coachstudentscount;
//		this->coachstudents = new GymVisitor[coachstudentscount];
//		for (int i = 0; i < coachstudentscount; i++) {
//			this->coachstudents[i] = coachstudents[i];
//		}
//	}
//}
//void Trainer::set_coachstudents(int coachstudentscount, GymVisitor *coashstudents){
//	this->coachstudentscount = coachstudentscount;
//	for (int i = 0; i < coachstudentscount; i++) {
//		this->coachstudents[i] = coachstudents[i];
//	}
//}
//Trainer::~Trainer() {
//	cout << "Сработал деструктор класса Trainer" << endl;
//}
//int Trainer::get_coachstudentscount() {
//	return coachstudentscount;
//}
//void Trainer::get_coachstudents() {
//	for (int i = 0; i < 45; i++) {
//		cout<<"-" << endl;
//	}
//	for (int i = 0; i < coachstudentscount; i++) {
//		cout << "|" << i + 1 << "|" << setw(30) << left << coachstudents[i].get_name() << "|" << setw(10) << left << coachstudents[i].get_age() << "|" << endl;
//	}
//	for (int i = 0; i < 45; i++) {
//		cout << "-" << endl;
//	}
//}
//Exercise::Exercise() {
//	cout<<"Сработал конструктор класса Exercise" << endl;
//}
//Exercise::~Exercise() {
//	cout << "Сработал деструктор класса Exercise" << endl;
//}
//Exercise::Exercise(string exercisename, int setcount, int repeatcount) {
//	this->exercisename = exercisename;
//	this->setcount = setcount;
//	this->repeatcount = repeatcount;
//}
WeightPlate::WeightPlate() {
	mass = 0;
	size = 0;
	equipmentname = "Диск";
	cout << "Сработал конструктор класса WeightPlate" << endl;
}
WeightPlate::~WeightPlate() {
	cout<<"Сработал деструктор класса WeightPlate" << endl;
}
WeightPlate::WeightPlate(int mass, float size) {
	this->mass = mass;
	this->size = size;
	equipmentname = "Диск";
}
int WeightPlate::get_mass() {
	return mass;
}
float WeightPlate::get_size() {
	return size;
}
void WeightPlate::set_mass(int mass) {
	this->mass = mass;
}
void WeightPlate::set_size(float size){
	this->size = size;
}
string WeightPlate::get_equipmentname() {
	return "Диск";
}
Grip::Grip() {
	mass= 0;
	equipmentname = "Гриф";
	cout << "Сработал конструктор класса Grip" << endl;
}
string Grip::get_equipmentname(){
	return "Гриф";
}
Grip::~Grip() {
	cout << "Сработал деструктор класса Grip" << endl;
}
Grip::Grip(int mass) {
	this->mass = mass;
	equipmentname = "Гриф";
}
void Grip::set_mass(int mass){
	this->mass = mass;
}
int Grip::get_mass() {
	return mass;
}
//Barbell::Barbell() {
//	equipmentname = "Штанга";
//	grip.set_mass(20);
//	weightPlatescount = 2;
//	weightPlates = new WeightPlate[weightPlatescount];
//	for (int i = 0; i < weightPlatescount; i++) {
//		weightPlates[i] = WeightPlate(15, 0.25);
//	}
//	cout << "Сработал конструктор класса Barbell" << endl;
//}
//Barbell::Barbell(Grip grip, int weightPlatescount, WeightPlate* weightPlates) {
//	this->grip = grip;
//	this->weightPlatescount = weightPlatescount;
//	this->weightPlates = new WeightPlate[weightPlatescount];
//	for (int i = 0; i < weightPlatescount;i++) {
//		this->weightPlates[i] = weightPlates[i];
//	}
//}
//Barbell::~Barbell() {
//	delete[] weightPlates;
//	cout << "Сработал деструктор класса Barbell" << endl;
//}
//int Barbell::get_weightPlatescount() {
//	return weightPlatescount;
//}
//void Barbell::set_weightPlates(int weightPlatescount, WeightPlate *weightPlates) {
//	this->weightPlatescount = weightPlatescount;
//	for (int i = 0; i < weightPlatescount; i++) {
//		this->weightPlates[i] = weightPlates[i];
//	}
//}
//void Barbell::set_grip(Grip grip) {
//	this->grip = grip;
//}
//void Barbell::get_grip() {
//	for (int i = 0; i <23 ; i++) {
//		cout<<"-" << endl;
//	}
//	cout<<"|"<<setw(10)<<left<<grip.get_equipmentname()<<"|"<<setw(10)<<left<<grip.get_mass()<<"|" << endl;
//	for (int i = 0; i < 23; i++) {
//		cout << "-" << endl;
//	}
//}
//void Barbell::get_weightPlates() {
//	for (int i = 0; i <31 ; i++) {
//		cout << "-" << endl;
//	}
//	for (int i = 0; i <weightPlatescount ; i++) {
//		cout<<"|"<<i+1<<"|"<<setw(10)<<left<<weightPlates[i].get_equipmentname()<<"|"<<setw(5)<<left<<weightPlates[i].get_mass()<<"кг|"<<setw(5)<<left <<weightPlates[i].get_size()<<"м^2|" << endl;
//	}
//	for (int i = 0; i < 31; i++) {
//		cout << "-" << endl;
//	}
//}
//string Barbell::get_equipmentname() 
//{
//	return "Штанга";
//};
void SkippingRope::Rope::set_length(float length) {
	this->length = length;
}
void SkippingRope::Rope::set_material(string material){
	this->material = material;
}
string SkippingRope::Rope::get_material() {
	return material;
}
float SkippingRope::Rope::get_length() {
	return length;
}
string SkippingRope::get_equipmentname() {
	return "Скакалка";
}
SkippingRope::Rope::~Rope() {
	cout<<"Сработал деструктор класса Rope" << endl;
}
SkippingRope::Rope::Rope() {
	length = 0; 
	material = "no material";
}
SkippingRope::Rope::Rope(float length, string material) {
	this->length = length;
	this->material = material;
}
SkippingRope::SkippingRope() {
	rope_handle_type = "no type";
	equipmentname = "Скакалка";
	rope=Rope();
}
SkippingRope::SkippingRope(string rope_handle_type, float length, string material){
	this->rope_handle_type = rope_handle_type;
	rope=Rope(length, material);
	equipmentname = "Скакалка";
}
SkippingRope::~SkippingRope() {
	cout<<"Сработал деструктор класса SkippingRope" << endl;
}
string SkippingRope::get_rope_handle_type(){
	return rope_handle_type;
}
void SkippingRope::set_rope_handle_type(string rope_handle_type){
	this->rope_handle_type = rope_handle_type;
}