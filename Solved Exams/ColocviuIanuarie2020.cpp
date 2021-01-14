#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

class Masina {

private:
    int anProductie;
    string model;
    float viteza;
    float greutate;
    float autonomie;
public:
    virtual float calculAutonomie() {};

    Masina();

    Masina(int anProductie, string model, float viteza, float greutate, float autonomie);

    Masina(const Masina &m);

    friend istream& operator>>(istream&, Masina&);

    friend ostream& operator<<(ostream&, Masina&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    int getAn() { return anProductie; }

    string getModel() { return model; }

    float getViteza() { return viteza; }

    float getAutonomie() { return autonomie; }

    void setAutonomie(float autonomie) { this -> autonomie = autonomie; }

    float getGreutate() { return greutate; }

    ~Masina() {};

};

//----------CONSTRUCTORI--------------

Masina::Masina() {

    anProductie = 0;
    model = "Unknown";
    viteza = 0;
    greutate = 0;
    autonomie = 0;
}

Masina::Masina(int anProductie, string model, float viteza, float greutate, float autonomie) {

    this -> anProductie = anProductie;
    this -> model = model;
    this -> viteza = viteza;
    this -> greutate = greutate;
    this -> autonomie = autonomie;
}

Masina::Masina(const Masina &m) {

    this -> anProductie = m.anProductie;
    this -> model = m.model;
    this -> viteza = m.viteza;
    this -> greutate = m.greutate;
    this -> autonomie = m.autonomie;
}

//--------------IO--------------

void Masina::citire(istream &in) {

    cout << "Nume model: ";
    in >> model;
    cout << "An incepere productie: ";
    in >> anProductie;
    cout << "Viteza maxima: ";
    in >> viteza;
    cout << "Greutate: ";
    in >> greutate;
}

void Masina::afisare(ostream &out) {

    out << "Model: " << model << "\n" << "An incepere productie: " << anProductie << "\n" << "Viteza maxima: " << viteza << "\n" << "Greutate: " << greutate << "\n";

}

istream& operator>>(istream &in, Masina& m){
    m.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Masina& m){
    m.afisare(out);
    return out;
}

//-----------EXTINDERE--------------

class MasinaFosil : public Masina {

private:
    string tipCombustibil; // benzina sau motorina
    float capacitateRezervor;
public:

    MasinaFosil();

    MasinaFosil(int anProductie, string model, float viteza, float greutate, float autonomie, string tipCombustibil, float capacitateRezervor);

    MasinaFosil(const MasinaFosil &m);

    //MasinaFosil operator=(const MasinaFosil &);

    friend istream& operator>>(istream&, MasinaFosil&);

    friend ostream& operator<<(ostream&, MasinaFosil&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    float calculAutonomie()
    {
        float temp;
        temp = capacitateRezervor / sqrt( getGreutate() ) ;
        this->setAutonomie(temp);
        return temp;
    }

    ~MasinaFosil() {};

};

//----------CONSTRUCTORI--------------

MasinaFosil::MasinaFosil() : Masina() {

    tipCombustibil = "Unknown";
    capacitateRezervor = 0;
}

MasinaFosil::MasinaFosil(int anProductie, string model, float viteza, float greutate, float autonomie, string tipCombustibil,
                         float capacitateRezervor) : Masina( anProductie, model, viteza, greutate, autonomie) {

    this -> tipCombustibil = tipCombustibil;
    this -> capacitateRezervor = capacitateRezervor;
}

MasinaFosil::MasinaFosil(const MasinaFosil &m) : Masina(m) {

    this -> tipCombustibil = m.tipCombustibil;
    this -> capacitateRezervor = m.capacitateRezervor;
}
/*
MasinaFosil MasinaFosil::operator=(const MasinaFosil &m) {
    if ( this != &m ) {
        //destructor aici pt dezalocare daca aveam altceva de dezalocat la lot perisabil;
        this -> anProductie = m.an;
        this -> model = m.model;
        this -> viteza = m.viteza;
        this -> greutate = m.greutate;
        this -> autonomie = m.autonomie;
        this -> tipCombustibil = m.tipCombustibil;
        this -> capacitateRezervor = m.capacitateRezervor;
    }
return *this;
}
*/

//--------------IO--------------

void MasinaFosil::citire(istream &in) {

    Masina::citire(in);
    cout << "Introduceti tipul de combustibil: ";
    in >> tipCombustibil;
    cout << "Introduceti capacitatea rezervorului: ";
    in >> capacitateRezervor;
}

void MasinaFosil::afisare(ostream &out) {

    Masina::afisare(out);
    out << "Tip combustibil: " << tipCombustibil <<"\n" << "Capacitate rezervor: " << capacitateRezervor <<"L \n";
    out << "Autonomie : " << this->calculAutonomie() <<"\n" ;
}

istream &operator>>(istream &in, MasinaFosil &m) {
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, MasinaFosil &m) {
    m.afisare(out);
    return out;
}

//-----------EXTINDERE--------------

class MasinaElectrica : public Masina {

private:
    float capacitateBaterie;
public:

