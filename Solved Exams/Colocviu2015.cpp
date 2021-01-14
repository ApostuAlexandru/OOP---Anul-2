#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Produs{

private:
    string numeProdus;
    string unitMas;
public:

    Produs() ;

    Produs(string numeProdus, string unitMas);

    Produs(const Produs &p);

    Produs operator=(const Produs &);

    friend ostream& operator<< (ostream &, const Produs &);

    friend istream& operator>> (istream &, Produs &);

    ~Produs() {}; // nu am nimic de dezalocat

    string getMasura() { return unitMas; }

    string getNume() { return numeProdus; }

};

//----------CONSTRUCTORI--------------

Produs::Produs() {

    numeProdus = "N/A";
    unitMas = "N/A";
}

Produs::Produs(string numeProdus, string unitMas) {

    this -> numeProdus = numeProdus;
    this -> unitMas = unitMas;
}

Produs::Produs(const Produs &p) {

    this -> numeProdus = p.numeProdus;
    this -> unitMas = p.unitMas;
}

//----------- = --------------


Produs Produs::operator=(const Produs &p) {

    if ( this != &p ) {
        //if ( numeProdus != NULL )
            //delete[] numeProdus;
    this -> numeProdus = p.numeProdus;
    this -> unitMas = p.unitMas;
    }
}

//-----------IO--------------

istream& operator>>(istream &in, Produs& b){

    cout << "Nume produs: ";
    in >> b.numeProdus;
    cout << "Unitate Masura: ";
    in >> b.unitMas;
return in;
}

ostream& operator<<(ostream &out, Produs& p){
    out << p.getNume();
return out;
}

// ---------------------------

class InterfacePrice {

public:

    virtual void calculeazaPretFinal() = 0;
};

// ---------------------------

class Lot : public InterfacePrice {

private:
    // const int id; // unic
    char* dataLot;
    Produs p;
    float pretPeUnitate;
    int procentReducere;
    int cantitate;
public:

    Lot() ;

    Lot(char* dataLot , Produs p , float pretPeUnitate, int procentReducere, int cantitate);

    Lot(const Lot &);

    Lot operator=(const Lot &);

    friend istream& operator>>(istream&, Lot&);

    friend ostream& operator<<(ostream&, Lot&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    void calculeazaPretFinal() { cout<<"Pretul final este de "<< procentReducere * pretPeUnitate / 100; } // functia din interfata

    Produs getProdus() { return p; }

    ~Lot();

};

//----------CONSTRUCTORI--------------

Lot::Lot() {

    dataLot = new char[strlen("N/A")+1];
        strcpy(dataLot , "N/A");
    pretPeUnitate = 0;
    procentReducere = 0;
    cantitate = 0;
}

Lot::Lot(char* dataLot , Produs p , float pretPeUnitate, int procentReducere, int cantitate) {

    this -> dataLot = new char[strlen(dataLot)+1];
        strcpy(this -> dataLot , dataLot);
    this -> p = p; // Am supraincarcat = deci pot zice this p = p;
    this -> pretPeUnitate = pretPeUnitate;
    this -> procentReducere = procentReducere;
    this -> cantitate = cantitate;
}

Lot::Lot (const Lot &p) {

    this -> dataLot = new char[strlen(p.dataLot)+1];
        strcpy(this -> dataLot , p.dataLot);

    this -> p = p.p;
    this -> pretPeUnitate = p.pretPeUnitate;
    this -> procentReducere = p.procentReducere;
    this -> cantitate = p.cantitate;
}

Lot Lot::operator= (const Lot &p) {

    if ( this != &p ) {

        if ( this -> dataLot != NULL )
            delete[] this -> dataLot;

        this -> dataLot = new char[strlen(p.dataLot)+1];
        strcpy(this -> dataLot , p.dataLot);

        this -> p = p.p;
        this -> pretPeUnitate = p.pretPeUnitate;
        this -> procentReducere = p.procentReducere;
        this -> cantitate = p.cantitate;
        }
    return *this;
}

//--------------IO--------------

void Lot::afisare(ostream &out) {

    out << "Pe data de " << dataLot << " magazinul primeste un lot de " << cantitate << " de " << p << ", la pretul de " << pretPeUnitate << " pe " << p.getMasura();
    if ( procentReducere > 0 )
        out << ", la care decide sa adauge o reducere de " << procentReducere << "%" << "\n";
}

void Lot::citire(istream &in) {

    cout << "Data introducere lot: ";
    char auxData[100];
    in >> auxData;

    if ( this -> dataLot != NULL )
        delete[] dataLot;

    this -> dataLot = new char[strlen(auxData)+1];
        strcpy(this->dataLot, auxData);

    cout <<"\nProdus: \n";
    in >> p;
    cout << "\nCantitate: ";
    in >> cantitate;
    if ( cantitate < 0 )
        throw(1);
    cout << "\nPret pe " << p.getMasura() << " :";
    in >> pretPeUnitate;
    if ( pretPeUnitate < 0 )
        throw(2);
    cout << "\nProcent reducere : ";
    in >> procentReducere;
}

istream& operator>>(istream &in, Lot& l){
    l.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Lot& l){
    l.afisare(out);
    return out;
}

//----------DESTRUCTOR----------

Lot::~Lot() {
    if ( this -> dataLot != NULL )
        delete[] this -> dataLot;
}

//----------EXTINDERE-----------

class LotPerisabil: public Lot {

private:
    int valabilitate;
public:

