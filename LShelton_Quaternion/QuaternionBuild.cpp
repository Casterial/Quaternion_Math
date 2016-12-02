#include "QuaternionBuild.h"

/*
TUPLE DEFINE:
*Tuples are objects that pack elements of -possibly- different types together in a single object, 
*just like pair objects do for pairs of elements, but generalized for any number of elements.
*/

//This tuple takes in all 4 ints and allows return of ints
template<class T>
std::tuple<T, T, T, T> Quaternion<T>::makeQuaternions()
{
	std::cout << "\nQuaternion: [Real, #i, #j, #k]\n";
	std::cout << "input R: ";
	std::cin >> r1;

	std::cout << "\n";
	std::cout << "input #i(#): ";
	std::cin >> i1;

	std::cout << "\n";
	std::cout << "input #j(#): ";
	std::cin >> j1;

	std::cout << "\n";
	std::cout << "input #k(#): ";
	std::cin >> k1;

	std::cout << "Building Quaternion.....\n";
	std::cout << "[" << r1 << "," << i1 << "i " << j1 << "j " << k1 << "k]\n";
	return std::make_tuple(r1, i1, j1, k1);
}

//creating Tuple (tuple which takes in values and is able to return 4 values)
template <class T>
std::tuple<T, T, T, T> Quaternion<T>::qAddition(std::tuple<T, T, T, T> q1, std::tuple<T, T, T, T> q2)
{
	//get<n> (quaternion Name) gives the values like an array.
	T r1 = std::get<0>(q1);
	T i1 = std::get<1>(q1);
	T j1 = std::get<2>(q1);
	T k1 = std::get<3>(q1);

	T r2 = std::get<0>(q2);
	T i2 = std::get<1>(q2);
	T j2 = std::get<2>(q2);
	T k2 = std::get<3>(q2);

	//addition math
	r = r1 + r2;
	i = i1 + i2;
	j = j1 + j2;
	k = k1 + k2;

	//prints the addition math
	std::cout << "\n\nq1 + q2 = " << "[" << r << ", " << i << "i " << j << "j " << k << "k]\n";

	//return the tuple to allow it to be accessed.
	return std::make_tuple(r, i, j, k);
}

//creating Tuple (tuple which takes in values and is able to return 4 values)
template <class T>
std::tuple<T, T, T, T> Quaternion<T>::qSubtraction(std::tuple<T, T, T, T> q1, std::tuple<T, T, T, T> q2)
{
	//get<n> (quaternion Name) gives the values like an array.

	T r1 = std::get<0>(q1);
	T i1 = std::get<1>(q1);
	T j1 = std::get<2>(q1);
	T k1 = std::get<3>(q1);

	T r2 = std::get<0>(q2);
	T i2 = std::get<1>(q2);
	T j2 = std::get<2>(q2);
	T k2 = std::get<3>(q2);

	r = r1 - r2;
	i = i1 - i2;
	j = j1 - j2;
	k = k1 - k2;

	//prints the subtraction math
	std::cout << "\n\nq1 - q2 = " << "[" << r << ", " << i << "i " << j << "j " << k << "k]\n";
	
	//return the tuple to allow it to be accessed.
	return std::make_tuple(r, i, j, k);
}

template<class T>
std::tuple<T, T, T, T> Quaternion<T>::qMultiplication(std::tuple<T, T, T, T> q1, std::tuple <T, T, T, T> q2)
{
	T r1 = std::get<0>(q1);
	T i1 = std::get<1>(q1);
	T j1 = std::get<2>(q1);
	T k1 = std::get<3>(q1);

	T r2 = std::get<0>(q2);
	T i2 = std::get<1>(q2);
	T j2 = std::get<2>(q2);
	T k2 = std::get<3>(q2);

	r = (r1*r2 - i1*i2 - j1*j2 - k1*k2);
	i = (r1*i2 + i1*r2 + j1*k2 - k1*j2);
	j = (r1*j2 - i1*k2 + j1*r2 + k1*r2);
	k = (r1*k2 + i1*j2 - j1*i2 + k1*r2);

	std::cout << "\n\nq1 * q2 = " << "[" << r << ", " << i << "i " << j << "j " << k << "k]\n";
	
	return std::make_tuple(r, i, j, k);


}

//allows looping to take in the tuple for q1 & q2, can expand for more.
template <class T>
void Quaternion<T>::qLoop()
{
	//tuple 1 makes q1 quaternion (takes in input)
	q1 = makeQuaternions();

	//tuple 2 makes q2 quaternion (takes in input)
	q2 = makeQuaternions();
}
template<class T>
void Quaternion<T>::qMathprint()
{
	//prints out the operation mathematics.
	std::tuple<T, T, T, T> qAdd = qAddition(q1, q2);
	std::tuple<T, T, T, T> qSub = qSubtraction(q1, q2);
	std::tuple<T, T, T, T> qMul = qMultiplication(q1, q2);
}

template class Quaternion<float>;