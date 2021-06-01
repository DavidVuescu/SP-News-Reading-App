#ifndef INDEX_H
#define INDEX_H

#include <iostream>
#include <fstream>
#include <string>

#include "Stire.hpp"

string * index (int &nr)
{
    string buffer;

    ifstream fin;
    fin.open ("News\\index.txt", ios::in);
    if(!fin.is_open())
    {
        perror("Could not open index file");
    }
    else
    {
        fin >> nr;
        if (nr < 10) fin.seekg(1);
            else if (nr >= 10 && nr < 100) fin.seekg(2);
                else if (nr >= 100 && nr < 1000) fin.seekg(3);

        string * titles = new string[nr+2];
        int i = 0;
        while (getline(fin, buffer))
        {
            titles[i] = buffer;
            i=i+1;
        }
        return titles;
    }

    fin.close();
}

#endif
