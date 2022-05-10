To compile, simply, type ''make'' at the terminal (without the quotes).

Please do not forget to include a README file in your submission.
It's worth 5 points.

Your README file should include:

– Names and email addresses of all partners.
Arsal Khan -arsalziakhan@gmail.cm
– The programming language you use (e.g. C++ or Java)
C++
– How to execute your program.

– Whether you implemented the extra credit.
no
– Anything special about your submission that we should take note of.
We tried to implement the AES cipher using strategies we discussed in class. Looking at the data a block at a time but we were not able to break the data down into making the program read the data a block at a time. Thus for AES, we have left our attempt at the way we were trying to do things

# CSUF-Cryptography-Assignment2-SP2020
For CSUF Cryptography with Mikael Gofman for Spring 2020

Students:


Program completed in C++

Instructions to Compile and Execute Code: 
1. To compile type in make in the command line in the correct directory.
2. For execution enter the command like this using the instructions in assignemnt2: .\cipher <Cipher_name> <key> <ENC/DEC> <Input_file> <Output_file>
      
      
   Example: .\cipher DES 0123456789abcdef ENC enc.txt dec.txt
   
   Example: .\cipher AES 00112233445566778899aabbccddeeff ENC enc.txt dec.txt
   
