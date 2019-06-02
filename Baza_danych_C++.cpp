//Patryk Murawski  Code::Blocks 13.12, GNU GCC Compiler

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdio>
#include <vector>
#include<cstdlib>
#include <sstream>

using namespace std;
const int MAX_M = 20;
const int MAX_P = 50;
const int MAX_W = 100;

struct osoba
{
	char imie[MAX_M + 1];
	char nazwisko[MAX_M + 1];
	int  indeks;
	char e_mail[MAX_M + 1];
};
struct projekt
{
	int  indeks;
	int projekt;
	string data;

};

struct uwagi
{
	int indeks;
	string komentarz;
	string data;
};
//____DODAWANIE ___>>>>>>>>>>>>>>>>>>>>>>>>>>
void dodaj_osobe(osoba *P[], projekt *R[], uwagi *S[], int &n)
{   system("cls");
	cout << "  DODAWANIE OSOBY  " << endl;
	P[n] = new osoba;
	R[n] = new projekt;
    S[n] = new uwagi;
	cout << "Imie: ";
	cin >> P[n]->imie;
	cout << "Nazwisko: ";
	cin >> P[n]->nazwisko;
	cout << "Indeks: ";
	cin >> P[n]->indeks;


	if (n>0)
	{
		for (int i = 0; i<n; i++)
		{
			if (P[n]->indeks == P[i]->indeks)
			{
				while (P[n]->indeks == P[i]->indeks)
				{
					cout << "BLEDNY INDEKS !" << endl << "OSOBA O DANYM INDEKSIE JUZ ISTNIEJE" << endl;
					cout << "WPISZ POPRAWNY NR INDEKSY !!! ";
					cin >> P[n]->indeks;
					i = 0;
				}
			}
		}
	};
        R[n]->indeks=P[n]->indeks;
        S[n]->indeks=P[n]->indeks;

	cout << "e_mail: ";
	cin >> P[n]->e_mail;
	n++;
}


void dodaj_projekt(projekt *R[], int &n)
{
    time_t czas;
    time( & czas );
    string data,zmiana;
   data= ctime( & czas );

    int nr,id,indeks;
    string time;
    cout<<"PODAJ INDEKS STUDENTA:"<<endl;
    cin>>indeks;

    int kontrola = 0;
    if(n!=0)
    {

        for (int i=0; i<n; i++)
		{
			if (indeks == R[i]->indeks)
            {
                id=i;
                kontrola = 1;
                break;
            }
		};
    }
    if(kontrola==0){
    	cout << "ZLE CIECIU" << endl;
    	dodaj_projekt(R,n);
	}

	else if(kontrola==1){

  	cout<<"PODAJ NUMER PROJEKTU :";
	cin>>nr;
	while(nr != 1 and nr!=2)
        {
            cout<< "PODAJ WLASCIWY NR";
            cin>> nr;

        }
    R[id]->projekt=nr;
    R[id]->data=data;

for(int i=0;i<n;i++)
{
    if(R[i]->projekt !=1 and R[i]->projekt!=2)
    {
        R[i]->projekt=0;
         zmiana="NIE PRZESLANO";
        R[i]->data=zmiana;
    }
}

};

}





void dodaj_uwage(uwagi *S[], int &n)
{
    time_t czas;
    time( & czas );
    string data,notka;
    data= ctime( & czas );
    int nr,id,indeks;
    cout<<"PODAJ INDEKS STUDENTA:"<<endl;
    cin>>indeks;
    		for (int i = 0; i<n; i++)
		{
			if (indeks== S[i]->indeks)
			{
                id=i;
			}
		};

cout<<"DODAJ KOMENTARZ: "<<endl;
cin.ignore(); // czyszczenia "bufora"
getline (cin,notka);// pobieranie calej lini do notki
S[id]->komentarz=notka;

S[id]->data=data;
system("PAUSE");


}

