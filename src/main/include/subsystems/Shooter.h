/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/Timer.h>
#include <rev/CANSparkMax.h>

#include "Constants.h"

constexpr double SHOOTER_PREP_SHOOT_SPEED = 0.8;
constexpr double SHOOTER_PREP_SHOOT_RAMP = 0.7;
constexpr double SHOOTER_TOTAL_CHARGE_TIME = 1.5;

/**
 * @brief The shooter mechanism of the robot.
 *
 */
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
  rev::CANSparkMax m_RightMotor{SHOOTER_RIGHT_MOTOR, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_LeftMotor{SHOOTER_LEFT_MOTOR, rev::CANSparkMax::MotorType::kBrushless};

  frc::Timer m_Timer;
};
