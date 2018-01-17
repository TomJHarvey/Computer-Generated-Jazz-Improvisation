# Computer-Generated-Jazz-Improvisation

Instructions for running program.

JUCE must be installed to run this program. It can be downloaded at https://juce.com/get-juce

1.Fork this repositry 

2. Next double click and open the “Computer Generated Jazz Improvisation.jucer”  

3. Click on the config tab and click “juce_audio_basics” under the “Modules” tab

4. In the Path for “Xcode (MacOSX)” drop down menu click the ellipsis and naviage to “Final Year Project/JUCE”  and select the ”modules” folder

5.In the left hand drop down menu click on “Modules”  which is underneath “juce_audio_basics”

6. Click on the “juce_audio_basics”  then select “set paths for all modules”  and select “ copy the path from  ‘juce_audio_basics’   to all other modules”

7. Click “save project and open in IDE…” which is on the bottom left of the window

8. In Xcode, select “FYP program” in the top left of the window then select “FYP program/Source/ReadFiles.Cpp”

9. Delete the existing file path between the red quotation marks for the “minMelodies[0]”

10. Navigate to “FinalYearProject/midi transcriptions/Min7”  and drag the MIDI file “Min7-1Melody1.mid” between the red quotation marks

11. Repeat this process and make sure each chord has the transcriptions in the right place ( once one file path  is dragged in it can be copied to the one below and the numbers are the only thing that needs to be changed)

12. Navigate to “Main.cpp”  on the left hand side.

13. Change the variable “songChoice”  to change the song, and the variable “songRepeat” for the number of repetitions 

14. Navigate to “PrintFiles.cpp”  and change the string to name the song between this line  str += String(“/InsertNameHere”) + String(".mid"); A new file name has to be chosen each time.

15. Build and run the program

16. Search for the MIDI file in finder under the chosen name, or navigate to the “Final Year Project/Computer Generated Jazz Improvisation/Builds/MaxOSX/build/debug” and it should be in the debug folder.

17. Use any DAW with midi and audio combaibility and drag in the backing track which ever song it generated the solo for found in FinalYearProject/Backing Tracks

18. Set the bpm equal to the file name

19. drag in the midi file, select an instrument and listen!
