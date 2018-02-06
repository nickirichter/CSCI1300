// Author: Nicole Richter
// Recitation: 202-Bu Sun Kim
//
// Assignment 3
// Problem 1

#include <iostream>
#include <string>

using namespace std;

/**
 * Algorithm Description:
 *   Create a story generator beginning with a menu function
 *   Allow user to choose story 1, story 2, or story 3
 *   May escape mode by pressing 'q'
 *   If entry != 1, 2, 3, or q ask for valid input
*/


void story1 (void)
{
    string pluralnoun = " ";
    string occupation = " ";
    string animal = " ";
    string place = " ";
    cout << "Enter a plural noun: " << endl;
    cin >> pluralnoun;
    cout << "Enter an occupation: " << endl;
    cin >> occupation;
    cout << "Enter an animal name: " << endl;
    cin >> animal;
    cout << "Enter a place: " << endl;
    cin >> place;
    cout << "In the book War of the " << pluralnoun << ", the main character is an anonymous " <<
        occupation << " who records the arrival of the " << animal << "s in " << place << "." << endl;
}

void story2 (void)
{
    string name = " ";
    string state_country = " ";
    cout << "Enter a name: " << endl;
    cin >> name;
    cout << "Enter a state/country: " << endl;
    cin >> state_country;
    cout << name << ", I've got a feeling we're not in " << state_country << " anymore." << endl;
}

void story3 (void)
{
    string first_name = " ";
    string relative = " ";
    string verb = " ";
    cout << "Enter a first name: " << endl;
    cin >> first_name;
    cout << "Enter a relative: " << endl;
    cin >> relative;
    cout << "Enter a verb: " << endl;
    cin >> verb;
    cout << "Hello. My name is " << first_name << ". You killed my " << relative << ". Prepare to " << verb << "." << endl;
}

void menu(void)
{
    cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: " << endl;
    string choice = " ";
    cin >> choice;
    while (choice != "q")
    {
        // put cout in while loop before if statements to repeat menu after story is over
        if (choice == "1")
        {
            story1 ();
            //break;
        }
        else if (choice == "2")
        {
            story2 ();
            //break;
        }
        else if (choice == "3")
        {
            story3 ();
        }

        else
        {
            cout << "Valid choice not selected." << endl;
        }
        cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: " << endl;
        cin>>choice;
    }
    cout<<"Goodbye"<<endl;
}


int main ()
{
    menu();
}
