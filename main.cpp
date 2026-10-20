#include <iostream> //start of main.cpp
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>

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
	ifstream inFile_1("people.txt");

	if (inFile_1) // if it doesn't exist we weep
	{
		std::getline(inFile_1, line);

		int m = std::stoi(line);

		for (int i = 0; i < m; i++)
		{
			Person new_person;	 // the person
			address new_address; // the coordinates

			std::getline(inFile_1, line);
			new_person.name(line);

			std::getline(inFile_1, line);
			new_person.phone(line);

			std::getline(inFile_1, line);
			new_address.address_line1 = line;

			std::getline(inFile_1, line);
			new_address.address_line2 = line;

			std::getline(inFile_1, line);
			new_address.city = line;

			std::getline(inFile_1, line);
			new_address.state = line;

			std::getline(inFile_1, line);
			new_address.zip = line;

			new_person.person_address(new_address);
			store1.add_customer(new_person);
		}

		inFile_1.close();
	}
	else
	{
		cout << "Error: People is Not Available!" << endl; // the humans escaped
		return -1;																				 // crash out
	}

	ifstream inFile_2("credit_card.txt");

	if (inFile_2)
	{
		std::getline(inFile_2, line);

		int m = std::stoi(line);

		for (int i = 0; i < m; i++)
		{
			credit_card new_card;

			std::getline(inFile_2, line);
			while (line == "")
				std::getline(inFile_2, line);
			string card_owner = line;

			std::getline(inFile_2, line);
			while (line == "")
				std::getline(inFile_2, line);
			new_card.cc_number = std::stoi(line);

			std::getline(inFile_2, line);
			while (line == "")
				std::getline(inFile_2, line);
			new_card.limit = std::stod(line);

			std::getline(inFile_2, line);
			while (line == "")
				std::getline(inFile_2, line);
			new_card.current_balance = std::stod(line);

			Person temp_person = Person();
			temp_person.name(card_owner);
			int j = store1.find_customer(temp_person);

			if (j > -1 && j < 100)
			{
				Person customer = store1.get_customer(j);
				customer.person_credit_card(new_card);
				store1.update_customer(j, customer);
			}
		}

		inFile_2.close();
	}
	else
	{
		cout << "Error: Credit Card is Not Available!" << endl;
		return -1; // rage quit
	}

	ifstream inFile_3("products.txt");

	if (inFile_3)
	{
		std::getline(inFile_3, line);

		int m = std::stoi(line);

		for (int i = 0; i < m; i++)
		{
			product new_product;

			std::getline(inFile_3, line);
			while (line == "")
				std::getline(inFile_3, line);
			new_product.name = line;

			std::getline(inFile_3, line);
			while (line == "")
				std::getline(inFile_3, line);
			new_product.description = line;

			std::getline(inFile_3, line);
			while (line == "")
				std::getline(inFile_3, line);
			new_product.price = std::stoi(line);

			store1.add_product(new_product);
		}

		inFile_3.close();
	}
	else
	{
		cout << "Error: Credit Card is Not Available!" << endl;
		return -1; // rage quit
	}

	// print store info after you finish importing info
	// from text files and add them to your store (no transactions yet!)
	cout << "Store Info (Before Scamming): " << endl
			 << endl;
	cout << store1.store_info() << endl
			 << endl;

	// make random number of random transactions
	int randomly_generated_transactions_count = rand() % 91 + 10;
	if (store1.num_customers() > 0 && store1.num_products() > 0)
	{
		for (int i = 0; i < randomly_generated_transactions_count; i++)
		{
			int random_customer = rand() % store1.num_customers();
			int random_product = rand() % store1.num_products();
			int random_amount = rand() % 5 + 1; // 5 was the chosen one.

			Person person = store1.get_customer(random_customer); // exhibit a
			product product = store1.get_product(random_product); // exhibit b

			bool success = store1.make_purchase(person, product, random_amount);
			cout << "Transaction " << i << " success: " << success << "\n";
		}
	}
	else
	{
		cout << "Error: Store has no customers or products!\n";
		return -1;
	}

	// print store info at the end (with transactions)
	cout << "\n\n\n\nStore Info (After Scamming): " << endl
			 << endl;
	cout << store1.store_info() << endl
			 << endl;

	return 0;
}
// if assembly was streamlined, made practical, and modernize it..it..thats holy c
// jonathan started questioning his life choices, his bloodline, and his faith in the entire 'c' language bloodline