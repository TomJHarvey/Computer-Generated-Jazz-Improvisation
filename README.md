# Computer-Generated-Jazz-Improvisation

Instructions for running program.

JUCE must be installed to run this program. It can be downloaded at https://juce.com/get-juce.
A DAW with midi functionality must also be installed.

1. Open the “Computer Generated Jazz Improvisation.jucer”  

2. On the left hand side click 'Modules' then 'juce_audio_basics' and select 'Use global path for this module'

3. Repeat this process for each module on the left hand side or manually chose the path for the modles as JUCE/modules.

4. Click “save project and open in IDE…” which is on the top right next to a pencil icon.

5. Navigate to ReadFiles.cpp

6. Change the file path for each file to the correct one for the computer being used eg. /Users/Tom/Desktop/Year 3/Final Year Project/Midi transcriptions/Min7/Min7-1Melody1.mid

7. Navigate to “Main.cpp”.

8. Change the variable “songChoice” on line 31 to change the song, and the variable “songRepeat” on line 32 for the number of repetitions 

9. Navigate to “PrintFiles.cpp”  and change the string to an apporiate name str += String(“/InsertNameHere”) + String(".mid"); A new file name has to be chosen each time.

10. Build and run the program

11. Search for the MIDI file in finder under the chosen name, or navigate to the “Computer Generated Jazz Improvisation/Builds/MaxOSX/build/debug” and it will be in the debug folder.

12. Use any DAW with midi and audio combaibility and drag in the backing track which ever song it generated the solo for found in FinalYearProject/Backing Tracks

13. Set the bpm equal to the file name

14. Drag in the midi file, select an instrument and listen!
