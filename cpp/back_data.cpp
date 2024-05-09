#include "../headers/back_data.hpp"


void clearScreen(){std::cout << "\033[2J\033[1;1H";}

/* ========================================================================== */
//!                                   EMBEREK                                 */
/* ========================================================================== */

/* ------------------------------ KONTRUKTOROK ------------------------------ */

Ember::Ember(): vezeteknev("N/A"), len_vez(3), keresztnev("N/A"), len_kereszt(3), becenev("N/A"), len_bece(3){};

Ember::Ember(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb): 
                vezeteknev(v), len_vez(lv), keresztnev(k), 
                    len_kereszt(lk), becenev(b), len_bece(lb){ //*konstruktor parameterekkel
                    }


Ember::Ember(const std::string& v, size_t lv, const std::string& k, size_t lk, const std::string& b, size_t lb): //*konstruktor parameterekkel es stringkezelessel
                vezeteknev(v.c_str()), len_vez(lv), keresztnev(k.c_str()), len_kereszt(lk), becenev(b.c_str()), len_bece(lb){
            }


/* ------------------------------- DESTRUKTOR ------------------------------- */
Ember::~Ember(){}

/* -------------------------------- GETTEREK -------------------------------- */
const char* Ember::getVezetek()const{return vezeteknev;}      //* visszaadja a vezeteknevet
const char* Ember::getKereszt()const{return keresztnev;}      //* visszaadja a keresztnevet
const char* Ember::getBece()const{return becenev;}            //* visszaadja a becenevet
size_t Ember::getLenVez()const{return len_vez;}         //* visszaadja a vezeteknev hosszat
size_t Ember::getLenKer()const{return len_kereszt;}     //* visszaadja a keresztnev hosszat
size_t Ember::getLenBece()const{return len_bece;}       //* visszaadja a becenev hosszat



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