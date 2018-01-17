/*
 ==============================================================================
 
 ChordLibrary.h
 Created: 24 Feb 2017 6:55:52pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */
#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>

#ifndef CHORDLIBRARY_H_INCLUDED
#define CHORDLIBRARY_H_INCLUDED


/**
 Class for storing the information and blueprint for songs
 */

class ChordLibrary
{
public:
    
    /**
     ChordLibrary constructor
     */
    ChordLibrary();
    
    /**
     ChordLibrary destructor
     */
    ~ChordLibrary();
    
    
    /**
     Structure used for storing the chord, timing, key and length for songs
     */
    
    struct SongProperties
    {
        Array<int> chordDuration; // how long each chord lasts in ticks
        Array<int> chordNumber; // what number it is within the scale
        Array<int> key;         // if the chord needs to be transposed
        int songLength;         // song length in miliseconds
    };
    
    
    /** Used to select a song from the chord library
     @param songChoice the number of the song to be used
     */
    SongProperties returnChords(int songChoice);
    
private:
    
    SongProperties giantSteps;
    SongProperties ladyBird;
    SongProperties twoFiveOneSix;
    SongProperties twoFiveOne;
    SongProperties cmaj;
    
};



#endif  // CHORDLIBRARY_H_INCLUDED
