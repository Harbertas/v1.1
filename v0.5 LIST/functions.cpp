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
    auto it = temp.paz.begin();
    for(int i = 0; i < temp.kiekPaz; i++){
        suma = suma + *it;
        std::advance(it, 1);
    }
    vidurkis = (double)suma / temp.kiekPaz;
    temp.rezult = 0.4 * vidurkis + 0.6 * temp.egz;
    //cout << temp.rezult << endl;
    return temp.rezult;
}

double mediana(duomenys& temp){
    double rez = 0;
    int index = temp.kiekPaz/2;
    list<int>::iterator it = temp.paz.begin();
    list<int>::iterator it2 = temp.paz.begin();
    if(temp.kiekPaz % 2 != 0){
        // 1 2 3
        std::advance(it, index);
        rez = *it;
    }
    else{
        // 1 2 3 4
        std::advance(it, index);
        std::advance(it2, index+1);
        rez = (double)((*it) + *(it2)) / 2;
    }
    return rez;
}

void isvedimas(duomenys& temp){
    cout << std::left << std::setw(15) << temp.pavarde << std::left << std::setw(15) << temp.vardas << std::left << std::setw(19) << std::fixed << std::setprecision(2) << temp.rezult << std::fixed << std::setprecision(2) << mediana(temp) << endl;
}

void spausdinti(list<duomenys>& sarasas, list<duomenys>& sarasas2, int fileLength/*, double &timeTaken*/){
    auto start = std::chrono::high_resolution_clock::now();
    start = std::chrono::high_resolution_clock::now();
    stringstream my_buffer;

    std::ofstream rf;
    rf.open("kietekai.txt");

    my_buffer << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
    my_buffer << "-------------------------------------------------------------------" << endl;
    for(auto &el : sarasas2){
        my_buffer << std::left << std::setw(15) << el.pavarde << std::left << std::setw(15) << el.vardas << std::left << std::setw(19) << std::fixed << std::setprecision(2) << el.rezult << std::fixed << std::setprecision(2) << mediana(el) << endl;
    }
    rf << my_buffer.str();
    my_buffer.str("");
    my_buffer.clear();
    rf.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
    //std::cout << fileLength << " eiluciu irasymas i faila (nelaimingieji.txt) uztruko: "<< diff.count() << " s\n";
    //timeTaken += diff.count();

    start = std::chrono::high_resolution_clock::now();
    std::ofstream rf2;
    rf2.open("nelaimingieji.txt");
    my_buffer << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(17) << "Galutinis (Vid.) " << "/ Galutinis (Med.)" << endl;
    my_buffer << "-------------------------------------------------------------------" << endl;
    for(auto &el : sarasas){
        my_buffer << std::left << std::setw(15) << el.pavarde << std::left << std::setw(15) << el.vardas << std::left << std::setw(19) << std::fixed << std::setprecision(2) << el.rezult << std::fixed << std::setprecision(2) << mediana(el) << endl;
    }
    rf2 << my_buffer.str();
    my_buffer.str("");
    my_buffer.clear();
    rf2.close();

    end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
    //std::cout << fileLength << " eiluciu irasymas i faila (kietekai.txt) uztruko: "<< diff.count() << " s\n";
    //timeTaken += diff.count();
}

void rikiavimas(list<duomenys>& sarasas, int fileLength, double &timeTaken){
    string rusiuoti = "3";
    //cout << "Pagal ka norite rusiuoti? (nieko nerusiuoti - 0, varda - 1, pavarde - 2, galutini pazymi - 3)" << endl;
    //cin >> rusiuoti;
    while((rusiuoti != "1" && rusiuoti != "2" && rusiuoti != "3" && rusiuoti != "0") || onlyLetters(rusiuoti) == true){ //|| rusiuoti != 1 || rusiuoti != 2 || rusiuoti != 3
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> rusiuoti;
    }
    auto start = std::chrono::high_resolution_clock::now();

//    if(rusiuoti == "1")
//        //sort(sarasas.begin(), sarasas.end(), compare_vardas);
//    else if(rusiuoti == "2")
//        //sort(sarasas.begin(), sarasas.end(), compare_pavarde);
//    else if(rusiuoti == "3")
        //sort(sarasas.begin(), sarasas.end(), compare_g_paz);
        sarasas.sort(compare_g_paz);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << fileLength << " eiluciu rusiavimas uztruko: "<< diff.count() << " s\n";
    timeTaken += diff.count();
}

