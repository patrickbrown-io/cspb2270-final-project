/*
    Matrix Data Structure is a two-dimensional array arranged in rows and columns. 
    It is commonly used to represent mathematical matrices and is fundamental in various fields like mathematics, computer graphics, and data processing. 
    Matrices allow for efficient storage and manipulation of data in a structured format.
    Source: Geeks for Geeks (https://www.geeksforgeeks.org/matrix/)
 */

//
//  Author: Patrick Brown
//  CU ID: pabr5825
//  GitHub Username: patrickbrown-io

#include "Matrix.h"
#include <iostream>

// Constructor with dimensions
Matrix::Matrix(int width, int height): width(width), height(height), data(height, std::vector<int>(width, 0)) {}

// Default constructor
Matrix::Matrix() : width(0), height(0), data(std::vector<std::vector<int>>()) {}

// Destructor
Matrix::~Matrix() {}

// Gets the value at (index_x, index_y)
int Matrix::value_at(int index_x, int index_y) {
    return 1;
}

// Sets the value at (index_x, index_y)
bool Matrix::set_value(int index_x, int index_y, int value) {
  return true;
}

// Searches for a value in the matrix
bool Matrix::search(int value) {
  return false;
}

// Remove value at (index_x, index_y)
bool Matrix::remove(int index_x, int index_y) {
  return true;
}

// Replaces value at the (index_x, index_y)
bool replace(int index_x, int index_y, int new_value) { return true; }

// Prints the matrix
void Matrix::print_matrix() {}

// TO DO: 
// add, subtract, multiply, divide
// add data to a new matrix
// sorts
// combine arrays