#include "../headers/base.hpp"
#include <string>   //stringhez
#include <fstream>
#include <sstream>
#include <iostream>



/* ========================================================================== */
/*                                  BEJEGYZES                                 */
/* ========================================================================== */

/* ------------------------------ KONSTRUKTOROK ----------------------------- */

Bejegyzes::Bejegyzes():ember(), telefon(),  varos(0), havi_dij(0){}

Bejegyzes::Bejegyzes(const Ember& e, const Telefon& t,  unsigned int v, unsigned int h):
                ember(e),telefon(t),  varos(v), havi_dij(h){
                    }

/* ------------------------------ DESTROKTOROK ------------------------------ */
Bejegyzes::~Bejegyzes(){}

/* -------------------------------- GETTEREK -------------------------------- */
unsigned int Bejegyzes::getVaros()const{return varos;}                              //* visszaadja a varos iranyito szamat
unsigned int Bejegyzes::getHavi() const{return havi_dij;}                           //* visszaadja a havi dijjat
unsigned long int Bejegyzes::getSzemTell()const{return telefon.getSzemTell();}      //* visszaadja a szemelyes telefonszamot
unsigned long int Bejegyzes::getCegeTell()const{return telefon.getCegesTell();}     //* visszaadja a ceges telefonszamot
const char* Bejegyzes::getVezetek()const{return ember.getVezetek();}                //* visszaadja a vezeteknevet
const char* Bejegyzes::getKereszt()const{return ember.getKereszt();}                //* visszaadja a keresztnevet
const char* Bejegyzes::getBece()const{return ember.getBece();}                      //* visszaadja a becenevet
size_t Bejegyzes::getLenVez()const{return ember.getLenVez();}                       //* visszaadja a vezeteknev hosszat
size_t Bejegyzes::getLenKer()const{return ember.getLenKer();}                       //* visszaadja a keresztnev hosszat
size_t Bejegyzes::getLenBece()const{return ember.getLenBece();}                     //* visszaadja a becenev hosszat
size_t Bejegyzes::getLenSzem()const{return telefon.getLenSzem();}                   //* visszaadja a szemelyes telefonszam hosszat
size_t Bejegyzes::getLenCeg()const{return telefon.getLenCeg();}                     //* visszaadja a ceges telefonszam hosszat
size_t Bejegyzes::getLenVar()const{return std::to_string(varos).length();}          //* visszaadja a varos iranyito szam hosszat

/* -------------------------------- SETTEREK -------------------------------- */
void Bejegyzes::setVaros(unsigned int v){varos = v;}   //* beallitja a varos iranyito szamat
void Bejegyzes::setHavi(unsigned int h){havi_dij = h;} //* beallitja a havi dijjat
void Bejegyzes::setSzemTell(unsigned long int sz){telefon.setSzemTell(sz);} //* beallitja a szemelyes telefonszamot
void Bejegyzes::setCegeTell(unsigned long int ce){telefon.setCegesTell(ce);} //* beallitja a ceges telefonszamot
void Bejegyzes::setVezetek(const char* v, size_t lv){ember.setVezetek(v, lv);} //* beallitja a vezeteknevet
void Bejegyzes::setKereszt(const char* k, size_t lk){ember.setKereszt(k, lk);} //* beallitja a keresztnevet
void Bejegyzes::setBece(const char* b, size_t lb){ember.setBece(b, lb);} //* beallitja a becenevet



/* ========================================================================== */
//!                                TELEFONKONYV                                */
/* ========================================================================== */
/* ------------------------------ KONSTRUKTOROK ----------------------------- */

Telefonkonyv::Telefonkonyv(): bejegyzesek(nullptr), meret(0){
    feltoltesTelefonkonyv("files/source.txt");
    rendez();
    //rendezKerNev();
    }
Telefonkonyv::Telefonkonyv(size_t size) : bejegyzesek(new Bejegyzes[size]), meret(size) {
    feltoltesTelefonkonyv("files/source.txt");
    rendez();
    //rendezKerNev();
    }
Telefonkonyv::Telefonkonyv(Bejegyzes* b, size_t m) : bejegyzesek(b), meret(m) {
    feltoltesTelefonkonyv("files/source.txt");
    rendez();
    //rendezKerNev();
    }
