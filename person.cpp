// code for person class here
#include "person.h"
#include <iostream>

using std::string;

// Get Set Methods are Below!

Person::Person()
{
}

Person::Person(string name, string phone, address person_address, credit_card person_credit_card)
    : name_(name), phone_(phone), person_address_(person_address), person_credit_card_(person_credit_card)
{
  // Don't do this->_name = name, etc...
}

// Name
void Person::name(string new_name)
{
  name_ = new_name;
}
string Person::name()
{
  return name_;
}

// Phone
void Person::phone(string new_phone)
{
  phone_ = new_phone;
}
string Person::phone()
{
  return phone_;
}

// Person Address
void Person::person_address(address new_person_address)
{
  person_address_ = new_person_address;
}
address Person::person_address()
{
  return person_address_;
}

// Person Credit Card
void Person::person_credit_card(credit_card new_person_credit_card)
{
  person_credit_card_ = new_person_credit_card;
}
credit_card Person::person_credit_card()
{
  return person_credit_card_;
}

// string

string Person::person_info()
{
  return "PERSON Name: " + name_ + " | Phone: " + phone_ + " \n\tAddress: (" + person_address_.address_info() + ") \n\tCredit Card: (" + person_credit_card_.credit_card_info() + ")\n\n";
}