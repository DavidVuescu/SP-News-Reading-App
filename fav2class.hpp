#ifndef FAV2CLASS_H
#define FAV2CLASS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Stire.hpp"

using namespace std;


void classify (vector <Stire> & vector, string * titles, int nr, int &counter) {

    string file_path;

    for(int i=0;i<nr;i++) {        
        file_path = "News\\";
        file_path = file_path + titles[i+1];
        file_path = file_path + ".txt";

        ifstream open_article;      //currently open article file
        open_article.open (file_path.c_str(), ios::in);

            Stire article_class;    //currently open article class
            getline(open_article, article_class.get_title_adress());

            string buffer;
            string fat_buffer;
            while(getline(open_article, buffer))
            {
                fat_buffer = fat_buffer + "\n" + buffer;
            }
            article_class.set_content(fat_buffer);

        if (article_class.get_fav()) {
            counter ++;
            vector.push_back(article_class);
        }
    }
}

#endif
