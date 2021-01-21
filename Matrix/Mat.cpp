#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

//--------------------------------------
// CS421 File mat.cpp for HW2A Matrix Practice
// Your name:
//--------------------------------------

// the following can be changed and the rest of the code should work
int const R = 3;  // number of rows
int const C = 4;  // number of columns
int const VM = 3; // table entry (vector) length

vector<char>  T[R][C];  // 3 rows and 4 columns table for now

// ------------------ Functions --------------------------------

int convert(char x)
{
    return x - 'a'; //subtracts the askii value of a from the character to get the actual value
}

int readTable()
{
    int row, col;  // row and col numbers
    char col_c;     // column indicator
    ifstream fin("lines.txt", ios::in);

    // Read in the file into T
    while (fin >> row) // next line of file
    {
        fin >> col_c;
        col = convert(col_c);                       // convert to a slot number
        vector<char> v;  // a vector to fill
        char c; // one char from the file

        // ** Fill v with chars from the file (there are VM chars)
        for ( int i = 0; i < VM; ++i) {             //for loop to fill v with chars from the file
            fin >> c;                               //reads characters from file and puts them in c
            v.push_back(c);                         //pushes elements into vector v from the back
        }
        // ** Put  v in T[row][col]
        T[row][col] = v;                            //adds v to t[row][col]
    }//end of while
}

// Displays a vector or "---" if the vector is empty
void showVector(vector<char> v)
{
    if (v.size() == 0)  // empty entry
        for (int i = 1; i <= VM; i++) cout << "- ";                                // prints three --- when there was no entry in the field
    else
        // show the content of v separated by blanks (e.g. "a b c")
        for (int i = 0; i < v.size(); i++) {                                      //for statment that displays all letters seperated by blanks as it loops through the vector
            cout << v[i] << ' ';                                                  //prints out value for it with a blank behind it for seperation
        }
}

// Displays T as a table, separating entries with "|"
void displayTable()
{
    // ** display T nicely labeled with row numbers (col numbers not needed)
    for ( int i = 0; i < R; ++i) {                                  //for statment that will print for each number of rows
        cout << i;                                                  //prints out number of rows
        for ( int j = 0; j < C; ++j) {                              //for statment that will iterate for the total amount of columns

            cout << "| ";                                           //prints a | to seperate each position in the vector
            showVector(T[i][j]);                                    //prints the value associated in each vector either --- or the characters inside that position
        }
        cout << endl;                                               //end the line for that number of rows
    }
}


// Driver
int main()
{
    cout << "Reading table from lines.txt..." << endl;              //message explaining location read from as a string
    readTable();                                                    //calls readingTable
    displayTable();                                                 //calls displayTable
}//the end
