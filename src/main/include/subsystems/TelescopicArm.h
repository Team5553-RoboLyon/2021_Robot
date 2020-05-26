/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DutyCycleEncoder.h>
#include <frc/VictorSP.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

constexpr double TELESCOPIC_ARM_UP_SPEED = 0.55;
constexpr double TELESCOPIC_ARM_DOWN_SPEED = 0.35;

/**
 * @brief The telescopic arm mechanism of the robot.
 *
 */
class TelescopicArm : public frc2::SubsystemBase {
 public:
  /**
   * @brief Construct a new Telescopic Arm object
   *
   */
  TelescopicArm();

  /**
   * @brief Reset the telescopic arm encoder value to zero
   *
   */
  void ResetEncoder();

  /**
   * @brief Get the position of the telescopic arm
   *
   * @return double The value of the encoder
   */
  double GetEncodeur();

  /**
   * @brief Raise the telescopic arm at a determined speed
   *
   */
  void GoUp();

  /**
   * @brief Lower the turret at a determined speed
   *
   */
  void GoDown();

  /**
   * @brief Stop the telescopic arm motor
   *
   */
  void Stop();

  /**
   * @brief Set the telescopic arm motor to a value that allows it to stay in place
   *
   */
  void ResistGravity();

 private:
  frc::VictorSP m_Motor{TELESCOPIC_ARM_MOTOR};
  frc::DutyCycleEncoder m_Encoder{TELESCOPIC_ARM_ENCODER};
};
