#include <iostream> //start of main.cpp
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

int main()
{
	// spawn in store 1
	Store store1 = Store();

	// import from text files
	std::string line = "";
	ifstream inFile("people.txt");

	if (inFile) // if it doesn't exist we weep
	{
		std::getline(inFile, line);

		int m = std::stoi(line);
		Person new_person;	 // the person
		address new_address; // the coordinates

		for (int i = 0; i < m; i++)
		{
			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_person.name(line);

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_person.phone(line);

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_address.address_line1 = line;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_address.city = line;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_address.state = line;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_address.zip = line;

			new_person.person_address(new_address);
			store1.add_customer(new_person);
		}

		inFile.close();
	}
	else
	{
		cout << "Error: People is Not Available!" << endl;
		return -1;
	}

	std::string line = "";
	ifstream inFile("credit_card.txt");

	if (inFile)
	{
		std::getline(inFile, line);

		int m = std::stoi(line);

		for (int i = 0; i < m; i++)
		{
			credit_card new_card;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			string card_owner = line;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_card.cc_number = std::stoi(line);

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_card.current_balance = std::stoi(line);

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_card.limit = std::stoi(line);

			Person temp_person = Person();
			temp_person.name(card_owner);

			int j = store1.find_customer(temp_person);

			if (j != -1 && j < 100)
			{
				Person customer = store1.get_customer(j);
				customer.person_credit_card(new_card);
				store1.update_customer(j, customer);
			}
		}

		inFile.close();
	}
	else
	{
		cout << "Error: Credit Card is Not Available!" << endl;
		return -1; // rage quit
	}

	std::string line = "";
	ifstream inFile("products.txt");

	if (inFile)
	{
		std::getline(inFile, line);

		int m = std::stoi(line);

		for (int i = 0; i < m; i++)
		{
			product new_product;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_product.name = line;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_product.description = line;

			std::getline(inFile, line);
			while (line == "")
				std::getline(inFile, line);
			new_product.price = std::stoi(line);

			store1.add_product(new_product);
		}

		inFile.close();
	}
	else
	{
		cout << "Error: Credit Card is Not Available!" << endl;
		return -1; // rage quit
	}

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
		int random_product = rand() * store1.num_products();
		int random_amount = rand() * 5; // 5 was chosen.

		Person person = store1.get_customer(random_customer); // exhibit a
		product product = store1.get_product(random_product); // exhibit b

		store1.make_purchase(person, product, random_amount);
	}

	// print store info at the end (with transactions)
	cout << "Store info: " << endl
			 << endl;
	cout << store1.store_info() << endl
			 << endl;

	inFile.close();
	return 0;
}
