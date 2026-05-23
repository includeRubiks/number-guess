#include <iostream> //The standard C++ import
#include <cstdlib> //Used for random number generation

/*
This code is Copyright 2026 Doug Mead under the GNU General Public License v3.0 for more info, see "LICENSE".
There are 3 sections in this code as of this commit. Their names and purposes, respectively are:
1. Definitions - To define and/or initialize all the variables that are to be used
2. Input - Take in the user's input.
3. Anylization - Anylize the user's guess and report back
Sections 2 and 3 are looped for as many guesses as are defined in section 1.
*/

using namespace std;

int main(){
	
	//The following section will define all the variables or ask the user to define them
	
	int guesses; //The number of guesses the user gets
	cout << "Number of Guesses? ";
        cin >> guesses;
	int minimum; //The minimum random number
	cout << "Minimum Number? ";
	cin >> minimum;
	int maximum; //The maximum random number
	cout << "Maximum Number? ";
	cin >> maximum;
	int number = rand() % (maximum - minimum + 1) + minimum; //The random number generation
	float guess; //The guess, defined as a float because it allows for binary search guessing.
	
	for (int i = 0; i < guesses; i++) {

		//The following section takes user input

		cout << "Guess? "; //Prompt the user for their guess
		cin >> guess; //Save the guess

		//The following section anylizes the user input and gives output

		if (guess > number) { 
			cout << "Too high!" << endl;
		}
		else if (guess < number)
		{
			cout << "Too Low!" << endl;
		}
		else if (guess == number)
		{
			cout << "You got it!" << endl;
			exit(0);
		}
	}
	if (guess != number) {
		cout << "Better luck next time!" << endl;
	}
}
