// implementation code for address struct here
#include "address.h"
#include <sstream>
#include <iomanip>

string address::address_info()
{
	std::ostringstream out;
	out << std::fixed << std::setprecision(2);
	out << address_line1 << ", "
			<< address_line2 << ", "
			<< city << ", "
			<< state << ", "
			<< zip << "";
	return out.str();
}