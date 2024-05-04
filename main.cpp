#include <iostream>
#include <string>
#include <fstream>
#include <sstream>



#include "headers/base.hpp"





int main(){
        /* ----------------------------- TESTELESHEZ JO ----------------------------- */

Bejegyzes valami;
char vezeteknev1[] = "Test";
size_t l_vez = 5;
char keresztnev[] = "Kalapacs";
size_t l_ker = 9;
char becenev[] = "Kala";
size_t l_bece = 5;
Ember ember(vezeteknev1, l_vez, keresztnev, l_ker, becenev, l_bece);


        /* -------------------------------------------------------------------------- */

/* option shift a


std::string vezeteknev2 ;
size_t l_vez2;
std::string keresztnev2;
size_t l_ker2;
std::string becenev2;
size_t l_bece2;
unsigned long int szemelyes;
unsigned long int ceges;
unsigned int varos;
unsigned int havi_dij;


std::ifstream file("files/source.txt");
std::string line;
header();

while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string vezeteknev2, keresztnev2, becenev2;
    unsigned long int szemelyes, ceges;
    unsigned int varos, havi_dij;

    std::getline(iss, vezeteknev2, ';');
    std::getline(iss, keresztnev2, ';');
    std::getline(iss, becenev2, ';');
    iss >> szemelyes;
    iss.ignore(); // ';' karakter átugrása
    iss >> ceges;
    iss.ignore(); // ';' karakter átugrása
    iss >> varos;
    iss.ignore(); // ';' karakter átugrása
    iss >> havi_dij;

    Ember ember2(vezeteknev2, vezeteknev2.length(), keresztnev2, keresztnev2.length(), becenev2, becenev2.length());
    Telefon telefon(szemelyes, ceges);
    Bejegyzes bejegyzes(ember2, telefon, varos, havi_dij); 
    bejegyzesKi(bejegyzes);    

   
}  //*/
//feltoltesTelefonkonyv("files/source.txt");
Telefon tf;
Bejegyzes bejegy(ember, tf, 1, 100);
header();
bejegyzesKi(bejegy);
Telefonkonyv tk;
//header();
//tk.addBejegyzes(valami);
//tk.feltoltesTelefonkonyv("files/source.txt");
//tk.kiir();



return 0;
}