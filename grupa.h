#ifndef GRUPA_H_INCLUDED
#define GRUPA_H_INCLUDED
#include "student.h"
#include "przedmiot.h"
#include <string>
using namespace std;

class CGrupa
{
private:
    CStudent *listaStudent[30];
    CPrzedmiot *listaPrzedmiot[20];
    int nrGrupy;
    int liczStudent;
    int liczPrzedmiot;

public:
    CGrupa();
    virtual~CGrupa();

    void wpiszNrGrupy(int);
    int wypiszNrGrupy();

    void dodajStud(string,int);
    string wypiszImie(int);
    int wypiszNr(int);
    void usunStud(int);
    void usunWstud();
    void zmienStud(int, string, int);
    int ilosc();

                        void dodajPrzedmiot(int, string, string);
                        string wypiszNazP(int);
                        int wypiszGodzP(int);
                        string wypiszProP(int);
                        void zmienP(int, int, string, string);
                        void usunPrzedmiot(int);
                        void usunWprzedmiot();
                        int iloscP();


};


#endif // GRUPA_H_INCLUDED
