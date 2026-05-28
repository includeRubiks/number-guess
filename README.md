# number-guess
A simple number guessing game with (roughly) daily updates.

## The updates so far:
Day One: Made this repo, added the bare minimum. Improved file with necessary things, like number of guesses and range.  
TODO Tommorow: Add input validation.  
Day Two: Very big day! Many improvements were made. First off, I began using classes to organize everything, but that didn't work out very well. So, I just declared functions, and organized it! Lots of organization took place, and so did some input sanitization. Initially, I used different functions to prompt for everything, then I found out I could use just one. I also added input sanitization.  
TODO Tommorow: Add a looping feature and support for flags in the terminal.  
Also on day two: I started making pixel art for the eventual GUI of this game. Feel free to submit a pull request or email me with art!  
Day Three: I decided support for flags would be too hard to implement for too little use, and I want to focus on the SDL3 part of this more. Added a looping feauture! Also decided to have the CLI version named cli.cpp and gui named gui.cpp
Day Four: I began on the gui.cpp file, and added a "Compiling" section of the readme. So far, setting everything up and toying around with SDL3. Following the tutorial by constref on YouTube.
Day Five: Not much done. Put color on screen.

## Compiling
On linux, use g++ gui.cpp or cli.cpp $(pkg-config --cflags --libs sdl3) (the whole second part is not necessary for cli.cpp)
