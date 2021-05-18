#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <conio.h>

#include "arrow.hpp"
#include "Stire.hpp"

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

            arrow(1,pos); cout<<" || VIEW PLAYLISTS\n";
            arrow(2,pos); cout<<" || CREATE NEW PLAYLIST\n";
            arrow(3,pos); cout<<" || DELETE PLAYLIST\n";
            arrow(4,pos); cout<<" || EXIT\n\n";
            arrow(5,pos); cout<<"  ||  TESTING  ||\n";

            cout<<"=============================================\n";    //fluff

            key = getch();


            // //Pos increment, controlling arrow movement
            // if(key==80 && pos!=4) pos++;
            //     else if (key==80 && pos==4) pos=1;         //upwards cycle
            //         else if(key==72 && pos!=1) pos--;
            //             else if(key==72 && pos==1) pos=4;  //downwards cycle
            //                 else pos=pos;


            //TEST Pos increment
            if(key==80 && pos!=5) pos++;
                else if (key==80 && pos==5) pos=1;         //upwards cycle
                    else if(key==72 && pos!=1) pos--;
                        else if(key==72 && pos==1) pos=5;  //downwards cycle
                            else pos=pos;


        }

        switch(pos)
        {
            case 1:
            {
                cout << "User selected option number " << pos;
                system("pause");
                key=1;
                break;
            }
            case 2:
            {
                cout << "User selected option number " << pos;
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
            
            case 5:
            {
                Stire test("test1", "test2");
                cout << test;
                test.MakeFav();
                cout << "\n\n\n";
                if (test.fav == 1) cout << test;

                system("pause");
                key=1;
                break;
            }
        }
    }
}


#endif
