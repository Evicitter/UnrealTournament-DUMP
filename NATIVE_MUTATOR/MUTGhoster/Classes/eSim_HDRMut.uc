//-----------------------------------------------------------
//Created by -=EVILemitter=-
//-----------------------------------------------------------
class eSim_HDRMut expands eTestHUDMut native;

var transient const bool isFound;
var transient PlayerPawn pPawn;

function PostRender( canvas C );
function bool CheckReplacement(Actor Other, out byte bSuperRelevant) { return true; }
function bool IsRelevant(Actor Other, out byte bSuperRelevant)
{
 if( NextMutator != None )
  return NextMutator.IsRelevant(Other, bSuperRelevant);
 return true;
}

DefaultProperties
{
 NetUpdateFrequency=1.0
 RemoteRole=ROLE_DumbProxy
 bNet=True
 bNetSpecial=True
 bStasis=False
 NetPriority=0.5
}
