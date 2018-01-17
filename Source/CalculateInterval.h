/*
 ==============================================================================
 
 CalculateInterval.h
 Created: 22 Feb 2017 6:48:32pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"

#ifndef CALCULATEINTERVAL_H_INCLUDED
#define CALCULATEINTERVAL_H_INCLUDED

/**
 Class for calculating the interval relationship between two notes in analysis
 */

class CalculateInterval
{
    
public:
    
    /**
     CalculateInterval constructor
     */
    CalculateInterval();
    
    /**
     CalculateInterval destructor
     */
    ~CalculateInterval();
    
    
    /** Works out the interval realationship between a note and its following note
     
     @param sequenceNotes  an array which contains all the analysed notes
     @param noteCounter  used as the index for the current item in the sequenceNotes array
     
     */
    
    int calculateInterval(Array<int> sequenceNotes, int noteCounter);
    
private:
    
    int diatonicNotes[7] = {0 ,2 ,4 ,5 ,7 ,9 , 11};
    int intervalValues[13] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    int melodicDeviceNumber = -1;
    bool nextNoteScaleDegree = false;
    
};



#endif  // CALCULATEINTERVAL_H_INCLUDED
