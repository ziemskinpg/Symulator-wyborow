#include <iostream>

using namespace std;

int glosy[10]; //max 9 kandydatów

int numer=1;

class wyborca
{
private:
    int numer_pop_kandydata;
    int plec; // 1-mezczyzna, 0-kobieta
public:
    wyborca();
    friend void zliczanie_glosow();
};

class kandydat
{
private:
    char* imie;
    char* nazwisko;
    int numer_kandydata;
public:
    kandydat();
    ~kandydat();
    friend void wyswietl_kandydatow();
};


kandydat::kandydat()
{
    imie = new char[20];
    cout << "Podaj imie: " << endl;
    cin >> imie;
    nazwisko = new char[20];
    cout << "Podaj nazwisko: " << endl;
    cin >> nazwisko;
    numer_kandydata=numer;
    numer++;
}

kandydat::~kandydat()
{
    if(imie!=NULL) delete[] imie;
    if(nazwisko!=NULL) delete[] nazwisko;
    numer--;
}

void wyswietl_kandydatow()
{
    // do napisania
}

wyborca::wyborca()
{
    cout << "Podaj swoja plec: (1-M, 0-K)";
    cin >> plec;
    cout << "Ktorego kandydata popierasz?" << endl;
    wyswietl_kandydatow();
    cin >> numer_pop_kandydata;
    if(numer_pop_kandydata>9 || numer_pop_kandydata<1){
             cout << "Chyba sie pomyliles!" << endl;
             glosy[0]++;
    }
    else glosy[numer_pop_kandydata]++;
}

void zliczanie_glosow()
{
    int suma_wazne=0;
    float poparcie;
    for(int i=1;i<10;i++)
        suma_wazne+=glosy[i];
    for(int j=1;j<10;j++)
    {
        poparcie=glosy[j]/suma_wazne * 100;
        cout << "Poparcie dla kandydata o numerze" << j << "wynosi: " << poparcie << "%." << endl;
    }
    cout << "Glosow niewaznych bylo " << (glosy[0]/(suma_wazne+glosy[0]))*100 << "%." << endl;
}

int main()
{
    kandydat A,B,C;
    wyborca a,b,c;
    zliczanie_glosow();
}
