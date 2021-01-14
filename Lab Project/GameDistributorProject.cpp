#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <set>
#include <iterator>

using namespace std;

class Corporation;

class Game;

class Person;

class Corporation {

private:

    const char corpName[13] = "Doobie Gamez";
    double netWorth;
    int numberOfEmployees;
    char *foundingDate;
    int ranking;
    bool LFE;
    static int numberOfCorporations;

protected:

public:

    Corporation();

    Corporation(double netWorth, int numberOfEmployees, char *foundingDate, int ranking, bool LFE);

    Corporation(const char *foundingDate);

    Corporation(const Corporation &corp);

    ~Corporation();

    friend istream &operator>>(istream &, Corporation &);

    friend ostream &operator<<(ostream &, Corporation &);

    Corporation operator=(const Corporation &);

    void citire(istream &in);

    void afisare(ostream &out);

/// ------------------------------------------- Setteri ------------------------------------------------ ///

    void setFoundingDate(char *data);

    void setRanking(int ranking) { this->ranking = ranking; }

    void setLFE(bool LFE) { this->LFE = LFE; }

    void setNumberOfEmployees(int numberOfEmployees) { this->numberOfEmployees = numberOfEmployees; }

/// ------------------------------------------- Getteri ------------------------------------------------ ///

    const char getCorpName() { return this->corpName[13]; }

    double getNetWorth() { return this->netWorth; }

    int getNumberOfEmployees() { return this->numberOfEmployees; }

    char *getFoundingDate() { return this->foundingDate; }

    int getRanking() { return this->ranking; }

    bool getLFE() { return this->LFE; }

};

/// ---------------------------------------------------------------------------------------------------- ///

int Corporation::numberOfCorporations; // am declarat variabila statica

/// ---------------------------------- Functii Citire + Afisare ---------------------------------------- ///

void Corporation::citire(istream &in) {

    char aux[100];

    cout << "Introduceti data la care a fost fondata compania: \n";
    in.get(aux, 100);
    if (foundingDate != nullptr)
        delete[] foundingDate;
    foundingDate = new char[strlen(aux) + 1];
    strcpy(foundingDate, aux);

    cout << "Introduceti valoarea companiei: \n";
    in >> netWorth;
    cout << "Introduceti numarul de angajati: \n";
    in >> numberOfEmployees;
    cout << "Introduceti numarul companiei in clasament: \n";
    in >> ranking;
    cout << "Compania cauta angajati? ( 1 - DA | 0 - NU ) \n";
    in >> LFE;
    cin.get();
}

void Corporation::afisare(ostream &out) {
    out << fixed;
    out << setprecision(2);
    out << "Compania dvs. se numeste " << corpName << "." << endl;
    out << corpName << " a fost fondata la data de " << foundingDate << " si are in prezent " << numberOfEmployees
        << " angajati." << endl;
    out << "Compania se situeaza pe pozitia " << ranking << " in clasament si valoreaza aprox. " << netWorth << " $ ."
        << endl;
    if (LFE == 1) out << corpName << " este in cautare de noi angajati." << endl;
    if (LFE == 0) out << corpName << " nu are joburi disponibile momentan. " << endl;
}

/// Alte functii / setteri :

void Corporation::setFoundingDate(char *data) {

    if (this->foundingDate != nullptr)
        delete[] this->foundingDate;
    this->foundingDate = new char[strlen(data) + 1];
    strcpy(this->foundingDate, data);
}

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Corporation::Corporation() {

    //cout << "CFP" << endl;
    this->netWorth = 0;
    this->numberOfEmployees = 0;
    this->foundingDate = new char[strlen("Unknown") +
                                  4];     // Vreau 11 caractere ca in formatul DD.MM.YYYY, dar sa se intializeze by default cu unknown
    strcpy(this->foundingDate, "Unknown");
    this->ranking = 0;
    this->LFE == 0;
    numberOfCorporations++;
}

///                                    Constructorul 1 cu parametri                                     ///

Corporation::Corporation(double netWorth, int numberOfEmployees, char *foundingDate, int ranking, bool LFE) {

    //cout << "CP 1" << endl;
    this->netWorth = netWorth;
    this->numberOfEmployees = numberOfEmployees;
    this->ranking = ranking;
    this->LFE = LFE;
    this->foundingDate = new char[strlen("DD.MM.YYYY") + 1];
    strcpy(this->foundingDate, foundingDate);
    numberOfCorporations++;
}

///                                   Constructorul 2 cu parametri                                      ///

Corporation::Corporation(const char *foundingDate) {

    //cout << "CP 2" << endl;
    this->netWorth = 0;
    this->numberOfEmployees = 0;
    this->foundingDate = new char[strlen("DD.MM.YYYY") + 1];
    strcpy(this->foundingDate, foundingDate);
    this->ranking = 0;
    this->LFE == 0;
    numberOfCorporations++;
}

///                                     Constructorul de copiere                                       ///

Corporation::Corporation(const Corporation &corp) {

    //cout << "CC" << endl;
    this->netWorth = corp.netWorth;
    this->numberOfEmployees = corp.numberOfEmployees;
    this->ranking = corp.ranking;
    this->LFE = corp.LFE;
    this->foundingDate = new char[strlen(corp.foundingDate) + 1];
    strcpy(this->foundingDate, corp.foundingDate);
}

/// Destructor ///

Corporation::~Corporation() {

    //cout << "DST" << endl;
    if (this->foundingDate != NULL)
        delete[] this->foundingDate;

    numberOfCorporations--;
}

/// ------------------------------------------- Supraincarcari ------------------------------------------- ///

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Corporation &corp) {
    corp.citire(in);
    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Corporation &corp) {
    corp.afisare(out);
    return out;
}

///                                                 "="                                                    ///

Corporation Corporation::operator=(const Corporation &corp) {

    if (this != &corp) {

        //cout << "EGAL" << endl;
        this->netWorth = corp.netWorth;
        this->ranking = corp.ranking;
        this->numberOfEmployees = corp.numberOfEmployees;
        this->LFE = corp.LFE;

        if (this->foundingDate != nullptr)
            delete[] this->foundingDate;
        this->foundingDate = new char[strlen(corp.foundingDate) + 1];
        strcpy(this->foundingDate, corp.foundingDate);
    }

    return *this;
}

/// --------------------------------------------------------------------------------------------------------- ///

class Game {

private:
    // string releaseDate;
    char *gName;
    char gGenre[20];
    char ageRating;
    int copiesSold;
    float gPrice;
    float *dlcPrices;
    double hoursPlayed;
    const char gPlatform[8] = "Windows";
    static int numberOfGames;
    bool available;

protected:

public:

    Game();

    Game(char ageRating, char *gName, char gGenre[20], int copiesSold, float gPrice, float *dlcPrices,
         double hoursPlayed);

    Game(const char *gName);

    Game(const Game &g);