//____DODAWANIE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//____WYPISYWANIE >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void wypisz_osoby(osoba *P[], const int &n)
{
	system("cls");
	if (n != 0)
	{
		cout << "NR"<<setw(15)<<"IMIE" << setw(15) << "NAZWISKO" << setw(15) << "INDEKS" << setw(20) << "E_MAIL" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i << setw(15) << P[i]->imie << setw(15) << P[i]->nazwisko << setw(15) << P[i]->indeks << setw(20) << P[i]->e_mail  << endl;
		}
	}
	else
		cout << "Brak osob w bazie" << endl;
}
void wypisz_projekty( projekt *R[], const int &n)
{
	system("cls");
	if (n != 0)
	{cout << "NR"<<setw(15)<<"INDEKS" << setw(15) << "PROJEKT " << setw(40) << "DATA PRZESLANIA PROJEKTU " <<endl;

        for (int i = 0; i < n; i++)
		{
			if(R[i]->projekt==1 or R[i]->projekt==2)
            {
            cout << i << setw(15) << R[i]->indeks << setw(15) << R[i]->projekt << setw(40) << R[i]->data<< endl;
            }
		};
    }
	else
    {
        cout << "Brak projektów w bazie" << endl;
    }

}

void wypisz_uwagi( uwagi *S[], const int &n)
{

	if (n != 0)
	{
		cout << "NR"<<setw(15)<<"INDEKS" << setw(40) << "DATA " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i << setw(15) << S[i]->indeks << setw(40) << S[i]->data<<endl;
			cout<<endl<<"           KOMENTARZ        "<<endl;
			cout<<setw(5)<<S[i]->komentarz<<endl;
		}
	}
	else
		cout << "Brak komentarzy w bazie" << endl;
}
//______WYPISYWANIE <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


//______EDYCJA >>>>>>>>>>>>>>>>>
void edytuj_osobe(osoba *P[], const int &n)
{   system("cls");
	int nr, edycja;
	wypisz_osoby(P,n);
	cout << "PODAJ NR OSOBY " << endl;
	cin >> nr;
	cout <<"IMIE" << setw(15) << "NAZWISKO" << setw(15) << "INDEKS" << setw(20) << "E_MAIL" << endl;
    cout << P[nr]->imie << setw(15) << P[nr]->nazwisko << setw(15) << P[nr]->indeks << setw(20) << P[nr]->e_mail  << endl;
	cout << "EDYTUJ" << endl << "Imie ---> 1" << endl << "Nazwisko ---> 2" << endl << "Indeks ---> 3" << endl << "E_mail ---> 4" << endl;
	cout<<"PODAJ NR: "<<endl;
	cin >> edycja;
	if (edycja == 1)
	{
		cout << "Imie: ";
		cin >> P[nr]->imie;
	}
	else if (edycja == 2)
	{
		cout << "Nazwisko: ";
		cin >> P[nr]->nazwisko;
	}
	else if (edycja == 3)
	{
		cout << "Indeks: ";
		cin >> P[nr]->indeks;

if (n>0)
	{
		for (int i = 0; i<n; i++)
		{
			if (P[nr]->indeks == P[i]->indeks)
			{
				while (P[nr]->indeks != P[i]->indeks)
				{
					cout << endl<<"BLEDNY INDEKS !" << endl << "OSOBA O DANYM INDEKSIE JUZ ISTNIEJE" << endl;
					cout << "WPISZ POPRAWNY NR INDEKSY !!! "<<endl;
                    cout << "Indeks: ";
					cin >> P[nr]->indeks;

					i = 0;
				}

			}
		}


	};
	}
	else if (edycja == 4)
	{
		cout << "e_mail: ";
		cin >> P[nr]->e_mail;
	}
	else
	{
	}

}


void edytuj_projekt(projekt *R[], const int &n)
{   system("cls");
	int nr, edycja,x;
	string data,zmiana;
	wypisz_projekty(R,n);
	cout << "PODAJ NR  " << endl;
	cin >> nr;
	while(nr>=n)
    {
       cout<<" BLEDNY NR "<<endl;
           cin>>nr;

    }
    cout <<setw(15) <<"INDEKS" << setw(15) << "PROJEKT " << setw(40) << "DATA PRZESLANIA PROJEKTU  " << endl;
	cout <<setw(15)<< R[nr]->indeks << setw(15) << R[nr]->projekt << setw(40) << R[nr]->data << endl;
	cout << "EDYTUJ" << endl << "PROJEKT  ----> 1" << endl << "DATA PRZESLANIA PROJEKTU  ---> 2" << endl;
	cout<<endl<<"WYBIERZ OPCJE: "<<endl;
	cin >> edycja;
	if (edycja == 1)
	{
		cout <<endl<< "PROJEKT  "<<endl<<"PRZESLANY ---> 1 "<<endl<<"NIE PRZESLANY --->0 "<<endl;
		cin >> x;

		while(x != 1 and x != 0)
        {
            cout<< "PODAJ WLASCIWY NR";
            cin>>x;
        }
        R[nr]->projekt=x;
    }
	else if (edycja == 2)
	{
    cout << "DATA: "<<endl;
    cin.ignore();
    getline (cin,data);
    R[nr]->data=data;
	}
	else
	{
	}

}



