# PPM Player
## Author and Create time
	Caitlynn Tian Zhou 
	20 April 2016

## Last edited time
	12 May 2016

## Installation and Usage
	* open Terminal and change the directory to the folder of the program
	* simply type in 'make' to compile the program
	* commands to run the program:
		* ./rledecode (rlefile) - | ./ppmplayer (delay) (brightness) (contrast) (saturation)
			(rlefile) : a .rle file
			(delay): an int; (delay) milliseconds betweem each frame
			(brightness): an int; (brightness) = 50 when user don't want to change, more than 50 means enhance the brightness, less than 50 means reduce the brightness 
			(contrast): an int; (contrast) = 50 when user don't want to change, more than 50 means enhance the contrast, less than 50 means reduce the contrast 
			(saturation): an int; (saturation) = 50 when user don't want to change, more than 50 means enhance the saturation, less than 50 means reduce the saturation 
	 * explanation of the commands
	 	* Situation 1
	 		Example: ./rledecode rlefiles/virtua.rle - | ./ppmplayer 20 50 50 50
	 		Explanation: the ./rledecode program will decode the virtua.rle file into ppm files, then ./ppmplayer will play the original ppm files as a video with 20 milliseconds between each frame
	 	* Situation 2
	 		Example: ./rledecode rlefiles/virtua.rle - | ./ppmplayer 20 80 25 70 
	 		Explanation: the ./rledecode program will decode the virtua.rle file into ppm files, then ./ppmplayer will play the adjusted ppm files as a video with 20 milliseconds between each frame, enhanced brightness, reduced contrast and enhanced saturation

## What functionality is and is not supported
	 * this program can successfully play ppm files as a video with the (delay) milliseconds between each frame

## Precondition:
	User has to install SDL2.0 library before running the program.
	Download from here: https://www.libsdl.org/download-2.0.php

## Notes:
	I have tested my program several times with no delay, and compared with my friends', mine is a lot faster than all of them, I'm proud.