int generateFileName(string &generatedFileName, int &pazymiuKiekis){
    int fileLength;
    generatedFileName = "kursiokai";
    cout << "Kokio ilgio faila generuoti?" << endl;
    cin >> fileLength;
    while(cin.fail()){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> fileLength;
    }
    generatedFileName += to_string(fileLength) + ".txt";
    //cout << fileLength << endl;
    //cout << generatedFileName << endl;

    cout << "Iveskite kiek pazymiu tures studentai?" << endl;
    cin >> pazymiuKiekis;
    cout << endl;
    while(cin.fail()){
        cout << "Ivedete netinkamus duomenis, bandykite dar karta!" << endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin >> pazymiuKiekis;
    }

    return fileLength;
}

void generateFileData(string generatedFileName, int fileLength, int pazymiuKiekis, double & timeTaken){
    list<string> vardas = {"Petras", "Antanas", "Jonas", "Tomas", "Valdas", "Romas", "Lukas", "Matas", "Virgis", "Mantas", "Kazys"};
    string generatedName;

    list<string> pavarde = {"Petraitis", "Antanaitis", "Jonaitis", "Tomaitis", "Valdaitis", "Romaitis", "Lukaitis", "Mataitis", "Virgaitis", "Mantaitis", "Kazaitis"};
    string generatedSurname;

    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> name(0, vardas.size()-1);
    std::uniform_int_distribution<int> surname(0, pavarde.size()-1);
    std::uniform_int_distribution<int> pazymys(1, 10);

    std::ofstream rf;
    rf.open(generatedFileName);
    string ND;
    int a = 0;
    std::stringstream my_buffer;

    auto start = std::chrono::high_resolution_clock::now();

    //Virsutines eilutes spausdinimas
    my_buffer << std::left << std::setw(15)<< "Vardas" <<
    std::left << std::setw(15) << "Pavarde";
    for(int i = 0; i < pazymiuKiekis; i++){
        ND = "";
        ND += "ND" + to_string(i+1);
        my_buffer << std::setw(10) << ND;
    }
    my_buffer << "Egz.";
    my_buffer << endl;

    //Studentu eilutes spausdinimas
    list<int>::iterator itV;
    list<int>::iterator itP;
    for(int i = 0; i < fileLength; i++){
        auto itV = vardas.begin();
        auto itP = pavarde.begin();
        std::advance(itV, name(mt));
        std::advance(itP, surname(mt));
        generatedName = *itV;
        generatedSurname = *itP;
        my_buffer << std::setw(15) << generatedName
        << std::left << std::setw(15) << generatedSurname;
        for(int j = 0; j < pazymiuKiekis; j++){
           my_buffer << std::setw(10) << pazymys(mt);
        }
        a++;
        my_buffer << pazymys(mt);
        if(a < fileLength)
            my_buffer << endl;
    }
    rf << my_buffer.str();
    my_buffer.str("");
    my_buffer.clear();
    rf.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << fileLength << " eiluciu failo sukurimas uztruko: "<< diff.count() << " s\n";
    timeTaken += diff.count();

    cout << "Failas: " << generatedFileName << " sekmingai sukurtas!" << endl;
}

void atskirti(list<duomenys>& sarasas, list<duomenys>& sarasas2, int fileLength, double &timeTaken){
    auto start = std::chrono::high_resolution_clock::now();

    auto temp = sarasas;
    for(auto &el : sarasas){
        //cout << el.vardas << "    " << el.pavarde << "      " << el.rezult << endl;
        if(el.rezult >= 5){
            sarasas2.push_back(el);
            temp.pop_back();
        }
    }
    sarasas = temp;
    temp.clear();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start; // Skirtumas (s)
    std::cout << fileLength << " eiluciu failo dalijimo i dvi grupes laikas, panaikinant pradini list: "<< diff.count() << " s\n";
    timeTaken += diff.count();
}
