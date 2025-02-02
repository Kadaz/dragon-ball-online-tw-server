#include "stdafx.h"
#include "NtlAvatar.h"

#include "NtlBitFlagManager.h"

CNtlAvatar::CNtlAvatar(void)
{
	Init();
}

CNtlAvatar::~CNtlAvatar(void)
{
}

void CNtlAvatar::Init()
{
	InitializeAttributeLink();
}

void CNtlAvatar::InitializeAttributeLink()
{
}

CNtlAvatar* CNtlAvatar::GetInstance()
{
	static CNtlAvatar avatar;
	return &avatar;
}

bool CNtlAvatar::SaveAvatarAttribute(CNtlBitFlagManager* pChangedFlag, sAVATAR_ATTRIBUTE_LINK* pAttributeDataLink, void* pvBuffer, DWORD* pwdDataSize)
{
	BYTE* pbyBuffer = (BYTE*)pvBuffer;
	BYTE* pbyAttributeDataLink = (BYTE*)pAttributeDataLink;

	*pwdDataSize = 0;

	::CopyMemory(pbyBuffer, pChangedFlag->GetRawData(), pChangedFlag->GetBytesUsed());

	pbyBuffer += pChangedFlag->GetBytesUsed();
	*pwdDataSize += pChangedFlag->GetBytesUsed();

	for (BYTE byIndex = ATTRIBUTE_TO_UPDATE_FIRST ; byIndex <= ATTRIBUTE_TO_UPDATE_LAST ; byIndex++)
	{
		if (false != pChangedFlag->IsSet(byIndex))
		{
			void* pvAttributeFieldLink = *((void**)(pbyAttributeDataLink + byIndex * sizeof(void*)));
			if (NULL == pvAttributeFieldLink)
			{
				continue;
			}

			DWORD dwDataSize = m_attributeLogic[byIndex].pCopyAttributeFunction(pvAttributeFieldLink, pbyBuffer);
			if (0 == dwDataSize)
			{
				return false;
			}
			else
			{
				pbyBuffer += dwDataSize;
				*pwdDataSize += dwDataSize;
			}
		}
	}

	return true;
}

bool CNtlAvatar::FillAvatarAttribute(sAVATAR_ATTRIBUTE_LINK* pAttributeDataLink, sAVATAR_ATTRIBUTE* pAttributeData)
{
	BYTE* pbyAttributeDataLink = (BYTE*)pAttributeDataLink;
	BYTE* pbyAttributeData = (BYTE*)pAttributeData;

	for (BYTE byIndex = ATTRIBUTE_TO_UPDATE_FIRST ; byIndex <= ATTRIBUTE_TO_UPDATE_LAST ; byIndex++)
	{
		void* pvAttributeFieldLink = *((void**)(pbyAttributeDataLink + byIndex * sizeof(void*)));
		if (NULL == pvAttributeFieldLink)
		{
			continue;
		}

		DWORD dwDataSize = m_attributeLogic[byIndex].pCopyAttributeFunction(
																			pvAttributeFieldLink,
																			pbyAttributeData + m_attributeLogic[byIndex].dwFieldOffset);
		if (0 == dwDataSize)
		{
			return false;
		}
	}

	return true;
}

#ifndef ATTRIBUTE_LOGIC_DEFINE
#define ATTRIBUTE_LOGIC_DEFINE(field_name, type)					\
	{																\
		PtrToUlong(&(((sAVATAR_ATTRIBUTE*)NULL)->field_name)),		\
		CopyValueByType_##type										\
	}
#endif

