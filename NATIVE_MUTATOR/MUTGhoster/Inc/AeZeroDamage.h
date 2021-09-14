//----------------------------------------
//CONTINUE FILE >>>>>>>>>>>>>>>
//----------------------------------------
	// Constructors.
	AeZeroDamage() {}

	static const TCHAR* StaticConfigName() {return TEXT("CFG_MUTGhoster");}
	void Spawned();
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

	/*static UBOOL StaticExec( const TCHAR* Cmd, FOutputDevice& Ar=*GLog )
	{
	 const TCHAR* Str = Cmd;


	 return AMutator::StaticExec(Cmd,Ar);
	}*/
	
	/*UBOOL ScriptConsoleExec( const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor )
	{
	 debugf(TEXT("WOW=============== %s"), Cmd);
	 return AMutator::ScriptConsoleExec(Cmd, Ar, Executor);
	}*/
	
/*-------------------------
	The End.
----------------------------*/