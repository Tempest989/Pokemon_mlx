# Text-Based Pokemon
Converted an old University OOP Project from C++ to C, whilst bug-fixing the remaining issues in that code.\
This was done to test the reliability and accuracy of the back-end function results so parts of this code can be used in creating the Pokemon Battle Simulator as an extension for the 42 so_long project.\
Though the code is basically finished for now, there are a few known bugs that remain to be fixed currently.
## Running / Compiling Code:
- make, make all and make Text_Pokemon will compile the code into the executable "Text_Pokemon".
- make rm will remove the created executable "Text_Pokemon".
- make run will compile the code into the executable "Text_Pokemon" and then it will run the executable "Text_Pokemon".
## Current Known Bugs / Issues:
- When the fastest Pokemon attack inflicts the Frozen status effect on the targeted Pokemon, the now Frozen, targeted Pokemon is still able to attack that turn, then it shouldn't be able to.
- Haven't fully tested if the Confused status effect or the move Sleep Talk work correctly.
- Make the Commands for interacting with the code more obvious and clear (-1 = back to previous option is not clear anywhere).
- Add more information about battle conditions, such as a Pokemon using Giga Impact must recharge the turn after they connect with the move, but there is no infomation about that happening, or a Pokemon not being able to move due to them being Frozen.
