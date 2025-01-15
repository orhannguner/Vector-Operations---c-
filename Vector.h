#pragma once

#include<iostream>
using namespace std;
class Vector {
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream& in, Vector&);
private:
	double* data;
	int dimension;
public:
	
	int const getDimension();
	bool operator!=(const Vector& vector);
	Vector* operator+(const Vector& secondOperand);
	Vector* operator-(const Vector& secondOperand);
	const Vector& operator=(const Vector& copyVector);
	bool operator==(const Vector& vector);
	double& operator[](int index);
	Vector& operator()(double index[], int dimension);
	Vector(int dimension = 3);
	Vector(double data[], int dimension);
	Vector(const Vector& copyVector);
	~Vector();


};
ostream& operator<<(ostream& out, const Vector& vector)
{
	out << "[";
	for (int i = 0; i < vector.dimension; i++)
	{
		out << vector.data[i] << ", ";
	}
	out <<" ]"<< endl;
	return out;

}
istream& operator>>(istream& in, Vector& vector)
{
	for (int i = 0; i < vector.dimension; i++)
	{
		in >> vector.data[i];
	}
	
	return in;

}
int const Vector::getDimension()
{
	return dimension;
}
bool Vector::operator!=(const Vector& vector)
{
	if (this == &vector)
	{
		return false;
	}
	else return true;
}
Vector* Vector::operator+(const Vector& secondOperand)
{
	Vector* vector = new Vector(3);
	for (int i = 0; i < dimension; i++)
	{

		vector->data[i] = data[i] + secondOperand.data[i];

	}

	return vector;
}
Vector* Vector::operator-(const Vector& secondOperand)
{
	Vector* vector = new Vector(3);

	for (int i = 0; i < dimension; i++)
	{

		vector->data[i] = data[i] - secondOperand.data[i];

	}

	return vector;


}
const Vector& Vector::operator=(const Vector& copyVector)
{
	if (&copyVector != this)
	{
		if (dimension != copyVector.dimension)
		{
			delete[]data;
			dimension = copyVector.dimension;
			data = new double[dimension];

		}
		for (int i = 0; i < dimension; i++)
		{
			data[i] = copyVector.data[i];
		}
	}
	return *this;
}
bool Vector::operator==(const Vector& vector)
{
	if (dimension != vector.dimension)
	{
		return false;
	}
	for (int i = 0; i < dimension; i++)
	{
		if (data[i] = vector.data[i])
		{
			return true;
		}
		else return false;
	}
}
double& Vector:: operator[](int index)
{
	if (index < 0 || index >= dimension)
	{

		cout << "\nError: Index " << index;
		cout << " out of range" << endl;



	} // end if

	return this->data[index];
}
Vector& Vector::operator()(double index[], int dimension)
{
	//Vector v;
	for (int i = 0; i < dimension; i++)
	{
		this->data[i] = index[i];
	}
	return *this;
}

Vector::Vector(int d)
{
	dimension = (d > 0 ? d : 3);
	data = new double[dimension];
	for (int i = 0; i < dimension; i++)
	{
		data[i] = 0;
	}

}


Vector::Vector(double data[], int dimension)
{
	Vector v;
	v.dimension = dimension;
	for (int i = 0; i < dimension; i++)
	{
		v.data[i] = data[i];
	}
	*this = v;
}
Vector::Vector(const Vector& copyVector)
{
	dimension = copyVector.dimension;

	data = new double[dimension];
	for (int i = 0; i < dimension; i++)
	{
		data[i] = copyVector.data[i];


	}
}
Vector::~Vector()
{
	delete data;
}

