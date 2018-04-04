#pragma once
#include <string>
#include "CourseInfo.h"

using namespace std;

class RoomInfo
{
private:
	string roomNumber;
	CourseInfo **myCourses;
	int courseArraySize;
	int numCourses;
public:
	RoomInfo( )
	{
		roomNumber = "";
		myCourses = nullptr;
		courseArraySize = 0;
	}

	~RoomInfo( )
	{
		if ( myCourses != nullptr )
		{
			delete[] myCourses;
		}
	}

	void fillAll( string roomNumber )
	{
		this->roomNumber = roomNumber;
	}

	void fillCourses( CourseInfo *courses, int arraySize )
	{
		string room;
		for ( int i = 0; i < arraySize; i++ )
		{
			room = courses[i].getPrefRoom( );
			if ( roomNumber == room )
			{
				bool conflict = false;
				for ( int index = 0; index < courseArraySize && conflict != true; index++ )
				{
					conflict = courses[i].checkForConflict( *myCourses[index] );
				}
				if ( conflict == false )
				{
					addCourse( &courses[i] );
				}
			}
		}
	}

	void addCourse( CourseInfo *course )
	{
		int last = 0;
		CourseInfo **temp = new CourseInfo*[courseArraySize + 1];
		for ( int i = 0; i < courseArraySize; i++ )
		{
			temp[i] = myCourses[i];
			last++;
		}
		temp[last + 1] = course;
		if ( myCourses != nullptr )
		{
			delete myCourses;
		}
		myCourses = temp;
	}
};