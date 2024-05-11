#include "../headers/back_data.hpp"


void clearScreen(){std::cout << "\033[2J\033[1;1H";}

/* ========================================================================== */
//!                                   EMBEREK                                 */
/* ========================================================================== */

/* ------------------------------ KONTRUKTOROK ------------------------------ */

Ember::Ember(): vezeteknev(nullptr), len_vez(0), keresztnev(nullptr), len_kereszt(0),
         becenev(nullptr), len_bece(0){};

Ember::Ember(char *v, size_t lv, char *k, size_t lk, char *b, size_t lb){
            vezeteknev = new char[lv+1];
            strcpy(vezeteknev, v);
            len_vez = lv;

            keresztnev = new char[lk+1];
            strcpy(keresztnev, k);
            len_kereszt = lk;

            becenev = new char[lb+1];
            strcpy(becenev, b);
            len_bece = lb;

}

Ember::Ember(const char* v, size_t lv, const char* k, size_t lk, const char* b, size_t lb) {
            vezeteknev = new char[lv + 1];
            std::strncpy(vezeteknev, v, lv);
            vezeteknev[lv] = '\0';

            keresztnev = new char[lk + 1];
            std::strncpy(keresztnev, k, lk);
            keresztnev[lk] = '\0';

            becenev = new char[lb + 1];
            std::strncpy(becenev, b, lb);
            becenev[lb] = '\0';
        }



Ember::Ember(const Ember& other){
    vezeteknev = new char[other.len_vez+1];
    std::strcpy(vezeteknev, other.vezeteknev);
    len_vez = other.len_vez;

    keresztnev = new char[other.len_kereszt+1];
    std::strcpy(keresztnev, other.keresztnev);
    len_kereszt = other.len_kereszt;

    becenev = new char[other.len_bece+1];
    std::strcpy(becenev, other.becenev);
    len_bece = other.len_bece;
}

Ember& Ember::operator=(const Ember& other){
    if (this == &other) return *this;

    delete[] vezeteknev;
    vezeteknev = new char[other.len_vez+1];
    std::strcpy(vezeteknev, other.vezeteknev);
    len_vez = other.len_vez;

    delete[] keresztnev;
    keresztnev = new char[other.len_kereszt+1];
    std::strcpy(keresztnev, other.keresztnev);
    len_kereszt = other.len_kereszt;

    delete[] becenev;
    becenev = new char[other.len_bece+1];
    std::strcpy(becenev, other.becenev);
    len_bece = other.len_bece;

    return *this;
}


/* ------------------------------- DESTRUKTOR ------------------------------- */
Ember::~Ember(){
    delete[] vezeteknev;
    delete[] keresztnev;
    delete[] becenev;
}

/* -------------------------------- GETTEREK -------------------------------- */

const char* Ember::getVezetek()const{return vezeteknev;}      //* visszaadja a vezeteknevet
const char* Ember::getKereszt()const{return keresztnev;}      //* visszaadja a keresztnevet
const char* Ember::getBece()const{return becenev;}            //* visszaadja a becenevet
size_t Ember::getLenVez()const{return std::strlen(vezeteknev);}         //* visszaadja a vezeteknev hosszat
size_t Ember::getLenKer()const{return std::strlen(keresztnev);}     //* visszaadja a keresztnev hosszat
size_t Ember::getLenBece()const{return std::strlen(becenev);}       //* visszaadja a becenev hosszat

/* -------------------------------- SETTEREK -------------------------------- */
void Ember::setVezetek(const char* v, size_t lv){
    delete[] vezeteknev;
    vezeteknev = new char[lv+1];
    strcpy(vezeteknev, v);
    len_vez = lv;
}
void Ember::setKereszt(const char* k, size_t lk){
    delete[] keresztnev;
    keresztnev = new char[lk+1];
    strcpy(keresztnev, k);
    len_kereszt = lk;
}
void Ember::setBece(const char* b, size_t lb){
    delete[] becenev;
    becenev = new char[lb+1];
    strcpy(becenev, b);
    len_bece = lb;
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