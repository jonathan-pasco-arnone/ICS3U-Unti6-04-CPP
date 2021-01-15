// Copyright (c) 2020 Jonathan Pasco-Arnone all rights reserved
//
// Created by Jonathan Pasco-Arnone
// Created on January 2021
// This program finds the lowest number in a list of random numbers

#include <iostream>
#include <array>
#include <random>


template <int rows, int cols>
float sumOfNumbers(int (&passedIn2DList)[rows][cols]) {
    // this function adds up all the elements in  a 2D array

    float amount_of_digits = 0;
    float average = 0;
    float total = 0;

    /* size_t is used so that rowElement can be compared to rows.
       It compares a regular number from "rowElement" to the number
       of items in list "rows" */
    for (size_t rowElement = 0; rowElement < rows; ++rowElement) {
        for (size_t columnElement = 0; columnElement < cols; ++columnElement) {
            /* row element means which row, and column element means
               which column. And "passedIn2DList[rowElement][columnElement]"
               gets value of the digit at the specified row and column */
            total += passedIn2DList[rowElement][columnElement];
            amount_of_digits += 1;
        }
    }

    average = total / amount_of_digits;

    return average;
}


int main() {
    // this function uses a 2D array

    int aSingleRandomNumber = 0;
    float average;
    const int rows = 2;  // number of rows
    const int columns = 5;  // number of columns
    int a2DArray[rows][columns];

    srand(time(NULL));


    for (int rowElement = 0; rowElement < rows; rowElement++) {
        for (int columnElement = 0; columnElement < columns; columnElement++) {
            // Random number code
            std::random_device rseed;
            std::mt19937 rgen(rseed());  // mersenne_twister
            std::uniform_int_distribution<int> idist(0, 50);  // [0, 50]
            aSingleRandomNumber = idist(rgen);
            a2DArray[rowElement][columnElement] = aSingleRandomNumber;
            std::cout << aSingleRandomNumber << ", ";
        }
        std::cout << std::endl;
    }

    average = sumOfNumbers(a2DArray);
    std::cout << "The average is: " << average << std::endl;
}

/* NOTE

I did not use a try or an if statement to confirm valid inputs like I did
in the python version of this because there are no inputs in this version

*/
