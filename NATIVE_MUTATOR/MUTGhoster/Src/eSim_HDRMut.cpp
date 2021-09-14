// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================

#include "MUTGhosterPrivate.h" 

IMPLEMENT_CLASS(AeSim_HDRMut);

UBOOL AeSim_HDRMut::Tick( FLOAT DeltaTime, enum ELevelTick TickType )
{
 if(isFound)
 {
  AActor* A;
  FVector CL;
  FRotator CR;
  float cd, bd = 10000;	//Best Distance;
  ALight* L, *CurL;

  pPawn->eventPlayerCalcView(A,CL,CR);
  FCoords S = GMath.UnitCoords / CR;
  S.Origin = CL;

  for(int i=1;i < XLevel->Actors.Num();i++)
  {
   L = (ALight*)XLevel->Actors(i);
   if(L && L->bCorona && (L->LightType > LT_None))
   {
	if((cd = FDist(CL,L->Location)) < bd )
	{
	 bd = cd;
	 CurL = L;
	}
   }
  }

  if(CurL)
  {
   cd = S.XAxis | ((CurL->Location - S.Origin).UnsafeNormal());
   cd *= (float)(cd > 0.0);
   cd = (cd/CurL->LightRadius)*(CurL->LightRadius-bd);
   cd = cd<0 ? 0 : cd<1 ? cd : 1;
   pPawn->ConstantGlowFog = FVector( cd, cd, cd );
  }
 } 
 else
 {
  if(Level->NetMode == NM_DedicatedServer)
	  return 0;
  
  APawn* A;
  APlayerPawn* P;
   for(A = Level->PawnList; A; A = A->nextPawn)
   if(A && A->IsA(APlayerPawn::StaticClass()))
   {
	P = (APlayerPawn*)A;
	if(P->Player && P->Player->IsA(UViewport::StaticClass()))
	{
	 pPawn = P;
	 isFound = 1;
	 break;
	}
   }
 } 

 return 0;
}

void AeSim_HDRMut::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("eSim_HDRMut"));
}