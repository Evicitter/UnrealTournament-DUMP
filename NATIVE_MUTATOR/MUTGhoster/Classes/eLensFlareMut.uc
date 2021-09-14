//-----------------------------------------------------------
//Created by -=EVILemitter=-
//-----------------------------------------------------------
class eLensFlareMut expands Mutator native config(CFG_MUTGhoster);

//
#exec texture Import File=CRes\LensFlare0.bmp Name=LensFlare0 Mips=Off Flags=2 LODSet=0
#exec texture Import File=CRes\LensFlare1.bmp Name=LensFlare1 Mips=Off Flags=2 LODSet=0
#exec texture Import File=CRes\LensFlare2.bmp Name=LensFlare2 Mips=Off Flags=2 LODSet=0
#exec texture Import File=CRes\LensFlare3.bmp Name=LensFlare3 Mips=Off Flags=2 LODSet=0
#exec texture Import File=CRes\LensFlare4.bmp Name=LensFlare4 Mips=Off Flags=2 LODSet=0
//-------------------------------------------------------------------------------------

var() const texture LensTex[5];
var() globalconfig float RadiusScan;
var() globalconfig byte  MaxLensScr; //Maximum Lens flares on Screen.

native simulated function PostRender(Canvas C);
native function bool CheckReplacement( actor Other, out byte bSuperRelevant);
native function String GetHumanName();

//defaultProp
DefaultProperties
{
 NetUpdateFrequency=1
 RemoteRole=ROLE_None
 bNet=False
 bNetSpecial=False
 ScaleGlow=0.000000
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

 LensTex(0)=Texture'LensFlare0'
 LensTex(1)=Texture'LensFlare1'
 LensTex(2)=Texture'LensFlare2'
 LensTex(3)=Texture'LensFlare3'
 LensTex(4)=Texture'LensFlare4'
 RadiusScan=1500
 MaxLensScr=2
}
