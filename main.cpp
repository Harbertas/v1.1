#include "functions.h"
#include "mix.h"

int main()
{
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    vector<duomenys> sarasas;
    string rusiuoti;
    mix("kursiokai3.txt", "kursiokai_copy.txt", sarasas);
    cout << "Pagal ka norite rusiuoti? (varda - 1, pavarde - 2, galutini pazymi - 3)" << endl;
    cin >> rusiuoti;
    while((rusiuoti != "1" && rusiuoti != "2" && rusiuoti != "3") || onlyLetters(rusiuoti) == true){ //|| rusiuoti != 1 || rusiuoti != 2 || rusiuoti != 3
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> rusiuoti;
    }
    if(rusiuoti == "1")
        sort(sarasas.begin(), sarasas.end(), compare_vardas);
    else if(rusiuoti == "2")
         sort(sarasas.begin(), sarasas.end(), compare_pavarde);
    else
        sort(sarasas.begin(), sarasas.end(), compare_g_paz);
    cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    for(auto el : sarasas){
        isvedimas(el);
    }
    //cout << sarasas.size();
    sarasas.clear();
    return 0;
}
