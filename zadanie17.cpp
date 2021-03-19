//
// Created by Waclendy
// 19.03.2021
//


#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// dynamic data container for lines from file 
static vector<string> inputData;


void	In_ReadFile( string filepath ) {
	ifstream ifstr;
	char buf[32];

	ifstr.open( filepath, ios::in );

	if( !ifstr.is_open() ) {
		cout << "File doesnt exsists!" << endl;
		return;
	}


	// Read  äøòóûfrom the file
	while( !ifstr.eof() ) {
		ifstr.getline( buf, 32 );
		// add received line from file to vector
		inputData.push_back( buf );
	}

	/* SUCCESSFULL */

}


string calc() {
	int				r_minValueInteger = 30001;
	string			r_minValueString = "not found";
	int				r_temp = -1;
	string			r_elem = "";

	for( int i = 0; i < inputData.size(); i++ ) {

		r_elem = inputData[i].c_str();

		// aviable only two-digit number 
		if( r_elem.size() > 2 )
			continue;
		
		// aviable only number what ends on 6
		if( r_elem[1] != '6' )
			continue;

		r_temp = atoi( r_elem.c_str() );

		// this is not min number
		if( r_temp > r_minValueInteger )
			continue;

		r_minValueInteger = r_temp;
		r_minValueString = r_elem;
		
	}

	if( r_minValueInteger == 30001 ) 
		return "\nNumbers for search couldnt found\nOR\nFile is empty\n";

	return r_minValueString;
	

}

int main()
{

	// NOTE: if file path length will be longer than 128 chars
	//       program will crash

	char buf[128];

	cout << "Zadanie 17 Informatika" << endl;
    cout << "Current program requiring path to file with numbers" << endl;

	cout << "Enter path: ";
	cin >> buf;

	In_ReadFile( buf );
	cout << "Program result: " << calc().c_str() << endl;

	system( "pause" );
	

}

