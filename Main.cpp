#include<iostream>
#include<string>

#include"Vector.h"
using namespace std;

int main()
{
	Vector<int> v1(5, 1); // First vector
	
	// Print v1
	for (int i = 0; i < v1.size(); i++)
	{
		cout << " " << v1.at(i);
	}
	cout << endl;

	Vector<int> v2(6, 2); // Second vector

	// Print v2
	for (int i = 0; i < v2.size(); i++)
	{
		cout << " " << v2.at(i);
	}
	cout << endl;

	// Swap them
	v1.swap(v2);

	// Print v1 again
	for (int i = 0; i < v1.size(); i++)
	{
		cout << " " << v1.at(i);
	}
	cout << endl;

	// Print v2 again
	for (int i = 0; i < v2.size(); i++)
	{
		cout << " " << v2.at(i);
	}
	cout << endl;



	return 0;
}