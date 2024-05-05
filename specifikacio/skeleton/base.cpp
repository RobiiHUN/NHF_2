#include "base.hpp"


/* ========================================================================== */
/*                                  BEJEGYZES                                 */
/* ========================================================================== */

/* ------------------------------ KONSTRUKTOROK ----------------------------- */

Bejegyzes::Bejegyzes(): telefon(), ember(), varos(0), havi_dij(0){
    if (DEBUG) std::cout<<"Bejegyzes ctor"<<std::endl;
}

Bejegyzes::Bejegyzes(const Ember& e, const Telefon& t,  unsigned int v, unsigned int h):
                telefon(t), ember(e), varos(v), havi_dij(h){
                    if (DEBUG) std::cout<<"Bejegyzes param ctor"<<std::endl;}

/* ------------------------------ DESTROKTOROK ------------------------------ */
Bejegyzes::~Bejegyzes(){if (DEBUG) std::cout<<"Bejegyzes dtor"<<std::endl;}

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


/* ========================================================================== */
//!                                TELEFONKONYV                                */
/* ========================================================================== */
/* ------------------------------ KONSTRUKTOROK ----------------------------- */

Telefonkonyv::Telefonkonyv(): bejegyzesek(), meret(0){
    if (DEBUG) std::cout<<"Telefonkonyv ctor"<<std::endl;
}
Telefonkonyv::Telefonkonyv(size_t size) : bejegyzesek(new Bejegyzes[size]), meret(size) {
            if (DEBUG) std::cout << "Telefonkonyv param ctor" << std::endl;
        }
Telefonkonyv::Telefonkonyv(Bejegyzes* b, size_t m) : bejegyzesek(b), meret(m) {
            if (DEBUG) std::cout << "Telefonkonyv param ctor" << std::endl;
        }
/* ------------------------------ DESTROKTOROK ------------------------------ */
Telefonkonyv::~Telefonkonyv() {
    if (DEBUG) std::cout << "Telefonkonyv dtor" << std::endl;
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
            if (meret == 0) {
                bejegyzesek = new Bejegyzes[1];
                meret = 1;
            } else {
                Bejegyzes* temp = new Bejegyzes[meret + 1];
                for (size_t i = 0; i < meret; ++i) {
                    temp[i] = bejegyzesek[i];
                    
                }
                delete[] bejegyzesek;
                bejegyzesek = temp;
                ++meret;
            }
            bejegyzesek[meret - 1] = bejegyzes;
        }


/* ------------------------------- KIIRATAS -------------------------------- */

void Telefonkonyv::kiir() const { 
    header();
    for (size_t i = 0; i < meret; ++i) {
        bejegyzesKi(bejegyzesek[i]);
    }
}

/* ---------------------------- FEJLEC KIIRATASA ---------------------------- */

void header(){          //fejlec kiirasa
    clearScreen();    //toroljuk a kepernyot
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "=";
    }
    std::endl(std::cout);
    
    int width = 20; // Oszlop szélessége
    std::cout << std::setw(10) <<std::left <<"Vezeteknév" 
              << std::setw(width - 10) << std::setfill(' ') << ""

              << std::setw(11) <<std::left << "Keresztnév" 
              << std::setw(width - 11) << std::setfill(' ') << ""

              << std::setw(7) <<std::left << "Becenév"
              << std::setw(width - 7) << std::setfill(' ') << ""

              << std::setw(14) <<std::left << "Sz.telefonszám"
              << std::setw(width - 14) << std::setfill(' ') << ""

              << std::setw(5) <<std::left << "Város" 
              << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "=";
    }
    std::endl(std::cout);
}

//* -------------------------- EGY BEJEGYZES KIÍRÁSA ------------------------- *//


void bejegyzesKi(Bejegyzes& be){        //bejegyzes kiirasa
    header();
    int width = 20; // Oszlop szélessége
    std::cout << std::setw(be.getLenVez()) <<std::left <<be.getVezetek() 
              << std::setw((width - be.getLenVez())) << std::setfill(' ') << ""

              << std::setw(be.getLenKer()) <<std::left << be.getKereszt() 
              << std::setw(width - be.getLenKer()) << std::setfill(' ') << ""

              << std::setw(be.getLenBece()) <<std::left << be.getBece() 
              << std::setw(width - be.getLenBece()) << std::setfill(' ') << ""

              << std::setw(be.getLenSzem()) <<std::left << be.getSzemTell() 
              << std::setw(width - be.getLenSzem()) << std::setfill(' ') << ""

              << std::setw(be.getLenVar()) <<std::left << be.getVaros() 
              << std::endl;
}
