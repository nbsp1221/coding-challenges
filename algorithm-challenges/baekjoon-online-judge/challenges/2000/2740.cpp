#include <iostream>
#include <vector>

using namespace std;
using Matrix = vector<vector<int>>;

void inputMatrix(Matrix& matrix)
{
    for (size_t y = 0; y < matrix.size(); y++) {
        for (size_t x = 0; x < matrix[0].size(); x++) {
            cin >> matrix[y][x];
        }
    }
}

void printMatrix(const Matrix& matrix)
{
    for (size_t y = 0; y < matrix.size(); y++) {
        for (size_t x = 0; x < matrix[0].size(); x++) {
            cout << matrix[y][x] << " ";
        }

        cout << "\n";
    }
}

Matrix multiplyMatrix(const Matrix& first, const Matrix& second)
{
    Matrix matrix(first.size(), vector<int>(second[0].size(), 0));

    for (size_t i = 0; i < first.size(); i++) {
        for (size_t j = 0; j < first[0].size(); j++) {
            for (size_t k = 0; k < second[0].size(); k++) {
                matrix[i][k] += first[i][j] * second[j][k];
            }
        }
    }

    return matrix;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Matrix matrixA, matrixB;
    int rowA, columnA, rowB, columnB;

    cin >> rowA >> columnA;
    matrixA.assign(rowA, vector<int>(columnA));
    inputMatrix(matrixA);

    cin >> rowB >> columnB;
    matrixB.assign(rowB, vector<int>(columnB));
    inputMatrix(matrixB);

    Matrix matrixResult;
    matrixResult = multiplyMatrix(matrixA, matrixB);
    printMatrix(matrixResult);

    return 0;
}