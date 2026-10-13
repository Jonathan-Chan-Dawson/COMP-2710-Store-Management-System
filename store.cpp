// code for store class here
// The Store Stores Customers and Products, and Manages Transactions
#include "store.h"

Store::Store()
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
void Store::num_products(int transaction_count)
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
    return true;
  }
}

transaction Store::get_transaction(int index)
{
  return transactions_[index];
}

// is the int the product # or cash? we un known the int.
bool Store::make_purchase(Person person, product product, int index)
{
  get_product(index);
  return person.person_credit_card().make_purchase(product.price);
}