    ~Game();

    friend istream &operator>>(istream &, Game &);

    friend ostream &operator<<(ostream &, Game &);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    Game operator=(const Game &);

    ///                                      Operatori + Functii membre                                        ///

    int operator[](
            int index) { return dlcPrices[index]; } // Supraincarcare [] -> Returneaza pretul unui DLC de la pozitia index-ului

    Game operator++() {                // Supraincarcare ++ prefix -> Mareste pretul jocului cu 25%
        gPrice = 1.25 * gPrice;
        return *this;
    }

    Game operator++(int) {           // Supraincarcare ++ postfix
        gPrice = 1.25 * gPrice;
        return *this;
    }

    Game operator--() {                // Supraincarcare -- prefix -> Reduce pretul unui joc cu 25%
        gPrice = 0.75 * gPrice;
        return *this;
    }

    Game operator--(int) {           // Supraincarcare -- postfix
        gPrice = 0.75 * gPrice;
        return *this;
    }

    float operator+(float x) {         // Supraincarcare + -> adauga x la pret
        return gPrice + x;
    }

    double operator*(double x) {         // Supraincarcare * -> adauga x la orele totale jucate
        return hoursPlayed + x;
    }

    Game operator+=(float x) {       // Supraincarcare +=  -> Modifica pretul din obiect cu x
        gPrice += x;
        return *this;
    }

    Game operator-=(float x) {       // Supraincarcare -=  -> Modifica pretul din obiect cu x
        gPrice -= x;
        return *this;
    }

    bool
    operator<(const Game &g) {    // Supraincarcare " < "     -> Compara numarul de ore jucate ( popularitatea jocului )

        if (this->hoursPlayed < g.hoursPlayed)
            return true;
        else return false;
    }

    bool operator>(const Game &g) {    // Supraincarcare " >"

        if (this->hoursPlayed > g.hoursPlayed)
            return true;
        else return false;
    }

    bool operator==(const Game &g) {      // Supraincarcare " == "

        if (strcmp(this->gName, g.gName) == 0 && this->gPrice == g.gPrice && this->copiesSold == g.copiesSold)
            return true;
        else return false;
    }

    explicit operator int() { return (int) this->gPrice; }     // Supraincarcare cast

/// Setteri:

    void setName(char *nume);

    void setAgeRating(char ageRating) { this->ageRating = ageRating; }

    void setCopiesSold(int copiesSold) { this->copiesSold = copiesSold; }

    void setPrice(float gPrice) { this->gPrice = gPrice; }

    void setAvailable(bool available) { this->available = available; }

    void setHoursPlayed(double hoursPlayed) { this->hoursPlayed = hoursPlayed; }

/// Getteri:

    char *getNume() { return this->gName; }

    char getAgeRating() { return this->ageRating; }

    int getCopiesSold() { return this->copiesSold; }

    float getPrice() { return this->gPrice; }

    bool getAvailable() { return this->available; }

    double getHoursPlayed() { return this->hoursPlayed; }

    static int getnumberOfGames() { return numberOfGames; }

};

int Game::numberOfGames;

/// ---------------------------------- Functii Citire + Afisare ---------------------------------------- ///

void Game::citire(istream &in) {

    char aux[100];

    cout << "Introduceti numele jocului: \n";
    in.get(aux, 100);

    if (gName != nullptr)
        delete[] gName;
    gName = new char[strlen(aux) + 1];
    strcpy(gName, aux);

    cout << "E disponibil pe piata? ( 1 - DA | 0 - NU ) \n";
    in >> available;
    cout << "Introduceti rating-ul de varsta: ( E | M | T | A ) \n";
    in >> ageRating;
    cout << "Introduceti genul jocului: \n";
    in >> gGenre;
    cout << "Introduceti pretul: \n";
    in >> gPrice;
    cout << "Introduceti numarul de ore jucate: \n";
    in >> hoursPlayed;
    cout << "Introduceti numarul de copii vandute: \n";
    in >> copiesSold;
    cin.get();
}

void Game::afisare(ostream &out) {

    out << fixed;
    out << setprecision(2);

    out << "\nJocul cautat este " << gName << " , exclusiv pentru sistemul de operare " << gPlatform << " .\n" << endl;

    if (available == 1)
        out << "Acesta este disponibil in librarie.\n";
    if (available == 0)
        out << "Acesta nu este disponibil momentan.\n";

    out << "Gen : " << gGenre << "." << endl;
    if (ageRating == 'E' || ageRating == 'e') out << "Age rating : Everyone \n";
    if (ageRating == 'M' || ageRating == 'm') out << "Age rating : Mature \n";
    if (ageRating == 'T' || ageRating == 't') out << "Age rating : Teen \n";
    if (ageRating == 'A' || ageRating == 'a') out << "Age rating : Adult \n";
    out << "Pret : " << (float) gPrice << " $" << endl;
    out << "Total ore jucate : " << hoursPlayed << endl;
    out << "Total copii vandute : " << copiesSold << endl;
    //out << "Numarul total de jocuri din libraria noastra este " << getnumberOfGames() << "." << endl;
}

/// Alte Functii:

void Game::setName(char *nume) {

    if (this->gName != nullptr)
        delete[] this->gName;
    this->gName = new char[strlen(nume) + 1];
    strcpy(this->gName, nume);
}

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Game::Game() {

    //cout << "CFP" << endl;

    numberOfGames++;
    this->gPrice = (float) 0;
    this->copiesSold = 0;

    strcpy(gGenre, "Unlisted");

    this->gName = new char[strlen("Unnamed") + 1];
    strcpy(this->gName, "Unnamed");

    dlcPrices = new float[5];
}

///                                    Constructorul 1 cu parametri                                      ///

Game::Game(char ageRating, char *gName, char gGenre[20], int copiesSold, float gPrice, float *dlcPrices,
           double hoursPlayed) {

    //cout << "CP 1" << endl;

    numberOfGames++;
    this->ageRating = ageRating;
    this->copiesSold = copiesSold;
    this->gPrice = gPrice;
    this->hoursPlayed = hoursPlayed;

    strcpy(this->gGenre, gGenre);

    this->gName = new char[30];
    strcpy(this->gName, gName);

    this->dlcPrices = new float[5]; // Fiecare joc va avea maxim 5 DLC - uri

}

///                                    Constructorul 2 cu parametri                                      ///

Game::Game(const char *gName) {

    //cout << "CP 2" << endl;
    numberOfGames++;

    numberOfGames++;
    this->ageRating = ageRating;
    this->copiesSold = copiesSold;
    this->gPrice = gPrice;
    this->hoursPlayed = hoursPlayed;

    strcpy(this->gGenre, gGenre);

    this->gName = new char[30];
    strcpy(this->gName, gName);

    this->dlcPrices = new float[5];
}

///                                     Constructorul de copiere                                       ///

