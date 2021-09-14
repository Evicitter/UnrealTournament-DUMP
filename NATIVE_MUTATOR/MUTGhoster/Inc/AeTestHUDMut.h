//----------------------------------------
//CONTINUE FILE >>>>>>>>>>>>>>>
//----------------------------------------
	// Constructors.
	AeTestHUDMut() {}

	static const TCHAR* StaticConfigName() {return TEXT("CFG_MUTGhoster");}
	
	void AeTestHUDMut::Spawned()
	{
	 AMutator::Spawned(); 
	 GLog->Logf( TEXT("---------------------------------") );
	 GLog->Logf( TEXT("--- BEGIN TestHUDMut ------------") );
	 GLog->Logf( TEXT("---------------------------------") );
	}

	void eventPostRender(class UCanvas* Canvas)
	{
	 PreDrawerAim(Canvas);
    }

	void ProcessEvent( UFunction* Function, void* Parms, void* Result=NULL )
	{
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

	void PreDrawerAim(UCanvas* C); //Main not event function.
/*-----------------------------------------
	The End.
-------------------------------------------*/