// code for transaction struct here
#include "transaction.h"

std::string transaction::transaction_info()
{
  return "Transaction Number: " + std::to_string(transaction_number) + " \n\tCustomer: (" + customer.person_info() + ")\n\tPurchased Item: ()" + purchased_item.description + ")\nQuantity: " + std::to_string(quantity);
}