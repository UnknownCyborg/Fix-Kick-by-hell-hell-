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
#if !defined DELAY_KICK
	#define DELAY_KICK 1250
#endif

#if !defined MESSAGE_KICK
	#define MESSAGE_KICK
#endif

#if !defined KICK_STAT
	#define KICK_STAT
#endif
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
	#if defined KICK_STAT
		print(!"------------------------");
		printf("---Total Kick's [%d]!---", FIX_Total_Kick);
		print(!"------------------------");
	#else 
		#pragma unused FIX_Total_Kick
	#endif
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
		#if defined KICK_STAT
			FIX_Total_Kick++;
		#endif
		#if defined MESSAGE_KICK
			new fix_string[62], fix_year, fix_month, fix_day, fix_hour, fix_minute, fix_second;
			getdate(fix_year, fix_month, fix_day), gettime(fix_hour, fix_minute, fix_second);
			format(fix_string, sizeof(fix_string), "Соединение с сервером потеряно! [%02d/%02d/%02d] [%02d:%02d:%02d]", fix_year, fix_month, fix_day, fix_hour, fix_minute, fix_second);
			SendClientMessage(targetid, -1, fix_string);
		#endif
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