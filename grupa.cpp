#include "grupa.h"

CGrupa:: CGrupa()
{
    liczStudent=0;
	liczPrzedmiot=0;
}
CGrupa::~CGrupa()
{
}

void CGrupa::wpiszNrGrupy(int nGrupy)
    {
    nrGrupy=nGrupy;
    }

int CGrupa::wypiszNrGrupy()
    {
        return(nrGrupy);
    }

//STUDENT
    void CGrupa::dodajStud(string ImNazS,int NrLegitS)
    {
                CStudent*nStudent=new CStudent;
                listaStudent[liczStudent]=nStudent;
                listaStudent[liczStudent]->wpiszImNaz(ImNazS);
                listaStudent[liczStudent]->wpiszNrLegit(NrLegitS);
                liczStudent++;
    }

    string CGrupa::wypiszImie(int indeks)
    {
        string a;
        a=listaStudent[indeks]->wypiszImNaz();
        return a;
    }

    int CGrupa::wypiszNr(int indeks)
    {
        int a;
        a=listaStudent[indeks]->wypiszNrLegit();
        return a;
    }

    void CGrupa::zmienStud(int indeks, string ImNazS,int NrLegitS)
    {
        listaStudent[indeks]->wpiszImNaz(ImNazS);
        listaStudent[indeks]->wpiszNrLegit(NrLegitS);
    }

    int CGrupa::ilosc()
    {   int a=0;
        a=liczStudent;
        return a;
    }

    int CGrupa::iloscP()
    {   int a=0;
        a=liczPrzedmiot;
        return a;
    }

    void CGrupa::usunStud(int indeks)
    {
        delete listaStudent[indeks];
        for(int i = indeks; i <= liczStudent-1; i++)
        {
        listaStudent[i]=listaStudent[i+1];
        }
        //delete listaStudent[liczStudent];
        liczStudent--;
    }

    void CGrupa::usunWstud()
    {
            for(int i = 0; i <= liczStudent; i++)
            {
            delete listaStudent[i];
            }

    }


//PRZEDMIOT
    void CGrupa::dodajPrzedmiot(int godzP,string nazwaP,string prowadzacyP)
    {
                CPrzedmiot*nPrzedmiot=new CPrzedmiot;
                listaPrzedmiot[liczPrzedmiot]=nPrzedmiot;
                listaPrzedmiot[liczPrzedmiot]->wpiszNazwe(nazwaP);
                listaPrzedmiot[liczPrzedmiot]->wpiszGodz(godzP);
                listaPrzedmiot[liczPrzedmiot]->wpiszProwadzacego(prowadzacyP);
                liczPrzedmiot++;
    }

    string CGrupa::wypiszNazP(int indeks)
    {
        string a;
        a=listaPrzedmiot[indeks]->wypiszNazwe();
        return a;
    }

    int CGrupa::wypiszGodzP(int indeks)
    {
        int a;
        a=listaPrzedmiot[indeks]->wypiszGodz();
        return a;
    }

    string CGrupa::wypiszProP(int indeks)
    {
        string a;
        a=listaPrzedmiot[indeks]->wypiszProwadzacego();
        return a;
    }

    void CGrupa::zmienP(int indeks, int godzP, string nazwaP, string prowadzacyP)
    {
                listaPrzedmiot[indeks]->wpiszNazwe(nazwaP);
                listaPrzedmiot[indeks]->wpiszGodz(godzP);
                listaPrzedmiot[indeks]->wpiszProwadzacego(prowadzacyP);
    }

    void CGrupa::usunPrzedmiot(int indeks)
        {
            delete listaPrzedmiot[indeks];

            for(int i = indeks; i <= liczPrzedmiot-1; i++)
            {
            listaPrzedmiot[i]=listaPrzedmiot[i+1];
            }
            //delete listaPrzedmiot[liczPrzedmiot];
            liczPrzedmiot--;
        }

    void CGrupa::usunWprzedmiot()
        {
            for(int i = 0; i <= liczPrzedmiot; i++)
            {
            delete listaPrzedmiot[i];
            }

        }
