#ifndef STIRE_H
#define STIRE_H
#pragma once

#include <iostream>
using namespace std;

class Stire
{
    
    string title;
    string content;

public:

    bool fav;

    Stire();

    Stire(string, string);

    Stire(const Stire&);

    virtual ~Stire();

    Stire& operator=(const Stire&);

    friend ostream & operator << (ostream&, const Stire);

    void MakeFav();

    void set_title(string);

    void set_content(string);

    string get_title();

    string get_content();

    string& get_title_adress();

    string& get_content_adress();

};


#endif
