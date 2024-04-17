#include <iostream>

#include "headers/base.h"
//#include "headers/back_data.h"


int main(){
        /* ----------------------------- TESTELESHEZ JO ----------------------------- */

Ember emb;
char vezeteknev[] = "Test";
size_t l_vez = 5;
char keresztnev[] = "Kalapacs";
size_t l_ker = 9;
char becenev[] = "KALA";
size_t l_bece = 5;

        /* -------------------------------------------------------------------------- */


//Ember test;
//Ember teszt(vezeteknev, l_vez, keresztnev, l_ker, becenev, l_bece);
//Telefon teszt(vezeteknev, l_vez, keresztnev, l_ker, becenev, l_bece, 120121020201, 21);
//Telefon teszt;
//Bejegyzes be(1, 32);
Bejegyzes teszt;
Bejegyzes nane(vezeteknev, l_vez, keresztnev, l_ker, becenev, l_bece, 120121020201, 012321, 4355, 5000);
//std::cout<< teszt.getVezetek() <<" " <<teszt.getKereszt() <<" " <<   teszt.getSzemTell() <<std::endl;
//std::cout << teszt.getSzemTell();
bejegyzesKi(nane);


return 0;
}