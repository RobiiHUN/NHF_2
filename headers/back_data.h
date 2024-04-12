
/* ------------------------------ EZ MEG JO IS ------------------------------ */
class Number{
    int business;
    int personal;

    public:
        Number(): business(203952740), personal(20312821){}    
        int getBusiness()const{return business;}
        int getPersonal()const {return personal;}


};


/* ------------------------- CSAK A TESZT MIATT VAN ------------------------- */
class Date
{
    private:
        int a;
    public:
        Date(): a(10){};
        int getDate()const{return a;}
        
};