void edytuj_komentarz(uwagi *S[], const int &n)
{
    system("cls");
	int nr;
	string notka;
	wypisz_uwagi(S,n);
	cout << "PODAJ NR  " << endl;
	cin >> nr;
    cout<<"DODAJ KOMENTARZ: "<<endl;
cin>>notka;

S[nr]->komentarz=notka;
}



//_______EDYCJA <<<<<<<<<<<<<<<<<

//________ZAPIS >>>>>>>>>>>>>>>>
void zapisz_osoby(osoba *P[], int &n,string nazwa)
{


    string nazwa_pliku,nazwa_tmp;
    nazwa_tmp="_osoby.txt";
    nazwa_pliku=nazwa+nazwa_tmp;
	fstream plik(nazwa_pliku.c_str(), ios::out);
	if (plik.good())
	{
		for (int i = 0; i < n; i++)
		{
			plik << P[i]->imie << setw(15) << P[i]->nazwisko << setw(15) << P[i]->indeks << setw(15) << P[i]->e_mail << endl;
		}
		plik.close();
	}
	else
		cout << "error";
}


void zapisz_projekty(projekt *R[],  int &n,string nazwa)
{


    string nazwa_pliku,nazwa_tmp;
    nazwa_tmp="_projekty.txt";
    nazwa_pliku=nazwa+nazwa_tmp;;
	fstream plik(nazwa_pliku.c_str(), ios::out);
	if (plik.good())
	{
		for (int i = 0; i < n; i++)
		{

			plik << R[i]->indeks << setw(15) << R[i]->projekt << setw(40) << R[i]->data<<endl;
		}
		plik.close();
	}
	else
		cout << "error";
}

void zapisz_komentarze(uwagi *S[],  int &n,string nazwa)
{


	string nazwa_pliku,nazwa_tmp;
    nazwa_tmp="_komentarze.txt";
    nazwa_pliku=nazwa+nazwa_tmp;

	fstream plik(nazwa_pliku.c_str(), ios::out);
	if (plik.good())
	{
		for (int i = 0; i < n; i++)
		{

			plik << S[i]->indeks << endl<<S[i]->data<<endl<<S[i]->komentarz << endl;
		}
		plik.close();
	}
	else
		cout << "error";
}
//_______ZAPIS <<<<<<<<<<<<<<<<<<<<<<<<<<<


// __________WCZYTAJ>>>>>>>>>>>>>>>>>>>
void wczytaj_osoby(osoba *P[], int &n,string nazwa)
{


char imie[MAX_M + 1];
char nazwisko[MAX_M + 1];
int  indeks;
char e_mail[MAX_M + 1];

int i = 0;
string nazwa_pliku,nazwa_tmp;
nazwa_tmp="_osoby.txt";
nazwa_pliku=nazwa+nazwa_tmp;


ifstream plik;
    plik.open( nazwa_pliku.c_str() );
    while( true ) //pêtla nieskoñczona
    {

        plik >> imie>> nazwisko >>indeks>>e_mail;
        if( plik.good() )
         {

            P[i] = new osoba;

		strcpy(P[i]->imie, imie);
		strcpy(P[i]->nazwisko, nazwisko);
		P[i]->indeks =indeks;
		strcpy(P[i]->e_mail,e_mail);
		i++;}
        else
             break; //zakoñcz wczytywanie danych - wyst¹pi³ jakiœ b³¹d (np. nie ma wiêcej danych w pliku)

    }

n = i;
plik.close();
}
void wczytaj_projekty( projekt *R[], int &n,string nazwa)
{


int projekts;

int  indeks;
string a,b,c,d,e,calosc,s;
s=" ";

int i = 0;
    string nazwa_pliku,nazwa_tmp;
    nazwa_tmp="_projekty.txt";
    nazwa_pliku=nazwa+nazwa_tmp;;

ifstream plik;
    plik.open(nazwa_pliku.c_str());
    while(  true ) //pêtla nieskoñczona
    {
        plik >> indeks>> projekts >>a>>b>>c>>d>>e;
        if( plik.good() )
         {

            R[i] = new projekt;

		R[i]->indeks =indeks;
		R[i]->projekt =projekts;
		calosc=a+s+b+s+c+s+d;
		R[i]->data=calosc;
		i++;
		}
        else
             break; //zakoñcz wczytywanie danych - wyst¹pi³ jakiœ b³¹d (np. nie ma wiêcej danych w pliku)

    }

n = i;
plik.close();
}
void wczytaj_komentarze( uwagi *S[], int &n,string nazwa)
{
ifstream pliks;
int k=0;
int i=0;
int l;
string nazwa_pliku,nazwa_tmp;
nazwa_tmp="_komentarze.txt";
nazwa_pliku=nazwa+nazwa_tmp;
string linia;

pliks.open (nazwa_pliku.c_str(),ios::in);

	while (true) //pobieranie calej lini i zapisywanie do wektora
	{

	    getline( pliks, linia );
	     if( pliks.good() )
         {

	     if(k==0)
        {   int w = atoi(linia.c_str());

           S[i] = new uwagi;
           S[i]->indeks = w;

        }
        else if(k==1)
        {
           S[i]->data =linia;
        }
         else if(k==3)
        {
           S[i]->komentarz =linia;
           k=-1;
           i++;
        }
            k++;
		}
        else
           {
               break; //zakoñcz wczytywanie danych - wyst¹pi³ jakiœ b³¹d (np. nie ma wiêcej danych w pliku)
           }
    };
    n = i;
	pliks.close();
}


