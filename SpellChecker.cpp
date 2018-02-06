//Nicki Richter
//Recitation 202: Bu Sun Kim
//
//Assignment 7

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cctype>
#include "SpellChecker.h"

using namespace std;
//default constructor
SpellChecker::SpellChecker()
{
    validIndex= 0; //initialize
    correctedIndex= 0;
}
//for language spellchecker is using, not defined in class
SpellChecker::SpellChecker(string input_lang)
{
    validIndex= 0;
    correctedIndex= 0;
    language=input_lang; //set language to user input

}
//open file, return false if file fails to open correctly
bool SpellChecker::readValidWords(string filename)
{
    ifstream valid_file;
    valid_file.open(filename, ios::in);
    if (valid_file.fail())
    {
        return false;
    }
    string valid_word=""; //create empty string to store valid word

    while (getline(valid_file, valid_word)) //use getline to look at full line in file, store in valid_word string
    {
        valid_arr[validIndex]=valid_word; //store valid_word string into array at index position
        validIndex++; //increment index to continue through the array
    }

    valid_file.close();
    return true;

}

bool SpellChecker::readCorrectedWords(string filename)
{
    ifstream corrected_file; //open file
    corrected_file.open(filename);

    if (corrected_file.fail())
    {
        return false;
    }
    else
    {
        string mystring; //create string to store file string line
        //int i=0;
        while(getline(corrected_file, mystring, '\t'))
        {
            correct_arr[correctedIndex][0]=mystring;//fill array at first column w misspelled words
            getline(corrected_file, mystring);
            correct_arr[correctedIndex][1]=mystring; //fill array at second column w correctly spelled words
            correctedIndex++; //increment index of rows to iterate through all of the streams
        }

    }
    corrected_file.close();
    return true;
}

//string for object's language, validfilename for correctly spelled words, correctedfilename for misspelled words and correction
SpellChecker::SpellChecker(string input_lang, string validfilename, string correctedfilename)
{
    validIndex= 0; //starting position
    correctedIndex= 0;
    language=input_lang;
    readValidWords(validfilename);
    readCorrectedWords(correctedfilename);
}

//destructor
SpellChecker::~SpellChecker()
{

}

bool SpellChecker::setStartMarker(char beginchar)
{
    startmarker=beginchar; //set beginning character to startmarker
    return true;
}

bool SpellChecker::setEndMarker(char endchar)
{
    endmarker=endchar; //set endmarker to end character
    return true;
}

char SpellChecker::getStartMarker()
{
    return startmarker;
}

char SpellChecker::getEndMarker()
{
    return endmarker;
}

string SpellChecker::repair(string sentence)
{
    string newsentence = ""; //empty string
    stringstream ss(sentence); //use string stream to split sentence easier
    string word; //substring after parsing
    while(getline(ss, word, ' '))
    {
        if(ispunct(word[0])) //use ispunct to strip punctuation from beginning of word
        {
            word.erase(0,1);
        }
        if(ispunct(word[word.length()-1])) //use ispunct to strip punctuation from last position in word
        {
            word.erase(word.length()-1);
        }
        for (int i=0; i<word.length();i++)
        {
            word[i]=tolower(word[i]); //make all letters in word lowercase
        }

        int pos=-1;
        for (int i=0; i<validIndex; i++)
        {
            if(valid_arr[i]==word)
            {
                pos=i; //update position to index of array
            }
        }
        if(pos==-1)
        {
            for (int j=0; j<correctedIndex; j++)
            {
                if (correct_arr[j][0]==word) //if word is misspelled
                {
                    word=correct_arr[j][1]; //switch the word in same position i to corrected word from column 2
                    pos=j; //update position
                    break; //prevents infinite loop
                }

            }
            if(pos==-1)
            {
                word=startmarker+word+endmarker; //if word is invalid and misspelled beyond recognition return
            }
        }
        newsentence=newsentence+ word +" ";
    }
    newsentence.erase(newsentence.length()-1,1);
    return newsentence;
}


