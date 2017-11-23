#include<iostream>
using namespace std;

#ifndef VECTOR_H_
#define VECTOR_H_

template<typename T>
class Vector
{
private:
	T* data; // dynamically allocated array pointer
	int capacity = 0; // total space in the array
	int numberOfElements = 0; // the number of elements in the array so far

	void setSize(int newSize)
	{
		numberOfElements = newSize;
	}

public:

	/*CONSTRUCTORS*/


	// Empty vector constructor
	Vector<T>()
	{
		numberOfElements = 0;
		capacity = 10;
		data = new T[capacity];
	}

	// Default vector constructor
	Vector<T>(int theSize)
	{
		capacity = theSize;
		numberOfElements = theSize;
		data = new T[capacity];

		// Assign each element a default value of 0
		for (int i = 0; i < capacity; i++)
		{
			data[i] = 0;
		}
	}

	// Vector constructor filled with specified value
	Vector<T>(int theSize, T defaultValue)
	{
		capacity = theSize;
		numberOfElements = theSize;

		data = new T[capacity];

		// Assign each element a default value of "defaultValue"
		for (int i = 0; i < capacity; i++)
		{
			data[i] = defaultValue;
		}
	}

//////////

	// Append an element to the end of the vector
	void push_back(T element)
	{
		if (numberOfElements == capacity)
			doubleCapacity(); // If the vector is already full, double its capacity

		// Assign new element to the slot directly proceeding the original last element
		// (last element is data[numberOfElements - 1])
		data[numberOfElements] = element;

		// Now it's one bigger in the number of elements (not capacity, necessarily)
		// so increase numberOfElements by 1
		numberOfElements++;
	}

	void doubleCapacity()
	{
		T* newData = new T[capacity * 2]; // create new array of double the original length

		// loop that walks through the new array, assigning its first half of elements
		// the values of the original elements in the old array (from data to newData)
		for (int i = 0; i < capacity; i++)
		{
			newData[i] = data[i];
		}

		capacity *= 2;

		// Assign the rest of the new empty slots some zeroes
		for (int i = (capacity / 2); i < capacity; i++)
		{
			newData[i] = 0;
		}

		delete[] data;
		data = newData;
	}

	// Delete last element in the vector
	void pop_back()
	{
		data[numberOfElements - 1] = NULL;
		numberOfElements--;
	}

	// Getter for current number of elements in vector
	int size() const 
	{
		return numberOfElements;
	}

	// Getter for element at specific index in vector
	T at(int index) const
	{
		return data[index];
	}

	// Boolean that tells whether or not the vector is empty
	// (returns TRUE if empty)
	bool empty() const
	{
		if (numberOfElements == 0)
			return true;

		else
			return false;
	}

	// Clear function: Clears all elements in vector
	void clear()
	{
		numberOfElements = 0;
	}

	void swap(Vector &v2)
	{
		//Hold their original numberOfElements (we'll need them later)
		int tempNumThis = this->numberOfElements;
		int tempNumThat = v2.numberOfElements;

		// Find out which vector is smaller

		int limit = 0;
		if (this->numberOfElements > v2.numberOfElements)
			limit = v2.numberOfElements;
		//but
		if (v2.numberOfElements > this->numberOfElements)
			limit = this->numberOfElements;
		// BUT...
		if (this->numberOfElements == v2.numberOfElements)
			limit = this->numberOfElements; // either way...
		
		/* Straight-swap the values until we reach the end
		of the smaller vector */
		for (int i = 0; i < limit; i++)
		{
			T temp = data[i];
			data[i] = v2.at(i);
			v2.data[i] = temp;
		}

		/* Then append the rest of the values from the bigger vector
		to the end of the smaller vector (only if one is bigger than the other)*/
		if (this->numberOfElements > v2.numberOfElements)
		{
			for (int i = v2.numberOfElements; i < this->numberOfElements; i++)
			{
				v2.push_back(data[i]);
			}
		}
		//or
		if (v2.numberOfElements > this->numberOfElements)
		{
			for (int i = this->numberOfElements; i < v2.numberOfElements; i++)
			{
				this->push_back(v2.data[i]);
			}
		}

		/* Finally, swap their original "numberOfElements" 
		(this is where we needed them... HA!) */
		this->numberOfElements = tempNumThat;
		v2.numberOfElements = tempNumThis;
	}

	// Destructor
	~Vector()
	{
		delete[] data;
	}

};

#endif