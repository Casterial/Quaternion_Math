#ifndef _QUATERNIONBUILD_H
#define _QUATERNIONBUILD_H

#include <iostream>
#include <math.h>
#include <vector>
#include <tuple>

template<class T>
class Quaternion
{
private:
	//creating private ints used within the class.
	T r1, i1, j1, k1, r, i, j, k;


public:
	//globalizes the std::tuple to be accessed by all classes and refresh amount.
	std::tuple<T, T, T, T> q1;
	std::tuple<T, T, T, T> q2;

	//creating the tuple classes for quaternion multiplication, addition, subtraction, etc.
	std::tuple<T, T, T, T> makeQuaternions();
	std::tuple<T, T, T, T> qAddition(std::tuple<T, T, T, T> q1, std::tuple<T, T, T, T> q2);
	std::tuple<T, T, T, T> qSubtraction(std::tuple<T, T, T, T> q1, std::tuple<T, T, T, T> q2);
	std::tuple<T, T, T, T> qMultiplication(std::tuple<T, T, T, T> q1, std::tuple <T, T, T, T> q2);

	//qLoop is looping the creation of how many quaternions there are (q1, q2...qn)
	void qLoop();
	//printing function for all math functions
	void qMathprint();
};

#endif