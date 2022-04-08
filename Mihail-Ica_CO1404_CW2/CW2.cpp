
/*Mihail Ica - G20857128*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



void ReadFile(fstream &file, vector <string> &v) //Function reads file into program which then gets pushed into vector called by ref
{
	if (!file)
	{
		cout << "NO such file!" << endl;
	}
	else
	{

		string str;


		while (!file.eof())
		{

			string str;
			file >> str;




			if (file.eof())
			{
				file.close();
				cout << endl;
			}

			
			v.push_back(str);

		}

		cout << endl;
	}
}

void DisplayVector(vector <string> v) // Function iterates through vector, takes any vector as parameter
{
	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
}

void CensorText(vector <string> bannedText, vector <string> originalText, vector <string> &censoredText)

{ //Function that iterates through both the banned text vector and any given vector to compare the words against the banned ones,
	//Number of occurences gets recorded using local vars, banned words from the text vector get replaced with *** 
	//This is then pushed onto the censoredText vector, called by ref so any changes will be shown in main

	int catHits = 0;
	int dogHits = 0;
	int aimHits = 0;
	int addHits = 0;
	int earHits = 0;
	int backHits = 0;
	int punkHits = 0;
	int ableHits = 0;
	int wordCount = 0;

	for (auto itOriginalText = originalText.begin(); itOriginalText != originalText.end(); itOriginalText++)
	{
		for (auto itBanned = bannedText.begin(); itBanned != bannedText.end(); itBanned++)
		{
			if (*itOriginalText == *itBanned)
			{


				if (*itBanned == "cat")
				{
					catHits += 1;

				}
				else if (*itBanned == "dog")
				{
					dogHits += 1;

				}
				else if (*itBanned == "aim")
				{
					aimHits += 1;

				}
				else if (*itBanned == "add")
				{
					addHits += 1;

				}
				else if (*itBanned == "ear")
				{
					earHits += 1;

				}
				else if (*itBanned == "back")
				{
					backHits += 1;

				}
				else if (*itBanned == "punk")
				{
					punkHits += 1;

				}
				else if (*itBanned == "able")
				{
					ableHits += 1;

				}

				
				*itOriginalText = "***";
				
			}

			
		}
		
		censoredText.push_back(*itOriginalText);

	}

	cout << " 'cat' found " << catHits << " times" << endl;
	cout << " 'dog' found " << dogHits << " times" << endl;
	cout << " 'aim' found " << aimHits << " times" << endl;
	cout << " 'add' found " << addHits << " times" << endl;
	cout << " 'ear' found " << earHits << " times" << endl;
	cout << " 'back' found " << backHits << " times" << endl;
	cout << " 'punk' found " << punkHits << " times" << endl;
	cout << " 'able' found " << ableHits << " times" << endl;
}

int main()
{
	/*Fstream data types for read-in files*/
	fstream banned("banned.txt");
	fstream text1("text1.txt");
	fstream text2("text2.txt");

	/*Vectors that hold text read into the program*/
	vector <string> bannedText ;
	vector <string> text1V;
	vector <string> text1VFiltered;
	vector <string> text2V;

	ReadFile(banned, bannedText);
	
	cout << "These are the banned words: \n";

	DisplayVector(bannedText);
	
	ReadFile(text1, text1V);

	cout << "This should be text1 as it was \n";
	cout << "\n";

	DisplayVector(text1V);

	cout << "\n";

	

	CensorText(bannedText, text1V, text1VFiltered);

	cout << "This is text1 censored\n";

	DisplayVector(text1VFiltered);
	
	ReadFile(text2, text2V);

	cout << "This should be text2 as it was \n";

	DisplayVector(text2V);


	ofstream filteredText1("filteredText1.txt");

	if (!filteredText1)
	{
		cout << "Cannot create file." << endl;
	}

	for (auto itWritten = text1VFiltered.begin(); itWritten != text1VFiltered.end(); itWritten++)
	{
		filteredText1 << *itWritten << " ";
	}

	filteredText1.close();

	

	
}