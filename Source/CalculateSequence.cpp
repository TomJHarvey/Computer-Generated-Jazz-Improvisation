/*
 ==============================================================================
 
 CalculateSequence.cpp
 Created: 29 Nov 2016 3:34:14pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "CalculateSequence.h"
#include <stdio.h>

CalculateSequence::CalculateSequence()
{
    
}

CalculateSequence::~CalculateSequence()
{
    
}

void CalculateSequence::addNumber(int note)
{
    sequenceNotes.add(note);
}


void CalculateSequence::calculateSequence()
{
    
    int melodicDeviceNumber = 0;
    
    for (noteCounter = 0; noteCounter < sequenceNotes.size(); noteCounter ++)    // This increments the note counters for each note
    {
        if(endOfSequence[noteCounter] != 0) // If its the last note in the sequence it doesn't check it
            
        {
            melodicDeviceNumber = interval.calculateInterval(sequenceNotes, noteCounter);   // then checks each type of interval
            if (melodicDeviceNumber != -1) // it ignores anything above an octave jump for now
            {
                for (int count = 0; count < 12; count ++)
                {
                    if ((sequenceNotes[noteCounter] - count) % 12 == 0 ) // works out the type of interval
                    {
                        currentNoteValue = count;
                    }
                }
                
                melodicDevicePerChord[currentNoteValue][melodicDeviceNumber] ++; // adds the probability to the array
            }
            
        }
    }
    
    
    
}


