// code for transaction struct here
#include "transaction.h"

std::string transaction::transaction_info()
{
  return "Transaction Details:\n"
  	"Transaction #: " + std::to_string(transaction_number) + "\n" +
	"Customer:\n" + customer.person_info() +
	"Product:\n" + purchased_item.product_info() +
	"Quantity: " + std::to_string(quantity) + "\n";
}