#include "mix.h"
#include "functions.h"

void mix(std::string read_vardas, std::string write_vardas, vector<duomenys>& sarasas){
  std::vector<std::string> splited;
  std::string eil;
  //----------------------------------------------------------------------
  auto start = std::chrono::high_resolution_clock::now();
  auto st=start;
    std::ifstream open_f(read_vardas);
    while (open_f){
      if (!open_f.eof()) {
          std::getline(open_f, eil);
          //cout << eil << endl;
          splited.push_back(eil);}
      else break;
    }
    open_f.close();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> diff = end-start; // Skirtumas (s)
  std::cout << "Failo nuskaitymas tiesiai į eilučių vektorių užtruko: "<< diff.count() << " s\n";

//  start = std::chrono::high_resolution_clock::now();
//    std::string outputas="";
//    for (std::string &a: splited) (a.compare(*splited.rbegin()) !=0) ? outputas+=a+"\n": outputas+=a;
//    //cout << outputas << endl;
//  diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
//  std::cout << "Eilučių vektoriaus konvertavimas į vieną eilutę užtruko: "<< diff.count() << " s\n";
//
//  start = std::chrono::high_resolution_clock::now();
//    std::ofstream out_f(write_vardas);
//    out_f << outputas;
//    out_f.close();
//  end = std::chrono::high_resolution_clock::now();
//  diff = end-start; // Skirtumas (s)
//  std::cout << "Failo įrašymas per vieną eilutę užtruko: "<< diff.count() << " s\n";
//
//  diff = std::chrono::high_resolution_clock::now()-st; // Skirtumas (s)
//  std::cout << "Visas sugaištas laikas: "<< diff.count() << " s\n\n";

  int KiekTarpu = 0;
  for(auto el : splited)
  {
        for(int i = 0; i < el.length(); i++)
        {
            if(i != el.length()-1){
                //cout << "symb " << el.at(i) << " symb+1 " << el.at(i+1) << endl;
                if((el.at(i) == ' ') && (el.at(i+1) != ' ')){
                    KiekTarpu++;
                }
            }
        }
        break;
  }
  //cout << a-3 << endl;
  stringstream ss;

  duomenys tempTemp;
  duomenys temp;

  int pazymys, kiek = 1, kiekPazymiu = KiekTarpu-2;
  string vardas, pavarde;

  for(auto &eilute: splited){
    if(kiek == 1)
    {
        ss << eilute;
        ss >> vardas >> pavarde;
        for(int i = 0; i < kiekPazymiu; i++)
            ss >> vardas;
        ss >> vardas;
        kiek = 0;
    }
    else
    {
        ss.clear();
        tempTemp = temp;
        ss << eilute;
        ss >> tempTemp.vardas >> tempTemp.pavarde;
        //cout << tempTemp.vardas << " " << tempTemp.pavarde << endl;
        for(int i = 0; i < kiekPazymiu; i++)
        {
            ss >> pazymys;
            tempTemp.paz.push_back(pazymys);
        }
        tempTemp.kiekPaz = kiekPazymiu;
        ss >> pazymys;
        tempTemp.egz = pazymys;
        skaiciuoti(tempTemp);
        sarasas.push_back(tempTemp);
   }
//  cout << splited.at(1) << endl;
//  ss << splited.at(1);
//  string vardas, pavarde;
//  vector<int> paz;
//  int pazymys;
//  ss >> vardas >> pavarde >> pazymys;
//  temp.vardas = vardas;
//  temp.pavarde = pavarde;
//  cout << temp.vardas << endl;
//  cout << temp.pavarde << endl;
//  cout << pazymys << endl;
  }
}
