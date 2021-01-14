#include <iostream>
#include <vector>

using namespace std;

/// Ce nu merge: Outputul la riscul cardiovascular pt fiecare pacient e gresit. Arata doar pentru clasa de baza Pacient
/// Rezolvare ideala: O interfata cu functia calculeazaRisc(), suprascrisa in fiecare clasa derivata ( nu stiu sa fac )

class Pacient {

private:

    string nume;
    string prenume;
    int varsta;
    string adresa;
    string dataColesterol;
    string dataTensiune;
    float valoareColesterol;
    float valoareTensiune;

public:

    Pacient() ;

    Pacient(string nume, string prenume, int varsta, string adresa, string dataColesterol, string dataTensiune, float valoareColesterol, float ValoareTensiune);

    Pacient(const Pacient &p);

    Pacient operator=(const Pacient &);

    friend istream& operator>>(istream&, Pacient&);

    friend ostream& operator<<(ostream&, Pacient&);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    virtual bool calculeazaRisc() { if ( valoareTensiune >= 140 || valoareColesterol >= 240 ) return 1; else return 0;   }

    float getColesterol() { return valoareColesterol; }

    float getTensiune() { return valoareTensiune; }

    string getNume() { return nume; }

    ~Pacient() {}; // nu am nimic de dezalocat

};

//----------CONSTRUCTORI--------------

Pacient::Pacient() {

    nume = "Anonim";
    prenume = "Anonim";
    adresa = "N/A";
    dataColesterol = "N/A";
    dataTensiune = "N/A";
    varsta = 0;
    valoareColesterol = 0;
    valoareTensiune = 0;

}

Pacient::Pacient(string nume, string prenume, int varsta, string adresa, string dataColesterol, string dataTensiune, float valoareColesterol, float ValoareTensiune) {

    this -> nume = nume;
    this -> prenume = prenume;
    this -> adresa = adresa;
    this -> varsta = varsta;
    this -> dataColesterol = dataColesterol;
    this -> dataTensiune = dataTensiune;
    this -> valoareColesterol = valoareColesterol;
    this -> valoareTensiune = ValoareTensiune;
}

Pacient::Pacient (const Pacient &p) {

    this -> nume = p.nume;
    this -> prenume = p.prenume;
    this -> adresa = p.adresa;
    this -> varsta = p.varsta;
    this -> dataColesterol = p.dataColesterol;
    this -> dataTensiune = p.dataTensiune;
    this -> valoareColesterol = p.valoareColesterol;
    this -> valoareTensiune = p.valoareTensiune;
}

Pacient Pacient::operator= (const Pacient &p) {

    if ( this != &p ) {
        this -> nume = p.nume;
        this -> prenume = p.prenume;
        this -> adresa = p.adresa;
        this -> varsta = p.varsta;
        this -> dataColesterol = p.dataColesterol;
        this -> dataTensiune = p.dataTensiune;
        this -> valoareColesterol = p.valoareColesterol;
        this -> valoareTensiune = p.valoareTensiune;
    }
    return *this;
}

//--------------IO--------------

void Pacient::afisare(ostream &out) {

    string temp;
    if ( calculeazaRisc() == 0 )
        temp = "NU";
    else temp = "DA";
    out << nume << " " << prenume << ": Risc Cardiovascular: " << temp << "; Colesterol ( " << dataColesterol << " ) : "<<valoareColesterol << " mg/dl ; TA ( " << dataTensiune << " ) : " << valoareTensiune <<"\n";
}

void Pacient::citire(istream &in) {

    cout << "Nume pacient: \n";
    in >> nume;
    cout << "Prenume pacient: \n";
    in >> prenume;
    cout << "Adresa Pacient: \n";
    in >> adresa;
    cout << "Varsta Pacient: \n";
    in >> varsta;
    cout << "Data Analize Colesterol: \n";
    in >> dataColesterol;
    cout << "Valoare Colesterol: \n";
    in >> valoareColesterol;
    cout << "Data Analize Tensiune: \n";
    in >> dataTensiune;
    cout << "Valoare Tensiune: \n";
    in >> valoareTensiune;

}

istream& operator>>(istream &in, Pacient& p){
    p.citire(in);
    return in;
}

ostream& operator<<(ostream &out, Pacient& p){
    p.afisare(out);
    return out;
}


//----------EXTINDERE 1-----------

class PacientPeste40: public Pacient {

private:

    bool fumator;
    char sedentarism; // S, M sau R

public:

    PacientPeste40() ;

    PacientPeste40(string nume, string prenume, int varsta, string adresa, string dataColesterol, string dataTensiune,
                   float valoareColesterol, float ValoareTensiune, bool fumator, char sedentarism);

    PacientPeste40(const PacientPeste40 &p);

    PacientPeste40 operator=(const PacientPeste40 &);

    friend istream& operator>>(istream&, PacientPeste40&);

    friend ostream& operator<<(ostream&, PacientPeste40&);

    void citire(istream &in);

    void afisare(ostream &out);

