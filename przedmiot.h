#ifndef PRZEDMIOT_H_INCLUDED
#define PRZEDMIOT_H_INCLUDED
#include <string>
using namespace std;

class CPrzedmiot
{
private:
    string nazwa;
    int godz;
    string prowadzacy;

public:
    CPrzedmiot();
    virtual~CPrzedmiot();

    void wpiszNazwe(string);
    string wypiszNazwe();

    void wpiszGodz(int);
    int wypiszGodz();

    void wpiszProwadzacego(string);
    string wypiszProwadzacego();

};


#endif // PRZEDMIOT_H_INCLUDED
