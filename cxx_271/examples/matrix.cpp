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
	~Column();
	int & operator[] (int index);
	int size();
	void  resize(int newSize);

};
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
public:
	Matrix (int rows=0, int cols=0);
	~Matrix();
	Column &  operator[](int rowNum);

	Matrix  operator+ (Matrix & m);
	int size();
};

Matrix Matrix::operator+ (Matrix & m)
{
	Matrix retval;
	return retval;
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

int main()
{
	Column c(4);
	for (int i=0; i < c.size(); i++)
		c[i] = i;

	Matrix m(3,4);
	for (int i=0; i < m.size(); i++)
	{
		for (int j=0; j < m[0].size(); j++)
			m[i][j] = i+j;
	}

	for (int i=0; i < m.size(); i++)
	{
		for (int j=0; j < m[0].size(); j++)
		{
			int value = m[i][j];
			cout << value << " ";
		}

		cout << endl;
	}

    return 0;
}
