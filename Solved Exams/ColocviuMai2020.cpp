#include <iostream>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

class MascaChirurgicala {

private:

    string tipProtectie;
    string culoare;
    int nrPliuri;

public:

    MascaChirurgicala();

    MascaChirurgicala(string tipProtectie, string culoare, int nrPliuri);

    MascaChirurgicala(const MascaChirurgicala &m);

    MascaChirurgicala operator=(const MascaChirurgicala &m);

    friend istream& operator>>(istream&, MascaChirurgicala&);

    friend ostream& operator<<(ostream&, MascaChirurgicala&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    string getProtectie() { return tipProtectie; }

    ~MascaChirurgicala() {} ;
};

//----------CONSTRUCTORI--------------

MascaChirurgicala::MascaChirurgicala() {

    tipProtectie = "Unknown";
    culoare = "Unknown";
    nrPliuri = 0;
}

MascaChirurgicala::MascaChirurgicala(string tipProtectie, string culoare, int nrPliuri) {

    this -> tipProtectie = tipProtectie;
    this -> culoare = culoare;
    this -> nrPliuri = nrPliuri;
}

MascaChirurgicala::MascaChirurgicala(const MascaChirurgicala &m) {

    this -> tipProtectie = m.tipProtectie;
    this -> culoare = m.culoare;
    this -> nrPliuri = m.nrPliuri;
}

MascaChirurgicala MascaChirurgicala::operator=(const MascaChirurgicala &m) {

    if ( this != &m )
    {
        this -> tipProtectie = m.tipProtectie;
        this -> culoare = m.culoare;
        this -> nrPliuri = m.nrPliuri;
    }
return *this;
}

//--------------IO--------------

void MascaChirurgicala::citire(istream &in) {

    cout << "Introduceti tipul de protectie: ";
    in >> tipProtectie;
    cout << "Introduceti culoarea: ";
    in >> culoare;
    cout << "Introduceti numarul de pliuri: ";
    in >> nrPliuri;
}

void MascaChirurgicala::afisare(ostream &out) {

    out << "Masca chirurgicala \n" << "Tip de protectie: " << tipProtectie << "\n" << "Culoare: " << culoare << "\n" << "Numar de pliuri: " << nrPliuri << "\n";
}

istream& operator>>(istream &in, MascaChirurgicala& m){
    m.citire(in);
    return in;
}

ostream& operator<<(ostream &out, MascaChirurgicala& m){
    m.afisare(out);
    return out;
}

//----------EXTINDERE-----------

class MascaPolicarbonat: public MascaChirurgicala {

private:

    string tipProtectie;
    string tipPrindere;

public:

    MascaPolicarbonat();

    MascaPolicarbonat(string tipProtectie, string culoare, int nrPliuri);

    MascaPolicarbonat(const MascaPolicarbonat &m);

    MascaPolicarbonat operator=(const MascaPolicarbonat &m);

    friend istream& operator>>(istream&, MascaPolicarbonat&);

    friend ostream& operator<<(ostream&, MascaPolicarbonat&);

    void citire(istream &in);

    void afisare(ostream &out);

    ~MascaPolicarbonat() {} ;

};

//----------CONSTRUCTORI--------------

MascaPolicarbonat::MascaPolicarbonat() : MascaChirurgicala() {

    tipPrindere = "Unknown";
    tipProtectie = "ffp0";
}

MascaPolicarbonat::MascaPolicarbonat(string tipProtectie, string culoare, int nrPliuri) : MascaChirurgicala(tipProtectie, culoare, nrPliuri) {

    this -> tipPrindere = tipPrindere;
}

MascaPolicarbonat::MascaPolicarbonat(const MascaPolicarbonat &m) : MascaChirurgicala(m) {

    this -> tipPrindere = m.tipPrindere ;
}

MascaPolicarbonat MascaPolicarbonat::operator=(const MascaPolicarbonat &m) {

    if ( this != &m ) {
        MascaChirurgicala::operator=(m);
        //destructor aici pt dezalocare daca aveam altceva de dezalocat la lot perisabil;
        this -> tipPrindere = m.tipPrindere;
    }
return *this;
}

//--------------IO--------------

void MascaPolicarbonat::citire(istream &in) {

    tipProtectie = "ffp0";
    cout << "Introduceti tipul de prindere: ";
    in >> tipPrindere;
}

void MascaPolicarbonat::afisare(ostream &out) {

    //MascaChirurgicala::afisare(out);
    out << "Masca Policarbonat \n";
    out << "Tip protectie: " << tipProtectie << "\n";
    out << "Tipul de prindere: " << tipPrindere << "\n";
}

istream& operator>>(istream &in, MascaPolicarbonat& m){
    m.citire(in);
    return in;
}

ostream& operator<<(ostream &out, MascaPolicarbonat& m){
    m.afisare(out);
    return out;
}

//------------------------------

class Dezinfectant {

private:

    double nrSpeciiUcise;
    vector<string> ingrediente;
    vector<string> suprafete;

public:

    Dezinfectant();

    Dezinfectant(double nrSpeciiUcise, vector<string> ingrediente, vector<string> suprafete);

