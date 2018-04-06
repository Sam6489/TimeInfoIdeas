#pragma once
#include <string>
#include "CourseInfo.h"

class Node
{
private:
	Node * next;
	CourseInfo *data;
public:
	Node( )
	{
		next = nullptr;
		data = nullptr;
	}

	Node( CourseInfo *data )
	{
		this->data = data;
		next = nullptr;
	}

	Node *getNext( )
	{
		return next;
	}

	CourseInfo *getInfo( )
	{
		return data;
	}

	void addNode( CourseInfo *data )
	{
		if ( next == nullptr )
		{
			next = new Node( data );
		}
		else
		{
			next->addNode( data );
		}
	}
};