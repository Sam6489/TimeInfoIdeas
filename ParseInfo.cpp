#include "ParseInfo.h"

//parseAll: takes in a raw string and parses it into a 16 position array based off of a comma delimeter
//target[]: array for holding all elements of a line seperately
//rawInput: the complete string before being pulled apart
void ParseInfo::parseAll( string target[16], string rawInput )
{
	if ( rawInput[0] == ',' )
	{
		return;
	}
	for ( int i = 0; i < 16; i++ )
	{
		target[i] = "";
	}
	int position = 0;
	for ( int i = 0; i < rawInput.size( ) && position<16; i++ )
	{
		if ( rawInput[i] == ',' )
		{
			position++;
		}
		else
		{
			target[position] += rawInput[i];
		}
	}
}

//stringToNumber: an alpha to numeric conversion utilized for all elements read in that need to be stored as ints
//rawInput: string to be converted to int
int ParseInfo::stringToNumber( string rawInput )
{
	return atoi( rawInput.c_str( ) );
}