    bool calculeazaRisc() { if ( (getColesterol() >= 240 || getTensiune() >= 140 ) && sedentarism == 'R' ) return 1;
                            if ( (getColesterol() >= 240 || getTensiune() >= 140 ) && sedentarism == 'M' ) return 2;
                            if ( getColesterol() < 240 || getTensiune() < 140 ) return 0;   }

    ~PacientPeste40() {}; // nu am nimic de dezalocat

};

//----------CONSTRUCTORI--------------

PacientPeste40::PacientPeste40() : Pacient() {

    fumator = 0;
    sedentarism = '0' ;
}

PacientPeste40::PacientPeste40(string nume, string prenume, int varsta, string adresa, string dataColesterol, string dataTensiune, float valoareColesterol,
                               float ValoareTensiune, bool fumator, char sedentarism) : Pacient ( nume, prenume, varsta, adresa, dataColesterol, dataTensiune, valoareColesterol , ValoareTensiune) {

    this -> fumator = fumator;
    this -> sedentarism = sedentarism;
}

PacientPeste40::PacientPeste40(const PacientPeste40 &p) : Pacient(p) {

    fumator = p.fumator;
    sedentarism = p.sedentarism;
}

PacientPeste40 PacientPeste40:: operator=(const PacientPeste40 &p) {
    if ( this != &p ) {
        Pacient::operator=(p);
        //destructor aici pt dezalocare daca aveam altceva de dezalocat la lot perisabil;
        this -> fumator = p.fumator;
        this -> sedentarism = p.sedentarism;
    }
return *this;
}

//--------------IO--------------

void PacientPeste40::afisare(ostream &out) {

    Pacient::afisare(out);
    if ( fumator == 1 ) out << "Fumator : DA \n";
        else out << "Fumator : NU \n";
    cout << "Sedentarism: " << sedentarism << "\n";
}

void PacientPeste40::citire(istream &in) {

    Pacient::citire(in);
    cout << "Fumator (1 - DA | 0 - NU ): ";
    in >> fumator;
    cout << "Sedentarism ( S - scazut | M - mediu | R - ridicat ) : ";
    in >> sedentarism;
}

istream &operator>>(istream &in, PacientPeste40 &p) {
    p.citire(in);
    return in;
}

ostream &operator<<(ostream &out, PacientPeste40 &p) {
    p.afisare(out);
    return out;
}

//----------EXTINDERE 2-----------


class Copil: public Pacient {

private:

    string numeparinte1;
    string numeparinte2;
    bool predispunere;
    string dataProteinaC;
    float valoareProteinaC;

public:

    Copil() ;

    Copil(string nume, string prenume, int varsta, string adresa, string dataColesterol, string dataTensiune, float valoareColesterol,
          float ValoareTensiune, bool predispunere, string numeparinte1, string numeparinte2, string dataProteinaC, float valoareProteinaC);

    Copil(const Copil &p);

    Copil operator=(const Copil &);

    friend istream& operator>>(istream&, Copil&);

    friend ostream& operator<<(ostream&, Copil&);

    void citire(istream &in);

    void afisare(ostream &out);

    bool getPredispunere() { return predispunere; }

    float getProteina() { return valoareProteinaC; }

    ~Copil() {}; // nu am nimic de dezalocat
};

//----------CONSTRUCTORI--------------

Copil::Copil() : Pacient() {

    numeparinte1 = "Anonim 1 ";
    numeparinte2 = "Anonim 2 ";
    predispunere = 0;
    dataProteinaC = "N/A";
    valoareProteinaC = 0;
}

Copil::Copil(string nume, string prenume, int varsta, string adresa, string dataColesterol, string dataTensiune, float valoareColesterol, float ValoareTensiune,
              bool predispunere, string numeparinte1, string numeparinte2, string dataProteinaC, float valoareProteinaC) : Pacient ( nume, prenume, varsta, adresa, dataColesterol, dataTensiune, valoareColesterol , ValoareTensiune) {

    this -> numeparinte1 = numeparinte1 ;
    this -> numeparinte2 = numeparinte2 ;
    this -> dataProteinaC = dataProteinaC;
    this -> predispunere = predispunere ;
    this -> valoareProteinaC = valoareProteinaC;
}

Copil::Copil(const Copil &p) : Pacient(p) {

    numeparinte1 = p.numeparinte1 ;
    numeparinte2 = p.numeparinte2 ;
    dataProteinaC = p.dataProteinaC;
    predispunere = p.predispunere ;
    valoareProteinaC = p.valoareProteinaC;
}

Copil Copil:: operator=(const Copil &p) {
    if ( this != &p ) {
        Pacient::operator=(p);
        //destructor aici pt dezalocare daca aveam altceva de dezalocat la lot perisabil;
        this -> numeparinte1 = p.numeparinte1 ;
        this -> numeparinte2 = p.numeparinte2 ;
        this -> dataProteinaC = p.dataProteinaC;
        this -> predispunere = p.predispunere ;
        this -> valoareProteinaC = p.valoareProteinaC;
    }
return *this;
}

//--------------- IO ---------------

