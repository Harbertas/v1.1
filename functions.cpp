#include "functions.h"

bool onlyLetters(string name){
    for(auto i : name){
        if(isdigit(i) == true){
            return false;
        }
    }
    return true;
}


bool compare_pavarde(const duomenys &a, const duomenys &b){
    if(a.pavarde == b.pavarde){
        return a.vardas < b.vardas;
    }
    return a.pavarde < b.pavarde;
}

bool compare_g_paz(const duomenys &a, const duomenys &b){
    if(a.rezult == b.rezult){
        return a.pavarde < b.pavarde;
    }
    return a.rezult < b.rezult;
}

bool compare_vardas(const duomenys &a, const duomenys &b){
    if(a.vardas == b.vardas){
        return a.pavarde < b.pavarde;
    }
    return a.vardas < b.vardas;
}

double skaiciuoti(duomenys& temp){
    double vidurkis = 0;
    int suma = 0;
    for(int i = 0; i < temp.kiekPaz; i++){
        suma = suma + temp.paz[i];
    }
    vidurkis = (double)suma / temp.kiekPaz;
    temp.rezult = 0.4 * vidurkis + 0.6 * temp.egz;
    return temp.rezult;
}

double mediana(duomenys& temp){
    double rez = 0;
    int index = temp.kiekPaz/2;
    if(temp.kiekPaz % 2 != 0){
        // 1 2 3
        rez = temp.paz[index];
    }
    else{
        // 1 2 3 4
        rez = (double)(temp.paz[index] + temp.paz[index-1]) / 2;
    }
    return rez;
}

void isvedimas(duomenys temp){
    cout << std::left << std::setw(15) << temp.pavarde << std::left << std::setw(15) << temp.vardas << std::left << std::setw(19) << std::fixed << std::setprecision(2) << temp.rezult << std::fixed << std::setprecision(2) << mediana(temp) << endl;
}
