#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Decoratiune {

private:
    string nume;
    string culoare;
    int pret;
    bool reciclabila;

public:

    Decoratiune(string nume, string culoare, int pret, bool reciclabila);

    Decoratiune(const Decoratiune &deco);

    ~Decoratiune();

    friend istream &operator >> (istream & , Decoratiune & );

    friend ostream &operator << (ostream & , Decoratiune & );

    Decoratiune operator= (const Decoratiune &);

    void citire(istream &in);

    void afisare(ostream &out);

    int price(){
        return pret;
    }


};

Decoratiune::Decoratiune(string nume = "N/A", string culoare = "N/A", int pret = 0, bool reciclabila = 0) {

    this -> nume = nume;
    this -> culoare = culoare;
    this -> pret = pret;
    this -> reciclabila = reciclabila;
}

Decoratiune::Decoratiune(const Decoratiune &deco) {

    this -> nume = deco.nume;
    this -> pret = deco.pret;
    this -> culoare = deco.culoare;
    this -> reciclabila = deco.reciclabila;
}

Decoratiune Decoratiune::operator=(const Decoratiune &deco) {

    if ( this != &deco ) {

        this-> nume = deco.nume;
        this -> pret = deco.pret;
        this -> culoare = deco.culoare;
        this -> reciclabila = deco.reciclabila;
    }

return *this;
}

void Decoratiune::citire(istream &in) {

    cout << "Numele decoratiunii: ";
    in >> nume;
    cout << "Culoarea: ";
    in >> culoare;
    cout << "Pret : ";
    in >> pret;
    cout << "Reciclabila ? ( 0 - NU | 1 - DA ) : ";
    in >> reciclabila;

    cin.get();
}

void Decoratiune::afisare(ostream &out) {

    out << "Nume : " << nume << "\n";
    out << "Culoare: " << culoare << "\n";
    out << "Pret : " << pret << "\n";
    if ( reciclabila == 0 )
        out << "Decoratiunea NU este reciclabila" << "\n";
    else out << "Decoratiunea este reciclabila \n";
}

istream &operator>>(istream &in, Decoratiune &deco) {
    deco.citire(in);
    return in;
}

ostream &operator<<(ostream &out, Decoratiune &deco) {
    deco.afisare(out);
    return out;
}

Decoratiune::~Decoratiune() {
    nume.clear();
    culoare.clear();
}

class ListaProduse {

private:
    vector <Decoratiune> d;

public:

ListaProduse(){};

~ListaProduse() {};

ListaProduse operator+(Decoratiune a){
    d.push_back(a);
    return *this;
}

ListaProduse operator=(ListaProduse l){
    d = l.d;
    return *this;
}

void afisare(){
    for(int i = 0; i < d.size(); i++)
        cout << d[i];
}

Decoratiune &operator[](int index){
    return d[index-1];
}

int price(){
    int suma = 0;
    for(int i = 0; i < d.size(); i++)
        suma = suma + d[i].price();
    return suma;
}

void sterge(int index){
    d.erase(d.begin() + index - 1);
}

};

int main() {
Decoratiune d;
ListaProduse b;
cin >> d;
b = b + d;
cin >> d;
b = b + d;
b.afisare();
cout << b[1].price();
cout << b.price();
b.sterge(1);
b.afisare();
return 0;
}
