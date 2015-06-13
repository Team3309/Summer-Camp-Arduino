Summer Camp 2014
================

Resources and samples for robotics summer camp

#Setup Instructions

##Arduino IDE
1. Download the Arduino IDE for your platform from http://www.arduino.cc/en/Main/Software
2. If you are using Windows, install the drivers for the Arduino Uno by following the instructions at http://www.arduino.cc/en/Guide/Windows#toc4

##Import Libraries
1. Download [MSMotorShield.zip](https://github.com/Team3309/Summer-Camp-Arduino/raw/master/MSMotorShield.zip) and [NewPing.zip](https://github.com/Team3309/Summer-Camp-Arduino/raw/master/NewPing.zip) and save them to any location on your computer
2. Launch the Arduino IDE
3. Open the **Sketch** menu -> **Include Library** -> **Add .ZIP Library**
4. Browse to the MSMotorShield.zip file

Repeat #3-4 for NewPing.zip

##Deploying Code
1. Download code samples [Samples.zip](https://github.com/Team3309/Summer-Camp-Arduino/raw/master/Samples.zip) and extract to any location on your computer.  You can also copy/paste the samples using the links at the bottom of this page.
2. Connect the Arduino to your computer via the USB Cable
3. Launch the Arduino IDE
4. Ensure that the "Arduino Uno" is selected under the **Tools** -> **Board** menu
5. Ensure that the Arduino device is recognized and selected under the **Tools** -> **Port** menu
6. Open a sample from the **File** -> **Open** menu or paste one into the Editor
7. Click the **Upload** button in the upper left toolbar of the Arduino IDE to deploy


##Robot Schematic

![Image] (robot-schematic.png)

##Samples

###[navigate.ino](sample_code/navigate/navigate.ino)

This program is set up to continually drive forward until an obstacle is detected, and then turn.
The goal is to navigate around a rectangular/square enclosure.  

Change the line at the end of ````void loop()```` to ````turnLeft()```` if left turns are desired.

This program can be adapted to navigate around various obstacles by repeatedly chanining the ```while (dist > 15 or dist == 0)``` loop and calls to ````turnRight()```` or ````turnLeft()````

###[proximity_stop.ino](sample_code/proximity_stop/proximity_stop.ino)

This program simply drives forward until an obstacle is detected, and then stops.  

###[turntest.ino](sample_code/turntest/turntest.ino)

This program simply executes one call to ````turnRight()```` and then stops.  Useful for tuning the ````delay```` in milliseconds that is used during the turns
