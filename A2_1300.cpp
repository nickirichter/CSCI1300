// Nicki Richter: CS1300 Fall 2017
// Recitation: 202 - Bu Sun Kim
//
// Assignment 2

#include <iostream>

using namespace std;

/**
 * Algorithm determining U.S. population in exactly one
  year (365 days) with howMany()
 * sum of births, deaths, immigrants with initial population
 * return new population
*/

int howMany (int population) {
    int pop;
    int births;
    int deaths;
    int immigrants;
    pop = 325766246;
    int tsecs = (365 * 24 * 60 * 60);
    births = (tsecs/8);
    deaths = tsecs/12;
    immigrants = tsecs/33;
    int endPop = 0;
    endPop = (population+births-deaths+immigrants);
    return endPop;

}


/**
 * Algorithm for finding number in years, months, days, and seconds given seconds between 0 and 1,000,000
 *if decimal left over, number of hours=decimal/(60*60)
 *if no decimal, output number of days, 0 hours, 0 minutes, 0 seconds
 *if decimal left over, number of minutes=decimal/60
 *if no decimal, output number of days, number of hours, 0 minutes, 0 seconds
 *if decimal left over, number of seconds=decimal
 *output number of days, number of hours, number of minutes, number of seconds
 *if no decimal, output number of days, number of hours, number of minutes, 0 seconds
 */
void howLong(int seconds) {
    int numberofdays = seconds/86400;
    int remainder = seconds%86400;

    int numberofhours = remainder/3600;
    remainder = remainder%3600;

    int numberofminutes = remainder/60;
    remainder = remainder%60;

    int numberofseconds = remainder;
    if (seconds <= 0)
    {
        numberofdays = 0;
        numberofhours = 0;
        numberofminutes = 0;
        numberofseconds = 0;
    }
    cout << "Time is " << numberofdays << " days, " << numberofhours << " hours, " << numberofminutes << " minutes, " << "and " << numberofseconds << " seconds." << endl;

}


/**
 * Algorithm for converting a user-given temperature (Celsius) to Fahrenheit
 * (Celsius temp-32) * (5/9) = Fahrenheit
 * return input temperature to Fahrenheit temp
 */
int howHot(int Ctemp)
{

    int Ftemp;
    Ftemp = ((Ctemp*(9/5.0)+32));
    return Ftemp;
}

int main ()
{
     int pop = 1000000;
     cout << howMany(pop);

     int seconds = 70000;
     howLong(seconds);

     int Ctemp = 20;
     cout << howHot(Ctemp);
}
