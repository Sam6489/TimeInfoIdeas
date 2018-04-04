#include "AllData.h"

//fill: reads, parses, and passes correct data onto CommonInfo & CourseInfo
void AllData::fill( )
{
	string rawCourseData[MAX];// whole file in one array
	string myArray[16];// one line of file split into 16 element array
	ParseInfo parser;// object of ParseInfo class for splitting apart file and converting from string to int
	CommonInfo *link;// pointer for passing link from 
	int CRS, CRN, section, credits, startT, endT, capacity;// All elements that will need to be converted from string to int to be stored

	ifstream getcourseinfo;
	getcourseinfo.open( "201930 Natural Science First Draft.csv" );
	getline( getcourseinfo, rawCourseData[courseInfoSize] );
	while ( !getcourseinfo.fail( ) && courseInfoSize < MAX )
	{
		courseInfoSize++;
		getline( getcourseinfo, rawCourseData[courseInfoSize] );
	}
	//Reading in and storing 1st element
	myCourses = new CourseInfo[courseInfoSize];
	parser.parseAll( myArray, rawCourseData[1] );
	CRS = parser.stringToNumber( myArray[2] );
	CRN = parser.stringToNumber( myArray[0] );
	section = parser.stringToNumber( myArray[3] );
	credits = parser.stringToNumber( myArray[5] );
	startT = parser.stringToNumber( myArray[7] );
	endT = parser.stringToNumber( myArray[8] );
	capacity = parser.stringToNumber( myArray[11] );
	myCommons.setHead( myArray[1], CRS, myArray[4], credits, capacity );
	link = myCommons.setCommon( myArray[1], CRS, myArray[4], credits, capacity );
	myCourses[0].setAllValues( myArray, parser, link );
	//Reading in and storing rest of file
	for ( int i = 1; i < courseInfoSize - 1; i++ )
	{
		parser.parseAll( myArray, rawCourseData[i + 1] );
		CRS = parser.stringToNumber( myArray[2] );
		CRN = parser.stringToNumber( myArray[0] );
		section = parser.stringToNumber( myArray[3] );
		credits = parser.stringToNumber( myArray[5] );
		startT = parser.stringToNumber( myArray[7] );
		endT = parser.stringToNumber( myArray[8] );
		capacity = parser.stringToNumber( myArray[11] );
		link = myCommons.setCommon( myArray[1], CRS, myArray[4], credits, capacity );
		myCourses[i].setAllValues( myArray, parser, link );
	}

}

//linkCheck: calls function to check if CRN is the same
void AllData::linkCheck( )
{
	for ( int i = 0; i < courseInfoSize - 2; i++ )
	{
		myCourses[i].checkForLink( myCourses[i + 1] );
	}
}

//printContents: uses overloaded operators in CommonInfo & CourseInfo to output contents of objects
void AllData::printContents( )
{
	for ( int i = 0; i < courseInfoSize - 1; i++ )
	{
		cout << myCourses[i];
	}
}