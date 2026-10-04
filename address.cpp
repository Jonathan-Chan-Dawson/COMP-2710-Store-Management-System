// implementation code for address struct here
#include "address.h"

string address::address_info()
{
  return "Line 1: " + address_line1 + " | Line 2: " + address_line2 + " | City: " + city + " | State: " + state + " | Zip: " + zip;
}