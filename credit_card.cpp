// implementation code for credit_card struct here
#include "credit_card.h"
#include <sstream>
#include <iomanip>

// balance is the balance on the card, limit is the credit limit.
// if balance + purchase exceeds limit, the purchase is rejected.
bool credit_card::make_purchase(double purchase_amount)
{
	if (purchase_amount <= 0 || current_balance + purchase_amount > limit)
	{
    	return false;
	}
	current_balance += purchase_amount;
	return true;
}

bool credit_card::make_payment(double payment_amount)
{
	if (payment_amount <= 0)
	{
		return false;
	}
	current_balance -= payment_amount;
	return true;
}

std::string credit_card::credit_card_info()
{
	std::ostringstream out;
	out << std::fixed << std::setprecision(2);
	out << "Credit card number: " << cc_number << "\n"
    	<< "Credit Card Limit: $" << limit << "\n"
    	<< "Current Balance: $" << current_balance << "\n";
	return out.str();
}