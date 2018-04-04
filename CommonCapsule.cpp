#include "CommonCapsule.h"

//setCommon: checks if a new node of the Common Info linked list is needed or if a correct element already exists. Returns link to new or existing node
//prefix: 3 character course prefix: CSC, CNG, MAT, etc..
//CRS: Course Number: 101, 119, 234, etc...
//Title: Course's full title
//credits: How many credits the Course is worth
//capacity: How many people can be taught in one Class
CommonInfo * CommonCapsule::setCommon( string prefix, int CRS, string title, int credits, int capacity )
{

	CommonInfo *cur = head;
	CommonInfo *toReturn = nullptr;
	CommonInfo *next = nullptr;
	while ( cur )
	{
		next = cur->getNext( );
		if ( cur->isSame( prefix, CRS, title, credits, capacity ) )
		{
			toReturn = cur;
			break;
		}
		else if ( next == nullptr )
		{
			next = new CommonInfo( prefix, CRS, title, credits, capacity );
			cur->setNext( next );
			toReturn = next;
			numNodes++;
			break;
		}
		else
		{
			cur = next;
		}
	}
	return toReturn;
}

//deleteAll: deletes all elements of the CommonInfo linked list
void CommonCapsule::deleteAll( )
{
	CommonInfo *cur = head;
	while ( cur )
	{
		head = head->getNext( );
		delete cur;
		cur = head;
	}
}