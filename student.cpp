#include "student.h"

CStudent:: CStudent()
{
}
CStudent::~CStudent()
{
}


void CStudent::wpiszImNaz(string ImNazS)
{
    ImNaz=ImNazS;
}
string CStudent::wypiszImNaz()
{
    return(ImNaz);
}

void CStudent::wpiszNrLegit(int NrLegitS)
{
    NrLegit=NrLegitS;
}
int CStudent::wypiszNrLegit()
{
    return(NrLegit);
}
