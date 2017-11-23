#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

#ifndef SHUFFLEVECTOR_H_
#define SHUFFLEVECTOR_H_

template<typename T>
void shuffle(vector<T> &v)
{
	// Call random function thingy
	srand(time(NULL));

	// THE SHUFFLING BEGINS...
	for (int i = 0; i < v.size(); i++)
	{
		// Choose a random index inside the vector
		int randomIndex = rand() %	v.size();

		/* Make sure our random index isn't the same as
		where we're looking currently*/
		if (i != randomIndex)
		{
			/*Swap the current element with the element
			at the random index*/
			T temp = v.at(i);
			v.at(i) = v.at(randomIndex);
			v.at(randomIndex) = temp;
		}
	}

}

#endif
