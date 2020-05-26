/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Encoder.h>
#include <frc/VictorSP.h>
#include <frc2/command/PIDSubsystem.h>

#include "Constants.h"

class Turret : public frc2::PIDSubsystem {
 public:
  /**
   * @brief Construct a new Turret object
   *
   */
  Turret();

  /**
   * @brief Use the PID calculated value to move the turret to the setpoint
   *
   * @param output The PID calculated output
   * @param setpoint The current setpoint in degrees
   */
  void UseOutput(double output, double setpoint) override;

  /**
   * @brief Get the turret angle in degrees
   *
   * @return Turret angle in degrees
   */
  double GetMeasurement() override;

  /**
   * @brief Set the turret setpoint clamped within the acceptable angles
   *
   * @param setpoint The setpoint in degrees
   */
  void SetClampedSetpoint(double setpoint);

  /**
   * @brief Stop the turret motor
   *
   */
  void Stop();

  /**
   * @brief Turn the turret to the left at a determined speed
   *
   */
  void TurnLeft();

  /**
   * @brief Turn the turret to the right at a determined speed
   *
   */
  void TurnRight();

 private:
  frc::VictorSP m_Motor{TURRET_MOTOR};
  frc::Encoder m_Encoder{TURRET_ENCODER_A, TURRET_ENCODER_B};
};
