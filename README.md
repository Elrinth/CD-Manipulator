# CD Manipulator
CD Tool for ripping / writing CD

Original code written by: Y.Kanechika. Copyright 2003, All rights reserved.
See license file: cdm-license.txt which is provided as asked by original author!


Modifications by me (Elrinth):
* Ability to automatically start rip from drive at specific index and output file. parameters example: cdm.exe -driveindex 0 -o "c:\temp\rippedcd\GFreatPcEngineGame.cdm"
* Fix memory leak (in destructor of PBBuffer.cpp there was no memory clear!)
* Maybe Fix max tracks from 99 -> 999 (untested). (simply changed track nr from 99 to 999)
* If user cancelled the ripping process, can tell other applications by saying "Canceled" during ending in console.
