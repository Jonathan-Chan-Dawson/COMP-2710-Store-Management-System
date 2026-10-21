// code for store class here
// The Store Stores Customers and Products, and Manages Transactions
#include "store.h"
#include <iostream>
#include <algorithm>

using namespace std;

Store::Store()
    : num_customers_(0), num_products_(0), num_transactions_(0)
{
}

// get set number customers
void Store::num_customers(int customer_count)
{
  if (customer_count >= 0 && customer_count <= 100)
    num_customers_ = customer_count;
}
int Store::num_customers()
{
  return num_customers_;
}

// get set number products
void Store::num_products(int product_count)
{
  if (product_count >= 0 && product_count <= 100)
    num_products_ = product_count;
}
int Store::num_products()
{
  return num_products_;
}

// get set number transactions
void Store::num_transactions(int transaction_count)
{
  if (transaction_count >= 0 && transaction_count <= 100)
    num_transactions_ = transaction_count;
}

int Store::num_transactions()
{
  return num_transactions_;
}

// add customer
bool Store::add_customer(Person customer)
{
  if (num_customers_ >= 100)
  {
    return false;
  }
  else
  {
    customers_[num_customers_] = customer;
    num_customers(num_customers_ + 1);
    return true; // added
  }
}

// updates customer within boundaries 0 to 99, and customer names must match
bool Store::update_customer(int index, Person customer)
{
  if (index >= 100 || index < 0 || customer.name() != customers_[index].name())
  {
    return false;
  }
  else
  {
    customers_[index] = customer; // replace all info
    return true;
  }
}

Person Store::get_customer(int index)
{
  return customers_[index];
}

// add products
bool Store::add_product(product item)
{
  if (num_products_ >= 100)
  {
    return false;
  }
  else
  {
    products_[num_products_] = item;
    num_products(num_products_ + 1);
    return true;
  }
}

product Store::get_product(int index)
{
  return products_[index];
}

// add transactions
bool Store::add_transaction(transaction transaction_item)
{
  if (num_transactions_ >= 100)
  {
    return false;
  }
  else
  {
    transactions_[num_transactions_] = transaction_item;
    num_transactions(num_transactions_ + 1);
    return true;
  }
}

transaction Store::get_transaction(int index)
{
  return transactions_[index];
}

// is the int the product # or cash? we un known the int.
// needs to add a transaction
// adds a person if not already added
bool Store::make_purchase(Person person, product product, int quantity)
{
  if (num_transactions_ >= 100) // never > 100
  {
    return false;
  }

  credit_card card = person.person_credit_card();
  bool purchase_success = card.make_purchase(product.price * quantity);

  if (purchase_success)
  {
    person.person_credit_card(card);

    transaction new_transaction;
    new_transaction.customer = person;
    new_transaction.purchased_item = product;
    new_transaction.quantity = quantity;
    new_transaction.transaction_number = num_transactions_;
    add_transaction(new_transaction);

    if (!update_customer(find_customer(person), person))
      add_customer(person);
  }
  return purchase_success;
}

// returns a string listing all products associated
// with this store.
std::string Store::product_info()
{
  std::string str = "\nPRODUCT INFO: \n";
  for (int i = 0; i < num_products_; i++)
  {
    std::string str_temp = get_product(i).product_info();
    str += "\n\n" + str_temp;
  }
  str += "\n";
  str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
  return str;
}

// returns a string listing all transactions associated
// with this store
string Store::transaction_info()
{
  std::string str = "\nTRANSACTIONS INFO: \n";
  for (int i = 0; i < num_transactions_; i++)
  {
    std::string str_temp = get_transaction(i).transaction_info();
    str += "\n\n" + str_temp;
  }
  str += "\n";
  str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
  return str;
}

string Store::customer_info()
{
  std::string str = "\nCUSTOMERS INFO: \n";
  for (int i = 0; i < num_customers_; i++)
  {
    std::string str_temp = get_customer(i).person_info();
    str += "\n\n" + str_temp;
  }
  str += "\n";
  str.erase(std::remove(str.begin(), str.end(), '\r'), str.end());
  return str;
}

// returns a string listing all information about this
// store (transactions and products)
string Store::store_info()
{
  std::string str = "\n~~~~~~ FULL STORE INFO: ~~~~~~~\n";
  return product_info() + transaction_info() + customer_info();
}

// searches through the transactions_[] and returns a
// string representing all transactions that belong to
// a specific customer.
string Store::purchase_history(Person customer)
{
  std::string str = "Transaction History of Customer " + customer.name() + ": ";

  for (int i = 0; i < num_transactions_; i++)
  {
    if (transactions_[i].customer.name() == customer.name())
      str += transactions_[i].transaction_info() + ", ";
  }

  if (str.length() > 2)
    str.erase(str.length() - 2);

  return str; // <= no customer found
}

// given a customer, returns the index in the customer_[]
// where that customer is located >(by name)
int Store::find_customer(Person customer)
{
  for (int i = 0; i < num_customers_; i++)
  {
    if (customers_[i].name() == customer.name())
      return i;
  }
  return -1; // <= no customer found
}