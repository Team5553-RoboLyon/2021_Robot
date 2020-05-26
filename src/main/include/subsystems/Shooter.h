/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc/Timer.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

#define TOTAL_CHARGE_TIME 1.5

class Shooter : public frc2::SubsystemBase {
 public:
  /**
   * @brief Construct a new Shooter object
   *
   */
  Shooter();

  /**
   * @brief Set the shooter motor power
   *
   * @param power The power in percentage output (-1 to 1)
   */
  void Shoot(double power);

  /**
   * @brief Set the ramp value
   *
   * @param seconds_from_neutral_to_full Minimum desired time to go from neutral to full throttle. A
   * value of '0' will disable the ramp.
   */
  void SetRamp(double seconds_from_neutral_to_full);

  /**
   * @brief Get the time elapsed since the last ResetTimer() call
   *
   * @return double The time in seconds
   */
  double GetTimer();

  /**
   * @brief Reset the shooter timer
   *
   */
  void ResetTimer();

  /**
   * @brief Stop the shooter timer
   *
   */
  void StopTimer();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_RightMotor{SHOOTER_RIGHT_MOTOR};
  ctre::phoenix::motorcontrol::can::VictorSPX m_LeftMotor{SHOOTER_LEFT_MOTOR};
  frc::Timer m_Timer;
};