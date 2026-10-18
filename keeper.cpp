#include <iostream>
#include <fstream>
#include <stdexcept>
#include "keeper.h"

using namespace std;

Keeper::Keeper() {
    data=nullptr;
    size=0;
    cout<<"Вызван конструктор Keeper\n";
}

Keeper::~Keeper() {
    if (data!=nullptr) {
        for (int i=0; i<size; ++i) {
            delete data[i];
        }
        delete[] data;
    }
    cout<<"Вызван деструктор Keeper\n";
}

// добавление
void Keeper::add(Instrument* item) { 
    Instrument** newData=new Instrument*[size+1];
    for (int i=0; i<size; i++) {
        newData[i]=data[i];
    }
    newData[size]=item;
    delete[] data;
    data=newData;
    size+=1;
}

// удаление
void Keeper::remove(int index) {
    if (size==0) {
        throw runtime_error("Ошибка: инструментов в оркестре нет\n");
    }
    if (index<0 || index>=size) {
        throw out_of_range("Ошибка: неверный номер инструмента\n");
    }
    delete data[index];

    // создание нового массива на 1 меньше размером
    Instrument** newData=nullptr;
    if (size-1>0) {
        newData=new Instrument*[size-1];
        int newIndex=0;
        for (int i=0; i<size; i++){
            if (i==index) continue;
            newData[newIndex]=data[i];
            newIndex++;
        }
    }
    delete[] data;
    data=newData;
    size-=1;
    cout<<"Инструмент успешно удален из оркестра\n";
}

// показ
void Keeper::showAll() const {
    if (size==0) {
        cout<<"Ошибка: инструментов в оркестре нет\n";
        return;
    }
    cout<<"\nСписок инструментов оркестра\n";
    for (int i=0; i<size; i++) {
        cout<<"Инструмент № "<<(i+1)<<endl;
        data[i]->print();
    }
    cout<<endl;
}

// сохранение
void Keeper::saveToFile(const string& file) const {
    ofstream out(file);
    if (!out.is_open()) {
        throw runtime_error("Ошибка: не удалось открыть файл для сохранения");
    }
    out<<size<<endl;

    for (int i=0; i<size; i++) {
        out<<data[i]->getTypeId()<<endl;
        data[i]->save(out);
    }
    out.close();
}

// загрузка
void Keeper::loadToFile(const string& file) {
    ifstream in(file);
    if (!in.is_open()) {
        throw runtime_error("Ошибка: не удалось открыть файл для загрузки");
    }
    if (data!=nullptr) {
        for (int i=0; i<size; i++) {
            delete data[i];
        }
        delete[] data;
        data=nullptr;
        size=0;
    }
    int count;
    if (!(in>>count)) {
        in.close();
        return;
    }

    for (int i=0; i<count; i++) {
        int type;
        in>>type;
        in.ignore();

        Instrument* item=nullptr;
        if (type==1) {
            item=new Percussion();
        }
        else if (type==2) {
            item=new StringInst();
        }
        else if (type==3) {
            item=new Wind();
        } 

        if (item!=nullptr) {
            item->load(in);
            add(item);
        }
    }
    in.close();
}
