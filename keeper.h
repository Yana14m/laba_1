#pragma once 
#include <string>
#include "instrument.h"

class Keeper {
    Instrument** data;
    int size;
public:
    Keeper();
    ~Keeper();

    void add(Instrument* item);
    void remove(int index);
    void showAll() const;
    void saveToFile(const std::string& file) const;
    void loadToFile(const std::string& file);
    int getSize() const {return size;}
};