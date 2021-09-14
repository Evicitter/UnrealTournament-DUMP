// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================
#include "MUTGhosterPrivate.h" 

IMPLEMENT_CLASS(AeProMesMut);
IMPLEMENT_FUNCTION (AeProMesMut, -1, execnChat);
IMPLEMENT_FUNCTION (AeProMesMut, -1, execGetHumanName);

void AeProMesMut::Spawned()
{
	if(Level->Game)
	{
     NextMessageMutator = Level->Game->MessageMutator;
	 Level->Game->MessageMutator = this;
	}

	AMutator::Spawned();
}

void AeProMesMut::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("eProMesMut"));
}

void AeProMesMut::execnChat (FFrame& Stack, RESULT_DECL)
{ 
 guard (AeProMesMut::execnChat);

 P_GET_OBJECT(APlayerPawn,Sen);
 P_GET_OBJECT(APawn,Rec);
 P_GET_OBJECT(APlayerReplicationInfo, PRI);
 P_GET_STR(MSG);
 P_FINISH;

 LastSender = Sen;
 LastReceiver = Rec;
 LastPRI = PRI;
 LastMSG = MSG;
 LastCombineMSG = ParseChat(MSG);

 if(Rec)
    Rec->eventTeamMessage(PRI, LastCombineMSG, FName(TEXT("TeamSay")), 1);

 unguardexec; 
}

