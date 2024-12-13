# Matricies: Management, Manipulation, Mathematics and More!

A project by Patrick Brown for CSPB2270

## Project Walkthrough

If you'd rather watch a complete walkthrough, use the Vimeo link below. Will be deleted January 31, 2025
https://vimeo.com/1039064206

## Structure Implemented

The data structure I chose to explore was the matrix. Simply, a matrix is a number of entries into rows and columns. An entry can be a number to be manipulated using mathematics or even pixels in an image to be manipulated. It can be used for pathfinding in video games. Regardless of the use case, matrices allow for efficient storage and manipulation of data in a structured format.

## Matrix Features

- Have a size, as defined by rows x columns
- Coordinates define each entry, such as (2,2)
- You can perform a number of operations on them such as addition, subtraction and multiplication.
- It's inverse may be used to solve linear equations
- And so much more!

# Run as is

You can simply run `./matrix` in your command line of choice

# Installation Instructions -- Compile and run

You may choose to build this project on your own. Clone this repository. You can run
`g++ -o main main.cpp matrix.cpp matrixstore.cpp tictactoe.cpp` in the root to build, and then run `./main` to execute the program.

# The Matrix Store

Running this program will kick off the CLI program I've designed to build and manipulate matricies, dubbed the Matrix Store. This is a mini-CLI database that can perform standard CRUD operations, mathematics, and even play tic-tac-toe in a specialized matrix data structure.

## Matrix Store Features

There are a number of operations you can run including:

### Create a Matrix

This will allow you to manually create a matrix with the chosen dimensions. Simply input the rows and columns, and then enter until the program stops you. Then name your matrix's label for easy retrieval later. It will be stored in the Matrix Store for further manipulation.

### See All Available

This will print out all stored Matrices available with their labels.

### Remove a Matrix

Enter the name of a matrix you want to remove. I made this slightly more manual to ensure that you're SURE you'd like to delete, so instead of inputting a number you must input the exact name.

### Update a Matrix

Choose a matrix, and then update specific coordinates with a new number

### Add Two Matricies: Matrix Addition

Choose 2 matrices of the same size to do matrix addition. The result will be stored in the Matrix Store with the label 'Sum of MatrixA and MatrixB'

### Subtract Two Matricies: Matrix Addition

Choose 2 matrices of the same size to do matrix subtraction. The result will be stored in the Matrix Store with the label 'Difference of MatrixA and MatrixB'

### Multiply Two Matricies

Choose 2 matricies with a common side to do matrix multiplication. The result will be stored in the Matrix Store with the label 'Product of MatrixA and MatrixB'

### Invert a Matrix

Since matrix division isn't a thing, matrix inversion multiplies the matrix by -1 and stores the result as 'Inverted MatrixName' in the Matrix Store.

### Sort: Row or Column Sorts

Choose a matrix, and then choose whether to sort it row-wise or column wise. It will sort low -> high and store in the Matrix Store as "Sorted by row/column MatrixName.

### Tic Tac Toe

This will kick off a game of tic tac toe versus the computer, using a specialized matrix with member variables to store game state. Play a classic game of tic tac toe against a computer till your heart is content. The game will keep score and the computer will try its hardest to defeat you! Good luck

### Create Demo Matrices

Should you want to quickly spin up some matricies for testing, use this to create 4 sample matricies that will be stored as 'Test Matrix #'

### Does this Matrix Contain?

This will prompt the user to select a matrix and input a value to see if it contains the value. The Matrix Store will relay if it DOES or DOES NOT contain the value

### Get Coordinates of a Value in a Matrix

Similar to the above function, this will prompt the user to select a matrix and input a value to return coordinates within that matrix. If it does, you'll get coordinates. If not, it will return a message.

### Transpose a Matrix (Swap rows and columns)

As described, this process will prompt a user to select a matrix and then it will create a new matrix swapping the rows and columns (called a transpose) in the Matrix Store called "Transpose of MatrixName".

### Video Walkthrough

- TO DO
