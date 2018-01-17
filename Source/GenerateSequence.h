/*
 ==============================================================================
 
 GenerateSequence.h
 Created: 23 Feb 2017 8:31:19am
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include <stdio.h>
#include "RhythmLibrary.h"
#include <vector>
#include "GenerateThirdDyad.h"
using std::vector;

#ifndef GENERATESEQUENCE_H_INCLUDED
#define GENERATESEQUENCE_H_INCLUDED

/**
 Class for generating the pitch and rhythm information for a sequence
 */

class GenerateSequence
{
    
public:
    
    
    /**
     GenerateSequence constructor
     */
    GenerateSequence();
    /**
     GenerateSequence destructor
     */
    ~GenerateSequence();
    
    
    /** Sets the pitch values in the sequence based on the current time position of the previous note and on the properties of the song
     
     @param chordNumber_ the number of the current chord which determines its chord type, e.g maj7, min7, dom7
     @param chordDuration_ the length of the current chord in MIDI ticks
     @param key_ the key of the current chord
     @paeam nextChord_ the number of the next chord which determines its chord type
     @param nextKey_ the key of the next chord
     
     */
    
    void setNotesInSequence(int chordNumber_, int chordDuration_, int key_, int nextChord_, int nextKey_);
    
    /**
     Sets the direction of the notes if the previous note is out of the set range
     */
    
    void setDirection();
    
    /**
     Randomly chooses a value based off the chord type or chooses findNearestChordTone()
     */
    void setCurrentNote();
    
    /**Finds the nearest chord tone to the previous note in the selected key
     
     @param chordNumber_ the number of the current chord which determines its chord type, e.g maj7, min7, dom7
     @param key_ the key of the current chord
     
     */
    void findNearestChordTone(int chordNumber_, int key_);
    
    /** Adds the randomly selected interval
     
     @param intervalNumber the randomly selected interval to add
     
     */
    void addInterval(int intervalNumber);
    
    /** Sets the probabilities for each chord type
     
     @param melodicDevicePerChord contains the information for what interval follows each note
     
     */
    void setChordProbabilities(int melodicDevicePerChord[12][24], int chord);
    
    /** Generates the rhythm for the entire sequence
     
     @param totalRhythm the entire length of the sequence
     @param chordDuration the length of each chord in an array
     @param songRepeat how often the entire chord sequence is repeated
     
     */
    
    void generateRhythm(int totalRhythm, Array<int> chordDuration_, int songRepeat);
    
    /**
     Structure used for storing all the note information per note for the final sequence
     */
    
    struct NoteProperties
    {
        
        Array<int> noteNumber; // the midi note number
        Array<int> noteOn;     // its note on value in midi ticks
        Array<int> noteOff;     // its note off value in midi ticks
        Array<int> rest;        // if its a rest or note
        Array<int> firstNoteOfChord; // 1 means it is, 0 means everything else
        Array<int> barPosition;     // its position in the bar
        
    };
    
    Random random;
    
    Array<int> finalSequence;
    int firstTimeCount = 0;
    
    GenerateSequence::NoteProperties sequenceRhythm; // the skeloton rhythm for the entire sequence
    
private:
    
    
    bool firstTime = true;
    bool firstNote = false;
    int chordDuration;
    int chord = 0;
    int nextChord = 0;
    int nextKey = 0;
    
    Array<int> chordTimeStamps;
    int chordCounter = 0;
    
    int diatonicNotes[7] = {0 ,2 ,4 ,5 ,7 ,9 , 11};
    
    int direction = 0;
    int randNum = 0;
    int sequenceDuration = 0;
    
    int sequenceCounter = 0;
    int key = 0;
    
    int testCoutner = 0;
    
    int sumOfMelodicDeiveMinor[12] = {0};
    int sumOfMelodicDeiveDominant[12] = {0};
    int sumOfMelodicDeiveMajor[12] = {0};
    
    
    int* sumOfdevicePointer = nullptr;
    
    vector<vector<int> >* probabilityPointer = nullptr;
    
    vector<vector<int> > melodicDeviceMinorProbabilities;
    vector<vector<int> > melodicDeviceDominantProbabilities;
    vector<vector<int> > melodicDeviceMajorProbabilities;
    
    vector<vector<int> > tempVector;
    
    
    
    int minorVectorCounter = 0;
    int previousNote = 72;
    
    int chordTones[5][5] ={
        
        {0,4,7,11,12}, // Major1
        {2,5,9,0,12},   //Minor2
        {7,11,2,5,14},
        {7,11,2,5,14} ,
        {7,11,2,5,14}}; //Dominant5
    
    int seed = 0;
    
    int dominantAvoidNote = 0;
    int majorAvoidNote = 5;
    
    int rhythmCounter = 0;
    int previousNoteOff = 0;
    
    Array<int> rhythm1Values;
    
    int rhythm1Probabilities[20] = {
        123,
        78,
        13,
        13,
        8,
        8,
        8,
        8,
        8,
        7,
        7,
        7,
        7,
        7,
        7,
        7,
        6,
        6,
        6,
        6};
    
    RhythmLibrary rhythmLibrary;    // Used to call the function to select what rhythm
    RhythmLibrary::RhythmProperties rhythms;    // Used to store the retrived rythm
    
    
    GenerateThirdDyad thirdDyad;
    
    int longRhythmCounter = 0;
    int chromaticCounter = 0;
    int timeStampCounter = 0;
    
    bool tester = false;
    
};




#endif  // GENERATESEQUENCE_H_INCLUDED
