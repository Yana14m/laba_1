#pragma once 
#include <string>
#include <iostream>
#include <fstream>

class Instrument {
protected:
    std::string name;
    std::string name_owner;
    int price;
    int count;
public:
    Instrument();
    Instrument(const std::string& n, const std::string& n_o, int p, int c);
    Instrument(const Instrument& other);
    virtual ~Instrument();

    virtual int getTypeId() const=0;
    virtual void print() const=0;
    virtual void save(std::ofstream& out) const=0;
    virtual void load(std::ifstream& in)=0;

    virtual std::istream& input(std::istream& in)=0;
    friend std::istream& operator>>(std::istream& in, Instrument& obj) {
        return obj.input(in);
    }

    std::string getName() const {return name;}
    void setName(const std::string& n) {name=n;}

    std::string getNameOwner() const {return name_owner;}
    void setNameOwner(const std::string& n_o) {name_owner=n_o;}   

    int getPrice() const {return price;}
    void setPrice(int p) {price=p;}

    int getCount() const {return count;}
    void setCount(int c) {count=c;}
};

// класс ударных
class Percussion: public Instrument {
    std::string type;
public:
    Percussion();
    Percussion(const std::string& n, const std::string& n_o, int p, int c, const std::string& t);
    Percussion(const Percussion& other);
    virtual ~Percussion();

    int getTypeId() const override {return 1;}
    void print() const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::istream& input(std::istream& in) override;
    
    std::string getType() const {return type;}
    void setType(const std::string& t) {type=t;} 
};

// класс струнных
class StringInst: public Instrument {
    std::string name_producer;
    std::string text;
public:
    StringInst();
    StringInst(const std::string& n, const std::string& n_o, int p, int c, const std::string& n_p, const std::string& t);
    StringInst(const StringInst& other);
    virtual ~StringInst();

    int getTypeId() const override {return 2;}
    void print() const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::istream& input(std::istream& in) override;

    std::string getNameProducer() const {return name_producer;}
    void setNameProducer(const std::string& n_p) {name_producer=n_p;} 

    std::string getText() const {return text;}
    void setText(const std::string& t) {text=t;} 
};

// класс духовых
class Wind: public Instrument {
    std::string name_producer;
    std::string text_defect;
public:
    Wind();
    Wind(const std::string& n, const std::string& n_o, int p, int c, const std::string& n_p, const std::string& t_d);
    Wind(const Wind& other);
    virtual ~Wind();

    int getTypeId() const override {return 3;}
    void print() const override;
    void save(std::ofstream& out) const override;
    void load(std::ifstream& in) override;
    std::istream& input(std::istream& in) override;

    std::string getNameProducer() const {return name_producer;}
    void setNameProducer(const std::string& n_p) {name_producer=n_p;} 

    std::string getTextDefect() const {return text_defect;}
    void setTextDefect(const std::string& t_d) {text_defect=t_d;} 
};