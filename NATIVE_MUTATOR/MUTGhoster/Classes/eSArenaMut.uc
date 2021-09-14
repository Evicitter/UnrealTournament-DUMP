//-----------------------------------------------------------
//Created by -=EVILemitter=-
//-----------------------------------------------------------
class eSArenaMut expands Mutator native config(CFG_MUTGhoster);

var() globalconfig bool bDestroyDMMut;
var() globalconfig byte CurWeaponNum;
var() globalconfig class<Weapon> cDefWeapon[24];
var const transient class<Ammo> LoadAmmo;

native final function bool nAlwaysKeep(Actor O);
native function bool CheckReplacement(Actor Other, out byte bSuperRelevant);
native function String GetHumanName();
native function AddMutator(Mutator M);

function bool AlwaysKeep(Actor O)
{
 if(nAlwaysKeep(O)) return true;
 return super.AlwaysKeep(O);
}

DefaultProperties
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

 DefaultWeapon=class'DoubleEnforcer'
 CurWeaponNum=12
 cDefWeapon(0)=class'UnrealShare.ASMD'
 cDefWeapon(1)=class'UnrealShare.AutoMag'
 cDefWeapon(2)=class'UnrealShare.DispersionPistol'
 cDefWeapon(3)=class'UnrealShare.Eightball'
 cDefWeapon(4)=class'UnrealShare.Stinger'
 cDefWeapon(5)=class'UnrealI.FlakCannon'
 cDefWeapon(6)=class'UnrealI.GESBioRifle'
 cDefWeapon(7)=class'UnrealI.Minigun'
 cDefWeapon(8)=class'UnrealI.Rifle'
 cDefWeapon(9)=class'UnrealI.RazorJack'
 cDefWeapon(10)=class'Botpack.UT_BioRifle'
 cDefWeapon(11)=class'Botpack.Enforcer'
 cDefWeapon(12)=class'Botpack.DoubleEnforcer'
 cDefWeapon(13)=class'Botpack.ImpactHammer'
 cDefWeapon(14)=class'Botpack.Minigun2'
 cDefWeapon(15)=class'Botpack.Ripper'
 cDefWeapon(16)=class'Botpack.WarHeadLauncher'
}
