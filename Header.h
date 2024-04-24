#pragma once
#include <iostream>
#include <string>

using namespace std;

class Kredit {
    string name; //�������� �������
    int sum; //����� �������
    string type_valuta; //��� ������
    int stavka; //������ � %

public:
    Kredit(string name, int sum, string type_valuta, int stavka) { //�����������
        this->name = name;
        this->sum = sum;
        this->type_valuta = type_valuta;
        this->stavka = stavka;
    }

    Kredit(const Kredit& kredit) { //����������� �����������
        this->name = kredit.name;
        this->sum = kredit.sum;
        this->type_valuta = kredit.type_valuta;
        this->stavka = kredit.stavka;
    }

    Kredit() { //����������� � ������
        name = "";
        sum = 0;
        type_valuta = "";
        stavka = 0;
    }

    //������������� ������� ��� ���������� ���������� �����-������
    friend ostream& operator<<(ostream& os, const Kredit& k1);
    friend istream& operator >>(istream& is, Kredit&);

    //������������� ������� ��� ���������� ���������� ���������
    friend bool operator>(const Kredit& k1, const Kredit& k2);
    friend bool operator<(const Kredit& k1, const Kredit& k2);
    friend bool operator ==(const Kredit& k1, const Kredit& k2);

    int getStavka() const {
        return stavka;
    }
};

ostream& operator<<(ostream& os, const Kredit& k1) { //���������� ��������� ������
    os << "Name of kredit: " << k1.name << endl;
    os << "Sum of kredit: " << k1.sum << endl;
    os << "Type of valuta: " << k1.type_valuta << endl;
    os << "Stavka: " << k1.stavka << "%" << endl;
    return os;
}

istream& operator>>(istream& is, Kredit& k1) { //���������� ��������� �����
    is >> k1.name;
    is >> k1.sum;
    is >> k1.type_valuta;
    is >> k1.stavka;
    return is;
}

bool operator >(const Kredit& k1, const Kredit& k2) { //���������� ��������� ��������� � ���� �������
    return k1.stavka > k2.stavka;
}

bool operator <(const Kredit& k1, const Kredit& k2) { //���������� ��������� ��������� � ������ �������
    return k1.stavka < k2.stavka;
}

bool operator ==(const Kredit& k1, const Kredit& k2) { //���������� ��������� ��������� � ������ �������
    return k1.stavka == k2.stavka;
}

/*struct KreditHash {
    size_t operator()(const Kredit& kredit) const {
        return hash<int>() (kredit.getStavka());
    }
};*/