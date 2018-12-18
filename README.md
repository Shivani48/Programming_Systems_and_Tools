# Program to implement OOPS in C programming
## Fall 2018
### PROGRAM 4 README FILE

## KNOWN BUGS AND INCOMPLETE PARTS:
- valgrind


## REFERENCES:
- N/A

## MISCELLANEOUS COMMENTS:
- N/A

### Driver Code and Test Files

* program4.c
    * include the driver code with your submission, but do not alter it, except where specified by comments
* players.dat

## Part A: Building Your League

For Part A, you will need to create your data structs to represent players and teams, as well as free functions to run your tournament.

#### struct Player
* offensive (`int`)
* defensive (`int`)
* number (`int`)
* team (`int`)
* first (`char *`)
* last (`char *`)

All of the player information will be read in from the player.dat file.

#### struct Team
* name (`char *`)
    * a string buffer for the team
* players (`Player *`)
    * a pointer to an array of players
* `void (*delete)(Team *)`
    * a function pointer to a function that takes a Team pointer and returns nothing
* You may add any additional attributes you require

#### Free Functions
Create the following functions:
* `Player * draftPlayers(char * filename, int team, int num_players)`
    * The draft players function takes a filename for a file containing players in the following format:
        ```
        <team #>,<first name>,<last name>,<player_num>,<offense>,<defense>
        ```
        * :bulb: I recommend the c library function `strtok` for parsing each line.
    * Each player information will be on a separate line
    * You are guaranteed to only have well formed files.
    * The function should return an array of `num_players` for the given team number

* `Team * newTeam(char * name, Player * players)`
    * Takes a team name (`char *`) and an array of players.
    * The function should:
        * Create a Team struct,
        * The function should return a pointer to the newly created team (not a copy).
        * The driver code will use your newTeam() function to create 8, 16, or 32 teams, which will be placed into an array called league[], so make sure your function follows the expected interface.

* `Team * game(Team *, Team *)`
    * Takes pointers to two teams (`Team *`).
    * Your `game()` function should complete the following:
        * The algorithm for determining the winner of a game is as follows:
            * Each team gets at 2 least attempts to score. You can later this as you wish.
            * You must compare the defensive team’s players total defense with a random value between 0 and the offensive team’s total offense.
            * If the final offensive value is greater than the defense, the team has a scored.
    * Return a pointer to the winner.
        * If the game is a tie, it should go to sudden death (use whatever algorithm you choose to determine a winner).
    * Make sure this works correctly before moving on to the next part.

:warning: You will need to typedef your structs to remove the struct keyword in order to run the supplied driver code below.

Once you have your game working and the result is random, create a function:

* `Team * tournament(Team **, int)`
    * Takes an array of pointers to Team structs and the number of teams.
        * You must verify the number of teams is a power of 2. If it is not, print a message saying the number of teams is invalid and return a NULL pointer.
        * :bulb: Use your game function for each round to determine the rounds winners.
    * Because this is an elimination style tournament, each team should lose only once, while the winner goes on to the next round.
    * You will need to create unique matchups (no team plays more than one game per round) for each round between two teams, and discard the losers.
        * :warning: MAKE SURE you do not delete the pointers from the league array. This will cause a memory leak.
    * You will need to keep track of the winners each round, and match them up on the next round.
    * Do not assume you will only have 8 teams. Your code should work with any power of 2 (8 | 16 | 32).

Lastly, you will need to write a function that cleans up memory for each team:

* `void deleteTeam(Team *)`
    * Takes a team pointer and deletes all memory

You will need to point the team `delete` function pointer to this function