    MasinaElectrica();

    MasinaElectrica(int anProductie, string model, float viteza, float greutate, float autonomie, float capacitateBaterie);

    MasinaElectrica(const MasinaElectrica &m);

    //MasinaElectrica operator=(const MasinaElectrica &);

    friend istream& operator>>(istream&, MasinaElectrica&);

    friend ostream& operator<<(ostream&, MasinaElectrica&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    float calculAutonomie()
    {
        float temp;
        temp = capacitateBaterie / ( getGreutate() * getGreutate() ) ;
        this->setAutonomie(temp);
        return temp;
    }

    ~MasinaElectrica() {};

};

//----------CONSTRUCTORI--------------

MasinaElectrica::MasinaElectrica() : Masina() {

    capacitateBaterie = 0;
}

MasinaElectrica::MasinaElectrica(int anProductie, string model, float viteza, float greutate, float autonomie, float capacitateBaterie) : Masina( anProductie, model, viteza, greutate, autonomie) {

    this -> capacitateBaterie = capacitateBaterie;
}

MasinaElectrica::MasinaElectrica(const MasinaElectrica &m) : Masina(m) {

    this -> capacitateBaterie = m.capacitateBaterie;
}

//--------------IO--------------

void MasinaElectrica::citire(istream &in) {

    Masina::citire(in);
    cout << "Introduceti capacitatea bateriei: ";
    in >> capacitateBaterie;
}

void MasinaElectrica::afisare(ostream &out) {

    Masina::afisare(out);
    out << "Capacitate baterie: " << capacitateBaterie <<"MegaAmperi \n";
    out << "Autonomie : " << this->calculAutonomie() <<"\n" ;
}

istream &operator>>(istream &in, MasinaElectrica &m) {
    m.citire(in);
    return in;
}

ostream &operator<<(ostream &out, MasinaElectrica &m) {
    m.afisare(out);
    return out;
}

class MasinaHibrida : public Masina {

private:

public:


};

class Tranzactii {

private:
    string nume;
    string data;
    vector <MasinaFosil> mf;
    vector <MasinaElectrica> me;
public:

    Tranzactii();

    Tranzactii(string nume, string data, vector<MasinaFosil> mf, vector<MasinaElectrica> me);

    Tranzactii(const Tranzactii &t);

    Tranzactii operator=(const Tranzactii &);

    friend istream& operator>>(istream&, Tranzactii&);

    friend ostream& operator<<(ostream&, Tranzactii&);

    void citire(istream &in);

    void afisare(ostream &out);

