/* Apostu Alexandru-Mihai 212
GNU GCC Compiler (folosesc CodeBlocks)
Tutore de laborator : Szmeteanca Eduard Gabriel */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <iterator>

// Sintaxa folosita pentru toti constructorii si headerele functiilor sunt similare cu cele facute in proiectul facut de mine
// Meniul este facut pe acelasi format cu proiectul de laborator

using namespace std;

class schema {

public:

    virtual void afisareSchemaVaccinare() = 0;

};

class Vaccin : schema {

private:

    string producator;
    float pret;
    float temperatura;
    vector<string> ingrediente;

public:

    Vaccin() ;

    Vaccin(string producator, float pret, float temperatura, vector<string> ingrediente);

    Vaccin(const Vaccin &v);

    Vaccin operator=(const Vaccin &);

    friend istream& operator>>(istream&, Vaccin&);

    friend ostream& operator<<(ostream&, Vaccin&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    string getProducator() { return this->producator; }

    void afisareSchemaVaccinare() {}

    ~Vaccin() ;

};

//-------- CONSTRUCTORI ---------

Vaccin::Vaccin() {

    pret = 0;
    temperatura = 0;
}

Vaccin::Vaccin(string producator, float pret, float temperatura, vector<string> ingrediente) {

    this -> producator = producator;
    this -> pret = pret;
    this -> temperatura = temperatura;
    this -> ingrediente = ingrediente;
}

Vaccin::Vaccin(const Vaccin &v) {

    this -> producator = v.producator;
    this -> pret = v.pret;
    this -> temperatura = v.temperatura;
    this -> ingrediente = v.ingrediente;
}

Vaccin Vaccin::operator=(const Vaccin &v) {

    if ( this != &v )
    {
        this -> producator = v.producator;
        this -> pret = v.pret;
        this -> temperatura = v.temperatura;
        this -> ingrediente = v.ingrediente;
    }
return *this;
}


//-------------- IO --------------

void Vaccin::citire(istream &in) {

    cout << "Introduceti numele producatorului: ";
    in >> producator;
    cout << "Introduceti pretul vaccinului: ";
    in >> pret;
    cout << "Introduceti temperatura de depozitare: ";
    in >> temperatura;
    cout << "Introduceti numarul de elemente din compozitie: ";
    int n;
    in >> n;
    for ( int i = 0 ; i < n ; i ++)
    {
        cout << "Introduceti elementul " << i+1 << " :";
        string temp;
        in >> temp;
        ingrediente.push_back(temp);
    }
}

void Vaccin::afisare(ostream &out) {

    out << "Producator: " << producator << "\n";
    out << "Pretul vaccinului : " << pret << "\n";
    out << "Temperatura de depozitare: " << temperatura << "\n";
    out << "Elementele din compozitia vaccinului sunt: \n";
    for ( int i = 0 ; i < ingrediente.size() ; i ++ )
        out << ingrediente[i] << "\n";
}

istream& operator>>(istream &in, Vaccin& v){
    v.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Vaccin& v){
    v.afisare(out);
    return out;
}


//---------- DESTRUCTOR ----------

Vaccin::~Vaccin() {

    ingrediente.clear();
}


class VaccinAntigripal : public Vaccin {

private:

    vector<string> tulpini;

public:

    VaccinAntigripal() ;

    VaccinAntigripal(string producator, float pret, float temperatura, vector<string> ingrediente, vector<string> tulpini);

    VaccinAntigripal(const VaccinAntigripal &v);

    VaccinAntigripal operator=(const VaccinAntigripal &);

    friend istream& operator>>(istream&, VaccinAntigripal&);

    friend ostream& operator<<(ostream&, VaccinAntigripal&);

    void citire(istream &in);

    void afisare(ostream &out);

    void afisareSchemaVaccinare() { cout << "Adulti : doza de 0.5 ml \nCopii: doza de 0.3 ml \nReinnoire: odata la 2 ani \n"; }

