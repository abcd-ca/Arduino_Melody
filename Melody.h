#ifndef Melody_H
#define Melody_H

#include "Note.h"

class Melody {
	public:
		Melody(int melodyPin);
		void setNotes(Note* notes, int numNotes);
		void play();
		
	private:
		int melodyPin;
		int numNotes;
		Note *notes_ptr;
};
#endif //Melody_H