#include <iostream>
#include <string.h>

#include "Stire.hpp"

using namespace std;



Stire::Stire(string t, string c)
{
    this->title = t;
    this->content = c;

    this->fav = false;
}
Stire::Stire(const Stire& str)
{
    this->title = str.title;
    this->content = str.content;
}
Stire::~Stire() {}



Stire& Stire::operator=(const Stire& str)
{
    if (this == &str) return *this;
    this->title = str.title;
    this->content = str.content;
    return *this;
}
ostream& operator<<(ostream& os, const Stire& str)
{
    os << "Titlu:" << str.title << "\n" << str.content << "\n\n";
    return os;
}



void Stire::MakeFav()
{
    if (this->fav == false) this->fav = true;
    else this->fav = false;
}
