#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

motor RightMotor(PORT17);
motor LeftMotor(PORT11);
motor ArmMotor(PORT2);
motor ArmMotor2(PORT3);
motor RingMotor(PORT10);

controller Controller1;

// VEXcode device constructors


// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}