/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <ctre/phoenix/motorcontrol/can/VictorSPX.h>
#include <frc/DutyCycleEncoder.h>
#include <frc2/command/PIDSubsystem.h>

#include "Constants.h"

constexpr double ADJUSTABLE_HOOD_POSITION_CONVERSION_FACTOR = 360 * 18 / 34;
constexpr double ADJUSTABLE_HOOD_P_GAIN = 0.013;
constexpr double ADJUSTABLE_HOOD_I_GAIN = 0.00075;  // 0.00175;//0.002;//0.0015;//0.001;
constexpr double ADJUSTABLE_HOOD_D_GAIN = 0.00025;
constexpr double ADJUSTABLE_HOOD_GRAVITY_GAIN = 0.05;

/**
 * @brief The adjustable hood mechanism of the robot.
 *
 */
class AdjustableHood : public frc2::PIDSubsystem {
 public:
  /**
   * @brief Construct a new Adjustable Hood object
   *
   */
  AdjustableHood();

  /**
   * @brief Use the PID calculated value to move the adjustable hood to the setpoint
   *
   * @param output The PID calculated output
   * @param setpoint The current setpoint in degrees
   */
  void UseOutput(double output, double setpoint) override;

  /**
   * @brief Get the adjustable hood angle in degrees
   *
   * @return Adjustable hood angle in degrees
   */
  double GetMeasurement() override;

  /**
   * @brief Set the adjustable hood setpoint clamped within the acceptable angles
   *
   * @param setpoint The setpoint in degrees
   */
  void SetClampedSetpoint(double setpoint);

  /**
   * @brief Reset the adjustable hood encoder to zero
   *
   */
  void ResetEncoder();

  /**
   * @brief Raise the hood at a determined speed
   *
   */
  void GoUp();

  /**
   * @brief Lower the hood at a determined speed
   *
   */
  void GoDown();

  /**
   * @brief Raise the hood at a greater speed than GoUp() to unblock it
   *
   */
  void Unblock();

  /**
   * @brief Stop the adjustable hood motor
   *
   */
  void Stop();

 private:
  ctre::phoenix::motorcontrol::can::VictorSPX m_Motor{ADJUSTABLE_HOOD_MOTOR};
  frc::DutyCycleEncoder m_Encoder{ADJUSTABLE_HOOD_ENCODER};
  int m_LockedCount = 0;
  double m_PrevVelocityError;
};
