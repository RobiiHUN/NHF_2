#include "../headers/base.hpp"
//#include <string>   //stringhez
#include <fstream>
#include <sstream>
#include <iostream>
#include "../headers/memtrace.h"




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
std::string Bejegyzes::getVezetek()const{return ember.getVezetek();}                //* visszaadja a vezeteknevet
std::string Bejegyzes::getKereszt()const{return ember.getKereszt();}                //* visszaadja a keresztnevet
std::string Bejegyzes::getBece()const{return ember.getBece();}                      //* visszaadja a becenevet
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
void Bejegyzes::setVezetek(std::string v){ember.setVezetek(v);} //* beallitja a vezeteknevet
void Bejegyzes::setKereszt(std::string k){ember.setKereszt(k);} //* beallitja a keresztnevet
void Bejegyzes::setBece(std::string b){ember.setBece(b);} //* beallitja a becenevet



/* ========================================================================== */
//!                                TELEFONKONYV                                */
/* ========================================================================== */
/* ------------------------------ KONSTRUKTOROK ----------------------------- */

Telefonkonyv::Telefonkonyv(){
    bejegyzesek = new Bejegyzes[0];
    meret = 0;
    try
    {
        feltoltesTelefonkonyv("files/source.txt");
    }
    catch(const std::runtime_error& e)
    {
        
        factoryReset("files/source_backup.txt", "files/source.txt");
        feltoltesTelefonkonyv("files/source.txt");
    }
    
    
    rendez();
    
    
    }


   
/* ------------------------------ DESTROKTOROK ------------------------------ */
Telefonkonyv::~Telefonkonyv() {
    mentesTelefonkonyv("files/source.txt");
    delete[] bejegyzesek;
}


/* -------------------------------- GETTEREK -------------------------------- */
size_t Telefonkonyv::getMeret()const{
    return meret;
}

Bejegyzes &Telefonkonyv::getBejegyzes(int index)const{      
    if (index > meret)
    {
        throw "Ez kicsit sok lesz, nem?";
    }
    return bejegyzesek[index];
}


/* --------------------------- BEJEGYZES HOZZADASA -------------------------- */

