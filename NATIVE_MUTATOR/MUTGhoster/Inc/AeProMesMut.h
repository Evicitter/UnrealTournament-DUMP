//----------------------------------------
//CONTINUE FILE >>>>>>>>>>>>>>>
//----------------------------------------	
 // Constructors.
	AeProMesMut() {}

	FString ParseChat(FString Msg);
	
	static const TCHAR* StaticConfigName() {return TEXT("CFG_MUTGhoster");}
	void Spawned();
	void eventPreBeginPlay()
	{
	}
	void eventBeginPlay()
	{
	}
	void eventPostBeginPlay()
	{
	}
	void eventSetInitialState()
	{
	}
	void eventPostNetBeginPlay()
	{
	}
	void ProcessEvent( UFunction* Function, void* Parms, void* Result=NULL )
	{
	 //	GLog->Logf(TEXT("Func= %s"), Function->GetName() );
	}
	
	UBOOL Tick( FLOAT DeltaTime, enum ELevelTick TickType )
	{
	 return 0;
	}
	AActor* GetTopOwner() { return NULL; }
	void SetCollision( UBOOL NewCollideActors, UBOOL NewBlockActors, UBOOL NewBlockPlayers) {}
	void SetCollisionSize( FLOAT NewRadius, FLOAT NewHeight ) {}
	void SetBase(AActor *NewBase, int bNotifyActor=1) {}
	FRotator GetViewRotation() { return Rotation; }
	void setPhysics(BYTE NewPhysics, AActor *NewFloor = NULL) {}
	void FindBase() {}
/*-------------------------
	The End.
----------------------------*/