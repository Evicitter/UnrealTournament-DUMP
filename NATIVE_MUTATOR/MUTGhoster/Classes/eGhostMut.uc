//-----------------------------------------------------------------------------------------------------------------------------------------------------
//Created by -=EVILemitter=-
//-----------------------------------------------------------------------------------------------------------------------------------------------------
class eGhostMut extends Mutator
	native;

var() class<PickUp> DestroyPU, DestroyPU2;
//----------------------------------------
var transient bool Initialized;
//----------------------------------------

native final function nScoreKill(Pawn Killer, Pawn Other);
native final function nMutatorTakeDamage(int AD, Pawn V, Pawn IB);
native function bool CheckReplacement( actor Other, out byte bSuperRelevant);
native function String GetHumanName();

function ScoreKill(Pawn K, Pawn O)
{
 nScoreKill(K, O);
 super.ScoreKill(K, O);
}

function MutatorTakeDamage(out int ActualDamage, Pawn Victim, Pawn InstigatedBy,
 out Vector HitLocation, out Vector Momentum, name DamageType)
{
  nMutatorTakeDamage(ActualDamage, Victim, InstigatedBy);
  Super.MutatorTakeDamage(ActualDamage, Victim, InstigatedBy, HitLocation, Momentum, DamageType);
}

defaultproperties
{
 NetUpdateFrequency=1.0
 RemoteRole=ROLE_None
 bNet=False
 bNetSpecial=False
 ScaleGlow=0.0
 bMovable=False
 SoundRadius=0
 SoundVolume=0
 SoundPitch=0
 TransientSoundVolume=0.0
 CollisionRadius=0.0
 CollisionHeight=0.0
 bJustTeleported=False
 Mass=1.0
 NetPriority=0.1
 bScriptInitialized=True
 bStasis=True

 DestroyPU=class'UT_Invisibility'
 DestroyPU2=class'Invisibility'
}
