#ifndef MATRIXSTORE_H__
#define MATRIXSTORE_H__

#include <string>
#include <vector>
#include "matrix.h"


/*
    We will use this structure to store Matrixes in a pseduo-database, as well as provide operations to run on them.
    Each matrix node will contain the matrix as well as a user-defined label to make retrieval easier, instead of trying to remember what matrix is where
*/
class MatrixStore {
public:
    // Constructor
    MatrixStore();

    // Destructor
    ~MatrixStore();

    // Menu System
    void prompt_user();

    // Add a matrix to the store with a user-provided label (name, should make it easier for retrieval)
    void add_matrix(const std::string& name, Matrix& matrix);

    // Get a matrix by its name
    Matrix* get_matrix(std::string& name);

    // Remove a matrix by its name
    bool remove_matrix(std::string& name);

    // Print all matrices and their names
    void print_store();

    // Math functions
    Matrix add_matrices(Matrix &matrixA, Matrix &matrixB);
    Matrix subtract_matrices(Matrix &matrixA, Matrix &matrixB);
    Matrix multiply_matrices(Matrix &matrixA, Matrix &matrixB);
    Matrix invert_matrix(Matrix &matrix);
    Matrix sort_matrix(Matrix &matrix, int sort);
    Matrix transpose_matrix(Matrix &matrix);
    void bubblesort(std::vector<int> &data);

private:
    // Struct for storing matrix nodes within the store, but with a user-created label
    // Could add addtl attributes here. Could also add operations? We'll see.
    struct MatrixNode {
        std::string name;
        Matrix matrix;
    };

    std::vector<MatrixNode> store; // Vector of matrix nodes
};

#endif
