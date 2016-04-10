#include"CMatrix.h"
#include<cmath>

using namespace std;

CMatrix CMatrix::transpose() {
        int i,j;
        int length = ncol*nrow;
        double array[length];

        for (i=0;i<length;i++)
                array[i]=0;
        CMatrix temp(array,ncol,nrow);

        for (i=0;i<nrow;i++) {
                for (j=0;j<ncol;j++) {
                        temp.matrix[j][i] = matrix[i][j];
                }
        }
        return temp;
}

CMatrix CMatrix::minor(int row, int col) {
        int i,j;
        double** minor;
        minor = new double*[nrow-1];
        for(i = 0; i < (nrow-1); i++)
                minor[i] = new double[ncol-1];
        int minor_row = 0;
        for (i=0;i<nrow;i++) {
                int minor_col = 0;
                for (j=0;j<ncol;j++) {
                        if ( (i != row-1) && (j != col-1) ) {
                                minor[minor_row][minor_col] = matrix[i][j];
                                minor_col++;
                        }
                }
                if ( i != row-1)
                        minor_row++;
        }
        CMatrix obj(minor, nrow-1, ncol-1);
        return obj;
}

double CMatrix::determinant() throw (std::string){
	if (nrow != ncol) {
		throw std::string("ERROR in 'determinant': not can a square matrix!\n");
	}
	if (nrow==2) 
		return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0] );	
	int i;
	double sum = 0;
	for (i=0;i<nrow;i++) {
		CMatrix obj = this->CMatrix::minor(1,(i+1));
		sum = sum + (this->matrix[0][i])*pow(-1,(1+i+1))*obj.CMatrix::determinant();
	}
	return sum;
}

CMatrix CMatrix::cbind( CMatrix& b) throw (std::string){
	if (nrow != b.nrow) {
		throw std::string("ERROR in 'cbind': unequal number of rows!\n");
	}
	int i,j;
        int length = (ncol+b.ncol)*nrow;
        double array[length];
        for (i=0;i<length;i++)
                array[i]=0;
        CMatrix temp(array,nrow,(ncol+b.ncol));
	for (i=0;i<temp.nrow;i++) 
                for (j=0;j<temp.ncol;j++)
			if (j < ncol )
                        	temp.matrix[i][j] = matrix[i][j];
			else
				temp.matrix[i][j] = b.matrix[i][j-ncol];
        return temp;
}


CMatrix CMatrix::rbind( CMatrix& b) throw (std::string){
	if (ncol != b.ncol) {
		throw std::string("ERROR in 'rbind': unequal number of columns!\n");
	}
	int i,j;
        int length = ncol*(nrow+b.nrow);
        double array[length];
        for (i=0;i<length;i++)
                array[i]=0;
        CMatrix temp(array,(nrow+b.nrow),ncol);
	for (i=0;i<temp.nrow;i++) 
                for (j=0;j<temp.ncol;j++)
			if ( i < nrow )
                        	temp.matrix[i][j] = matrix[i][j];
			else
				temp.matrix[i][j] = b.matrix[i-nrow][j];
        return temp;
}

CMatrix CMatrix::upperTriangle() {
	int i,j,k;
	double c;
	CMatrix temp(*this);

	for (i=0;i<(ncol);i++) {
		for (j=i+1;j<nrow;j++) {
			c = temp.matrix[j][i] / temp.matrix[i][i];
			for (k=0;k<ncol;k++) {
				temp.matrix[j][k]=temp.matrix[j][k] - c*temp.matrix[i][k];
			}
		}
	}
	return temp;
}

CMatrix CMatrix::inverse() throw (std::string){
	if (ncol != nrow) {
		throw std::string("ERROR in  'inverse': not can a square matrix!\n");
	}
	CMatrix temp(*this);
	CMatrix temp1(temp.ncol);
	CMatrix aug = temp.CMatrix::cbind(temp1);
	CMatrix uAug = aug.upperTriangle();

	int i,j,k;
	double c;	

	for (i=0;i<uAug.nrow;i++) {
		c = uAug.matrix[i][i] ;
		for (j=0;j<uAug.ncol;j++) {
			uAug.matrix[i][j] = uAug.matrix[i][j] /c;
		}
	}
	
	for (i=(ncol-1);i>=0;i--) {
		for (j=i-1;j>=0;j--) {
			c = uAug.matrix[j][i] / uAug.matrix[i][i];
			for (k=0;k<uAug.ncol;k++) {
				uAug.matrix[j][k]=uAug.matrix[j][k] - c*uAug.matrix[i][k];
			}
		}
	}

	for (i=0;i<nrow;i++)
		for (j=0;j<ncol;j++)
			temp.matrix[i][j] = uAug.matrix[i][j+3];

	return temp;
}

CMatrix* CMatrix::luDecomposition() throw (std::string){
	if (ncol != nrow) {
		throw std::string("ERROR in  'luDecomposition': not can a square matrix!\n");
	}
	CMatrix l(nrow);
	CMatrix u(nrow);

	int i,j,k;

	for (i=0;i<nrow;i++) {
		l.matrix[i][i] = 1;
		u.matrix[0][i] = matrix[0][i];
		l.matrix[i][0] = matrix[i][0] / u.matrix[0][0];
	}
	
	for (i=1;i<nrow;i++) {
		for (j=1;j<ncol;j++) {
			if (i <= j) {
				double sum = 0;
				for (k=0;k<(i);k++)
					sum = sum + l.matrix[i][k]*u.matrix[k][j];
				u.matrix[i][j] = matrix[i][j]  - sum;
			}
			else {
				double sum = 0;
                                for (k=0;k<(j);k++)
                                        sum = sum + l.matrix[i][k]*u.matrix[k][j];
				l.matrix[i][j] = (  matrix[i][j] - sum ) / u.matrix[j][j];
			}
		}
	}
	CMatrix* op = new CMatrix;
	op[0] = l;
	op[1] = u;
	return op;
}


