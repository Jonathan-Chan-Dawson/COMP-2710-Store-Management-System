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

	// add to store and other variables
	Store store1 = Store();
	// TODO: Add the products into the store

	// print store info after you finish importing info
	// from text files and add them to your store (no transactions yet!)
	cout << "Store info: " << endl
			 << endl;
	cout << store1.store_info() << endl
			 << endl;

	// make random number of random transactions
	int randomly_generated_transactions_count = rand() * 90 + 10;
	for (int i = 0; i < randomly_generated_transactions_count; i++)
	{
		int random_customer = rand() * store1.num_customers();
		Person person = store1.get_customer(random_customer);
		// TODO: figure out how to add a person and randomize a [roduct for the transaction
	}

	// print store info at the end (with transactions)
	cout << "Store info: " << endl
			 << endl;
	cout << store1.store_info() << endl
			 << endl;

	inFile.close();
}