void Copil::afisare(ostream &out) {

    Pacient::afisare(out);
    out << "Parinti: " << numeparinte1 << " si " << numeparinte2 << " \n";
    out << "Proteina C reactiva ( " << dataProteinaC << " ) : "<< valoareProteinaC << " mg/dl \n ";
    if ( predispunere == 1 ) out << "Antecedente : DA \n";
        else out << "Antecedente : NU \n";
}

void Copil::citire(istream &in) {

    Pacient::citire(in);
    cout << "Nume Mama: ";
    in >> numeparinte1;
    cout << "Nume Tata: ";
    in >> numeparinte2;
    cout << "Predispunere ( Antecedente ) (1 - DA | 0 - NU ): ";
    in >> predispunere;
    cout << "Data Analize Proteina C : ";
    in >> dataProteinaC;
    cout << "Valoare Proteina C: ";
    in >> valoareProteinaC;
}

istream &operator>>(istream &in, Copil &p) {
    p.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Copil &p) {
    p.afisare(out);
    return out;
}

int main() {

vector <Pacient*> listaPacienti;
vector <Pacient> listasub40;
vector <PacientPeste40> listapeste40;
vector <Copil> listacopii;
char optiune = 'a';

while (optiune != '0')
{
	cout << "\n1) Introdu pacient \n2) Afiseaza toti pacientii \n3) Afiseaza informatii pentru copiii cu risc cardiovascular \n4) Afiseaza informatii pentru toti adultii cu risc cardiovascular \n5) Cauta pacient dupa numele de familie \n0) Exit \n\n";
	cout << "Introduceti optiunea: ";
	cin >> optiune;

    switch(optiune) {

        case '1':
        {
        cout << "\n1) Adauga pacient adult sub 40 \n2) Adauga pacient adult peste 40 \n3) Adauga pacient copil";
				cout << "\nIntroduceti optiunea: ";
				int comanda2;
				cin >> comanda2;
				switch (comanda2)
				{
					case 1:
						{
							Pacient p;
							cin >> p;
							listasub40.push_back(p);
							break;
						}

					case 2:
						{
							PacientPeste40 p;
							cin >> p;
							listapeste40.push_back(p);
							break;
						}

                    case 3:
                        {
							Copil c;
							cin >> c;
							listacopii.push_back(c);
							break;
                        }
				}
        break;
        }

        case '2' :

        {
            cout << "Adulti: \n";
            cout << "Adulti peste 40 de ani: \n";
            for ( int i = 0 ; i < listapeste40.size() ; i++ )
            {
                cout << listapeste40[i] << "\n";
            }
            cout << "Adulti sub 40 de ani: \n";
            for ( int i = 0 ; i < listasub40.size() ; i++ )
            {
                cout << listasub40[i] << "\n";
            }
            cout << "Copii \n";
            for ( int i = 0 ; i < listacopii.size() ; i++ )
            {
                cout << listacopii[i] << "\n";
            }
				break;
        }

        case '3' :

        {
            if ( listacopii.size() > 0 )
            {
                for ( int i = 0 ; i < listacopii.size() ; i++ )
                {
                    if ( listacopii[i].getPredispunere() == 1 )
                        cout << listacopii[i] << "\n";
                    else cout << "Nu exista pacienti copii cu risc cardiovascular !";
                }
            }
            else cout << "Lista de pacienti copii este goala !";

            break;

        }

        case '4' :

        {
            if ( listasub40.size() > 0 )
            {
                for ( int i = 0 ; i < listasub40.size() ; i++ )
                {
                    if ( listasub40[i].getColesterol() >= 240 || listasub40[i].getTensiune() >= 140 )
                        cout << listasub40[i] << "\n";
                    else cout << "Nu exista pacienti sub 40 de ani cu risc cardiovascular !\n";
                }
            }
            else cout << "Lista de pacienti sub 40 este goala !";

            if ( listapeste40.size() > 0 )
            {
                for ( int i = 0 ; i < listapeste40.size() ; i++ )
                {
                    if ( listapeste40[i].getColesterol() >= 240 || listapeste40[i].getTensiune() >= 140 )
                        cout << listapeste40[i] << "\n";
                    else cout << "Nu exista pacienti peste 40 de ani cu risc cardiovascular !\n";
                }
            }
            else cout << "Lista de pacienti peste 40 este goala !\n";

            break;

        }

        case '5' :

        {
                string temp;
                cout << "\nIntroduceti numele de familie al pacientului: ";
                cin >> temp;
                cout << "\nUrmatorii pacienti cu numele de familie "<<temp << " au fost identificati: \n";
                for ( int i = 0 ; i < listasub40.size() ; i++ )
                {
                    if ( listasub40[i].getNume() == temp )
                    cout << listasub40[i] << "\n";
                }
                for ( int i = 0 ; i < listapeste40.size() ; i++ )
                {
                    if ( listapeste40[i].getNume() == temp )
                    cout << listapeste40[i] << "\n";
                }
                for ( int i = 0 ; i < listacopii.size() ; i++ )
                {
                    if ( listacopii[i].getNume() == temp )
                    cout << listacopii[i] << "\n";
                }
        break;
        }

        case '0' : break;
    }

}
return 0;
}