FString AeProMesMut::ParseChat(FString Msg)
{
 int i;
 FString nMsg;

 for(i=0; i <= Msg.Len(); i++)
 {
    if (Msg.Mid(i, 1) == TEXT("%"))
    {
      // найден escape символ %,
      // теперь необходимо узнать следующий за ним символ
      i += 1;

      // ---------------------------------------------------
      switch (appToUpper(Msg.Mid(i,1).GetCharArray()(0)))
      {
        // символ '%' - вставляет символ '%' (мало ли - может понадобится :)
        case 35: //%
		{
          nMsg += FString(TEXT("%"));
          break;
		}
		// броня игрока - вставляет количество Вашей брони
        case 65: //A
		{
         if(Msg.Mid(i+1, 1).Caps() == FString(TEXT("W")))
		 {
		  i++;
		  if(LastSender->Weapon && LastSender->Weapon->AmmoType)
		   nMsg += FString::Printf(TEXT("%i"), LastSender->Weapon->AmmoType->AmmoAmount);
		  else
		   nMsg += FString(TEXT("NoAMMO"));
		  break;
		 }
		 else
		 {
		  int amt = 0;
          for (Inventory = LastSender->Inventory; Inventory; Inventory = Inventory->Inventory)
           if (Inventory->bIsAnArmor)
            amt += Inventory->Charge;
          nMsg += FString::Printf(TEXT("%i"), amt);
          break;
		 }
		}
		// друзья - вставляет список друзей,
        // находящихся в определенном радиусе
        case 66: //B
		{
		  int numBuddy, lBuddyLen;
		  FString bStr, lbStr;
          APawn* Buddy;
		  APlayerReplicationInfo* bPRI;
			  
		  for(Buddy = Level->PawnList; Buddy; Buddy = Buddy->nextPawn)
		  {
            bPRI = Buddy->PlayerReplicationInfo;
            if (Buddy != LastSender && Buddy->bIsPlayer && bPRI->Team == LastPRI->Team)
            {
              lbStr = bPRI->PlayerName;
              lBuddyLen = lbStr.Len();
              if (numBuddy < 1)
                bStr = lbStr;
              else bStr += FString(TEXT(", ")) + lbStr;
              numBuddy++;
            }
          }

          // вставляем в список друзей союзы "and" между их именами
          // в случае если их больше одного.
          if (numBuddy >= 3)
            bStr = bStr.Left(bStr.Len() - lBuddyLen) + FString(TEXT(" and ")) + lbStr;
          else if (numBuddy == 2)
            bStr = bStr.Left(bStr.Len() - lBuddyLen - 2) + FString(TEXT(" and ")) + lbStr;
          else if (numBuddy == 0)
            bStr = FString(TEXT("nobody"));

          nMsg += bStr;
          break;
		}
		// здоровье игрока - вставляет количество Вашего здоровья
        case 72: //H
		{
		  nMsg += LastSender->Health > 0 ? FString::Printf(TEXT("%i"),LastSender->Health) : FString(TEXT("Is Death"));
          break;
		}
		//Показывает кличество невидимости
		case 73: //I
		{
          if(LastSender->Visibility <= 10)
		  {
		   for (Inventory = LastSender->Inventory; Inventory; Inventory = Inventory->Inventory)
			if(Inventory->GetClass()->IsChildOf(InvisPic1) || Inventory->GetClass()->IsChildOf(InvisPic2))
			{
			 nMsg += FString::Printf(TEXT("Is Not Visible... %i"), Inventory->Charge);
			 break;
			}
		  }
		  else
			 nMsg += FString(TEXT("Is Visible" ));
		  break;
		}
		// положение игрока - вставляет Ваше местоположение
        case 76: //L
		{
          if (LastPRI->PlayerLocation)
            nMsg += LastPRI->PlayerLocation->LocationName;
          else if (LastPRI->PlayerZone)
            nMsg += LastPRI->PlayerZone->ZoneName;
          else nMsg += FString(TEXT("somewhere"));
          break;
		}
		// имя игрока - вставляет Ваше имя
        case 78: //N
		{
          nMsg += LastPRI->PlayerName;
          break;
		}
		// статус игрока - вставляет Ваш статус (Health: xxx Armor: xxx)
        case 83: //S
		{
          if(Msg.Mid(i+1, 1).Caps() == FString(TEXT("A"))) //sa - подробный статус
		  {
			i++;
			
			if(!Level->Game->bTeamGame || ((LastReceiver->PlayerReplicationInfo && LastPRI) && LastReceiver->PlayerReplicationInfo->Team != LastPRI->Team))
			{
			 if (LastPRI->PlayerLocation)
              nMsg += LastPRI->PlayerLocation->LocationName;
             else if (LastPRI->PlayerZone)
              nMsg += LastPRI->PlayerZone->ZoneName;
             else nMsg += FString(TEXT("somewhere"));
			}

			 if(LastSender->Health > 0)
			 {
			  int ax=0;
				for (Inventory = LastSender->Inventory; Inventory; Inventory = Inventory->Inventory)
                 if (Inventory->bIsAnArmor) ax += Inventory->Charge;
				 nMsg += (LastSender->Weapon && LastSender->Weapon->AmmoType) ? FString::Printf(TEXT("_H:%i _A:%i _W:%i _P:%i"), LastSender->Health, ax, LastSender->Weapon->InventoryGroup, LastSender->Weapon->AmmoType->AmmoAmount) : FString::Printf(TEXT("_H:%i _A:%i"), LastSender->Health, ax);
			 }
			 else
			  nMsg += FString(TEXT("Is Death."));
		  }
		  else
		  {
		   int bmt = 0;
           for (Inventory = LastSender->Inventory; Inventory; Inventory = Inventory->Inventory)
            if (Inventory->bIsAnArmor)
              bmt += Inventory->Charge;
			nMsg += LastSender->Health > 0 ? FString::Printf(TEXT("Health: %i  Armor: %i"), LastSender->Health, bmt) : FString(TEXT("Is Death"));
		  }
          break;
		}
        // оружие игрока - вставляет наименование Вашего оружия
        case 87: //W
		{
		  if(LastSender->Weapon)
			nMsg += LastSender->Weapon->ItemName;
		  else
			nMsg += FString(TEXT("No Weapon"));
          break;
		}
        default:
          break;
      }
    }

    // если символ не является escape кодом (#),
    // просто дописываем его в конечную строку
    else nMsg += Msg.Mid(i, 1);
  }

  // и, наконец, возвращаем модифицированное сообщение
  return nMsg;
}
