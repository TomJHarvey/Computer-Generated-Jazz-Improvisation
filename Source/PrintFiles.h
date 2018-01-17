/*
 ==============================================================================
 
 PrintFiles.h
 Created: 2 Apr 2017 10:49:56am
 Author:  Thomas Harvey
 
 ==============================================================================
 */


#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>
#include "GenerateSequence.h"

#ifndef PRINTFILES_H_INCLUDED
#define PRINTFILES_H_INCLUDED


/**
 Class for Printing the generated sequence to a MIDI file
 */

class PrintFiles
{
    
public:
    
    /**
     PrintFiles constructor
     */
    PrintFiles();
    
    /**
     PrintFiles destructor
     */
    
    ~PrintFiles();
    
    /**Prints the final sequence to a MIDI file
     
     @param finalSequence a structure containing all the note information to be printed as a MIDI file
     
     */
    
    void PrintFile(GenerateSequence::NoteProperties finalSequence);
    
private:
    
};



#endif  // PRINTFILES_H_INCLUDED
