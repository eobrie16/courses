#include <iostream>
using namespace std;
#include <string>

template <typename T>
class Column
{
private:
	T * m_cols;
	int num_cols;
public:
	Column(int cols);
	Column (const Column & c); // Copy Constructor
	~Column();
	T & operator[] (int index);
	int size();
	void  resize(int newSize);

};
template <typename T>
Column<T>::Column (const Column<T> & c) // Copy Constructor
{
	num_cols= c.num_cols;
	m_cols = new T[num_cols];
	for (int i=0; i < num_cols; i++)
		m_cols[i] = c.m_cols[i];
}
template <typename T>
void Column<T>::resize(int newSize)
{
	T * temp = new T[newSize];
	int copySize = num_cols;
	if (newSize < copySize) copySize = newSize;
	for (int i=0; i < copySize; i++)
		temp[i] = m_cols[i];
	delete [] m_cols;
	m_cols = temp;
	num_cols = newSize;
}
template <typename T>
Column<T>::Column(int cols)
{
	m_cols = new T[cols];
	num_cols = cols;
}
template <typename T>
Column<T>::~Column()
{
	delete[] m_cols;
}
template <typename T>
int Column<T>::size()
{
	return num_cols;
}
template <typename T>
T & Column<T>::operator[](int index)
{
	if (index < 0 || index >= num_cols)
		throw string("Column: index out of bounds");
	return m_cols[index];
}

template <typename T>
class Matrix
{
private:
	//Column * m_rows[];
	Column<T> ** m_rows;
	int num_rows;
	void cloneMe(const Matrix & m);
public:
	Matrix (int rows=0, int cols=0);
	Matrix (const Matrix & m); // Copy Constructor
	~Matrix();
	Column<T> &  operator[](int rowNum);

	Matrix  operator+ (Matrix & m);
	Matrix &operator=(Matrix & m);
	int size();
};
template <typename T>
Matrix<T> &Matrix<T>::operator=(Matrix & m)
{
	cloneMe( m);
	return *this;
}
template <typename T>
Matrix<T>::Matrix (const Matrix & m) // Copy Constructor
{
	cloneMe( m);
}
template <typename T>
void Matrix<T>::cloneMe (const Matrix & m)
{
	num_rows = m.num_rows;
	m_rows = new Column<T> * [num_rows];
	for (int i=0; i < num_rows; i++)
		m_rows[i] = new Column<T>(*m.m_rows[i]);
}
template <typename T>
Matrix<T> Matrix<T>::operator+ (Matrix<T> & m)
{
	int r = size(); //Number of rows
	int c= (*m_rows[0]).size(); // Number of cols
	if (r != m.size()) 
		throw "Matrix Add Error: Num Rows mismatched";
	if (c != (*m.m_rows[0]).size())
		throw "Matrix Add Error: Num Cols mismatched";

	Matrix<T> mRet(r,c);
	for (int i=0; i < r; i++)
	{
		for (int j=0; j < c; j++)
			mRet[i][j] =   (*m_rows[i])[j] + m[i][j];
	}
	return mRet;
}
template <typename T>
Column<T> & Matrix<T>::operator[](int rowNum)
{
	if(rowNum < 0 || rowNum >= num_rows)
		throw string("Matrix: row index out bounds");
	return *m_rows[rowNum];
}
template <typename T>
int Matrix<T>::size()
{
	return num_rows;
}
template <typename T>
Matrix<T>::Matrix(int r, int c)
{
	num_rows = r;
	m_rows = new Column<T> * [r];
	for (int i=0; i < r; i++)
		m_rows[i] = new Column<T>(c);
}
template <typename T>
Matrix<T>::~Matrix()
{
	for (int i=0; i < num_rows; i++)
		delete m_rows[i];
	delete[] m_rows;
}

template <typename T>
void print (Matrix<T> & m)
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
	Column<int> c(4);
	for (int i=0; i < c.size(); i++)
		c[i] = i;

	Matrix<int> m(3,4), m2(3,4), m3(3,4);
	for (int i=0; i < m.size(); i++)
	{
		for (int j=0; j < m[0].size(); j++)
		{
			m[i][j] = (i+j);
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

// Lets do strings
	
	Matrix<string> sm(3,4), sm2(3,4), sm3(3,4);
	for (int i=0; i < sm.size(); i++)
	{
		for (int j=0; j < sm[0].size(); j++)
		{
			string str;
			for (int k=0; k < 3; k++)
			{
				str += 'a' + rand()%26;
			}
			sm[i][j] = str;

			str += 'a' + rand()%26;
			sm2[i][j] = str;
		}
	}

	sm3 = sm + sm2;

	cout <<"m " << endl;
	print(sm);
	cout <<endl << "m2"<<endl;
	print(sm2);
	cout <<endl << "m3"<<endl;
	print(sm3);
    return 0;
}
