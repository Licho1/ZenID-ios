// Copyright (c) Společnost pro informační technologie a právo, s.r.o.
// This file is generated automatically. Any change will be overwritten.

#pragma once

#include <cstdint>

namespace RecogLibC
{

enum class DocumentCodes : uint8_t
{
	IDC1 = 0,
	IDC2 = 1,
	DRV = 2,
	PAS = 3,
	SK_IDC_2008plus = 4,
	SK_DRV_2004_08_09 = 5,
	SK_DRV_2013 = 6,
	SK_DRV_2015 = 7,
	SK_PAS_2008_14 = 8,
	SK_IDC_1993 = 9,
	SK_DRV_1993 = 10,
	PL_IDC_2015 = 11,
	DE_IDC_2010 = 12,
	DE_IDC_2001 = 13,
	HR_IDC_2013_15 = 14,
	AT_IDE_2000 = 15,
	HU_IDC_2000_01_12 = 16,
	HU_IDC_2016 = 17,
	AT_IDC_2002_05_10 = 18,
	HU_ADD_2012 = 19,
	AT_PAS_2006_14 = 20,
	AT_DRV_2006 = 21,
	AT_DRV_2013 = 22,
	CZ_RES_2011_14 = 23,
	CZ_RES_2006_T = 24,
	CZ_RES_2006_07 = 25,
	CZ_GUN_2014 = 26,
	HU_PAS_2006_12 = 27,
	HU_DRV_2012_13 = 28,
	HU_DRV_2012_B = 29,
	EU_EHIC_2004_A = 30,
	Unknown = 31,
	CZ_GUN_2017 = 32,
	CZ_RES_2020 = 33,
	PL_IDC_2019 = 34,
	IT_PAS_2006_10 = 35,
	INT_ISIC_2008 = 36,
	DE_PAS = 37,
	DK_PAS = 38,
	ES_PAS = 39,
	FI_PAS = 40,
	FR_PAS = 41,
	GB_PAS = 42,
	IS_PAS = 43,
	NL_PAS = 44,
	RO_PAS = 45,
	SE_PAS = 46,
	PL_PAS = 47,
	PL_DRV_2013 = 48,
	CZ_BIRTH = 49,
	CZ_VEHICLE_I = 50,
	INT_ISIC_2019 = 51,
	SI_PAS = 52,
	SI_IDC = 53,
	SI_DRV = 54,
	EU_EHIC_2004_B = 55,
	PL_IDC_2001_02_13 = 56,
};

enum class PageCodes : uint8_t
{
	F = 0,
	B = 1,
};

enum class Country : uint8_t
{
	Cz = 0,
	Sk = 1,
	At = 2,
	Hu = 3,
	Pl = 4,
	De = 5,
	Hr = 6,
	Ro = 7,
	Ru = 8,
	Ua = 9,
	It = 10,
	Dk = 11,
	Es = 12,
	Fi = 13,
	Fr = 14,
	Gb = 15,
	Is = 16,
	Nl = 17,
	Se = 18,
	Si = 19,
};

enum class DocumentRole : uint8_t
{
	Idc = 0,
	Pas = 1,
	Drv = 2,
	Res = 3,
	Gun = 4,
	Hic = 5,
	Std = 6,
	Car = 7,
	Birth = 8,
};

enum class SupportedLanguages : uint8_t
{
	English = 0,
	Czech = 1,
	Polish = 2,
	German = 3,
};

enum class DocumentVerifierState : int
{
	NoMatchFound = 0,
	AlignCard = 1,
	HoldSteady = 2,
	Blurry = 3,
	ReflectionPresent = 4,
	Ok = 5,
	Hologram = 6,
	Dark = 7,
};

enum class SelfieVerifierState : int
{
	Ok = 0,
	NoFaceFound = 1,
	Blurry = 2,
	Dark = 3,
	ConfirmingFace = 4,
};

enum class HologramState : int
{
	NoMatchFound = 0,
	TiltLeft = 1,
	TiltRight = 2,
	TiltUp = 3,
	TiltDown = 4,
	RotateClockwise = 5,
	RotateCounterClockwise = 6,
	Ok = 7,
};

enum class FaceLivenessVerifierState : int
{
	LookAtMe = 0,
	TurnHead = 1,
	Smile = 2,
	Ok = 3,
};

}
