#include"CMatrix.h"
#include<cmath>

using namespace std;

CMatrix::CMatrix() {
	nrow=1;
	ncol=1;
	matrix = new double*[nrow];
	matrix[0] = new double[ncol];
	matrix[0][0] = 0;
}

CMatrix::CMatrix(int diagSize) {	
	nrow = diagSize;
	ncol = diagSize;
	matrix = new double*[nrow];
	int i,j;
	for(i = 0; i < nrow; ++i)
    		matrix[i] = new double[ncol];
	for (i=0;i<nrow;i++) 
                for (j=0;j<ncol;j++)
			if (i==j)
                		matrix[i][j] = 1;
			else
				matrix[i][j] = 0;
}

CMatrix::CMatrix(double* array, int nrw, int ncl) {
	nrow = nrw;
	ncol = ncl;
	matrix = new double*[nrow];
	int length = ncol*nrow;
	int r=1,c,i;
	for(int i = 0; i < nrow; ++i)
    		matrix[i] = new double[ncol];
	for (i=0;i<length;i++) {
		c = (i+1) % ncl;
		if (c==0)
			c=ncl;
		matrix[r-1][c-1] = array[i];
		if (c==ncl)
			r++;
	}
}


CMatrix::CMatrix(double** array, int nrw, int ncl) {
	nrow = nrw;
	ncol = ncl;
	matrix = new double*[nrow];
	int i,j;
	for(i = 0; i < nrow; ++i)
    		matrix[i] = new double[ncol];
	for (i=0;i<nrow;i++) {
                for (j=0;j<ncol;j++) {
                	matrix[i][j] = array[i][j];
                }
        }
}

CMatrix::CMatrix(const CMatrix& m ) {
	nrow = m.nrow;
	ncol = m.ncol;
	matrix = new double*[nrow];
	int i,j;
	for(i = 0; i < nrow; ++i)
    		matrix[i] = new double[ncol];
	for (i=0;i<nrow;i++) {
                for (j=0;j<ncol;j++) {
                	matrix[i][j] = m.matrix[i][j];
                }
        }
}

void CMatrix::set_ncol(int ncl) {
	ncol = ncl;
}

void CMatrix::set_nrow(int nrw) {
	nrow=nrw;
}

int CMatrix::get_ncol() {
	return ncol;
}

int CMatrix::get_nrow() {
	return nrow;
}

void CMatrix::setValue(double value, int nrw, int ncl) {
	matrix[nrw-1][ncl-1] = value;
}

double CMatrix::getValue(int nrw, int ncl) {
	return matrix[nrw-1][ncl-1];
}

//CMatrix::CMatrix(&CMatrix m ) {
	//algo


