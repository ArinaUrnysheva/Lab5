#include "Header.h"

#include <vector>
#include <list>
#include <algorithm>
#include <fstream>
#include <set>
#include <unordered_set>

void SaveToFile(const string& filename, const Kredit& k1) { //функция сохранения данных типа Kredit в файл
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << k1 << endl;
        cout << k1 << endl;
        file.close();
    }
    else cerr << "Can't open this file :(" << endl;
}

void SaveToFile(const string& filename, const string& s) { //перегрузка функции для сохранения в файл данных типа string
    ofstream file(filename, ios::app);
    if (file.is_open()) {
        file << s << endl;
        cout << s << endl;
        file.close();
    }
    else cerr << "Can't open this file :(" << endl;
}

struct KreditHash {
    size_t operator()(const Kredit& kredit) const {
        return hash<int>() (kredit.getStavka());
    }
};

int main() {
    ofstream clear("output.txt");
    clear.close();
    ifstream input("input.txt");

    int n;
    list<Kredit>K1; //создание двусвязного списка 
    vector<Kredit>K2; //создание вектора
    set<Kredit>set1; //создание множества
    unordered_set<Kredit, KreditHash> uset1; //создание неупорядоченного множества
    cout << "Enter amount of kredits: ";
    cin >> n;
    cout << endl;

    for (size_t i = 0; i < n; ++i) {
        Kredit k;
        input >> k;
        K1.push_back(k); //добавление элементов из файла в двусвязный список
        set1.insert(k); //добавление элементов из файла в множество
        uset1.insert(k); //добавление элементов из файла в неупорядоченное множество
    }
    /*cout << "Set: ";
    for (auto e : set1) cout << e << ' ';
    cout << endl;

    cout << "Unordered set: ";
    for (auto e : uset1) cout << e << ' ';
    cout << endl;*/

    string s = "Before sort: ";
    SaveToFile("output.txt", s); //сохранение строки в файл

    for (const auto e : K1) SaveToFile("output.txt", e); //сохранение элементов двусвязного списка в файл

    s = "After sort";

    K1.sort(); //сортировка двусвязного списка 

    SaveToFile("output.txt", s); //сохранение строки в файл
    for (const auto e : K1) SaveToFile("output.txt", e); //сохранение отсортированного двусвязного списка в файл

    s = "Vector from list: ";
    SaveToFile("output.txt", s); //сохранение строки в файл


    copy(K1.begin(), K1.end(), back_inserter(K2)); //копирование двусвязного списка в вектор

    for (const auto e : K2) SaveToFile("output.txt", e); //сохранение вектора в файл

    s = "Elements from set: ";
    SaveToFile("output.txt", s);

    for (const auto e : set1) SaveToFile("output.txt", e);

    s = "Elements from unordered set: ";
    SaveToFile("output.txt", s);

    for (const auto e : uset1) SaveToFile("output.txt", e);

    return 0;
}
