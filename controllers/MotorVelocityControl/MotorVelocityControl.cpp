#include <webots/Motor.hpp>
#include <webots/Robot.hpp>

constexpr double maxEpuckMotorSpeed{6.28};

// TODO: Complete these functions.
void move(webots::Motor& left, webots::Motor& right, double speed);
void turn(webots::Motor& left, webots::Motor& right, double speed);

// Waits for a duration (in milliseconds).
void wait(webots::Robot& robot, int duration) {
  const double start{robot.getTime()};
  const double timeStep{robot.getBasicTimeStep()};
  while (robot.getTime() - start < duration * 0.001) {
    robot.step(timeStep);
  }
}

int main(int argc, char **argv) {
  webots::Robot robot;
  webots::Motor& leftMotor{*robot.getMotor("left wheel motor")};
  webots::Motor& rightMotor{*robot.getMotor("right wheel motor")};
  
  // Do not set a limit on how much the wheel can rotate.
  leftMotor.setPosition(INFINITY);
  rightMotor.setPosition(INFINITY);
  
  // Get the time step of the current world.
  double timeStep{robot.getBasicTimeStep()};
  
  // TODO: Complete the robot behaviour as specified.
  while (robot.step(timeStep) != -1) {
    move(leftMotor, rightMotor, maxEpuckMotorSpeed);
    wait(robot, 1000);
    move(leftMotor, rightMotor, 0);
    wait(robot, 1000);
  };

  return 0;
}
