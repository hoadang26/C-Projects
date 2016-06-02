// © copyright 2015 Hoa Dang. All Rights Reserved.

// Author: Hoa Dang

// Date: 03/30/2016

// Contact: hoa.dang26@gmail.com

// Description: I'm the (computer) scientist

// This is a program that translate character into Morse code

#include <iostream>

#include <windows.h> // access Sleep(), Beep(), SetConsoleTitle() … library functions

#include <cstring> // string type access.


using namespace std;

// function prototype

void morseCode(char);

char morseCodeHist() {
	cout << "The Morse code is a long established form of communication.\
	It was widely used for more than a century and provided its value in\
	a variety of areas from land line telegraph systems through to radio\
	communications. The Morse code was developed by Samuel Morse and his\
	associates in the middle of the nineteenth Century and has been in\
	widespread use ever since. Initially the Morse code was used for\
	sending messages over a telegraph system and as a result it became\
	known as the Morse telegraph. This system became the first widespread\
	method of sending messages over great distances. It was simple to use\
	and flexible, and it soon became a World-Wide standard." << endl;
}

void dot() {

 Beep(1000, 100); // sound of a DOT

 cout << '.'; // print a DOT

 Sleep(10); // wait for 1o milliseconds

}

void dash() {

 Beep(500, 200); // sound of a DASH

 cout << '-'; // print a DASH

 Sleep(50); // wait 5o milliseconds

}

int main () {

 string in;                         // from cstring

 int a;

 cout << "This program translates Characters into Morse Code" << endl;
 cout << endl;
 cout << "Do you want to (Enter 1 or 2):" <<endl;
 cout << "1. Translate Characters into Morse Code" << endl;
 cout << "2. Learn About Morse Code" << endl;
 cin >> a;

 cin.ignore();

 if (a == 2)
{
	morseCodeHist(); }
else if (a==1) {

    cout<< "Enter a sentence: ";

    getline(cin, in, '\n');

 int len = in.length();          // get length of string.

 for(int i=0; i<len; i++) {

 char letter = in[i];           // get ith character from string.

 cout << "letter "<< letter;    // display character

 morseCode( letter);            // convert to Morse code sound and dot-dash print

 cout << endl;                  // skip a line on output

 Sleep(10);                   // wait (about) 1o milliseconds

 } }

 else {
    cout << "Invalid Input";
 }

 return 0;
  }// end of main

// INPUT: character

// OUTPUT: Morse Code sounds and dot-dash print

void morseCode(char letter) // look for pattern in here …

{

 switch( toupper(letter)) { // change character into its Morse code sounds.

 // HERE IS WHERE YOU SHOULD LOOK for a PATTERN

 case 'A':

    dot(); dash();

    break;

 case 'B':

    dash(); dot(); dot(); dot();

    break;

 case 'C':

    dash(); dot(); dash(); dot();

    break;

 case 'D':

    dash(); dot(); dot();

    break;

case 'E':

    dot(); dot();

    break;

case 'F':

    dot(); dot(); dash(); dot();

    break;

case 'G':

    dash(); dash(); dot();

    break;

case 'H':

    dot(); dot(); dot(); dot();

    break;

case 'I':

    dot(); dot();

    break;

case 'J':

    dot(); dash(); dash(); dash();

    break;

case 'K':

    dash(); dot(); dash();

    break;

case 'L':

    dot(); dash(); dot(); dot();

    break;

case 'M':

    dash(); dash();

    break;

case 'N':

    dash(); dot();

    break;

 case 'O':

    dash(); dash(); dash();

    break;

case 'P':

    dot(); dash(); dash(); dot();

    break;

case 'Q':

    dash();dash();dot();dash();

    break;

case 'R':

    dot(); dash();dot();

    break;

case 'S':

    dot();dot();dot();

    break;

case 'T':

    dash();dash();

    break;

 case 'U':

    dot(); dot(); dash();

    break;

 case 'V':

    dot(); dot(); dot(); dash();

    break;

 case 'W':

    dot(); dash(); dash();

    break;

 case 'X':

    dash();dot();dot();dash();

    break;

 case 'Y':

    dash();dot();dash();dash();

    break;

 case 'Z':

    dash();dash();dot();dot();

    break;

 case '1':

    dot();dash();dash();dash(); dash();

    break;

case '2':

    dot();dot();dash();dash(); dash();

    break;

case '3':

    dot();dot();dot();dash(); dash();

    break;

case '4':

    dot();dot(); dot();dot();dash();

    break;

case '5':

    dot();dot(); dot();dot();dot();

    break;

case '6':

    dash();dot();dot(); dot();dot();

    break;

case '7':

    dash();dash();dot();dot(); dot();

    break;

case '8':

    dash();dash();dash();dot(); dot();

    break;

case '9':

    dash();dash();dash();dash(); dot();

    break;

 case '0':

    dash();dash();dash();dash(); dash();

    break;

 case ' ':      // blank space, need a pause without sound.

 break;

 default:

 cout<<"Bad Input"<< endl;

 }

} // end of Morse code