/* ------------------------------ DESTROKTOROK ------------------------------ */
Telefonkonyv::~Telefonkonyv() {
    mentesTelefonkonyv("files/source.txt");
    delete[] bejegyzesek;
}
/* ------------------------------- MASOLO CTOR ------------------------------ */
Telefonkonyv::Telefonkonyv(const Telefonkonyv& other) : bejegyzesek(new Bejegyzes[other.meret]), meret(other.meret) {
    for (size_t i = 0; i < meret; ++i) {
        bejegyzesek[i] = other.bejegyzesek[i];
    }
}

/* -------------------------------- GETTEREK -------------------------------- */
size_t Telefonkonyv::getMeret()const{
    return meret;
}


/* --------------------------- EGYENLOSEG OPERATOR -------------------------- */
Telefonkonyv& Telefonkonyv::operator=(const Telefonkonyv& other) {
    if (this != &other) {
        delete[] bejegyzesek;
        meret = other.meret;
        bejegyzesek = new Bejegyzes[meret];
        for (size_t i = 0; i < meret; ++i) {
            bejegyzesek[i] = other.bejegyzesek[i];
        }
    }
    return *this;
}

/* --------------------------- BEJEGYZES HOZZADASA -------------------------- */


void Telefonkonyv::addBejegyzes(const Bejegyzes& bejegyzes) { //bejegyzes hozzaadasa a telefonkonyvhez
       //ha a tomb tele van
         
        Bejegyzes* uj = new Bejegyzes[meret + 1]; 
        for (size_t i = 0; i < meret; ++i) {
            uj[i] = bejegyzesek[i];
        }
         
        uj[meret].setVezetek(bejegyzes.getVezetek(), bejegyzes.getLenVez());
        uj[meret].setKereszt(bejegyzes.getKereszt(), bejegyzes.getLenKer());
        uj[meret].setBece(bejegyzes.getBece(), bejegyzes.getLenBece());
        uj[meret].setSzemTell(bejegyzes.getSzemTell());
        uj[meret].setCegeTell(bejegyzes.getCegeTell());
        uj[meret].setVaros(bejegyzes.getVaros());
        uj[meret].setHavi(bejegyzes.getHavi());
        meret++;
        delete[] bejegyzesek; 
        bejegyzesek = uj;
                  
    
}




/* ------------------------------- KIIRATAS -------------------------------- */

void Telefonkonyv::kiir() const { 
    for (size_t i = 0; i < meret; i++) {
        bejegyzesek[i].bejegyzesKi(i + 1);
        
    }
}


//* -------------------------- EGY BEJEGYZES KIÍRÁSA ------------------------- *//



void Bejegyzes::bejegyzesKi(int sorszam)const{
    
    std::cout << "\e[1;34m"; //félkövér, kék betű
    
    
   
    int width = 20; // Oszlop szélessége
    std::cout 
              << std::setw(5) <<std::left << sorszam
              
              << std::setw(ember.getLenVez()) <<std::left << ember.getVezetek() 
              << std::setw((width - ember.getLenVez())) << std::setfill(' ') << ""

              << std::setw(ember.getLenKer()) <<std::left << ember.getKereszt() 
              << std::setw(width - ember.getLenKer()  - 1) << std::setfill(' ') << ""
              <<"\033[0m"

              << std::setw(ember.getLenBece()) <<std::left << ember.getBece() 
              << std::setw(width - ember.getLenBece()) << std::setfill(' ') << ""

              << "+ "<< std::setw(telefon.getLenSzem()) <<std::left  << telefon.getSzemTell() 
              << std::setw(width - telefon.getLenSzem() - 2) << std::setfill(' ') << ""

              << std::setw(std::to_string(varos).length()) <<std::left << varos 
              << std::endl;
    std::cout << "\033[90m";
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "-";
    }
    std::cout << "\033[0m";
    std::endl(std::cout);         
}


/* -------------------- TELEFONKONYV FELTOLTESE A FAJLBOL ------------------- */

