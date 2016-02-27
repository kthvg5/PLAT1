//Kyle Hatfield	     12396364
//Homework one
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


//recognizing function declarations
bool recognizeInteger(string s);
bool recognizeDecimal(string s);
bool recognizeScientific(string s);
bool recognizeHex(string s);
bool recognizeBin(string s);
bool recognizeKey(string s);
bool recognizeIdentifier(string s);

//main
int main()
{
	int runs;
	string current;
	cin >> runs;
	cout << runs << endl;
	for (int i = 0; i < runs; i++)
	{
		cin >> current;
		if(recognizeInteger(current))
			cout << i+1 << ": Integer.\n";
		else if(recognizeDecimal(current))
			cout << i+1 << ": Decimal.\n";
		else if(recognizeScientific(current))
			cout << i+1 << ": Scientific.\n";
		else if(recognizeHex(current))
			cout << i+1 << ": Hexadecimal.\n";
		else if(recognizeBin(current))
			cout << i+1 << ": Binary.\n";  //This is the exact moment I remembered isalnum()
		else if(recognizeKey(current))
			cout << i+1 << ": Keyword.\n";
		else if(recognizeIdentifier(current))
			cout << i+1 << ": Identifier.\n";
		else
			cout << i+1 << ": Invalid!\n";

	}
	return 0;
}

//functions
bool recognizeInteger(string s)
{
	int state = 0, i = 0;
	bool acceptable = false;
	while ( i < s.length() )
	{
		switch (state)
		{
			case 0: if (s[i] == '+' || s[i] == '-' || s[i] == '0' || s[i] == '1' 
				|| s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' 
				|| s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
					{
						state = 1;
						acceptable = true;
					}
					else
					{
						state = -1; //failure state
					}
					break;
			case 1: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
					{
						state = 1;
					}
					else
					{
						state = -1;
						acceptable = false;
					}
					break;
			default: //failure state
					i = s.length();
					break;
		}//switch
		i++;
	}
	return acceptable;
}
bool recognizeDecimal(string s)
{
	int state = 0, i = 0;
	bool acceptable = false;
	while ( i < s.length() )
	{
		switch (state)
		{
			case 0: if (s[i] == '+' || s[i] == '-' || s[i] == '0' || s[i] == '1' 
				|| s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' 
				|| s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
					{
						state = 1;
					}
					else
					{
						state = -1; //failure state
					}
					break;
			case 1: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
					{
						state = 1;
					}
					else if(s[i] == '.')
					{
						state = 2;
					}
					else
					{
						state = -1;
					}
					break;
			case 2: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
					{
						state = 3;
						acceptable = true;
					}
					else
						state = -1;
					break;
			case 3: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
					{
						state = 3;
					}
					else
					{
						acceptable = false;
						state = -1;
					}
					break;
			default: //failure state
					i = s.length();
					break;
		}//switch
		i++;
	}
	return acceptable;
}
bool recognizeScientific(string s)
{
	int state = 0, i = 0;
	bool acceptable = false;
	while ( i < s.length() )
	{
		switch (state)
		{
			case 0: if (s[i] == '+' || s[i] == '-' || s[i] == '0' || s[i] == '1' 
				|| s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' 
				|| s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
					{
						state = 1;
					}
					else
					{
						state = -1; //failure state
					}
					break;
			case 1: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
					{
						state = 1;
					}
					else if(s[i] == '.')
					{
						state = 2;
					}
					else
					{
						state = -1;
					}
					break;
			case 2: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
				{
					state = 3;
				}
				else
				{
					state = -1;
				}
				break;
			case 3: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
				{
					state = 3;
				}
				else if (s[i] == 'E')
				{
					state = 4;
				}
				else
				{
					state = -1;
				}
				break;
			case 4: if (s[i] == '+' || s[i] == '-' || s[i] == '1' 
				|| s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' 
				|| s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
				{
					state = 5;
					acceptable = true;
				}
				else
				{
					state = -1;
				}
				break;
			case 5: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' 
				|| s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' 
				|| s[i] == '8' || s[i] == '9')
				{
					state = 5;
				}
				else
				{
					state = -1;
					acceptable = false;
				}
				break;
			default:
				i = s.length();
				break;
		} //switch
		i++;
	}
	return acceptable;
}
bool recognizeHex(string s)
{
	int state = 0, i = 0;
	bool acceptable = false;
	while ( i < s.length() )
	{
		switch (state)
		{
			case 0: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || 
				s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || 
				s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == 'A' || 
				s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || 
				s[i] == 'F')
					{
						state = 1;
					}
					else
					{
						state = -1;
					}
					break;
			case 1: if (s[i] == '0' || s[i] == '1' || s[i] == '2' || 
				s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || 
				s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == 'A' || 
				s[i] == 'B' || s[i] == 'C' || s[i] == 'D' || s[i] == 'E' || 
				s[i] == 'F')
					{
						state = 1;
					}
					else if(s[i] == 'H')
					{
						state = 2;
						acceptable = true;
					}
					else
					{
						state = -1;
					}
					break;
			case 2:
					state = -1;
					acceptable = false;
					break;
			default://failure!!!
					i = s.length();
					break;

		}
		i++;
	}
	return acceptable;				
}
bool recognizeBin(string s)
{
	int state = 0, i = 0;
	bool acceptable = false;
	while(i < s.length())
	{
		switch(state)
		{
			case 0: if(s[i] == '1' || s[i] == '0')
					{
						state = 1;
					}
					else
					{
						state = -1;
					}
					break;
			case 1: if(s[i] == '1' || s[i] == '0')
					{
						state = 1;
					}
					else if(s[i] == 'B')
					{
						state = 2;
						acceptable = true;
					}
					else
					{
						state = -1;
					}
					break;
			case 2: 
					state = -1;
					acceptable = false;
					break;
			default:
					i = s.length();
					break;
		}//switch
		i++;
	}
	return acceptable;
}
bool recognizeKey(string s)
{
	bool acceptable = false;
	if(s == "while" || s == "else" || s == "end" || s == "print")
		acceptable = true;
	return acceptable;
}
bool recognizeIdentifier(string s)
{
	int state = 0, i = 0;
	bool acceptable = false;
	while(i < s.length())
	{
		switch(state)
		{
			case 0: if(isalpha(s[i]))
					{
						state = 1;
						acceptable = true;
					}
					else
					{
						state = -1;
					}
					break;
			case 1: if(isalnum(s[i]) || s[i] == '_')
					{
						state = 1;
					}
					else
					{
						state = -1;
					}
					break;
			default:
					i = s.length();
					break;
		}//switch
		i++;
	}
	return acceptable;
}