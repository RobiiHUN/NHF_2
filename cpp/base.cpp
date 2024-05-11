#include "../headers/base.hpp"


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


/* ========================================================================== */
//!                                TELEFONKONYV                                */
/* ========================================================================== */
/* ------------------------------ KONSTRUKTOROK ----------------------------- */

Telefonkonyv::Telefonkonyv(): bejegyzesek(nullptr), meret(0){}
Telefonkonyv::Telefonkonyv(size_t size) : bejegyzesek(new Bejegyzes[size]), meret(size) {}
Telefonkonyv::Telefonkonyv(Bejegyzes* b, size_t m) : bejegyzesek(b), meret(m) {}
/* ------------------------------ DESTROKTOROK ------------------------------ */
Telefonkonyv::~Telefonkonyv() {
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
        bejegyzesek[i].bejegyzesKi();
    }
}

/* ---------------------------- FEJLEC KIIRATASA ---------------------------- */



//* -------------------------- EGY BEJEGYZES KIÍRÁSA ------------------------- *//



void Bejegyzes::bejegyzesKi()const{
    int width = 20; // Oszlop szélessége
    std::cout << std::setw(ember.getLenVez()) <<std::left << ember.getVezetek() 
              << std::setw((width - ember.getLenVez())) << std::setfill(' ') << ""

              << std::setw(ember.getLenKer()) <<std::left << ember.getKereszt() 
              << std::setw(width - ember.getLenKer()) << std::setfill(' ') << ""

              << std::setw(ember.getLenBece()) <<std::left << ember.getBece() 
              << std::setw(width - ember.getLenBece()) << std::setfill(' ') << ""

              << std::setw(telefon.getLenSzem()) <<std::left << telefon.getSzemTell() 
              << std::setw(width - telefon.getLenSzem()) << std::setfill(' ') << ""

              << std::setw(std::to_string(varos).length()) <<std::left << varos 
              << std::endl;
}
