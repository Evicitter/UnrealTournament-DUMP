//-----------------------------------------------------------
//Created by -=EVILemitter=-
//-----------------------------------------------------------
class eZeroDamage expands Mutator native;

var transient bool bInitCurMut;
var transient vector LastMom;   //-<< For debug
var transient int LastDam;      //-<< for debug

var bool bIsDebug;

native final function nCurMutDamage(Pawn Victim, Pawn InstigatedBy, name DamageType);
native function String GetHumanName();

function MutatorTakeDamage(out int ActualDamage, Pawn Victim, Pawn InstigatedBy,
                           out Vector HitLocation, out Vector Momentum, name DamageType)
{
  super.MutatorTakeDamage(ActualDamage, Victim, InstigatedBy, HitLocation, Momentum, DamageType);

  LastDam = ActualDamage;
  LastMom = Momentum;
  nCurMutDamage(Victim, InstigatedBy, DamageType);
  ActualDamage = LastDam;
  Momentum = LastMom;
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
}
