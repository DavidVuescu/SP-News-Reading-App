#ifndef ARROW_H
#define ARROW_H

#include <iostream>

void arrow(int, int);
void arrow(int actual_pos, int arrow_pos)
// Function used for arrow menu
// Compares the menu position
// If menu position is equal to the arrow position it prints the arrow
{
    if (actual_pos==arrow_pos)
        std::cout<<" ---->>  ";

        else
            std::cout<<"            ";
}

void sub_arrow(int actual_pos, int arrow_pos)
// Function used for submenu arrows
// Same function as the above, just different way of printing
{
    if (actual_pos==arrow_pos)
        std::cout<<"  >>  ";

        else
            std::cout<<"   ";
}
#endif
