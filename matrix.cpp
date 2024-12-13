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

#include "matrix.h"
#include <iostream>

// Constructor with dimensions
Matrix::Matrix(int width, int height): width(width), height(height), data(height, std::vector<int>(width, 0)) {}

// Default constructor
Matrix::Matrix() : width(0), height(0), data(std::vector<std::vector<int> >()) {}

// Destructor
Matrix::~Matrix() {}

// Gets the value at (index_x, index_y)
int Matrix::value_at(int index_x, int index_y) {
    // to do
    return 1;
}

// Sets the value at (index_x, index_y), will be programmatically set via a loop
bool Matrix::set_value(int index_x, int index_y, int value) {
    if (index_x >= 0 && index_x < width && index_y >= 0 && index_y < height) {
        data[index_y][index_x] = value;
        return true;
    }
    return false;
}
int Matrix::get_value(int index_x, int index_y) {
// return the value
    return data[index_y][index_x];
}

// Searches for a value in the matrix
bool Matrix::search(int value) {

for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
        if(data[i][j] == value){
            return true;
        }
    }
}
  return false;
}

// Get coordinates
std::pair<int, int> Matrix::get_coordinates(int value) {
    // iterate over matrix
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            // if a match, return the coordinates
            if (data[i][j] == value) {
                return std::make_pair(i, j);
            }
        }
    }
    // else return sentinel values that prompt a bad coordinates, shouldn't happen.
    return std::make_pair(-1, -1);
}

// Prints the matrix
void Matrix::print_matrix() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) { 
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl; // adds a new line after the rows to better resemble a matrix
    }
}
// access private attributes
  int Matrix::get_width(){
      return this->width;
  }
  int Matrix::get_height(){
      return this->height;
  }