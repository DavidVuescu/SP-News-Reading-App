#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

#include "Stire.hpp"
#include "index.hpp"
#include "arrow.hpp"

using namespace std;

void menu()
{
    int pos=1, key=0;

    while(pos!=0)
    {
        while(key!=13)
        {
            system("cls");

            cout<<"=============================================\n";    //fluff
            cout<<"=============================================\n";    //fluff
            cout<<"===           NEWS-O-MATIC 1000           ===\n";    //fluff
            cout<<"=============================================\n";    //fluff
            cout<<"=============================================\n\n";  //fluff

            arrow(1,pos); cout<<" || VIEW CURRENT NEWS\n";
            arrow(2,pos); cout<<" || CREATE NEW NEWS ARTICLE\n";
            arrow(3,pos); cout<<" || DELETE NEWS ARTICLE\n";
            arrow(4,pos); cout<<" || EXIT\n\n";
            // arrow(5,pos); cout<<"  ||  TESTING  ||\n";

            cout<<"=============================================\n";    //fluff

            key = getch();


            //Pos increment, controlling arrow movement
            if(key==80 && pos!=4) pos++;
                else if (key==80 && pos==4) pos=1;         //upwards cycle
                    else if(key==72 && pos!=1) pos--;
                        else if(key==72 && pos==1) pos=4;  //downwards cycle
                            else pos=pos;
        }

        switch(pos)
        {
            case 1:
            {
            // VIEW CURRENT NEWS OPTION
                    int nr;
                    string * titles;
                    titles = index(nr);
        
                int sub_key = 0;
                int sub_pos = 0;
                while(sub_key != 13)
                {
                    system("cls");

                    cout<<"==== SELECT THE NEWS ARTICLE YOU WANT TO READ ====";
                    cout<<endl<<endl;

                    for (int i=0;i<nr;i++)
                        {sub_arrow(i,sub_pos); cout<<titles[i+1]<<endl;}
                    sub_key = getch();

                    if(sub_key==80 && sub_pos!=(nr-1)) sub_pos++;
                    else if (sub_key==80 && sub_pos==(nr-1)) sub_pos=1;    //upwards cycle
                    else if(sub_key==72 && sub_pos!=0) sub_pos--;
                    else if(sub_key==72 && sub_pos==0) sub_pos=(nr-1);     //downwards cycle
                    else sub_pos=sub_pos;
                }

                string file_path;
                file_path = "News\\";
                file_path = file_path + titles[sub_pos+1];
                file_path = file_path + ".txt";
                // cout<<endl<<file_path; // test line

                ifstream article;
                article.open (file_path.c_str(), ios::in);
                if(!article.is_open())
                {
                    perror("Could not open news article file");
                }
                else
                {
                    Stire useread_article;
                    getline(article, useread_article.get_title_adress());

                    string buffer;
                    string fat_buffer;
                    while(getline(article, buffer))
                    {
                        fat_buffer = fat_buffer + "\n" + buffer;
                    }
                    useread_article.set_content(fat_buffer);

                    system("cls");
                    cout<<useread_article;
                }
                

                delete [] titles;
                article.close();

                system("pause");
                key=1;
                break;
            }
            case 2:
            {
            // CREATE NEW NEWS ARTICLE OPTION
                    int nr;
                    string * titles;
                    titles = index(nr);

                    string new_title;
                    string new_content;

                cout << "Introduceti titlul stirii dumneavoastra: ";
                getline(cin, new_title);

                system("cls");
                cout << "======================== " << new_title << " ========================\n";
                cout << "Please write your new article: " << endl << endl;

                int writers_block=0;
                string buffer;
                while(writers_block != 27)
                {
                    getline(cin, buffer);
                    new_content += buffer + "\n";
                    writers_block = getch();
                }
                Stire new_article;
                new_article.set_title(new_title);
                new_article.set_content(new_content);


                ofstream index; index.open("News\\index.txt");
                titles[nr+1] = new_title;
                nr++;
                index<<nr<<endl;
                for(int i=1;i<=nr;i++)
                {
                    index<<titles[i]<<endl;
                }
                index.close();

                string new_path;
                new_path = "News\\";
                new_path += titles[nr];
                new_path += ".txt";
                ofstream f_new_news;    f_new_news.open(new_path.c_str());
                f_new_news<<new_article.get_title()<<endl;
                f_new_news<<new_article.get_content();
                f_new_news.close();

           
                delete [] titles;
                
                system("pause");
                key=1;
                break;
            }
            case 3:
            {
                cout << "User selected option number " << pos;
                system("pause");
                key=1;
                break;
            }
            case 4:
            {
                pos=0;

                cout<<"Goodbye, Friend"<<endl;
                system("pause");
                break;
            }
            

        }
    }
}


#endif