//_________WCZYTAJ<<<<<<<<<<<<<<
void szukaj(osoba *P[], int &n)
{    system("cls");
	int indeks, szukaj;
	string nazwisko;
	cout << endl << "SZUKAJ PO " << endl<<"INDEKSIE ---> 1"<<endl<<"NAZWISKU ---> 2"<<endl;
	cin >> szukaj;


switch( szukaj)
{
case 1:
cout<<"PODAJ NR INDEKSU :"<<endl;
cin>>indeks;
for (int i = 0; i < n; i++)
	{
		if (P[i]->indeks == indeks)
		{
			cout << P[i]->imie << setw(10) << P[i]->nazwisko << setw(10) << P[i]->indeks << setw(10) << P[i]->e_mail << endl;
        }
	}
break;

    case 2:
   cout<<"PODAJ NAZWISKO :"<<endl;
  cin.ignore();
getline (cin,nazwisko);
for (int i = 0; i < n; i++)
	{   string pomoc;
	pomoc=P[i]->nazwisko;
		if (pomoc == nazwisko.c_str())
		{
			cout << P[i]->imie << setw(10) << P[i]->nazwisko << setw(10) << P[i]->indeks << setw(10) << P[i]->e_mail << endl;
		}
	}
    break;
default:
    system("cls");
    break;
}
}


//___USUN>>>>>>>>>>>>>
void usun_projekt( projekt *R[], int &n)
{
     system("cls");
	int nr, x;
	wypisz_projekty(R,n);
	cout << "PODAJ NR OSOBY " << endl;
	cin >> nr;
	for (int i = nr; i<n; i++)
	{
	    if(nr!=n)
		{
		    R[i]=R[i+1];
		}
		else
        {
            // osoba nie zostala usunieta lecz pominieta w wyswietlaniu i innych operacjach z powodu wyjscia po za tablice
        }
	};

	n--;

}

void usun_komentarze( uwagi *S[], int &n)
{
     system("cls");
	int nr, x;
	wypisz_uwagi(S,n);
	cout << "PODAJ NR OSOBY " << endl;
	cin >> nr;
	for (int i = nr; i<n; i++)
	{
	    if(nr!=n)
		{
		    S[i]=S[i+1];
		}
		else
        {
            // osoba nie zostala usunieta lecz pominieta w wyswietlaniu i innych operacjach z powodu wyjscia po za tablice
        }
	};

	n--;

}


void usun_osobe(osoba *P[], projekt *R[], uwagi *S[], int &n)
{
     system("cls");
	int nr, x;
	wypisz_osoby(P,n);
	cout << "PODAJ NR OSOBY " << endl;
	cin >> nr;
	for (int i = nr; i<n; i++)
	{
	    if(nr!=n)
		{
		    P[i]=P[i+1];
		}
		else
        {
            // osoba nie zostala usunieta lecz pominieta w wyswietlaniu i innych operacjach z powodu wyjscia po za tablice
        }
	};

	n--;

}
//    USUN<<<<<<<<<<<<
//_______MENU____

