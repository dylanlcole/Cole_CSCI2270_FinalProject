Some of the main menu options are misleading. When "Remove Game"
was selected, I expected a game to be removed from the list. Instead,
the quantity was set to zero. This function should be replaced with
a "set quantity" function that takes the game and the new quantity
as arguments.

Similarly, the program allows you to return a game that you have not
rented. There should be a vector that keeps track of what games are
being rented and how many.

The user should not be required to type N/A whenever some part of the
input isn't specified. A better implementation would be to create
a function that prints out a menu containing the list of genres
or the list of consoles, and prompts the user to the number for their
chosen option (1-4) or 0 if not specified.

All of this could be implemented much more cleanly and with less memory
usage/search if it were implemented in a series of hash tables instead
of a tree and vectors.

There's a bug that I can't reproduce consistently. Sometimes, when
a name including a space is entered after the "Find Game" function
is called, the program starts printing the main menu repeatedly.