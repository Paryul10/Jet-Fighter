﻿GRAPHICS-ASSIGNMENT2-QUICK-GUIDE
                                PARYUL JAIN - 20170183


TO START THE GAME
        
        mkdir build (if not already present)
        cd build
        cmake ..
        make all
        ./graphics_asgn1 (could not change it.)


KEY CONTROLS 


CONTROLS:->


A : TO STEER LEFT
D : TO STEER RIGHT
Q: TO STEER ANTICLOCKWISE
E : TO STEER CLOCKWISE
W : TO ACCELERATE.
Z : TO MOVE UP
C : TO MOVE DOWN
L : TO Quit
X : TO MOVE BACKWARDS
MOUSE_LEFT_BUTTON : SHOOT MISSILES(GOES IN THE LAUNCHED DIRECTION)
MOUSE_RIGHT_BUTTON : SHOOT BOMBS (GOES VERTICALLY DOWNWARDS)


CAMERA VIEWS->


Y : FIRST PERSON VIEW (FIGHTER JET VIEW)
U : TOP VIEW 
I : TOWER VIEW
O : FOLLOW CAM VIEW
P : HELICOPTER VIEW


SCORE:->


Score is displayed in textual manner via Seven Segment Display.
A -> DENOTES ALTITUDE
F -> FUEL  PERCENTAGE LEFT
H -> HEALTH INDICATOR
P-> TOTAL POINTS
S -> SPEED OF JET




OBJECTIVE:->
KILL ALL ENEMIES TO FINISH THE GAME.


POINTS:->


1. GO THROUGH THE SMOKE RINGS.(WILL CHANGE THE COLOR OF RING….)
2. PLAYING TIME
3. DESTROY ENEMIES
4. SHOOT THE FLYING OBJECTS.(BEWARE,, THEY HAVE A MOTION IN VERTICAL DIRECTION...)




HEALTH->


1.IF PLAYER GETS HIT BY ENEMY MISSILES 10 TIMES THEN GAME GET OVER.
2.ALSO , THERE IS A NO FLYING ZONE. NEAR A VOLCANO. IF PLANE GOES TOO NEAR, IT CRASHES AUTOMATICALLY, AND GAME IS OVER.
        3. IF PLANE GOES INTO WATER.
        
ENEMY MISSILES ARE RANDOMLY SPAWNED.. BE AWARE


POWERUPS->
        FUEL -> REFILLS THE FUEL TANK BY 20 UNITS.

BONUS->
	COMPASS. INDICATES THE NORTH DIRECTION.
