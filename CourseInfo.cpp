#include "CourseInfo.h"

//setAllValues: sets all values in an object of CourseInfo to a real value read in from the file
//rawInput[]: a single line read in from the file
//parser: object of ParseInfo used for it's stringToNumber method
//link: address established in AllData that links to the appropriate member of CommonInfo
void CourseInfo::setAllValues( string rawInput[16], ParseInfo &parser, CommonInfo *link )
{
	CRN = parser.stringToNumber( rawInput[0] );
	section = parser.stringToNumber( rawInput[3] );
	days = rawInput[6];
	startT = parser.stringToNumber( rawInput[7] );
	endT = parser.stringToNumber( rawInput[8] );
	prefRoom = rawInput[10];
	startD = rawInput[12];
	endD = rawInput[13];
	myCommons = link;
	time.setAll( startD, endD, startT, endT, days );
}

//checkForLink: checks if two objects have the same CRN, useful for connecting a lecture/lab class
//toCompare: the other object of CourseInfo besides the one that checkForLink is called from
void CourseInfo::checkForLink( CourseInfo toCompare )
{
	if ( CRN == toCompare.CRN )
	{
		link = &toCompare;
	}
}

//Compares two TimeInfo objects to check if they overlap (True if conflict, false if no conflict)
//toCompare: The other CourseInfo object that is being compared to this object
bool CourseInfo::checkForConflict( CourseInfo toCompare )
{
	bool toReturn = time.checkForConflict( toCompare.time );
	return toReturn;
}

//Overloaded CourseInfo output operator for testing
ostream &operator<<( ostream &stream, CourseInfo toOutput )
{
	stream << "CRN: " << toOutput.CRN << endl;
	stream << "Section: " << toOutput.section << endl;
	stream << "Days: " << toOutput.days << endl;
	stream << "Start Time: " << toOutput.startT << endl;
	stream << "End Time: " << toOutput.endT << endl;
	stream << "Preferred Room: " << toOutput.prefRoom << endl;
	stream << "Start Date: " << toOutput.startD << endl;
	stream << "End Date: " << toOutput.endD << endl;
	stream << toOutput.myCommons << endl;
	return stream;
}