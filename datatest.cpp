#include <iostream>
#include <fstream>
#include <regex>

using namespace std;

void helpscrn();

int main(int argc, char* argv[]){

	// display help screen in first arg is -h or --help
	if( ((string)argv[1] == "-h") || ((string)argv[1] == "--help") ){

		// display help screen
		helpscrn();

		return 0;
	}

	string in;
	string temp;
	string regstr;

	// if no second arg
	if(!argv[2]){
		// stdin to string in
		for( ; getline(cin, temp); in = in + temp) ;
	} else {
		// file to string in
		
		ifstream infile((string)argv[2]);

		for( ; getline(infile, temp); in = in + temp) ;

		infile.close();
	}

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

		// do a regex search and save the resulting
		// submatches to std::smatch sm
		regex_search(in, sm, r);

		// revise later so sudo global not required
		if( (sm[2] != "") || (sm[2] != "\0") ){
			cout << sm[1] << ", ";
		} else {
			cout << sm[1] << endl;
		}

		in = sm[2];


	} while( (in != "") || (in != "\0") );

	cout << endl;

	return 0;
}

// help screen
void helpscrn(){

	cout << "\t+=======================================================+" << endl;
	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t--help (-h)\t\t\t\t\t|\n";

	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t    test /path/to/regex path/to/file\t\t|\n";

	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t|\t    cat input | test /path/to/regex\t\t|\n";

	cout << "\t|\t\t\t\t\t\t\t|\n";
	cout << "\t+=======================================================+" << endl;

}
