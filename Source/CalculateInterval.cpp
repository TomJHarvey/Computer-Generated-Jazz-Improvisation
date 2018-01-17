/*
 ==============================================================================
 
 CalculateInterval.cpp
 Created: 22 Feb 2017 6:48:32pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "CalculateInterval.h"


CalculateInterval::CalculateInterval()
{
    
}

CalculateInterval::~CalculateInterval()
{
    
}

int CalculateInterval::calculateInterval(Array<int> sequenceNotes, int noteCounter)
{
    
    int intervalSum = sequenceNotes[noteCounter] - sequenceNotes[noteCounter + 1]; // Calculates the interval relationships between it and the next note
    
    if (intervalSum >= 0)   // if its a positive the array values match up
    {
        melodicDeviceNumber = intervalValues[intervalSum];
    }
    
    else if (intervalSum < 0 )  // this makes the values positive then wraps the array around
    {
        melodicDeviceNumber = intervalValues[intervalSum * -1] + 12;
    }
    
    else    // if it doesn't fit into the category of either
    {
        melodicDeviceNumber = -1;
    }
    
    return melodicDeviceNumber;
}
