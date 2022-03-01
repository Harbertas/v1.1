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

void spausdinti(vector<duomenys> sarasas){
    auto start = std::chrono::high_resolution_clock::now();
    string where;
    duomenys temp;
    cout << "Kur norite irasyti rezultatus? (failas - 1, konsoleje - 2)" << endl;
    cin >> where;
    while((where != "1" && where != "2") || onlyLetters(where) == true){ //|| rusiuoti != 1 || rusiuoti != 2 || rusiuoti != 3
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> where;
    }
    if(where == "2"){
        cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
        cout << "-------------------------------------------------------------------" << endl;
        for(auto el : sarasas){
            isvedimas(el);
        }
        //cout << sarasas.size();
        sarasas.clear();
    }
    else{
        start = std::chrono::high_resolution_clock::now();
        std::ofstream rf;
        rf.open("kursiokai_rez.txt");
        rf << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
        rf << "-------------------------------------------------------------------" << endl;
        for(auto el : sarasas){
            temp = el;
            rf << std::left << std::setw(15) << temp.pavarde << std::left << std::setw(15) << temp.vardas << std::left << std::setw(19) << std::fixed << std::setprecision(2) << temp.rezult << std::fixed << std::setprecision(2) << mediana(temp) << endl;
        }
        rf.close();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start; // Skirtumas (s)
        diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
        std::cout << "Irasymas i faila uztruko: "<< diff.count() << " s\n";
    }
}

void rikiavimas(vector<duomenys>& sarasas){
    string rusiuoti;
    cout << "Pagal ka norite rusiuoti? (nieko nerusiuoti - 0, varda - 1, pavarde - 2, galutini pazymi - 3)" << endl;
    cin >> rusiuoti;
    while((rusiuoti != "1" && rusiuoti != "2" && rusiuoti != "3" && rusiuoti != "0") || onlyLetters(rusiuoti) == true){ //|| rusiuoti != 1 || rusiuoti != 2 || rusiuoti != 3
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> rusiuoti;
    }
    auto start = std::chrono::high_resolution_clock::now();

    if(rusiuoti == "1")
        sort(sarasas.begin(), sarasas.end(), compare_vardas);
    else if(rusiuoti == "2")
        sort(sarasas.begin(), sarasas.end(), compare_pavarde);
    else if(rusiuoti == "3")
        sort(sarasas.begin(), sarasas.end(), compare_g_paz);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << "Rusiavimas uztruko: "<< diff.count() << " s\n";

}
