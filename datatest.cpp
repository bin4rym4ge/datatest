#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

int main(int argc, char* argv[]){

	string in;
	string temp;
	string regstr;


	// stdin to string
	for( ; getline(cin, temp); in = in + temp);


	// Read regex file
	// Get Location of file from first command line arg
	ifstream regfile((string)argv[1]);


	// assign regex file to string regstr
	while(getline(regfile, temp)) regstr = regstr + temp;


	// Create a regex object from regstr
	regex r(regstr);
	smatch sm;

	// return all \1 submatches as comma seperated list items
	// reqireds all regex to end in (.*) to continue matching
	// think of this as using /g global tag

	do{

		regex_search(in, sm, r);


		if( (sm[2] != "") || (sm[2] != "\0") ){
			cout << sm[1] << ", ";
		} else {
			cout << sm[1] << endl;
		}

		in = sm[2];


	} while( (in != "") || (in != "\0") );

	/*
	   while( (in != "") || (in != "\0") ){

	   regex_search(in, sm, r);

	   cout << sm[1] << ", ";

	   in = sm[2];

	   }
	   */

	cout << endl;

	return 0;
}

