# Cole_CSCI2270_FinalProject
This program reads in a file (Provided by command line, or 
using the default in the directory).  From that file, a tree 
is built in alphabetical order using the titles.  Vectors are 
created containing each individual console and genre.  User 
can then search for games, print all games of a certain system/genre, 
rent/trade games, add a new game or have a game recommended 
based on their requirements.  Many of the inputs allow the 
user to enter the system/genre of their game in addition to 
the title, so as to search the smaller vectors of games with 
similar attributes instead the full tree alphabetically, saving 
some time (as much as a tree size of 20 can save). 

#How to Run
User needs to download Tree.h, Tree.cpp, main.cpp, and gameList.txt.  gameList.txt can be a command line argument but not required for files to run if gameList.txt is in the same directory

#Group Members
Dylan Cole
Ben Herman

#Open Issues/Bugs
-In the current main branch, Main.cpp lacks #include<stdlib.h>, which
 includes atoi. atoi is not part of the standard library on all
 virtual machines.
-Possible bug is if the text file does not fill a 
vector and you search that vector
