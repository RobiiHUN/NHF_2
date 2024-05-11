#include "../headers/ui.hpp"

/* ----------------------------- KIJELZO TORLESE ---------------------------- */

void UI::clearScreen(){std::cout << "\033[2J\033[1;1H";}

/* ---------------------------- HEADER KIIRATASA ---------------------------- */
void UI::header(){          //fejlec kiirasa
    clearScreen();    //toroljuk a kepernyot
    std::cout<<"\033[1m"; //félkövér betű
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "=";
    }
    std::endl(std::cout);
    std::cout << "\033[32m";
    int width = 20; // Oszlop szélessége
    std::cout << std::setw(10) <<std::left <<"Vezeteknév" 
              << std::setw(width - 10) << std::setfill(' ') << ""

              << std::setw(11) <<std::left << "Keresztnév" 
              << std::setw(width - 11) << std::setfill(' ') << ""

              << std::setw(7) <<std::left << "Becenév"
              << std::setw(width - 7) << std::setfill(' ') << ""

              << std::setw(14) <<std::left << "Sz.telefonszám"
              << std::setw(width - 14) << std::setfill(' ') << ""

              << std::setw(5) <<std::left << "Város" 
              << std::endl;

    std::cout << "\033[0m";
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "=";
    }
    std::endl(std::cout);

}

/* ------------------------------ MENU KIIRASA ------------------------------ */

void UI::menu(){
    if (TESTELES) return;               //ha a TESTELES makro igaz, akkor nem fut le a menu
    logo();                             //logo kiirasa      
    std::cout<<std::endl;            
    std::cout<<std::endl; 

    std::cout << "1. Bejegyzés hozzáadása" << std::endl;
    std::cout << "2. Bejegyzés törlése" << std::endl;
    std::cout << "3. Bejegyzés módosítása" << std::endl;
    std::cout << "4. Bejegyzések listázása" << std::endl;
    std::cout << "5. Keresés" << std::endl;
    std::cout << "6. Kilépés" << std::endl;
    std::cout<<std::endl;            
    std::cout<<std::endl; 
    std::cout << "Válasszon menüpontot: (1-6)" << std::endl;
    menuPontValasztas();



}

int UI::menuPontValasztas(){
    int valasztas = 0;

    while (true)
    {
        std::cin >> valasztas;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\x1b[1A\x1b[K";
            std::cout << "Hibás bemenet! Kérem adjon meg egy számot 1 és 6 között!" << std::endl;
        }else if (valasztas < 1 || valasztas > 6)
        {
            std::cout << "\x1b[1A\x1b[K";
            std::cout << "Hibás bemenet! Kérem adjon meg egy számot 1 és 6 között!" << std::endl;
        }else
        {
            return valasztas;
        }
    }
    
    
    
}


/* ------------------------------ LOGO KIIRASA ------------------------------ */

void UI::logo(){
    std::ifstream file("files/logo.txt");
    if (file.is_open())
    {
        std::string line;
        std::cout << "\033[32m";
        while (std::getline(file, line))
        {
            std::cout << line << std::endl;
        }
        std::cout << "\033[0m";
        file.close();
    }
    else
    {
        std::cout << "Nem sikerult megnyitni a logo fajlt!" << std::endl;
    }
    
    
}       //logo kiirasa
