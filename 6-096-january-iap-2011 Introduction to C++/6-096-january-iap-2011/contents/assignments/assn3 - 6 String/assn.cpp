#include  <iostream>
#include <string> 

// using namespace std, in order to omit " std:: " operator
using namespace std;

const string VOWELS("aeiou");

string pigLatinify(const string word)
{
	//////////////////////////////////////////////////////////////////////////
	if (word.size() == 0)
	{// oops, empty string
		return word;
	}
	//////////////////////////////////////////////////////////////////////////
	string head(word.substr(0, 1)); // can be replaced by word[0]
	if (VOWELS.find(head) /*== 0*/!= VOWELS.npos)
	{
		return word + "way";
	}else if(word.substr(0, 2) == "qu")
	{
		return word.substr(2) + "-qu" + "ay";
	}else{
		return word.substr(1) + "-" + word.substr(0, 1) + "ay";
	}
	
}

int main ()
{
	string s[5] = {"beast", "dough", "happy", "question", "earch"};
	for (int i=0; i < 5; i++)
	{
		cout << pigLatinify(s[i]) << endl;
	}


	return 0;
}

