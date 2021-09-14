﻿/*===========================================================================
    C++ class definitions exported from UnrealScript.
    This is automatically generated by the tools.
    DO NOT modify this manually! Edit the corresponding .uc files instead!
===========================================================================*/
#if _MSC_VER
#pragma pack (push,4)
#endif

#ifndef MUTGHOSTER_API
#define MUTGHOSTER_API DLL_IMPORT
#endif

#ifndef NAMES_ONLY
#define AUTOGENERATE_NAME(name) extern MUTGHOSTER_API FName MUTGHOSTER_##name;
#define AUTOGENERATE_FUNCTION(cls,idx,name)
#endif


#ifndef NAMES_ONLY

class MUTGHOSTER_API AeZeroDamage : public AMutator
{
public:
    BITFIELD bInitCurMut:1 GCC_PACK(4);
    FVector LastMom GCC_PACK(4);
    INT LastDam;
    BITFIELD bIsDebug:1 GCC_PACK(4);
    DECLARE_FUNCTION(execGetHumanName);
    DECLARE_FUNCTION(execnCurMutDamage);
    DECLARE_CLASS(AeZeroDamage,AMutator,0,MUTGhoster)
    #include "AeZeroDamage.h"
};

#define UCONST__RadOdn 3.979874073
#define UCONST__OdnR 0.100356432
#define UCONST__DdnR 0.196349541
#define UCONST_hPi 0.008726646

class MUTGHOSTER_API AeTestHUDMut : public AMutator
{
public:
    class UFont* UsingFont;
    class UTexture* tDrawTex;
    DECLARE_FUNCTION(execGetHumanName);
    DECLARE_FUNCTION(execCheckReplacement);
    DECLARE_FUNCTION(execPostRender);
    DECLARE_CLASS(AeTestHUDMut,AMutator,0,MUTGhoster)
    #include "AeTestHUDMut.h"
};


class MUTGHOSTER_API AeSim_HDRMut : public AeTestHUDMut
{
public:
    BITFIELD isFound:1 GCC_PACK(4);
    class APlayerPawn* pPawn GCC_PACK(4);
    DECLARE_CLASS(AeSim_HDRMut,AeTestHUDMut,0,MUTGhoster)
    #include "AeSim_HDRMut.h"
};


class MUTGHOSTER_API AeSArenaMut : public AMutator
{
public:
    BITFIELD bDestroyDMMut:1 GCC_PACK(4);
    BYTE CurWeaponNum GCC_PACK(4);
    class UClass* cDefWeapon[24];
    class UClass* LoadAmmo;
    DECLARE_FUNCTION(execAddMutator);
    DECLARE_FUNCTION(execGetHumanName);
    DECLARE_FUNCTION(execCheckReplacement);
    DECLARE_FUNCTION(execnAlwaysKeep);
    DECLARE_CLASS(AeSArenaMut,AMutator,0|CLASS_Config,MUTGhoster)
    #include "AeSArenaMut.h"
};


class MUTGHOSTER_API AeProMesMut : public AMutator
{
public:
    class UClass* InvisPic1;
    class UClass* InvisPic2;
    class APlayerPawn* LastSender;
    class APawn* LastReceiver;
    class APlayerReplicationInfo* LastPRI;
    FStringNoInit LastMSG;
    FStringNoInit LastCombineMSG;
    DECLARE_FUNCTION(execGetHumanName);
    DECLARE_FUNCTION(execnChat);
    DECLARE_CLASS(AeProMesMut,AMutator,0,MUTGhoster)
    #include "AeProMesMut.h"
};


class MUTGHOSTER_API AeLensFlareMut : public AMutator
{
public:
    class UTexture* LensTex[5];
    FLOAT RadiusScan;
    BYTE MaxLensScr;
    DECLARE_FUNCTION(execGetHumanName);
    DECLARE_FUNCTION(execCheckReplacement);
    DECLARE_FUNCTION(execPostRender);
    DECLARE_CLASS(AeLensFlareMut,AMutator,0|CLASS_Config,MUTGhoster)
    #include "AeLensFlareMut.h"
};


class MUTGHOSTER_API AeGhostMut : public AMutator
{
public:
    class UClass* DestroyPU;
    class UClass* DestroyPU2;
    BITFIELD Initialized:1 GCC_PACK(4);
    DECLARE_FUNCTION(execGetHumanName);
    DECLARE_FUNCTION(execCheckReplacement);
    DECLARE_FUNCTION(execnMutatorTakeDamage);
    DECLARE_FUNCTION(execnScoreKill);
    DECLARE_CLASS(AeGhostMut,AMutator,0,MUTGhoster)
    #include "AeGhostMut.h"
};


class MUTGHOSTER_API ABurnerProj : public AProjectile
{
public:
    FLOAT HurtTime;
    FLOAT Lifetime;
    TArray<class ABurnerProj*> AllProjs;
    DECLARE_FUNCTION(execProcessTouch);
    DECLARE_FUNCTION(execSetDefaultDisplayProperties);
    DECLARE_FUNCTION(execSetDisplayProperties);
    DECLARE_FUNCTION(execGetHumanName);
    DECLARE_CLASS(ABurnerProj,AProjectile,0,MUTGhoster)
    #include "ABurnerProj.h"
};

#endif

AUTOGENERATE_FUNCTION(AeZeroDamage,-1,execGetHumanName);
AUTOGENERATE_FUNCTION(AeZeroDamage,-1,execnCurMutDamage);
AUTOGENERATE_FUNCTION(AeTestHUDMut,-1,execGetHumanName);
AUTOGENERATE_FUNCTION(AeTestHUDMut,-1,execCheckReplacement);
AUTOGENERATE_FUNCTION(AeTestHUDMut,-1,execPostRender);
AUTOGENERATE_FUNCTION(AeSArenaMut,-1,execAddMutator);
AUTOGENERATE_FUNCTION(AeSArenaMut,-1,execGetHumanName);
AUTOGENERATE_FUNCTION(AeSArenaMut,-1,execCheckReplacement);
AUTOGENERATE_FUNCTION(AeSArenaMut,-1,execnAlwaysKeep);
AUTOGENERATE_FUNCTION(AeProMesMut,-1,execGetHumanName);
AUTOGENERATE_FUNCTION(AeProMesMut,-1,execnChat);
AUTOGENERATE_FUNCTION(AeLensFlareMut,-1,execGetHumanName);
AUTOGENERATE_FUNCTION(AeLensFlareMut,-1,execCheckReplacement);
AUTOGENERATE_FUNCTION(AeLensFlareMut,-1,execPostRender);
AUTOGENERATE_FUNCTION(AeGhostMut,-1,execGetHumanName);
AUTOGENERATE_FUNCTION(AeGhostMut,-1,execCheckReplacement);
AUTOGENERATE_FUNCTION(AeGhostMut,-1,execnMutatorTakeDamage);
AUTOGENERATE_FUNCTION(AeGhostMut,-1,execnScoreKill);
AUTOGENERATE_FUNCTION(ABurnerProj,-1,execProcessTouch);
AUTOGENERATE_FUNCTION(ABurnerProj,-1,execSetDefaultDisplayProperties);
AUTOGENERATE_FUNCTION(ABurnerProj,-1,execSetDisplayProperties);
AUTOGENERATE_FUNCTION(ABurnerProj,-1,execGetHumanName);

#ifndef NAMES_ONLY
#undef AUTOGENERATE_NAME
#undef AUTOGENERATE_FUNCTION
#endif NAMES_ONLY

#if _MSC_VER
#pragma pack (pop)
#endif
