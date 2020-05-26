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
#include <networktables/NetworkTableEntry.h>

#include "Constants.h"

constexpr double TURRET_POSITION_CONVERSION_FACTOR = -360.0 * ((16.0 / 132.0) / 2048.0);
constexpr double TURRET_SPEED = 0.2;
constexpr double TURRET_MAX_POSITION = 45.0;
constexpr double TURRET_MAX_SPEED = 0.4;
constexpr double TURRET_P_GAIN = 0.0503;
constexpr double TURRET_I_GAIN = 0.004;
constexpr double TURRET_D_GAIN = 0.002;
constexpr int TURRET_BUFFER_SIZE = 3;

/**
 * @brief The turret mechanism of the robot.
 *
 */
class Turret : public frc2::PIDSubsystem {
 public:
  /**
   * @brief Construct a new Turret object
   *
   */
  Turret();

  /**
   * @brief This method is called periodically by the CommandScheduler.
   *
   * AutoAdjust the turret if enabled.
   */
  void Periodic() override;

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
   * @brief Enable the automatic adjustment of the turret with the powerport
   *
   * Just call this method once to enable the automatic adjustment. Then, the Periodic() method will
   * periodically adjust the turret based on vision processing inputs.
   */
  void EnableAutoAdjust();

  /**
   * @brief Disable the automatic adjustment of the turret with the powerport
   *
   * Disables the PID control.  Sets motor to zero.
   */
  void DisableAutoAdjust();

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

  bool m_AutoAdjustEnabled;
  nt::NetworkTableEntry m_ChameleonYawEntry;
  nt::NetworkTableEntry m_ChameleonIsValidEntry;
  double m_BufferYaw[TURRET_BUFFER_SIZE] = {0};
  double m_BufferYawSorted[TURRET_BUFFER_SIZE] = {0};
  unsigned int m_BufferCount;
};
