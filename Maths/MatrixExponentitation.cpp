//Matrix Exponentiation is a technique used to calculate a matrix raised to a power efficiently, that is in logN time.
// It is mostly used for solving problems related to linear recurrences.
#include <bits/stdc++.h>
using namespace std;


const int MOD = 1e9 + 7;
typedef vector<vector<long long>> Matrix;

// Function to multiply two matrices
Matrix matrixMultiplication(Matrix &A, Matrix &B) {
    Matrix result(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                result[i][j] = (result[i][j] + A[i][k] * B[k][j]) % MOD;
    return result;
}

// Function to raise matrix base to the power exponent (Just like Binary exponentiation)
Matrix matrixExponentiation(Matrix& base, int exponent) {
    if (exponent == 0) {
        Matrix identity(2, vector<long long>(2, 0));
        for (int i = 0; i < 2; ++i) //making an Identity matrix
            identity[i][i] = 1;
        return identity;
    }

    Matrix half   = matrixExponentiation(base, exponent / 2);
    Matrix result = matrixMultiplication(half, half);

    if (exponent % 2 == 1)
        result = matrixMultiplication(result, base);

    return result;
}


int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n == 0) {
        cout << "Fibonacci(" << n << ") = 0" << endl;
        return 0;
    }

    Matrix T = {{1, 1}, {1, 0}};
    Matrix mat = {{1}, {0}}; // Base case matrix: F(1) = 1, F(0) = 0

    Matrix Tn = matrixExponentiation(T, n - 1);
    Matrix result = matrixMultiplication(Tn, mat);

    cout << "Fibonacci(" << n << ") = " << result[0][0] << endl;
    return 0;
}