    ~VaccinAntigripal() ;

};

//-------- CONSTRUCTORI ---------

VaccinAntigripal::VaccinAntigripal() : Vaccin() {}

VaccinAntigripal::VaccinAntigripal(string producator, float pret, float temperatura, vector<string> ingrediente , vector<string> tulpini) : Vaccin(producator, pret, temperatura, ingrediente ) {

    this -> tulpini = tulpini;
}

VaccinAntigripal::VaccinAntigripal(const VaccinAntigripal &v) : Vaccin(v) {

    this -> tulpini = v.tulpini;
}

VaccinAntigripal VaccinAntigripal::operator=(const VaccinAntigripal &v) {

    if ( this != &v )
    {
        Vaccin::operator=(v);
        this -> tulpini = v.tulpini;
    }
return *this;
}

//-------------- IO --------------

void VaccinAntigripal::citire(istream &in) {

    Vaccin::citire(in);
    cout << "Introduceti numarul de tulpini: ";
    int n;
    in >> n;
    for ( int i = 0 ; i < n ; i++ )
        {
            cout << "Introduceti tulpina " << i+1 << " :";
            string temp;
            in >> temp;
            tulpini.push_back(temp);
        }
}

void VaccinAntigripal::afisare(ostream &out) {

    Vaccin::afisare(out);
    out << "Lista de tulpini combatate : \n";
    for ( int i = 0 ; i < tulpini.size() ; i++ )
        out << tulpini[i] << "\n";
}

istream &operator>>(istream &in, VaccinAntigripal &v) {
    v.citire(in);
    return in;
}

ostream &operator<<(ostream &out, VaccinAntigripal &v) {
    v.afisare(out);
    return out;
}

//---------- DESTRUCTOR ----------

VaccinAntigripal::~VaccinAntigripal() {

    tulpini.clear();

}


class VaccinAntihepatic : public Vaccin {

private:

    char tipHepatita;

public:

    VaccinAntihepatic() ;

    VaccinAntihepatic(string producator, float pret, float temperatura, vector<string> ingrediente, char tipHepatita);

    VaccinAntihepatic(const VaccinAntihepatic &v);

    VaccinAntihepatic operator=(const VaccinAntihepatic &);

    friend istream& operator>>(istream&, VaccinAntihepatic&);

    friend ostream& operator<<(ostream&, VaccinAntihepatic&);

    void citire(istream &in);

    void afisare(ostream &out);

    void afisareSchemaVaccinare() { cout << "Copii <1 an : 2 injectari odata la o luna / a treia injecatare la 6 luni dupa prima administrare \nAdulti: conform schemei de imunizare recomandata de medic \n"; }

    ~VaccinAntihepatic() {} // nu am nimic de dezalocat

};

//-------- CONSTRUCTORI ---------

VaccinAntihepatic::VaccinAntihepatic() : Vaccin() { tipHepatita = '0'; }

VaccinAntihepatic::VaccinAntihepatic(string producator, float pret, float temperatura, vector<string> ingrediente , char tipHepatita) : Vaccin(producator, pret, temperatura, ingrediente ) {

    this -> tipHepatita = tipHepatita;
}

VaccinAntihepatic::VaccinAntihepatic(const VaccinAntihepatic &v) : Vaccin(v) {

    this -> tipHepatita = v.tipHepatita;
}

VaccinAntihepatic VaccinAntihepatic::operator=(const VaccinAntihepatic &v) {

    if ( this != &v )
    {
        Vaccin::operator=(v);
        this -> tipHepatita = v.tipHepatita;
    }
return *this;
}

//-------------- IO --------------

void VaccinAntihepatic::citire(istream &in) {

    Vaccin::citire(in);
    cout << "Introduceti tipul de hepatita: ";
    int n;
    in >> tipHepatita;
}

void VaccinAntihepatic::afisare(ostream &out) {

    Vaccin::afisare(out);
    out << "Tipul de hepatita combatat: " << tipHepatita << "\n";
}

istream &operator>>(istream &in, VaccinAntihepatic &v) {
    v.citire(in);
    return in;
}

ostream &operator<<(ostream &out, VaccinAntihepatic &v) {
    v.afisare(out);
    return out;
}



class VaccinAntiSarsCov2 : public Vaccin {

private:

    vector<string> reactiiAdverse;

public:

    VaccinAntiSarsCov2() ;

    VaccinAntiSarsCov2(string producator, float pret, float temperatura, vector<string> ingrediente, vector<string> reactiiAdverse);

    VaccinAntiSarsCov2(const VaccinAntiSarsCov2 &v);

    VaccinAntiSarsCov2 operator=(const VaccinAntiSarsCov2 &);

    friend istream& operator>>(istream&, VaccinAntiSarsCov2&);

    friend ostream& operator<<(ostream&, VaccinAntiSarsCov2&);

    void citire(istream &in);

    void afisare(ostream &out);

    void afisareSchemaVaccinare() { cout << "Persoanelor cu varsta de peste 16 ani, 2 doze la o perioada de 21 de zile \n"; }

