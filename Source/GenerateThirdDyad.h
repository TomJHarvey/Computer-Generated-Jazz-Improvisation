/*
 ==============================================================================
 
 GenerateThirdDyad.h
 Created: 21 Dec 2016 12:51:38pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"


#ifndef GENERATETHIRDDYAD_H_INCLUDED
#define GENERATETHIRDDYAD_H_INCLUDED

/**
 Class for generating a third interval
 */

class GenerateThirdDyad
{
    
    
public:
    
    
    /**
     GenerateThirdDyad constructor
     */
    
    GenerateThirdDyad();
    
    /**
     GenerateThirdDyad destructor
     */
    
    ~GenerateThirdDyad();
    
    
    /**Calculates the two possible dyads it could be
     
     @param currentNote_ the value of the current note
     @param direction_ the direction the interval should travel
     
     */
    
    int calculateThirdDyad(int currentNote_ , int direction_);
    
    /**Sets the next note a diatonic third in the selected diretcion
     
     @param currentNote_ the value of the current note
     @param dyad_ theinterval to be added to the current note
     
     */
    
    void setThirdDyad(int dyad_[], int currentNote_);
    
    int lastNote = 0;
    Array <int> thirdDyadArray;
    
private:
    
    Random randomDyad;
    int thirdNote = 0;
    
    int thirdDyad[7][2] =   // the different intervals for a third for each note in the major scale
    
    {{0,4},
        {2,5},
        {4,7},
        {5,9},
        {7,11},
        {9,0},
        {11,2}};
};



#endif  // GENERATETHIRDDYAD_H_INCLUDED
