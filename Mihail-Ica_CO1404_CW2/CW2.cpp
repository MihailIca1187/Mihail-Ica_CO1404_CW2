
/*Mihail Ica - G20857128*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int HALFCONSOLELENGHT = 40; //Constant int holding the value of half of the console's lenght


void DrawLines(int HALFCONSOLELENGHT) //This function draws lines that help separate the application menus.
{
	for (int i = 0; i <= HALFCONSOLELENGHT; i++)
	{
		cout << '-';
	}
	cout << endl;
}

string ToLower(string myString) //Function provided as part of Intro to Programming module, used for input validation by converting strings to lower case.
{
	string lowerString;
	for (auto c : myString) lowerString += tolower(c);
	return lowerString;
}

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

		
	}

	
}

void DisplayVector(vector <string> v) // Function iterates through vector, takes any vector as parameter
{
	DrawLines(HALFCONSOLELENGHT);

	for (auto it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";

	DrawLines(HALFCONSOLELENGHT);
}

void CensorText(vector <string> bannedText, vector <string> originalText, vector <string> &censoredText)

{ //Function that iterates through both the banned text vector and any given vector to compare the words against the banned ones,
	//Number of occurences gets recorded using local vars, banned words from the text vector get replaced with *** 
	//This is then pushed onto the censoredText vector, called by ref so any changes will be registered in main

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

		string word = ToLower(*itOriginalText);
		string originalWord = *itOriginalText;

		for (auto itBanned = bannedText.begin(); itBanned != bannedText.end(); itBanned++)
		{
			int index = (word.find(*itBanned) +1); // .find function from the string header returns the position of the first occurence in a string
											  // if the term in not found, the -1 value is returned, hence the conditional statements below
			if (word.find(*itBanned) != -1)

			{
				

				if (word.find("cat") != -1)
				{
					catHits += 1;
					
				}
				else if (word.find("dog") != -1)
				{
					dogHits += 1;
					
				}
				else if (word.find("aim") != -1)
				{
					aimHits += 1;
					
				}
				else if (word.find("add") != -1)
				{
					addHits += 1;
					
				}
				else if (word.find("ear") != -1)
				{
					earHits += 1;
					
				}
				else if (word.find("back") != -1)
				{
					backHits += 1;
					
				}
				else if (word.find("punk") != -1)
				{
					punkHits += 1;
					
				}
				else if (word.find("able") != -1)
				{
					ableHits += 1;
					
				}

				originalWord.replace(index,1,string(1,'*')); //.replace function from the string header replaces
				
				
			}
			
			
		}
		
		censoredText.push_back(originalWord);

	}

	cout << "\n\n";
	cout << " 'cat' found " << catHits << " times \n\n" ;
	cout << " 'dog' found " << dogHits << " times \n\n" ;
	cout << " 'aim' found " << aimHits << " times \n\n" ;
	cout << " 'add' found " << addHits << " times \n\n" ;
	cout << " 'ear' found " << earHits << " times \n\n" ;
	cout << " 'back' found " << backHits << " times \n\n";
	cout << " 'punk' found " << punkHits << " times \n\n";
	cout << " 'able' found " << ableHits << " times \n\n";
	cout << "\n\n";								    
}

void SaveFile(ofstream &file, vector <string> &v)
{
	if (!file)
	{
		cout << "Cannot create file.\n";
	}

	for (auto itWritten = v.begin(); itWritten != v.end(); itWritten++)
	{
		file << *itWritten << " ";
	}

	file.close();
}

int main()
{
	/*Fstream data types for read-in files*/
	fstream banned("banned.txt");
	fstream text1("text1.txt");
	fstream text2("text2.txt");
	fstream text3("text3.txt");
	fstream text4("text4.txt");

	/*Vectors that hold text read into the program*/
	vector <string> bannedText ;
	vector <string> text1V;
	vector <string> text1VFiltered;
	vector <string> text2V;
	vector <string> text2VFiltered;
	vector <string> text3V;
	vector <string> text3VFiltered;
	vector <string> text4V;
	vector <string> text4VFiltered;

	//Banned words
	ReadFile(banned, bannedText);
	
	cout << "These are the banned words: \n\n";

	DisplayVector(bannedText);
	
	//Text1 file
	ReadFile(text1, text1V);

	cout << "This should be text1 as it was \n\n";
	cout << "\n";

	DisplayVector(text1V);

	CensorText(bannedText, text1V, text1VFiltered);

	cout << "This is text1 censored\n\n";

	DisplayVector(text1VFiltered);
	
	ofstream filteredText1("filteredText1.txt");

	SaveFile(filteredText1, text1VFiltered);

	//Text2 file
	ReadFile(text2, text2V);

	cout << "This should be text2 as it was \n\n";

	DisplayVector(text2V);

	CensorText(bannedText, text2V, text2VFiltered);

	cout << "This is text2 censored \n\n";

	DisplayVector(text2VFiltered);

	ofstream filteredText2("filteredText2.txt");

	SaveFile(filteredText2, text2VFiltered);

	//Text3 file
	ReadFile(text3, text3V);

	cout << "This should be text3 as it was \n\n";

	DisplayVector(text3V);

	CensorText(bannedText, text3V, text3VFiltered);

	cout << "This is text3 censored \n\n";

	DisplayVector(text3VFiltered);

	ofstream filteredText3("filteredText3.txt");

	SaveFile(filteredText3, text3VFiltered);

	//Text4 file
	ReadFile(text4, text4V);

	cout << "This should be text4 as it was \n\n";

	DisplayVector(text4V);

	CensorText(bannedText, text4V, text4VFiltered);

	cout << "This is text4 censored \n\n";

	DisplayVector(text4VFiltered);

	ofstream filteredText4("filteredText4.txt");

	SaveFile(filteredText4, text4VFiltered);
	

	
}