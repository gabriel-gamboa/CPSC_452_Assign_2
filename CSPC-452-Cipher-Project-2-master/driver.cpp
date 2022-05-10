#include "driver.h"
//functions wed use for the reading and writing of files
 void readFile(char fn, string buffer){
    ifstream myFile(fn);
	if (myFile.fail())
	{
		cout << "file unable to open" << endl;
	}
}

void writeFile(char fn, string buffer){
	//Prints out to a file 
    ofstream oFile;
    oFile.open(fn);
	if(oFile.fail()){
		cout << "Unable to create file " << endl;
	}
	else{
		oFile << buffer << endl;
	}   
	oFile.close();
}
