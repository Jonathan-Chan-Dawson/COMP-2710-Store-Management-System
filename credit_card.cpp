// implementation code for credit_card struct here
#include "credit_card.h"

// balance is the balance on the card limit is the credit limit
// balance can go below 0, for which thats excess money that you can spend
// if balance exceeds limit, you can no longer make purchases.
bool credit_card::make_purchase(double purchase_amount)
{
  if (current_balance + purchase_amount > limit)
  {
    return false;
  }
  else
  {
    current_balance += purchase_amount;
    return true;
  }
}

bool credit_card::make_payment(double payment_amount)
{
  if (payment_amount <= 0)
  {
    return false;
  }
  else
  {
    current_balance -= payment_amount;
    return true;
  }
}
