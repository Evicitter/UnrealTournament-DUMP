// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================

#include "MUTGhosterPrivate.h" 

IMPLEMENT_PACKAGE(MUTGhoster); 
IMPLEMENT_CLASS(AeGhostMut);

IMPLEMENT_FUNCTION (AeGhostMut, -1, execnScoreKill);
IMPLEMENT_FUNCTION (AeGhostMut, -1, execCheckReplacement);
IMPLEMENT_FUNCTION (AeGhostMut, -1, execnMutatorTakeDamage);
IMPLEMENT_FUNCTION (AeGhostMut, -1, execGetHumanName);

void AeGhostMut::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("eGhostMut"));
}

void AeGhostMut::execnScoreKill (FFrame& Stack, RESULT_DECL) 
{ 
 guard (AeGhostMut::execnScoreKill);
 
 P_GET_OBJECT(APawn,K);	//is a Killer
 P_GET_OBJECT(APawn,O); //is a Other
 P_FINISH;

 /*if(K)
	 this->eventBroadcastMessage( FString::Printf(TEXT("GOOD_KILLER")),0,NAME_None );
   if(O)
	 this->eventBroadcastMessage( FString::Printf(TEXT("GOOD_OTHER")),0,NAME_None );*/

  if ((K != O) && O && K)
  {
    K->ScaleGlow += 0.2; // если у нас появился победитель, увеличим его glowing
    O->ScaleGlow = 1.5; // у жертвы сбросим glowing на исходное значение
  }

  // при суициде установим игроку то, что он заслужил :)
  if (O && (!K || (K == O)))
	  O->ScaleGlow = 1.5;

  // установим значение видимости (visibility) для того, чтобы боты нормально ее воспринимали
  O->Visibility = ((APawn *)(O->GetClass()->GetDefaultActor()))->Visibility * O->ScaleGlow;
  K->Visibility = ((APawn *)(O->GetClass()->GetDefaultActor()))->Visibility * K->ScaleGlow;

 unguardexec; 
}

void AeGhostMut::execCheckReplacement (FFrame& Stack, RESULT_DECL) 
{ 
 guard (AeGhostMut::execCheckReplacement); 
 
 P_GET_ACTOR(A);
 P_GET_INT(B);
 P_FINISH;

 //игроки, боты и каркасы (carcasses) (включая джибсы) должны также быть невидимыми
 if( A->IsA(APawn::StaticClass()) || A->IsA(ACarcass::StaticClass()))
     A->Style = STY_Translucent;
 
 // пикапы, дающие невидимость несколько неуместны
  // поэтому просто избавимся от них если они в стеке разумеется...
 if(A->GetClass()->IsChildOf(DestroyPU) || A->GetClass()->IsChildOf(DestroyPU2))
  *(UBOOL*)Result = 0;
 else
  *(UBOOL*)Result = 1;
 unguardexec; 
}

void AeGhostMut::execnMutatorTakeDamage (FFrame& Stack, RESULT_DECL) 
{ 
 guard (AeGhostMut::execnMutatorTakeDamage);

 P_GET_INT(A);
 P_GET_OBJECT(APawn,K);
 P_GET_OBJECT(APawn,O);
 P_FINISH;

 // уменьшаем glowing жертвы
 float dg = (float)A / 70.0;
 if(dg <= 0.1) dg = 0.1;
 K->ScaleGlow -= dg;
 if(K->ScaleGlow <= 0.1) K->ScaleGlow = 0.1;

 // увеличиваем glowing атакующего
 if (O != K) O->ScaleGlow += dg;

  // установим значение видимости (visibility) для того, чтобы боты нормально ее воспринимали
 K->Visibility = ((APawn*)(K->GetClass()->GetDefaultActor()))->Visibility * K->ScaleGlow;
 O->Visibility = ((APawn*)(O->GetClass()->GetDefaultActor()))->Visibility * O->ScaleGlow;

 unguardexec; 
}

void AeGhostMut::Spawned()	//virtual void Spawned();
{
	AMutator::Spawned(); 
	//GLog->Logf( TEXT("SPAWNED BEGIN") );
	if (Initialized) return;
	Initialized = 1;
	
	if(Level && Level->Game)
	{
	 NextDamageMutator = Level->Game->DamageMutator; //M.NextDamageMutator = DamageMutator;
	 Level->Game->DamageMutator = this;						//DamageMutator = M;
	}
}
