#include <iostream>
#include <string>
using namespace std;


int main (int argc, char* argv[]) {
	// 1) Create an int array with min/max int values
	int a[]{ INT8_MIN, INT8_MAX };
	cout<< a[0] << " " << a[1] << endl;
	// 2) Create a double array with 5 double values
	double b[]{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	// 3) Create an array of size 1, then set its value
	char c[1];
	c[0] = 'a';
	cout << c[0] << endl;
	// 4) Create a 2d array of characters, asigning them values 'a' through 'i'
	char d[2][5]{ 'a','b','c','d','e' };
	d[1][0] = 'f';
	d[1][1] = 'g';
	d[1][2] = 'h';
	d[1][3] = 'i';

	char d2[2][5]{{'a','b','c','d','e'},{'f','g','h','i'}};
	// 5) create a int 3d array with assigned values of 1-8;

	// 6) Create a character array with your name

	// 7) Create a character array with only special characters
	char spec[] = "\n\t\\\'\"\0";
	cout << spec << endl;
	// 8) Create two strings called food1, food2 with values "soup" and "salad", and swap them.


	return 0;
}







