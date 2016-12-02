#include "QuaternionBuild.h"

Quaternion<float> qMath;

int main()
{
	//calls loop (peek definition)
	qMath.qLoop();
	
	std::cout << "\t\n QUATERNION MATHEMATICS\n\n";

	//prints out addition, subtraction, multiplication, etc.
	qMath.qMathprint();
	
	//cin.get x2 to clear buffer the first time.
	std::cin.get();
	std::cout << "\n\t\t[Enter] to exit the program.\n";
	std::cin.get();
}