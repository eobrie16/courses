#include <iostream>
using namespace std;
#include <string>

class Column
{
private:
	int * m_cols;
	int num_cols;
public:
	Column(int cols);
	Column (const Column & c); // Copy Constructor
	~Column();
	int & operator[] (int index);
	int size();
	void  resize(int newSize);

};
Column::Column (const Column & c) // Copy Constructor
{
	num_cols= c.num_cols;
	m_cols = new int[num_cols];
	for (int i=0; i < num_cols; i++)
		m_cols[i] = c.m_cols[i];
}
void Column::resize(int newSize)
{
	int * temp = new int[newSize];
	int copySize = num_cols;
	if (newSize < copySize) copySize = newSize;
	for (int i=0; i < copySize; i++)
		temp[i] = m_cols[i];
	delete [] m_cols;
	m_cols = temp;
	num_cols = newSize;
}

Column::Column(int cols)
{
	m_cols = new int[cols];
	num_cols = cols;
}
Column::~Column()
{
	delete[] m_cols;
}
int Column::size()
{
	return num_cols;
}
int & Column::operator[](int index)
{
	if (index < 0 || index >= num_cols)
		throw string("Column: index out of bounds");
	return m_cols[index];
}

class Matrix
{
private:
	//Column * m_rows[];
	Column ** m_rows;
	int num_rows;
	void cloneMe(const Matrix & m);
public:
	Matrix (int rows=0, int cols=0);
	Matrix (const Matrix & m); // Copy Constructor
	~Matrix();
	Column &  operator[](int rowNum);

	Matrix  operator+ (Matrix & m);
	Matrix &operator=(Matrix & m);
	int size();
};
Matrix &Matrix::operator=(Matrix & m)
{
	cloneMe( m);
	return *this;
}
Matrix::Matrix (const Matrix & m) // Copy Constructor
{
	cloneMe( m);
}
void Matrix::cloneMe (const Matrix & m)
{
	num_rows = m.num_rows;
	m_rows = new Column * [num_rows];
	for (int i=0; i < num_rows; i++)
		m_rows[i] = new Column(*m.m_rows[i]);
}

Matrix Matrix::operator+ (Matrix & m)
{
	int r = size(); //Number of rows
	int c= (*m_rows[0]).size(); // Number of cols
	if (r != m.size()) 
		throw "Matrix Add Error: Num Rows mismatched";
	if (c != (*m.m_rows[0]).size())
		throw "Matrix Add Error: Num Cols mismatched";

	Matrix mRet(r,c);
	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
			mRet[i][j] =  m[i][j] +(*m_rows[i])[j] ;
	}
	return mRet;
}

Column & Matrix::operator[](int rowNum)
{
	if(rowNum < 0 || rowNum >= num_rows)
		throw string("Matrix: row index out bounds");
	return *m_rows[rowNum];
}
int Matrix::size()
{
	return num_rows;
}
Matrix::Matrix(int r, int c)
{
	num_rows = r;
	m_rows = new Column * [r];
	for (int i=0; i < r; i++)
		m_rows[i] = new Column(c);
}
Matrix::~Matrix()
{
	for (int i=0; i < num_rows; i++)
		delete m_rows[i];
	delete[] m_rows;
}

void print (Matrix & m)
{
	for (int i=0; i < m.size(); i++)
	{
		for (int j=0; j < m[0].size(); j++)
		{			
			cout << m[i][j] << " ";
		}

		cout << endl;
	}
}
int main()
{
	Column c(4);
	for (int i=0; i < c.size(); i++)
		c[i] = i;

	Matrix m(3,4), m2(3,4), m3(3,4);
	for (int i=0; i < m.size(); i++)
	{
		for (int j=0; j < m[0].size(); j++)
		{
			m[i][j] = i+j;
			m2[i][j] = 2*(i+j);
		}
	}

	m3 = m + m2;

	cout <<"m " << endl;
	print(m);
	cout <<endl << "m2"<<endl;
	print(m2);
	cout <<endl << "m3"<<endl;
	print(m3);
    return 0;
}
