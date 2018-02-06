//Author: Nicole Richter
//Recitation 234- Bu Sun Kim
//
//Assignment 6

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

//Problem 1
//read file, count characters, average the number of characters
//use getline to read entire line including spaces
//average number of characters is returned

float avgCharsPerLine(string filename)
{
    float count=0;
    float char_num=0;
    ifstream myfile;
    myfile.open(filename);
    if (myfile.fail())
    {
        return 0;
    }
    else
    {
        string mystring;
        while (getline(myfile, mystring))
        {
            char_num=char_num+mystring.length(); //number of characters=number of characters + characters in string
            count++; //number of lines
        }
    }
    myfile.close();
    float avg= char_num/count; //average=number of characters (sum)/number of lines
    return avg;
}


//Problem 2

int fillArray(string filename, float array[][5])
{
    ifstream myfile;
    myfile.open(filename);
    if (myfile.fail())
    {
        return 0;
    }
    else
    {
        string mystring="";
        int rows=0;
        getline(myfile, mystring); //ignores header line
        while (getline(myfile, mystring)) //looks at entire line including white spaces
        {
            stringstream s(mystring); //stringstream acts like a file but specifically for program: file of mystring
            int col=0;
            string str="";
            while(getline(s, str, ',')) //separates numbers at ','
            {
                array[rows][col]= stof(str); //fill array with rows and columns, transform string to float
                col++;
            }
            rows++;
        }
        myfile.close();
        return rows; //return number of rows in array
    }
}

//Problem 3
float arrayStats(string filename, float numbers[][5])

{
    float avg_rows=0;
    float avg_col=0;
    float row1=0;
    float col1=0;
    float sum_rows=0;
    float sum_col=0;
    float sum_final=0;

    int rows=fillArray(filename, numbers); //call function to get array and organize, use rows for size in array

    for (int i=1; i<rows; i+=2) //look at odd rows only
    {
        for (int j=0; j<5; j++) //index through each column spot in row
        {
           row1=numbers[i][j];
           sum_rows=sum_rows+row1; //add numbers in row and store as sum
        }
        avg_rows=avg_rows+sum_rows/5; //mean of rows/column #, plus previous mean of rows
        sum_rows=0;
    }
    for (int j=1; j<5; j+=2) //look at odd columns only
    {
         for (int i=0; i<rows; i++) //index down column at every row spot in column
         {
            col1=numbers[i][j];
            sum_col=sum_col+col1; //add numbers in column and store as sum
         }

        avg_col=avg_col+sum_col/rows; //mean of column values/# of rows, plus previous means of columns
        sum_col=0;
    }
    sum_final=avg_rows+avg_col; //add the sums of averages of rows and sums of averages of columns
    return sum_final; //return sum value

}
 //Problem 4
int search(string array[], int size, string target) //search function to go through an array to find target
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


void addBookRatings(string filename, string users[], int ratings[][50])
{

    ifstream myfile;
    myfile.open(filename);
    string string_user = "";

    getline(myfile, string_user); //ignore header line

    for(int i = 0; i < 100; i++) //go through number of users (max)
    {
        users[i] = "";
        for(int j = 0; j < 50; j++) //number of ratings (max)
        {
            ratings[i][j] = 0; //initialize to 0 so we can replace ratings IF it needs to be replaced
        }
    }

    int i=0;

    while(getline(myfile, string_user))
    {

        istringstream ss(string_user); /////set ss to contents of stream

        string name, book_id, rating;
        getline(ss, name, ','); //looks at the string stream at name
        getline(ss, book_id, ','); //looks at string stream at book_id
        getline(ss, rating); //looks at string stream at rating

        int book = stoi(book_id); //convert string to int
        int rate = stoi(rating); // "                   "
        int index = search(users, i, name); //call search function to search in the users array and determine if a name has appeared or not
        if(index == -1)
        {
            users[i] = name;
            ratings[i][book] = rate; //if a name has not appeared, add this name to the array
            i++; //increment to move to next row
        }
        else
        {
            ratings[index][book] = rate; //if name has appeared, move to the next rating
        }
    }


}


