#include <iostream>
#include <string.h>

#include "Stire.hpp"

using namespace std;



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