Game::Game(const Game &g) {

    //cout << "CC" << endl;

    numberOfGames++;

    this->ageRating = g.ageRating;
    this->copiesSold = g.copiesSold;
    this->gPrice = g.gPrice;
    this->hoursPlayed = g.hoursPlayed;
    this->available = g.available;

    strcpy(this->gGenre, g.gGenre);

    this->gName = new char[30];
    strcpy(this->gName, g.gName);

    this->dlcPrices = new float[5];
    for (int i = 0; i < 5; i++)
        this->dlcPrices[i] = dlcPrices[i];

}

/// Destructor ///

Game::~Game() {

    //cout << "DST" << endl;

    if (this->gName != NULL)
        delete[] this->gName;

    if (this->dlcPrices != NULL)
        delete[] this->dlcPrices;

    strcpy(this->gGenre, "");

    numberOfGames--;
}

/// ------------------------------------------- Supraincarcari ------------------------------------------- ///

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Game &g) {
    g.citire(in);
    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Game &g) {
    g.afisare(out);
    return out;
}

///                                                 "="                                                    ///

Game Game::operator=(const Game &g) {

    if (this != &g) {

        cout << "EGAL" << endl;

        if (this->gName != nullptr)
            delete[] this->gName;
        this->gName = new char[strlen(g.gName) + 1];
        strcpy(this->gName, g.gName);

        if (this->dlcPrices != nullptr)
            delete[] this->dlcPrices;

        dlcPrices = new float[5];
        for (int i = 0; i < 5; i++)
            this->dlcPrices[i] = dlcPrices[i];

        strcpy(this->gGenre, g.gGenre);

        this->ageRating = g.ageRating;
        this->available = g.available;
        this->gPrice = g.gPrice;
        this->copiesSold = g.copiesSold;
        this->hoursPlayed = g.hoursPlayed;
    }

    return *this;
}

/// -------------------------------------  Extinderea clasei ( 1 )   -------------------------------------------- ///

class Singleplayer : public Game {

private:
    string difficulty;
    bool storyRich;
public:
    Singleplayer();

    Singleplayer(char ageRating, char *gName, char gGenre[20], int copiesSold, float gPrice, float *dlcPrices,
                 double hoursPlayed, string difficulty, bool storyRich);

    Singleplayer(const Singleplayer &sp);

    ~Singleplayer();

    friend istream &operator>>(istream &in, Singleplayer &sp);

    friend ostream &operator<<(ostream &out, Singleplayer &sp);

    void citire(istream &in);

    void afisare(ostream &out);

    //void calcPricePerPlayer();

    Singleplayer operator=(const Singleplayer &);

};

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Singleplayer::Singleplayer() : Game() {

    this->difficulty = "Unknown difficulty";
    this->storyRich = 0;
}

///                                    Constructorul cu parametri                                      ///

Singleplayer::Singleplayer(char ageRating, char *gName, char gGenre[20], int copiesSold, float gPrice, float *dlcPrices,
                           double hoursPlayed, string difficulty, bool storyRich) {

    cout << "Constructor Singleplayer \n";
    this->difficulty = difficulty;
    this->storyRich = storyRich;
}

///                                     Constructorul de copiere                                       ///

Singleplayer::Singleplayer(const Singleplayer &sp) : Game(sp) {

    cout << "Copy Constructor Singleplayer Game \n";
    difficulty = sp.difficulty;
    storyRich = sp.storyRich;
}

/// Destructor ///

Singleplayer::~Singleplayer() {

    cout << "DST Singleplayer \n";
}

/// ------------------------------------------- Supraincarcari ------------------------------------------- ///

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Singleplayer &sp) {
    sp.citire(in);
    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Singleplayer &sp) {
    sp.afisare(out);
    return out;
}

///                                                 "="                                                    ///

Singleplayer Singleplayer::operator=(const Singleplayer &sp) {

    this->Game::operator=(sp);

    if (this != &sp) {

        this->difficulty = sp.difficulty;
        this->storyRich = sp.storyRich;
    }
    return *this;
}

/// ---------------------------------- Functii Citire + Afisare ---------------------------------------- ///

void Singleplayer::citire(istream &in) {

    Game::citire(in);
    cout << "Este jocul bazat pe firul unei povesti? 1 - DA | 0 - NU \n";
    in >> storyRich;
    cout << "Introduceti dificultatea jocului: \n";
    in >> difficulty;
}

void Singleplayer::afisare(ostream &out) {

    Game::afisare(out);
    out << "Difficulty: " << difficulty << "\n";
    if (storyRich) out << "Jocul este bazat pe o poveste ampla.\n";
    else out << "Jocul nu urmareste un fir narativ. \n";
}

/// -------------------------------------  Extinderea clasei ( 2 )   -------------------------------------------- ///

class Multiplayer : public Game {

private:
    double totalPlayers;
    bool microTransactions;
public:
    Multiplayer();

    Multiplayer(char ageRating, char *gName, char gGenre[20], int copiesSold, float gPrice, float *dlcPrices,
                double hoursPlayed, double totalPlayers, bool microTransactions);

    Multiplayer(const Multiplayer &mp);

    ~Multiplayer();

    friend istream &operator>>(istream &in, Multiplayer &sp);

    friend ostream &operator<<(ostream &out, Multiplayer &sp);

    void citire(istream &in);

    void afisare(ostream &out);

    Multiplayer operator=(const Multiplayer &);

};

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Multiplayer::Multiplayer() : Game() {

    this->totalPlayers = 0;
    this->microTransactions = 0;
}

///                                    Constructorul cu parametri                                      ///

Multiplayer::Multiplayer(char ageRating, char *gName, char gGenre[20], int copiesSold, float gPrice, float *dlcPrices,
                         double hoursPlayed, double totalPlayers, bool microTransactions) {

    cout << "Constructor Multiplayer \n";
    this->totalPlayers = totalPlayers;
    this->microTransactions = microTransactions;
}

///                                     Constructorul de copiere                                       ///

Multiplayer::Multiplayer(const Multiplayer &mp) : Game(mp) {

    cout << "Copy Constructor Multiplayer Game \n";
    totalPlayers = mp.totalPlayers;
    microTransactions = mp.microTransactions;
}

/// Destructor ///

Multiplayer::~Multiplayer() {

    cout << "DST Multiplayer \n";
}

/// ------------------------------------------- Supraincarcari ------------------------------------------- ///

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Multiplayer &mp) {
    mp.citire(in);
    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Multiplayer &mp) {
    mp.afisare(out);
    return out;
}

///                                                 "="                                                    ///

Multiplayer Multiplayer::operator=(const Multiplayer &mp) {

    this->Game::operator=(mp);

    if (this != &mp) {

        this->totalPlayers = mp.totalPlayers;
        this->microTransactions = mp.microTransactions;
    }
    return *this;
}

/// ---------------------------------- Functii Citire + Afisare ---------------------------------------- ///

