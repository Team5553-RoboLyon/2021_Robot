/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/Turret.h"

/**
 * @brief Move the turret to a specified angle.
 *
 */
class MoveTurret : public frc2::CommandHelper<frc2::CommandBase, MoveTurret> {
 public:
  /**
   * @brief Construct a new Move Turret object
   *
   * @param pturret The turret subsystem of the robot
   * @param angle The angle to be reached by the turret
   */
  MoveTurret(Turret* pturret, double angle);

  /**
   * @brief Enable the PID control of the turret and set the new setpoint (aka the angle)
   *
   */
  void Initialize() override;

  /**
   * @brief Do nothing
   *
   */
  void Execute() override;

  /**
   * @brief Disable the PID control of the turret and stop its motor
   *
   * @param interrupted whether the command was interrupted/canceled
   */
  void End(bool interrupted) override;

  /**
   * @brief Return if the turret has reached its setpoint
   *
   * @return true if the turret has reached its setpoint
   * @return false if the turret has not yet reached its setpoint
   */
  bool IsFinished() override;

 private:
  Turret* m_pTurret;
  double m_Angle;
};
