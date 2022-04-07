
/*Mihail Ica - G20857128*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int BANNEDNO = 8; // This constant represents the number of banned words.




void ReadFile(fstream &file, vector <string> v)
{
	
	cout << "This has been read:" << endl;
	cout << endl;

	if (!file)
	{
		cout << "NO such file!" << endl;
	}
	else 
	{
		
		string str;
		
		
		while (!file.eof())
		{
			
			getline(file, str);
			cout << str;
			
			
			
			
			if (file.eof())
			{
				file.close();
				cout << endl;
			}

			cout << endl;
			v.push_back(str);
			
		}
		
		cout << endl;
		
	}
	
	
}





int main()
{

	fstream banned("banned.txt");
	fstream text1("text1.txt");

	vector <string> bannedText ;
	
	ReadFile(banned, bannedText);
	
	
	
	

	/*for (auto itBanned = bannedText.begin(); itBanned!=bannedText.end(); itBanned++)
	{
		cout << *itBanned << endl;
	}*/

	
	//Reading text1 file into the program

	int i = 0;
	
	int catHits = 0;
	int dogHits = 0;
	int aimHits = 0;
	int addHits = 0;
	int earHits = 0;
	int backHits = 0;
	int punkHits = 0;
	int ableHits = 0;
	int wordCount = 0;

	

	vector <string> text1V;
	vector <string> text1VFiltered;

	while (!text1.eof())
	{
		string str;
		text1 >> str;
		
		

		if (text1.eof())
		{
			text1.close();
			cout << endl;
		}
		
		
		text1V.push_back(str);
		text1VFiltered.push_back(str);

		for (auto itBanned = bannedText.begin(); itBanned!=bannedText.end();itBanned++)
		{
			if (str == *itBanned)
			{
				

				if (*itBanned== "cat")
				{
					catHits += 1;
					
				}
				else if (*itBanned== "dog")
				{
					dogHits += 1;
				
				}
				else if (*itBanned== "aim")
				{
					aimHits += 1;
					
				}
				else if (*itBanned== "add")
				{
					addHits += 1;
					
				}
				else if (*itBanned== "ear")
				{
					earHits += 1;
					
				}
				else if (*itBanned== "back")
				{
					backHits += 1;
				
				}
				else if (*itBanned== "punk")
				{
					punkHits += 1;
					
				}
				else if (*itBanned== "able")
				{
					ableHits += 1;
					
				}

				
			}

			for (auto itText1Filtered = text1VFiltered.begin(); itText1Filtered!=text1VFiltered.end();itText1Filtered++)
			{
				if (*itText1Filtered == *itBanned)
				{
					*itText1Filtered = "***";
				}
					
			}
			
		}



	}
		
	cout << "Here is the original text: \n";

	for (auto itText1 = text1V.begin(); itText1!=text1V.end();itText1++)
	{
		cout << *itText1 << endl;

	}

	
	

	cout << "We have the following hits: " << endl;
	cout << endl;

	cout << " 'cat' found " << catHits << " times" << endl;
	cout << " 'dog' found " << dogHits << " times" << endl;
	cout << " 'aim' found " << aimHits << " times" << endl;
	cout << " 'add' found " << addHits << " times" << endl;
	cout << " 'ear' found " << earHits << " times" << endl;
	cout << " 'back' found " << backHits << " times" << endl;
	cout << " 'punk' found " << punkHits << " times" << endl;
	cout << " 'able' found " << ableHits << " times" << endl;

	cout << " here is the filtered vector: " << endl;

	for (auto itText1Filtered = text1VFiltered.begin(); itText1Filtered!=text1VFiltered.end();itText1Filtered++)
	{
		cout << *itText1Filtered << endl;

	}
	
	ofstream filteredText1("filteredText1.txt");

	if (!filteredText1)
	{
		cout << "Cannot create file." << endl;
	}

	for (auto itWritten = text1VFiltered.begin(); itWritten!=text1VFiltered.end();itWritten++)
	{
		filteredText1 << *itWritten << " ";
	}

	filteredText1.close();

	
}