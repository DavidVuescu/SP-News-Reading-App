#include <iostream>
#include <string.h>

using namespace std;

class Stire
{
    string title;
    string content;

public:

    bool fav;

    Stire(string, string);

    Stire(const Stire&);

    virtual ~Stire();

    virtual ostream& afisare(ostream&)const;

    Stire& operator=(const Stire&);

    friend ostream& operator<<(ostream&, const Stire&);

    void MakeFav();

protected:

    void init(const string&, const string&);
};



void Stire::init(const string& t, const string& c)
{
    this->title = t;
    this->content = c;

    this->fav = false;
}
Stire::Stire(string t, string c)
{
    this->init(t, c);
}
Stire::Stire(const Stire& str)
{
    this->init(str.title, str.content);
}


Stire& Stire::operator=(const Stire& str)
{
    if (this == &str) return *this;
    this->init(str.title, str.content);
    return *this;
}
ostream& Stire::afisare(ostream& os)const
{
    os << "Titlu:" << this->title << "\n" << this->content << "\n\n";
    return os;
}
ostream& operator<<(ostream& os, const Stire& str)
{
    return str.afisare(os);
}



void Stire::MakeFav()
{
    if (this->fav == false) this->fav = true;
    else this->fav = false;
}

Stire::~Stire() {}




int main()
{

    Stire test("test1", "test2");
    cout << test;
    test.MakeFav();
    cout << "\n\n\n";
    if (test.fav == 1) cout << test;

    return 0;
}
