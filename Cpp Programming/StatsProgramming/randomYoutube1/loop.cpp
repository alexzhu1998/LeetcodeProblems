#include <iostream>
#include <string>
using namespace std;

// enum A;
// enum B{ bat, bird, bee };

int main() {
	
	int i =0;
	for (;;) {
		cout << ++i << endl;
		if (i == 10) {
			break;
		}
	}
	return 0;

}


