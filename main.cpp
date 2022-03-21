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

    string generuoti;
    cout << "Ar norite generuoti faila? (0 - ne, 1 - taip)" << endl;
    cin >> generuoti;
    while((generuoti != "0" && generuoti != "1") || onlyLetters(generuoti) == true){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> generuoti;
    }
    if(generuoti == "1"){
        string generatedFileName;
        //Failo pavadinimo ir ilgio pasirinkimas

        fileLength = generateFileName(generatedFileName, pazymiuKiekis);

        //Failo duomenu kurimas
        generateFileData(generatedFileName, fileLength, pazymiuKiekis, timeTaken);
    }
    else{
        string generatedFileName = "kursiokai";
        int fileLength;

        cout << "Iveskite failo ilgi" << endl;
        cin >> fileLength;

        while(cin.fail()){
            cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
            cin.clear();
            cin.ignore(256,'\n');
            cin >> fileLength;
        }

        generatedFileName += to_string(fileLength) + ".txt";

        vector<duomenys> sarasas; //Nelaimingieji
        vector<duomenys> sarasas2; //Kietekai
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
    }
    return 0;
}
