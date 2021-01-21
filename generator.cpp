#include<iostream>
#include<string>
#include <cstdlib>
#include "queue.h" // include queue.h or equivalent such as <queue>
using namespace std;
//----------------------------------------------
// CS421 HW1
// Write a generator in C++ for L = {x | x is a binary number}.
// Your name:
//----------------------------------------------

// Copy the recognizer function here from the other file.
bool recognizer(string s)
{
	bool isB;                                       // variable to hold true or false value of true or false
	for (int j = 0; j < s.length(); j++) {          // loop that checks the value for the legth of the string
		if (s[j] == '1' || s[j] == '0') {           // checks to see if the value at a specific position is a bool number and assigns it to be true if it is
			isB = true;								//assigns isB to true
		}
		else {                                      //else if the value is anything other then a 1 or a 0 then isB is assigned false
			isB = false;							//Assigns isB to false
			break;                                  //Breaks the loop to stop the iteration due to it allready failing by having a value that was not bool
		}
	}
	return isB;                                     //returns ether true or false

}


// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed.
//   Keeps on going until the queue overflows but the user can
//   terminate the program with control-C
//   after about 20 strings have been displayed.
int main()
{
	int numberOfElements = 0;												//counter to hold number of iterations checked
	int counter = 0;														//counter to hold number of displayed binary numbers
	queue queueNumbers;														//the queue to hold all the numbers
	string userInput;														//holds the string of the users input
	string numbersUsed[] = { "0", "1", "2" };								//numberes used when generating the sets
	string number;															//this value will be pushed to the recognizer
	string newNumber;														//the new newNumber created systematically

// initialize queueNumbers with numbersUsed
for (int i = 0; i < sizeof(numbersUsed) / sizeof(numbersUsed[0]); i++) {		//for loop to to initalize the quenumbers with the numbers used
	queueNumbers.add(numbersUsed[i]);											//adds numbers to the queue
}

try {
	while (true) {
		numberOfElements++;																							//increments numberOfElements to keep track of iterations checked
		queueNumbers.remove(number);																				//removes the current number from queueNumbers for each iteration
		//If statment that print the number that is binary and an explination that it is binary as long as it recieves true from the recognizer.
		if (recognizer(number)) { 																					//pushes the number to recognizer to be analized
			cout << number << " is binary " << endl;																//If the value returned is true then display the number and string after
			counter++;																								//increment counter
		}
		//if statment that executes if the Queue is not full that creates a new number and adds it to to the initalized queue
		if (!queueNumbers.isFull()) {																				//create new number and add into queueNumbers
			for (int j = 0; j < sizeof(numbersUsed) / sizeof(numbersUsed[0]); j++) {								//iterates through queue to poppulate it with numbers
				newNumber =  numbersUsed[j] + number;																//adds number to numUsed onto newNumebr
				queueNumbers.add(newNumber);																		//adds newNumber to queueNumbers

			}
		}
		//checks user input so that they can see 20 results and decided if they want to terminate the program or not.
		if (counter == 20 || counter == 40 || counter == 60 || counter == 80 || counter == 100 || counter == 120)	//If counter equals 20, 40, 60, 80, 100, 120 then user input is needed
		{
			counter++;																								//inciment counter
			cout << "The number of Elements Processed is " << numberOfElements << endl;								//prints the number of elements processed
			cout << "Enter STOP to stop program or continue with any input or enter CTR-C \n";						//explination of what to input
			cin >> userInput;																						//takes user input
			//if the user inputs stop or STOP then a message is given that you have terminated the program and exits.
			if (userInput == "stop" || userInput == "STOP")															//checks for two inputs and if it equals one then terminates program
			{
				cout << "You have terminated the program...\n";														//displays that the user has terminated the program
				exit(1);
			}
		}

	}// end of while
}
catch (queue::Overflow) {								//catches any errors for overflow when there are to many values in the queue
	cerr << "ERROR: Queue is full." << endl;			//displays error message explaining what happened
	return 0;
}
catch (queue::Underflow) {								//catch any errors for underflow when there are no more values in the queue
	cerr << "ERROR: Queue is empty." << endl;			//displays error message explaining what happened
	return 0;
}

}// end of main
