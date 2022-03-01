#include "functions.h"
#include "mix.h"

const string fileName = "kursiokai.txt";

int main()
{
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    vector<duomenys> sarasas;
    try{
        std::ifstream df(fileName);
        if(!df)
            throw 1;
        df.close();
    }
    catch(int x){
        cout << "Toks duomenu failas ('" << fileName << "') neegzistuoja, Klaidos kodas: " << x << endl;
        exit(0);
    }
    mix(fileName, "kursiokai_copy.txt", sarasas);
    rikiavimas(sarasas);
    spausdinti(sarasas);
    return 0;
}
