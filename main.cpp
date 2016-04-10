#include<iostream>
#include"CMatrix.h"

using namespace std;

int main() {
	double array[16] = {1, 1, 1, 1, 2, 4, 8, 16, 3, 9, 27, 81, 4, 16, 64, 256 };
	double array1[9] = {1, 1, 1, 1, 2, 4, 8, 16, 3 };
	CMatrix objA(array,4,4);
	//CMatrix objB(objA);
	CMatrix objB(array1,3,3);   //use this objB to for exception handling!
	double scalar = 5.0;

	try {
	//matrix A and B
	cout << "Matrix A: " << endl;
	cout << objA << endl;
	cout << "Matrix B: " << endl;
	cout << objB << endl;
	//matrix addition
	cout << "Addition of A and B" << endl;
	CMatrix add = objA + objB;
	cout << add << endl;
	
	//matrix subtraction
	cout << "Subtraction of A and B" << endl;
	CMatrix sub = objA - objB;
	cout << sub << endl;

	//matrix multiplication
	cout << "Multiplication of A and B" << endl;
	CMatrix prod = objA * objB;
	cout << prod << endl;
	
	//matrix multiplication
	cout << "Multiplication of A and scalar" << endl;
	CMatrix prodS = objA * scalar;
	cout << prodS << endl;

	//transpose
	cout << "Transpose of A" << endl;
	CMatrix trans = objA.transpose();
	cout << trans << endl;

	//determenant
	cout << "Determinant of A" << endl;
	CMatrix det = objA.determinant();
	cout << trans << endl;

	//LUdecomposition
	cout << "LU-decomposition of A" << endl;
	CMatrix *obj1 = new CMatrix;
	obj1 = objA.luDecomposition();
	cout <<"\t" << "Lower matrix" << endl;
	cout <<obj1[0]<<endl;
	cout <<"\t" <<"Upper matrix" << endl;
	cout<<obj1[1]<<endl;

	//Inverse
	cout << "Inverse of A" << endl;
	CMatrix inv = objA.inverse();
	cout << inv << endl;
	}
	catch(std::string str) {
		cerr<<endl<<str<<endl;
	}
	
	return 0;
}
