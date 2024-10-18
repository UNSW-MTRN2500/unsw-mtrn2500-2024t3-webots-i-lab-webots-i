#include <webots/Motor.hpp>
#include <webots/PositionSensor.hpp>
#include <webots/Robot.hpp>

constexpr double epuckWheelRadius{0.0206};
constexpr double epuckAxleLength{0.052};

// TODO: Complete these functions.
void move(webots::Motor& leftMotor, webots::Motor& rightMotor, webots::PositionSensor& leftSensor,
          webots::PositionSensor& rightSensor, double distance);
void turn(webots::Motor& leftMotor, webots::Motor& rightMotor, webots::PositionSensor& leftSensor,
          webots::PositionSensor& rightSensor, double rotation);

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
  webots::PositionSensor& leftSensor{*robot.getPositionSensor("left wheel sensor")};
  webots::PositionSensor& rightSensor{*robot.getPositionSensor("right wheel sensor")};

  // Get the time step of the current world.
  double timeStep{robot.getBasicTimeStep()};
  
  // Turn on the sensors and set its refresh rate.
  leftSensor.enable(timeStep);
  rightSensor.enable(timeStep);
  
  // TODO: Complete the robot behaviour as specified.
  while (robot.step(timeStep) != -1) {
    move(leftMotor, rightMotor, leftSensor, rightSensor, 0.2);
    wait(robot, 4000);
  }

  return 0;
}