void Multiplayer::citire(istream &in) {

    Game::citire(in);
    cout << "Introduceti numarul total de jucatori: \n";
    in >> totalPlayers;
    cout << "Jocul cotine microtranzactii ? 1 - DA | 0 - NU \n";
    in >> microTransactions;
}

void Multiplayer::afisare(ostream &out) {

    Game::afisare(out);
    out << "Numarul total de jucatori : " << totalPlayers << "\n";
    if (microTransactions) out << "Jocul contine microtranzactii. \n";
    else out << "Jocul nu suporta microtranzactii. \n";
}

/// ------------------------------------------------------------------------------------------------------ ///

class Person {

private:

    char sex;
    char *name;
    // string city;
    char CNP[15];
    // string dateOfBirth;
    int age;
    int lvl;
    float virtualWallet;
    int *friendList;
    bool major;
    double accountScore;
    const char status[7] = "Active";
    int id;
    static int numberOfUsers;
    vector<Game *> library;
    set <int> blockedList;

protected:

public:

    Person();

    Person(char sex, char *name, char CNP[15], int age, float virtualWallet, int *friendList);

    Person(const char *name);

    Person(const Person &p);

    ~Person();

    friend istream &operator>>(istream &, Person &);

    friend ostream &operator<<(ostream &, Person &);

    virtual void citire(istream &in);

    virtual void afisare(ostream &out);

    void emajor();

    void calcScore();

    void addGame(Game *g);

    // void addGame_Menu();

    Person operator=(const Person &);

///                                      Operatori + Functii membre                                        ///

    int &operator[](int index)
     { return friendList[index]; } // Supraincarcare [] -> Returneaza ID-ul unui prieten la un anumit index din friendList

    Person operator++() {                // Supraincarcare ++ prefix -> Mareste nivelul unui utilizator cu 1

        lvl++;
        return *this;
    }

    Person operator++(int) {           // Supraincarcare ++ postfix
        lvl++;
        return *this;
    }

    Person operator--() {                // Supraincarcare -- prefix -> Scade nivelul unui utilizator cu 1
        lvl--;
        return *this;
    }

    Person operator--(int) {           // Supraincarcare -- postfix
        lvl--;
        return *this;
    }

    Person operator+(
            Person &p) {        // Supraincarcare " + "     -> Transfera toti banii din virtual wallet de la un utilizator la altul

        Person result = *this;
        result.virtualWallet = this->virtualWallet + p.virtualWallet;
        p.virtualWallet = 0;
        return result;
    }

    Person operator/(
            Person &p) {        // Supraincarcare " / "     -> Face split la banii din virtualWallet intre cei 2 utilizatori

        Person result = *this;
        result.virtualWallet = (this->virtualWallet + p.virtualWallet) / 2;
        p.virtualWallet = result.virtualWallet;
        return result;
    }

    bool operator<(const Person &p) {    // Supraincarcare " < "     -> Compara valoarea contului utilizatorilor

        if (this->accountScore < p.accountScore)
            return true;
        else return false;
    }

    bool operator>(const Person &p) {    // Supraincarcare " >"

        if (this->accountScore > p.accountScore)
            return true;
        else return false;
    }

    bool operator==(const Person &p) {      // Supraincarcare " == "

        if (strcmp(this->name, p.name) == 0 && strcmp(this->CNP, p.CNP) == 0 && this->lvl == p.lvl)
            return true;
        else return false;
    }

    Person
    transferOnline(Person &p, int suma) {                     // Functie pentru transfer de bani intre utilizatori
        this->virtualWallet = this->virtualWallet + suma;
        p.virtualWallet = p.virtualWallet - suma;
        return *this;
    }

    Person transferOnline(int suma) {                     // Functie pentru modificare bani utilizator
        this->virtualWallet = this->virtualWallet + suma;
        return *this;
    }

    explicit operator int() { return (int) this->virtualWallet; }

/// Setteri:

    void setName(char *nume);

    void setSex(char sex) { this->sex = sex; }

    void setAge(int age) { this->age = age; }

    void setVirtualWallet(float virtualWallet) { this->virtualWallet = virtualWallet; }

    void setaccountScore(double accountScore) { this->accountScore = accountScore; }

    void setId(int id) { this->id = id; }

/// Getteri:

    char *getNume() { return this->name; }

    char getSex() { return this->sex; }

    int getAge() { return this->age; }

    float getVirtualWallet() { return this->virtualWallet; }

    double getaccountScore() { return this->accountScore; }

    int getId() { return this->id; }

    static int getNumberOfUsers() { return numberOfUsers; }

    int getLvl() { return lvl; }

    vector<Game *> &getLibrary() { return library; }

    set<int> getBlocked() { return this -> blockedList; }
};

int Person::numberOfUsers;

/// ---------------------------------- Functii Citire + Afisare ---------------------------------------- ///

void Person::citire(istream &in) {

    char aux[100];

    cout << "Introduceti numele persoanei: \n";
    in.get(aux, 100);
    if (name != nullptr)
        delete[] name;
    name = new char[strlen(aux) + 1];
    strcpy(name, aux);

    cout << "Introduceti genul ( M / F ) :\n";
    in >> sex;
    cout << "Introduceti CNP-ul: \n";
    in >> CNP;
    cout << "Introduceti varsta: \n";
    in >> age;
    if (age <= 0)
        throw (1);
    emajor();
    cout << "Introduceti suma de bani din wallet: \n";
    in >> virtualWallet;
    if (virtualWallet < 0)
        throw (2);
    cin.get();
}

void Person::afisare(ostream &out) {

    emajor();
    calcScore();
    out << fixed;
    out << setprecision(2);
    out << "ID: " << id << endl;
    out << "User-ul are statusul: " << status << "." << endl;
    out << "User level : " << lvl << "." << endl;
    out << "Persoana se numeste " << name << "." << endl;

    if (major == 1) {
        if (sex == 'M') {
            out << "Utilizatorul este major , mai exact are " << age << " ani." << endl;
        } else
            out << "Utilizatoarea este majora , mai exact are " << age << " ani." << endl;
    }

    if (major == 0) {
        if (sex == 'M') {
            out << "Utilizatorul este minor , mai exact are " << age << " ani." << endl;
        } else
            out << "Utilizatoarea este minora , mai exact are " << age << " ani." << endl;
    }

    out << "CNP-ul este " << CNP << "." << endl;
    out << "Scorul contului este " << accountScore << ", iar suma din virtual wallet este " << virtualWallet << ". \n";

    out << "Utilizatorul detine urmatoarele jocuri: \n";
    if (library.size() == 0)
        out << "N/A \n";
    else {
        for (int i = 0; i < library.size(); i++)
            out << library[i]->getNume() << " ; ";
    }
    if (friendList == NULL) out << "Persoana nu are prieteni ";
    set <int>::iterator it = blockedList.begin() ;
    cout << "Lista de utilizatori blocati: ";
    for( ; it != blockedList.end() ; it ++ )
        { cout << *it << " " ; }
    cout << "\n";
    //out << *friendList;
    //else for (int i = 0 ; i < size(friendList) ; i ++ ) out << (friendList[i]) << " ; " ;
    //out << endl;
    //out << "Numarul total de utilizatori este " << getNumberOfUsers() << "." << endl;
}

