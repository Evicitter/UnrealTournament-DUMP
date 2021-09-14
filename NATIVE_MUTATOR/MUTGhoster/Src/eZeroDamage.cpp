// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================

#include "MUTGhosterPrivate.h" 

IMPLEMENT_CLASS(AeZeroDamage);
IMPLEMENT_FUNCTION (AeZeroDamage, -1, execnCurMutDamage);
IMPLEMENT_FUNCTION (AeZeroDamage, -1, execGetHumanName);

void AeZeroDamage::Spawned()	//virtual void Spawned();
{
	AMutator::Spawned(); // Эта функция вызывается при инициализации любого актора

	if (bInitCurMut)
		 return;
	bInitCurMut = 1;
	
	// Регистрация damage мутатора
	if(Level && Level->Game)
	{
	 GLog->Logf( TEXT("------ ZeroDamage mutator ------") );
	 NextDamageMutator = Level->Game->DamageMutator; //M.NextDamageMutator = DamageMutator;
	 Level->Game->DamageMutator = this;						//DamageMutator = M;
	}
}

void AeZeroDamage::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("eZeroDamage"));
}

// Эта функция вызывается для зарегистрированных damage мутаторов
// перед подсчетом финального ущерба
void AeZeroDamage::execnCurMutDamage (FFrame& Stack, RESULT_DECL) 
{ 
 guard (AeZeroDamage::execnCurMutDamage);

 P_GET_OBJECT(APawn,V);
 P_GET_OBJECT(APawn,K);
 P_GET_NAME(C);
 P_FINISH;
 
 if(bIsDebug) // Сообщения для отладки
  {
   if(V && V->PlayerReplicationInfo)
    eventBroadcastMessage( FString(TEXT("Victim: ")) + V->PlayerReplicationInfo->PlayerName, 0, NAME_None );
   if(K && K->PlayerReplicationInfo)
    eventBroadcastMessage( FString(TEXT("Killer: ")) + K->PlayerReplicationInfo->PlayerName, 0, NAME_None );
   eventBroadcastMessage( FString::Printf(TEXT("ActualDamage: %i"), LastDam) , 0, NAME_None );
  }

  // Увеличиваем момент
  LastMom += FVector(LastDam, LastDam, LastDam);
  
  // Обнуляем полученные повреждения только если киллер - игрок
  if (K->IsA(APawn::StaticClass()))
	  LastDam=0;
  
  // Если падение с высоты, то дамаж уменьшаем, но не обнуляем
  if (C == FName(TEXT("Fell")))
    LastDam/=2;
  
  FName Fn = V->HeadRegion.Zone->GetClass()->GetFName();
  if( ( Fn == FName(TEXT("PressureZone")))  ||
      ( Fn == FName(TEXT("VacuumZone")))    ||
	  ( Fn == FName(TEXT("LavaZone")))	    ||
	  ( Fn == FName(TEXT("KillingField")))  ||
      V->HeadRegion.Zone->bKillZone         ||
	  V->HeadRegion.Zone->bPainZone		    ||
	  V->HeadRegion.Zone->bDestructive)
	LastDam = V->Health; //- не имеет общее значение.

  if(LastDam != V->Health)
  {
   V->DieCount++;	//добавим к (Общее кол-во сметрей у жертвы)
   K->KillCount++;  //добавим к (Общее кол-во убийств у убийцы)
   if(V->PlayerReplicationInfo)
	  V->PlayerReplicationInfo->Score-=1; //отнимем очко у жертвы
   if(K->PlayerReplicationInfo  )
	  K->PlayerReplicationInfo->Score += 1; //... и дадим его убийце.
  }
 unguardexec; 
}