void Telefonkonyv::addBejegyzes(const Bejegyzes& bejegyzes) {
    Bejegyzes* uj = new Bejegyzes[meret + 1];
    for (size_t i = 0; i < meret; ++i) {
        uj[i] = bejegyzesek[i];
    }
    uj[meret].setVezetek(bejegyzes.getVezetek());
    uj[meret].setKereszt(bejegyzes.getKereszt());
    uj[meret].setBece(bejegyzes.getBece());
    uj[meret].setSzemTell(bejegyzes.getSzemTell());
    uj[meret].setCegeTell(bejegyzes.getCegeTell());
    uj[meret].setVaros(bejegyzes.getVaros());
    uj[meret].setHavi(bejegyzes.getHavi());
    
    ++meret;
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



void Bejegyzes::bejegyzesKi(int sorszam)const{      //nem dohat exception-t mert mindig csak a max meretig fut
    
    std::cout << "\e[1;34m"; //félkövér, kék betű
    
    
   
    int szelesseg = 20; // Oszlop szélessége
    std::cout 
              << std::setw(5) <<std::left << sorszam
              
              << std::setw(ember.getLenVez()) <<std::left << ember.getVezetek() 
              << std::setw((szelesseg - ember.getLenVez())) << std::setfill(' ') << ""

              << std::setw(ember.getLenKer()) <<std::left << ember.getKereszt() 
              << std::setw(szelesseg - ember.getLenKer()  - 1) << std::setfill(' ') << ""
              <<"\033[0m"

              << std::setw(ember.getLenBece()) <<std::left << ember.getBece() 
              << std::setw(szelesseg - ember.getLenBece()) << std::setfill(' ') << ""

              << "+ "<< std::setw(telefon.getLenSzem()) <<std::left  << telefon.getSzemTell() 
              << std::setw(szelesseg - telefon.getLenSzem()) << std::setfill(' ') << ""

              << "+ "<< std::setw(telefon.getLenCeg()) <<std::left  << telefon.getCegesTell() 
              << std::setw(szelesseg - telefon.getLenCeg()) << std::setfill(' ') << ""

              << std::setw(std::to_string(havi_dij).length()) <<std::left  << havi_dij  << " Ft"
              << std::setw(szelesseg - std::to_string(havi_dij).length() - 3) << std::setfill(' ') << ""

              << std::setw(std::to_string(varos).length()) <<std::left << varos 
              << std::endl;
    std::cout << "\033[90m";
    for (size_t i = 0; i < 140; i++)
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
        if (!fajl.is_open()) {
            throw std::runtime_error("Nem lehet megnyitni a fajlt: " + fajlnev + "\n\n");
        }
        bool hiba = true;
        while (std::getline(fajl, sor)) {
            hiba = false;
            std::stringstream ss(sor);
            std::string vezeteknev_str, keresztnev_str, becenev_str, telefon1, telefon2, irsz, havi_dij;

            std::getline(ss, vezeteknev_str, ';');
            std::getline(ss, keresztnev_str, ';');
            std::getline(ss, becenev_str, ';');
            std::getline(ss, telefon1, ';');
            std::getline(ss, telefon2, ';');
            std::getline(ss, irsz, ';');
            std::getline(ss, havi_dij, ';');

            Ember ember(vezeteknev_str, keresztnev_str, becenev_str);
            Telefon telefon(std::stol(telefon1), std::stol(telefon2));
            Bejegyzes bejegyzes(ember, telefon, std::stol(irsz), std::stol(havi_dij));
            addBejegyzes(bejegyzes);
        }
        if (hiba)
        {
            throw std::runtime_error("A fajl ures: " + fajlnev + "\n\n");
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
    if (index >= meret) {
        std::cerr << "Hibás index: " << index << std::endl;
        return;
    }
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
    
    if (sorszam >= meret) {
        std::cerr << "Hibás sorszám: " << sorszam << std::endl;
        return;
    }
    if (sorszam < meret) {
        bejegyzesek[sorszam] = bejegyzes;
    }
     
}

/* ------------------------------ FACTORY RESET ----------------------------- */

void Telefonkonyv::factoryReset(const std::string& forras, const std::string& cel){


    std::ofstream celFile(cel, std::ios::trunc);
    celFile.close();

    std::ifstream forr(forras, std::ios::binary);
    std::ofstream target(cel, std::ios::binary);

    if (!forr) {
        throw std::runtime_error("Nem lehet megnyitni a fajlt:  " + forras + "\n\n");
    }

    if (!target) {
       throw std::runtime_error("Nem lehet megnyitni a fajlt:  " + cel + "\n\n");
    }

    target << forr.rdbuf();

    forr.close();
    target.close();
    
}

/* -------------------------------- RENDEZES -------------------------------- */

int Telefonkonyv::osszeBej(const Bejegyzes& a, const Bejegyzes& b)const {
    int vezeteknevEredmeny = a.getVezetek().compare(b.getVezetek());
    if (vezeteknevEredmeny != 0) {
        return vezeteknevEredmeny;
    }

    int keresztnevEredmeny = a.getBece().compare(b.getBece());
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
Bejegyzes* Telefonkonyv::Telefonykonyvkeres(std::string vezeteknev) const {
    int bal = 0;
    int jobb = meret - 1;
    while (bal <= jobb) {
        int kozep = bal + (jobb - bal) / 2;
        int eredmeny = vezeteknev.compare(bejegyzesek[kozep].getVezetek());
        if (eredmeny == 0)
            return &bejegyzesek[kozep];
        if (eredmeny < 0)
            jobb = kozep - 1;
        else
            bal = kozep + 1;
    }
    return nullptr;
}

Bejegyzes* Telefonkonyv::lin_keres(std::string keresett, int mod)const{
    for (size_t i = 0; i < meret; i++)
    {
        switch (mod)
        {
        case 1:
            if (keresett == bejegyzesek[i].getKereszt())
            {
                return &bejegyzesek[i];
            }
            break;
        case 2:
            if (keresett == bejegyzesek[i].getBece())
            {
                return &bejegyzesek[i];
            }
            break;
        case 3: 
            try
            {
                unsigned long keres = std::stoul(keresett);
                if (keres == bejegyzesek[i].getSzemTell())
                {
                    return &bejegyzesek[i];
                }
            }
            catch(const std::invalid_argument& e)
            {
                return nullptr;
            }
            
            break;
        case 4:
            try
            {
                unsigned long keres = std::stoul(keresett);
                if (keres == bejegyzesek[i].getSzemTell())
                {
                    return &bejegyzesek[i];
                }
            }
            catch(const std::invalid_argument& e)
            {
                return nullptr;
            }
            
            break;
        case 5:
            try
            {
                unsigned long keres = std::stoul(keresett);
                if (keres == bejegyzesek[i].getSzemTell())
                {
                    return &bejegyzesek[i];
                }
            }
            catch(const std::invalid_argument& e)
            {
                return nullptr;
            }
            
            break;
        case 6:
            try
            {
                unsigned long keres = std::stoul(keresett);
                if (keres == bejegyzesek[i].getSzemTell())
                {
                    return &bejegyzesek[i];
                }
            }
            catch(const std::invalid_argument& e)
            {
                return nullptr;
            }
            
            break;        }
    }
    return nullptr;
}
