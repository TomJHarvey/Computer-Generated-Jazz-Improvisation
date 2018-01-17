/*
 ==============================================================================
 
 CalculateSequence.h
 Created: 29 Nov 2016 3:34:14pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */
#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>

#include "CalculateInterval.h"




#ifndef CALCULATESEQUENCE_H_INCLUDED
#define CALCULATESEQUENCE_H_INCLUDED

/**
 Class for incrementing the probabilities for notes to follow another
 */

class CalculateSequence
{
public:
    
    /**
     CalculateSequence constructor
     */
    CalculateSequence();
    
    /**
     CalculateSequence destructor
     */
    ~CalculateSequence();
    
    /** Adds a number to the note array
     
     @param note The note to be added
     
     */
    void addNumber(int note);
    
    /** Increments counters for each note to follow another
     */
    
    void calculateSequence();
    
    
    int melodicDevicePerChord[12][24] =
    {{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0},{0}};
    
    Array <int> sequenceNotes;
    Array<int> endOfSequence;
    
private:
    
    int noteCounter;
    int currentNoteValue = 0;
    int diatonicNotes[7] = {0 ,2 ,4 ,5 ,7 ,9 , 11};
    CalculateInterval interval;
    
};





#endif  // CALCULATESEQUENCE_H_INCLUDED
