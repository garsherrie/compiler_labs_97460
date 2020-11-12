#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <regex>
#include <list>
#include <map>

using namespace std;


int main() {

	int x = 0;
	cout << "Welcome to my simple lexical analyzer\n";

	//put a while loop so that the code keeps on running
	while (x == 0) {
		//define your string
		string mystring;

		//the user gets a chance to enter the string for evaluation
		cout << "Please input your string say (y=24+k;) : ";

		//extract the input from user and appends it to the string until a delimiter is found
		getline(cin, mystring);

		// defining all the possible token types 
		map<string, string> inputs{
			{ "[0-9]+" ,   "integer" },{ "[_a-zA-Z]+" ,   "identifier" },{ "\\*|\\+|\\-|\\=",  "operator" },{ "[)}({]" , "special characters" },{"[,.:]", "punctuation symbol;"},{";","shows end of code"}
		};


		// store the results by mapping them
		map< size_t, pair<string, string> > matches;

		//check through the inputs to get the token type of a certain token
		for (auto way = inputs.begin(); way != inputs.end(); ++way)
		{
			regex r(way->first);
			auto words_begin = sregex_iterator(mystring.begin(), mystring.end(), r);
			auto words_end = sregex_iterator();


			for (auto it = words_begin; it != words_end; ++it)
				matches[it->position()] = make_pair(it->str(), way->second);
		}

		//after the iteration, the tokens have been matched with their respective token type
		for (auto match = matches.begin(); match != matches.end(); ++match)

			//we are now dispaying the tokens and their matches (token types)
			cout << match->second.first << " : " << match->second.second << endl;

		//we have the output as follows if we use our example y=24+k;
		/*
		y : identifier
		= : operator
		24 : integer
		+ : operator
		k : identifier
		; : shows end of code
		*/

		cout << "\n" << "Awesome! You can try again!" << "\n";

	}
}