    ~Tranzactii();

};

//----------CONSTRUCTORI--------------

Tranzactii::Tranzactii() {

    nume = "Necunoscut";
    data = "Necunoscuta";
}

Tranzactii::Tranzactii(string nume, string data, vector<MasinaFosil> mf, vector<MasinaElectrica> me) {

    this -> nume = nume;
    this -> data = data;
    this -> mf = mf;
    this -> me = me;
}

Tranzactii::Tranzactii(const Tranzactii &t) {

    this -> nume = t.nume ;
    this -> data = t.data ;
    this -> mf = t.mf ;
    this -> me = t.me;
}

Tranzactii Tranzactii::operator=(const Tranzactii &t) {

    if ( this != &t ) {
        //destructor aici pt dezalocare daca aveam altceva de dezalocat la lot perisabil;
        this -> nume = t.nume ;
        this -> data = t.data ;
        this -> mf = t.mf ;
        this -> me = t.me;
    }
return *this;
}

//--------------IO--------------

void Tranzactii::citire(istream &in) {

    cout << "Introduceti numele: ";
    in >> nume;
    cout << "Introduceti data efectuarii tranzactiei: ";
    in >> data;



    char optiune = 'a';
    while ( optiune != '0' )
    {
        cout << "Ce tip de masina doriti sa achizitionati ? \n1)Masina Combustibil Fosili \n2)Masina Electrica \n0)Exit \n";
    cin >> optiune ;
    if ( optiune == '1' )
        {
            MasinaFosil temp;
            cin >> temp;
            mf.push_back(temp);
        }
    if ( optiune == '2' )
        {
            MasinaElectrica temp;
            cin >> temp;
            me.push_back(temp);
        }
    }
}

void Tranzactii::afisare(ostream &out) {
    out << "Nume: " << nume << "\n" << "Data: " << data << "\n";
    out << "Modele de masini cumparate: \n";
    for ( int i = 0 ; i < mf.size() ; i++ )
        out << mf[i] <<"\n";
    for ( int i = 0 ; i < me.size() ; i++ )
        out << me[i] <<"\n";
}

istream &operator>>(istream &in, Tranzactii &t) {
    t.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Tranzactii &t) {
    t.afisare(out);
    return out;
}

Tranzactii::~Tranzactii() {

    mf.clear();
    me.clear();
}

int main() {

vector<MasinaFosil> masiniF;
vector<MasinaElectrica> masiniE;
vector<Tranzactii> tranz;
char optiune = 'a';

while (optiune != '0')
{
	cout << "\n1) Introdu model nou masina \n2) Afiseaza toate modelele \n3) Adauga tranzactie \n4) Afiseaza modelul de masina cu cea mai buna autonomie \n0) Exit \n\n";
	cout << "Introduceti optiunea: ";
	cin >> optiune;

    switch(optiune) {

        case '1' :
            {
                cout << "\n1) Masina Combustibil Fosil \n2) Masina Electrica";
                int optiune2;
                cout << "\nIntroduceti optiunea: ";
                cin >> optiune2;
                if ( optiune2 == 1 )
                {
                    MasinaFosil temp;
                    cin >> temp;
                    masiniF.push_back(temp);
                }
                if ( optiune2 == 2 )
                {
                    MasinaElectrica temp;
                    cin >> temp;
                    masiniE.push_back(temp);
                }
            break;
            }

        case '2' :
            {
                for ( int i = 0 ; i < masiniF.size() ; i ++ )
                    cout << masiniF[i] << "\n";
                for ( int j = 0 ; j < masiniE.size() ; j ++ )
                    cout << masiniE[j] << "\n";
            break;
            }

        case '3' :
            {
                Tranzactii temp;
                cin >> temp;
                tranz.push_back(temp);
            break;
            }

        case '4' :
            {
                float maximAutF = 0;
                float maximAutE = 0;
                int indiceF;
                int indiceE;
                for ( int i = 0 ; i < masiniF.size() ; i ++ )
                {
                    if ( masiniF[i].calculAutonomie() > maximAutF )
                    {
                        maximAutF = masiniF[i].calculAutonomie();
                        indiceF = i ;
                    }
                }

                for ( int j = 0 ; j < masiniE.size() ; j ++ )
                {
                    if ( masiniE[j].calculAutonomie() > maximAutE )
                    {
                        maximAutE = masiniE[j].calculAutonomie();
                        indiceE = j ;
                    }
                }

                if ( maximAutE > maximAutF )
                {
                    cout << "Modelul cu cea mai buna autonomie este " << masiniE[indiceE] <<"\n";
                    cout << "Acesta are o autonomie de " << maximAutE << "\n";
                }
                else
                {
                    cout << "Modelul cu cea mai buna autonomie este " << masiniE[indiceF] <<"\n";
                    cout << "Acesta are o autonomie de " << maximAutF << "\n";
                }
            break;
            }
    }

}

return 0;
}
