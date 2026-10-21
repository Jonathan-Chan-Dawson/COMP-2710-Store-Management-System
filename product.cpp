// code for product struct here
#include "product.h"
#include <sstream>
#include <iomanip>

std::string product::product_info()
{
	std::ostringstream out;
	out << std::fixed << std::setprecision(2);
	out << "PRODUCT" << " | "
			<< "Name: " << name << ", \n"
			<< "Description: " << description << ", "
			<< "Price: $" << price << "";
	return out.str();
}