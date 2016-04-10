#include"CMatrix.h"
#include<cmath>

using namespace std;

//operator overloaders

CMatrix CMatrix::operator+(CMatrix& c) const throw (std::string)  {
        if ( ncol!=c.ncol || nrow!=c.nrow ) {
		throw std::string("ERROR in 'CMatrix +': unequal dimensions!\n");
        }
        int i,j;
        int length = ncol*nrow;
        double array[length];

        for (i=0;i<length;i++)
                array[i]=0;
        CMatrix temp(array,nrow,ncol);

        for (i=0;i<nrow;i++) {
                for (j=0;j<ncol;j++) {
                        temp.matrix[i][j] = matrix[i][j] + c.matrix[i][j];
                }
        }

        return temp;
}

CMatrix CMatrix::operator-(CMatrix& c) const throw (std::string) {
        if ( ncol!=c.ncol || nrow!=c.nrow ) {
		throw std::string("ERROR in 'CMatrix -': unequal dimensions!\n");
        }
        int i,j;
        int length = ncol*nrow;
        double array[length];

        for (i=0;i<length;i++)
                array[i]=0;
        CMatrix temp(array,nrow,ncol);

        for (i=0;i<nrow;i++) {
                for (j=0;j<ncol;j++) {
                        temp.matrix[i][j] = matrix[i][j] - c.matrix[i][j];
                }
        }

        return temp;
}

CMatrix CMatrix::operator*(CMatrix& c) const throw (std::string) {
        if ( ncol!=c.nrow ) {
		throw std::string("ERROR in 'CMatrix *': illegal matrix product!\n");
        }
        int i,j,k;
        int length = ncol*nrow;
        double array[length];

        for (i=0;i<length;i++)
                array[i]=0;
        CMatrix temp(array,nrow,c.ncol);

        for (i=0;i<nrow;i++) {
                for (j=0;j<c.ncol;j++) {
                        temp.matrix[i][j] = 0;
                        for (k=0;k<ncol;k++)
                                temp.matrix[i][j] =  temp.matrix[i][j] +   matrix[i][k] * c.matrix[k][j];
                }
        }
        return temp;
}

CMatrix CMatrix::operator*(double value) const {
        int i,j;
        int length = ncol*nrow;
        double array[length];

        for (i=0;i<length;i++)
                array[i]=0;
        CMatrix temp(array,nrow,ncol);

        for (i=0;i<nrow;i++) {
                for (j=0;j<ncol;j++) {
                                temp.matrix[i][j] = matrix[i][j] * value;
                }
        }
        return temp;
}


std::ostream& operator<<(std::ostream& os, CMatrix& c) {
        int nrw = c.nrow;
        int ncl = c.ncol;
        int i,j;
        for (i=0;i<nrw;i++) {
                for (j=0;j<ncl;j++) {
                        cout.width(12);
                        cout.precision(4);
                        cout.setf(ios::left);
                        os<< std::scientific << c.matrix[i][j];
                }
                os<<endl;
        }
        return os;
}





