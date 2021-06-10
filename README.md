
# My Runner 

**1)Setup file**

**2) Compilation**

**3) Run**

**4) Compile and Run**

# Setup Files

1 Character you can put in the file

    ┌───────────────────────────────┐
    │   'x' = [ /^\ - Cold_pic. ]   │
    ├───────────────────────────────┤
    │   'o' = [  @  - Ghost. ]      │
    ├───────────────────────────────┤
    │   '|' = [  ▒  - End_line. ]   │
    └───────────────────────────────┘

2 Usage

    Example :   row-1 : x_o|

    ·Open 'file.txt' or Open your own file.
    ·Write what you are expected in the game path.

# Compilation (Fedora - 32)

    Example: make re

    Compile:    make re
    Delete:     make fclean

# Run

    Example ./my_runner file.txt 4

    ·Run program:   ./my_runner
    ·With a file:   file.txt
    ·Set a speed:   4          Can't be negative or equal to zero

# Compile and Run

**Example:**

        make launch
        │
        ├>  make re
        └>  ./my_runner file.txt 3 0.0001

**Monde:**

*   Monde1:

        lvl1 > make lvl1
        lvl2 > make lvl2
        lvl3 > make lvl3
        lvl4 > make lvl4
        lvl5 > make lvL5
# Play

    (The Game is explicit)

    ·Press "Space" to jump.

    ·Press "Enter" to Play.
    ·Press "-" or "+" to change the sound volume.
    ·Press "Escape" to leave.
    ·Press "Tab" to stop the game few second.

# ────────────────── REQUIREMENTS ──────────────────

# MUST

* **↓ Done ↓**
    *   The window must be closed using events.
    *   The program must manage the input from the keyboard.
    *   The program must contain animated sprites rendered thanks to sprite sheets.
    *   The program must contain moving (rotating, translating, or scaling) elements.
    *   The program background must include a parallax scrolling with at least 3 objects moving at different speeds.
    *   The program must take a file in argument which will contain the map of your current game.
    *   The program must display a score which is update regularly during the game.
    *   The program must have an end whether it’s a victory or a defeat.
    *   The program must handle basic game physics (jumping / falling / hitting a wall).
    *   The program must have at least one music and one sound effect.

# SHOULD

* **↓ Done ↓**
    *   Your window should have a limited frame rate such that it can be compute without lagging.
    *   The program should accept the “-h” option, then display usage of the program.
    *   Possible user interactions should be explicitly explained in a usage.
    *   Your window should stick between 800x600 pixels and 1920x1080 pixels.

* **↓ In Progress ↓**
    *   The program should have randomly spawning enemies.
    *   Animations and movements in your program should not depend on the speed of your computer.
    *   Animations and movements in your program should be timed by sfClock elements.

# COULD

* **↓ Done ↓**
    *   The program could have several different levels.
    *   The program could have a main menu.
    * The program could have a pause menu.
* **↓ In Progress ↓**
    * The program could store the highest score made.
    * The program could have an infinite mode where you generate randomly the map till the player dies.
    *    The program could let the user customize its character.
    *    The program could have bonus / malus which gives / removes points or advantages to the player.