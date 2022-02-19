#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <iterator>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

const int n = 3;

struct duomenys{
    string vardas, pavarde;
    int paz[n] = {0};
    int egz = 0;
    double rezult = 0;
    string generuoti;
};

bool onlyLetters(string name){
    for(auto i : name){
        if(isdigit(i) == true){
            return false;
        }
    }
    return true;
}

void ivedimas(duomenys& temp){
    srand((unsigned)time(NULL));
    cout << "iveskite varda" << endl;
    cin >> temp.vardas;
    while(onlyLetters(temp.vardas) == false){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin >> temp.vardas;
    }
    cout << "iveskite pavarde" << endl;
    cin >> temp.pavarde;
    while(onlyLetters(temp.pavarde) == false){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin >> temp.pavarde;
    }
    cout << "Ar norite, kad pazymiai butu sugeneruoti automatiskai? (1 - taip, bet koks simbolis - ne)" << endl;
    cin >> temp.generuoti;
    if(temp.generuoti == "1"){
        int random;
        for(int i = 0; i < n; i++){
            random = 1 + (rand() % 10);
            temp.paz[i] = random;
            cout << i+1 << " pazymys: " << temp.paz[i] << endl;
        }
    }
    else{
        int pazymys;
        cout << "iveskite pazymius (" << n << ")" << endl;
        for(int i = 0; i < n; i++){
            cin >> temp.paz[i];
            while(cin.fail() || temp.paz[i] > 10 || temp.paz[i] < 1){
                cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
                cin.clear();
                cin.ignore(256,'\n');
                cin >> temp.paz[i];
            }
        }
    }
    cout << "iveskite egzamino ivertinima" << endl;
    cin >> temp.egz;
    while(cin.fail() || temp.egz > 10 || temp.egz < 1){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> temp.egz;
    }
}

double skaiciuoti(duomenys& temp){
    double vidurkis = 0;
    int suma = 0;
    for(int i = 0; i < n; i++){
        suma = suma + temp.paz[i];
    }
    vidurkis = (double)suma / n;
    temp.rezult = 0.4 * vidurkis + 0.6 * temp.egz;
    return temp.rezult;
}

double mediana(duomenys& temp){
    double rez = 0;
    int index = n/2;
    if(n % 2 != 0){
        // 1 2 3
        rez = temp.paz[index];
    }
    else{
        // 1 2 3 4
        rez = (double)(temp.paz[index] + temp.paz[index-1]) / 2;
    }
    return rez;
}

void isvedimas(duomenys& temp){
    cout << std::left << std::setw(15) << temp.pavarde << std::left << std::setw(15) << temp.vardas << std::left << std::setw(19) << std::fixed << std::setprecision(2) << temp.rezult << std::fixed << std::setprecision(2) << mediana(temp) << endl;
}

int main()
{
    vector<duomenys> sarasas;
    duomenys laikinas;
    int daugiau;
    int ivesta = 0;
    int m; // kiek studentu
    cout << "Kiek studentu norite ivesti?" << endl;
    cin >> m;
    while(cin.fail()){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> m;
    }
    sarasas.reserve(m);
    for(int i = 0; i < m; i++){
        if(ivesta != m){
            ivedimas(laikinas);
            skaiciuoti(laikinas);
            sarasas.push_back(laikinas);
            ivesta++;
        }
        if(ivesta == m){
            cout << "Ar norite iveste dar 1-a studenta? (1 - taip,0 - ne)" << endl;
            cin >> daugiau;
            if(daugiau == 1){
                sarasas.reserve(m+1);
                ivedimas(laikinas);
                skaiciuoti(laikinas);
                sarasas.push_back(laikinas);
                m++;
                ivesta++;
            }
        }
    }
    cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for(auto &el :  sarasas){
        isvedimas(el);
    }
    sarasas.clear();
    return 0;
}