/// Alte Functii :

void Person::setName(char *nume) {

    if (this->name != nullptr)
        delete[] this->name;
    this->name = new char[strlen(nume) + 1];
    strcpy(this->name, nume);
}

void Person::emajor() {
    if (this->getAge() >= 18) major = 1;
    if (this->getAge() < 18) major = 0;
}

void Person::calcScore() {
    this->accountScore = (this->lvl) * 5000 + (this->virtualWallet) * 100;
}

void Person::addGame(Game *g) {

    library.push_back(g);

}

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Person::Person() {

    //cout << "CFP" << endl;
    id = numberOfUsers;
    numberOfUsers++;
    this->accountScore = 0;
    this->virtualWallet = 0;
    this->sex = '?';
    strcpy(CNP, "000000000000000");
    lvl = 1;

    this->name = new char[strlen("Unknown") + 1];
    strcpy(this->name, "Unknown");

    friendList = new int[1];
}

///                                    Constructorul 1 cu parametri                                      ///

Person::Person(char sex, char *name, char CNP[15], int age, float virtualWallet, int *friendList) {

    //cout << "CP 1" << endl;
    emajor();
    id = numberOfUsers + 1;
    numberOfUsers++;
    this->sex = sex;
    this->age = age;
    this->virtualWallet = virtualWallet;
    this->major = major;
    lvl = 1;
    calcScore();

    strcpy(this->CNP, CNP);

    this->name = new char[30];
    strcpy(this->name, name);

    this->friendList = friendList; // Fiecare utilizator va avea maxim 5 de prieteni in lista

}

///                                    Constructorul 2 cu parametri                                      ///

Person::Person(const char *name) {

    //cout << "CP 2" << endl;
    emajor();
    id = numberOfUsers + 1;
    numberOfUsers++;
    this->accountScore = 0;
    this->virtualWallet = 0;
    this->sex = '?';
    strcpy(this->CNP, CNP);

    this->name = new char[strlen("Unknown") + 1];
    strcpy(this->name, "Unknown");
    this->name = new char[30];
    strcpy(this->name, name);
    lvl = 1;
    this->friendList = new int[1];
}

///                                     Constructorul de copiere                                       ///

Person::Person(const Person &p) {

    //cout << "CC" << endl;
    numberOfUsers++;
    this->accountScore = p.accountScore;
    this->age = p.age;
    this->sex = p.sex;
    this->virtualWallet = p.virtualWallet;
    this->major = p.major;
    this->id = p.id;
    this->lvl = p.lvl;
    strcpy(this->CNP, p.CNP);

    this->name = new char[30];
    strcpy(this->name, p.name);

    this->friendList = new int[25];
    for (int i = 0; i < 25; i++)
        this->friendList[i] = friendList[i];
}

/// Destructor ///

Person::~Person() {

    //cout << "DST" << endl;

    if (this->name != NULL)
        delete[] this->name;

    if (this->friendList != NULL)
        delete[] this->friendList;

    strcpy(this->CNP, "");

    numberOfUsers--;
}

/// ------------------------------------------- Supraincarcari ------------------------------------------- ///

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Person &p) {
    p.citire(in);
    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Person &p) {
    p.afisare(out);
    return out;
}

///                                                 "="                                                    ///

Person Person::operator=(const Person &p) {

    if (this != &p) {

        //cout << "EGAL" << endl;

        if (this->name != nullptr)
            delete[] this->name;
        this->name = new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);

        if (this->friendList != nullptr)
            delete[] this->friendList;

        //WfriendList = new int[25];
        for (int i = 0; i < 25; i++)
            this->friendList[i] = p.friendList[i];

        strcpy(this->CNP, p.CNP);

        this->sex = p.sex;
        this->age = p.age;
        this->virtualWallet = p.virtualWallet;
        this->accountScore = p.accountScore;
        this->major = p.major;
        this->id = p.id;
    }

    return *this;
}

/// -------------------------------------  Extinderea clasei ( 1 )  -------------------------------------------- ///

class Staff : public Person {

private:
    int seniority;
    double salary;
    string hireDate;
public:
    Staff();

    Staff(char sex, char *name, char CNP[15], int age, float virtualWallet, int *friendList, int seniority,
          double salary, string hireDate);

    //Staff(const char *name);

    Staff(const Staff &s);

    ~Staff();

    friend istream &operator>>(istream &in, Staff &s);

    friend ostream &operator<<(ostream &out, Staff &s);

    void citire(istream &in);

    void afisare(ostream &out);

    void calcScore();

    Staff operator=(const Staff &);

};

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Staff::Staff() : Person() {

    this->hireDate = "Unknown date";
    this->salary = 0;
    this->seniority = 0;
}

///                                    Constructorul cu parametri                                      ///

Staff::Staff(char sex, char *name, char CNP[15], int age, float virtualWallet, int *friendList, int seniority = 0,
             double salary = 0, string hireDate = "") : Person(sex, name, CNP, age, virtualWallet, friendList) {

    cout << "Constructor STAFF\n";
    this->seniority = seniority;
    this->salary = salary;
    this->hireDate = hireDate;
}

///                                     Constructorul de copiere                                       ///

Staff::Staff(const Staff &s) : Person(s) {
    cout << "Copy Constructor Staff\n";
    seniority = s.seniority;
    salary = s.salary;
    hireDate = s.hireDate;
}

/// Destructor ///

Staff::~Staff() {

    cout << "DST Staff \n";

}

/// ------------------------------------------- Supraincarcari ------------------------------------------- ///

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Staff &s) {
    s.citire(in);
    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Staff &s) {
    s.afisare(out);
    return out;
}

///                                                 "="                                                    ///

Staff Staff::operator=(const Staff &s) {

    this->Person::operator=(s);

    if (this != &s) {

        this->seniority = s.seniority;
        this->salary = s.salary;
        this->hireDate = s.hireDate;
    }
    return *this;
}

/// ---------------------------------- Functii Citire + Afisare ---------------------------------------- ///

void Staff::citire(istream &in) {

    Person::citire(in);
    cout << "Introduceti salariul: \n";
    in >> salary;
    cout << "Introduceti vechimea de munca: \n";
    in >> seniority;
    cout << "Introduceti data angajarii: \n";
    in >> hireDate;
}

void Staff::afisare(ostream &out) {

    Person::afisare(out);
    out << "Angajatul are o vechime de munca de " << seniority << " ani, fiind angajat la data de " << hireDate
        << ", si avand un salariu de " << salary << "$. \n";
}