    ~VaccinAntiSarsCov2() ;

};

//-------- CONSTRUCTORI ---------

VaccinAntiSarsCov2::VaccinAntiSarsCov2() : Vaccin() {}

VaccinAntiSarsCov2::VaccinAntiSarsCov2(string producator, float pret, float temperatura, vector<string> ingrediente , vector<string> reactiiAdverse) : Vaccin(producator, pret, temperatura, ingrediente ) {

    this -> reactiiAdverse = reactiiAdverse;
}

VaccinAntiSarsCov2::VaccinAntiSarsCov2(const VaccinAntiSarsCov2 &v) : Vaccin(v) {

    this -> reactiiAdverse = v.reactiiAdverse;
}

VaccinAntiSarsCov2 VaccinAntiSarsCov2::operator=(const VaccinAntiSarsCov2 &v) {

    if ( this != &v )
    {
        Vaccin::operator=(v);
        this -> reactiiAdverse = v.reactiiAdverse;
    }
return *this;
}

//-------------- IO --------------

void VaccinAntiSarsCov2::citire(istream &in) {

    Vaccin::citire(in);
    cout << "Introduceti numarul de reactii adverse: ";
    int n;
    in >> n;
    for ( int i = 0 ; i < n ; i++ )
        {
            cout << "Introduceti reactia " << i+1 << " :";
            string temp;
            in >> temp;
            reactiiAdverse.push_back(temp);
        }
}

void VaccinAntiSarsCov2::afisare(ostream &out) {

    Vaccin::afisare(out);
    out << "Lista de reactii adverse : \n";
    for ( int i = 0 ; i < reactiiAdverse.size() ; i++ )
        out << reactiiAdverse[i] << "\n";
}

istream &operator>>(istream &in, VaccinAntiSarsCov2 &v) {
    v.citire(in);
    return in;
}

ostream &operator<<(ostream &out, VaccinAntiSarsCov2 &v) {
    v.afisare(out);
    return out;
}

//---------- DESTRUCTOR ----------

VaccinAntiSarsCov2::~VaccinAntiSarsCov2() {

    reactiiAdverse.clear();
}

//---------- CLASA COMANDA ----------

class Comanda {

private:
    string data;
    string nume;
    int nrDozeGripal;
    int nrDozeHepatita;
    int nrDozeCovid;
public:

    Comanda() ;

    Comanda(string data, string nume, int nrDozeGripal, int nrDozeHepatita, int nrDozeCovid );

    Comanda(const Comanda &c);

    Comanda operator=(const Comanda &);

    friend istream& operator>>(istream&, Comanda&);

    friend ostream& operator<<(ostream&, Comanda&);

    void citire(istream &in);

    void afisare(ostream &out);

    ~Comanda() {};

};

//----------CONSTRUCTORI--------------

Comanda::Comanda() {

    nume = "Anonim";
    data = "Necunoscuta";
    nrDozeCovid = 0;
    nrDozeGripal = 0;
    nrDozeHepatita = 0;
}

Comanda::Comanda( string data, string nume, int nrDozeGripal, int nrDozeHepatita, int nrDozeCovid) {

    this -> data = data;
    this -> nume = nume;
    this -> nrDozeCovid = nrDozeCovid;
    this -> nrDozeGripal = nrDozeGripal;
    this -> nrDozeHepatita = nrDozeHepatita;
}

Comanda::Comanda (const Comanda & c) {

    this -> data = c.data;
    this -> nume = c.nume;
    this -> nrDozeCovid = c.nrDozeCovid;
    this -> nrDozeGripal = c.nrDozeGripal;
    this -> nrDozeHepatita = c.nrDozeHepatita;
}

Comanda Comanda::operator= (const Comanda &c) {

    if ( this != &c ) {
        this -> data = c.data;
        this -> nume = c.nume;
        this -> nrDozeCovid = c.nrDozeCovid;
        this -> nrDozeGripal = c.nrDozeGripal;
        this -> nrDozeHepatita = c.nrDozeHepatita;
    }
return *this;
}

//--------------- IO ---------------

void Comanda::afisare(ostream &out) {

    out << nume << " a comandat " << nrDozeGripal << " doze de vaccin AntiGripal, " << nrDozeCovid << " doze de vaccin Anti Sas-Cov2, si " << nrDozeHepatita << " doze de vaccin AntiHepatita \n";

}

void Comanda::citire(istream &in) {

    cout << "Introduceti numele cumparatorului: ";
    in >> nume;
    cout << "Introduceti data achizitiei: ";
    in >> data;
    char optiune;
    while( optiune != '0' )
    {
    cout << "1) Achizitioneaza vaccin antigripal \n2) Achizitioneaza vaccin antihepatic \n3) Achizitioneaza vaccin SarsCov2 \n0) Back \n";
    cin >> optiune;
    switch(optiune) {

        case '0' : break;

        case '1' :
            {
                cout << "Introduceti numarul de doze: ";
                in >> nrDozeGripal;
                break;
            }

        case '2' :
            {
                cout << "Introduceti numarul de doze: ";
                in >> nrDozeHepatita;
                break;
            }

        case '3' :
            {
                cout << "Introduceti numarul de doze: ";
                in >> nrDozeCovid;
                break;
            }
        }
    }
}

istream& operator>>(istream &in, Comanda& c){
    c.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Comanda& c){
    c.afisare(out);
    return out;
}

//----------LISTA COMENZI----------

class ListaComenzi {

private:

