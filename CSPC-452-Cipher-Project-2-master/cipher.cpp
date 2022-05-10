/*
//arsal's code commented out
#include "driver.h"

using namespace std;

int main(int argc, char** argv)
{
	char option;

		FILE * inputtxt = fopen(inputFileName.c_str(), "rb");// to help open non text files

 // to help help write to non text fill
				if(option == 'A'){
					while(!feof(inputtxt)){

						int datareader = fread(newBlock, 1, 17, inputtxt);

						// for padding if not quite 16 bytes
						if(datareader != 0 ){
							for(int i = datareader; i < 16; i++){
								newBlock[i] = '0';
							}

						}
					}
					printf("AES Encryption Was Successful!\n");
				}
				return 0;
		}
	*/

	#include <string>
	#include <iostream>
	#include <fstream>
	//#include <typeinfo>
	#include "CipherInterface.h"
	#include "DES.h"
	#include "AES.h"


	using namespace std;

	int main(int argc, char** argv)
	{
		/**
		 * TODO: Replace the code below	with your code which can SWITCH
		 * between DES and AES and encrypt files. DO NOT FORGET TO PAD
		 * THE LAST BLOCK IF NECESSARY.
		 *
		 * NOTE: due to the incomplete skeleton, the code may crash or
		 * misbehave.
		 */

		//cout << "This is testing function 1" << endl;

		/* Create an instance of the DES cipher */
		//CipherInterface* cipher = NULL;

		/* Error checks */
		/*if(!cipher)
		{
			fprintf(stderr, "ERROR [%s %s %d]: could not allocate memory\n",
			__FILE__, __FUNCTION__, __LINE__);
			exit(-1);
		}*/






		/* my code starts here */

		//argv[0] == program name
		//argv[1] == cipher name (AES or DES)
		//argv[2] == key
		//argv[3] == ENC or DEC specification
		//argv[4] == input file name
		//argv[5] == output file name

		string argv1 = argv[1];
		string argv2 = argv[2];
		string argv3 = argv[3];
		string argv4 = argv[4];
		string argv5 = argv[5];

		cout << "This is testing function 1" << endl;


		/* Create an instance of the DES cipher */
		CipherInterface* des_cipher = new DES;
		CipherInterface* aes_cipher = new AES; //make sure file

		/* Create an instance of the AES cipher */
		//AES* aes_cipher;

		/*Read in the input file and save to char* input*/

		cout << "This is the file trying to be opened: " << argv4 << "\n";


		ifstream in_file (argv4, ios::in | ios::binary);  //opens the plaintext file
		ofstream out_file (argv5, ios::out | ios::binary);  //outputs to the ciphertext file
		//in_file.open(argv4);
		//unsigned char* input;

		unsigned char block[8];
		//unsigned char cipherBlock[8];
		unsigned char* cipherBlock;


		/* perform encryption or decryption using DES */
		//char dname[3] = "DES";
		//unsigned char* a2;
		//a2 = argv[2];

		if(argv1 == "DES"){
			if (argv3 == "ENC"){
				cout << "We are in encrypt if block updated blah\n";
				des_cipher->setKey((unsigned char*)argv[2]);
				cout << "We are passed setkey \n";

				int bytesRead;

				do
				{
						in_file.read((char*) block, 8);

						if(in_file.gcount() == 0) {}

							else
							{
								bytesRead = in_file.gcount();

								for(int index = bytesRead; index < 8; index++){
									block[index] = '\0';
								}

								//cout << "We are approaching encrypt function";
								cipherBlock = des_cipher->encrypt(block);

								out_file.write((char*) cipherBlock, 8);


							}

				} while(in_file);

				in_file.close();
				out_file.close();

				//unsigned char* cipherText = des_cipher->encrypt(input); //what are we doing with string?
				//cout << "We are passed the encrypt function \n";
			}																													//we need to create the output file and write out either the plaintext or the cipher text to it
			else if (argv3 == "DEC"){																//still need to pad with null characters when necessary
				cout << "We are in DEcrypt if block\n";
				des_cipher->setKey((unsigned char*)argv[2]);
				cout << "We are passed decrypt setkey \n";

				int bytesRead;

				do
				{
						in_file.read((char*) block, 8);

						if(in_file.gcount() == 0) {}

							else
							{
								bytesRead = in_file.gcount();

								for(int index = bytesRead; index < 8; index++){
									block[index] = '\0';
								}

								//cout << "We are approaching encrypt function";
								cipherBlock = des_cipher->decrypt(block);

								out_file.write((char*) cipherBlock, 8);

							}
					} while(in_file);

					in_file.close();
					out_file.close();
				//unsigned char* plainText = des_cipher->decrypt(input);
				//cout << "We are passed the decrypt function \n";*/
			}
			else
				cout << "Wrong enc/dec Specification\n";
		}

		else if(argv1 == "AES"){
			if (argv3 == "ENC"){
				cout << "We are in encrypt if block of AES\n";
				aes_cipher->setKey((unsigned char*)argv[2]);
				cout << "We are passed setkey \n";

				int bytesRead;

				cout << "We are passed int declaration\n";

				do
				{
						in_file.read((char*) block, 8);
						//a b c d e f g h i
						if(in_file.gcount() == 0) {}

							else
							{
								bytesRead = in_file.gcount();

								for(int index = bytesRead; index < 32; index++){
									block[index] = '\0';
								}

								//cout << "We are approaching encrypt function";
								cipherBlock = aes_cipher->encrypt(block);
								cout << "We are out of the encrypt block\n";
								out_file.write((char*) cipherBlock, 32);


							}

				} while(in_file);
				cout << "We are out of the loop\n";
				in_file.close();
				out_file.close();

				cout << "We closed the file succesfully\n";
				//unsigned char* cipherText = des_cipher->encrypt(input); //what are we doing with string?
				//cout << "We are passed the encrypt function \n";
			}
			else if (argv3 == "DEC"){																//still need to pad with null characters when necessary
				cout << "We are in DEcrypt if block\n";
				aes_cipher->setKey((unsigned char*)argv[2]);
				cout << "We are passed decrypt setkey \n";

				int bytesRead;

				do
				{
						in_file.read((char*) block, 16);

						if(in_file.gcount() == 0) {}

							else
							{
								bytesRead = in_file.gcount();

								for(int index = bytesRead; index < 8; index++){
									block[index] = '\0';
								}

								//cout << "We are approaching encrypt function";
								cipherBlock = aes_cipher->decrypt(block);

								out_file.write((char*) cipherBlock, 16);

							}
					} while(in_file);

					in_file.close();
					out_file.close();
				//unsigned char* plainText = des_cipher->decrypt(input);
				//cout << "We are passed the decrypt function \n";*/
			}
			else{
				cout << "Wrong enc/dec Specification\n";
			}

			} //end of aes else if statement
		/* Set the encryption key
		 * A valid key comprises 16 hexidecimal
		 * characters. Below is one example.
		 * Your program should take input from
		 * command line.
		 */
		 else{
		 	cout << "Wrong block cipher Specification\nYour block cipher specification was: ";
			cout << argv[1] << "\n";// << "The type of argv[1] is: " << typeid(argv[1]).name();
		}

		//cipher->setKey((unsigned char*)"0123456789abcdef");

		/* Perform encryption */
		//string cipherText = cipher->encrypt("hello world");

		/* Perform decryption */
		//cipher->decrypt(cipherText);

		cout << "We are approaching return 0\n";
		return 0;
	}
