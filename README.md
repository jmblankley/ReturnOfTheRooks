# Return Of The Rooks

Author: Joshua M Blankley

Date Started: 2/1/2023


## DEV LOG

### Day 1 (2/1/2023)

Initiliazed project. Wrote pseudocode.

Constrtucted main class. Construced an initBoard function to initialize the chess board. Constructed readGrid function to to take in fstream and iterate through an input file. Constructed fileRead() function to take user input to select a file. Construced a printGrid() function to print out the 2d array in the text file. 

Started working on functions to place rooks where they will not be able to be attacked. So far for this problem I have two boolean functions that will check every row and column in the 2d array. Still needs finished.

Stopping Point: Got most of canPlace() and solveBoard() started. Need to work out some kinks and get them functioning properly.

### Day 2 (2/4/2023)

Worked on canPlace() and solveBoard() functions. Got some 'R's populated onto the board but not the right number. Need to work on recursion to get it to place them properly. I am close though, hopefully gonna get this figure out next session.

Stopping Point: Need to get the right number of 'R's populating onto the board in the proper spaces.

### Day 3 (2/7/2023)

Had to basically scrap all of canPlace() and solveBoard(). Started the rebuild of these functions, getting close to where I need them, just some slight tweaks and they will be working.

Stopping Point: Need to get canPlace() properly checking for 'R's and '#'s.

### Day 4 (2/13/2023)

Finished project. Needed some small tweaks on solveBoard() to get it to work properly. Tested the program against 6 or 7 different text files and they are worked. 
