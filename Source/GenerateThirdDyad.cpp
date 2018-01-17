/*
 ==============================================================================
 
 GenerateThirdDyad.cpp
 Created: 21 Dec 2016 12:51:38pm
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "GenerateThirdDyad.h"

GenerateThirdDyad::GenerateThirdDyad()
{
    
    
}
GenerateThirdDyad::~GenerateThirdDyad()
{
    
    
    
}

int GenerateThirdDyad::calculateThirdDyad(int currentNote_ , int direction_)
{
    
    // Which dyads contain this note?
    // Out of the two, which is the most popular on a minor chord?
    
    
    int dyad1[2] = {0}; // first element is which dyad it is 0-6
    int dyad2[2] = {0}; // second element is : 0 = 1st , 1 = 3rd
    bool checkDyad = false;
    
    
    
    for (int count = 0; count < 7; count ++)
    {
        for (int counter = 0 ; counter < 2; counter ++)
        {
            
            if ((currentNote_ - thirdDyad[count][counter] ) % 12 == 0)
            {
                
                if(checkDyad == false)  // If its not found a dyad
                {
                    dyad1[0] = count;       // set the dyad number
                    dyad1[1] = counter;     // set the position: 1st or 3rd
                    checkDyad = true;
                }
                
                
                else if(checkDyad == true)   // If it has found a dyad
                {
                    dyad2[0] = count;
                    dyad2[1] = counter;
                    checkDyad = true;
                }
            }
            
        }
        
    }
    
    // randomly chose which dyad baed on which is more popular on the selected chord
    
    // dyadChoice = randomDyad.nextInt(2);
    
    
    if (direction_ == 1)    // accend or decend // pass this through the function
    {
        setThirdDyad(dyad1, currentNote_);    // with current note as root
    }
    else if (direction_ == 0)
    {
        setThirdDyad(dyad2, currentNote_);    // with current note as third
    }
    
    return thirdNote; // return an int as the next note
    
}

void GenerateThirdDyad::setThirdDyad(int dyad_[], int currentNote_)
{
    int nextNote = 0;
    int i = 0;
    
    if (dyad_[0] == 5 || dyad_[1] == 6) // if the triad numver is 5 or 6, adds 12 to the third to make it bigger than the first
    {
        i = 12;
    }
    
    if (dyad_[1] == 0) // If this is the root, accend
    {
        nextNote += (thirdDyad[dyad_[0]][1] + i)- thirdDyad[dyad_[0]][0];   // This works out the third - the first to work out if its major or minor
        //nextNote += currentNote_;
    }
    
    else if (dyad_[1] == 1) // If this is the third, decend
    {
        nextNote += (thirdDyad[dyad_[0]][0] + i)- thirdDyad[dyad_[0]][1];
        // nextNote += currentNote_;
    }
    
    thirdNote = nextNote;
    
}
