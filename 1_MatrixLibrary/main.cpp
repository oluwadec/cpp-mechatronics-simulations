#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = std::vector<std::vector<double>>(r, std::vector<double>(c, 0.0));
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    void set(int r, int c, double value) {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("That position doesn't exist in this matrix.");
        data[r][c] = value;
    }

    double get(int r, int c) const {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            throw std::out_of_range("That position doesn't exist in this matrix.");
        return data[r][c];
    }

    void print(const std::string& label = "Matrix") const {
        std::cout << "\n" << label << " (" << rows << "x" << cols << ")\n";
        for (int i = 0; i < rows; i++) {
            std::cout << "[ ";
            for (int j = 0; j < cols; j++)
                std::cout << std::setw(7) << std::fixed << std::setprecision(2) << data[i][j] << " ";
            std::cout << "]\n";
        }
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw std::invalid_argument("Can't add matrices of different sizes.");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw std::invalid_argument("Columns of the first matrix must match rows of the second.");

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                double sum = 0.0;
                for (int k = 0; k < cols; k++)
                    sum += data[i][k] * other.data[k][j];
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[j][i] = data[i][j];
        return result;
    }
};

int main() {
    try {
        std::cout << "Matrix Math Library\n";

        // a couple of coordinates / state values as a 2x3 matrix
        Matrix A(2, 3);
        A.set(0, 0, 1); A.set(0, 1, 2); A.set(0, 2, 3);
        A.set(1, 0, 4); A.set(1, 1, 5); A.set(1, 2, 6);
        A.print("A");

        A.transpose().print("A transposed");

        // a 3x2 transform matrix to multiply A by
        Matrix B(3, 2);
        B.set(0, 0, 7); B.set(0, 1, 8);
        B.set(1, 0, 9); B.set(1, 1, 1);
        B.set(2, 0, 2); B.set(2, 1, 3);
        B.print("B");

        (A * B).print("A * B");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}