// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================

#include "MUTGhosterPrivate.h" 

IMPLEMENT_CLASS(AeSArenaMut);
IMPLEMENT_FUNCTION (AeSArenaMut, -1, execnAlwaysKeep);
IMPLEMENT_FUNCTION (AeSArenaMut, -1, execCheckReplacement);
IMPLEMENT_FUNCTION (AeSArenaMut, -1, execGetHumanName);
IMPLEMENT_FUNCTION (AeSArenaMut, -1, execAddMutator);

void AeSArenaMut::Spawned() //------------------------------------
{
 AMutator::Spawned();

 //SaveConfig(CPF_Config,StaticConfigName());

 if(bDestroyDMMut && Level->Game->BaseMutator->GetClass()->GetFName() == FName(TEXT("DMMutator")))
 {
  XLevel->DestroyActor(Level->Game->BaseMutator);
  Level->Game->BaseMutator = this;
  Level->Game->bCoopWeaponMode = 0;
 }

 DefaultWeapon = cDefWeapon[CurWeaponNum];

 if(DefaultWeapon)
  LoadAmmo = ((AWeapon*)(DefaultWeapon->GetDefaultActor()))->AmmoName;
}

void AeSArenaMut::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("eSArenaMut"));
}

void AeSArenaMut::execAddMutator (FFrame& Stack, RESULT_DECL)
{
 P_GET_OBJECT(AMutator,M);
 P_FINISH;

 if(!Level->Game || !M || (M->GetClass()->GetFName() == FName(TEXT("Arena"))))
	return;

 for(AMutator* Cur = Level->Game->BaseMutator; true; Cur = Cur->NextMutator)
  if(Cur && !Cur->NextMutator)
  {
   Cur->NextMutator = M;
   break;
  }
}

void AeSArenaMut::execnAlwaysKeep (FFrame& Stack, RESULT_DECL)
{
 guard (AeSArenaMut::execnAlwaysKeep); 

 P_GET_ACTOR(Other);
 P_FINISH;

 if ( Other->GetClass() == DefaultWeapon) // .IsA(WeaponName) )
 {
  AWeapon* W = (AWeapon*)Other;
   W->PickupAmmoCount = ((AAmmo*)(LoadAmmo->GetDefaultActor()))->MaxAmmo;

  *(UBOOL*)Result=1;
  return;
 }
 else if ( Other->GetClass() == LoadAmmo )
 {
  AAmmo* A = (AAmmo*)Other;
  A->AmmoAmount = A->MaxAmmo;
  *(UBOOL*)Result=1;
  return;
 }
 
 *(BITFIELD*)Result=0;

 unguardexec;
}

void AeSArenaMut::execCheckReplacement (FFrame& Stack, RESULT_DECL)
{
 guard (AeSArenaMut::execCheckReplacement); 
 
 P_GET_ACTOR(Other);
 P_GET_BYTE(B);
 P_FINISH;

 if ( Other->IsA(AWeapon::StaticClass()) )
 {
  if(!DefaultWeapon)
  {
	 *(UBOOL*)Result = 0;
	 return;
  }
  else if (DefaultWeapon && (Other->GetClass() != DefaultWeapon))
  {
   nReplaceWith(Other, DefaultWeapon);
   *(UBOOL*)Result = 0;
	return;
  }
 }
 else if ( Other->IsA(AAmmo::StaticClass()) )
 {
  if (!LoadAmmo)
  {
	*(UBOOL*)Result = 0;
	return;
  }
  else if (LoadAmmo && (Other->GetClass() != LoadAmmo))
  {
   nReplaceWith(Other, LoadAmmo);
	*(UBOOL*)Result = 0;
	return;
  }
 }

 *(UBOOL*)Result = 1;
 unguardexec;
}

void AeSArenaMut::nReplaceWith(AActor* O, UClass* C)
{
 AActor* A;

 if ( C )
  A = XLevel->SpawnActor( C, O->Tag, O->Owner, O->Instigator, O->Location, O->Rotation );
 
 if(!A)
	return;

 if ( O->IsA(AInventory::StaticClass()) )
 {
  Inventory = (AInventory*)O;
   if ( Inventory->myMarker )
   {
    Inventory->myMarker->markedItem = (AInventory*)A;
	if ( A->IsA(AInventory::StaticClass()) )
	{
	 ((AInventory*)A)->myMarker = Inventory->myMarker;
	  A->Location += FVector(0,0, A->CollisionHeight - O->CollisionHeight);
	}
	Inventory->myMarker = NULL;
   }
   else if (A->IsA(AInventory::StaticClass()) )
   {
	Inventory = (AInventory*)A;
	Inventory->bHeldItem = 1;
	Inventory->RespawnTime = 0.0;
   }
 }

  A->Event = O->Event;
}