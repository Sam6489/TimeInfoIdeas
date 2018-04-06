#pragma once
#include "Node.h"
#include "CourseInfo.h"

class CourseList
{
private:
	int listSize;
	bool hasHead;
	Node *head;
public:
	CourseList( )
	{
		cout << "In CourseList Constructor" << endl;
		listSize = 0;
		hasHead = false;
		head = nullptr;
	}

	~CourseList( )
	{
		while ( head != nullptr )
		{
			Node *next = head->getNext( );
			delete head;
			head = next;
		}
	}

	void addNode( CourseInfo *data )
	{
		cout << "Adding node" << endl;
		if ( hasHead == false )
		{
			head = new Node( data );
			listSize++;
			hasHead = true;
		}
		else
		{
			head->addNode( data );
		}
	}

	bool conflictCheck( CourseInfo toCheck )
	{
		if ( head->getInfo( ) == nullptr )
		{
			return false;
		}
		CourseInfo *cur = head->getInfo( );
		bool isConflict = cur->checkForConflict( toCheck );
		Node*next = head->getNext( );
		while ( isConflict==false && next != nullptr )
		{
			cur = next->getInfo( );
			isConflict = cur->checkForConflict( toCheck );
			next = next->getNext( );
		}

		return isConflict;
	}
};