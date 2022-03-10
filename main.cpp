#include "functions.h"
#include "mix.h"

int main()
{
    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);

    int fileLength;
    int pazymiuKiekis;
    double timeTaken;
    string generatedFileName;
    fileLength = generateFileName(generatedFileName, pazymiuKiekis);

    generateFileData(generatedFileName, fileLength, pazymiuKiekis, timeTaken);

    vector<duomenys> sarasas;
    vector<duomenys> sarasas2;
    try{
        std::ifstream df(generatedFileName);
        if(!df)
            throw 1;
        df.close();
    }
    catch(int x){
        cout << "Toks duomenu failas ('" << generatedFileName << "') neegzistuoja, Klaidos kodas: " << x << endl;
        exit(0);
    }
    mix(generatedFileName, "kursiokai_copy.txt", sarasas, fileLength, timeTaken);
    rikiavimas(sarasas, fileLength, timeTaken);
    atskirti(sarasas, sarasas2, fileLength, timeTaken);
    spausdinti(sarasas, sarasas2, fileLength, timeTaken);
    cout << '\n';
    cout << fileLength << " irasu testo laikas: " << timeTaken << endl;
    sarasas.clear();
    sarasas2.clear();
    return 0;
}
