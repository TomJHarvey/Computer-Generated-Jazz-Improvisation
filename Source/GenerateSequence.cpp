/*
 ==============================================================================
 
 GenerateSequence.cpp
 Created: 23 Feb 2017 8:31:19am
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "GenerateSequence.h"

#include <stdio.h>
GenerateSequence::GenerateSequence()
{
    
    melodicDeviceMinorProbabilities.resize(12);
    melodicDeviceDominantProbabilities.resize(12);
    melodicDeviceMajorProbabilities.resize(12);
    tempVector.resize(12);
    
    
    for (int count = 0; count < 20; count ++)
    {
        for (int counter = 0 ; counter < rhythm1Probabilities[count]; counter ++)
        {
            rhythm1Values.add(count);
        }
    }
    
    std::cout << rhythm1Values.size();
    
}


GenerateSequence::~GenerateSequence()
{
    
    
    
}

void GenerateSequence::generateRhythm(int totalRhythm, Array<int> chordDuration_, int songRepeat)
{
    
    
    
    int rhythmTooLong = 1;
    
    int currentTimestamp = 0;// - chordDuration_[0];
    int counter = 0;
    // sequenceRhythm.firstNoteOfChord.add(1);
    
    for (int count = 0; count < (chordDuration_.size()) * songRepeat; count ++) // creates a new array with timestamps at each chord change
    {
        
        if (counter == chordDuration_.size())
        {
            counter = 0;
        }
        
        currentTimestamp = chordDuration_[counter] + currentTimestamp;
        std::cout << "CHORDS = " << currentTimestamp << std::endl;
        chordTimeStamps.add(currentTimestamp);
        
        counter ++;
    }
    chordCounter = 0;
    
    for (int count = 0 ; count < chordTimeStamps.size(); count ++)
    {
        std::cout << "time stamps = " << chordTimeStamps[count] << std::endl;
    }
    
    while (rhythmCounter < totalRhythm )
    {
        
        if (longRhythmCounter == 0)
        {
            randNum = random.nextInt(340) + 1;
            rhythms = rhythmLibrary.returnRhythm(rhythm1Values[randNum]); // figure out random ranges
        }
        
        if (rhythms.longRest == 1 && longRhythmCounter == 0) // if its a long rhythm
        {
            longRhythmCounter = 1;
        }
        
        else if ( longRhythmCounter > 0)
        {
            longRhythmCounter ++;
            
            while (rhythmTooLong == 1)
            {
                randNum = random.nextInt(340) + 1;
                rhythms = rhythmLibrary.returnRhythm(rhythm1Values[randNum]); // figure out random ranges
                rhythmTooLong = rhythms.longRest;
            }
            
            if (longRhythmCounter == 4)
            {
                longRhythmCounter = 0;
            }
            
            rhythmTooLong = 1;
        }
        
        
        //  rhythms = rhythmLibrary.returnRhythm(0); // Generates specific rhythm for testing
        std::cout << "Length = " << rhythms.length << std::endl;
        
        for (int count = 0; count < rhythms.length; count ++)
        {
            sequenceRhythm.noteOn.add(rhythms.noteOn[count] + previousNoteOff);
            sequenceRhythm.noteOff.add(rhythms.noteOff[count] + previousNoteOff);
            sequenceRhythm.rest.add(rhythms.rest[count]);
            
        }
        
        rhythmCounter += rhythms.noteOff[rhythms.noteOff.size() - 1]; // increment the counter by the total length of the rhythms
        previousNoteOff += rhythms.noteOff[rhythms.noteOff.size() - 1]; // this is the starting time for the next rhythm copied to the array
    }
    
    rhythmCounter = 0;
    
    for (int count = 0; count < sequenceRhythm.noteOn.size(); count ++)
    {
        std::cout <<  count << " Note on  = " << sequenceRhythm.noteOn[count] << std::endl;
        std::cout <<  count << " Note off  = " << sequenceRhythm.noteOff[count] << std::endl;
        std::cout <<  count << " Rest  = " << sequenceRhythm.rest[count] << std::endl;
    }
    
    
    for (int count = 0; count < chordTimeStamps.size(); count ++)
    {
        
        //std::cout <<"Noteon = "<< count << " = " << sequenceRhythm.noteOn[count] << std::endl;
        std::cout <<"Timestamps =  " << count << " = " <<chordTimeStamps[count] << std::endl;
        
    }
    
    
    
}


void GenerateSequence::setNotesInSequence(int chordNumber_, int chordDuration_, int key_, int nextChord_, int nextKey_)
{
    
    key = key_;
    chord = chordNumber_;
    nextChord = nextChord_;
    chordDuration = chordDuration_;
    nextKey = nextKey_;
    // previousNote = previousNote + key;
    
    // std::cout << "Chord number = " << chord << std::endl;
    
    firstTime = true;
    while (sequenceDuration < chordDuration)    // It exits when one bar has been played
    {
        
        if (sequenceRhythm.rest[sequenceCounter] == 1) // if its not a rest
        {
            setDirection();
            setCurrentNote();
        }
        
        else    // fix this only temporary
        {
            sequenceRhythm.noteNumber.add(0);
            testCoutner ++;
        }
        
        sequenceDuration = sequenceRhythm.noteOff[sequenceCounter]; // make this a coutner
        sequenceCounter ++;
        
    }
    
    //firstTime = true;
}

void GenerateSequence::setCurrentNote()
{
    
    // WITHIN THE SPACE OF 8 NOTES IT CAN'T PLAY THE SAME INTERVAL FROM THE SAME NOTES MORE THAN THREE TIMES, AND IT CAN'T IN  A ROW EITHER
    
    int noteValue = 0;;
    bool foundNearestChordTone = false;
    // std::cout << "previous note = " << previousNote << std::endl;
    
    for (int count = 0; count < 12; count ++)
    {
        if (((previousNote - key) - count) % 12 == 0 )
        {
            noteValue = count;
        }
    }
    
    
    if (firstTime == true) // if its the first note on a chord
    {
        std::cout << "First Time" << std::endl;
        findNearestChordTone(chord, key);
        firstTime = false;
        
    }
    
    else    // if its already on a chord
    {
        if (chord  == 1)
        {
            sumOfdevicePointer = sumOfMelodicDeiveMinor;
            tempVector = melodicDeviceMinorProbabilities;
        }
        
        else if (chord  == 4)
        {
            sumOfdevicePointer = sumOfMelodicDeiveDominant;
            tempVector = melodicDeviceDominantProbabilities;
        }
        
        else if (chord  == 0)
        {
            sumOfdevicePointer = sumOfMelodicDeiveMajor;
            tempVector = melodicDeviceMajorProbabilities;
        }
        
        
        
        // if there are no notes in the right direction, find nearest chord tone
        
        seed = sumOfdevicePointer[noteValue];
        if (seed <= 0)
        {
            findNearestChordTone(chord, key);
            firstTime = false;
            DBG("FirstTime");
            
        }
        
        else
        {
            
            randNum = random.nextInt(seed); // how many probabilites are avaialble for the specific tone // figure out random messing up and see if they are the correct size
            randNum = tempVector[noteValue][randNum];
            
            int randNumFinder = 0;
            
            if (direction == -1 && randNum > 11) // if its too high
            {
                while (randNum > 11)
                {
                    randNum = random.nextInt(seed); // how many probabilites are avaialble for the specific tone
                    randNum = tempVector[noteValue][randNum];
                    
                    randNumFinder ++;
                    
                    if (randNumFinder == 5)
                    {
                        findNearestChordTone(chord, key);
                        foundNearestChordTone = true;
                        break;
                    }
                }
                
            }
            
            else if (direction == 1 && randNum < 12) // if its too high
            {
                while (randNum < 12)
                {
                    randNum = random.nextInt(seed); // how many probabilites are avaialble for the specific tone
                    randNum = tempVector[noteValue][randNum];
                    
                    randNumFinder ++;
                    
                    if (randNumFinder == 5)
                    {
                        findNearestChordTone(chord, key);
                        foundNearestChordTone = true;
                        break;
                    }
                }
                
            }
            
            
            if (foundNearestChordTone == false)
            {
                addInterval(randNum);
            }
            
            //  findNearestChordTone();
            
        }
        
        // clears the temporary vector
        
        for (int counter = 0; counter < 12; counter ++)
        {
            // std::cout << " Note = " << counter  << std::endl;
            for (int count = 0; count < sumOfdevicePointer[counter]; count ++)
            {
                tempVector[counter][count] = 0;
            }
        }
        
        for (int count = 0; count < 12; count ++)
        {
            tempVector[count].resize(0);
        }
        
        
        sumOfdevicePointer = nullptr;
        
    }
    
    if (tester == true)
    {
        
        
        
    }
    
    tester = false;
}


void GenerateSequence::findNearestChordTone(int chordNumber_, int key_)
{
    
    int finalIncrement = 0;
    int incrementArray[8] = {-4,-3,-2,-1,1,2,3,4};
    Array<int> foundChordToneArray;
    int chordToneCounter = -1;
    int biggestNote = 10;
    
    for (int count = 0; count < 8; count ++)
    {
        for (int counter = 0; counter < 4; counter ++)
        {
            if (((previousNote + incrementArray[count] ) - chordTones[chordNumber_][counter] - key_ ) % 12 == 0 )
            {
                // adds the two possible chord tones found to the array
                foundChordToneArray.add(incrementArray[count]* chordToneCounter); // the first is negative and made positive
                chordToneCounter =1;
            }
        }
    }
    
    if (direction == -1)    // if its below make it positive temporairly
    {
        finalIncrement = foundChordToneArray[0] * -1;
    }
    
    else if (direction == 1) // if its a negative increment
    {
        finalIncrement = foundChordToneArray[1];
    }
    else
    {
        for (int count = 0; count < 2; count ++)
        {
            if (foundChordToneArray[count] < biggestNote)
            {
                biggestNote = foundChordToneArray[count];
                
                if (count == 0) // if its negative use the first item in the array and times it by -1 to make it negative again
                {
                    finalIncrement = foundChordToneArray[count] * -1;
                }
                
                else    // if its a positive increment
                {
                    finalIncrement = foundChordToneArray[count];
                }
                
            }
            
        }
        
    }
    
    previousNote = previousNote + finalIncrement;
    sequenceRhythm.noteNumber.add(previousNote);
    testCoutner ++;
    
    
}

void GenerateSequence::addInterval(int intervalNumber)
{
    int note;
    
    
    if (intervalNumber < 12)
    {
        note = intervalNumber * -1;
    }
    
    else if (intervalNumber > 12)
    {
        note = intervalNumber - 12;
    }
    
    else if (intervalNumber == 12) // add an octave
    {
        note = 12;
    }
    
    bool isNoteChromatic = true;
    bool foundNearestChordTone = false;
    
    int avoidNote = 0;
    
    for (int count = 0; count < 7 ; count ++)
    {
        if((((previousNote + note) - key) - diatonicNotes[count] ) % 12 == 0)
        {
            isNoteChromatic = false; // Sets the note to be not chromatic
        }
    }
    
    
    
    
    while (sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size() + 1] >= chordTimeStamps[timeStampCounter] && timeStampCounter != chordTimeStamps.size()) // if the next note is
    {
        std::cout << "Note on = " << sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size() + 1] << std::endl;
        std::cout << "Timestamp = " << chordTimeStamps[timeStampCounter] << std::endl;
        std::cout << "Size = " << sequenceRhythm.noteNumber.size() << std::endl;
        timeStampCounter ++; // finds the nearest timestamp
    }
    
    timeStampCounter --;
    
    // std::cout << "REST = " << sequenceRhythm.rest[sequenceRhythm.noteNumber.size() + 1] << std::endl;
    if (sequenceRhythm.rest[sequenceRhythm.noteNumber.size() + 1] == 0) // if the note after is a rest
    {
        
        
        std::cout << "Rest = " << sequenceRhythm.rest[sequenceRhythm.noteNumber.size() + 1] << std::endl;
        
        
        if(sequenceRhythm.noteOff[sequenceRhythm.noteNumber.size()] -
           sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size()] < 480 &&
           sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size() + 1] == chordTimeStamps[timeStampCounter]) // If the current note is smaller than a crotchet and the next note is the first note of a chord
        {
            
            DBG("Right");
            std::cout << "chord number = " << nextChord << std::endl;
            findNearestChordTone(nextChord, nextKey); // find the nearest chord tone of the next chord if
            foundNearestChordTone = true;
            tester = true;
            
            
        }
        
        else// if the next note is just a rest, end on a chord tone
        {
            
            DBG("WRONG");
            findNearestChordTone(chord, key);
            foundNearestChordTone = true;
        }
        
        
        
    }
    
    int increment = 0;
    
    // if the note is chromatic check to see if its on a weak beat
    
    if(isNoteChromatic == true && foundNearestChordTone == false)
    {
        
        // std::cout << sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size()] << " / 480 =  " << sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size()] / 480 <<  std::endl;
        
        if(sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size()] % 480 == 0) // if its on a weak beat
        {
            
            if (note < 1)       // makes it in key because every note is one note away from being in key
            {
                note = note - 1;
            }
            
            else if (note > 0)
            {
                note = note + 1;
            }
            
            DBG("Weak");
        }
        
    }
    
    
    else if ((chord == 0 || chord == 4 ) && foundNearestChordTone == false)  // if its a major or dominant chord which both have avoid notes
    {
        
        if (chord == 0)
        {
            avoidNote = majorAvoidNote;
        }
        if (chord == 4)
        {
            avoidNote = dominantAvoidNote;
        }
        
        
        if(sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size()] % 480 == 0) // if its on a strong beat
        {
            std::cout << "current note = " << sequenceRhythm.noteNumber[sequenceRhythm.noteNumber.size()] << std::endl;
            
            if (((previousNote + note) - key - avoidNote) % 12 == 0) // if its an 4th on a maj
            {
                if (note < 1)       // makes it in key because every note is one note away from being in key
                {
                    note = note -1;
                    increment = -1;
                }
                
                else if (note > 0)
                {
                    note = note +1;
                    increment = 1;
                }
                
                isNoteChromatic = true;
                for (int count = 0; count < 7 ; count ++)
                {
                    if((((previousNote + note) - key) - diatonicNotes[count] ) % 12 == 0)
                    {
                        isNoteChromatic = false; // Sets the note to be not chromatic
                    }
                }
                
                if (isNoteChromatic == true)
                {
                    note = note + increment;
                }
                
            }
            
            
        }
    }
    //
    //
    // the note wont before on a weak beat if its chromatic but it now might be too big, so now it will be resized
    if(sequenceRhythm.noteOff[sequenceRhythm.noteNumber.size() -1] - sequenceRhythm.noteOn[sequenceRhythm.noteNumber.size() - 1] <= 120 && foundNearestChordTone == false) // if its smaller or equal to a sixteenth note
    {
        
        int intervalDirection = 0;
        int multiplier = 0;
        
        if (note < 1)   // decending
        {
            intervalDirection = 0;
            note = note * -1; // makes the interval positive
        }
        else        // accending
        {
            intervalDirection = 1;
            multiplier = 1;
        }
        
        
        std::cout << "current note = " << sequenceRhythm.noteNumber[sequenceRhythm.noteNumber.size() -1] << std::endl;
        
        if (note > 4) // if its bigger than a major third
        {
            note = thirdDyad.calculateThirdDyad(previousNote, intervalDirection);
        }
        
        // if the interval between them is bigger than a third ( so bigger than 4)
    }
    
    if (foundNearestChordTone == false) // if its hasn't gone to find the nearest chord tone add the note to the array.
    {
        sequenceRhythm.noteNumber.add(note + previousNote);
        previousNote = note + previousNote;
        testCoutner ++;
    }
    
}

void GenerateSequence::setDirection()
{
    
    if (previousNote < 60) // Sets the lowest limit for notes
    {
        direction = 1;
    }
    
    else if (previousNote > 84) // sets the upper limit for notes
    {
        direction = -1;
    }
    
    else    // remains at 0 if it hasn't exceeded either of these two
    {
        direction = 0;
    }
}



void GenerateSequence::setChordProbabilities(int melodicDevicePerChord[12][24], int chord)
{
    
    int vectorCounter = 0;
    
    if (chord  == 0)    // set the pointer to change the sum of values
    {
        sumOfdevicePointer = sumOfMelodicDeiveMinor;
    }
    
    else if (chord  == 1)
    {
        sumOfdevicePointer = sumOfMelodicDeiveDominant;
    }
    
    else if (chord  == 2)
    {
        sumOfdevicePointer = sumOfMelodicDeiveMajor;
    }
    
    for (int counter = 0; counter < 12; counter ++) // sets how many different notes follow a note for each chord
    {
        for (int count = 0; count < 24; count ++)
        {
            if (melodicDevicePerChord [counter][count] != 0)
            {
                sumOfdevicePointer[counter] += melodicDevicePerChord[counter][count];
            }
        }
    }
    
    for (int count = 0; count < 12; count ++)   // sets the amount of possibilites for a note to follow another for each chord
    {
        tempVector[count].resize(sumOfdevicePointer[count]);
    }
    
    for (int counter = 0; counter < 12; counter ++)
    {
        for (int count = 0; count < 24; count ++)
        {
            if(melodicDevicePerChord[counter][count] != 0  && sumOfdevicePointer[counter] != 0)
            {
                for (int count2 = 1; count2 <= melodicDevicePerChord[counter][count] ; count2 ++)
                {
                    tempVector[counter][vectorCounter] = count;
                    // std::cout << vectorCounter <<  " :Chord probabilities = " << tempVector[counter][vectorCounter] << std::endl;
                    vectorCounter ++;
                }
            }
        }
        vectorCounter = 0;
    }
    
    
    // Copies the temporary values into the aprotiate chord vector.
    
    if (chord == 0)
    {
        melodicDeviceMinorProbabilities = tempVector;
    }
    
    if (chord == 1)
    {
        melodicDeviceDominantProbabilities = tempVector;
    }
    
    if (chord == 2)
    {
        melodicDeviceMajorProbabilities = tempVector;
    }
    
    // clears the temporary vector
    
    for (int counter = 0; counter < 12; counter ++)
    {
        for (int count = 0; count < sumOfdevicePointer[counter]; count ++)
        {
            tempVector[counter][count] = 0;
        }
    }
    
    for (int count = 0; count < 12; count ++)
    {
        tempVector[count].resize(0);
    }
    
    sumOfdevicePointer = nullptr;
}

