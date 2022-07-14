# Text-Based Pokemon
This Project is a Text-Based, Terminal Pokemon Battle Simulator, where the Player, with 6, random, non-duplicate Pokemon from a pool of available Pokemon, must defeat the AI, Steven, who is Champion of Hoem is some Pokemon games, in a 1v1 battle.  
Made from converting an old University OOP Project from C++ to C, whilst bug-fixing the remaining issues in that code.  
This Project was done to improve upon my old C++ code and to test my skills in C to see if I could pull off the conversion from C++ to C successfully.
Though the code is basically finished for now, there are a few known bugs that remain to be fixed currently.
## Makefile Utility:
- `make`, `make all` and `make Text_Pokemon` will compile the code into the executable "Text_Pokemon".
- `make clean` will remove the created executable "Text_Pokemon".
- `make run` will compile the code into the executable "Text_Pokemon" and then it will run the executable "Text_Pokemon".
## Current Known Bugs / Issues:
- When the fastest Pokemon attack inflicts the Frozen status effect on the targeted Pokemon, the now Frozen, targeted Pokemon is still able to attack that turn, then it shouldn't be able to.
- Haven't fully tested if the Confused status effect or the move Sleep Talk work correctly.
- Make the Commands for interacting with the code more obvious and clear (-1 = back to previous option is not clear anywhere).
- Add more information about battle conditions, such as a Pokemon using Giga Impact must recharge the turn after they connect with the move, but there is no infomation about that happening, or a Pokemon not being able to move due to them being Frozen.
- Not following the Given Commands could potentially crash the code, though I haven't attempted to test this, and the only real crash would be if scanf would be unable to handle the input.
