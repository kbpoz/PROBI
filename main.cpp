#include <iostream>
#include <cstdlib>
#include "grupa.h"
#include "student.h"
#include "przedmiot.h"
using namespace std;

CGrupa * listaGrup[100];
int liczGrupy=0;

main()
{
    char wyj=0;
	cout << "Witaj w programie F.Kuligowskiego i J.Pozniaka"<<endl;
	cout << "Program do zarzadzania grupami dziekanskimi i studentami"<<endl<<endl;

	char a,b;

	do
{
	cout << "Wybierz opcje: "<<endl;
	cout << "1. Grupa dziekanska\n2. Student\n3. Przedmiot\n\n1,2,3? "<<endl;
	cin >> a;
	cout<<endl;
    if(a!='1' && a!='2' && a!='3')
        {
			cout << "Nie ma takiej komendy!"<<endl;
		}
    else
    {
        cout << "1. Dodaj\n2. Usun\n3. Wyswietl\n4. Edytuj\n\n1,2,3,4? "<<endl;
        cin >> b;
        cout<<endl;

    }
	switch(a)
	{
    case '1':  //GRUPA
    {
        switch(b)
        {
        case '1':   //DODAJ GRUPE
            {
                cout << "Dodawanie grupy dziekanskiej\n" << "Podaj numer grupy: "<<endl;
                CGrupa *ngrupa=new CGrupa;
                listaGrup[liczGrupy]=ngrupa;
                int nrGrupy;
                cin >> nrGrupy;
                listaGrup[liczGrupy]->wpiszNrGrupy(nrGrupy);
                liczGrupy++;

                cout << "Dodano grupe." <<endl;


                break;
            }
        case '2':   //USUN GRUPE
            {
                cout << "Ktora grupe dziekanska chcesz usunac? (podaj indeks grupy)"<<endl;
                int  indeks_gr;
                cin >> indeks_gr;
                if(listaGrup[indeks_gr]->iloscP() > 0)
                {
                listaGrup[indeks_gr]->usunWprzedmiot();
                };
                if(listaGrup[indeks_gr]->ilosc()>0)
                {
                listaGrup[indeks_gr]->usunWstud();
                };
                delete listaGrup[indeks_gr];
                for(int i = indeks_gr; i <= liczGrupy-1; i++ )
                        {
                            listaGrup[i] = listaGrup[i+1];
                        }
                       // delete listaGrup[liczGrupy];
                        liczGrupy--;

                cout << "Usunieto grupe"<<endl;
                break;
            }
        case '3':   //WYSWIETL GRUPE
            {
                cout << "Ktora grupe dziekanska chcesz zobaczyc? (podaj indeks grupy)"<<endl;
                int indeks_gr;
                cin >> indeks_gr;
                system( "cls" );
                cout << "Numer grupy o indeksie: " << indeks_gr << " to: "<< listaGrup[indeks_gr]->wypiszNrGrupy()<<endl;
                int a = listaGrup[indeks_gr]->ilosc();
                cout <<"Studenci w grupie: "<<endl;

                for(int n=0; n<=a-1; n++)
               {
               cout <<n<<". "<<"Imie i nazwisko: "<< listaGrup[indeks_gr]->wypiszImie(n) <<" Numer legitymacji: "<< listaGrup[indeks_gr]->wypiszNr(n) <<endl;
               };

               int b = listaGrup[indeks_gr]->iloscP();
               cout <<"Przedmioty w grupie: "<<endl;

               for(int n=0; n<=b-1; n++)
               {
               cout <<n<<". "<<"Nazwa przedmiotu: "<< listaGrup[indeks_gr]->wypiszNazP(n) <<" Godziny: "<< listaGrup[indeks_gr]->wypiszGodzP(n) <<" Prowadzacy: "<<listaGrup[indeks_gr]->wypiszProP(n) <<endl;
               };

            break;
            }
        case '4':   //EDYTUJ GRUPE
            {
                cout << "Ktora grupe dziekanska chcesz zmienic? (podaj indeks grupy)"<<endl;

                int indeks_gr;
                cin >> indeks_gr;
                cout << "Podaj nowy numer grupy: ";
                int nr_grupy;
                cin >> nr_grupy;
                listaGrup[indeks_gr]->wpiszNrGrupy(nr_grupy);
                cout << "Edytowano grupe"<<endl;

                break;
            }
        break;
        }
    break;
    }
    case '2': //STUDENT
    {
        switch(b)
        {
        case '1': //DODAJ STUDENTA
            {
                cout << "Dodawanie studenta" << endl << "Do ktorej grupy chcesz dodac studenta? (podaj indeks grupy)"<<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ilu studentow chcesz dodac? " << endl;
                int n;
                cin >> n;

                for(int i=1; i<=n; i++)
                {
                system( "cls" );

                cout << "Podaj imie i nazwisko studenta: " << endl;
                string im_naz;
                cin.ignore();
                getline (cin,im_naz);

                cout << "Podaj numer legitymacji studenta: " << endl;
                int nr_legit;
                cin >> nr_legit;

                listaGrup[indeks_gr]->dodajStud(im_naz, nr_legit);
                cout << "Dodano studenta: "<<im_naz<<" do grupy "<<listaGrup[indeks_gr]->wypiszNrGrupy()<< endl;
                }
                break;
            }
        case '2': //USUN STUDENTA
            {
                cout << "Usuwanie studenta" << endl << "Z ktorej grupy chcesz usunac studenta? (podaj indeks grupy)"<<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ktorego studenta chcesz usunac? (podaj indeks studenta)"<<endl;
                int indeks_st;
                cin >> indeks_st;
                listaGrup[indeks_gr]->usunStud(indeks_st);

                cout << "Usunieto studenta"<<endl;
                break;
            }
        case '3': //WYSWIETL STUDENTA
            {
                cout << "Wyswietlanie studenta" << endl << "Studenta ktorej grupy chcesz wyswietlic? (podaj indeks grupy)" <<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ktorego studenta chcesz wyswietlic? (podaj indeks studenta)" <<endl;
                int indeks_st;
                cin >> indeks_st;
                cout << listaGrup[indeks_gr]->wypiszImie(indeks_st) <<endl;
                cout << listaGrup[indeks_gr]->wypiszNr(indeks_st) <<endl;
                break;
            }
        case '4': //EDYTUJ STUDENTA
            {
                cout <<  "Edytowanie studenta" << endl << "Studenta ktorej grupy chcesz edytowac? (podaj indeks grupy)" <<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ktorego studenta chcesz edytowac? (podaj indeks studenta)"<< endl;
                int indeks_st;
                cin >> indeks_st;

                cout << "Podaj imie i nazwisko studenta: " << endl;
                string im_naz;
                cin.ignore();
                getline(cin, im_naz);

                cout << "Podaj nowy numer legitymacji studenta:" <<endl;
                int nr_legit;
                cin >> nr_legit;
                listaGrup[indeks_gr]->zmienStud(indeks_st, im_naz, nr_legit);
                cout << "Edytowano studenta: "<<im_naz<<" z grupy: "<<listaGrup[indeks_gr]->wypiszNrGrupy()<< endl;
                break;
            }
        break;
        }
    break;
    }
    case '3': //PRZEDMIOT
    {
        switch(b)
        {
        case '1':
            {
                cout << "Dodawanie przedmiotu. " <<endl<< "Do ktorej grupy chcesz dodac przedmiot? (podaj indeks grupy)" <<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ile przedmiotow chcesz dodac? "<<endl;
                int n;
                cin >> n;
                cin.ignore();
                for(int i = 1; i<=n; i++)
                    {
                    system( "cls" );
                    cout << "Podaj nazwe przedmiotu: " <<endl;
                    string nazwa_p;
                    getline(cin,nazwa_p);

                    cout << "Podaj liczbe godzin: " <<endl;
                    int godz_p;
                    cin >> godz_p;

                    cout << "Podaj imie i nazwisko prowadzacego przedmiot: " <<endl;
                    string prowadzacy_p;
                    cin.ignore();
                    getline(cin, prowadzacy_p);

                    listaGrup[indeks_gr]->dodajPrzedmiot(godz_p, nazwa_p, prowadzacy_p);

                    cout << "Dodano przedmiot: "<<nazwa_p<<" do grupy " <<listaGrup[indeks_gr]->wypiszNrGrupy() <<endl;
                    }
                break;
            }
        case '2':
            {
                cout << "Usuwanie przedmiotu " <<endl<< "Z ktorej grupy chcesz usunac przedmiot? (podaj indeks grupy)" <<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ktory przedmiot chcesz usunac? (podaj indeks przedmiotu)" <<endl;
                int indeks_p;
                cin >> indeks_p;
                listaGrup[indeks_gr]->usunPrzedmiot(indeks_p);
                cout << "Usunieto przedmiot\n" <<endl;
                break;
            }
        case '3':
            {
                cout << "Wyswietlanie przedmiotu " <<endl<< "Przedmiot z ktorej grupy chcesz wyswietlic? (podaj indeks grupy)" <<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ktory przedmiot chcesz wyswietlic? (podaj indeks przedmiotu)" <<endl;
                int indeks_p;
                cin >> indeks_p;
                cout << "Grupa: "<< listaGrup[indeks_gr]->wypiszNrGrupy() <<endl;
                cout << "Nazwa przedmiotu: "<< listaGrup[indeks_gr]->wypiszNazP(indeks_p)  <<endl;
                cout << "Liczba godzin: "<< listaGrup[indeks_gr]->wypiszGodzP(indeks_p) <<endl;
                cout << "Prowadzacy: "<< listaGrup[indeks_gr]->wypiszProP(indeks_p)  <<endl;

                break;
            }
        case '4':
            {
                cout <<  "Edytowanie przedmiotu " << endl << "Przedmiot z ktorej grupy chcesz edytowac? (podaj indeks grupy)"<<endl;
                int indeks_gr;
                cin >> indeks_gr;

                cout << "Ktory przedmiot chcesz edytowac? (podaj indeks przedmiotu)"<<endl;
                int indeks_p;
                cin >> indeks_p;

                cout << "Podaj nowa nazwe przedmiotu: " <<endl;
                string nazwa_p;
                cin.ignore();
                getline(cin, nazwa_p);

                cout << "Podaj nowa ilosc godzin: " <<endl;
                int godz;
                cin >> godz;

                cout << "Podaj imie i nazwisko nowego prowadzacego: " <<endl;
                string prowadzacy_p;
                cin.ignore();
                getline(cin, prowadzacy_p);
                listaGrup[indeks_gr]->zmienP(indeks_p, godz, nazwa_p, prowadzacy_p);
                cout << "Edytowano przedmiot.\n" <<endl;
                break;
            }
        break;
        }
    break;
    }
    }
    cout << "Czy chcesz opuscic program?\n Tak - nacisnij 't'\n Nie - dowolny klawisz\n";
		cin >> wyj;
    }
    while(wyj!='t');
	return 0;
}

