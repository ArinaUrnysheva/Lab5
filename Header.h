#pragma once
#include <iostream>
#include <string>

using namespace std;

class Kredit {
    string name; //название кредита
    int sum; //сумма кредита
    string type_valuta; //тип валюты
    int stavka; //ставка в %

public:
    Kredit(string name, int sum, string type_valuta, int stavka) { //конструктор
        this->name = name;
        this->sum = sum;
        this->type_valuta = type_valuta;
        this->stavka = stavka;
    }

    Kredit(const Kredit& kredit) { //конструктор копирования
        this->name = kredit.name;
        this->sum = kredit.sum;
        this->type_valuta = kredit.type_valuta;
        this->stavka = kredit.stavka;
    }

    Kredit() { //конструктор с нулями
        name = "";
        sum = 0;
        type_valuta = "";
        stavka = 0;
    }

    //дружественные функции для перегрузки операторов ввода-вывода
    friend ostream& operator<<(ostream& os, const Kredit& k1);
    friend istream& operator >>(istream& is, Kredit&);

    //дружественные функции для перегрузки операторов сравнения
    friend bool operator>(const Kredit& k1, const Kredit& k2);
    friend bool operator<(const Kredit& k1, const Kredit& k2);
    friend bool operator ==(const Kredit& k1, const Kredit& k2);

    int getStavka() const {
        return stavka;
    }
};

ostream& operator<<(ostream& os, const Kredit& k1) { //перегрузка оператора вывода
    os << "Name of kredit: " << k1.name << endl;
    os << "Sum of kredit: " << k1.sum << endl;
    os << "Type of valuta: " << k1.type_valuta << endl;
    os << "Stavka: " << k1.stavka << "%" << endl;
    return os;
}

istream& operator>>(istream& is, Kredit& k1) { //перегрузка оператора ввода
    is >> k1.name;
    is >> k1.sum;
    is >> k1.type_valuta;
    is >> k1.stavka;
    return is;
}

bool operator >(const Kredit& k1, const Kredit& k2) { //перегрузка оператора сравнения в одну сторону
    return k1.stavka > k2.stavka;
}

bool operator <(const Kredit& k1, const Kredit& k2) { //перегрузка оператора сравнения в другую сторону
    return k1.stavka < k2.stavka;
}

bool operator ==(const Kredit& k1, const Kredit& k2) { //перегрузка оператора сравнения в другую сторону
    return k1.stavka == k2.stavka;
}

/*struct KreditHash {
    size_t operator()(const Kredit& kredit) const {
        return hash<int>() (kredit.getStavka());
    }
};*/