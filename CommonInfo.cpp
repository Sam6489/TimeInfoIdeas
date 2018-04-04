#include "CommonInfo.h"

//setAll: takes in all values in the common info class except for next and changes the ones in the current object to the passed in values
//prefix: 3 character course prefix: CSC, CNG, MAT, etc..
//CRS: Course Number: 101, 119, 234, etc...
//Title: Course's full title
//credits: How many credits the Course is worth
//capacity: How many people can be taught in one Class
void CommonInfo::setAll( string prefix, int CRS, string title, int credits, int capacity )
{
	this->CRS = CRS;
	this->prefix = prefix;
	this->title = title;
	this->credits = credits;
	this->capacity = capacity;

}

//isSame: takes in all members of CommonInfo and checks if they are identical. Returns true if they are the same, otherwise false.
//prefix: 3 character course prefix: CSC, CNG, MAT, etc..
//CRS: Course Number: 101, 119, 234, etc...
//Title: Course's full title
//credits: How many credits the Course is worth
//capacity: How many people can be taught in one Class
bool CommonInfo::isSame( string prefix, int CRS, string title, int credits, int capacity )
{
	bool toReturn;// return value
	if ( this->CRS == CRS && this->prefix == prefix && this->title == title && this->credits == credits && this->capacity == capacity )
	{
		toReturn = true;
	}
	else
	{
		toReturn = false;
	}
	return toReturn;
}

//Overloaded CommonInfo output operator for testing
ostream &operator<<( ostream &stream, CommonInfo *toOutput )
{
	stream << "Prefix: " << toOutput->prefix << endl;
	stream << "CRS: " << toOutput->CRS << endl;
	stream << "Title: " << toOutput->title << endl;
	stream << "Credits: " << toOutput->credits << endl;
	stream << "Capacity: " << toOutput->capacity << endl;
	return stream;
}
