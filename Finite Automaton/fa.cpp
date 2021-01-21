#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//------------------------------------------------
// CS421 File fa.cpp for HW2B DFA->Scanner Function
// Your name:
//------------------------------------------------

// ** Change this to fit the HW2B specification - look for **
// ** Must have the same types of tracing couts as mytoken.
// ** Must complete the ** comments with RE

// ---------- DFAs follow -------------------------

// MYTOKEN DFA done by Rika Sensei has a sample
// This FA is for a b^+
bool mytoken(string s)
{
  int state = 0;
  int charpos = 0;

  cout << "Trying the mytoken machine..." << endl;

  while (s[charpos] != '\0')
    {
      cout << "current state: " << state << endl;
      cout << "character: " << s[charpos] << endl;

      if (state == 0 && s[charpos] == 'a')
      state = 1;
      else
      if (state == 1 && s[charpos] == 'b')
      state = 2;
      else
      if (state == 2 && s[charpos] == 'b')
      state = 2;
      else
	{
	  cout << "I am stuck in state " << state << endl;
	  return(false);
	}
      charpos++;
    }//end of while

  // where did I end up????
  if (state == 2) return(true);  // end in a final state
   else return(false);
}// end of mytoken


// IDENT DFA
// This FA is for RE: 1 (1|d|_)*
bool ident_token(string s)
{
    int state = 0;                                                                //sets 0 to state
    int charpos = 0;                                                              //sets 0 to charpos

    cout << "Trying the ident_token machine..." << endl;                          //prints string to user
    //while loop that continues to loop as ong as s[charpos] is not equal to zero
    while (s[charpos] != '\0')
    {
        cout << "current state: " << state << endl;                               //displays current state
        cout << "character: " << s[charpos] << endl;                              //dispays current character

        //This will transiton from state 0 ---->state 1 if state is 0 and characters are 'a' or 'b'
        if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'b'))               //checks to see if in state 0 and has a s[charpos] 'a' ir 'b'
            state = 1;                                                            //assigns 1 to state

        //this is loop on letters, digis or underscore
        //will finction if state is currently at 1
        else
            if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'b'))           //checks for state 1 and s[charpos] is 'a' or 'b'
                state = 1;                                                        //assigns 1 to state
            else
                if (state == 1 && (s[charpos] == '2' || s[charpos] == '3' || s[charpos] == '_'))    //checks if state is 1 and s[charpos] is '2' or'3'or '_'
                    state = 1;                                                                      //assigns state 1 if it does
                else {                                                             //else statment if stuck in state
                    cout << "I am stuck in state  " << state << endl;               //tells the user when the program got stuck and in what state
                    return(false);                                                 //returns false
                }
        charpos++;           //incriments charpos
    }
    if (state == 1)          //if the state is 1 then returns true and ends in a final state
        return(true);
    else
        return(false);       //else if the state is not in 1 return false

}//end of ident


// REAL DFA
// This FA is for RE: d^*. d^+
bool real_token(string s)
{
    int state = 0;                                                                  //sets 0 to state
    int charpos = 0;                                                                //sets 0 to charpos

    cout << "Trying the real_token machine..." << endl;                             //prints string to user
    //while loop that continues to loop as ong as s[charpos] is not equal to zero
    while (s[charpos] != '\0')
    {
        cout << "current state: " << state << endl;                                 //displays current state
        cout << "character: " << s[charpos] << endl;                                //displays current program

        //this will continue looping as long as state is equal to zero and character is ether 2 or 3
        if (state == 0 && (s[charpos] == '2' || s[charpos] == '3'))                 //checks to see if stat is 0 and s[charpos] is ether '2' or '3'
            state = 0;                                                              //assins 0 to state
        //This will check so see if the state is 0 and the character is '.' if so
        //this state will transition from state 0-------> state 1
        else
            if (state == 0 && s[charpos] == '.')                                    //checks to see if state is 0 and s[charpos] is '.'
                state = 1;                                                          //assins 1 to state
            //This will check ans see if state is 0 and s[charpos] is a digit
            //if so then state will transiton from state 1------>state 2
            else
                if (state == 1 && (s[charpos] == '2' || s[charpos] == '3'))         //checks to see if state is 1 and s[charpos] is '2' or  '3'
                    state = 2;

                else
                    //This state will continue looping as long as stat is equal to 2 and the s[charpos] is a digit
                    if (state == 2 && (s[charpos] == '2' || s[charpos] == '3'))     //checks to see if state is 2 and s[charpos] is '2' or '3'
                        state = 2;                                                  //assigns 2 to state
                    else
                    {
                        cout << "I am stuck in state " << state << endl;            //tells the user when the program got stuck and in what state
                        return(false);                                              //return false
                    }
        charpos++;            //increment charpos
    }

    if (state == 2)           //if state is equal to 2 then return true and ends in a final state
        return(true);
    else                      //else if state is not equal to 1 then return false
        return(false);
}//end of real


