#include "functions.h"
#include "mix.h"

int main()
{
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    vector<duomenys> sarasas;
    duomenys temp;
    string rusiuoti;
    string where;
    mix("kursiokai.txt", "kursiokai_copy.txt", sarasas);
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
    cout << "Kur norite irasyti rezultatus? (failas - 1, konsoleje - 2)" << endl;
    cin >> where;
    while((where != "1" && where != "2") || onlyLetters(rusiuoti) == true){ //|| rusiuoti != 1 || rusiuoti != 2 || rusiuoti != 3
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
        diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
        std::cout << "Irasymas i faila uztruko: "<< diff.count() << " s\n";
    }
    return 0;
}
