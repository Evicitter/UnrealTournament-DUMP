// ================================================== 
// Project: Native Function
// 
// CREATED BY (( Alexander -=EVILemitter=- BRAGIN ))
// ==================================================

#include "MUTGhosterPrivate.h" 

IMPLEMENT_CLASS(AeLensFlareMut);
IMPLEMENT_FUNCTION (AeLensFlareMut, -1, execPostRender);
IMPLEMENT_FUNCTION (AeLensFlareMut, -1, execGetHumanName);
IMPLEMENT_FUNCTION (AeLensFlareMut, -1, execCheckReplacement);

void AeLensFlareMut::execGetHumanName (FFrame& Stack, RESULT_DECL)
{
 Stack.Code++;
 *(FString*)Result = FString(TEXT("eLensFlareMut"));
}

void AeLensFlareMut::execCheckReplacement (FFrame& Stack, RESULT_DECL)
{
 guard (AeLensFlareMut::execCheckReplacement); 

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

 *(UBOOL*)Result = 1;

 unguardexec;
}

//Главное рисование (Lens Flare) - "Рассеивание в объективе"
void AeLensFlareMut::execPostRender (FFrame& Stack, RESULT_DECL)
{
 guard (AeLensFlareMut::execPostRender);

 P_GET_OBJECT(UCanvas,C);
 P_FINISH;					//Останавливаем код стека, и передаём эстафету другому коду.

 MainDrawLens(C);
 
 if(NextHUDMutator && NextHUDMutator->bHUDMutator) //Передаём запуск следующему объекту.
	NextHUDMutator->eventPostRender(C);
 unguardexec;
}

void AeLensFlareMut::MainDrawLens(UCanvas* Can)
{
 APlayerPawn* P = Can->Viewport->Actor;

 if(P)		//Ну если наблюдатель существует.
 {
  ALight* Other;
  FVector Dir, V;
  float Dist, ScaleX, ScaleY, fLen;	//Дистанция до лампы.
  FCheckResult Hit(1.0f);

  ScaleX = Can->Viewport->SizeX / 640.0;	//Норм. число размера X экрана.
  ScaleY = Can->Viewport->SizeY / 480.0;	//Норм. число размера Y экрана.

  FVector C(Can->ClipX*0.5f, Can->ClipY*0.5f, 0); 

  AActor* Angus;
  P->eventPlayerCalcView(Angus,V,Rotation);

  FCoords FC = GMath.UnitCoords / Rotation;	//Переведём углы эйлера в 3 вектора.
  FC.Origin = P->Location;						//Поставим позицию наблюдателя.
  BYTE m=0;

  for(int i=1;i < XLevel->Actors.Num();i++)		//Переберём весь список объектов.
	if(XLevel->Actors(i) &&												//Объект существует.
	   XLevel->Actors(i)->IsA(ALight::StaticClass()) &&					//И это лампочка.
	   (Dist = FDist(XLevel->Actors(i)->Location, FC.Origin)) < RadiusScan) //И растояние меньше радиуса сканирования.
	{
	 Other = (ALight*)XLevel->Actors(i);								//Вставим раб. лампу.
	 //Если у лампы включена корона
	 //И угол между векторами взгляда и вектором напр. до лампы, больше по половине косинуса угла обзора камеры.
	 //И луч доходит до лампы.
	 if(Other->bCorona && (((Dir = (Other->Location - FC.Origin)/Dist) | FC.XAxis) > appCos(P->FovAngle * UCONST_hPi)) && 
		XLevel->SingleLineCheck(Hit, P, FC.Origin, Other->Location, TRACE_AllColliding))
	 {
		if(m == MaxLensScr)
		 break;
		m++;

		V = WorldToScr(Can, Other->Location) - C;
		fLen = V.Size2D(); 
		V /= fLen;
		//Работа над конвасом..............
		Can->Style = STY_Translucent; //STY_Additive;
		FPlane Fclr = FGetHSV(Other->LightHue, Other->LightSaturation, 255 - (255 * (1-((Dir | FC.XAxis)*UCONST__RadOdn))) ); //hls2rgb(Other.LightHue, 15, 75);
		float vxl = V.X*fLen; 
		float vyl = V.Y*fLen;
		float dsx = 32*ScaleX;
		float dsy = 32*ScaleY;

		dDIcon(Can,3,dsx,dsy,Fclr, (vxl*1.2)-dsx+C.X, (vyl*1.2)-dsy+C.Y);

		dDIcon(Can,1,dsx,dsy,Fclr, vxl-dsx+C.X, vyl-dsy+C.Y);
		dsx = 64*ScaleX;
		dsy = 64*ScaleY;

		dDIcon(Can,1,dsx,dsy,Fclr, (vxl*0.66)-dsx+C.X, (vyl*0.66)-dsy+C.Y);

		dDIcon(Can,0,dsx,dsy,Fclr, (vxl*0.33)-dsx+C.X, (vyl*0.33)-dsy+C.Y);

		dDIcon(Can,2,dsx,dsy,Fclr, (vxl*0.125)-dsx+C.X, (vyl*0.125)-dsy+C.Y);

		dDIcon(Can,3,dsx,dsy,Fclr, (vxl*-0.21)-dsx+C.X, (vyl*-0.21)-dsy+C.Y);
		dsx = 32*ScaleX;
		dsy = 32*ScaleY;

		dDIcon(Can,4,dsx,dsy,Fclr, (vxl*-0.3)-dsx+C.X, (vyl*-0.3)-dsy+C.Y);
		dsx = 90*ScaleX;
		dsy = 90*ScaleY;

		dDIcon(Can,4,dsx,dsy,Fclr, (vxl*-0.5)-dsx+C.X, (vyl*-0.5)-dsy+C.Y);
	 }
	}
 }
}

FVector AeLensFlareMut::WorldToScr(UCanvas* C, FVector V)
{
 AActor* A;
 FVector t;
 FRotator R;
 
 t = V;
 C->Viewport->Actor->eventPlayerCalcView(A, V, R);
 t -= V;
 t /= t.Size();
 
 FCoords S = GMath.UnitCoords / R;
 
 V.Z = (t | S.XAxis) / appTan(C->Viewport->Actor->FovAngle * UCONST_hPi);
 V.X = C->ClipX*0.5f;
 V.Y = C->ClipY*0.5f;
 return FVector(V.X + (t | S.YAxis) * (V.X / V.Z),
 	            V.Y + (-(t | S.ZAxis)) * (V.Y / V.Z), 0);
}