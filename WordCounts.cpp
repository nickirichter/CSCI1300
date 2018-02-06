//Nicki Richter
//Recitation 202: Bu Sun Kim
//
//Assignment 7

#include "WordCounts.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

/*
Algorithm:
take in sentence: string of multiple words
remove punctuation
use a for loop to increment word count for every unique word in sentence
*/

//constructor
WordCounts::WordCounts()
{
    newWordCount=0;
}
//destructor
WordCounts::~WordCounts()
{

}
//remove punctuation keep running count of words in string
void WordCounts::tallyWords(string sentence)
{
    stringstream ss(sentence);
    string word = "";
    while(getline(ss, word, ' ')){

    for (int i=0; i<word.length(); i++)
    {
       word[i] = tolower(word[i]);
    }
       if (ispunct(word[0]))
       {
           word.erase(0,1); //erase punctuation at very beginning of word
       }

       if(ispunct(word[word.length()-1]))
       {
           word.erase(word.length()-1,1); //erase punctuation at end of word
       }

       bool isfound = false; //bool to determine if word is found in word array: initialize to false
        for (int i=0; i<newWordCount; i++)
        {
            if (word_arr[i]==word) //if word is in the word array
            {
                word_count[i]++; //increment the word count at position i
                isfound=true; //change isfound to true since it is in the array
            }

        }

        if(isfound==false) //if word is not found in the words array
          {
              word_count[newWordCount]=1;
              word_arr[newWordCount]=word; //add this word into the array/list
              newWordCount++; //increment count of unique words
          }


    }
}


//return current count of given word
int WordCounts::getTally(string word)
{
    for (int i=0; i<newWordCount; i++)
    {
        if (word==word_arr[i]) //if word is in the current words array/list
        {
            return word_count[i]; //return count of that word in the array
        }

    }
    return 0;
}

//reset word count array to 0
void WordCounts::resetTally()
{
    for (int i=0; i<newWordCount; i++) //loop through to reset count array to 0 at each new position in array
    {
        word_count[i]=0;
    }
    for (int i=0; i<newWordCount; i++)
    {
        word_arr[i]=""; //loop through to reset word array to empty at each new position before filling it
    }
    newWordCount=0; //re-initialize unique word counter to 0
}

//find the n most common words in the text w bubble sort
int WordCounts::mostTimes(string words[], int counts[], int n)
{
    bool sorted = false;
    while(!sorted) //while not sorted (not false), sorted = true
    {
        sorted = true;
        for(int i = 0; i < newWordCount - 1; i++)
        {
            if(word_count[i] < word_count[i+1]) //determine if value in index i is less than next value in array
            {
                int temp1 = word_count[i]; //if it is, swap the counts in order to sort in descending order
                word_count[i] = word_count[i+1];
                word_count[i+1] = temp1;

                string temp2 = word_arr[i]; //must also swap here to make sure the count matches w the correct word
                word_arr[i] = word_arr[i+1];
                word_arr[i+1] = temp2;
                sorted = false; //reset to false to continue to loop until the arrays are certainly sorted
            }
        }

        int i=0;
        //i < n so not to return more values than needed
        //i<newWordCount so
        for (int i=0; i< n && i<newWordCount;i++) //n is number of most common words in text
        {
            words[i] = word_arr[i]; //fill words array from my array I was filling
            counts[i] = word_count[i]; //fill counts from my array of counts of word I was filling
        }
        return i; //return the index which tells position of word and count in array
    }

}





