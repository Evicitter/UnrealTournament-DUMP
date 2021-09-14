//-----------------------------------------------------------
//Created by -=EVILemitter=-
//Message Mutator
// -------------------------------------------------------------------------
// %n - имя игрока
// %l - положение игрока
// %s - статус игрока (здоровье/броня)
// %sa - подробный статус игрока (имя игрока/ здоровье/ броня / група оружия /патроны)
// %h - здоровье игрока
// %a - броня игрока
// %aw - Колчество патронов
// %i - Показывает видим ли игрок, если нет то сколько осталось невидимости.
// %b - друзья, перечисляет всех "дружественных" игроков в определенном радиусе
// %w - оружие игрока
// %% - выводит символ '#'
// --------------------------------------------------------------------------
//-----------------------------------------------------------
class eProMesMut expands Mutator native;

var() class<Pickup> InvisPic1, InvisPic2;
//----------------------------------------------
var transient PlayerPawn LastSender;
var transient Pawn LastReceiver;
var transient PlayerReplicationInfo LastPRI;
var transient string LastMSG, LastCombineMSG;

native final simulated function nChat(PlayerPawn Sender, Pawn Receiver, PlayerReplicationInfo PRI, string Msg);
native function String GetHumanName();

function bool MutatorTeamMessage( Actor Sender, Pawn Receiver, PlayerReplicationInfo PRI, coerce string S, name Type, optional bool bBeep )
{
 if(PlayerPawn(Sender) != None)
 {
  nChat(PlayerPawn(Sender), Receiver, PRI, S);
  return false;
 }
 return super.MutatorTeamMessage(Sender, Receiver, PRI, S, Type, bBeep);
}

defaultproperties
{
 NetUpdateFrequency=1.0
 RemoteRole=ROLE_None
 bNet=False
 bNetSpecial=False
 ScaleGlow=0.0
 bMovable=False
 SoundRadius=0
 SoundVolume=0
 SoundPitch=0
 TransientSoundVolume=0.0
 CollisionRadius=0.0
 CollisionHeight=0.0
 bJustTeleported=False
 Mass=1.0
 NetPriority=0.1
 bScriptInitialized=True
 bStasis=True

 InvisPic1=class'UT_Invisibility'
 InvisPic2=class'Invisibility'
}
