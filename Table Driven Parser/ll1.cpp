
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<stack>
#include<vector>
#include<string>
using namespace std;

//---------------------------------------
// CS421 File ll1.cpp for HW3A LL1 Table-Driven Parser
// Your name: **
//---------------------------------------

// Complete this to fit the HW3A specification - look for **
// Must have the same types of tracing couts as my demo program.

// Feel free to use a stack class or use a vector
// to implement your stack.  The stack will contain characters.
stack<char> characterStack;
vector<char> M[3][2];  // the table of rules
                       // 3 rows for S, A, B
                       // 2 rows for 0, 1
       // Each slot contains a rule's right side
       // which is a vector of characters

//  ------- conversion functions ------------------------
// to convert non-terms S, A, B to table rows 0, 1, 2
int toRow(char C)
{
    // ** bunch of if then else
    if (C == 'S')               //checks to see if the character is an S. If it is then it will return 0
    {
        return 0;               //returns 0
    }
    else if (C == 'A')          //checks to see if the chatacter is an A. If it is then it will return a 1
    {
        return 1;               //returns 0
    }
    else if (C == 'B')          // checks to see if the chatacter is an B. If it is then it will return a 2
    {
        return 2;               //returns 0
    }

    return -1;                  //returns -1 if no cases are matched
}

// to convert '0' and '1' to table columns 0 and 1
int toCol(char c)
{
    // ** bunch of if then else
    if (c == '0')               //checks to see if the chatacter is a 0. if so returns 0
    {
        return 0;               //returns 0
    }
    else if (c == '1')          //checks to see if the chatacter is a 1. If so returns 1
    {
        return 1;               //returns 1
    }

    return -1;                  //returns -1 if no cases are matched
}

// to convert row 0, 1, 2 to non-terms S, A and B
char toNonterm(int r)
{
    // ** bunch of if then else
    if (r == 0)                 //checks to see if int is a  0.If so returns S
    {
        return 'S';             //returns S
    }
    else if (r == 1)            //checks to see if int is a 1. If so returns A
    {
        return 'A';             //returns A
    }
    else if (r == 2)            //checks to see if int is a 2. If so returns B
    {
        return 'B';             //returns B
    }
    return -1;                  //returns -1 if no cases matched
}


// ** Then complete the following functions.-----------------------------

// to display a rule's rhs which is in vector V
void displayVector(vector<char> V)
{
    // ** display V horizontally e.g. 0 A 0
    cout << "\t\t";
    for (int i = 0; i < V.size(); i++) {                  //increments through vector displaying all letters seperated by blanks
        cout << V[i] << ' ';                              //prints value with a space seperation for each element
    }
}

// to read in the rules into M, make sure ; is not stored
void readrules()
{
    ifstream fin("rules", ios::in);
    int nonTRI;
    int row;
    char lHandSide;
    char rHandSide;

    // For each line of "rules" (e.g. S  0 A 0 ;)
    // The first char of a line determines the row of M
    // The second char of a line determine the column of M
    // Note that each entry of M (the second char up to ;)
    // will be a vector representing
    // the right hand side of a rule (rhs)

    while (fin >> lHandSide) {
        row = toRow(lHandSide);                     //this will set the row value
        fin >> rHandSide;                           //gets the next right hand side character from the file
        nonTRI = toCol(rHandSide);                  //this will set the col index value
        while (rHandSide != ';') {                  //will continue to loop as long as rHandside does not equal ;
            M[row][nonTRI].push_back(rHandSide);    //pushes back the righthandside to the vector
            fin >> rHandSide;                       //reads the next character from the right side
        }
    }

    // ** Display the table nicely
    //    use toNonterm to show row labels (S, A, B)
    //    use displayVector for each content

    for (int i = 0; i < 3; ++i) {                   //loops through nonTerminal and prints value
        cout << toNonterm(i) << ':';                //This will display the left hand side value
        for (int j = 0; j < 2; j++) {               //loops through M and prints the value at the specific location of [i][j]
            displayVector(M[i][j]);                 // This will display the right hand side value
        }
        cout << endl;
    }
}

