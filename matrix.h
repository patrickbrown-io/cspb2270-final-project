#ifndef MATRIX_H__
#define MATRIX_H__

#include <vector>

class Matrix {
public:
  // Constructor: Initialize a matrix with the given width and height, filled with zeros
  Matrix(int width, int height);

  // Default constructor: Initialize an empty matrix
  Matrix();

  // Destructor
  ~Matrix();

  // Get the value at the given (x, y) index
  int value_at(int index_x, int index_y);

  // Set a value at the given (x, y) index
  bool set_value(int index_x, int index_y, int value);

  // Needs a getter for values
  int get_value(int index_x, int index_y);

  // Search for a value in the matrix
  bool search(int value);

  // Remove the value at the given (x, y) indexes by setting it to zero
  bool remove(int index_x, int index_y);

  // Replace the value at the given (x, y) indexes
  bool replace(int index_x, int index_y, int new_value);

  // Print the matrix for debugging
  void print_matrix();

  int get_width();
  int get_height();

private:
  int width;
  int height;
  std::vector<std::vector<int> > data;
};

#endif