/// -------------------------------------  Extinderea clasei ( 2 )  -------------------------------------------- ///

class Client : public Person {

private:
    string cardNumber;
    string registerDate;
    bool premium;
public:
    Client();

    Client(char sex, char *name, char CNP[15], int age, float virtualWallet, int *friendList, string cardNumber,
           string registerDate, bool premium);

    Client(const Client &c);

    ~Client();

    friend istream &operator>>(istream &in, Staff &s);

    friend ostream &operator<<(ostream &out, Staff &s);

    void citire(istream &in);

    void afisare(ostream &out);

    void calcScore();

    Client operator=(const Client &);

};

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Client::Client() : Person() {

    this->cardNumber = "Unknown number";
    this->registerDate = "N/A";
    this->premium = 0;
}

///                                    Constructorul cu parametri                                      ///

Client::Client(char sex, char *name, char CNP[15], int age, float virtualWallet, int *friendList, string cardNumber,
               string registerDate, bool premium) : Person(sex, name, CNP, age, virtualWallet, friendList) {

    cout << "Costructor Client \n";
    this->cardNumber = cardNumber;
    this->registerDate = registerDate;
    this->premium = premium;
}

///                                     Constructorul de copiere                                       ///

Client::Client(const Client &c) : Person(c) {

    cout << "Copy Constructor Client \n";
    premium = c.premium;
    registerDate = c.registerDate;
    cardNumber = c.cardNumber;
}

/// Destructor ///

Client::~Client() {

    cout << "DST Client \n";
}

/// ------------------------------------------- Supraincarcari ------------------------------------------- ///

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Client &c) {
    c.citire(in);
    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Client &c) {
    c.afisare(out);
    return out;
}

///                                                 "="                                                    ///

Client Client::operator=(const Client &c) {

    this->Person::operator=(c);

    if (this != &c) {

        this->cardNumber = c.cardNumber;
        this->registerDate = c.registerDate;
        this->premium = c.premium;
    }
    return *this;
}

/// ---------------------------------- Functii Citire + Afisare ---------------------------------------- ///

void Client::citire(istream &in) {

    Person::citire(in);
    cout << "Introduceti numarul cardului: \n";
    in >> cardNumber;
    cout << "Introduceti data inregistrarii: \n";
    in >> registerDate;
    cout << "Este utilizatorul premium ? 1 - DA | 0 - NU \n";
    in >> premium;
}

void Client::afisare(ostream &out) {

    Person::afisare(out);
    out << "Clientul s-a inregistrat in data de " << registerDate << " .\n";
    out << "Numar card: " << cardNumber << "\n";
    if (premium) out << "Utilizatorul beneficiaza de statutul PREMIUM.\n";
    else out << "Utilizatorul are statutul BASIC.\n";
}

/// ------------------------------------------------------------------------------------------------------ ///

class Meniu {

private:

    int index;
    char option;
    char *instructiune;
    static int nrAfisari;
    const char message[60] = "---------- Doobiez Gamez Company Management Menu ----------";

public:

    Meniu();

    Meniu(int index);

    Meniu(const char message);

    Meniu(const Meniu &m);

    ~Meniu();

    Meniu operator=(const Meniu &);

    friend istream &operator>>(istream &, Meniu &);

    friend ostream &operator<<(ostream &, Meniu &);

/// Functie meniu:

