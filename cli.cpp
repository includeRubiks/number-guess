#include <iostream> //The standard C++ import
#include <cstdlib> //Used for random number generation, and for exiting
#include <string> //Used to access strings, if not included by default
#include <ctime> //Used to get the time to seed the number generator

/*
This code is Copyright 2026 Doug Mead under the GNU General Public License v3.0 for more info, see "LICENSE".
There are 3 sections in this code as of this commit. Their names and purposes, respectively are:
1. Definitions - To define and/or initialize all the variables that are to be used
2. Input - Take in the user's input.
3. Analyzation - Anylize the user's guess and report back
Sections 2 and 3 are looped for as many guesses as are defined in section 1.
*/

using namespace std;

	//This subsection of the definitions initializes the variables that are to be defined by the define() function
int guesses; //The number of guesses that the user gets
int minimum; //The minimum random number
int maximum; //The maximum random number
int guess; //The guess of the user, integer because, realisticly, who is going to use a float? Plus, it doesn't really >
int number; //The random number generation

int promptuserint(string prompt) {
        int intervariable;
        cout << prompt; //Prompt the user for ... whatever prompt is specified
        while (!(cin >> intervariable)) { //Check if the guess is a valid integer
                cin.clear();
		cin.ignore(1000000000,'\n');
		cout << "Please enter a valid integer! " << endl << prompt;
	}
        return intervariable; 
}


void define() {
	//The following section will define all the variables or ask the user to define them
	guesses = promptuserint("What is the maximum number of guesses you want? "); //Prompt the user for the number of guesses they should get
	minimum = promptuserint("What is the minimum random number you want generated? "); //Prompt the user for the minimum random number
	maximum = promptuserint("What is maximum number you want generated? "); //Prompt the user for the maximum random number
	if (minimum > maximum) { //Checking if the minimum is more than the maximum, which breaks the code!
		cout << "The minimum value must be less than the maximum! " << endl; //Let the user know that they messed up!
	        minimum = promptuserint("What is the minimum random number you want generated? "); //Prompt the user for the minimum ra>
	        maximum = promptuserint("What is maximum number you want generated? "); //Prompt the user for the maximum random number
	}
	number = rand() % (maximum - minimum + 1) + minimum; //Set the number that is to be guessed
}

void input() {
	//The following section takes user input for the guess. This is looped, along with the next section until the maximum number of guesses is reached
	guess = promptuserint("What is your guess? "); //Prompt the user for their guess
}

int analyze() {
	//The following section analyzes the user input and gives the result
	if (guess > number) {
		cout << "The guess is too high! " << endl;
	}
	else if (guess < number)
	{
		cout << "The guess is too low! " << endl;
	}
	else if (guess == number)
	{
		cout << "You got it!" << endl;
		return 2;
	}
	return 0;
}

int main(){
	while (true) {
		define();
		for (int i = 0; i < guesses; i++) {
			input();
			if (analyze() == 2) { //If the analyze function returns 2, which it does when the user is successful, it will break the loop and ask if the user wants to play again.
				break;
			}
		}
		if (guess != number) {
			cout << "You ran out of guesses!" << endl;
		}
		
		if (promptuserint("Do you want to play again? (1 for yes, anything else for no) ") != 1) {
			break;
		}
	}
	cout << "Goodbye!" << endl;
}
