#include "dictionary.h"
using namespace std;

// default constructor
Dictionary::Dictionary() {
	cout << "Default constructor invoked." << endl;
	index = 0; // start with 0 entries
	// set the default number of alternate spellings to 0
	for (int i = 0; i < MAX_ENTRIES; i++) {
		entries[i].alt_spellings = NULL;
		entries[i].num_alt_spellings = 0;
	}
}

// copy constructor
Dictionary::Dictionary(const Dictionary& old_obj) {
	cout << "Copy constructor invoked." << endl;

	index = old_obj.index;
	entry *tmp1;
	for (int i = 0; i < MAX_ENTRIES; i++){
		tmp1 = &entries[i];
		const entry* tmp2 = &old_obj.entries[i];
		if(i > index){
			tmp1->alt_spellings = NULL;
			tmp1->num_alt_spellings = 0;
		} else {
			tmp1->num_alt_spellings = tmp2->num_alt_spellings;
			for(int j = 0; j < tmp1->num_alt_spellings; j++){
				tmp1->alt_spellings[j] = tmp2->alt_spellings[j];
			}
		}
		delete tmp2;
	}
}

// assignment operator overload
Dictionary& Dictionary::operator=(const Dictionary& old_obj) {
	cout << "Assignment operator overload invoked." << endl;

	index = old_obj.index;
	entry *tmp1;
	for (int i = 0; i < MAX_ENTRIES; i++){
		tmp1 = &entries[i];
		const entry* tmp2 = &old_obj.entries[i];
		if(i > index){
			tmp1->alt_spellings = NULL;
			tmp1->num_alt_spellings = 0;
		} else {
			tmp1->num_alt_spellings = tmp2->num_alt_spellings;
			for(int j = 0; j < tmp1->num_alt_spellings; j++){
				tmp1->alt_spellings[j] = tmp2->alt_spellings[j];
			}
		}
		delete tmp2;
	}

	return *this;
}

// deallocate all dynamic memory
Dictionary::~Dictionary() {
	cout << "Destructor invoked." << endl;
	for (int i = 0; i < MAX_ENTRIES; i++)
		delete [] entries[i].alt_spellings;
}

// add a word to the dictionary (along with its two alternate spellings)
void Dictionary::add_word(string new_word, string alt_1, string alt_2) {
	entry *tmp = &entries[index];
	tmp->word = new_word;
	tmp->num_alt_spellings = 2;
	tmp->alt_spellings = new string[tmp->num_alt_spellings];
	tmp->alt_spellings[0] = alt_1;
	tmp->alt_spellings[1] = alt_2;
	index++;
}

void Dictionary::display(){
	for(int i = 0; i < index+1; i++){
		entry* tmp = &entries[i];
		cout << tmp->word << "\n";
		for (int j = 0; j < tmp->num_alt_spellings; ++j){
			cout << "\t" << tmp->alt_spellings[j] << "\n";
		}
	}
}

