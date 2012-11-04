#include "math.h"
#include <iostream>
#include <fstream>
float distortedCosine(float _theta, long seed=0);

#define PI 3.1415927f
float distortedCosine(float _theta, long seed)
{
	srand(unsigned long(777*(seed+tan(_theta))));
	return ((float(rand()%100)/100)+((1-cos(_theta))/2))/2;
}
int main()
{
	float theta=0;
	float rnda=0;
	long seed=88;

	std::ofstream file;
	file.open("cosine-d.txt");

	file << "Seed: " << seed << "\n";
	for(theta=0; theta<2*PI; theta+=0.01f)
	{
		file << "Distortion(" << theta << ") = " << distortedCosine(theta, seed) << "\n";
	}

	file.close();

}