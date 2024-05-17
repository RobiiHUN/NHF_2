#include "../headers/ui.hpp"

/* ----------------------------- KIJELZO TORLESE ---------------------------- */

void UI::clearScreen(){std::cout << "\033[2J\033[1;1H"; log("Kijelző törölve!");}

/* ------------------------------- KONSTRUKTOR ------------------------------ */
UI::UI(Telefonkonyv& t):tk(t){menu(); log("UI sikeresen konstruálódott!");}

/* ---------------------------- HEADER KIIRATASA ---------------------------- */
void UI::header(){          //fejlec kiirasa
    log("Header kiirva!");
    clearScreen();    //toroljuk a kepernyot
    std::cout<<"\033[1m"; //félkövér betű
    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "=";
    }
    std::endl(std::cout);
    std::cout << "\033[32m";
    int width = 20; // Oszlop szélessége
    std::cout << std::setw(5) <<std::left << "ID"
              << std::setw(10) <<std::left <<"Vezeteknév" 
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
    if (TESTELES){log("A program TEST módban van. Kérem a log írásához, kapcsolja ki a TESTELES macrót!");return;} //ha a TESTELES makro igaz, akkor nem fut le a menu
    logo();                                             //logo kiirasa 
    log("Program elindult! Normál módban!");           //log fileba iras
    std::cout<<std::endl;            
    std::cout<<std::endl; 

    while (true)                         //menu ciklusa
    {
        /* ========================================================================== */
        /*                                 MENUPONTOK                                 */
        /* ========================================================================== */
        std::cout<<std::endl;            
        std::cout<<std::endl; 

        std::cout << "1. Bejegyzés hozzáadása" << std::endl;
        std::cout << "2. Bejegyzés törlése" << std::endl;
        std::cout << "3. Bejegyzés módosítása" << std::endl;
        std::cout << "4. Bejegyzések listázása" << std::endl;
        std::cout << "5. Keresés" << std::endl;
        std::cout << "6. Factory Reset" << std::endl;
        std::cout << "7. Kilépés" << std::endl;
        std::cout<<std::endl;            
        std::cout<<std::endl; 
        std::cout << "Válasszon menüpontot: (1-7)" << std::endl;


        unsigned int valasztas = bemenetCHECK(1,7);

        switch (valasztas)
        {
        case 1:                 //bejegyzes hozzaadasa
            std::cout << "Bejegyzés hozzáadása" << std::endl;
            bejegyzesBE();
            break;
        case 2:                 //bejegyzes torlese
            std::cout << "Bejegyzés törlése" << std::endl;
            bejegyzesKI();
            break;
        case 3:                //bejegyzes modositasa
            std::cout << "Bejegyzés módosítása" << std::endl;
            bejegyzesMOD();
            
            break;
        case 4:                 //bejegyzes listazasa
            std::cout << "Bejegyzések listázása" << std::endl;
            header();
            tk.kiir();
            break;
        case 5:                 
            std::cout << "Keresés" << std::endl;
            kereses();
            break;
        case 6:                 
            std::cout << "Factory Reset" << std::endl;
            try
            {
                tk.factoryReset("files/source_backup.txt", "files/source.txt");
                std::cout << "Az adatok visszaállítva! Viszlát!" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << "Nem sikerült visszaállítani az adatokat!" << std::endl;
            }
            
            return;
            break;
        case 7:                 //kilepes
            clearScreen();
            clearScreen();
            std::cout << "Viszlát! :)" << std::endl;          
            return;
            break;
        
        }
    }
    
    }


/* -------------------------- BEJEGYZES MODOSITASA -------------------------- */
void UI::bejegyzesMOD(){
    log("Bejegyzés módosítása");
    std::cout << "Kérem adja meg a módosítandó bejegyzés sorszámát: ";
    int sorszam = bemenetCHECK(0, tk.getMeret());
    std::cout << "Kérem adja meg a módosítandó bejegyzés adatait: " << std::endl;
    bejegyzesBE();
    tk.modosit(sorszam - 1, tk.getBejegyzes(tk.getMeret() - 1));
    tk.bejTorles(tk.getMeret() - 1);
    std::cout << "A bejegyzés módosítva!" << std::endl;
    log("Bejegyzés módosítva!");
}

/* --------------------------- BEJEGYZES BEKERESE --------------------------- */

