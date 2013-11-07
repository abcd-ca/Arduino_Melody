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

