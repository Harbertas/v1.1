#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::stringstream;

struct duomenys{
    string vardas, pavarde;
    vector<int> paz;
    int egz = 0;
    int kiekPaz = 0;
    double rezult = 0;
};

double skaiciuoti(duomenys&);
double mediana(duomenys&);
void isvedimas(duomenys);
bool compare_pavarde(const duomenys&, const duomenys&);
bool compare_g_paz(const duomenys&, const duomenys&);
bool compare_vardas(const duomenys&, const duomenys&);
bool onlyLetters(string);
void rikiavimas(vector<duomenys>&);
void spausdinti(vector<duomenys>);

#endif
