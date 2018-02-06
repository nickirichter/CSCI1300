//Nicki Richter
//Recitation 202: Bu Sun Kim
//
//Assignment 7

#include <iostream>

using namespace std;

#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#endif // SPELLCHECKER_H


class SpellChecker
{
public:
    SpellChecker(); //default constructor
    SpellChecker(string); //constructor for object's language
    SpellChecker(string, string, string); //string for object's language, filename for correctly spelled words, filename for misspelled words and corrections
    ~SpellChecker(); //destructor w no arguments

    bool readValidWords(string); //method for file
    bool readCorrectedWords(string); //method for file
    string repair(string); //method

    bool setStartMarker(char); //setter
    bool setEndMarker(char); //setter
    char getStartMarker(); //getter
    char getEndMarker(); //getter


    string language; //member for language for user to pass in

private:
    char startmarker; //private constructor
    char endmarker; //private constructor
    string valid_arr[10000]; //array of valid words-from file of valid words
    int validIndex; //index for valid_arr
    string correct_arr[10000][2]; //2D array of misspelled and corrected words from file
    int correctedIndex; //index for correct_arr
} ;