    void start() {
        option = 'a';
        vector <Person> person;
        vector <Game> game;
        vector <Corporation> corp;
        while (option != '0') {
            cout << "\n" << message << "\n" << endl;
            this->afisareMeniuPrincipal();
            cin >> option;
            switch (option) {

                default: {
                    cout << "Introdu o valoarea valida! \n ";
                    break;
                }

                case '0':
                    break;

                case '1': {
                    char _option = 'a';
                    while (_option != '0') {
                        cout << endl << " ---------- Meniu companie ---------- \n" << endl;
                        this->afisareMeniuCompanie();
                        cin >> _option;
                        switch (_option) {
                            default: {
                                cout << "Introduceti o valoare valida! \n";
                                break;
                            }

                            case '0' :
                                break;

                            case '1': {
                                if (corp.size() == 0) {
                                    cin.get();
                                    corp.resize(corp.size() + 1); // De fapt oricum citesc doar primul element
                                    cin >> corp[corp.size() - 1]; // Dar pentru simetrie am lasat asa
                                } else cout << "Ati introdus deja datele companiei, le puteti doar actualiza! \n";
                                break;
                            }

                            case '2' : {
                                if (corp.size() > 0)
                                    for (int i = 0; i < corp.size(); i++)
                                        cout << corp[i];
                                else cout << "Nu au fost introduse datele companiei ! \n";
                                break;
                            }

                            case '3': {
                                if (corp.size() == 0)
                                    cout << "Mai intai introduceti datele companiei ! \n";
                                else {
                                    char _option = 'a';
                                    while (_option != '0') {
                                        this->afisareMeniuActualizari();
                                        cin.get();
                                        cin >> _option;
                                        switch (_option) {
                                            case '1': {
                                                int nr;
                                                cout << "Introduceti noul numar de angajati: \n";
                                                cin.get();
                                                cin >> nr;
                                                corp[0].setNumberOfEmployees(nr);
                                                break;
                                            }

                                            case '2': {
                                                int r;
                                                cout << "Introduceti noua pozitie in clasament: \n";
                                                cin.get();
                                                cin >> r;
                                                corp[0].setRanking(r);
                                                break;
                                            }
                                            case '3': {
                                                char c;
                                                cout << "Compania angajeaza ? ( 1 - DA | 0 - NU ) \n";
                                                cin.get();
                                                cin >> c;
                                                corp[0].setLFE(c);
                                                break;
                                            }
                                        }
                                    }
                                    break;
                                }
                                break;
                            }
                        }
                    }
                    break;
                }
                case '2': {
                    char _option = 'a';
                    while (_option != '0') {
                        cout << endl << " ---------- Meniu utilizatori ---------- \n" << endl;
                        this->afisareMeniuPerson();
                        cin >> _option;
                        switch (_option) {
                            case '1': {
                                if (person.size() > 0)
                                    for (int i = 0; i < person.size(); i++) {
                                        cout << "Pe platforma noastra sunt inregistrati "
                                             << person[i].getNumberOfUsers() << " utilizatori .\n" << endl;
                                        cout << "Nr: " << i << "\n" << person[i];
                                    }
                                else cout << "Nu au fost introduse persoane ! \n";
                                break;
                            }

                            case '2': {
                                try {
                                    int op;
                                    cout << "Alege metoda de adaugare \n 1) Tastatura \n 2) Fisier \n";
                                    cin >> op;
                                    if (op == 1) {
                                        cin.get();
                                        person.resize(person.size() + 1);
                                        cin >> person[person.size() - 1];
                                    }
                                    if (op == 2) {
                                        string s;
                                        cout << "Introdu nume fisier: ";
                                        cin >> s;
                                        ifstream fin(s);
                                        person.resize(person.size() + 1);
                                        fin >> person[person.size() - 1];
                                    }
                                }
                                catch (int eroare) {
                                    person.resize(person.size() - 1);
                                    if (eroare == 1)
                                        cout << "Eroare la citirea varstei ! \n";
                                    if (eroare == 2)
                                        cout << "Eroare la suma din virtual wallet ! \n";
                                }

                                break;
                            }

                            case '3': {
                                int nr;
                                cout << "Introdu numar utilizator: ";
                                cin.get();
                                cin >> nr;
                                person.erase(person.begin() + nr);
                                break;
                            }

                            case '4': {
                                char __option = 'a';
                                while (__option != '0') {
                                    cout << "1) Modifica lvl \n";
                                    cout << "2) Modifica bani \n";
                                    cout << "0) Back \n";
                                    cin.get();
                                    cin >> __option;
                                    switch (__option) {
                                        default: {
                                            cout << "Introdu valoare valida! \n";
                                            break;
                                        }
                                        case '0':
                                            break;
                                        case '1': {
                                            int nr;
                                            cout << "Introdu NR: ";
                                            cin >> nr;
                                            cout << "1) Adauga lvl";
                                            cout << "2) Scade lvl";
                                            cin >> __option;
                                            if (__option == '1')
                                                person[nr]++;
                                            if (__option == '2')
                                                person[nr]--;
                                            break;
                                        }
                                        case '2': {
                                            char optiune = 'a';
                                            while (optiune != '0') {
                                                cout << "1) Transfer intre utilizatori \n";
                                                cout << "2) Modificare bani la un singur utilizator \n";
                                                cout << "0) Back \n";
                                                cin.get();
                                                cin >> optiune;
                                                switch (optiune) {
                                                    default: {
                                                        cout << "Introduceti o valoare valida! \n";
                                                        break;
                                                    }
                                                    case '0':
                                                        break;

                                                    case '1': {
                                                        int nr1, nr2;
                                                        float suma;
                                                        cout << "Introdu NR utilizator care primeste: ";
                                                        cin >> nr1;
                                                        cout << "Introdu NR utilizator care ofera: ";
                                                        cin >> nr2;
                                                        cout << "Introdu suma: ";
                                                        cin >> suma;
                                                        person[nr1].transferOnline(person[nr2], suma);
                                                        break;
                                                    }

                                                    case '2': {
                                                        int nrr;
                                                        char optiune2;
                                                        cout << "Introdu NR utilizator: \n";
                                                        cin >> nrr;
                                                        cout << "1) Adauga bani: \n";
                                                        cout << "2) Scade bani: \n";
                                                        cin.get();
                                                        cin >> optiune2;
                                                        if (optiune2 == '1') {
                                                            float suma;
                                                            cout << "Introdu suma: ";
                                                            cin >> suma;
                                                            person[nrr].transferOnline(suma);
                                                        }
                                                        if (optiune2 == '2') {
                                                            float suma;
                                                            cout << "Introdu suma: ";
                                                            cin >> suma;
                                                            float suma2 = (-1) * suma;
                                                            person[nrr].transferOnline(suma2);
                                                        }
                                                        break;
                                                    }
                                                }       // End of case 22 switch
                                            }       // End of case 22 while
                                        }       // END OF case 22
                                    }
                                }
                            }
                            case '5': {
                                cout << "Denumiti fisierul de export: \n";
                                string s;
                                cin >> s;
                                ofstream fout(s);

                                if (person.size() > 0)
                                    for (int i = 0; i < person.size(); i++) {
                                        fout << "Pe platforma noastra sunt inregistrati "
                                             << person[i].getNumberOfUsers() << " utilizatori .\n" << endl;
                                        fout << "Nr: " << i << "\n" << person[i];
                                    }
                                else fout << "Nu au fost introduse persoane ! \n";
                                cout << "Fisierul a fost salvat!\n";
                                break;
                            }
                            case '6': {

                                int nrP, nrG, optiuneLibrarie;
                                cout << "Introdu utilizatorul la care se adauga un joc: ";
                                cin >> nrP;
                                cout << "1) Adauga joc existent \n2) Adauga joc nou \n";
                                cin >> optiuneLibrarie;
                                try {
                                    if (optiuneLibrarie == 1) {
                                        cout << "Introdu numar joc: ";
                                        cin >> nrG;
                                        if (nrG > game.size() - 1)
                                            throw (1);
                                        Game *g = &game[nrG];
                                        person[nrP].addGame(g);
                                    }
                                    if (optiuneLibrarie == 2) {
                                        cin.get();
                                        game.resize(game.size() + 1);
                                        cin >> game[game.size() - 1];
                                        Game *g = &game[game.size() - 1];
                                        person[nrP].addGame(g);
                                    }
                                }
                                catch (int eroare) {
                                    cout << "Eroare cod joc ! \n";
                                }

                            }

                            case '7' : {

                                int nr1, nr2;
                                cout << "Introdu NR utilizator care adauga la block: ";
                                cin >> nr1;
                                cout << "Introdu NR utilizator blocat: ";
                                cin >> nr2;
                                person[nr1].getBlocked().insert(nr2);
                                break;
                            }
                        }   // End switch case 2

                    }
                    break; // Break after case 2's while
                }   // End of case 2

                case '3': {
                    char _option = 'a';
                    while (_option != '0') {
                        cout << endl << " ---------- Meniu jocuri ---------- \n" << endl;
                        this->afisareMeniuJoc();
                        cin >> _option;
                        switch (_option) {
                            case '1' : {
                                if (game.size() > 0)
                                    for (int i = 0; i < game.size(); i++) {
                                        cout << "Numarul de jocuri totale in libraria noastra este "
                                             << game[i].getnumberOfGames() << "\n" << endl;
                                        cout << "Numar unic joc: " << i << "\n" << game[i];
                                    }
                                else cout << "Nu au fost introduse jocuri ! \n";
                                break;
                            }

                            case '2' : {
                                cin.get();
                                game.resize(game.size() + 1);
                                cin >> game[game.size() - 1];
                                break;
                            }

                            case '3': {
                                int nr;
                                cout << "Introduceti numarul jocului: ";
                                cin.get();
                                cin >> nr;
                                game.erase(game.begin() + nr);
                                break;
                            }

                            case '4' : {
                                char __option = 'a';
                                while (__option != '0') {
                                    this->afisareMeniuPreturi();
                                    cin.get();
                                    cin >> __option;
                                    switch (__option) {
                                        default : {
                                            cout << "Introduceti o valoare valida! \n";
                                            break;
                                        }

                                        case '0' :
                                            break;

                                        case '1' : {
                                            int nr;
                                            cout << "Introduceti numarul jocului: \n";
                                            cin >> nr;
                                            game[nr]++;
                                            break;
                                        }

                                        case '2' : {
                                            int nr;
                                            cout << "Introduceti numarul jocului: \n";
                                            cin >> nr;
                                            game[nr]--;
                                            break;
                                        }

                                        case '3' : {
                                            int nr;
                                            cout << "Introduceti numarul jocului: \n";
                                            cin >> nr;
                                            float suma;
                                            cout << "Introduceti valoarea: \n";
                                            cin >> suma;
                                            float price = game[nr].getPrice();
                                            price += suma;
                                            game[nr].setPrice(price);
                                            break;
                                            //game[nr].getPrice() += suma;
                                        }

                                        case '4' : {
                                            int nr;
                                            cout << "Introduceti numarul jocului: \n";
                                            cin >> nr;
                                            float suma;
                                            cout << "Introduceti valoarea: \n";
                                            cin >> suma;
                                            float price = game[nr].getPrice();
                                            price -= suma;
                                            game[nr].setPrice(price);
                                            break;
                                            //game[nr].getPrice() -= suma;
                                        }
                                    }
                                }
                                break;
                            }

                            case '0' :
                                break;

                            default: {
                                cout << "Introdu valoare valida! \n";
                                break;
                            }

                        }   // End Switch case 3

                    }   // End While case 3
                    break; // Break after case 3's while
                }   // End case 3

            }   // End Start Switch

        }   // End Start While

    }   // End of Start sFunction