void Telefonkonyv::feltoltesTelefonkonyv(const std::string& fajlnev) {
    std::ifstream fajl(fajlnev);
    std::string sor;

    while (std::getline(fajl, sor)) {
        std::stringstream ss(sor);
        std::string vezeteknev_str, keresztnev_str, becenev_str, telefon1, telefon2, irsz, jovedelem;

        std::getline(ss, vezeteknev_str, ';');
        std::getline(ss, keresztnev_str, ';');
        std::getline(ss, becenev_str, ';');
        std::getline(ss, telefon1, ';');
        std::getline(ss, telefon2, ';');
        std::getline(ss, irsz, ';');
        std::getline(ss, jovedelem, ';');

        const char* vezeteknev = vezeteknev_str.c_str();
        const char* keresztnev = keresztnev_str.c_str();
        const char* becenev = becenev_str.c_str();



        Ember ember(vezeteknev,vezeteknev_str.length(), keresztnev, keresztnev_str.length(), becenev,
            becenev_str.length());
        Telefon telefon(std::stol(telefon1), std::stol(telefon2));
        Bejegyzes bejegyzes(ember, telefon, std::stol(irsz), std::stol(jovedelem));
        addBejegyzes(bejegyzes);
    }
    
}

/* ------------------------ TELEFONKONYV KIIRASA FAJLBA ----------------------- */
void Telefonkonyv::mentesTelefonkonyv(const std::string& fajlnev) const {
    std::ofstream fajl(fajlnev);
    for (size_t i = 0; i < meret; ++i) {
        fajl << bejegyzesek[i].getVezetek() << ";"
             << bejegyzesek[i].getKereszt() << ";"
             << bejegyzesek[i].getBece() << ";"
             << bejegyzesek[i].getSzemTell() << ";"
             << bejegyzesek[i].getCegeTell() << ";"
             << bejegyzesek[i].getVaros() << ";"
             << bejegyzesek[i].getHavi() << std::endl;
    }
}

/* ---------------------------- BEJEGYZES TORLESE --------------------------- */
void Telefonkonyv::bejTorles(size_t index) {
    if (index < meret) {
        Bejegyzes* uj = new Bejegyzes[meret - 1];
        for (size_t i = 0; i < index; ++i) {
            uj[i] = bejegyzesek[i];
        }
        for (size_t i = index + 1; i < meret; ++i) {
            uj[i - 1] = bejegyzesek[i];
        }
        --meret;
        delete[] bejegyzesek;
        bejegyzesek = uj;
    }
}

/* -------------------------- BEJEGYZES MODOSITASA -------------------------- */
void Telefonkonyv::modosit(size_t sorszam, const Bejegyzes bejegyzes) {
    if (sorszam < meret) {
        bejegyzesek[sorszam] = bejegyzes;
    }
     
}

void Telefonkonyv::factoryReset(const std::string& forras, const std::string& cel){
    std::ifstream forr(forras, std::ios::binary);
    std::ofstream target(cel, std::ios::binary);

    if (!forr) {
        std::cerr << "Nem lehet megnyitni a fajlt:  " << forras << std::endl;
        return;
    }

    if (!target) {
        std::cerr << "Nem lehet megnyitni a fajlt:  " << cel << std::endl;
        return;
    }

    target << forr.rdbuf();

    forr.close();
    target.close();
    
}

/* -------------------------------- RENDEZES -------------------------------- */

int Telefonkonyv::osszeBej(const Bejegyzes& a, const Bejegyzes& b)const {
    int vezeteknevEredmeny = strcmp(a.getVezetek(), b.getVezetek());
    if (vezeteknevEredmeny != 0) {
        return vezeteknevEredmeny;
    }

    int keresztnevEredmeny = strcmp(a.getKereszt(), b.getKereszt());
    if (keresztnevEredmeny != 0) {
        return keresztnevEredmeny;
    }

    if (a.getVaros() < b.getVaros()) {
        return b.getVaros();
    }else{
        return a.getVaros();
    }
}


void Telefonkonyv::rendez(){
    for (size_t i = 0; i < meret - 1; ++i) {
        for (size_t j = i + 1; j < meret; ++j) {
            if (osszeBej(bejegyzesek[i], bejegyzesek[j]) > 0) {
                Bejegyzes tmp = bejegyzesek[i];
                bejegyzesek[i] = bejegyzesek[j];
                bejegyzesek[j] = tmp;
            }
        }
    }

}

/* -------------------------------- KERESO -------------------------------- */

Bejegyzes* Telefonkonyv::Telefonykonyvkeres(const char* vezeteknev){
   int bal = 0;
    int jobb = meret - 1;
    while (bal <= jobb) {
        int kozep = bal + (jobb - bal) / 2;
        int eredmeny = strcmp(bejegyzesek[kozep].getVezetek(), vezeteknev);
        if (eredmeny == 0)
            return &bejegyzesek[kozep];
        if (eredmeny < 0)
            bal = kozep + 1;
        else
            jobb = kozep - 1;
    }
    return nullptr; 
}

