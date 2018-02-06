// Author: Nicole Richter
// Recitation 202-Bu Sun Kim

// Assignment 5

#include <iostream>
#include <math.h>
using namespace std;

//Problem 1
//sum all of the values in an array

float sumArray(float array[], int size)
{
    float sum=0.;
    for (int i=0; i<size; i++)
    {
        sum=sum+array[i];
    }
    return sum;
}


//Problem 2
//search for target value in array
// return target value
// if target value isn't found, return -1

int search(int array[], int size, int target)
{

    for (int i=0; i<size; i++)
    {
        if (target==array[i])
        {

            return i;
        }
    }

    return -1;
}
//Problem 3
//calculate sum of squared differences between two arrays
//example: squared differences a and b is (a-b)^2

float calculateDifference(int a[], int b[], int size)
{
    float diff=0;
    float sq_diff=0;
    float sum=0;
    for (int i=0; i<size; i++)
    {
        diff=a[i]-b[i];
        sq_diff=pow(diff, 2);
        sum=sum+sq_diff;
    }
    return sum;
}

//Problem 4
//sort array in ascending order (smallest to biggest)
//use selection sort: take smallest value and move to first position in array
void sortArray(float unsortedArray[], int size)
{
    for (int i=0; i<size; i++)
    {
        float small= unsortedArray[i];
        int pos= i;
        for (int j=i; j<size; j++)
        {
            if (small>unsortedArray[j])
            {
                small= unsortedArray[j];
                pos= j;
            }
        }
        float temp=unsortedArray[i];
        unsortedArray[i]=unsortedArray[pos];
        unsortedArray[pos]=temp;
    }
    //cout << unsortedArray[0] << unsortedArray[1];
}

void copyArray(float source[], int size, float dest[])
{
    for (int i=0; i<size; i++)
    {
        dest[i]=source[i];
    }
}

void convert(int rating[], string text[], int size)
{
    for (int i=0; i<size; i++)
    {
        if (rating[i]==0)
        {
            text[i]="Not-Read";
        }
        else if (rating[i]==-5)
        {
           text[i]="Terrible";
        }
        else if (rating[i]==-3)
        {
            text[i]="Disliked";
        }
        else if (rating[i]==1)
        {
            text[i]="Average";
        }
        else if (rating[i]==3)
        {
            text[i]="Good";
        }
        else if (rating[i]==5)
        {
            text[i]="Excellent";
        }
        else
        {
            text[i]="INVALID";
        }
    }
}

float findMedian(float array[], int size)
{
    float ac[size];
    copyArray(array, size, ac);
    sortArray(ac, size);
    /*for (int i=0; i<size; i++)
    {
        cout<<ac[i] << " ";
    }
    cout << endl;
    */
    int middle_val_odd=(size/2);
    int middle_val_even= middle_val_odd-1;
    float return_val=0;
    for (int i=0; i<size; i++)
    {
        if (size%2 != 0)
        {
            return_val= ac[middle_val_odd];
            //cout<<return_val;
            return return_val;
        }
        else
        {
            return_val= (ac[middle_val_even]+ac[middle_val_odd])/2;
            //cout<<return_val;
            return return_val;
        }

    }
}












