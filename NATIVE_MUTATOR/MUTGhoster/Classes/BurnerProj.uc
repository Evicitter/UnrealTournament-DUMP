//-----------------------------------------------------------
//Created by -=EVILemitter=-
//-----------------------------------------------------------
class BurnerProj expands Projectile native;

var transient const float HurtTime;
var transient const float LifeTime;  //how long it lives
var() transient const array<BurnerProj> AllProjs;

native function string GetHumanName();
native function SetDisplayProperties(ERenderStyle NewStyle, texture NewTexture, bool bLighting, bool bEnviroMap );
native function SetDefaultDisplayProperties();
native simulated function ProcessTouch(Actor Other, Vector HitLocation);

DefaultProperties
{
 Damage=5.0
 MyDamageType=Burned
 Mesh=LodMesh'UnrealShare.FlameM'
 bUnlit=True
 bScriptInitialized=True
}
