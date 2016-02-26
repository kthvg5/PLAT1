//Kyle Hatfield	     12396364
//Homework one
#include <iostream>
#include <string>
using namespace std;


//recognizing function declarations
bool recognizeInteger(string s);
bool recognizeDecimal(string s);
bool recognizeScientific(string s);
//bool recognizeHex(string s);
//bool recognizeBin(string s);
//bool recognizeKey(string s);
//bool recognixeIdentifier(string s);

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
			case 3
		} //switch
		i++
	}
	return acceptable;		

}