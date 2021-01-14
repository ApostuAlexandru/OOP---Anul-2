#include <iostream>
#include <string>

using namespace std;

class Automobil {

private:
    string marca;
    string model;

public:

Automobil() {
    this -> marca = "Unknown";
    this -> model = "Unknown";
}

Automobil(string marca, string model){

    this -> marca = marca;
    this -> model = model;
}

friend istream& operator >>(istream& in, Automobil& a){

    a.citire(in);
    return in;
}

/*
friend ostream& operator<<(ostream& out, Automobil& a){

    a.afisare(out);
    return out;
}
*/

virtual void citire(istream &in){

    cout<<"Marca: ";
    in >> marca;
    cout<<"Modelul: ";
    in >> model;
    cin.get();
}

virtual void afisare(){

    cout << marca << "\n" << model << "\n";
}

Automobil& operator =(const Automobil& a){        /// Operator =

    if(this != &a){

    this -> marca = a.marca;
    this -> model = a.model;
        }
    }

};

class Undercover: public Automobil {

private:
    int nrGloante;
    float viteza;

public:

    friend istream &operator>>(istream &in, Undercover &u){
        u.citire(in);
        return in;
    }

    /*
    friend ostream &operator<<(ostream &out, Undercover &u){
        u.afisare(out);
        return out;
    }
    */

    void citire(istream &in){
        Automobil::citire(in);
        cout << "Rezistenta ( Nr gloante ) : ";
        in >> nrGloante;
        cout << "Viteza: ";
        in >> viteza;
    }

    void afisare(){
        Automobil::afisare();
        cout << "Rezistenta :" << nrGloante << " gloante. \n";
        cout << "Viteza: " << viteza << "\n";
    }

};

class Interventie: public Automobil {

    string arma = "Mitraliera R-85";
    int nrCartuse = 750;

public:

    friend istream &operator>>(istream &in, Interventie &i){
        i.citire(in);
        return in;
    }

    /*
    friend ostream &operator<<(ostream &out, Interventie &i){
        i.afisare(out);
        return out;
    }
    */

    void citire(istream &in){
        Automobil::citire(in);
    }

    void afisare(){
        Automobil::afisare();
        cout << "Masina e folosita la interventii. \n";
        cout << "Masina e dotata cu "<<arma << ", avand "<<nrCartuse <<"cartuse. \n";
    }

};

class EmisieReceptie: public Automobil {

    float distEmisie;
    float distReceptie;

public:

    friend istream &operator>>(istream &in, EmisieReceptie &e){
        e.citire(in);
        return in;
    }

    /*
    friend ostream &operator<<(ostream &out, EmisieReceptie &e){
        e.afisare(out);
        return out;
    }
    */

    void citire(istream &in){
        Automobil::citire(in);
        cout << "Distanta Emisie : ";
        in >> distEmisie;
        cout << "Distanta Receptie: ";
        in >> distReceptie;
    }

    void afisare(){
        Automobil::afisare();
        cout << "Distanta Emisie :" << distEmisie << "\n";
        cout << "Distanta Receptie: " << distReceptie << "\n";
    }

};

class ListaMasini {

private:


public:

    Automobil *a[100];
    int k = 0;

    ListaMasini operator+(Automobil &m) {
        a[k] = &m;
        k ++;
    return *this;
    }

};

int main()
{

 Undercover u;
 cout << " Automobil undercover : \n";
 cin >> u;
 Interventie i;
 cout << " Automobil Interventii : \n";
 cin >> i;
 EmisieReceptie e;
 cout << " Automobil Emisie-Receptie : \n";
 cin >> e;

 ListaMasini lista;
 lista = lista + u;
 lista = lista + i;
 lista = lista + e;

/*for ( int i = 0; i < lista.k; i ++)
{
    cout <<"Automobil "<<i+1<<" : \n";
    cout << "\n"<<*lista.a[i]<<"\n";
}*/

for ( int i = 0 ; i < lista.k ; i ++)
{
    cout << "Automobil " << i+1 << "\n";
    lista.a[i]->afisare();
}
return 0;
}
