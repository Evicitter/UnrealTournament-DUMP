//----------------------------------------
//CONTINUE FILE >>>>>>>>>>>>>>>
//----------------------------------------	
 // Constructors.
	AeSArenaMut() {}

	static const TCHAR* StaticConfigName() {return TEXT("CFG_MUTGhoster");}
	
	void ProcessEvent( UFunction* Function, void* Parms, void* Result=NULL )
	{
	}

	void Spawned();

	void nReplaceWith(AActor* A, UClass* C);

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
	/*static void StaticInit()
	{
	 GLog->Logf(TEXT("AAAAAAAA______________StaticInit"));
	 AMutator::StaticInit();
	}

	static void StaticExit()
	{
		GLog->Logf(TEXT("AAAAAAAA______________StaticExit"));
	 AMutator::StaticExit();	
	}

	static void BeginLoad()
	{
	 GLog->Logf(TEXT("AAAAAAAA______________BeginLoad"));
	 AMutator::BeginLoad();
	}
	static void EndLoad()
	{
	 GLog->Logf(TEXT("AAAAAAAA______________EndLoad"));
	 AMutator::EndLoad();
	}

	static void InitProperties( BYTE* Data, INT DataCount, UClass* DefaultsClass, BYTE* Defaults, INT DefaultsCount )
	{
	 GLog->Logf(TEXT("AAAAAAAA__________InitProperties"));
	 AMutator::InitProperties(Data, DataCount, DefaultsClass, Defaults, DefaultsCount);
	}
	
	void PostLoad()
	{
     GLog->Logf(TEXT("AAAAAAAA__________PostLoad"));
	 AMutator::PostLoad();
	}

	UBOOL ScriptConsoleExec( const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor )
	{
	 GLog->Logf(TEXT("AAAAAAAA__________ScriptConsoleExec"));
	 return 1;
	}

	void LoadConfig( UBOOL Propagate=0, UClass* Class=NULL, const TCHAR* Filename=NULL )
	{
     GLog->Logf(TEXT("AAAAAAAA___LoadConfig"));
	}*/
/*-------------------------
	The End.
----------------------------*/