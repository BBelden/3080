// Name:       Ben Belden
// Class ID#:  bpb2v
// Section:    CSCI 3080-001
// Assignment: lab3
// Due:        22:00:00, November 27, 2013
// Purpose:    Read in a hamming-encoded packet, check for errors, extract the message,
//             convert from gray to binary, convert binary to decimal, look up the
//             decimal index in the cipher, ouput decoded/deciphered message.
// Input:      Read from pre-formatted files.
// Output:     Print to terminal.
//
// File:       lab6.cpp
//

#include <iostream>     // for std::cout
#include <fstream>      // for std::ifstream
#include <cmath>        // for pow()

// function declarations
void hammingCheck(char array[]);
void extractGray(char inArray[], char outArray[]);
void grayToBinary(char inArray[], int outArray[]);
int decimalKey(int inArray[]);

int main(int argc, const char * argv[])
{
    // declare variables
    std::ifstream packets, chars;
    const int MAX_CHARS = 56, MAX_BITS = 11, WORD_SIZE = 6;
    char cipher[MAX_CHARS]={'0'}, hamming[MAX_BITS]={'0'}, gray[WORD_SIZE]={'0'};
    int binary[WORD_SIZE]={0};
    
    // open files and read in cipher
    packets.open("/Users/migration/Desktop/xCode/discrete/lab3/lab3/packets.dat");
    chars.open("/Users/migration/Desktop/xCode/discrete/lab3/lab3/chars.dat");
    for (int i=0; i<MAX_CHARS; i++)
        chars >> std::noskipws >> cipher[i];
    
    // prime the EOF loop; get first packet
    for (int i = 1; i<MAX_BITS; i++)
        packets >> hamming[i];
    
    // EOF loop
    while (packets){
        hammingCheck(hamming);
        extractGray(hamming, gray);
        grayToBinary(gray, binary);
        int key = decimalKey(binary);
        std::cout << cipher[key];
        
        // get next packet
        for (int i = 1; i<MAX_BITS; i++)
            packets >> hamming[i];
    } // end while
    std::cout << std::endl;
    return 0;
} // end main

//************************************************************************************************

// Function:    hammingCheck
// Purpose:     checks for correct transmission of hamming word. assumes a max of one bit shift.
//              creates a checkWord and flips the corresponding bit.
// Pre-cond:    inArray is the received hamming word containing only 0s and/or 1s
// Post-cond:   inArray contains the transmitted hamming word containing only 0s and/or 1s
void hammingCheck(char inArray[])
{
    int check[4];
    check[0] = (inArray[8]+inArray[9]+inArray[10])%2;
    check[1] = (inArray[4]+inArray[5]+inArray[6]+inArray[7])%2;
    check[2] = (inArray[2]+inArray[3]+inArray[6]+inArray[7]+inArray[10])%2;
    check[3] = (inArray[1]+inArray[3]+inArray[5]+inArray[7]+inArray[9])%2;
    int checkWord = (check[0]*8)+(check[1]*4)+(check[2]*2)+check[3];
    if (inArray[checkWord] == '0')
        inArray[checkWord] = '1';
    else
        inArray[checkWord] = '0';
} // end hammingCheck

//************************************************************************************************

// Function:    extractGray
// Purpose:     extracts the gray code word from the hamming word
// Pre-cond:    inArray is a full hamming word containing only 0s and/or 1s
// Post-cond:   parity bits are removed and the gray code word stored in outArray
void extractGray(char inArray[], char outArray[])
{
    outArray[0] = inArray[3];
    outArray[1] = inArray[5];
    outArray[2] = inArray[6];
    outArray[3] = inArray[7];
    outArray[4] = inArray[9];
    outArray[5] = inArray[10];
} // end extractGray

//************************************************************************************************

// Function:    grayToBinary
// Purpose:     converts a gray word to a binary word
// Pre-cond:    inArray contains only 0s and 1s
// Post-cond:   outArray is the binary equivalent of the gray word
void grayToBinary(char inArray[], int outArray[])
{
    outArray[0] = inArray[0]-48;
    outArray[1] = ((int)inArray[0]+(int)inArray[1]) %2;
    outArray[2] = ((int)inArray[0]+(int)inArray[1]+(int)inArray[2]) %2;
    outArray[3] = ((int)inArray[0]+(int)inArray[1]+(int)inArray[2]+(int)inArray[3]) %2;
    outArray[4] = ((int)inArray[0]+(int)inArray[1]+(int)inArray[2]+(int)inArray[3]+(int)inArray[4]) %2;
    outArray[5] = ((int)inArray[0]+(int)inArray[1]+(int)inArray[2]+(int)inArray[3]+(int)inArray[4]+(int)inArray[5]) %2;
} // end grayToBinary

//************************************************************************************************

// Function:    decipher
// Purpose:     Convert an array containing a binary word to its decimal equivalent
// Pre-cond:    array passed in only contains 0s and/or 1s
// Post-cond:   return the decimal equivalent
int decimalKey(int inArray[])
{
    int key=0, exp=5;
    for (int i=0; i<6; i++){
        key = key + pow(2,exp) * inArray[i];
        exp--;
    } // end for
    return key;
} // end decipher
