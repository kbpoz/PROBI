#include "przedmiot.h"


CPrzedmiot:: CPrzedmiot()
{
}
CPrzedmiot::~CPrzedmiot()
{
}

void CPrzedmiot::wpiszNazwe(string nazwaP)
{
    nazwa=nazwaP;
}
string CPrzedmiot::wypiszNazwe()
{
    return(nazwa);
}

void CPrzedmiot::wpiszProwadzacego(string prowadzacyP)
{
    prowadzacy=prowadzacyP;
}
string CPrzedmiot::wypiszProwadzacego()
{
    return(prowadzacy);
}

void CPrzedmiot::wpiszGodz(int godzP)
{
    godz=godzP;
}
int CPrzedmiot::wypiszGodz()
{
    return(godz);
}
