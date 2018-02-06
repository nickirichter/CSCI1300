//Nicki Richter
//Recitation 202: Bu Sun Kim
//
//Assignment 7

#include <iostream>

using namespace std;

#ifndef WORDCOUNTS_H
#define WORDCOUNTS_H
#endif // WORDCOUNTS_H


class WordCounts
{
public:
    //constructor
    WordCounts();

    //destructor
    ~WordCounts();

    void tallyWords(string sentence);
    int getTally(string word);
    void resetTally();
    int mostTimes(string words[], int counts[], int n);

    int newWordCount; //counter for the number of unique words encountered
    string word_arr[10000]; //array of running list of unique words
    int word_count[10000]; //array of number of times the word appears

};


