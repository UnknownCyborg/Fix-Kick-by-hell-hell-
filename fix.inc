//======================================================================
/*
	Owner hell'hell'.
	vk.com/dykan_vallik.
	all rights reserved.
*/
//======================================================================
#if defined _fix_included
  #endinput
#endif
#define _fix_included
//======================================================================
#if defined DELAY_KICK
	#undef DELAY_KICK
#endif
#define DELAY_KICK 1250
//======================================================================
static bool:PlayerKicked[MAX_PLAYERS];
static FIX_Total_Kick;
//======================================================================
public OnPlayerConnect(playerid)
{
	PlayerKicked[playerid] = false; // Reset Variable
	#if defined FIX_OnPlayerConnect
		return FIX_OnPlayerConnect(playerid);
	#else
		return true;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else 
	#define _ALS_OnPlayerConnect
#endif
#define OnPlayerConnect FIX_OnPlayerConnect
#if defined FIX_OnPlayerConnect
	forward FIX_OnPlayerConnect(playerid);
#endif

public OnGameModeInit()
{
	print(!"Fix Kick by hell'hell loaded!");
	print(!":))");
	#if defined FIX_OnGameModeInit
		return FIX_OnGameModeInit();
	#else
		return true;
	#endif
}
#if defined _ALS_OnGameModeInit
	#undef OnGameModeInit
#else
	#define _ALS_OnGameModeInit
#endif
#define OnGameModeInit FIX_OnGameModeInit
#if defined FIX_OnGameModeInit
	forward FIX_OnGameModeInit();
#endif

public OnGameModeExit()
{
	print(!"_______________________");
	printf("- Total Kick's [%d]!   ", FIX_Total_Kick);
	print(!"_______________________");
	#if defined FIX_OnGameModeExit
		return FIX_OnGameModeExit();
	#else
		return true;
	#endif
}
#if defined _ALS_OnGameModeExit
	#undef OnGameModeExit
#else
	#define _ALS_OnGameModeExit
#endif
#define OnGameModeExit FIX_OnGameModeExit
#if defined FIX_OnGameModeExit
	forward FIX_OnGameModeExit();
#endif
//======================================================================
stock fix_kick(targetid, delay = DELAY_KICK)
{
	if(!IsPlayerConnected(targetid)) return false;
	if(!PlayerKicked[targetid])
	{
		PlayerKicked[targetid] = true;
		FIX_Total_Kick++;
		return SetTimerEx(!"KickPlayer", delay, false, !"d", targetid);
	}
	return false;
}

forward KickPlayer(targetid);
public KickPlayer(targetid) return Kick(targetid);

#if defined _ALS_Kick
    #undef Kick
#else
    #define _ALS_Kick
#endif
#define Kick fix_kick
//======================================================================