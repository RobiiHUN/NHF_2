#ifndef UI_HPP
#define UI_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "macro.h"
#include "base.hpp"

class UI{
    Telefonkonyv tk;

    public:
        UI():tk(){menu();}
        UI(Telefonkonyv t):tk(t){menu();}
        
        void clearScreen();
        void header();
        void logo();
        void menu();
        int bemenetCHECK(int, int);
        void bejegyzesBE();

        //TODO sourve fájl frissitese
        //TODO ID sorszám adása a bejegyzéseknek
        //TODO torles
        //TODO modositas
        //TODO kereses


};

#endif
