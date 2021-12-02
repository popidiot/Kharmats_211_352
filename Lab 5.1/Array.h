#pragma once
class Array {
private:
	int col, rows;

public:
	double* matr = new double;
	void input() {
		std::cout << "Input size of matrix: ";
		std::cin >> col >> rows;
		matr = new double[(col) * (rows)];
		std::cout << "Input elements:" << std::endl;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < col; j++) {
				std::cout << "Input " << "[" << i << "][" << j << "]: ";
				std::cin >> matr[i * col + j];
			}
		}
		std::cout << std::endl;
	}

	void print() {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < col; j++) {
				std::cout << matr[i * (col)+j] << "\t";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}

	int get_columns() {
		return col;
	}

	int get_rows() {
		return rows;
	}

	int get_size() {
		return col * rows;
	}

	double get_elem(int i, int j) {
		return matr[i * col + j];
	}

	int matrixsum(double* matr1, double* matr2, int col1, int rows2) {
		if (col1 != rows2) return 0;
		matr = new double[col1 * rows2];
		col = col1; rows = rows2;
		for (int i = 0; i < col1 * rows2; i++) {
			matr[i] = matr1[i] + matr2[i];
		}
		return 1;
	}

	int matrixmult(double* matr1, int col1, int rows1, double* matr2, int col2, int rows2) {
		if (col1 == rows2) {
			col = col1; rows = rows2;
			matr = new double[rows * col];
			for (int i = 0; i < rows1; i++)
				for (int j = 0; j < col2; j++)
				{
					matr[i * col2 + j] = 0;
					for (int k = 0; k < col1; k++)
						matr[i * col2 + j] += matr1[i * col1 + k] + matr2[k * col2 + j];
				}
			return 0;
		}
		else {
			std::cout << "Error of mult: sizes are not equal.";
			col = rows = 0;
			return 1;
		}
	}

	void mult_by_num(double num) {
		for (int i = 0; i < rows * col; i++) {
			matr[i] *= num;
		}
		std::cout << "Multiplied successful with " << num << ".\n\n";
	}

	double trace(double* matr, int size) {
		double sum = 0;
		for (int i = 0; i < size; i++) {
			sum += matr[i * size + i];
		}
		return sum;
	}
};