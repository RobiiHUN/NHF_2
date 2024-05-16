#include "../headers/back_data.hpp"


void clearScreen(){std::cout << "\033[2J\033[1;1H";}

/* ========================================================================== */
//!                                   EMBEREK                                 */
/* ========================================================================== */

/* ------------------------------ KONTRUKTOROK ------------------------------ */

Ember::Ember():vezeteknev(), keresztnev(), becenev(){};

Ember::Ember(std::string *v, std::string *k, std::string *b){
    vezeteknev = *v;
    keresztnev = *k;
    becenev = *b;
}


Ember::Ember(std::string v, std::string k, std::string b){
    vezeteknev = v;
    keresztnev = k;
    becenev = b;
}


Ember::Ember(const Ember& other){
    becenev = other.getBece();
    keresztnev = other.getKereszt();
    vezeteknev = other.getVezetek();
    
}

Ember& Ember::operator=(const Ember& other){
    if(this == &other) return *this;
    becenev = other.getBece();
    keresztnev = other.getKereszt();
    vezeteknev = other.getVezetek();
    return *this;
}


/* ------------------------------- DESTRUKTOR ------------------------------- */
Ember::~Ember(){}

/* -------------------------------- GETTEREK -------------------------------- */

std::string Ember::getVezetek()const{return vezeteknev;}      //* visszaadja a vezeteknevet
std::string Ember::getKereszt()const{return keresztnev;}      //* visszaadja a keresztnevet
std::string Ember::getBece()const{return becenev;}            //* visszaadja a becenevet
size_t Ember::getLenVez()const{return vezeteknev.length();}         //* visszaadja a vezeteknev hosszat
size_t Ember::getLenKer()const{return keresztnev.length();}     //* visszaadja a keresztnev hosszat
size_t Ember::getLenBece()const{return becenev.length();}       //* visszaadja a becenev hosszat

/* -------------------------------- SETTEREK -------------------------------- */
void Ember::setVezetek(std::string v){
    vezeteknev.assign(v);
}
void Ember::setKereszt(std::string k){
    keresztnev.assign(k);
}
void Ember::setBece(std::string b){
    becenev.assign(b);
}



/* ========================================================================== */
//!                                   TELEFON                                 */
/* ========================================================================== */



/* ------------------------------ KONTRUKTOROK ------------------------------ */

Telefon::Telefon(){szemelyes = 100;business = 0;}   //*konstruktor parameter nelkul
Telefon::Telefon(unsigned long int sz, unsigned long int bu): szemelyes(sz), business(bu){          //*konstruktor parameterekkel
                }



/* ------------------------------- DESTRUKTOR ------------------------------- */
Telefon::~Telefon(){}

/* -------------------------------- GETTEREK -------------------------------- */
unsigned long int Telefon::getSzemTell()const{return szemelyes;}     //* visszaadja a szemelyes telefonszamot
unsigned long int Telefon::getCegesTell()const{return business;}   //* visszaadja a ceges telefonszamot
size_t Telefon::getLenSzem()const{return std::to_string(szemelyes).length();} //* visszaadja a szemelyes telefonszam hosszat
size_t Telefon::getLenCeg()const{return std::to_string(business).length();}   //* visszaadja a ceges telefonszam hosszat