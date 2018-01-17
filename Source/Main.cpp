/*
 ==============================================================================
 
 This file was auto-generated!
 
 It contains the basic startup code for a Juce application.
 
 ==============================================================================
 */

#include "../JuceLibraryCode/JuceHeader.h"
#include "CalculateSequence.h"
#include "GenerateSequence.h"
#include "ReadFiles.h"
#include "ChordLibrary.h"
#include "RhythmLibrary.h"
#include "PrintFiles.h"
#include <vector>
using std::vector;

//==============================================================================

int main (int argc, char* argv[])
{
    
    ReadFiles readfiles;
    PrintFiles printfile;
    GenerateSequence generateSequence;
    ChordLibrary chordLibrary;
    ChordLibrary::SongProperties chords;
    int songChoice = 2; // see chordLibary.cpp for differnt song choices (1 Giant Steps or 2 LadyBird)
    int songRepeat = 8; // set how many times it goes throug the song
    int totalRhythm = 0;
    int chordCounter = 0; // keeps track of what type of chord is being analysed 0 = min 1 = dominant 2 = maj
    float currentTime = 0;
    int count = 0;
    int previousChordDuration = 0;
    int increment = 0;
    
    Random random;
    
    while (chordCounter < 3)    // Reads each chord and sets the note probabiliites based on the chord
    {
        readfiles.readfile(chordCounter);
        generateSequence.setChordProbabilities(readfiles.sequence.melodicDevicePerChord, chordCounter);
        readfiles.resetCounters();
        chordCounter ++;
    }
    
    chords = chordLibrary.returnChords(songChoice); // chose the song
    totalRhythm =  songRepeat * chords.songLength; // sets the length of the sequence
    generateSequence.generateRhythm(totalRhythm, chords.chordDuration, songRepeat);   // generates the rhythm information for the entire sequence
    
    for (int counter = 0; counter < songRepeat; counter ++) // Generates notes based on the length of the song repeat
    {
        
        while (currentTime < chords.songLength) // Counts round for as long as the duration of the song
        {
            
            if (count + 1 == chords.chordNumber.size()) // if its the last chord
            {
                increment = (chords.chordNumber.size() - 1) * -1; // this makes it so the next chord is the first chord
            }
            else
            {
                increment = 1;  // sets the enxt chord
            }
            
            
            // generates the sequence based on the current chord and its duratiation and key, and the next chord and its key
            
            generateSequence.setNotesInSequence(chords.chordNumber[count], chords.chordDuration[count] + previousChordDuration,chords.key[count], chords.chordNumber[count + increment],chords.key[count + increment]);
            currentTime += chords.chordDuration[count];
            previousChordDuration += chords.chordDuration[count]; // updates the chord duration
            count ++;
        }
        
        currentTime = 0; // re sets counters for the next run through of the song
        count = 0;
    }
    
    
    printfile.PrintFile(generateSequence.sequenceRhythm); // Prints all the note information to a midi files
    
    return 0;
}

