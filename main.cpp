#include "dictionary.h"
#include <iostream>
using namespace std;

/*
	Test the functionality of the dictionary
*/
int main() {

	Dictionary d1;
	d1.add_word("island", "ilande", "ylonde");
	d1.add_word("jeopardy", "yeopardie", "ieoperde");
	d1.display();

	Dictionary d2;
	d2 = d1;
	return 0;
}
