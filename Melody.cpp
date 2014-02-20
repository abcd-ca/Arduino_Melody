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

Melody::Melody(int melodyPin) : 
								_melodyPin(melodyPin), 
								_playing(false),
								_noteIndex(0){
}

void Melody::setNotes(Note* notes, int numNotes){
	_notes_ptr = notes;
	_numNotes = numNotes;
}

/**
 * Have your main .ino file call this loop() in its own loop(). Instead of using timers. 
 * Timers could be preferred but you may not want your music to take priority over whatever
 * else is going on in the loop. 
 * //TODO make it work with hardware timer also, user configurable hardware timer vs loop fn
 */
void Melody::loop(){
	if (_playing && millis() - _lastTimeMS >= _restDuration){
		_lastTimeMS = millis();
		
		if (_noteIndex < _numNotes){
			_nextNote();
		}else{
			_noteIndex = 0;
			noTone(_melodyPin);
			_playing = false;
			Serial.println(F("Melody done."));
		}
	}
}

void Melody::start(){
	Serial.print(F("melody pin: ")); Serial.println(_melodyPin);
	Serial.println("Starting melody");
	_playing = true;
	_noteIndex = 0;
	_lastTimeMS = millis();
	_nextNote();
}

void Melody::_nextNote(){
	Serial.println(F("next note playing"));
	// to calculate the note duration, take one second 
	// divided by the note type.
	//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
	_noteDuration = 1000 / pgm_read_word(&(_notes_ptr[_noteIndex].duration));
	Serial.print(F("Note: ")); Serial.println(pgm_read_word(&(_notes_ptr[_noteIndex].note)));
	tone(_melodyPin, pgm_read_word(&(_notes_ptr[_noteIndex].note)), _noteDuration);
	
	// to distinguish the notes, set a minimum time between them.
	// the note's duration + 30% seems to work well:
	_restDuration = _noteDuration * 1.30;
	_noteIndex++;
}

