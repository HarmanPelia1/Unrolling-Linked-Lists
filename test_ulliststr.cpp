#include <random>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>


#include "ulliststr.h"
using namespace std; 

//Use this file to test your ulliststr implementation before running the test suite

ULListStr * makeList(std::vector<std::string> const & values, bool pushBack)
{
	// circular list is not copyable so we have to pass it by pointer
	ULListStr * list = new ULListStr();

	if(pushBack)
	{
		for(std::vector<std::string>::const_iterator valuesIter = values.cbegin(); valuesIter != values.cend(); ++valuesIter)
		{
			list->push_back(*valuesIter);
		}
	}
	else
	{
		// push values in reverse from the front
		for(std::vector<std::string>::const_reverse_iterator valuesIter = values.crbegin(); valuesIter != values.crend(); ++valuesIter)
		{
			list->push_front(*valuesIter);
		}
	}

	return list;
}


void test_pop_back() {
	std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};

	ULListStr * list = makeList(content, true);

	cout << list->get(9) << endl;
	cout << list->get(10) << endl;


	list->pop_back();

	cout << "Final: " << list->get(9) << endl;
}

void test_pop_front() {
	std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};

	ULListStr * list = makeList(content, true);

	cout << list->get(9) << endl;
	cout << list->get(10) << endl;


	list->pop_front();

	cout << "Final: " << list->get(9) << endl;
}

void test_push_front() {
	std::vector<std::string> content = {"sup", "er", "cal", "i", "frag", "il", "istic", "expi", "alo", "doc", "ious"};

	ULListStr * list = makeList(content, false);

	cout << list->get(9) << endl;
	cout << list->get(10) << endl;


	list->pop_front();

	cout << "Final: " << list->get(9) << endl;
}

void test_push_back() {
	std::vector<std::string> content = {"Harman", "is", "Awesome", "Please", "Let", "Me", "Know", "if", "it", "is", "false"};

	ULListStr * list = makeList(content, false);

	cout << list->get(9) << endl;
	cout << list->get(10) << endl;


	list->pop_back();

	cout << "Final: " << list->get(9) << endl;
}

int main(int argc, char* argv[])
{
	test_pop_back();
	test_pop_front();//these check get in it
	test_push_back();
	test_push_front();
}
