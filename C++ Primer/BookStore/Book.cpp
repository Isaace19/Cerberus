#include <iostream>
#include "Sales_item.h"
/*
    Simple main function

    Exercise 1.5.2: Write a program that reads several transactions and counts how many transactions occur for each ISBN.
*/

int main()
{
    Sales_item total;

    if (std::cin >> total)
    {
        Sales_item temp;
        while (std::cin >> temp)
        {
            if (total.isbn() == temp.isbn())
            {
                total += temp;
            }
            else
            {
                std::cout << "There are two completely different books!" << std::endl;
            }
            // want to figure out a way to recongize two seperate isbns and total them seperately and keep a running total.
            if (total.isbn() != temp.isbn())
            {
            }
        }
    }
    else
    {
        std::cerr << "No book data!" << std::endl;
        return 1;
    }

    return 0;
}