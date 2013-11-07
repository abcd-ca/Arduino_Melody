/*
The MIT License (MIT)

Copyright (c) <year> <copyright holders>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "pitches.h"
#include "Melody.h"

//as is described in tone() manual on arduino.cc, tone() interferes with pins 3 and 11 so don't use those pins
#define MELODY_PIN 8

//define three different songs by listing their notes and duration (4 is quarter note, 8 is 8th note...)

//initialize the song notes and timing with an array of notesData structs. notesData struct is defined in Note.h
PROGMEM Note melody1Notes[] = {
	{NOTE_C7, 4},
	{NOTE_E7, 4},
	{NOTE_D7, 8},
	{0, 4},
	{NOTE_D7, 8},
	{0, 4},
	{NOTE_D7, 8},
};

//initialize the song notes and timing with an array of notesData structs. notesData struct is defined in Note.h
PROGMEM Note melody2Notes[] = {
	{NOTE_E7, 8},
	{0, 16},
	{NOTE_E7, 8},
	{NOTE_E7, 8},
	{NOTE_E7, 8},
	{NOTE_E7, 8},
	{0, 16},
	{NOTE_C7, 8},
	{0, 16},
	{NOTE_E7, 8},
	{0, 16},
	{NOTE_G7, 1},
};

//initialize the song notes and timing with an array of notesData structs. notesData struct is defined in Note.h
PROGMEM Note melodyAlertNotes[] = {
	{NOTE_CS7, 16},
	{NOTE_CS7, 16},
	{NOTE_CS7, 4},
	{0, 8},
	{NOTE_CS7, 16},
	{NOTE_CS7, 16},
	{NOTE_CS7, 4},
	{0, 8},
	{NOTE_CS7, 16},
	{NOTE_CS7, 16},
	{NOTE_CS7, 4},
	{0, 1},
};	

//create three Melody instances
Melody melody1(MELODY_PIN);
Melody melody2(MELODY_PIN);
Melody melodyAlert(MELODY_PIN);

void setup(){
	//give each instance its notes
	melody1.setNotes(	melody1Notes, 
						sizeof(melody1Notes) / sizeof(melody1Notes[0]));
		
	melody2.setNotes(	melody2Notes, 
						sizeof(melody2Notes) / sizeof(melody2Notes[0]));

	melodyAlert.setNotes(	melodyAlertNotes, 
						sizeof(melodyAlertNotes) / sizeof(melodyAlertNotes[0]));
	
	//play the melodies in succession
	melody1.play();
	delay(1000);

	melody2.play();
	delay(1000);

	//play the alert tune three times
	melodyAlert.play();
	delay(1000);
	melodyAlert.play();
	delay(1000);
	melodyAlert.play();
}

void loop(){
	
}