CNtlAvatar::sATTRIBUTE_LOGIC CNtlAvatar::m_attributeLogic[ATTRIBUTE_TO_UPDATE_COUNT] =
{
	ATTRIBUTE_LOGIC_DEFINE(byBaseStr, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byLastStr, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byBaseCon, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byLastCon, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byBaseFoc, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byLastFoc, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byBaseDex, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byLastDex, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byBaseSol, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byLastSol, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byBaseEng, WORD),
	ATTRIBUTE_LOGIC_DEFINE(byLastEng, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseMaxLP, DWORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastMaxLP, DWORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseMaxEP, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastMaxEP, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseMaxAp, DWORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastMaxAp, DWORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseMaxRP, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastMaxRP, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseLpRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastLpRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseLpSitdownRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastLpSitdownRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseLpBattleRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastLpBattleRegen, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseEpRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastEpRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseEpSitdownRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastEpSitdownRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseEpBattleRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastEpBattleRegen, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseApRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastApRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseApSitdownRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastApSitdownRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseApBattleRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastApBattleRegen, WORD),

	ATTRIBUTE_LOGIC_DEFINE(unknown_int16_0, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown_int16_1, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown_int16_2, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown_int16_3, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseRpRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastRpRegen, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastRpDimimutionRate, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBasePhysicalOffence, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastPhysicalOffence, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBasePhysicalDefence, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastPhysicalDefence, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseEnergyOffence, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastEnergyOffence, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseEnergyDefence, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastEnergyDefence, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseAttackRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastAttackRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseDodgeRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastDodgeRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseBlockRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastBlockRate, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBaseCurseSuccessRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastCurseSuccessRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseCurseToleranceRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastCurseToleranceRate, WORD),

	ATTRIBUTE_LOGIC_DEFINE(unknown_rate1, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown_rate2, WORD),

	ATTRIBUTE_LOGIC_DEFINE(wBasePhysicalCriticalRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastPhysicalCriticalRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wBaseEnergyCriticalRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastEnergyCriticalRate, WORD),

	ATTRIBUTE_LOGIC_DEFINE(unknown_float1_0, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown_float1_1, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown_float1_0, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown_float1_1, float),

	ATTRIBUTE_LOGIC_DEFINE(fBaseRunSpeed, float),
	ATTRIBUTE_LOGIC_DEFINE(fLastRunSpeed, float),

	ATTRIBUTE_LOGIC_DEFINE(fBaseAirSpeed, float),
	ATTRIBUTE_LOGIC_DEFINE(fLastAirSpeed, float),
	ATTRIBUTE_LOGIC_DEFINE(fBaseAirDashSpeed, float),
	ATTRIBUTE_LOGIC_DEFINE(fLastAirDashSpeed, float),
	ATTRIBUTE_LOGIC_DEFINE(fBaseAirDash2Speed, float),
	ATTRIBUTE_LOGIC_DEFINE(fLastAirDash2Speed, float),

	ATTRIBUTE_LOGIC_DEFINE(wBaseAttackSpeedRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wLastAttackSpeedRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(fBaseAttackRange, float),
	ATTRIBUTE_LOGIC_DEFINE(fLastAttackRange, float),

	ATTRIBUTE_LOGIC_DEFINE(fCastingTimeChangePercent, float),
	ATTRIBUTE_LOGIC_DEFINE(fCoolTimeChangePercent, float),
	ATTRIBUTE_LOGIC_DEFINE(fKeepTimeChangePercent, float),
	ATTRIBUTE_LOGIC_DEFINE(fDotValueChangePercent, float),
	ATTRIBUTE_LOGIC_DEFINE(fDotTimeChangeAbsolute, float),
	ATTRIBUTE_LOGIC_DEFINE(fRequiredEpChangePercent, float),

	ATTRIBUTE_LOGIC_DEFINE(fHonestOffence, float),
	ATTRIBUTE_LOGIC_DEFINE(fHonestDefence, float),
	ATTRIBUTE_LOGIC_DEFINE(fStrangeOffence, float),
	ATTRIBUTE_LOGIC_DEFINE(fStrangeDefence, float),
	ATTRIBUTE_LOGIC_DEFINE(fWildOffence, float),
	ATTRIBUTE_LOGIC_DEFINE(fWildDefence, float),
	ATTRIBUTE_LOGIC_DEFINE(fEleganceOffence, float),
	ATTRIBUTE_LOGIC_DEFINE(fEleganceDefence, float),
	ATTRIBUTE_LOGIC_DEFINE(fFunnyOffence, float),
	ATTRIBUTE_LOGIC_DEFINE(fFunnyDefence, float),

	ATTRIBUTE_LOGIC_DEFINE(unknown2, float),

	ATTRIBUTE_LOGIC_DEFINE(wParalyzeToleranceRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wTerrorToleranceRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wConfuseToleranceRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wStoneToleranceRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(wCandyToleranceRate, WORD),

	ATTRIBUTE_LOGIC_DEFINE(fParalyzeKeepTimeDown, float),
	ATTRIBUTE_LOGIC_DEFINE(fTerrorKeepTimeDown, float),
	ATTRIBUTE_LOGIC_DEFINE(fConfuseKeepTimeDown, float),
	ATTRIBUTE_LOGIC_DEFINE(fStoneKeepTimeDown, float),
	ATTRIBUTE_LOGIC_DEFINE(fCandyKeepTimeDown, float),
	ATTRIBUTE_LOGIC_DEFINE(fBleedingKeepTimeDown, float),
	ATTRIBUTE_LOGIC_DEFINE(fPoisonKeepTimeDown, float),
	ATTRIBUTE_LOGIC_DEFINE(fStomachacheKeepTimeDown, float),

	ATTRIBUTE_LOGIC_DEFINE(fCriticalBlockSuccessRate, float),

	ATTRIBUTE_LOGIC_DEFINE(wGuardRate, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown6, WORD),

	ATTRIBUTE_LOGIC_DEFINE(fSkillDamageBlockModeSuccessRate, float),
	ATTRIBUTE_LOGIC_DEFINE(fCurseBlockModeSuccessRate, float),
	ATTRIBUTE_LOGIC_DEFINE(fKnockdownBlockModeSuccessRate, float),
	ATTRIBUTE_LOGIC_DEFINE(fHtbBlockModeSuccessRate, float),

	ATTRIBUTE_LOGIC_DEFINE(fSitDownLpRegenBonusRate, float),
	ATTRIBUTE_LOGIC_DEFINE(fSitDownEpRegenBonusRate, float),
	ATTRIBUTE_LOGIC_DEFINE(fPhysicalCriticalDamageBonusRate, float),
	ATTRIBUTE_LOGIC_DEFINE(fEnergyCriticalDamageBonusRate, float),

	ATTRIBUTE_LOGIC_DEFINE(fItemUpgradeBonusRate, float),
	ATTRIBUTE_LOGIC_DEFINE(fItemUpgradeBreakBonusRate, float),

	ATTRIBUTE_LOGIC_DEFINE(unknown3_0, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_1, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_2, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_3, float),
	ATTRIBUTE_LOGIC_DEFINE(SkillSpeed, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_5, float),
	ATTRIBUTE_LOGIC_DEFINE(MaxWeight, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_w6, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_7, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_8, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_9, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_10, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_11, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_12, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown3_13, float),

	ATTRIBUTE_LOGIC_DEFINE(unknown4_0, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown4_1, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown4_2, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown4_3, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown4_4, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown4_5, WORD),
	ATTRIBUTE_LOGIC_DEFINE(unknown4_6, WORD),

	ATTRIBUTE_LOGIC_DEFINE(unknown5_0, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown5_1, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown5_2, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown5_3, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown5_4, float),
	ATTRIBUTE_LOGIC_DEFINE(unknown5_5, float),
};

#undef ATTRIBUTE_LOGIC_DEFINE

DWORD CNtlAvatar::CopyValueByType_BYTE(void* pvValue, void* pvBuffer)
{
	BYTE* pbyBuffer = (BYTE*)pvBuffer;

	*pbyBuffer = *((BYTE*)pvValue);

	return sizeof(BYTE);
}

DWORD CNtlAvatar::CopyValueByType_WORD(void* pvValue, void* pvBuffer)
{
	WORD* pbyBuffer = (WORD*)pvBuffer;

	*pbyBuffer = *((WORD*)pvValue);

	return sizeof(WORD);
}

DWORD CNtlAvatar::CopyValueByType_float(void* pvValue, void* pvBuffer)
{
	float* pbyBuffer = (float*)pvBuffer;

	*pbyBuffer = *((float*)pvValue);

	return sizeof(float);
}

DWORD CNtlAvatar::CopyValueByType_DWORD(void* pvValue, void* pvBuffer)
{
	DWORD* pbyBuffer = (DWORD*)pvBuffer;

	*pbyBuffer = *((DWORD*)pvValue);

	return sizeof(DWORD);
}