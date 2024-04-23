#include <iostream>

#include "headers/base.h"
//#include "headers/back_data.h"


int main(){
        /* ----------------------------- TESTELESHEZ JO ----------------------------- */

Bejegyzes valami;
char vezeteknev1[] = "Test";
size_t l_vez = 5;
char keresztnev[] = "Kalapacs";
size_t l_ker = 9;
char becenev[] = "KALA";
size_t l_bece = 5;

        /* -------------------------------------------------------------------------- */

Ember teszt(vezeteknev1, l_vez, keresztnev, l_ker, becenev, l_bece);            //! ember konstruktor
Telefon teszt2(120121020201, 21);                                               //! telefon konstruktor




header();
Bejegyzes teszt3(teszt, teszt2, 4355, 5000);                               //! bejegyzes konstruktor
bejegyzesKi(teszt3);
bejegyzesKi(valami);


return 0;
}