#include <iostream>
#include "keeper.h"
#include "instrument.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");

    Keeper keeper;
    int choice;

    while (true) {
        cout<<"\nМеню\n"
        <<"1. Добавить инструмент\n"
        <<"2. Удалить инструмент\n"        
        <<"3. Посмотреть весь оркестр\n"
        <<"4. Сохранить в файл\n"
        <<"5. Загрузить из файла\n"
        <<"6. Выход\n"
        <<"Ваш выбор: ";
        
        if (!(cin>>choice)) {
            cout<<"Ошибка:введите число\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        } 

        try {
            if (choice==1) { // добавление
                cout<<"\nВведите тип инструмента:\n"
                <<"1.Ударный\n"
                <<"2.Струнный\n"
                <<"3.Духовой\n"
                <<"Ваш выбор: ";
                int typeChoice;
                cin>>typeChoice;

                Instrument* newInstrument=nullptr;

                if (typeChoice==1) {
                    newInstrument=new Percussion();
                }
                else if (typeChoice==2) {
                    newInstrument=new StringInst();
                }
                else if (typeChoice==3) {
                    newInstrument=new Wind();
                } 
                else {
                    cout<<"Ошибка: введен неверный тип инструмента\n";
                    continue;
                }

                cin>>*newInstrument;
                keeper.add(newInstrument);
                cout<<"Инструмент успешно добавлен\n";
            }
            else if (choice==2) { // удаление
                int index;
                cout<<"Введите номер для удаления: ";
                cin>>index;
                keeper.remove(index-1);
            }
            else if (choice==3) { // просмотр
                keeper.showAll();
            }
            else if (choice==4) { // сохранение
                keeper.saveToFile("file.txt");
                cout<<"Данные сохранены в file.txt\n";
            }
            else if (choice==5) { // загрузка
                keeper.loadToFile("file.txt");
                cout<<"Данные загружены из file.txt\n";
            }
            else if (choice==6) { // выход
                break;
            }
            else {
                cout<<"Ошибка: неверный выбор\n";
            }
        }
        catch (exception& e) {
            cout<<"Ошибка:"<<e.what()<<endl;
        }
    }
    cout<<"Программа завершена\n";
    return 0;
}

// g++ main.cpp keeper.cpp instrument.cpp -o main