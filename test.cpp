#include <iostream>
#include "scope_exit.h"

using namespace std;

int main() {
	cout << "before UTILITY_SCOPE_EXIT" << endl;
	UTILITY_SCOPE_EXIT( [=]{cout << "Inner Lambda 01" << endl;} );
	UTILITY_SCOPE_EXIT( [=]{cout << "Inner Lambda 02" << endl;} );
	cout << "after UTILITY_SCOPE_EXIT" << endl;

	return 0;
}
