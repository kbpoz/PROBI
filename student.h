#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>
using namespace std;

class CStudent
{
private:
    string ImNaz;
    int NrLegit;

public:
    CStudent();
    virtual~CStudent();

    void wpiszImNaz(string);
    string wypiszImNaz();

    void wpiszNrLegit(int);
    int wypiszNrLegit();

};


#endif // STUDENT_H_INCLUDED
