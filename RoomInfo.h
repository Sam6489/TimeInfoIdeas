#pragma once
#include <string>
#include "CourseInfo.h"
#include "CourseList.h"

using namespace std;

class RoomInfo
{
private:
	string roomNumber;
	//CourseInfo **myCourses;
	CourseList myCourses;
	int courseArraySize;
	int numCourses;
public:
	RoomInfo( )
	{
		roomNumber = "";
		//myCourses = nullptr;
		courseArraySize = 0;
	}

	~RoomInfo( )
	{
		//if ( myCourses != nullptr )
		//{
		//	delete myCourses;
		//}
	}

	void fillAll( string roomNumber )
	{
		this->roomNumber = roomNumber;
	}

	void fillCourses( CourseInfo *courses, int arraySize )
	{
		cout << "In fillCourses" << endl;
		string room;
		for ( int i = 0; i < arraySize; i++ )
		{
			room = courses[i].getPrefRoom( );
			//cout << room << endl;
			if ( roomNumber == room )
			{
				bool conflict = false;
				conflict = myCourses.conflictCheck( courses[i] );
				if ( conflict == false )
				{
					cout << "Found course for room: " << roomNumber << endl;
					myCourses.addNode( &courses[i] );
				}
			}
		}
	}

	/*void addCourse( CourseInfo *course )
	{
		cout << "In addCourses" << endl;
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
	}*/
};