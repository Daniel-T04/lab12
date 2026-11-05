# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:


 break Hangman::Hang(): sets a breakpoint on the derived contrsutor.

 
 run: Starts the program and pausing at the Hangman constructor.


 bt: Displays the call stack or the backtrcae for the Hangman.


 break Game::Game: Sets a breakpoint on the base contsructor.


 continue: Resumes the execution until  hitting the base consturctor.


 bt: Displays the call stack showing both constructors chained


 finish: Exits the current function (Game constructor) and returns the caller.


 break Hangman::~Hangman: Sets a breakpoint on the derived destructor


 break Game::~Game: Sets a breakpoint on the derived destructor.


 continue: Resume the execution until the program exits, which trigging destruction.

Backtrace inside `Hangman::Hangman` (paste it):

#0  Hangman::Hangman (this=0x7fffffffe160) at /home/ubuntu/lab12/src/hangman.cpp:8

#1  0x0000555555557733 in main () at /home/ubuntu/lab12/app/main.cpp:49

Backtrace inside `Game::Game` (paste it):

#0 Game::~Game (this=0x7fffffffe1f0, __in_chrg=<optimized out>) at /home/ubuntu/lab12/include/game.h:5

#1  0x0000555555557cc6 in Minesweeper::~Minesweeper (this=0x7fffffffe1f0, __in_chrg=<optimized out>) at /home/ubuntu/lab12/include/minesweeper.h:5

#2  0x000055555555791b in main () at /home/ubuntu/lab12/app/main.cpp:90

Where `finish` returned to:

finish exited the std::allocated helper frame and returned execution directly back to Hangman::Hangman in src/hangman.cpp:8, right where the constructor's initializer list invokes Game ("Hangman").


Order of destructor breakpoints when the program ended:

Hangman::~Hangman in Breakdown 2 since it was hit first when the derived objects begins 


Game::~Game in Breakdown 3 since it was hit second as the base part od the object is subsequently destroyed 


Construction order and destruction order, as read from the backtraces:

Order for Construction goes the Base 'Game' initializes first, then Derived 'Hangman' initializes second.


The backtrace reads it as. When I checked the backtrace inside other Constructors like Game::Game, Game::Game was at #0 then follows Hangman::Hangman right below with #1. this shows that the derived constructor pauses its own execution to call and fully execute the base constructor first, making sure the base-class parts of the objects exits before the derived class builds on top of them.


Destruction Order does Derivewd like Hangman and Minesweeper gets destory first, then Base Game destory second.


The backtrace reads it as. When my destructor breakpoint hits, Game::~Game at #0 on top then called by Minesweeper::~Minesweeper or Hangman::~Hangman sitting at #1. it proves that the derived destructor executes first to tear down its own specific layers then automatically invokes the base destructor to dismantle the rest of the object in strict reverse order of construction.


### What a base pointer shows

`print hangman` (paste it):

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:
