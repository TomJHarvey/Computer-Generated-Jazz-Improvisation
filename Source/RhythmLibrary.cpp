/*
 ==============================================================================
 
 RhythmLibrary.cpp
 Created: 11 Mar 2017 8:40:07am
 Author:  Thomas Harvey
 
 ==============================================================================
 */

#include "RhythmLibrary.h"


RhythmLibrary::RhythmLibrary()
{
    
    
    //1
    rhythms[0].noteOn =     {0,   320, 480, 800, 960,  1280, 1440, 1760};
    rhythms[0].noteOff =    {320, 480, 800, 960, 1280, 1440, 1760, 1920};
    rhythms[0].rest =       {1,   1,   1,   1,   1,    1,    1,    1};
    rhythms[0].length = 8;
    rhythms[0].longRest = 0;
    
    //2
    rhythms[1].noteOn =     {0};
    rhythms[1].noteOff =    {1920};
    rhythms[1].rest =       {0};
    rhythms[1].length = 1;
    rhythms[1].longRest = 1;
    
    //3
    rhythms[2].noteOn =     {0,   960,  1280, 1440, 1760};
    rhythms[2].noteOff =    {960, 1280, 1440, 1760, 1920};
    rhythms[2].rest =       {0,   1,    1,    1,    1};
    rhythms[2].length = 5;
    rhythms[2].longRest = 1;
    
    //4
    rhythms[3].noteOn =     {0,   320, 480, 640, 800,  960,  1280, 1440, 1760};
    rhythms[3].noteOff =    {320, 480, 640, 800, 960 , 1280, 1440, 1760, 1920};
    rhythms[3].rest =       {1,   1,   1,   1,   1,    1,    1,    1,    1   };
    rhythms[3].length = 9;
    rhythms[3].longRest = 0;
    
    //5
    rhythms[4].noteOn =     {0,   320, 960 };
    rhythms[4].noteOff =    {320, 960, 1920};
    rhythms[4].rest =       {1,   1,   0   };
    rhythms[4].length = 3;
    rhythms[2].longRest = 1;
    
    //6
    rhythms[5].noteOn =     {0,   720, 960,  1280, 1440, 1760};
    rhythms[5].noteOff =    {720, 880, 1280, 1440, 1760, 1920};
    rhythms[5].rest =       {0,   1,   1,    1,    1,    1   };
    rhythms[5].length = 6;
    rhythms[5].longRest = 1;
    
    //7
    rhythms[6].noteOn =     {0,   320, 480, 800, 960,  1440, 1760};
    rhythms[6].noteOff =    {320, 480, 800, 960, 1440, 1760, 1920};
    rhythms[6].rest =       {1,   1,   1,   1,   1,    1,    1   };
    rhythms[6].length = 7;
    rhythms[6].longRest = 0;
    
    //8
    rhythms[7].noteOn =     {0,   320, 480 };
    rhythms[7].noteOff =    {320, 480, 1920};
    rhythms[7].rest =       {1,   1,   0   };
    rhythms[7].length = 3;
    rhythms[7].longRest = 1;
    
    //9
    rhythms[8].noteOn =     {0,   320, 480, 640, 800,  960,  1280, 1440, 1760};
    rhythms[8].noteOff =    {320, 480, 640, 800, 960 , 1280, 1440, 1760, 1920};
    rhythms[8].rest =       {0,   1,   1,   1,   1,    1,    1,    1,    1   };
    rhythms[8].length = 9;
    rhythms[8].longRest = 0;
    
    //10
    rhythms[9].noteOn =     {0,    1760};
    rhythms[9].noteOff =    {1760, 1920};
    rhythms[9].rest =       {0,    1   };
    rhythms[9].length = 2;
    rhythms[9].longRest = 1;
    
    //11
    rhythms[10].noteOn =     {0,   120, 240, 360, 480, 600, 720, 840, 960,  1080, 1200, 1320, 1440, 1560, 1680, 1800};
    rhythms[10].noteOff =    {120, 240, 360, 480, 600, 720, 840, 960, 1080, 1200, 1320, 1440, 1560, 1680, 1800, 1920};
    rhythms[10].rest =       {1,   1,   1,   1,   1,   1,   1,   1,   1,    1,    1,    1,    1,    1,    1,    1   };
    rhythms[10].length = 16;
    rhythms[10].longRest = 0;
    
    //12
    rhythms[11].noteOn =     {0,   320, 480, 800, 960,  1440};
    rhythms[11].noteOff =    {320, 480, 800, 960, 1440, 1920};
    rhythms[11].rest =       {1,   1,   1,   1,   1,    0,  };
    rhythms[11].length = 6;
    rhythms[11].longRest = 0;
    
    //13
    rhythms[12].noteOn =     {0,    1280,   1440, 1760};
    rhythms[12].noteOff =    {1280, 1440,   1760, 1920};
    rhythms[12].rest =       {0,    1,      1,    1,  };
    rhythms[12].length = 4;
    rhythms[12].longRest = 1;
    
    //14
    rhythms[13].noteOn =     {0,   320, 480, 800, 960,  1280, 1440, 1760};
    rhythms[13].noteOff =    {320, 480, 800, 960, 1280, 1440, 1760, 1920};
    rhythms[13].rest =       {1,   1,   0,   1,   1,    1,    1,    1};
    rhythms[13].length = 8;
    rhythms[13].longRest = 0;
    
    //15
    rhythms[14].noteOn =     {0,    480 };
    rhythms[14].noteOff =    {480,  1920};
    rhythms[14].rest =       {1,    0   };
    rhythms[14].length = 2;
    rhythms[14].longRest = 1;
    
    
    //16
    rhythms[15].noteOn =     {0,   160, 320, 480, 800, 960,  1280, 1440, 1760};
    rhythms[15].noteOff =    {160, 320, 480, 800, 960, 1280, 1440, 1760, 1920};
    rhythms[15].rest =       {1,   1,   1,   1,   1,   1,    1,    1,    1   };
    rhythms[15].length = 9;
    rhythms[15].longRest = 0;
    
    //17
    rhythms[16].noteOn =     {0,   480, 800, 960,  1280, 1440, 1760};
    rhythms[16].noteOff =    {480, 800, 960, 1280, 1440, 1760, 1920};
    rhythms[16].rest =       {1,   1,   1,   1,    1,    1,    1   };
    rhythms[16].length = 7;
    rhythms[16].longRest = 0;
    
    //18
    rhythms[17].noteOn =     {0,   320, 480, 800, 960,  1040, 1120, 1200, 1440, 1760};
    rhythms[17].noteOff =    {320, 480, 800, 960, 1040, 1120, 1200, 1440, 1760, 1920};
    rhythms[17].rest =       {1,   1,   1,   1,   1,    1,    1,    1,    1,    1   };
    rhythms[17].length = 10;
    rhythms[17].longRest = 0;
    
    //19
    rhythms[18].noteOn =     {0,   320, 480, 600, 720, 840, 960,  1280, 1440, 1760};
    rhythms[18].noteOff =    {320, 480, 600, 720, 840, 960, 1280, 1440, 1760, 1920};
    rhythms[18].rest =       {0,   1,   1,   1,   1,   1,   1,    1,    1,    1   };
    rhythms[18].length = 10;
    rhythms[18].longRest = 0;
    
    //20
    rhythms[19].noteOn =     {0,   320, 480,  960,  1280, 1440, 1760};
    rhythms[19].noteOff =    {320, 480, 960,  1280, 1440, 1760, 1920};
    rhythms[19].rest =       {1,   1,   1,    1,    1,    1,    1   };
    rhythms[19].length = 7;
    rhythms[19].longRest = 0;
    
    //1
    rhythms2[0].noteOn =     {0,   320, 480, 800};
    rhythms2[0].noteOff =    {320, 480, 800, 960};
    rhythms2[0].rest =       {1,   1,   1,   1  };
    rhythms2[0].length = 4;
    
    
    //2
    rhythms2[1].noteOn =     {0};
    rhythms2[1].noteOff =    {960};
    rhythms2[1].rest =       {0};
    rhythms2[1].length = 1;
    
    
    
    //3
    rhythms2[2].noteOn =     {0,   320};
    rhythms2[2].noteOff =    {320, 960};
    rhythms2[2].rest =       {1,   1}  ;
    rhythms2[2].length = 2;
    
    
    //4
    rhythms2[3].noteOn =     {0,    800};
    rhythms2[3].noteOff =    {800,  960};
    rhythms2[3].rest =       {0,    1  };
    rhythms2[3].length = 2;
    
    
    //5
    rhythms2[4].noteOn =     {0,   320, 480, 800};
    rhythms2[4].noteOff =    {320, 480, 800, 960};
    rhythms2[4].rest =       {0,   1,   1,   1  };
    rhythms2[4].length = 4;
    
    
    //6
    rhythms2[5].noteOn =     {0,    480, 800};
    rhythms2[5].noteOff =    {480,  800, 960};
    rhythms2[5].rest =       {1,    1,   1  };
    rhythms2[5].length = 3;
    
    
    //7
    rhythms2[6].noteOn =     {0,    480, 800};
    rhythms2[6].noteOff =    {480,  800, 960};
    rhythms2[6].rest =       {0,    1,   1  };
    rhythms2[6].length = 3;
    
    //8
    rhythms2[7].noteOn =     {0,   320, 480};
    rhythms2[7].noteOff =    {320, 480, 960};
    rhythms2[7].rest =       {1,   1,   0, };
    rhythms2[7].length = 3;
    
    //9
    rhythms2[8].noteOn =     {0,   320, 480, 640, 800};
    rhythms2[8].noteOff =    {320, 480, 640, 800, 960};
    rhythms2[8].rest =       {1,   1,   1,   1,   1, };
    rhythms2[8].length = 5;
    
    //10
    rhythms2[9].noteOn =     {0,   480};
    rhythms2[9].noteOff =    {480, 960};
    rhythms2[9].rest =       {1,   0  };
    rhythms2[9].length = 2;
    
    //11
    rhythms[10].noteOn =     {0,   120, 240, 360, 480, 600, 720, 840};
    rhythms[10].noteOff =    {120, 240, 360, 480, 600, 720, 840, 960};
    rhythms[10].rest =       {1,   1,   1,   1,   1,   1,   1,   1, };
    rhythms[10].length = 8;
    
    //12
    rhythms2[11].noteOn =     {0,   480};
    rhythms2[11].noteOff =    {480, 960};
    rhythms2[11].rest =       {0,   1 };
    rhythms2[11].length = 2;
    
    //13
    rhythms2[12].noteOn =     {0,   320, 480, 640, 800};
    rhythms2[12].noteOff =    {320, 480, 640, 800, 960};
    rhythms2[12].rest =       {0,   1,   1,   1,   1, };
    rhythms2[12].length = 5;
    
    //14
    rhythms2[13].noteOn =     {0,   320, 480};
    rhythms2[13].noteOff =    {320, 480, 960};
    rhythms2[13].rest =       {1,   1,   1, };
    rhythms2[13].length = 3;
    
    //15
    rhythms2[14].noteOn =     {0,   160, 320, 480, 800};
    rhythms2[14].noteOff =    {160, 320, 480, 800, 960};
    rhythms2[14].rest =       {1,   1,   1,   1,   1  };
    rhythms2[14].length = 5;
    
    //16
    rhythms2[15].noteOn =     {0,   320, 480, 800};
    rhythms2[15].noteOff =    {320, 480, 800, 960};
    rhythms2[15].rest =       {1,   1,   0,   1  };
    rhythms2[15].length = 4;
    
    //17
    rhythms2[16].noteOn =     {0,   80,  240, 320, 480, 800};
    rhythms2[16].noteOff =    {80,  160, 320, 480, 800, 960};
    rhythms2[16].rest =       {1,   1,   1,   1,   1,   1, };
    rhythms2[16].length = 6;
    
    
    //18
    rhythms2[17].noteOn =     {0,   320, 480, 800};
    rhythms2[17].noteOff =    {320, 480, 800, 960};
    rhythms2[17].rest =       {0,   1,   0,   1  };
    rhythms2[17].length = 4;
    
    //19
    rhythms2[18].noteOn =     {0,   320};
    rhythms2[18].noteOff =    {320, 960};
    rhythms2[18].rest =       {0,   1}  ;
    rhythms2[18].length = 2;
    
    //20
    rhythms2[19].noteOn =     {0,   320, 800};
    rhythms2[19].noteOff =    {320, 800, 960};
    rhythms2[19].rest =       {0,   1,   1  };
    rhythms2[19].length = 3;
}
RhythmLibrary::~RhythmLibrary()
{
    
}

RhythmLibrary::RhythmProperties RhythmLibrary::returnRhythm(int rhythmChoice)
{
    return rhythms[rhythmChoice];
}
