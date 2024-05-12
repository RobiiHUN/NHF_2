#include <iostream>
#include <string>




#include "headers/base.hpp"
#include "headers/test.hpp"
#include "headers/ui.hpp"
#include "headers/search_tree.hpp"







int main(){
        test(); //teszt fuggveny csak akkor tortenik valami, ha a macro.h-ban a TEST makro true-n van
        
        
        
        UI ui; //menu objektum peldanyitasa
        //ui.menu();



        
        /* ----------------------------- TESTELESHEZ JO ----------------------------- */

char vezeteknev1[] = "Teszt";
size_t l_vez = 5;
char keresztnev[] = "Kalapacs";
size_t l_ker = 9;
char becenev[] = "Kala";
size_t l_bece = 5;

char vezeteknev2[] = "Tezzt";
size_t l_vez2 = 5;
char keresztnev2[] = "Kalapacc";
size_t l_ker2 = 9;
char becenev2[] = "Kalas";
size_t l_bece2 = 5;


        /* -------------------------------------------------------------------------- */

/* option shift a        */



Ember ember(vezeteknev1, l_vez, keresztnev, l_ker, becenev, l_bece);
Telefon tf2(36203952740, 36401239876);
Bejegyzes bejegy(ember, tf2, 1, 655);

Ember ember2(vezeteknev2, l_vez2, keresztnev2, l_ker2, becenev2, l_bece2);
Telefon tf3(36203952745, 36401239878);
Bejegyzes bejegy2(ember2, tf3, 3455, 625);




Telefonkonyv tk;
tk.feltoltesTelefonkonyv("files/source.txt");
ui.header();               //!tökéletesen működik
tk.kiir();                //!tökéletesen működik
//ui.menu();              //!tökéletesen működik


tk.feltoltFa();
std::cout << "Kereses: " << std::endl;
std::cout << tk.keresesFa("Peter") << std::endl;














return 0;
}