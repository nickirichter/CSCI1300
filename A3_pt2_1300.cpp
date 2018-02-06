// Author: Nicole Richter
// Recitation: 202-Bu Sun Kim
//
// Assignment 3
// Problem 2

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
/**
 * Algorithm for determining wind chill over variable wind speeds
 * Increment user input value of V (wind speed) by wind_speed_step
 * Fixed temperature T (air temperature)
 * wind chill = 35.74  + 0.6215*T - 35.75*pow(V, .16) + .4275*T * pow(V, 0.16)
*/

float windChillCalculator(float T, float V)
{
    float wind_chill = 35.74  + 0.6215*T - 35.75*pow(V, .16) + .4275*T * pow(V, 0.16);
    return wind_chill;
}

void printWindChill (float T, float low_wind_speed, float high_wind_speed, float wind_speed_step)
{
    float wind_chill;
    while (low_wind_speed <= high_wind_speed)
    {
        float z = windChillCalculator (T, low_wind_speed);
        cout << "The wind chill is " << z << " degrees F for an airtemperature of " << T << " degrees F and a wind speed of " << low_wind_speed << " mph." << endl;
        low_wind_speed = low_wind_speed + wind_speed_step;
    }

}
int main ()
{
    float T;
    cout << "Enter air temperature value: " << endl;
    cin >> T;
    float V;
    cout << "Enter wind speed value: " << endl;
    cin >> V;
    float wind_chill = windChillCalculator(T, V);
    cout << "The wind chill is " << wind_chill << " degrees F." << endl;
    float low_wind_speed;
    float high_wind_speed;
    float wind_speed_step;
    cout << "Enter low wind speed value: " << endl;
    cin >> low_wind_speed;
    cout << "Enter a high wind speed value: " << endl;
    cin >> high_wind_speed;
    cout << "Enter increment for wind speed values: " << endl;
    cin >> wind_speed_step;
    printWindChill (T, low_wind_speed, high_wind_speed, wind_speed_step);

}




