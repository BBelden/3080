// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3080-001
// Assignment: lab1
// Due:        23:59:59, September 27, 2013
// Purpose:
// Input:      Pre-formatted file data files.
// Output:     Print to terminal.
//
// File:       lab1main.cpp

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    // variable declarations
    // constants
    const int MAX = 10;
    const int MONTHS = 4;
    
    // arrays
//    int recipes[MAX][MAX]{{}};
//    int prices[MAX][MONTHS]{{}};
//    int costs[MAX][MAX]{{}};
//    string products[MAX]{};
    
    int recipes[MAX][MAX];
    int prices[MAX][MONTHS];
    int costs[MAX][MAX];
    string products[MAX];
    
    // file streams
    ifstream pricesFile;
    ifstream productsFile;
    ifstream ingredsFile;
    
    // open all three input files
    pricesFile.open("./prices.dat");
    productsFile.open("./products.dat");
    ingredsFile.open("./ingredients.dat");
 
    // test to see that all three input files are open, output error message if not open
    if (productsFile.is_open())
        ;
    else
        cout << "Error: coudn't open products.dat!\n";
    if (pricesFile.is_open())
        ;
    else
        cout << "Error: coudn't open prices.dat!\n";
    if (ingredsFile.is_open())
        ;
    else
        cout << "Error: coudn't open ingredients.dat!\n";
   
    // read in products and input them into products[] array
    int productSize = 0;
    productsFile >> productSize;
        // advances to the next line in the input file
    string g;
    getline(productsFile, g, '\n');
    for (int i = 0; i < productSize; i++)
        getline(productsFile, products[i], '\n');
    
    // read in ingredients and input them into recipes[][] array
    int ingredsSize;
    ingredsFile >> ingredsSize;
    for (int i = 0; i < productSize; i++)
        for (int j = 0; j < ingredsSize; j++)
            ingredsFile >> recipes[i][j];
    
    // read in prices and input them into prices[][] array
    int month;
    pricesFile >> month;
    for (int i = 0; i < ingredsSize; i++)
        for (int j = 0; j < MONTHS; j++)
            pricesFile >> prices[i][j];
    
    // multiply recipes[][] array and prices[][] array.
    // input results into costs[][] array
    int sum;
 	for (int i = 0; i < productSize; i++)
 	{
 		for (int j = 0; j < MONTHS; j++)
 		{
 			sum = 0;
 			for (int k = 0; k < ingredsSize; k++)
 			{
 				sum += recipes[i][k] * prices[k][j];
            }  // end inner for loop
            costs[i][j] = sum;
        }  // end middle for loop
    }  // end outer for loop
    
    // output to terminal
    cout << setw(18) << "Bakery Products";
    // outputs four months based on a given beginning month number m
    int m = month;
    int i = 0;
    while  (i < MONTHS){
        switch (m){
            case 1 : cout << setw(12)<< "January"; break;
            case 2 : cout << setw(12)<< "February"; break;
            case 3 : cout << setw(12)<< "March"; break;
            case 4 : cout << setw(12)<< "April"; break;
            case 5 : cout << setw(12)<< "May"; break;
            case 6 : cout << setw(12)<< "June"; break;
            case 7 : cout << setw(12)<< "July"; break;
            case 8 : cout << setw(12)<< "August"; break;
            case 9 : cout << setw(12)<< "September"; break;
            case 10 : cout << setw(12)<< "October"; break;
            case 11 : cout << setw(12)<< "November"; break;
            case 12 : cout << setw(12)<< "December"; break;
        };  // end switch
        if (m == 12)
            m = 1;
        else
            m++;
        i++;
    }  // end while
    cout << endl;
    // outputs products[] array in conjuction with costs[][] array
    for (int i = 0; i < productSize; i++)
    {
        cout << setw(18) << products[i];
        for (int j = 0; j < MONTHS; j++)
            cout << setw(12)<< costs[i][j];
        cout << endl;
    }  // end for

    // close all input files
    ingredsFile.close();
    pricesFile.close();
    productsFile.close();
    
    return 0;
}

