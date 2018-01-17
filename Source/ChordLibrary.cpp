/*
 ==============================================================================
 
 ChordLibrary.cpp
 Created: 24 Feb 2017 6:55:52pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "ChordLibrary.h"

ChordLibrary::ChordLibrary()
{
    
    // chord number
    //0 = 1maj
    //1 = 2min
    //4 = 5dom
    
    
    // key
    //C = 0
    //C# = 1
    //B = -1
    //G = -5
    //Eb = 3
    
    // duration is in midi ticks
    // length should eqaul all of the values of the chord duration summed
    
    
    giantSteps.chordDuration = {960,960,960,960,1920,960,960,960,960,960,960,1920,960,960,1920,960,960,1920,960,960,1920,960,960,1920, 960,960};
    giantSteps.chordNumber =   {0,  4,  0,  4,  0,   1,  4,  0,  4,  0,  4,  0,   1,  4,  0,   1,  4,  0,   1,  4,  0,   1,  4,  0,    1,  4  };
    giantSteps.key =           {-1, -5, -5,  3,  3,  -5, -5, -5 , 3  ,3, -1, -1,   3,  3,  3,  -5, -5, -5,  -1, -1 ,-1,   3,  3,  3,   -1, -1 };
    giantSteps.songLength = 30720;
    
    ladyBird.chordDuration = {1920, 1920,1920,1920,1920, 1920,1920,1920,1920, 1920,1920,1920,1920,1920,960,960,960,960};
    ladyBird.chordNumber =   {0,    0,    1,   4,   0,    0,   1,   4,   0,    0,   1,   4,   1,   4,   0,  4,  0,  4  };
    ladyBird.key =           {0,    0,    3,   3,   0,    0,  -4  ,-4  ,-4,   -4,  -5,  -5,   0,   0,   0, -4 ,-4 ,-6} ;
    ladyBird.songLength = 30720;
    
    
    twoFiveOneSix.chordDuration = {1920,1920,1920,1920};
    twoFiveOneSix.chordNumber =   {1,  4, 0,  4};
    twoFiveOneSix.key =           {0,   0,  0, 2};
    twoFiveOneSix.songLength = 7680;
    
    twoFiveOne.chordDuration = {1920,1920,1920, 1920};
    twoFiveOne.chordNumber =   {1,   4,   0,    0   };
    twoFiveOne.key =           {0,   0,   0,    0   };
    twoFiveOne.songLength = 7680;
    
    
    twoFiveOne.chordDuration = {1920,1920,1920, 960 , 960};
    twoFiveOne.chordNumber =   {1,   4,   0,    0,     4  };
    twoFiveOne.key =           {0,   0,   0,    0,     0  };
    twoFiveOne.songLength = 7680;
    
    cmaj.chordDuration = {1920,1920,1920, 1920};
    cmaj.chordNumber =   {0,   0,   0,    0   };
    cmaj.key =           {0,   0,   0,    0   };
    cmaj.songLength = 7680;
    
}
ChordLibrary::~ChordLibrary()
{
    
    
    
}


ChordLibrary::SongProperties ChordLibrary::returnChords(int songChoice)
{
    
    if(songChoice == 1)
        return giantSteps;
    if(songChoice == 2)
        return ladyBird;
    if(songChoice == 3)
        return twoFiveOneSix;
    if(songChoice == 4)
        return twoFiveOne;
    if(songChoice == 5)
        return cmaj;
    
    
    
}