//INT DFA
// This FA is for RE: d^+
bool integer_token(string s)
{
    int state = 0;                                                                  //sets 0 to state
    int charpos = 0;                                                                //sets 0 to charpos

    cout << "Trying the integer_token machine..." << endl;                          //prints string to user
    //while loop that continues to loop as ong as s[charpos] is not equal to zero
    while (s[charpos] != '\0')
    {
        cout << "current state: " << state << endl;                                 //displays current state
        cout << "character: " << s[charpos] << endl;                                //displays current program
        //This will check to see if the state is 0 and the s[charpos] is equal to '2' or '3'
        //if so then the state will transition from state 0 ---------> state 1
        if (state == 0 && (s[charpos] == '2' || s[charpos] == '3'))                 //checks to see if state 0 and s[charpos] is '2' or '3'
            state = 1;                                                              //sets 1 to state
        //will continue to loop as long as state is equal to 1 and s[charpos] is equal to '2' or '3'
        else
            if (state == 1 && (s[charpos] == '2' || s[charpos] == '3'))             //checks to see if state 0 and s[charpos] is equal to '2' or '3'
                state = 1;                                                          //sets 1 to state
            //prints that you are currently stuck in state
            else
            {
                cout << "I am stuck in state " << state << endl;                    //tells the user what state the program was stuck in
                return(false);                                                      //returns false
            }
        charpos++;              //incriment charpos
    }//end of while

    if (state == 1)             //if state is equal to 1 then return true and ends in a final state
        return(true);
    else
        return(false);          //else if state is not equal to 1 then return false
}// end of int


// -----------------------------------------------------

enum tokentype {ERROR, MYTOKEN, IDENT, REAL, INT};
int scanner(tokentype& , string& );  // to be called by main
fstream fin;   // file stream to use

// The test-driver -- NO NEED TO CHANGE THIS
int main()
{ string fname;
  cout << "Enter the input file name:";
  cin >> fname;

  fin.open( fname.c_str(), fstream::in);

  string tokens[5] = {"ERROR", "MYTOKEN", "IDENT", "REAL", "INT"};
  tokentype thetype;
  string theword;

  while (true)  // keep on going
    {
      scanner(thetype, theword);  // the paramers will be set by Scanner
      if (theword == "EOF") break;

      cout << ">>>>>Type is:" << tokens[thetype]  << endl;
    }

  cout << ">>>>>End of File encountered" << endl;
  fin.close();
}// end of main


// Scanner sets the_type and w - TO BE COMPLETED **
int scanner(tokentype& the_type, string& w)
{

  // This goes through all machines one by one on the input string w

  cout << endl;
  cout << ".....Scanner was called..." << endl;

  fin >> w;  // grab next word from fain.txt
  cout << ">>>>>Word is:" << w << endl;

  if (mytoken(w))
    { the_type = MYTOKEN;
  }
  //checks to see if w is the "EOF" so it doesnt have to go through all test cases
  else if (w == "EOF") {
      cout << "Reach the end of the file" << endl;
      the_type = ERROR;                                         //assigns ERROR to the_type
  }
    //else if the token is ident the assign IDENT
    else
      if (ident_token(w))
      {
          the_type = IDENT;                                     //assigns IDENT to the_type
      }
      //else if token is real then assign IDENT
      else
          if (real_token(w))
          {
              the_type = REAL;                                  //assign REAL to the_type
          }
          //else if token is integer then assign INT
          else
              if (integer_token(w))
              {
                  the_type = INT;                               //assign INT to the_type
              }
  else //none of the FAs returned TRUE
    { cout << ">>>>>Lexical Error: The string is not in my language" << endl;
      the_type = ERROR; }


}//the very end of scanner
