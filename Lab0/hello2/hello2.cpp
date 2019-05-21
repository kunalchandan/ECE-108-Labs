#include <iostream>
#include "hello2.h"
using namespace std;

int main(int argc, char* argv[]) {
	int i;
	cout << "argc = " << argc << endl;

	for (i = 0; i < argc; i++) {
		cout << "argv[" << i << "] = " << argv[i] << endl;
	}

	cout << endl;
	switch (argc) {

	case 0:
		cout << "No Arguments!" << endl;
		break;
	case 1:
		cout << MESSAGE << "World!." << endl;
		break;
	case 2:
		cout << MESSAGE << argv[argc-1] << "." << endl;
		break;
	default:
		cout << "You have too many arguments for me!" << endl;
		break;
	}
	cout << "\n---------------------------------\n\n";
	return 0;
}
