//-----------------------------------------------------------
//Created by -=EVILemitter=-
//-----------------------------------------------------------
class eTestHUDMut expands Mutator native;

const hPi = 0.008726646;
const _DdnR = 0.196349541; //0.392699082 * 0.5; //Pi * 22.5 / 180;
const _OdnR = 0.100356432; //0.200712864 * 0.5; //11.5 == Pi * 11.5 / 180
const _RadOdn = 3.979874073;

var() const Font UsingFont;
var() const texture tDrawTex;

native simulated function PostRender( canvas C );
native function bool CheckReplacement(Actor Other, out byte bSuperRelevant);
native function String GetHumanName();

//defaultProp
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

 UsingFont=Font'TinyRedFont'
 tDrawTex=texture'CrossHair6'
}
