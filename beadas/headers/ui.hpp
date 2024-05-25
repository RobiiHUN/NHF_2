#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "macro.h"
#include "base.hpp"

class UI{
    Telefonkonyv& tk;

    public:
        
        UI(Telefonkonyv& t);
        
        void clearScreen();
        void header();
        void logo();
        void menu();
        int bemenetCHECK(int, int);
        void bejegyzesBE();     //bejegyzes hozzaadasa
        void bejegyzesKI();     //bejegyzes torlese
        void bejegyzesMOD();    //bejegyzes modositasa
        void kereses();         //kereses
        void log(std::string); //log fileba iras
        std::string ido();           //visszaadja a pontos időt másodpercig
       


        
        



};

#endif