    vector<Comanda> comenzi;

public:

    ListaComenzi(){};

    ~ListaComenzi() { comenzi.clear(); };

    ListaComenzi operator+(Comanda c){
        comenzi.push_back(c);
    return *this;
    }

    ListaComenzi operator=(ListaComenzi c){
        comenzi = c.comenzi;
        return *this;
    }

    void afisare(){
        cout << "Lista tuturor comenzilor: \n";
        for(int i = 0; i < comenzi.size(); i++)
            cout << comenzi[i] << "\n";
    }

    Comanda &operator[](int index){
        return comenzi[index-1];
    }

    vector<Comanda> getComenzi() { return this->comenzi; }

} ;



//------------ MENIU --------------

int main() {

vector<VaccinAntigripal> va;
vector<VaccinAntihepatic> vh;
vector<VaccinAntiSarsCov2> vc;
ListaComenzi lista;

    char optiune = 'a';

    while (optiune != '0')
{
        cout << "\n1) Adaugare vaccin nou  \n2) Afisarea tuturor vaccinurilor \n3) Afiseaza numele producatorilor tuturor vaccinurilor \n4) Adaugarea unei comenzi \n5) Afisarea tuturor comenzilor \n6) - not functional - \n7) Afisare schema vaccinare pentru un anumit tip de vaccin \n8) Export comenzi in fisier extern \n0) Exit \n\n";
        cout << "Introduceti optiunea: ";
        cin >> optiune;

	switch (optiune)
	{
	    case '0': { break; }

        case '1' :
        {

            char optiune2 = 'b' ;

            while ( optiune2 != '0') {
            cout << "\n1) Vaccin AntiGripal \n2) Vaccin AntiHepatic \n3) Vaccin Anti Sars-Cov2 \n0) Back \n";
            cout << "Introduceti optiunea: ";
            cin >> optiune2;

                switch(optiune2)
                {
                    case '0' : break;

                    case '1' :
                        {
                            cout << "\n Introducere vaccin AntiGripal: \n";
                            VaccinAntigripal temp;
                            cin >> temp;
                            va.push_back(temp);
                            break;
                        }

                    case '2' :
                        {
                            cout << "\n Introducere vaccin Antihepatic: \n";
                            VaccinAntihepatic temp;
                            cin >> temp;
                            vh.push_back(temp);
                            break;
                        }

                    case '3' :
                        {
                            cout << "\n Introducere vaccin AntiSarsCov2: \n";
                            VaccinAntiSarsCov2 temp;
                            cin >> temp;
                            vc.push_back(temp);
                            break;
                        }
                }
            }
        break;
        }

        case '2' :
            {
                cout << "Lista tuturor vaccinurilor: \n\n";
                for ( int i = 0 ; i < va.size() ; i++ )
                    cout << va[i] << "\n";
                for ( int i = 0 ; i < vh.size() ; i++ )
                    cout << vh[i] << "\n";
                for ( int i = 0 ; i < vc.size() ; i++ )
                    cout << vc[i] << "\n";
                break;
            }

        case '3' :
            {
                cout << "Lista producatorilor: \n\n";
                for ( int i = 0 ; i < va.size() ; i++ )
                    cout << va[i].getProducator() << "\n";
                for ( int i = 0 ; i < vh.size() ; i++ )
                    cout << vh[i].getProducator() << "\n";
                for ( int i = 0 ; i < vc.size() ; i++ )
                    cout << vc[i].getProducator() << "\n";
                break;
            }

        case '4' :
            {
                Comanda c;
                cin >> c;
                lista = lista + c;
                break;
            }

        case '5' :
            {
                lista.afisare() ;
                break;
            }

        case '7' :
            {
            cout << "1) Schema vaccinare pentru vaccin Antigripal \n2) Schema vaccinare pentru vaccin Antihepatic \n3) Schema vaccinare pentru vaccin anti Sars-Cov2 \n";
            VaccinAntigripal v1;
            VaccinAntihepatic v2;
            VaccinAntiSarsCov2 v3;
            int optiune;
            cin >> optiune;
            if ( optiune == 1 )
                v1.afisareSchemaVaccinare();
            else if ( optiune == 2 )
                v2.afisareSchemaVaccinare();
            else if ( optiune ==3 )
                v3.afisareSchemaVaccinare();
            break;
            }

        case '8' :
            {
                cout << "Introduceti numele fisierului de export: ";
                string s;
                cin >> s;
                ofstream fout(s);

                if (lista.getComenzi().size() > 0)
                    for (int i = 0; i < lista.getComenzi().size(); i++)
                    {
                        fout << "Nr. comanda : " << i+1 << "\n" << lista.getComenzi()[i];
                    }
                    else fout << "Nu au fost introduse comenzi ! \n";

                cout << "Fisierul a fost salvat! \n";
            }
	}
}



return 0;
}
