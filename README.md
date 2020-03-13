# time_storage

This program allows the user to press a button to record the date and time. It supports deletion of the last created time and keeps track of how many date/time entries you have. The user may print at any time. Instructions for how to use the program are outputted at the start of the program.

## Installation

You will need CMake.
https://cmake.org/download/

You can also compile, build, and run it yourself from the source file if you'd like and know how, in which case know that a minimum standard of C++11 is required.

Once you have CMake, navigate to wherever you have the program files in your command-line interface, and run the following commands (without quotes):
1. "cmake ."
2. "cmake --build ."
3. "./time_storage"

## Usage

Upon starting the program, the following instructions are printed to the screen on how to use the program:
```
Press "CTRL-C" to create and add a time entry.
Press "CTRL-Z" to delete the last created entry.
Enter "print" to output all current stored times as well as how many have been stored.
Enter "r" to show these instructions again.
Enter "exit" to exit.
```

Example creating time entries (CTRL-C):
```
Input> ^C
Entry added. Current entries: 1

Input> ^C
Entry added. Current entries: 2

Input> ^C
Entry added. Current entries: 3
```

Example printing the current stored times (print):
```
Input> print
1: Fri Mar 13 01:21:22 2020
2: Fri Mar 13 01:21:28 2020
3: Fri Mar 13 01:21:37 2020
Total entries: 3
```

Example deleting the last entry (CTRL-Z):
```
Input> ^Z
Last entry deleted. Current entries: 2
```

Note that this program does not output the time entries to a text file upon exiting the program. If you wish to save your data you must copy and paste the entries from the print command yourself.

If for whatever reason the key commands "CTRL-C" and "CTRL-Z" do not work for you, you can uncomment lines 88-99 in the code to instead add the commands "e" and "d" for adding a time entry and deleting the last time entry respectively.

## Creation of the Program

I made this program using the limited knowledge of signals I had from taking my operating systems course. This is why only two key press commands are supported, and why those keys are "CTRL-C" and "CTRL-Z" as their signals are easily identified and handled with "SIGINT" and "SIGTSTP".

As of time of writing, it's been a few months since I created this program so my memory is a bit fuzzy. If I recall correctly I struggled with applying signal handling to any other keys, and I couldn't get them working no matter how much research I did whether it to be due to my limited knowledge, the machine I was using (macOS), or the language used for the program (C/C++). If you have any insights on this, feel free to let me know or modify the code yourself to show me.
