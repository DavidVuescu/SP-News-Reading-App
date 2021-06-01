#include <iostream>
#include <string.h>

#include "Stire.hpp"

using namespace std;


Stire::Stire()
{
    this->fav = false;
}
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
    os << "===#================#=== " << str.title << " ===#================#=== " << endl;
    os << str.content << "\n\n";
    return os;
}



void Stire::MakeFav()
{
    if (this->fav == false) this->fav = true;
    else this->fav = false;
}

void Stire::set_title(string title)
{
    this->title = title;
}
void Stire::set_content(string content)
{
    this->content = content;
}

string Stire::get_title()
{
    return title;
}
string Stire::get_content()
{
    return content;
}

string& Stire::get_title_adress()
{
    return title;
}
string& Stire::get_content_adress()
{
    return content;
}
