# CS580u Programming and System Tools
## Fall 2018
### PROGRAM 4 README FILE

## KNOWN BUGS AND INCOMPLETE PARTS:
- valgrind


## REFERENCES:
- N/A

## MISCELLANEOUS COMMENTS:
- N/A

# Assignment Description
## Program 4 - Files and Structures
### Due Date: 5:00 p.m., November 9th, 2018

*All programs will be tested on the machines in the Q22 lab. If your code does not run on the system in this lab, it is considered non-functioning EVEN IF IT RUNS ON YOUR PERSONAL COMPUTER. Always check that your code runs on the lab machines before submitting.*

### Driver Code and Test Files

* program4.c
    * include the driver code with your submission, but do not alter it, except where specified by comments
* players.dat

### Grading Rubric

**_TOTAL: 25 points_**

* **Part A** (15 points):
    * Test 1: Reads in player file correctly (4 points)
    * Test 1: Initializes Teams correctly  (4 points)
    * Test 2: Sanity check for null pointer (1 points)
    * Test 3: Game function implemented as described: (4 points)
    * Test 4: Team can play against itself (2 points))
* Part B (10 points):
    * Test 5: Ensure teams are a power of two (1 point)
    * Test 6: Tournament results in a single winner (3 points)
    * Test 7: Tournament results in a random winner (2 points)
    * Test 8: Cleans up memory for each Team(4 points)
        * uses a function pointer for the delete function
* Style Guidelines and Memory Leaks
    * You will lose significant points for the following:
        * Makefile does not have requested format and labels (-5 points)
        * Memory leak or error detected in valgrind  (-5 points)
        * Does not follow requested program structure and submission format (-10 points)

### Guidelines

This is an individual assignment. You must do the vast majority of the work on your own. It is permissible to consult with classmates to ask general questions about the assignment, to help discover and fix specific bugs, and to talk about high level approaches in general terms. It is not permissible to give or receive answers or solution details from fellow students.

You may research online for additional resources; however, you may not use code that was written specifically *to* solve the problem you have been given, and you may not have anyone else help you write the code or solve the problem. You may use code snippets found online, providing that they are appropriately and clearly cited, within your submitted code.

*By submitting this assignment, you agree that you have followed the above guidelines regarding collaboration and research.*

__In this program, you will learn to__:

* Work with files
* Create and Initialize structs

In this lab you are going to implement your own tournament program with teams consisting of players. You will alter the driver code to give the teams whatever names you like, but you will read the players’ data from a file.

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

## Part B:

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

## Part C: Submission

### Required file naming and organization:
* program4.c //Driver Code
* tournament.h
* tournament.c
* players.dat
* makefile
    * You must have the following labels in your makefile:
        * all - to compile all your code to an executable called ‘program4’ (no extension). Do not run.
        * run - to compile if necessary and run
        * memcheck - to compile only if necessary and run with valgrind
        * clean - to remove all executables and object files

:no_entry: Every program will have a required submission guidelines. Please read submission requirements carefully. Any deviations from specifications will result in point deductions or incomplete grades.

## README

* KNOWN BUGS AND INCOMPLETE PARTS
* REFERENCES
* MISCELLANEOUS COMMENTS

Before your final submission, edit the content for each of these sections in this README for your program. You do not have to use markdown, but you can find out more about markdown [here](https://guides.github.com/features/mastering-markdown/) if you would like to.

### Git

Below is a reminder of the commands you need to use to submit your program.

:warning: You have created several files and even a folder for this program. Be sure you add them to the repo. If you forget to add the files and the keys folder to the repo, your assignment will be considered late or not accepted at all.

```shell
git status
git add mylib.h
git commit -a -m "commit message"
git push
```

To find your most recent commit hash, use the following command:

```shell
git rev-parse HEAD
```    

To complete your submission, you must copy and paste this number into mycourses. Go to MyCourses, select cs580u, and **Assignment Hash Submission**.

:warning: You __MUST__ submit the commit hash on mycourses before the deadline to be considered on time **even if your program is completely working before the deadline**. :warning:
