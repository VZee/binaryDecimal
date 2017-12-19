/*************************************
** Author: Louisa Katlubeck
** Date: 10/25/17
** Description: converter.cpp includes two functions, one to convert from binary to decimal,
** and another to convert from decimal to binary.
*************************************/
#include<string>
#include<math.h>
using std::string;


/**************************************
** Description: binToDec is a recursive function that has a string parameter of 1's and 0's
** that is a binary representation of a positive integer. binToDec returns the integer in decimal integer form.
**************************************/
int binToDec (string binaryString)
{
	int length = binaryString.length();

	//base cases are when the length == 1 (binaryString is either '0' or '1')
	if (length == 1)
	{
		if (binaryString == "0")
			return 0;

		else if (binaryString == "1")
			return 1;
	}

	//recursive case
	else 
	{
		//multiplier for the next char
		int multiplier = pow(2, length - 1);

		string nextString;


		//next character
		char charString = binaryString[0];
		int nextChar;

		//integer version of the next character
		if (charString == '0')
			nextChar = 0;

		else if (charString == '1')
			nextChar = 1;

		//set nextString to binaryString without the current first character
		nextString = binaryString.substr(1);

		return binToDec(nextString) + multiplier * nextChar;
	}
}


/**************************************
** Description: decToBin decToBin is a recursvie function that has a positive integer as a paramter, and returns 
** a C++ string of 1's and 0's that is the binary representation of that integer. 
**************************************/
string decToBin(int decimalInt)
{
	//base cases are when the integer is < 2
	if (decimalInt == 0)
		return "0";

	else if (decimalInt == 1)
		return "1";

	//recursive case
	else
	{
		//the result of decimalInt / 2 becomes the value that we use in the recursive call
		int result = decimalInt / 2;

		//the remainder of decimalInt / 2 becomes the next bit in the binary string
		int nextBit = decimalInt % 2;
		string nextBitString;

		//get the string equivalent of the next bit
		if (nextBit == 0)
			nextBitString = "0";

		else if (nextBit == 1)
			nextBitString = "1";

		return decToBin(result) + nextBitString;
	}

}
