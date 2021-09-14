//----------------------------------------
//CONTINUE FILE >>>>>>>>>>>>>>>
//----------------------------------------	
 // Constructors.
	AeSim_HDRMut() {}

	static const TCHAR* StaticConfigName() {return TEXT("CFG_MUTGhoster");}
	void Spawned()
	{
		isFound=0;
		
		if(Level->NetMode == NM_DedicatedServer)
	     LifeSpan = 1.0;

		AActor::Spawned();

		/*for(int i=0;i < XLevel->Actors.Num(); i++)
		{
		 if(XLevel->Actors(i))	GLog->Logf(TEXT("Actor(%i)=%s"), i, XLevel->Actors(i)->GetName());
		}*/
	}


	UBOOL Tick( FLOAT DeltaTime, enum ELevelTick TickType );

	void execGetHumanName (FFrame& Stack, RESULT_DECL);

	void eventPostRender(class UCanvas* Canvas)
	{
	}
	void ProcessEvent( UFunction* Function, void* Parms, void* Result=NULL )
	{
	}
	AActor* GetTopOwner() { return NULL; }
	void SetCollision( UBOOL NewCollideActors, UBOOL NewBlockActors, UBOOL NewBlockPlayers) {}
	void SetCollisionSize( FLOAT NewRadius, FLOAT NewHeight ) {}
	void SetBase(AActor *NewBase, int bNotifyActor=1) {}
	FRotator GetViewRotation() { return Rotation; }
	void setPhysics(BYTE NewPhysics, AActor *NewFloor = NULL) {}
	void FindBase() {}
/*-----------------------------------------------------------------
	The End.
----------------------------------------------------------------*/