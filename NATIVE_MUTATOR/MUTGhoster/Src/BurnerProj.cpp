// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================
#include "MUTGhosterPrivate.h" 

IMPLEMENT_CLASS(ABurnerProj);
IMPLEMENT_FUNCTION (ABurnerProj, -1, execGetHumanName);
IMPLEMENT_FUNCTION (ABurnerProj, -1, execSetDisplayProperties);
IMPLEMENT_FUNCTION (ABurnerProj, -1, execSetDefaultDisplayProperties);
IMPLEMENT_FUNCTION (ABurnerProj, -1, execProcessTouch);

//--------------------------------------------------------------------------
void ABurnerProj::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("BurnerProj"));
}

void ABurnerProj::execSetDisplayProperties (FFrame& Stack, RESULT_DECL)
{
 P_GET_BYTE(A);
 P_GET_OBJECT(UTexture,B);
 P_GET_UBOOL(C);
 P_GET_UBOOL(D);
 P_FINISH;
 Style = A;
 Texture = B;
 bUnlit = C;
 bMeshEnviroMap = D;
}

void ABurnerProj::execSetDefaultDisplayProperties (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 Style = xDef->Style;
 Texture = xDef->Texture;
 bUnlit = xDef->bUnlit;
 bMeshEnviroMap = xDef->bMeshEnviroMap;
}
//--------------------------------------------------------------------------

void ABurnerProj::execProcessTouch (FFrame& Stack, RESULT_DECL)
{
 P_GET_ACTOR(Other);
 P_GET_VECTOR(HL);
 P_FINISH;

 if(!Other)
  return;

 ABurnerProj* FinalBurn;

 if ( Other->IsA(APawn::StaticClass()) )
 {
  for(int i=xDef->AllProjs.Num(); i >= 0; i--)
   if(xDef->AllProjs(i)->Base == Other)
   {
    FinalBurn = xDef->AllProjs(i);
	break;
   }

  if(!FinalBurn)
  {
   FinalBurn = (ABurnerProj*)XLevel->SpawnActor( GetClass(), xDef->GetFName(), Instigator, Instigator, Location, Other->Rotation);
   FinalBurn->Lifetime = 1.0;
   FinalBurn->SetBase(Other);
  }
   else
    FinalBurn->Lifetime += 5.0;
 }
}

UBOOL ABurnerProj::Tick( FLOAT DeltaTime, enum ELevelTick TickType )
{
 UBOOL B = Super::Tick(DeltaTime, TickType);

 if(!B)
  return 0;

 HurtTime += DeltaTime;
 Lifetime -= DeltaTime;
 
 if(HurtTime > 0.3 && Base)
 {
  Base->eventTakeDamage(Damage,Instigator,Location,FVector(0,0,0),MyDamageType);
  HurtTime=0;
 }

 if( (Lifetime < 0) || !Base)
  eventFellOutOfWorld();

 return 1;
}
