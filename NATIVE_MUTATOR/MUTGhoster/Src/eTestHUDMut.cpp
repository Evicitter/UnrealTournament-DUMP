// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================

#include "MUTGhosterPrivate.h" 

IMPLEMENT_CLASS(AeTestHUDMut);
IMPLEMENT_FUNCTION (AeTestHUDMut, -1, execPostRender);
IMPLEMENT_FUNCTION (AeTestHUDMut, -1, execCheckReplacement);
IMPLEMENT_FUNCTION (AeTestHUDMut, -1, execGetHumanName);

void AeTestHUDMut::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("eTestHUDMut"));
}

void AeTestHUDMut::execCheckReplacement (FFrame& Stack, RESULT_DECL) 
{ 
 guard (AeTestHUDMut::execCheckReplacement); 
 
 P_GET_ACTOR(O);
 P_GET_BYTE(B);
 P_FINISH;

 if(O->IsA(AHUD::StaticClass()))
 {
	 AHUD* H = (AHUD*)O;
	 NextHUDMutator = H->HUDMutator;
	 H->HUDMutator = this;
	 bHUDMutator = 1;
 }

 *(UBOOL*)Result=1;

 unguardexec;
}

void AeTestHUDMut::execPostRender (FFrame& Stack, RESULT_DECL) 
{ 
 guard (AeTestHUDMut::execPostRender); 
 
 P_GET_OBJECT(UCanvas,C);
 P_FINISH;

 PreDrawerAim(C);

 if(NextHUDMutator && NextHUDMutator->bHUDMutator) //Передаём запуск следующему объекту.
	NextHUDMutator->eventPostRender(C);

 unguardexec; 
}

void AeTestHUDMut::PreDrawerAim(UCanvas* uCan)
{
 uCan->Font = UsingFont;			//Установить фонт.
 if( Level->bHighDetailMode )	//Если высокая детализация то стиль
  uCan->Style = STY_Translucent; //3;	.... прозрачный.
 else
  uCan->Style = STY_Normal;		//1;	.... иначе нормальный.
 
 //Преобразуем угол Эйлера в 3 вектора.
 FCoords SC = GMath.UnitCoords / uCan->Viewport->Actor->Rotation; //Трансформируем в 3 вектора из углов Эйлера.
 SC.Origin = uCan->Viewport->Actor->Location;			//Ставим позицию наблюдателя.
 //0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-0-

 FCheckResult Hit(1.0f);
 APawn* P;					//Ссылка на отобранную пешку.
 FVector Dir;			//Вектор направления от наблюдателя к др пешке.
 float Dist;		

 for(P = Level->PawnList; P; P = P->nextPawn)	//Общий цикл поиска всех пешек.
 {
  if(P == uCan->Viewport->Actor)
   continue;

  Dir = P->Location - SC.Origin;	//Вектор напр. от пешки до наблюдателя.
  Dist = Dir.Size();				//Растояние вектора направления.
  Dir /= Dist;						//Теперь вектор направлен в сторону заложника.
  //Если заложник жив
  //(И) угол между векторами по косинусу больше угла взгляда. (UCONST_hPi = 0.5 * Pi / 180)
  //(И) луч достигает точки.
  if((P->Health > 0) &&
	 ((Dir | SC.XAxis) > appCos(uCan->Viewport->Actor->FovAngle * UCONST_hPi)) &&
	  XLevel->SingleLineCheck( Hit, P, P->Location, SC.Origin, TRACE_AllColliding ) )
  {	
    int xPos, yPos;
	xPos = 0.5 * uCan->ClipX * (1 + 1.4 * (Dir | SC.YAxis));
	yPos = 0.5 * uCan->ClipY * (1 - 1.4 * (Dir | SC.ZAxis));
	uCan->DrawTile(tDrawTex, xPos - 8, yPos - 8, tDrawTex->USize, tDrawTex->VSize, 0, 0, tDrawTex->USize, tDrawTex->VSize, NULL, uCan->Z, FPlane(1,1,1,1), FPlane(0,0,0,0), 0);
	uCan->CurX = xPos - 12;
	uCan->CurY = yPos + 8;
	uCan->WrappedPrintf(uCan->Font, 0, TEXT("%i"), Dist);
  }
 }
 //End function.
}