    LotPerisabil();

    LotPerisabil(char* dataLot , Produs p , float pretPeUnitate, int procentReducere, int cantitate, int valabilitate);

    LotPerisabil(const LotPerisabil &p);

    LotPerisabil operator =(const LotPerisabil &);

    friend istream &operator>>(istream &in, LotPerisabil &p);

    friend ostream &operator<<(ostream &out, LotPerisabil &p);

    void citire(istream &in);

    void afisare(ostream &out);

    ~LotPerisabil() {} // nu am nimic de dezalocat

};

//----------CONSTRUCTORI--------------

LotPerisabil::LotPerisabil() : Lot() { this -> valabilitate = 0; }

LotPerisabil::LotPerisabil(char* dataLot , Produs p , float pretPeUnitate, int procentReducere, int cantitate, int valabilitate) : Lot(dataLot , p , pretPeUnitate, procentReducere, cantitate) {

    this -> valabilitate = valabilitate;
}

LotPerisabil::LotPerisabil(const LotPerisabil &p) : Lot(p) {

    valabilitate = p.valabilitate;
}

//-------------- = -----------------

LotPerisabil LotPerisabil:: operator=(const LotPerisabil &p) {
    if ( this != &p ) {
        Lot::operator=(p);
        //destructor aici pt dezalocare daca aveam altceva de dezalocat la lot perisabil;
        this -> valabilitate = p.valabilitate;
    }
return *this;
}

//--------------- IO ---------------

void LotPerisabil::afisare(ostream &out) {

    Lot::afisare(out);
    cout << "Lotul are termen de valabilitate de "<<valabilitate<<" zile.";
}

void LotPerisabil::citire(istream &in) {

    Lot::citire(in);
    cout << "Valabilitate: ";
    in >> valabilitate;
}

istream &operator>>(istream &in, LotPerisabil &p) {
    p.citire(in);
    return in;
}

ostream &operator<<(ostream &out, LotPerisabil &p) {
    p.afisare(out);
    return out;
}

//-------------- MAIN ----------------

int main() {

    vector <Produs> listaProduse;
    vector <Lot*> listaLoturi;

   char optiune = 'a';

    while (optiune != '0')
{
	cout << "\n1) Introdu un produs \n2) Afiseaza toate produsele \n3) Adauga un lot nou dintr-un produs \n4) Afiseaza toate loturile \n0) Exit \n\n";
	cout << "Introduceti optiunea: ";
	cin >> optiune;

	switch (optiune)
	{
		case '1':
			{
				Produs temp;
				cin >> temp;
				listaProduse.push_back(temp);
				break;
			}

		case '2':
			{
				if (listaProduse.size() > 0)
				{
					cout << "Produsele care pot fi comercializate sunt : \n";
					for (int i = 0; i < listaProduse.size(); i++)
					{
						cout << listaProduse[i] << "\n";
					}
				}
				else cout << "Lista de produse este goala ! \n";
				break;
			}

		case '3':
			{
			    try {
				cout << "\n 1) Adauga lot produse perisabile \n 2) Adauga lot de produse neperisabile \n";
				cout << "Introduceti optiunea: ";
				int comanda2;
				cin >> comanda2;
				switch (comanda2)
				{
					case 1:
						{
							Lot * l;
							l = new LotPerisabil;
							cin >> *l;
							listaLoturi.push_back(l);

							break;
						}

					case 2:
						{
							Lot * l;
							l = new Lot;
							cin >> *l;
							listaLoturi.push_back(l);
							listaProduse.push_back(l->getProdus());

							break;
						}
				}
            } // paranteza de la try
                catch ( int eroare ) {
                    if (eroare == 1)
                        cout << "Eroare la citirea cantitatii - NEGATIVE NUMBER ! \n";
                    if (eroare == 2)
                        cout << "Eroare la citirea pretului _ NEGATIVE NUMBER ! \n";
                }
				break;
			}

		case '4':
			{
				if (listaLoturi.size() > 0)
				{
					for (int i = 0; i < listaLoturi.size(); i++)
					{
						cout << *(listaLoturi[i]) << "\n";
					}
				}
				else cout << "Lista de loturi este goala ! \n";
				break;
			}

		case '0':
			{
				break;
			}
	}
}

return 0;
}
