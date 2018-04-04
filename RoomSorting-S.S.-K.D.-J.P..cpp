//Sam Scheuerman, Kyle Dickens, Josh Penrod
//Room Scheduling Reading & Parsing Pt1
//Due: 3/30/18
//The portion of code for reading in all pertinent elements about a course from a file and storing them in appropriate, memory efficient, objects.

#include "AllData.h"
using namespace std;

int main( )
{
	AllData myData;
	myData.fill( );
	myData.linkCheck( );
	myData.printContents( );
	cout << "Everything output above comes from the objects that data has been read into, and not just output from the file." << endl;	
	cout << "Number of CourseInfo Objects (Unique): " << myData.getCourseInfoSize( )-1 << endl;
	cout << "Number of CommonInfo Objects (General): " << myData.getMyCommons( )->getNumNodes( ) << endl;

	cout << endl;
	system( "pause" );
	return 0;
}