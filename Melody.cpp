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

/**
 * Library based on http://arduino.cc/en/Tutorial/Tone
 */

#include "Arduino.h"
#include "Melody.h"
#include <avr/pgmspace.h>

int melodyPin;
int numNotes;
Note *notes_ptr;

Melody::Melody(int melodyPin){
	this->melodyPin = melodyPin;
	this->notes_ptr = NULL;
}

void Melody::setNotes(Note* notes, int numNotes){
	this->notes_ptr = notes;
	this->numNotes = numNotes;
}

void Melody::play(){
	Serial.println("Melody::play");
    // iterate over the notes of the melody:
    for (int noteIndex = 0; noteIndex < this->numNotes; noteIndex++) {
		// to calculate the note duration, take one second 
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / pgm_read_word(&(this->notes_ptr[noteIndex].duration));
		tone(this->melodyPin, pgm_read_word(&(this->notes_ptr[noteIndex].note)), noteDuration);

		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(this->melodyPin);
    }
}