    void afisareMeniuPrincipal() {
        cout << "1) Accesare detalii companie \n";
        cout << "2) Meniu utilizatori \n";
        cout << "3) Meniu jocuri \n";
        cout << "0) Exit \n";
    }

    void afisareMeniuCompanie() {
        cout << "1) Adauga detalii \n";
        cout << "2) Afiseaza date \n";
        cout << "3) Actualizeaza date \n";
        cout << "0) Back \n";
    }

    void afisareMeniuActualizari() {
        cout << "1) Actualizeaza nr de angajati \n";
        cout << "2) Actualizeaza rank-ul companiei \n";
        cout << "3) Actualizeaza statutul de angajari ( ON / OFF ) \n";
        cout << "0) Back \n";
    }

    void afisareMeniuPerson() {
        cout << "1) Afisare utilizatori \n";
        cout << "2) Adauga utilizator \n";
        cout << "3) Sterge utilizator \n";
        cout << "4) Modifica level / bani utilizator \n";
        cout << "5) Export data in fisier extern \n";
        cout << "6) Adauga joc la utilizator \n";
        // cout << "7) Adauga utilizator la block \n";
        cout << "0) Back \n";
    }

    void afisareMeniuJoc() {
        cout << "1) Afisare jocuri \n";
        cout << "2) Adauga jocuri \n";
        cout << "3) Sterge joc \n";
        cout << "4) Modifica pret jocuri \n";
        cout << "0) Back \n";
    }

    void afisareMeniuPreturi() {
        cout << "1) Mareste pretul cu 25% \n";
        cout << "2) Redu pretul cu 25% \n";
        cout << "3) Mareste pretul cu X \n";
        cout << "4) Redu pretul cu X \n";
        cout << "0) Exit \n";
    }
};

int Meniu::nrAfisari;

/// ------------------------------------------- Constructori ------------------------------------------- ///

///                                    Constructorul fara parametri                                      ///

Meniu::Meniu() {

    //cout << "CFP" << endl;
    nrAfisari++;
    this->instructiune = new char[strlen("instructiune") + 1];
    //strcpy(this -> instructiune, "Unknown");
}

///                                    Constructorul 1 cu parametri                                      ///

Meniu::Meniu(int index) {

    //cout << "CP 1" << endl;
    nrAfisari++;
    index = 0;
    this->instructiune = new char[15];
    strcpy(this->instructiune, instructiune);
}

///                                    Constructorul 2 cu parametri                                      ///

Meniu::Meniu(const char message) {

    //cout << "CP 2" << endl;
    nrAfisari++;
    index = 0;
    this->instructiune = new char[15];
    strcpy(this->instructiune, instructiune);
}

///                                     Constructorul de copiere                                       ///

Meniu::Meniu(const Meniu &m) {

    //cout << "CC" << endl;
    nrAfisari++;
    this->index = m.index;
    this->instructiune = new char[15];
    strcpy(this->instructiune, m.instructiune);
}

/// Destructor

Meniu::~Meniu() {

    //cout << "DST" << endl;
    if (this->instructiune != NULL)
        delete[] this->instructiune;

    nrAfisari--;
}

///                                                 "="                                                    ///

Meniu Meniu::operator=(const Meniu &m) {

    if (this != &m) {

        cout << "EGAL" << endl;
        this->index = m.index;

        if (this->instructiune != nullptr)
            delete[] this->instructiune;
        this->instructiune = new char[strlen(m.instructiune) + 1];
        strcpy(this->instructiune, m.instructiune);
    }

    return *this;
}

///                                                 ">>"                                                   ///

istream &operator>>(istream &in, Meniu &m) {

    char aux[15];
    cout << "Introduceti instructiunea: \n";
    in.get(aux, 15);
    if (m.instructiune != nullptr)
        delete[] m.instructiune;
    m.instructiune = new char[strlen(aux) + 1];
    strcpy(m.instructiune, aux);

    cout << "Index :\n";
    in >> m.index;

    return in;
}

///                                                 "<<"                                                   ///

ostream &operator<<(ostream &out, Meniu &m) {

    out << "Instructiunea primita este: " << m.instructiune << endl;
    out << "Indexul: " << m.index << endl;

    return out;
}

/// ------------------------------------------------------------------------------------------------------ ///

class Achievement {

private:

protected:

    float percent = 25;
    int difficulty = 1;
    double score = 0;

public:

    virtual float calcScore() = 0;

    void setDifficulty(int difficulty) { this->difficulty = difficulty; }

    void setPercent(float percent) { this->percent = percent; }

    double getScore() { return score; }
};

class Completion : public Achievement {

protected:

    string name = "Completion of the game \n";

public:

    float calcScore() {
        score = percent * 100 + difficulty * 2500;
    }

};

class Trophy : public Achievement {

protected:

    string name = "Got all the in-game achievements \n";

public:

    float calcScore() {
        score = 3 * percent * 100 + (difficulty + 1) * 2500;
    }

};

class Legend : public Achievement {

protected:

    string name = "--- Legendary player --- \n Completed every side-quest, in-game achievement and discovered all secrets. \n ";

public:

    float calcScore() {
        score = 10 * percent * 100 + (difficulty + 2) * 2500;
    }

};

/// ------------------------------------------------------------------------------------------------------ ///

int main() {

    Meniu m;
    m.start();
    return 0;
}
