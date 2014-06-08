Summer-Camp-2014
================

Resources and samples for robotics summer camp


#Arduino IDE

Download from here:
http://arduino.cc/en/Main/Software

Make sure to plug in the Arudnio to your machine and, if necessary, install the drivers included in the download.

##Robot Schematic

![Image] (robot-schematic.png)

##Samples

###navigate.io

This program is set up to continually drive forward until an obstacle is detected, and then turn.
The goal is to navigate around a rectangular/square enclosure.  

Change the line at the end of ````void loop()```` to ````turnLeft()```` if left turns are desired.

This program can be adapted to navigate around various obstacles by repeatedly chanining the ```while (dist > 15 or dist == 0)``` loop and calls to ````turnRight()```` or ````turnLeft()````

###proximity_stop.io

This program simply drives forward until an obstacle is detected, and then stops.  

###turntest.io

This program simply executes one call to ````turnRight()```` and then stops.  Useful for tuning the ````delay```` in milliseconds that is used during the turns
