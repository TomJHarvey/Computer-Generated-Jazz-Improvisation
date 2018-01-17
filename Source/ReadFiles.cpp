/*
 ==============================================================================
 
 ReadFiles.cpp
 Created: 23 Feb 2017 8:31:39am
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "ReadFiles.h"




ReadFiles::ReadFiles()
{
  
    ///////// SET THE  FILE PATHS FOR EACH OF TRANSCRIPTIONS WHICH ARE INCLUDED IN THE FOLDER WITH THE MAIN PROJECT
    
    min7Melodies[0] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody1.mid"));
    min7Melodies[1] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody2.mid"));
    min7Melodies[2] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody3.mid"));
    min7Melodies[3] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody4.mid"));
    min7Melodies[4] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody5.mid"));
    min7Melodies[5] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody6.mid"));
    min7Melodies[6] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody7.mid"));
    min7Melodies[7] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody8.mid"));
    min7Melodies[8] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody9.mid"));
    min7Melodies[9] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody10.mid"));
    min7Melodies[10] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody11.mid"));
    min7Melodies[11] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody12.mid"));
    min7Melodies[12] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody13.mid"));
    min7Melodies[13] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody14.mid"));
    min7Melodies[14] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody15.mid"));
    min7Melodies[15] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody16.mid"));
    min7Melodies[16] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody17.mid"));
    min7Melodies[17] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody18.mid"));
    min7Melodies[18] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody19.mid"));
    
    
    maj7Melodies[0] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody1.mid"));
    maj7Melodies[1] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody2.mid"));
    maj7Melodies[2] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody3.mid"));
    maj7Melodies[3] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody4.mid"));
    maj7Melodies[4] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody5.mid"));
    maj7Melodies[5] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody6.mid"));
    maj7Melodies[6] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody7.mid"));
    maj7Melodies[7] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody8.mid"));
    maj7Melodies[8] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody9.mid"));
    maj7Melodies[9] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody10.mid"));
    maj7Melodies[10] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody11.mid"));
    maj7Melodies[11] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody12.mid"));
    maj7Melodies[12] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody13.mid"));
    maj7Melodies[13] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody14.mid"));
    maj7Melodies[14] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody15.mid"));
    maj7Melodies[15] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody16.mid"));
    maj7Melodies[16] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody17.mid"));
    maj7Melodies[17] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody18.mid"));
    maj7Melodies[18] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Maj7/Maj7-1Melody19.mid"));
    
    dom7Melodies[0] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody1.mid"));
    dom7Melodies[1] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody2.mid"));
    dom7Melodies[2] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody3.mid"));
    dom7Melodies[3] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody4.mid"));
    dom7Melodies[4] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody5.mid"));
    dom7Melodies[5] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody6.mid"));
    dom7Melodies[6] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody7.mid"));
    dom7Melodies[7] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody8.mid"));
    dom7Melodies[8] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody9.mid"));
    dom7Melodies[8] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody10.mid"));
    dom7Melodies[9] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody11.mid"));
    dom7Melodies[10] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody12.mid"));
    dom7Melodies[11] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody13.mid"));
    dom7Melodies[12] = File::getCurrentWorkingDirectory().getChildFile (String("/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Dom7/Dom7-1Melody14.mid"));
    
    // More effecient way to read in files, is a work in progress
    
    //
    //    String midiTranscriptionsFilePath = "/Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions";
    //    String minor7FileEnd = "/Min7/Min7-1Melody";
    //    String major7FileEnd = "/Maj7/Maj7-1Melody";
    //    String dom7FileEnd = "/Dom7/Dom7-1Melody";
    //    String currentFile;
    //    String midiFileEnd = ".mid";
    //
    //    for (int count = 0; count < 19; count ++)
    //    {
    //        String Integer(count + 1);
    //        currentFile = midiTranscriptionsFilePath + minor7FileEnd + Integer + midiFileEnd;
    //        min7Melodies[count] = File::getCurrentWorkingDirectory().getChildFile (String(currentFile));
    //    }
    //
    //    for (int count = 0; count < 19; count ++)
    //    {
    //        String Integer(count + 1);
    //        currentFile = midiTranscriptionsFilePath + major7FileEnd + Integer + midiFileEnd;
    //        maj7Melodies[count] = File::getCurrentWorkingDirectory().getChildFile (String(currentFile));
    //    }
    //
    //    for (int count = 0; count < 13; count ++)
    //    {
    //        String Integer(count + 1);
    //        currentFile = midiTranscriptionsFilePath + dom7FileEnd + Integer + midiFileEnd;
    //        dom7Melodies[count] = File::getCurrentWorkingDirectory().getChildFile (String(currentFile));
    //    }
    
    
    }
    
ReadFiles::~ReadFiles()
{
    
    
    
}

void ReadFiles::readfile(int chordCounter)
{
    
    for (int fileCount = 0; fileCount < fileSize[chordCounter]; fileCount ++)
    {
        
        //pass the file into a file input stream
        
        
        if (chordCounter == 0)
        {
            FileInputStream fiStream(min7Melodies[fileCount]);
            jassert(fiStream.openedOk());
            //at this point we fill up our midi file.
            mFile[fileSize[chordCounter]].readFrom(fiStream);
        }
        
        else if (chordCounter == 1)
        {
            FileInputStream fiStream(dom7Melodies[fileCount]);
            jassert(fiStream.openedOk());
            //at this point we fill up our midi file.
            mFile[fileSize[chordCounter]].readFrom(fiStream);
        }
        
        else if (chordCounter == 2)
        {
            FileInputStream fiStream(maj7Melodies[fileCount]);
            jassert(fiStream.openedOk());
            //at this point we fill up our midi file.
            mFile[fileSize[chordCounter]].readFrom(fiStream);
        }
        
        //        FileInputStream fiStream(files[fileCount]);       // test one at a time
        //        jassert(fiStream.openedOk());
        //        //at this point we fill up our midi file.
        //        mFile[fileSize[chordCounter]].readFrom(fiStream);
        //
        const MidiMessageSequence * mSeq = mFile[fileSize[chordCounter]].getTrack(0);
        startOfsequenceCounter = 0;
        
        for (int i = 0; i < mSeq->getNumEvents(); i++)
        {
            const MidiMessageSequence::MidiEventHolder * mms = mSeq->getEventPointer(i);
            
            if(mms->message.isNoteOn()) // counts through and looks at each note on mesage
            {
                
                sequence.addNumber(mms->message.getNoteNumber() + key[chordCounter] );    // Prints all numbers into an array (add +key to determine what chord type is being looked at)
                noteCount ++;
                sequence.endOfSequence.set(noteCount, 1);
            }
            
        }
        sequence.endOfSequence.set(noteCount - 1, 0); // Marks the end of a sequence        //NOTE DATA WILL BE SWITCHED TO OF TYPE CALCULATE SEQUENCE
        
    }
    
    sequence.calculateSequence(); // this is where it works out what the note relationships are
    sequence.sequenceNotes.clear();
    
}


void ReadFiles::resetCounters()
{
    
    for (int counter = 0; counter < 12; counter ++) // re sets the melodic device counter for the next time its used
    {
        for (int count = 0; count < 24; count ++)
        {
            sequence.melodicDevicePerChord[counter][count] = 0;
        }
    }
    
}
