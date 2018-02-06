//Nicki Richter
//Recitation 202: Bu Sun Kim
//
//Assignment 7

#include <iostream>
#include "SpellChecker.h"
#include "WordCounts.h"

using namespace std;

int main()
{

    SpellChecker sc("English", "VALID_WORDS_3000.txt", "MISSPELLED.txt");
    cout<<sc.readValidWords("VALID_WORDS_3000.txt")<<endl;
    cout<<sc.readCorrectedWords("MISSPELLED.txt")<<endl;
    cout<<sc.repair("tomor is another day!")<<endl;


    WordCounts wc;
    wc.tallyWords("heLlo");


    for (int i=0; wc.word_arr[i] != ""; i++)
    {
        cout<<wc.word_arr[i]<<" "<<wc.word_count[i]<<endl;
    }

    cout<<wc.getTally("hello")<<endl;
    cout << wc.getTally("fox")<<endl;
    cout << wc.getTally("the")<<endl;
    cout << wc.getTally("blue")<<endl;

    wc.resetTally();

    return 0;
}
