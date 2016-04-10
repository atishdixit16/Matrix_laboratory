#include<iostream>

class CMatrix {
	private:
		double** matrix;
		int ncol, nrow;
	public:
		CMatrix();
		CMatrix(int diagSize);
		CMatrix(double* array, int nrw, int ncl);
		CMatrix(double** array, int nrw, int ncl);
		CMatrix(const CMatrix& m );
		void set_ncol( int ncl);
		void set_nrow(int nrw);
		int get_ncol();
		int get_nrow();
		void setValue(double value, int nrw, int ncl);
		double getValue(int nrw, int ncl);
		
		CMatrix transpose();
		CMatrix minor(int row, int col);
		double determinant() throw (std::string);
		CMatrix cbind(CMatrix& b)throw (std::string);
		CMatrix rbind(CMatrix& b)throw (std::string);
		CMatrix upperTriangle();
		CMatrix inverse()throw (std::string);
		CMatrix* luDecomposition()throw (std::string);

                //CMatrix& operator=(const CMatrix c); 
		CMatrix operator+(CMatrix& c) const throw (std::string);
                CMatrix operator-(CMatrix& c) const throw (std::string);
                CMatrix operator*(CMatrix& c) const throw (std::string);
                CMatrix operator*(double value) const;
		friend std::ostream& operator<<(std::ostream& os, CMatrix& c);
};

