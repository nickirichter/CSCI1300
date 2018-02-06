// Author: Nicole Richter
// Recitation 202-Bu Sun Kim

// Assignment 4

#include <iostream>
#include <string>
using namespace std;

float similarityScore (string sequence1, string sequence2)
{
	float match = 0;
	float not_match = 0;
	float similarity = 0;

	if (sequence1.length() == sequence2.length())
	{
		int i = 0;
		while (i < sequence1.length())
            {
				if (sequence1[i] == sequence2[i])
					{
						match = match + 1;
					}

				else
					{
						not_match = not_match+1;
					}
                i++;

            }
			similarity = (((sequence1.length() - not_match) / sequence1.length()));
        }
    return similarity;
}

int countMatches(string genome, string sequence1, float min_score)
{
    string mySubstring = "";
    int n_matches=0;
    int i=0;
    while (i<genome.length()-sequence1.length()+1)
    {
        mySubstring = genome.substr(i, sequence1.length());
        float score = similarityScore(mySubstring, sequence1);
        if(score>=min_score)
        {
            n_matches++;
        }

        i++;
    }
    return n_matches;
}

float findBestMatch(string genome, string seq)
{
    int i=0;
    float x=0;
    float bestmatch=0;
    while (i<genome.length())
    {
        x=similarityScore(seq, genome.substr(i, seq.length()));
        if (x>bestmatch)
        {
            bestmatch = x;
        }
        i++;

    }
    return bestmatch;
}

int findBestGenome(string genome1, string genome2, string genome3, string seq)
{
    float score1=findBestMatch(genome1, seq);
    float score2=findBestMatch(genome2, seq);
    float score3=findBestMatch(genome3, seq);

        if (score1>score2 && score1>score3)
        {
            return 1;
        }
        else if (score2>score1 && score2>score3)
        {
            return 2;
        }
        else if (score3>score1 && score3>score2)
        {
            return 3;
        }
        else
        {
            return 0;
        }

}
