// code for transaction struct here
#include "transaction.h"
#include <sstream>
#include <iomanip>

std::string transaction::transaction_info()
{
	std::ostringstream out;
	out << std::fixed << std::setprecision(2);
	out << "TRANSACTION DETAILS: " << "\n"
			<< "Transaction #: " << std::to_string(transaction_number) << "\n"
			<< "Customer: " << customer.person_info() << "\n"
			<< "Product: " << purchased_item.product_info() << "\n"
			<< "Quantity: " << std::to_string(quantity) << "\n";
	return out.str();
}