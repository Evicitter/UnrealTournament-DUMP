//----------------------------------------
//CONTINUE FILE >>>>>>>>>>>>>>>
//----------------------------------------	
	//Variable's.
	ABurnerProj* xDef;

	// Constructors.
	ABurnerProj() {}

	static const TCHAR* StaticConfigName() {return TEXT("CFG_MUTGhoster");}
	
	void ProcessEvent( UFunction* Function, void* Parms, void* Result=NULL )
	{
	}

	//Remaking ------------------------------------------------------------------
	void eventFellOutOfWorld()
    {
	 Super::ProcessEvent(FindFunctionChecked(ENGINE_FellOutOfWorld),NULL);
    }

	BITFIELD eventEncroachingOn(class AActor* Other)
    {
	 if ( Other && (Other->Brush || Other->IsA(ABrush::StaticClass())) )
	  return 1;
	 return 0;
    }
	//------------------------------

	UBOOL Tick( FLOAT DeltaTime, enum ELevelTick TickType );

	void Spawned()
	{
	 Super::Spawned();
	 xDef = (ABurnerProj*)GetClass()->GetDefaultActor();
	 xDef->AllProjs.AddItem(this);
	}

	void Destroy()
	{
	 xDef->AllProjs.RemoveItem(this);
	 xDef = NULL;
	 Super::Destroy();
	}
 
	//Reson Destroy ----------------------------------
	AActor* GetTopOwner() { return NULL; }
	FRotator GetViewRotation() { return Rotation; }
	//-------------------------------------------------
/*-------------------------
	The End.
----------------------------*/