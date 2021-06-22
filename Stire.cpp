#include <iostream>
#include <string>

#include "Stire.hpp"

using namespace std;


Stire::Stire()
{
    this->fav = false;
}
Stire::Stire(string title, string content)
{
    this->title = title;
    this->content = content;

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
ostream & operator << (ostream& os, const Stire str)
{
    string::const_iterator it;

    os << "===#================#=== "; 
    for (it = str.title.begin()+1; it != str.title.end(); it++) cout<<*it;
    os << " ===#================#=== " << endl;

    os << str.content << "\n\n";
    return os;
}



void Stire::MakeFav()
{
    if (title[0]== '0') {
        this->fav = true;
        title[0]='1';
    }
    else if (title[0]== '1') {
        this->fav = false;
        title[0]='0';
    }
}
bool Stire::get_fav() {
    if (title[0] == '1') return 1;
    return 0;
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
