/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <units/units.h>

// ############### CAN IDs ###############
// ##### NEO #####
// Drivetrain
constexpr int DRIVETRAIN_RIGHT_MOTOR_1 = 1;
constexpr int DRIVETRAIN_RIGHT_MOTOR_2 = 4;
constexpr int DRIVETRAIN_LEFT_MOTOR_1 = 2;
constexpr int DRIVETRAIN_LEFT_MOTOR_2 = 3;

// Winch
constexpr int WINCH_MOTOR = 5;

// Shooter
constexpr int SHOOTER_LEFT_MOTOR = 6;
constexpr int SHOOTER_RIGHT_MOTOR = 7;

// ##### Victor SPX #####
// Feeder
constexpr int FEEDER_MOTOR = 7;

// Conveyor
constexpr int CONVEYOR_MOTOR = 8;

// AdjustableHood IDs
constexpr int ADJUSTABLE_HOOD_MOTOR = 6;

// ############### PWM IDs ###############
// Intake
constexpr int INTAKE_MOTOR = 2;

// Turret
constexpr int TURRET_MOTOR = 3;

// ControlPanelManipulator
constexpr int CONTROL_PANEL_MANIPULATOR_MOTOR = 4;

// TelescopicArm
constexpr int TELESCOPIC_ARM_MOTOR = 0;

// ############### Encoders IDs ###############
// Drivetrain
constexpr int DRIVETRAIN_RIGHT_ENCODER_A = 0;
constexpr int DRIVETRAIN_RIGHT_ENCODER_B = 1;
constexpr int DRIVETRAIN_LEFT_ENCODER_A = 2;
constexpr int DRIVETRAIN_LEFT_ENCODER_B = 3;

// Turret
constexpr int TURRET_ENCODER_A = 4;
constexpr int TURRET_ENCODER_B = 5;

// AdjustableHood
constexpr int ADJUSTABLE_HOOD_ENCODER = 7;

// TelescopicArm
constexpr int TELESCOPIC_ARM_ENCODER = 8;

constexpr int TURRET_RELAY = 9;

// ############### PCM IDs ###############
// Intake
constexpr int INTAKE_SOLENOID_A = 4;
constexpr int INTAKE_SOLENOID_B = 5;
