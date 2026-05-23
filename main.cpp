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
	
	//The following section will define all the variables
	
	int range = 100; //The range of numbers (from 1 to this number)
	int number = rand() % range; //The random number generation
	float guess; //The guess, defined as a float because it allows for binary search guessing.
	
	while (true) {
		cout << "Guess? "; //Prompt the user for their guess
		cin >> guess; //Save the guess
		cout << endl; //Write a new line

		if (guess > number) {
			cout << "Too high!" << endl;
		}else if (guess < number) {
			cout << "Too Low!" << endl;
		}else if (guess == number) {
			cout << "You got it!" << endl;
			exit(0);
		}
	}
}