//  pushes V contents to the stack
void addtostack(vector<char> V)
{
    cout << "Pushing rhs of a rule to the stack." << endl;
    // **  be careful of the order
    // because 1 0 0 means 1 will be at the top of the stack
    // push from end to begin of V, to make sure begin of V is the top of the stack
    for (int index = V.size() - 1; index >= 0; index--) {       //increments through V in a decending order for right hand side production
        characterStack.push(V[index]);                          //pushes charactrStatck the value of v[index]
    }
}

int main()
{

    readrules();  // M is filled and displayed
    char nextChar;
    string ss;
    cout << "Enter a string made of 0's and/or 1's: ";
    cin >> ss;
    // ** push 'S' onto the stack to start
    characterStack.push('S');
    int i = 0;  // index for ss
    while (ss[i] != '\0')  // for each char of ss
    {
        // Based on ss[i] and
        //    the top of stack, update the stack:
        // ** note that empty stack will cause immediate failure
        // ** note that top of stack terminal and ss[i] mismatching
        //    will cause immediate failure
        // ** note that no entry in M for the top of stack (non-terminal)
        //    and ss[i] will cause immediate
        //    failure  (use toRow and toCol to look up M)
        // ** otherwise, addtoStack the M entry based on ss[i] and the top of stack

        if (characterStack.empty()) {                                  //If characterStack is empty this will handle an empty stack case and display information to the user

            cout << "Stack" << endl;
            cout << "[ empty ]" << endl;
            cout << "--------------" << endl;
            cout << "current char is: " << ss[i] << endl;
            cout << ">>Error - stack is empty. Reject!" << endl;
            return 1;
        }
        else {                                                          //Else the stack is copied to display it vertically from top to bottom This way you can pop the coppied stack and not the original
            stack<char> CopyStack(characterStack);                      //creates another stack named copyStack filled with CharacterStack
            cout << "Stack" << endl;
            while (!CopyStack.empty()) {                                //While copyStack is is not empty print out the value at the top of the stack and then pop it off the stack
                cout << CopyStack.top() << endl;                        //prints value of copiedstack.top
                CopyStack.pop();                                        //pops top of copy stack
            }
            cout << "--------------" << endl;
        }
        nextChar = characterStack.top();                                //this will set nextChar to characterStack.top to save the value
        characterStack.pop();                                           //removes the top character
        cout<< "current char is: " << ss[i] << endl;                    //prints the current character to the user

        if (toCol(ss[i]) == -1) {                                       //Checks to see if the character is unknown and if so displays an error to the user and returns a 1
            cout << ">>Error - no rule. Reject!" << endl;               //print error
            return 1;
        }

        if (toCol(nextChar)== -1) {                                     //checks to make sure the nextChar is equal to -1 and if so handles non-erm characters
            addtostack(M[toRow(nextChar)][toCol(ss[i])]);               //adds the value to the stack
            continue;
        }
        else if (ss[i] == nextChar) {                                   //checks to see if ss[i] is qual to nextChar if so diplays it to the user

            cout << "matched!" << endl;                                 //prints information to user
        }
        else {                                                          //else if character does not match print information to user and return 1
            cout << ">>Mismatch error. Reject!" << endl;                //prints information to user
            return 1;
        }
        cout << endl;
        ++i;                                                            //incriments i
    } // end of string


    // ** Here, check for success for failure based on stack empty or not
    if (characterStack.empty()) {

        cout << "Stack" << endl;
        cout << "[ empty ]" << endl;
        cout << "--------------" << endl;
        cout << ">>Accept!" << endl << endl;

        return 0;
    }

    // ** display the stack vertically from top to bottom
    stack<char> CopyStack(characterStack);  //If characterStack is empty this will handle an empty stack case and inform the user that the input is to short
    cout << "Stack" << endl;
    while (!CopyStack.empty()) {
        cout << CopyStack.top() << endl;
        CopyStack.pop();
    }
    cout << "--------------" << endl;
    cout << ">>Reject! input too short" << endl;

    return 1;
}// end of main
