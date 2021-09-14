//----------------------------------------
//CONTINUE FILE >>>>>>>>>>>>>>>
//----------------------------------------	
 // Constructors.
	AeLensFlareMut() {}

	static const TCHAR* StaticConfigName() {return TEXT("CFG_MUTGhoster");}
	//void Spawned();

	void eventPostRender(class UCanvas* Canvas)
	{
	 MainDrawLens(Canvas);
    }
	void ProcessEvent( UFunction* Function, void* Parms, void* Result=NULL )
	{
	 //	GLog->Logf(TEXT("Func= %s"), Function->GetName() );
	}

	/*UBOOL Tick( FLOAT DeltaTime, enum ELevelTick TickType )
	{
	 return 0;
	}*/
	AActor* GetTopOwner() { return NULL; }
	void SetCollision( UBOOL NewCollideActors, UBOOL NewBlockActors, UBOOL NewBlockPlayers) {}
	void SetCollisionSize( FLOAT NewRadius, FLOAT NewHeight ) {}
	void SetBase(AActor *NewBase, int bNotifyActor=1) {}
	FRotator GetViewRotation() { return Rotation; }
	void setPhysics(BYTE NewPhysics, AActor *NewFloor = NULL) {}
	void FindBase() {}

	void MainDrawLens(UCanvas* Canvas); //Main Drawing function Lens Flares effect.

	//EVILemitter ___ My Macros >>
	//#define sSetPos(CNV,SPX,SPY) CNV->CurX = SPX; CNV->CurY = SPY; //For Canvas
	#define dDIcon(Can,IdTex,mXL,mYL,Clr,SPX,SPY) Can->DrawTile(LensTex[IdTex],SPX,SPY,mXL*2,mYL*2,0,0,LensTex[IdTex]->USize,LensTex[IdTex]->VSize,NULL,Can->Z,Clr,FPlane(0,0,0,0),PF_Translucent);
	//End <<													 1				2	3	4	 5	   67			8						9			10		11		12			13				14		15
	//Macros Description ::
	//sSetPos ( Var. Canvas,,,, Var X Position ........ Var Y Position.....
	//dDIcon( Var. Canvas.... Id of Texture .... XL posTrine, YL posTrine .... Color of material...
	//END __<<

	//My Mega Silence function...................
	FVector WorldToScr(UCanvas* C, FVector V); //Convert World Loc. in Screen Pos.
/*-----------------------------------------------------------------
	The End.
----------------------------------------------------------------*/