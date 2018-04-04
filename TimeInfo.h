#pragma once
#include <string>
#include <iostream>

using namespace std;

class TimeInfo
{
private:
	int stime;
	int etime;
	int sday;
	int smonth;
	int syear;
	int eday;
	int emonth;
	int eyear;
	bool days[7];

	const string months[12]= { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
public:
	TimeInfo( );		//Default constructor

		//Overloaded constructor to fill variable at instantiation
	TimeInfo( string sdate, string edate, int stime, int etime, string days );

		//Parses date string into ints for comparison
	void parseDate( string date, int &day, int &month, int &year );

		//Parses week days string into bool array
	void parseWeek( string days, bool toFill[7] );

		//Fills variables w/ same code as overloaded constructor
	void fillAll( string sdate, string edate, int stime, int etime, string days );

	bool dateConflict( TimeInfo otherDate );

	bool timeConflict( TimeInfo otherTime );
};

TimeInfo::TimeInfo( )
{
	stime = 0;
	etime = 0;
	sday = 0;
	smonth = 0;
	syear = 0;
	eday = 0;
	emonth = 0;
	eyear = 0;
	for ( int i = 0; i < 7; i++ )
	{
		days[i] = false;
	}
}

TimeInfo::TimeInfo( string sdate, string edate, int stime, int etime, string days )
{
	parseDate( sdate, sday, smonth, syear );
	parseDate( edate, eday, emonth, eyear );
	this->stime = stime;
	this->etime = etime;
	parseWeek( days, this->days );
}

void TimeInfo::parseDate( string date, int &day, int &month, int &year )
{
	//This is where we need to parse the date string into usable numbers
	string nums = "";
	string chars = "";
	string days = "";
	string years = "";

	for ( int i = 0; i < date.size( ); i++ )
	{
		if ( isdigit( date[i] ) )
		{
			nums += date[i];
		}
		else if ( isalpha( date[i] ) )
		{
			chars += date[i];
		}
		else
		{
			continue;
		}

	}
	//cout << nums << endl;
	//cout << chars << endl;

	for ( int index = 0; index < 12; index++ )
	{
		if ( chars == months[index] )
		{
			month = index + 1;
		}
	}

	if ( nums.size( ) == 3 )
	{
		days += nums[0];
		for ( int e = 1; e < nums.size( ); e++ )
		{
			years += nums[e];
		}
	}
	else
	{
		int c = 0;
		while ( c < 2 )
		{
			days += nums[c];
			c++;
		}
		for ( int d = c; d < nums.size( ); d++ )
		{
			years += nums[d];
		}
	}

	day = atoi( days.c_str( ) );
	year = atoi( years.c_str( ) );

	//This was here to test, leaving it in in case I need it later
	/*cout << day << endl << year << endl;
	cout << endl << endl << "Final form." << endl;
	cout << "Day " << day << endl;
	cout << "Month " << month << endl;
	cout << "Year " << year << endl << endl;*/
}

void TimeInfo::parseWeek( string days, bool toFill[7] )
{
	for ( int i = 0; i < days.size( ); i++ )
	{
		switch ( days[i] )
		{
		case'M':
			toFill[0] = true;
			break;
		case'T':
			toFill[1] = true;
			break;
		case'W':
			toFill[2] = true;
			break;
		case'R':
			toFill[3] = true;
			break;
		case'F':
			toFill[4] = true;
			break;
		case'S':
			toFill[5] = true;
			break;
		case'U':
			toFill[6] = true;
			break;
		default:
			cout << "Bad week string found" << endl;
			break;
		}
	}
}

void TimeInfo::fillAll( string sdate, string edate, int stime, int etime, string days )
{
	parseDate( sdate, sday, smonth, syear );
	parseDate( edate, eday, emonth, eyear );
	this->stime = stime;
	this->etime = etime;
	parseWeek( days, this->days );
}

bool TimeInfo::dateConflict( TimeInfo otherDate )
{
	bool toReturn;
	if ( sday <= otherDate.eday&&smonth <= otherDate.emonth&&syear <= otherDate.eyear )
	{
		toReturn = true;
	}
	else if ( eday >= otherDate.sday&&emonth >= otherDate.smonth&&eyear >= otherDate.eyear )
	{
		toReturn = true;
	}
	else
	{
		toReturn = false;
	}

	return toReturn;
}

bool TimeInfo::timeConflict( TimeInfo otherTime )
{
	bool toReturn;
	if ( stime <= otherTime.etime )
	{
		toReturn = true;
	}
	else if ( etime >= otherTime.stime )
	{
		toReturn = true;
	}
	else
	{
		toReturn = false;
	}
	return toReturn;
}
