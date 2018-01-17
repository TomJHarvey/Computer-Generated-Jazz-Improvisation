/*
 ==============================================================================
 
 ReadFiles.h
 Created: 23 Feb 2017 8:31:39am
 Author:  Thomas Harvey
 
 ==============================================================================
 */


#include <stdio.h>
#include "../JuceLibraryCode/JuceHeader.h"
#include "CalculateSequence.h"

#ifndef READFILES_H_INCLUDED
#define READFILES_H_INCLUDED


/**
 Class for reading MIDI files
 */
class ReadFiles
{
public:
    
    /**
     ReadFiles constructor
     */
    
    ReadFiles();
    
    /**
     ReadFiles destructor
     */
    
    ~ReadFiles();
    
    /** Reads a group of  MIDI files containing meldodies for a type of chord
     
     @param chordCounter the number of the type chord that is to be read
     
     */
    
    void readfile(int chordCounter);
    
    /**
     Resets all array counters for the next chord
     */
    void resetCounters();
    
    CalculateSequence sequence;
    
private:
    
    int fileSize[4] = {19,13,19,0} ;// how many files for each chord // CHANGE 1 BACK TO 17
    int key[4] = {2,-5,0,0};
    int noteCount = 0;
    int startOfsequenceCounter = 0;
    
    MidiFile mFile[50];
    File maj7Melodies[19]; // Number of files to read from
    File min7Melodies[19];
    File dom7Melodies[13];
    File files[4];
    
};



#endif  // READFILES_H_INCLUDED
