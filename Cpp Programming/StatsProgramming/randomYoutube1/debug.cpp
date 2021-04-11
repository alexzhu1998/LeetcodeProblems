// #include <iostream>
// #include <string>
// using namespace std;

// inline const int f(const int* const p) {
// 	return 5;
// }

// int main() {
// 	int x = 6;
// 	int* p1 = &x;
// 	cout << f(p1) << endl;


// 	string y;
// 	getline(cin, y);
// 	return 0;
// }

#include <iostream>
#include <string>
using namespace std;

const long int square(const int i) { // hint
	return i*i;
}

int main() {
	int j = square(10);
	j *= 10;
	cout << j;
	string y;
	getline(cin, y);
	return 0;
}