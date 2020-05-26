/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

constexpr double FEEDER_SPEED = 0.7;
constexpr double CONVEYOR_SPEED = 0.4;

/**
 * @brief The feeder mechanism of the robot.
 *
 */
class Feeder : public frc2::SubsystemBase {
 public:
  /**
   * @brief Construct a new Feeder object
   *
   */
  Feeder();

  /**
   * @brief Turn the feeder motor on to feed the shooter
   *
   */
  void Activate();

  /**
   * @brief Set the motor feeder in reverse direction to unblock power cells
   *
   */
  void UnBlock();

  /**
   * @brief Stop the feeder motor
   *
   */
  void Stop();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_FeederMotor{FEEDER_MOTOR};
  ctre::phoenix::motorcontrol::can::VictorSPX m_ConveyorMotor{CONVEYOR_MOTOR};
};
