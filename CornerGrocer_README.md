# Corner Grocer Item Tracker

A C++ program that analyzes a store's daily purchase records and reports how
often each item was bought. It was built for CS 210 as the course project.

## Project summary and the problem it solved

The Corner Grocer needed a way to understand which produce items sell the most
so they could rearrange their produce section for a better layout. The store
generates a text file that lists every item purchased during the day, in the
order it was bought. My program reads that file, counts how many times each
item appears, and lets the user explore the results. From a menu the user can
look up the frequency of one item, print the frequency of every item, or print
a text histogram that draws one asterisk for each purchase. The program also
writes a backup file called frequency.dat at start up so the counts are saved
without the user having to do anything.

## What I did particularly well

I think the object oriented design came out clean. All of the counting and
reporting logic lives inside an ItemTracker class, and the data (a map of item
names to counts) is kept private so the rest of the program can only touch it
through a small set of public functions. That kept main short and easy to
follow, since main mostly just runs the menu. Choosing a map for the counts
also worked out well because it stores each item only once and keeps everything
in alphabetical order for free, which made the output tidy without any extra
sorting code.

## Where I could enhance the code

Right now the input file name is written directly into the program. A good
improvement would be to let the user type the file name, or read it from a
settings value, so the program is not tied to one specific file. The item
lookup is also case sensitive, so searching for "cranberries" instead of
"Cranberries" returns zero. Making the lookup case insensitive would make it
more forgiving and less error prone for a real cashier. I could also add more
defensive handling for a messy input file, such as skipping blank lines or
lines that are not formatted the way I expect, which would make the program
more secure against bad data instead of trusting that the file is always
perfect.

## The most challenging part and how I got through it

The trickiest piece was handling user input safely on the menu. When someone
types a letter where a number is expected, cin goes into a failed state and, if
you do not fix it, the program can get stuck in a loop. Learning to clear the
error with cin.clear() and then discard the leftover input so the next prompt
reads correctly took some trial and error. I worked through it by testing with
bad input on purpose and by reading the file input and output sections in
zyBooks. I am adding cppreference and the zyBooks examples to my go to
resources, since being able to look up exactly how a function behaves saved me
a lot of guessing.

## Skills that will transfer to other work

A lot of this project carries over. Designing a class with a clear public
interface and private data is something I will reuse in almost any language,
not just C++. Reading from and writing to files, counting things with a map or
similar structure, and validating user input before trusting it are all common
needs in real programs. Keeping the main function thin and pushing the real
work into a class is also a habit that scales up to much bigger projects.

## How I made it maintainable, readable, and adaptable

I used clear names for variables and functions so the code mostly explains
itself, and I added in line comments to describe what each section does and why.
Splitting the class across a header file and a source file makes the structure
easy to navigate and lets the class be reused somewhere else. I also stored the
file names as named constants at the top instead of scattering them through the
code, so if a file name changes there is only one place to update. Because the
counting logic is separated from the menu, I could add a new report later
without rewriting the parts that already work.

## Files

- `main.cpp` — menu driver and program entry point
- `ItemTracker.h` — ItemTracker class declaration
- `ItemTracker.cpp` — ItemTracker class definition
- `CS210_Project_Three_Input_File.txt` — input data