    Dezinfectant(const Dezinfectant &d);

    Dezinfectant operator=(const Dezinfectant &);

    friend istream& operator>>(istream&, Dezinfectant&);

    friend ostream& operator<<(ostream&, Dezinfectant&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    virtual float calcEficienta() { cout << "Functie clasa de baza"; }

    double getSpecii() { return nrSpeciiUcise; }

    ~Dezinfectant() ;

};

//----------CONSTRUCTORI--------------

Dezinfectant::Dezinfectant() {

    nrSpeciiUcise = 0;
}

Dezinfectant::Dezinfectant(double nrSpeciiUcise, vector<string> ingrediente, vector<string> suprafete) {

    this -> nrSpeciiUcise = nrSpeciiUcise;
    this -> ingrediente = ingrediente;
    this -> suprafete = suprafete;
}

Dezinfectant::Dezinfectant(const Dezinfectant &d) {

    this -> nrSpeciiUcise = d.nrSpeciiUcise;
    this -> ingrediente = d.ingrediente;
    this -> suprafete = d.suprafete;
}

Dezinfectant Dezinfectant::operator=(const Dezinfectant &d) {

    if ( this != &d ) {

        if ( this->ingrediente.size() != 0 )
            this->ingrediente.clear();
        if ( this->suprafete.size() != 0 )
            this->suprafete.clear();
        this -> nrSpeciiUcise = d.nrSpeciiUcise;
        this -> ingrediente = d.ingrediente;
        this -> suprafete = d.suprafete;
    }
return *this;
}

//-----------IO--------------

void Dezinfectant::citire(istream &in) {

    cout << "Introduceti numarul de specii ucise: ";
    in >> nrSpeciiUcise;
    int n;
    cout << "Introduceti numarul de ingrediente: ";
    cin >> n;
    for (int i = 0 ; i < n ; i ++ )
    {
        string temp;
        cout << "Introduceti ingredientul " << i+1 << " : ";
        in >> temp;
        ingrediente.push_back(temp);
    }
    int k;
    cout << "Introduceti numarul de suprafete: ";
    cin >> k;
    for ( int i = 0 ; i < k ; i++ )
    {
        string temp;
        cout << "Introduceti suprafata " << i+1 << " : ";
        in >> temp;
        suprafete.push_back(temp);
    }
}

void Dezinfectant::afisare(ostream &out) {

    out << "Numarul de specii ucise: " << nrSpeciiUcise << "\n";
    out << "Ingrediente : " << "\n";
    for ( int i = 0 ; i < ingrediente.size(); i++ )
        out << ingrediente[i] << "\n";
    out << "Suprafete : " << "\n";
    for ( int i = 0 ; i < suprafete.size(); i++ )
        out << suprafete[i] << "\n";
}

istream& operator>>(istream &in, Dezinfectant& d){
    d.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Dezinfectant& d){
    d.afisare(out);
    return out;
}

//----------DESTRUCTOR----------

Dezinfectant::~Dezinfectant() {

    ingrediente.clear();
    suprafete.clear();
}

//----------EXTINDERE 1-----------

class DezinfectantBacterii : public Dezinfectant {

private:
    const double nrBacterii = pow(10 , 9);
public:

    DezinfectantBacterii() {} ;

    float calcEficienta() { return getSpecii()/nrBacterii ; }

    ~DezinfectantBacterii() {};

};

class DezinfectantFungi : public Dezinfectant {
private:
    const double nrFungi = 1.5*pow(10, 6);
public:

    DezinfectantFungi() {};

    float calcEficienta() { return getSpecii()/nrFungi ; }

    ~DezinfectantFungi() {}
};

class DezinfectantVirusuri : public Dezinfectant {
private:
    const double nrVirusuri = pow(10 , 8);
public:

    DezinfectantVirusuri() {} ;

    float calcEficienta() { return getSpecii()/nrVirusuri ; }

    ~DezinfectantVirusuri() {}

};

class Achizitie {

private:
    string data;
    string numeClient;
    vector<MascaChirurgicala*> mastiCumparate;
    vector<Dezinfectant*> dezinfCumparate;

public:

    Achizitie() {

        data = "Unknown";
        numeClient = "Anonim";
    }

    Achizitie(const Achizitie &a) {

        this -> data = a.data;
        this -> numeClient = a.numeClient;
        this -> mastiCumparate = a.mastiCumparate;
        this -> dezinfCumparate = a.dezinfCumparate;
    }

    friend ostream& operator<< (ostream &out, Achizitie &a) {

    out << a.getNume() << " a cumparat in data de " << a.getData() <<" : \n";
    for ( int i = 0 ; i < a.mastiCumparate.size() ; i ++ )
        out << a.mastiCumparate[i] << "\n";
    for ( int i = 0 ; i < a.dezinfCumparate.size() ; i ++ )
        out << a.dezinfCumparate[i] << "\n";

    return out;
    }

    friend istream& operator>> (istream &in, Achizitie &a) {

        cout << "Nume client: ";
        in >> a.numeClient;
        cout << "Data achizitiei: ";
        in >> a.data;
    return in;
    }

