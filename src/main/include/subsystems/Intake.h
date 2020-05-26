/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/DoubleSolenoid.h>
#include <frc/VictorSP.h>
#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

constexpr double INTAKE_OPENED_SPEED = 0.6;
constexpr double INTAKE_CLOSED_SPEED = 0.2;

/**
 * @brief The intake mechanism of the robot.
 *
 */
class Intake : public frc2::SubsystemBase {
 public:
  enum class IntakePosition { kOpened, kClosed };

  /**
   * @brief Construct a new Intake object
   *
   */
  Intake();

  /**
   * @brief Raise the intake which blocks it from catching power cells
   *
   */
  void Close();

  /**
   * @brief Lower the intake which allows it to catch power cells
   *
   */
  void Open();

  /**
   * @brief Change the intake position
   * Call Open() if it is closed and Close() if it is opened
   */
  void ChangePosition();

  /**
   * @brief Turn the intake motor on
   * The motor speed and direction depends of the intake position
   */
  void Activate();

  /**
   * @brief Stop the intake motor
   *
   */
  void Stop();

 private:
  IntakePosition m_Position;
  frc::DoubleSolenoid m_Solenoid{INTAKE_SOLENOID_A, INTAKE_SOLENOID_B};
  frc::VictorSP m_Motor{INTAKE_MOTOR};
};
