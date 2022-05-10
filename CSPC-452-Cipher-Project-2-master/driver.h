#ifndef __DRIVER__
#define __DRIVER__

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "CipherInterface.h"
#include "AES.h"
#include "DES.h"
using namespace std;

void readFile(char fn, string buffer);
void writeFile(char fn, string buffer);


#endif