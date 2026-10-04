// code for product struct here
// product info string
#include "product.h"

std::string product::product_info()
{
  return "PRODUCT Name: " + name + " | Description: " + description + " | Price: " + std::to_string(price);
};
