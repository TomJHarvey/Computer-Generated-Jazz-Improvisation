/*
 ==============================================================================
 
 PrintFiles.cpp
 Created: 2 Apr 2017 10:49:56am
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "PrintFiles.h"


PrintFiles::PrintFiles()
{
    
    
    
}
PrintFiles::~PrintFiles()
{
    
    
}

void PrintFiles::PrintFile(GenerateSequence::NoteProperties finalSequence)
{
    
    // Prints to file
    
    std::cout << "SIZE = " << finalSequence.noteNumber.size() << std::endl;
    
    for (int count = 0; count < finalSequence.noteNumber.size(); count ++)
    {
        std::cout << finalSequence.noteNumber[count] << std::endl;
    }
    
    // Encapsulate this to a printing file.
    
    MidiFile mf;                       // create the midi file
    mf.setTicksPerQuarterNote(480);     // sets the ticks per quarter note
    String str = File::getCurrentWorkingDirectory().getFullPathName();  // where the file will go
    str += String("/Ladybird test2") + String(".mid"); // What the songw ill be called, create a new name for each generation
    std::cout << str << "\n";               // print to the console
    File final(str);                            // put everything in str into the file
    int count = 0;
    MidiMessageSequence midiSequence;   // creates sequence
    int sequenceCount = 0;
    count = 0;
    
    while (sequenceCount < finalSequence.noteOff[finalSequence.noteOff.size()-1]) // Adds each note to the sequence
    {
        if (finalSequence.noteNumber[count] != 0) // 0 is a rest, play notes if not a rest
        {
            
            MidiMessage messageOn (0x90 ,finalSequence.noteNumber[count], 127);  // note on, note number, velocity
            messageOn.setTimeStamp(finalSequence.noteOn[count]);              // the time which it will play
            MidiMessage messageOff (0x80, finalSequence.noteNumber[count], 0);   // note off, note number, velocity
            messageOff.setTimeStamp(finalSequence.noteOff[count]);    // The time it will stop
            midiSequence.addEvent(messageOn);
            midiSequence.addEvent(messageOff);
        }
        
        sequenceCount = finalSequence.noteOff[count]; // increment counter by the value of the rest or note
        count ++;
    }
    
    mf.addTrack(midiSequence);                  // adds the sequence to the file
    FileOutputStream fOutputStream (final);     // the output streem is whats in the string
    jassert(!fOutputStream.failedToOpen());
    mf.writeTo(fOutputStream);                  //Write the sequence to the output
    
    
}
