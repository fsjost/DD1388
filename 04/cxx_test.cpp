#include <cxxtest/TestSuite.h>
#include "matrix.cpp"


class MyTestSuite : public CxxTest::TestSuite {
public:

	void test_constructors() {
		Matrix<int> mat1 = Matrix<int>();
		Matrix<int> mat2 = Matrix<int>(1);
		Matrix<int> mat3 = Matrix<int>(2, 3);
		Matrix<int> mat4 = { 1, 2, 3, 4 };

		Matrix<char> matA = Matrix<char>();
		Matrix<char> matB = Matrix<char>(1);
		Matrix<char> matC = Matrix<char>(2, 3);
		Matrix<char> matD = { 'a', 'b', 'c', 'd' };

		TS_ASSERT_EQUALS(mat1, mat2);

		TS_ASSERT_EQUALS(matA, matB);

		//~mat1;
	}

	void test_addition() {
		Matrix<int> mat1 = Matrix<int>(2, 3);
		Matrix<int> mat2 = { 1, 2, 3, 4 };
		Matrix<int> mat3 = mat2;
		Matrix<int> mat4 = { 2, 4, 6, 8 };

		TS_ASSERT_THROWS(mat1 + mat2, std::out_of_range);
		TS_ASSERT_EQUALS(mat2 + mat3, mat4);

		mat2 += mat3;

		TS_ASSERT_EQUALS(mat2, mat4);
	}

	void test_subtraction() {
		Matrix<int> mat1 = Matrix<int>(2, 3);
		Matrix<int> mat2 = { 1, 2, 3, 4 };
		Matrix<int> mat3 = { 1, 2, 3, 4 };
		Matrix<int> mat4 = Matrix<int>(2, 2);

		TS_ASSERT_THROWS(mat1 - mat2, std::out_of_range);
		TS_ASSERT_EQUALS(mat2 - mat3, mat4);

		mat4 += mat3;

		TS_ASSERT_EQUALS(mat4, mat3);
	}

	void test_multiplication() {
		Matrix<int> mat1 = Matrix<int>(2, 3);
		Matrix<int> mat2 = { 1, 2, 3, 4 };
		Matrix<int> mat3 = { 2, 0, 1, 2 };
		Matrix<int> mat4 = { 4, 4, 10, 8 };

		TS_ASSERT_THROWS(mat1 * mat2, std::out_of_range);
		TS_ASSERT_EQUALS(mat2 * mat3, mat4);
	}

	void test_excel_functions() {
		Matrix<int> mat1 = { 1, 1, 1, 1 };
		mat1.insert_row(0);
		mat1.insert_column(0);
		Matrix<int> mat2 = { 0, 0, 0, 1, 1, 0, 1, 1, 0 };

		TS_ASSERT_EQUALS(mat1, mat2);

		mat1.append_row(1);
		mat1.append_column(1);
		Matrix<int> mat3 = { 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0 };

		TS_ASSERT_EQUALS(mat1, mat3);

		mat1.remove_row(3);
		mat1.remove_column(3);
		Matrix<int> mat4 = { 0, 0, 0, 1, 1, 0, 0, 0, 0};

		TS_ASSERT_EQUALS(mat1, mat4);
	}

	void test_reset() {
		Matrix<int> mat1 = { 1, 1, 1, 1 };
		Matrix<int> mat2 = Matrix<int>(2);
		mat1.reset();

		TS_ASSERT_EQUALS(mat1, mat2);
	}

	void test_identity() {
		Matrix<int> mat1 = identity(4);
		Matrix<int> mat2 = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };

		TS_ASSERT_EQUALS(mat1, mat2);
	}

	void test_random_functions() {
		Matrix<int> mat1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		Matrix<char> matA = { 'a', 'b', 'c', 'd' };

		TS_ASSERT_EQUALS(*mat1.begin(), 1);
		TS_ASSERT_EQUALS(*mat1.end(), 9);
		TS_ASSERT_EQUALS(*matA.begin(), 'a');
		TS_ASSERT_EQUALS(*matA.end(), 'd');

		TS_ASSERT_EQUALS(mat1.get_m_rows(), 3);
		TS_ASSERT_EQUALS(mat1.get_m_cols(), 3);
		TS_ASSERT_EQUALS(matA.get_m_rows(), 2);
		TS_ASSERT_EQUALS(matA.get_m_cols(), 2);
	}

	void test_output() {
		Matrix<int> mat1 = { 1, 2, 3, 4 };
		Matrix<int> mat2 = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	}


};
