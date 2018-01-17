/*
 ==============================================================================
 
 RhythmLibrary.h
 Created: 11 Mar 2017 8:40:07am
 Author:  Thomas Harvey
 
 ==============================================================================
 */


#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>


#ifndef RHYTHMLIBRARY_H_INCLUDED
#define RHYTHMLIBRARY_H_INCLUDED

/**
 Class for reading MIDI files
 */

class RhythmLibrary
{
public:
    
    /**
     RhythmLibrary destrutor
     */
    RhythmLibrary();
    
    /**
     RhythmLibrary constructor
     */
    
    ~RhythmLibrary();
    
    
    /**
     A structure containing rhythm information used by each of the 40 rhythms
     */
    
    struct RhythmProperties
    {
        Array<int> noteOn; // the time of the note on in MIDI ticks
        Array<int> noteOff; // the time of the note off in MIDI ticks
        Array<int> rest;    // if the note is a rest or not
        int length;         // the amount of notes
        int longRest;       // if it has large rest in it
    };
    
    /**
     Returns the selected rhythm
     
     @param rhythmChoice selects the rhythm
     
     */
    
    RhythmProperties returnRhythm(int rhythmChoice);
    
    
private:
    
    RhythmProperties rhythms[20];
    RhythmProperties rhythms2[20];
    
};



#endif  // RHYTHMLIBRARY_H_INCLUDED
