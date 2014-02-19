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

#ifndef Melody_H
#define Melody_H

#include "Arduino.h"
#include "Note.h"

class Melody {
	public:
		Melody(int melodyPin);
		void loop();
		void setNotes(Note* notes, int numNotes);
		void start();
		
	private:
		void _nextNote();
		
		int _melodyPin;
		int _numNotes;
		Note *_notes_ptr;
		unsigned long _lastTimeMS;
		int _noteDuration;
		int _restDuration;
		boolean _playing;
		int _noteIndex;
};
#endif //Melody_H