void UI::bejegyzesBE(){
    log("Bejegyzés hozzáadása");
    std::string vezeteknev;
    std::string keresztnev;
    std::string becenev;
    std::string szemelyes;
    std::string ceges;
    std::string irszam;
    std::string havi;
    

    std::cout << "Kérem adja meg a vezetéknevét: ";
    std::cin >> vezeteknev;
    std::cout << std::endl;

    std::cout << "Kérem adja meg a keresztnevét: ";
    std::cin >> keresztnev;
    std::cout << std::endl;

    std::cout << "Kérem adja meg a becenevét: ";
    std::cin >> becenev;
    std::cout << std::endl;

    std::cout << "Kérem adja meg a személyes telefonszámát: ";
    std::cin >> szemelyes;
    std::cout << std::endl;

    std::cout << "Kérem adja meg a céges telefonszámát: ";
    std::cin >> ceges;
    std::cout << std::endl;

    std::cout << "Kérem adja meg az irányítószámát: ";
    std::cin >> irszam;
    std::cout << std::endl;

    std::cout << "Kérem adja meg a havi telefonszamlajat: ";
    std::cin >> havi;
    std::cout << std::endl;

        


    if (vezeteknev.length() > 0 && keresztnev.length() > 0 && becenev.length() > 0 && szemelyes.length() > 0 && ceges.length() > 0 && irszam.length() > 0 && havi.length() > 0)
    {
        Ember ember(vezeteknev, keresztnev, becenev);
        Telefon telefon(std::stol(szemelyes), std::stol(ceges));
        Bejegyzes bejegyzes(ember, telefon, std::stol(irszam), std::stol(havi));
        tk.addBejegyzes(bejegyzes);

    }else
    {
        std::cout << "Hibás bemenet! Kérem próbálja újra később!" << std::endl;
    }
    log("Bejegyzés hozzáadva!");

}


/* ---------------------------- BEJEGYZES TORLESE --------------------------- */
void UI::bejegyzesKI(){
    log("Bejegyzés törlése");

    std::cout << "Kérem adja meg a törlendő bejegyzés sorszámát: ";
    int sorszam = bemenetCHECK(0, tk.getMeret());
    tk.bejTorles(sorszam - 1);
    std::cout << "A bejegyzés törölve!" << std::endl;
    
    log("Bejegyzés törölve!");
}


/* --------------------------- BEMENET ELLENORZES --------------------------- */

int UI::bemenetCHECK(int min, int max){
    log("Bemenet ellenőrzése");
    int valasztas = 0;

    while (true)
    {
        std::cin >> valasztas;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "\x1b[1A\x1b[K";
            std::cout << "Hibás bemenet! Kérem adjon meg egy számot " << min << " és " << max << " között!" << std::endl;

            log("Hibás bemenet!");
        }else if (valasztas < min || valasztas > max)
        {
            std::cout << "\x1b[1A\x1b[K";
            std::cout << "Hibás bemenet! Kérem adjon meg egy számot " << min << " és " << max << " között!" << std::endl;

            log("Hibás bemenet!");
        }else
        {
            log("Bemenet ellenőrizve!");
            return valasztas;
        }
    }
    
    
    
}


/* ------------------------------ LOGO KIIRASA ------------------------------ */

void UI::logo(){
    log("Logo kiirva!");

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

        log("Logo kiirva!");
    }
    else
    {
        log("Logo kiirasa sikertelen! Nem található fájl!");
        std::cout << "Nem sikerult megnyitni a logo fajlt!" << std::endl;
    }
    
    
}       //logo kiirasa


/* ------------------------------ KERESO FUGGVENY ------------------------------ */
void UI::kereses(){
    log("Keresés");
    tk.mentesTelefonkonyv("../files/source.txt");
    std::string keresett_str;
    std::cout << "Kérem adja meg a keresett adatot: ";
    std::cin >> keresett_str;
    Bejegyzes *bej = tk.Telefonykonyvkeres(keresett_str);
    
    if (bej == nullptr){        //TODO ez nem felele meg az OOP-nak
        for (size_t i = 1; i < 7; i++)
        {
            bej = tk.lin_keres(keresett_str, i);
            if (bej != nullptr)
            {
                break;
            }
        }
        
    }
    if(bej != nullptr){
        std::cout << "Szerepel ilyen adat a telefonkonyvben!" << std::endl;
        log("Keresés sikeres!");
        for (size_t i = 0; i < tk.getMeret(); i++)
        {
            if (bej == &tk.getBejegyzes(i))
            {
                header();
                bej->bejegyzesKi(i);
                
            }
        }
        

    }else{
        std::cout << "Nincs találat! :( " << std::endl;
        log("Nincs találat!");
        
       
    }
} 

/* -------------------------------- LOG FILE -------------------------------- */

void UI::log(std::string log){
    try {
        std::ofstream file("files/log.log");
        file << ido() << " ==== "<< log << std::endl;
        file.close();
        } catch (const std::exception& e) {
            std::cerr << e.what() << "Nem sikerült megnyitni a logot!" << std::endl;
       
    }
}

std::string UI::ido(){
    time_t jelenlegi_ido = time(0);
    tm *ltm = localtime(&jelenlegi_ido);
    std::string ido = std::to_string(1900 + ltm->tm_year) + 
        "." + std::to_string(1 + ltm->tm_mon) + "." + std::to_string(ltm->tm_mday) + 
            "-" + std::to_string(ltm->tm_hour) + ":" + std::to_string(ltm->tm_min) + 
                ":" + std::to_string(ltm->tm_sec);
    return ido;
}