    ~Achizitie()

    {
        mastiCumparate.clear();
        dezinfCumparate.clear();
    }

    string getNume() { return numeClient; }

    string getData() { return data; }

    vector<MascaChirurgicala*> getMasti() { return mastiCumparate; }

    vector<Dezinfectant*> getDezinf() { return dezinfCumparate; }
};


int main() {

vector<MascaChirurgicala> mc;
vector<MascaPolicarbonat> mp;
vector<Dezinfectant*> d;
vector<Achizitie> a;

char optiune = 'a';

    while (optiune != '0') {

	cout << "\n1) Adauga masca \n2) Afiseaza toate mastile \n3) Adauga dezinfectant \n4) Afiseaza toti Dezinfectantii \n5) Afiseaza cel mai eficient dezinfectant \n6) Adauga achizitie \n7) Afiseaza toate achizitiile \n0) Exit \n\n";
	cout << "Introduceti optiunea: ";
	cin >> optiune;

	switch (optiune)
	{
        case '1' :
        {
            cout <<"\n1) Adauga masca chirugicala \n2) Adauga masca policarbonat \n";
            int optiune;
            cout << "Introduce optiunea: ";
            cin >> optiune;
            if ( optiune == 1 )
                {
                    MascaChirurgicala temp;
                    cin >> temp;
                    mc.push_back(temp);
                }
            if ( optiune == 2 )
                {
                    MascaPolicarbonat temp;
                    cin >> temp;
                    mp.push_back(temp);
                }
        break;
        }

        case '2' :

        {
            if ( mc.size() !=0 || mp.size() != 0 )
            {
                for ( int i = 0 ; i < mc.size() ; i++ )
                    cout << mc[i] << "\n";
                for ( int j = 0 ; j < mp.size() ; j++ )
                    cout << mp[j] << "\n";
            }
            else cout << "Nu au fost adaugate masti ! \n";
        break;
        }

        case '3' :
        {
            cout << "\n1) Adauga dezinfectant bacterii \n2) Adauga dezinfectant fungi \n3) Adauga dezinfectant virusuri \n";
            int optiune;
            cout << "Introduce optiunea: ";
            cin >> optiune;
            if ( optiune == 1 )
            {
                Dezinfectant * temp;
                temp = new DezinfectantBacterii;
                cin >> *temp;
                d.push_back(temp);
            }
            else if ( optiune == 2)
            {
                Dezinfectant * temp;
                temp = new DezinfectantFungi;
                cin >> *temp;
                d.push_back(temp);
            }
            else if ( optiune == 3)
            {
                Dezinfectant * temp;
                temp = new DezinfectantVirusuri;
                cin >> *temp;
                d.push_back(temp);
            }
        break;
        }

        case '4' :
        {
            if ( d.size() != 0 )
            {
                for ( int i = 0 ; i < d.size() ; i++ )
                    cout << "Dezinfectant " <<  i+1  << ") \n" << *d[i] <<"\n";
            }
            else cout << "Nu au fost adaugati dezinfectanti ! \n";
        break;
        }

        case '5' :
         {
             float maxim = 0;
             int indice = 0;
             int i = 0;
             for ( i = 0 ; i < d.size() ; i ++ )
             {
                 if ( d[i]->calcEficienta() > maxim )
                 {
                     maxim = d[i]->calcEficienta();
                     indice = i;
                 }
             }
             cout << "Dezinfectantul cel mai eficient este dezinfectantul cu numarul " << i << " , cu o eficienta de " << maxim << "% \n";
         break;
         }

        case '6' :
        {
            /*
            // vectorul de achizitii e a, in a am mai multe obiecte de tip achizitii, si in achizitii am un vector de dezinfectante/masti . Deci apelez a.ac.getMasti()[i] ...
            Achizitie ac;
            cin >> ac;
            cout << "\n1)Cumpara masca \n2)Cumpara dezinfectant ";
            int option;
            cin >> option;
            if ( option == 1 )
                {
                    int nr;
                    cout << "\n1)Masca Chirurgicala \n2)Masca Policarbonat ";
                    cin >> nr;
                        if ( nr == 1 )
                        {
                            int nrr;
                            //ac.getMasti().push_back ( *(mc[nrr-1]) );
                        }
                        if ( nr == 2 )
                        {
                            int nrr;
                            //ac.getMasti().push_back ( mp[nrr-1] );
                        }
                }
            if ( option == 2)
                {
                    int nr;
                    cout << "Introduceti numarul unic al dezinfectantului: ";
                    cin >> nr;
                    Dezinfectant * temp;
                    temp = d[nr-1];  // temp e o adresa de memorie la dezinfectant
                    //cout << "\n" << *temp << "\n";
                    ( ac.getDezinf() ).push_back( temp ) ;
                    cout << ac.getDezinf().size();
                    //cout << ac;
                }
            a.push_back(ac);
            */
        }

        case '7' :
            {
                for ( int i = 0; i < a.size() ; i++ )
                    cout << a[i] << "\n";
            }

        }
    }


return 0;
}
