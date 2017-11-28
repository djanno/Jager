#ifndef _GLOBAL_
#define _GLOBAL_

/* this file is used to reference all the global variables to which the various tasks have access to, including the ones used to coordinate them */
/* variables used for task coordination */

extern bool detected; //signals if the robot path is blocked
extern bool found; //signals if the robot has found the chosenDirection
extern bool ready; //signals if the robot is facing the chosenDirection
extern int chosenDirection; //contains the direction of the chosen path

#endif
