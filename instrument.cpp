#include "instrument.h"
#include <iostream>

using namespace std;

Instrument::Instrument():name("Нет названия"), name_owner("Нет владельца"), price(0), count(0) {
    cout<<"Вызван конструктор Instrument без параметров\n";
}

Instrument::Instrument(const string& n, const string& n_o, int p, int c):name(n), name_owner(n_o), price(p), count(c) {
    cout<<"Вызван конструктор Instrument с параметрами\n";
}

Instrument::Instrument(const Instrument& other):name(other.name), name_owner(other.name_owner), price(other.price), count(other.count) {
    cout<<"Вызван конструктор копирования Instrument\n";
}

Instrument::~Instrument() {
    cout<<"Вызван деструктор Instrument\n";
}


// класс ударных
Percussion::Percussion():Instrument(), type("Нет типа") {
    cout<<"Вызван конструктор Percussion без параметров\n";
}

Percussion::Percussion(const string& n, const string& n_o, int p, int c, const string& t):Instrument(n, n_o, p, c), type(t) {
    cout<<"Вызван конструктор Percussion с параметрами\n";
}

Percussion::Percussion(const Percussion& other):Instrument(other), type(other.type) {
    cout<<"Вызван конструктор копирования Percussion\n";
}

Percussion::~Percussion() {
    cout<<"Вызван деструктор Percussion\n";
}

void Percussion::print() const {
    cout<<"Тип: ударный инструмент"
    <<"\nНазвание: "<<name
    <<"\nТип ударного инструмента: "<<type
    <<"\nСтоимость: "<<price
    <<"\nКоличество единиц в оркестре: "<<count
    <<"\nФИО владельца: "<<name_owner<<endl;
}

void Percussion::save(ofstream& out) const {
    out<<name<<"\n"<<name_owner<<"\n"<<price<<"\n"<<count<<"\n"<<type<<"\n";
}

void Percussion::load(ifstream& in) {
    getline(in, name);
    getline(in, name_owner);
    in>>price>>count;
    in.ignore();
    getline(in, type);

}

istream& Percussion::input(istream& in) {
    in.ignore(10000, '\n');
    cout<<"Введите название инструмента: ";
    getline(in, name);
    cout<<"Введите тип инструмента: ";
    getline(in, type);
    cout<<"Введите стоимость инструмента: ";
    in>>price;
    cout<<"Введите количество единиц инструмента в оркестре: ";
    in>>count;

    in.ignore(10000, '\n');
    cout<<"Введите ФИО владельца инструмента: ";
    getline(in, name_owner);
    return in;
}

// класс струнных
StringInst::StringInst():Instrument(), name_producer("Нет наименования производителя"), text("Нет описания")  {
    cout<<"Вызван конструктор StringInst без параметров\n";
}

StringInst::StringInst(const string& n, const string& n_o, int p, int c, const string& n_p, const string& t):Instrument(n, n_o, p, c), name_producer(n_p), text(t) {
    cout<<"Вызван конструктор StringInst с параметрами\n";
}

StringInst::StringInst(const StringInst& other):Instrument(other), name_producer(other.name_producer), text(other.text) {
    cout<<"Вызван конструктор копирования StringInst\n";
}

StringInst::~StringInst() {
    cout<<"Вызван деструктор String\n";
}

void StringInst::print() const {
    cout<<"Тип: струнный инструмент\n"
    <<"\nНазвание: "<<name
    <<"\nНаименование производителя: "<<name_producer
    <<"\nСтоимость: "<<price
    <<"\nКоличество единиц в оркестре: "<<count
    <<"\nОпсиание: "<<text
    <<"\nФИО владельца: "<<name_owner<<endl;
}

void StringInst::save(ofstream& out) const {
    out<<name<<"\n"<<name_owner<<"\n"<<price<<"\n"<<count<<"\n"<<name_producer<<"\n"<<text<<"\n";
}

void StringInst::load(ifstream& in) {
    getline(in, name);
    getline(in, name_owner);
    in>>price>>count;
    in.ignore();
    getline(in, name_producer);
    getline(in, text);

}

istream& StringInst::input(istream& in) {
    in.ignore(10000, '\n');
    cout<<"Введите название инструмента: ";
    getline(in, name);
    cout<<"Введите ФИО владельца инструмента: ";
    getline(in, name_owner);
    cout<<"Введите стоимость инструмента: ";
    in>>price;
    cout<<"Введите количество единиц инструмента в оркестре: ";
    in>>count;

    in.ignore(1000, '\n');
    cout<<"Введите наименование производителя инструмента: ";
    getline(in, name_producer);
    cout<<"Введите описание инструмента: ";
    getline(in, text);
    return in;
}


// класс духовых
Wind::Wind():Instrument(), name_producer("Нет наименования производителя"), text_defect("Нет описания дефектов")  {
    cout<<"Вызван конструктор Wind без параметров\n";
}

Wind::Wind(const string& n, const string& n_o, int p, int c, const string& n_p, const string& t_d):Instrument(n, n_o, p, c), name_producer(n_p), text_defect(t_d) {
    cout<<"Вызван конструктор Wind с параметрами\n";
}

Wind::Wind(const Wind& other):Instrument(other), name_producer(other.name_producer), text_defect(other.text_defect) {
    cout<<"Вызван конструктор копирования Wind\n";
}

Wind::~Wind() {
    cout<<"Вызван деструктор Wind\n";
}

void Wind::print() const {
    cout<<"Тип: духовой инструмент\n"
    <<"\nНазвание: "<<name
    <<"\nНаименование производителя: "<<name_producer
    <<"\nСтоимость: "<<price
    <<"\nКоличество единиц в оркестре: "<<count
    <<"\nОпсиание дефектов: "<<text_defect
    <<"\nФИО владельца: "<<name_owner<<endl;
}

void Wind::save(ofstream& out) const {
    out<<name<<"\n"<<name_owner<<"\n"<<price<<"\n"<<count<<"\n"<<name_producer<<"\n"<<text_defect<<"\n";
}

void Wind::load(ifstream& in) {
    getline(in, name);
    getline(in, name_owner);
    in>>price>>count;
    in.ignore();
    getline(in, name_producer);
    getline(in, text_defect);

}

istream& Wind::input(istream& in) {
    in.ignore(10000, '\n');
    cout<<"Введите название инструмента: ";
    getline(in, name);
    cout<<"Введите ФИО владельца инструмента: ";
    getline(in, name_owner);
    cout<<"Введите стоимость инструмента: ";
    in>>price;
    cout<<"Введите количество единиц инструмента в оркестре: ";
    in>>count;
    
    in.ignore(1000, '\n');
    cout<<"Введите наименование производителя инструмента: ";
    getline(in, name_producer);
    cout<<"Введите описание дефектов инструмента: ";
    getline(in, text_defect);
    return in;
}

