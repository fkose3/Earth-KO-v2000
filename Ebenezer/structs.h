struct _MAGIC_TABLE
{
	int	iNum;
	int	nBeforeAction;
	BYTE	bTargetAction;
	BYTE	bSelfEffect;
	BYTE	bFlyingEffect;
	int	iTargetEffect;
	BYTE	bMoral;
	short	sSkillLevel;	
	short	sSkill;
	short	sMsp;
	short	sHP;
	BYTE	bItemGroup;
	int	iUseItem;
	BYTE	bCastTime;
	short	sReCastTime;
	BYTE	bSuccessRate;
	BYTE	bType[2];
	short	sRange;
	short	sEtc;
};

struct _MAGIC_TYPE1
{
	int	iNum;
	BYTE	bHitType;
	short	sHitRate;
	short	sHit;
	short	sAddDamage;
	BYTE	bDelay;
	BYTE	bComboType;
	BYTE	bComboCount;
	short	sComboDamage;
	short	sRange;
};

struct _MAGIC_TYPE2
{
	int	iNum;
	BYTE	bHitType;
	short	sHitRate;
	short	sAddDamage;
	short	sAddRange;
	BYTE	bNeedArrow;
};

struct _MAGIC_TYPE3
{
	int	iNum;
	BYTE	bDirectType;
	short	sAngle;
	short	sFirstDamage;
	short	sEndDamage;
	short	sTimeDamage;
	BYTE	bRadius;
	BYTE	sDuration;  // duration, in seconds
	BYTE	bAttribute;
};

struct _MAGIC_TYPE4
{
	int	iNum;
	BYTE	bBuffType;
	BYTE	bRadius;
	short	sDuration;  // duration, in seconds
	BYTE	bAttackSpeed;
	BYTE	bSpeed;
	short	sAC;
	short	sACPct;
	BYTE	bAttack;
	BYTE	bMagicAttack;
	short	sMaxHP;
	short	sMaxHPPct;
	short	sMaxMP;
	short	sMaxMPPct;
	BYTE	bHitRate;
	short	sAvoidRate;
	BYTE	bStr;
	BYTE	bSta;
	BYTE	bDex;
	BYTE	bIntel;
	BYTE	bCha;
	BYTE	bFireR;
	BYTE	bColdR;
	BYTE	bLightningR;
	BYTE	bMagicR;
	BYTE	bDiseaseR;
	BYTE	bPoisonR;
	short	sExpPct;
	short	sSpecialAmount;

	bool	bIsBuff; // true if buff, false if debuff

	bool isBuff() { return bIsBuff; }
	bool isDebuff() { return !bIsBuff; }
};

struct _MAGIC_TYPE5
{
	int	iNum;
	BYTE	bType;
	BYTE	bExpRecover;
	short	sNeedStone;
};

struct _MAGIC_TYPE6
{
	int	iNum;
	short	sSize;
	short	sTransformID;
	short	sDuration; // duration, in seconds
	short	sMaxHp;
	short	sMaxMp;
	BYTE	bSpeed;
	short	sAttackSpeed;
	short	sTotalHit;
	short	sTotalAc;
	short	sTotalHitRate;
	short	sTotalEvasionRate;
	short	sTotalFireR;
	short	sTotalColdR;
	short	sTotalLightningR;
	short	sTotalMagicR;
	short	sTotalDiseaseR;
	short	sTotalPoisonR;
	short	sClass;
	BYTE	bUserSkillUse;
	BYTE	bNeedItem;
	BYTE	bSkillSuccessRate;
	BYTE	bMonsterFriendly;
};


enum TransformationSkillUse
{
	TransformationSkillUseSiege		= 0,
	TransformationSkillUseMonster	= 1,
	TransformationSkillUseNPC		= 3,
	TransformationSkillUseSpecial	= 4, // e.g. Snowman transformations
	TransformationSkillUseSiege2	= 7  // e.g. Moving Towers
};

struct _MAGIC_TYPE7
{
	int	iNum;
	BYTE	bValidGroup;
	BYTE	bNationChange;
	short	sMonsterNum;
	BYTE	bTargetChange;
	BYTE	bStateChange;
	BYTE	bRadius;
	short	sHitRate;
	short	sDuration;
	short	sDamage;
	BYTE	bVision;
	int	nNeedItem;
};

struct _MAGIC_TYPE8
{
	int	iNum;
	BYTE	bTarget;
	short	sRadius;
	BYTE	bWarpType;
	short	sExpRecover;
	short	sKickDistance; // used exclusively by soccer ball-control skills.
};

struct _MAGIC_TYPE9
{
	int	iNum;
	BYTE	bValidGroup;
	BYTE	bNationChange;
	short	sMonsterNum;
	BYTE	bTargetChange;
	BYTE	bStateChange;
	short	sRadius;
	short	sHitRate;
	short	sDuration;
	short	sDamage;
	short	sVision;
	int	nNeedItem;
};