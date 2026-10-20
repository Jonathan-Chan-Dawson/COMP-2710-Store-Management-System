// code for product struct here
#include "product.h"
#include <sstream>
#include <iomanip>

std::string product::product_info()
{
	std::ostringstream out;
	out << std::fixed << std::setprecision(2);
	out << "PRODUCT" << "\n"
			<< "Name: " << name << "\n"
			<< "Description: " << description << "\n"
			<< "Price: $" << price << "\n";
	return out.str();
}