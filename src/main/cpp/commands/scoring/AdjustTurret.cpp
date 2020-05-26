/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/scoring/AdjustTurret.h"

AdjustTurret::AdjustTurret(Turret* pturret) : m_pTurret(pturret) { AddRequirements(m_pTurret); }

void AdjustTurret::Initialize() { m_pTurret->EnableAutoAdjust(); }

void AdjustTurret::Execute() {}

void AdjustTurret::End(bool interrupted) { m_pTurret->DisableAutoAdjust(); }

bool AdjustTurret::IsFinished() { return false; }
