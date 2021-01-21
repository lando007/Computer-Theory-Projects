#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1
// Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name:
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
bool recognizer(string s)
{
    bool isB;                                       // variable to hold true or false value of true or false


    for (int j = 0; j < s.length(); j++) {          // loop that checks the value for the legth of the string
        if (s[j] == '1' || s[j] == '0') {           // checks to see if the value at a specific position is a bool number and assigns it to be true if it is
            isB = true;                             //Assigns isB to true
        }
        else {                                      //else if the value is anything other then a 1 or a 0 then isB is assigned false
            isB = false;                            //Assigns isB to false
            break;                                  //Breaks the loop to stop the iteration due to it allready failing by having a value that was not bool
        }
    }
    return isB;                                     //returns ether true or false

}// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main()
{
    string enterString = " ";                                                     //assigns an empty string to enterString
    while (enterString != "end") {                                                //while statment that continues as long as long as enterString does not equal end
        cout << "Enter string to check, enter 'end' to exit: " << endl;           //explains to user how to use program and to end it
        cin >> enterString;                                                       //assigns entered value to enterString
        bool isBinary = recognizer(enterString);                                  //passes enterString to recognizer and assineds returned boolian to isBinary
        if (isBinary == true) {                                                   //executes if isbinary is true
            cout << "YES IN L " << endl;                                          //displays to user if the value entered is bool
        }
        else if (enterString != "Z") {                                            //executes if isBinary is false
            cout << "NO NOT IN L " << endl;                                       //displays to user if the value entered is not bool
        }
    }

}// end of main
