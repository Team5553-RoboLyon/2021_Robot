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
 * @brief Automatically adjust the turret with the powerport based on vision processing inputs.
 *
 */
class AdjustTurret : public frc2::CommandHelper<frc2::CommandBase, AdjustTurret> {
 public:
  /**
   * @brief Construct a new Adjust Turret object
   *
   * @param pturret The turret subsystem of the robot
   */
  explicit AdjustTurret(Turret* pturret);

  /**
   * @brief Start the automatic adjustment of the turret with the powerport
   *
   * Call the Turret::EnableAutoAdjust() method
   */
  void Initialize() override;

  /**
   * @brief Do nothing
   *
   */
  void Execute() override;

  /**
   * @brief Stop the automatic adjustment of the turret with the powerport
   *
   * Call the Turret::DisableAutoAdjust() method
   *
   * @param interrupted whether the command was interrupted/canceled
   */
  void End(bool interrupted) override;

  /**
   * @brief Return false : this command has no finishing event
   *
   * @return false in every situation
   */
  bool IsFinished() override;

 private:
  Turret* m_pTurret;
};
