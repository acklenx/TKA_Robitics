

#include "vex.h"

using namespace vex;


competition Competition;




void pre_auton(void) {
 
  vexcodeInit();

  ArmMotor.setMaxTorque(60, percent);
  ArmMotor2.setMaxTorque(60, percent);

}


//////functions//////////

void driveFwd(int driving){
  LeftMotor.startRotateFor(directionType::fwd, driving, rotationUnits::deg);
  RightMotor.rotateFor(directionType::rev, driving, rotationUnits::deg);
}

void driveRev(int driving){
  LeftMotor.startRotateFor(directionType::rev, driving, rotationUnits::deg);
  RightMotor.rotateFor(directionType::fwd, driving, rotationUnits::deg);
}

void turnRight (void){
  LeftMotor.startRotateFor(directionType::fwd, 690, rotationUnits::deg);
  RightMotor.rotateFor(directionType::fwd, 690, rotationUnits::deg);
}

void turnLeft (void){
  RightMotor.startRotateFor(directionType::rev, 690, rotationUnits::deg);
  LeftMotor.rotateFor(directionType::rev, 690, rotationUnits::deg);
}

void rightComplete (void) {
  LeftMotor.startRotateFor(directionType::fwd, 1400, rotationUnits::deg);
  RightMotor.rotateFor(directionType::fwd, 1400, rotationUnits::deg);
}

void armLift1 (void) {
  ArmMotor2.rotateFor(directionType::rev, 1300, rotationUnits::deg);
}

void armDown1 (void) {
  ArmMotor2.rotateFor(directionType::fwd, 1300, rotationUnits::deg);
}

void armLift2 (void) {
  ArmMotor.rotateFor(directionType::rev, 1300, rotationUnits::deg);
}
  
void armDown2 (int armDegrees) {
  ArmMotor.rotateFor(directionType::fwd, armDegrees, rotationUnits::deg);
}

void ringPoint (void) {
  RingMotor.rotateFor(directionType::fwd, 45, rotationUnits::deg);
  RingMotor.rotateFor(directionType::rev, 45, rotationUnits::deg);
}


void autoFinal (void) {
  armDown1();
  driveFwd(600);
  armLift1();
  driveRev(600);
  ringPoint();
}


void autoPure (void) {
  armDown1();
  driveFwd(600);
  armLift1();
  driveFwd(800);
  turnLeft();
  driveFwd(6500);
  turnRight();
  driveRev(1000);
  turnLeft();
  armDown2(1200);
  driveRev(800);
  armLift2();
  driveRev(300);
  armDown2(1100);
  driveRev(2500);


}
   














void autonomous(void) {
  autoFinal();

}


 void diffMode(void) {
     RightMotor.spin(directionType::fwd, (Controller1.Axis1.value()+ (Controller1.Axis2.value()*-1)), vex::velocityUnits::pct);
     LeftMotor.spin(directionType::fwd, (Controller1.Axis1.value()+Controller1.Axis2.value()), vex::velocityUnits::pct);
    }

    

void usercontrol(void) { 



 
while (1) {

  
  RightMotor.spin(directionType::rev,Controller1.Axis2.value(), vex::velocityUnits::pct);
  LeftMotor.spin(directionType::fwd,Controller1.Axis3.value(), vex::velocityUnits::pct);

  if (Controller1.ButtonL1.pressing()) {
    ArmMotor.spin(directionType::fwd, 50, velocityUnits::pct);
  }
  
  else if (Controller1.ButtonL2.pressing()) {
    ArmMotor.spin(directionType::rev, 50, velocityUnits::pct);
  }

  else {
    ArmMotor.stop(brakeType::brake);
  }

  if (Controller1.ButtonR1.pressing()) {
    ArmMotor2.spin(directionType::fwd, 50, velocityUnits::pct);
  }
  
  else if (Controller1.ButtonR2.pressing()) {
    ArmMotor2.spin(directionType::rev, 50, velocityUnits::pct);
  }

  else {
    ArmMotor2.stop(brakeType::brake);
  }

    wait(20, msec); 
  }

  if (Controller1.ButtonA.pressing()) {
    RingMotor.spin(directionType::fwd, 50, velocityUnits::pct);
  }
  
  else if (Controller1.ButtonA.pressing()) {
    RingMotor.spin(directionType::rev, 50, velocityUnits::pct);
  }

  else {
    RingMotor.stop(brakeType::brake);
  }

    wait(20, msec); 
  }




int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

 
  pre_auton();

  while (true) {
    wait(100, msec);
  }
}