void osoby(osoba *P[], projekt *R[], uwagi *S[], int &n)
{
int x;

		cout << endl << "WYBIERZ:" << endl << "DODAJ  ---> 1  " << endl << "WYPISZ --->   2" << endl << "EDYTUJ -->   3" << endl << "USUN --->   4" << endl<<"SZUKAJ PO INDEKSIE LUB NAZWISKU   --->"<< endl << "WROC --->   0" <<  endl ;
		cin >> x;

			switch( x )
{
    case 1:
dodaj_osobe(P,R,S,n);
    break;
    case 2:
wypisz_osoby(P,n);
    break;
     case 3:
edytuj_osobe(P,n);
    break;
     case 4:
usun_osobe(P,R,S,n);
    break;
    case 5:
szukaj(P,n);
    break;


default:
system("cls");
    break;
}
	}


	void projekty(projekt *R[], int &n)
{
    int x;

	cout << endl << "WYBIERZ:" << endl << "DODAJ  ---> 1  " << endl << "WYPISZ --->   2" << endl << "EDYTUJ -->   3" << endl << "USUN --->   4" <<  endl << "WROC --->   0" <<  endl ;
		cin >> x;


			switch( x )
{
    case 1:
dodaj_projekt(R,n);
    break;

    case 2:
wypisz_projekty(R,n);

    break;
     case 3:
edytuj_projekt(R,n);

    break;
     case 4:
usun_projekt(R,n);;
    break;
default:
    system("cls");
    break;
}
}
	void uwaga(uwagi *S[], int &n)
{
    int x;

			cout << endl << "WYBIERZ:" << endl << "DODAJ  ---> 1  " << endl << "WYPISZ --->   2" << endl << "EDYTUJ -->   3" << endl << "USUN --->   4" <<  endl<< "WROC --->   0" <<  endl ;
		cin >> x;

			switch( x )
{
    case 1:
dodaj_uwage(S,n);
    break;

    case 2:
wypisz_uwagi(S,n);
    break;
     case 3:
edytuj_komentarz(S,n);
    break;
     case 4:
usun_komentarze(S,n);
    break;
default:
    system("cls");
    break;
}}

void odczyt_zapis(osoba *P[], projekt *R[], uwagi *S[], int &n);
void menu(osoba *P[], projekt *R[], uwagi *S[], int &n,int &petla)
{
    int opcja;
    cout << endl << "WYBIERZ:" << endl << "OSOBY --->   1  " << endl << "PROJEKTY --->   2" << endl << "KOMENTARZE --->   3"<<endl<< endl << "ODCZYT / ZAPIS --->   4"<<endl<< "ZAMKNIJ --->   0"<<endl;;
    cin>>opcja;
    switch( opcja )
{case 0:
    petla=0;

    break;

case 1:
 osoby(P,R,S,n);
    break;

case 2:
projekty(R,n);
    break;
case 3:
uwaga(S,n);
    break;
    case 4:
odczyt_zapis(P,R,S,n);
    break;
default:
    menu(P,R,S,n,petla);
    break;
}
}

void odczyt_zapis(osoba *P[], projekt *R[], uwagi *S[], int &n)
{
    int opcja;
    string nazwa;
    cout << endl << "WYBIERZ:" << endl << "WCZYTAJ --->   1  " << endl << "ZAPISZ --->   2" << endl ;
    cin>>opcja;
       switch( opcja )
{
case 1:

    cout<<"PODAJ NAZWE GRUPY "<<endl;
    cin>>nazwa;
  wczytaj_projekty(R,n,nazwa);
   wczytaj_komentarze(S,n,nazwa);
    wczytaj_osoby(P,n,nazwa);
    break;

case 2:
     cout<<"PODAJ NAZWE GRUPY "<<endl;
    cin>>nazwa;
 zapisz_osoby(P,n,nazwa);
  zapisz_komentarze(S,n,nazwa);
   zapisz_projekty(R,n,nazwa);
    break;

default:

   system("cls");
    break;
}
 menu(P,R,S,n,opcja);

}
//________MENU_______




int main()
{

	int petla=-1,n = 0;

	osoba	*P[MAX_P];
	projekt *R[MAX_P];
	uwagi	*S[MAX_P];
while(petla!=0)
{
    menu(P,R,S,n,petla);
}

	return 0;
}
