#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "address.h"
#include "credit_card.h"
#include "person.h"
#include "product.h"
#include "store.h"
#include "transaction.h"

using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;

int main()
{

	// import from text files
	ifstream inFile("credit_card.txt");
	ifstream outFile("credit_card.txt"); // ?

	// add to store and other variables
	Store store1 = Store();

	// print store info after you finish importing info
	// from text files and add them to your store
	cout << "Store info: " << endl
			 << endl;
	cout << store1.store_info() << endl
			 << endl;

	// make random number of random transactions

	// print store info at the end
	cout << "Store info: " << endl
			 << endl;
	cout << store1.store_info() << endl
			 << endl;
}
