#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



#include "headers/base.hpp"
#include "headers/test.hpp"
#include "headers/ui.hpp"







int main(){
        test(); //teszt fuggveny csak akkor tortenik valami, ha a macro.h-ban a TEST makro true-n van
        
        
        
        UI ui; //menu objektum peldanyitasa
        
        ui.menu();



        //ui.header();
        /* ----------------------------- TESTELESHEZ JO ----------------------------- */

char vezeteknev1[] = "Test";
size_t l_vez = 5;
char keresztnev[] = "Kalapacs";
size_t l_ker = 9;
char becenev[] = "Kalad";
size_t l_bece = 5;


        /* -------------------------------------------------------------------------- */

/* option shift a        */



Ember ember(vezeteknev1, l_vez, keresztnev, l_ker, becenev, l_bece);
Ember ember2;
Telefon tf;
Telefon tf2(36203952740, 36401239876);
Bejegyzes bejegyzes;
Bejegyzes bejegy(ember, tf2, 1, 100);

//bejegyzesKi(bejegy);
Telefonkonyv tk;






return 0;
}