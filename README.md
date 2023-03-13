"Dungeon Crawler Simulator" - Introductory C++ study project.

The game runs on the console, and simulates battles between the player and a number of enemies. The application starts by asking the user to choose a name for their character. Then it asks the user to choose the number of enemies they want to face. Each enemy has their stats randomly assigned within a reasonable range. The app creates a dynamic array with all these enemies, and iterates over it, simulating a combat between the player and the enemy, until one of the two dies. When the player dies or the list of enemies ends, the game ends, and inform the following:

- If the player won or died

- How many enemies of each size did the player kill, and how many weren’t killed.

Example:
You lose!
Slain Enemies:
Big: 3/7
Medium: 7/14
Small: 13/20

Goal

This assignment has as main purpose to put into practice the initial ideas that were introduced. The secondary purpose is to familiarize a bit with the standard C++ library, and use Google to search for solutions in this new language.

Requirements

- Define at least two classes: Character and Enemy, and one enum Sizes (These types must be separated into .h files)

-	Enemies must contain at least the following attributes (which must be randomly drawn): Health, Damage, Size (enum)

-	Do  not create Enemies within a for, pre-ally all enemies in a dynamic collection (remember that it will be necessary to know the total of enemies of each type)

-	Do not make any explicit allocation on the heap. Keep everything in the stack

-	Encapsulate combat logic within a Battle method

-	This method should receive character and enemy, and be able to manipulate them without making copies
