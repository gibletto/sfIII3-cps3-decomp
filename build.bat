@echo off
rem STREET FIGHTER III 3rd STRIKE -- program ROM
rem Hitachi SHC 5.0, asmsh 4.0, lnk 6.0; SEGA rof2bin 2.51
if "%SHC_LIB%"=="" set SHC_LIB=%~dp0bin
if "%SHC_TMP%"=="" set SHC_TMP=C:\TEMP
set PATH=%SHC_LIB%;%PATH%
if not exist "%SHC_TMP%" mkdir "%SHC_TMP%"
if not exist obj mkdir obj
if not exist build mkdir build
echo compiling
if not exist build\cg.bin python tools\cps3rom.py extract rom\sfiii3nr1.zip build\cg.bin
if errorlevel 1 goto fail

asmsh src\fixed_addr.src -object=obj\fixed_addr.obj
if errorlevel 1 goto fail
shc src\vbl_hook.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\vbl_hook.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
asmsh src\intr.src -object=obj\intr.obj
if errorlevel 1 goto fail
shc src\Game.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Game.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Entry.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\Entry.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
asmsh src\tasksw.src -object=obj\tasksw.obj
if errorlevel 1 goto fail
shc src\coin_cont.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\coin_cont.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\mode_init.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\mode_init.obj >obj\shc.log 2>&1
shc src\test_mode.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\test_mode.obj >obj\shc.log 2>&1
shc src\scrn_ctrl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\scrn_ctrl.obj >obj\shc.log 2>&1
shc src\Com_Pl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Com_Pl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Com_Sub.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Com_Sub.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Ck_Pass.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Ck_Pass.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass00.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass00.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS01.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS01.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS02.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS02.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS03.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS03.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS04.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS04.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS05.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS05.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS06.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS06.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS07.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS07.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS08.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS08.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS09.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS09.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass10.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass10.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS11.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS11.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PASS12.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS12.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass13.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass13.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass14.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass14.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass15.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass15.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass16.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass16.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass17.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass17.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass18.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass18.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\pass19.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass19.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Passive20.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Passive20.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\ACTIVE00.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ACTIVE00.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active01.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active01.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active02.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active02.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active03.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active03.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active04.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active04.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active05.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active05.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active06.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active06.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active07.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active07.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active08.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active08.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active09.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active09.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active10.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active10.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active11.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active11.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active12.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active12.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active13.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active13.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active14.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active14.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active15.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active15.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active16.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active16.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active17.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active17.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active18.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active18.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\active19.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active19.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\FOLLOW02.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\FOLLOW02.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL00.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL00.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL01.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL01.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL03.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL03.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL04.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL04.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL05.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL05.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL07.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL07.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL11.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL11.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL12.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL12.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL13.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL13.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SHELL14.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL14.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\aboutspr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\aboutspr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\CHARSET.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CHARSET.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\CHARMOVE.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CHARMOVE.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\CHARID.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CHARID.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\HITCHECK.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\HITCHECK.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\HITPLPL.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\HITPLPL.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\HITPLEF.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\HITPLEF.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\HITEFPL.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\HITEFPL.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\HITEFEF.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\HITEFEF.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SLOWF.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SLOWF.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SE.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SE.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\CALDIR.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CALDIR.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SYS_sub.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\SYS_sub.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
if errorlevel 1 goto fail
shc src\EM_Cand.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EM_Cand.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLCNT.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNT.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\SYS_sub2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SYS_sub2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Grade.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Grade.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg0001.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg0001.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Game_Main.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Game_Main.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\DEMO.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\DEMO.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\RANKING.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\RANKING.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Manage.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Manage.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Win.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Win.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sel_pl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\sel_pl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\next_cpu.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\next_cpu.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\game_config_main.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\game_config_main.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\CMD_MAIN.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\CMD_MAIN.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\ta_sub.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\ta_sub.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\tate00.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\tate00.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg_sub.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg_sub.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg000.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg000.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg040.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg040.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\BG050.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\BG050.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg090.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg090.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg100.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg100.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg120.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg120.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\bg130.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg130.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\n_input.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\n_input.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\appear.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\appear.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\win_pl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\win_pl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\lose_pl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\lose_pl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_main.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\end_main.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\end_4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_10.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_10.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_11.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_11.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_12.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_12.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_13.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_13.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_14.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_14.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_16.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_16.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_17.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_17.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_18.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_18.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_19.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_19.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_20.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_20.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\end_sub.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_sub.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sc_trans.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\sc_trans.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sc_face.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sc_face.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sc_logo.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sc_logo.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EffA2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffA2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\cmb_win.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\cmb_win.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\VITAL.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\VITAL.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\spgauge.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\spgauge.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sc_sub.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\sc_sub.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\cmb_cont.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\cmb_cont.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFECT.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFECT.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF00.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF00.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF02.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF02.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF03.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF03.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF04.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF04.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff05.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff05.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff06.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff06.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF07.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF07.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff08.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff08.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF09.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF09.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF10.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF10.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF11.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF11.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff12.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff12.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF13.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF13.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF13_KOTP.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF13_KOTP.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff14.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff14.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF15.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\EFF15.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF16.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF16.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF18.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF18.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF19.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF19.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff20.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff20.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF21.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF21.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF22.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF22.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF23.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF23.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF24.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF24.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF25.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\EFF25.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF26.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF26.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF27.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF27.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF29.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF29.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF30.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF30.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF31.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF31.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF32.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF32.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF33.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF33.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF34.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF34.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff35.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff35.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff36.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff36.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF37.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF37.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF38.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF38.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff39.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff39.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF41.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF41.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF42.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF42.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF44.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF44.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF45.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF45.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF46.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF46.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF47.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF47.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF48.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF48.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF49.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF49.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff50.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff50.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff51.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff51.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff52.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff52.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF53.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF53.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF54.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF54.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF58.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF58.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff59.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff59.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF61.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF61.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF62.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF62.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF63.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF63.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF67.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF67.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF68.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF68.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF69.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF69.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF70.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF70.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF71.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF71.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF72.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF72.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff73.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff73.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF74.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF74.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
if errorlevel 1 goto fail
shc src\EFF75_ORDER.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF75_ORDER.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff76.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff76.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff76_COLOR.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff76_COLOR.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF77.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF77.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF78.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF78.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff79.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff79.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff80.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff80.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff81.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff81.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF82.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF82.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF83.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF83.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF84.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF84.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF85.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF85.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF86.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF86.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff93.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff93.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff94.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff94.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\Eff95.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff95.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF96.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF96.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eff97.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff97.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF98.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF98.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFF99.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF99.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFA1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFA1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFA2_MAIN.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFA2_MAIN.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFA3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFA3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFA6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFA6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
if errorlevel 1 goto fail
shc src\EFFA7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFA7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFB0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFB1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFB1_INIT.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB1_INIT.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effb2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effb2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
if errorlevel 1 goto fail
shc src\EFFB4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFB5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFB6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFB8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effb9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effb9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFC9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFD0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFD1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effd3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effd3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFD4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFD5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFD7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EffD8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\EffD8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFD9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EffE0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffE0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFE1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFE1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFE2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFE2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effe3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effe3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFE5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFE5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effe6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\effe6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFE7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFE7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFE8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFE8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effe9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effe9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\efff0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\efff0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFF1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFF4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\efff5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\efff5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\efff6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\efff6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFF9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EffG0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffG0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFG3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFG4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFG5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFG6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFG7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effg8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effg8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFG9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFH0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFH1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFH2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFH3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFH9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI4MV.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI4MV.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\BBBSBALL.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\BBBSBALL.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFI9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFJ0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFJ0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effJ6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effJ6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFJ7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFJ7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFJ8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFJ8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFJ9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFJ9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EffK6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffK6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFK9.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK9.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFL0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFL0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFL1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFL1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effL2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effL2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effL3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effL3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFL4.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFL4.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effL7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effL7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effl8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effl8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effect_L9_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effect_L9_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effM0.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effM0.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
if errorlevel 1 goto fail
shc src\EFFM1.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFM1.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFM2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFM2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EffM3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffM3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effM5.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effM5.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\effM6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effM6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\EFFM7.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFM7.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLCNTAPP.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNTAPP.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLCNTSET.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\PLCNTSET.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLCNTDAT.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNTDAT.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLCNT2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNT2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLCNT3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNT3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLMAIN.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLMAIN.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLMAIN2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLMAIN2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLS00.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS00.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLS01.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS01.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLS02.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS02.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLSGAUGE.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\PLSGAUGE.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLS03.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS03.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLS03ATT.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS03ATT.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPNM.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPNM.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLNORMAL.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLNORMAL.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPDM.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPDM.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPCA.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPCA.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPCU.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPCU.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPATUNI.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPATUNI.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT00.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT00.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT01.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT01.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT02.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT02.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT03.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT03.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT04.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT04.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT05.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT05.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT06.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT06.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT07.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT07.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT08.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT08.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT09.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT09.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\plpat10.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat10.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT11.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT11.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT12.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT12.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\PLPAT13.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT13.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\plpat14.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat14.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\plpat16.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat16.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\plpat17.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat17.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\plpat18.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat18.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\plpat19.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat19.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\plpat20.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat20.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\BBBSCOM.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\BBBSCOM.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\BBBSCOM2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\BBBSCOM2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\meta_col.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\meta_col.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
asmsh lib\shclib.src -object=obj\shclib.obj
if errorlevel 1 goto fail
shc src\fifo.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\fifo.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\family.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\family.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sys_test.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\sys_test.obj >obj\shc.log 2>&1
shc src\coin_sw.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\coin_sw.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\eeprom.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\eeprom.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sys_config.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\sys_config.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\spr_pool.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\spr_pool.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
asmsh src\simmram.src -object=obj\simmram.obj
if errorlevel 1 goto fail
shc src\poly_que.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\poly_que.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\textsound.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -noinline -object=obj\textsound.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
asmsh lib\slow_mvn.src -object=obj\slow_mvn.obj
if errorlevel 1 goto fail
asmsh lib\sta_sftra.src -object=obj\sta_sftra.obj
if errorlevel 1 goto fail
shc src\cram_bank.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=0 -nospeed -object=obj\cram_bank.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\sound_voice.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sound_voice.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
asmsh lib\quick_strcpy.src -object=obj\quick_strcpy.obj
if errorlevel 1 goto fail
shc data\intr_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\intr_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
asmsh data\sections.src -object=obj\sections.obj
if errorlevel 1 goto fail
shc data\tasksw_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\tasksw_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Entry_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Entry_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Com_Pl_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Com_Pl_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Com_Sub_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Com_Sub_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Ck_Pass_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Ck_Pass_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Getup.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Getup.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass00_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass00_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS01_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS01_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS02_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS02_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS03_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS03_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS04_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS04_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS05_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS05_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS06_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS06_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS07_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS07_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS08_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS08_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS09_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS09_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass10_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass10_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS11_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS11_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PASS12_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PASS12_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass13_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass13_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass14_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass14_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass15_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass15_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass16_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass16_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass17_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass17_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass18_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass18_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass19_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass19_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass0000.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass0000.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass0001.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass0001.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass0002.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass0002.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\pass0003.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\pass0003.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Com_Data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Com_Data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ACTIVE00_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ACTIVE00_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active01_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active01_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active02_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active02_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active03_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active03_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active04_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active04_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active05_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active05_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active06_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active06_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active07_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active07_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active08_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active08_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active09_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active09_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active16_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active16_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active17_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active17_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active18_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active18_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\active19_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\active19_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\FOLLOW02_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\FOLLOW02_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\vs_shell.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\vs_shell.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL00_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL00_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL01_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL01_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL03_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL03_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL04_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL04_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL05_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL05_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL07_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL07_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL11_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL11_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL12_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL12_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL13_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL13_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SHELL14_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SHELL14_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\aboutspr_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\aboutspr_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\CHARSET_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CHARSET_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\CHARID_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CHARID_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\HITCHECK_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\HITCHECK_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SLOWF_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SLOWF_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SE_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SE_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Se_Data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Se_Data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SE_tbl2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SE_tbl2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\CALDIR_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CALDIR_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\SYS_sub_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\SYS_sub_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Grade_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Grade_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg0001_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg0001_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Game_Main_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Game_Main_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\DEMO_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\DEMO_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\DEMO02.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\DEMO02.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Manage_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Manage_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Win_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Win_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\POW_DATA.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\POW_DATA.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Sel_Data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Sel_Data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Win_tbl2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Win_tbl2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sel_pl_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sel_pl_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\next_cpu_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\next_cpu_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\CMD_MAIN_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\CMD_MAIN_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\cmd_data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\cmd_data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ta_sub_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ta_sub_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg_sub_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg_sub_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg000_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg000_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg_data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg_data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg000_tbl2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg000_tbl2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg_data2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg_data2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg000_tbl3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg000_tbl3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\BG050_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\BG050_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg100_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg100_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bg130_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bg130_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\n_input_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\n_input_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\appear_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\appear_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\win_pl_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\win_pl_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\lose_pl_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\lose_pl_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\OPENING.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\OPENING.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_main_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_main_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\OPENING2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\OPENING2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_main_tbl2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_main_tbl2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_1_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_1_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_4_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_4_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_5_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_5_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_7_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_7_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_8_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_8_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_10_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_10_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_11_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_11_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_12_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_12_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_13_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_13_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_14_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_14_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_16_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_16_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_17_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_17_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_18_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_18_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_19_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_19_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_20_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_20_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\end_sub_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\end_sub_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sc_trans_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sc_trans_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sc_data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sc_data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sc_trans_tbl2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sc_trans_tbl2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\cmb_win_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\cmb_win_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\VITAL_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\VITAL_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sc_data2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sc_data2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\spgauge_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\spgauge_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sc_data3.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sc_data3.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFECT_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFECT_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF00_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF00_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF01.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF01.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF02_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF02_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF03_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF03_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF04_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF04_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff05_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff05_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff06_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff06_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF07_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF07_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff08_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff08_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF09_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF09_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF10_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF10_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF11_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF11_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff12_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff12_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF13_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF13_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff14_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff14_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF16_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF16_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF18_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF18_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF19_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF19_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF21_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF21_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF22_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF22_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF23_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF23_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF24_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF24_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF26_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF26_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF27_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF27_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF29_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF29_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF33_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF33_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff35_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff35_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff36_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff36_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF37_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF37_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF38_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF38_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff39_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff39_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF41_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF41_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF42_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF42_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF44_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF44_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF45_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF45_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF47_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF47_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF48_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF48_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff52_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff52_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF53_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF53_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF54_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF54_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF58_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF58_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff59_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff59_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF61_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF61_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF62_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF62_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF63_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF63_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF67_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF67_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF68_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF68_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF69_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF69_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF71_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF71_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff73_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff73_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF74_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF74_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF75_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF75_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff76_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff76_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF77_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF77_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF78_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF78_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff79_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff79_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF84_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF84_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF85_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF85_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF86_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF86_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff93_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff93_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF92.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF92.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff93_tbl2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff93_tbl2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eff94_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eff94_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\Eff95_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\Eff95_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF98_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF98_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFF99_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFF99_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFA6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFA6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFB0_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB0_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFB1_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB1_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effb2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effb2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFB4_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB4_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFB6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFB6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFC0_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC0_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFC2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFC3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFC4_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC4_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFC7_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC7_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFC8_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC8_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFC9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFC9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFD0_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD0_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effd3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effd3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFD4_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD4_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFD5_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD5_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFD6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFD7_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD7_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EffD8_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffD8_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFD9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFD9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFE2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFE2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effe3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effe3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFE5_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFE5_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effe6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effe6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effe9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effe9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFF1_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF1_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFF2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\efff5_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\efff5_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\efff6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\efff6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFF9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFF8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFF9_tbl2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFF9_tbl2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EffG0_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffG0_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFG4_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG4_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFG5_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG5_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFG6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effg8_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effg8_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFG9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFG9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFH0_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH0_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFH1_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH1_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFH2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFH3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFH6.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH6.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFH9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFH9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFI0_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI0_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFI3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFI5_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI5_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFI7_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI7_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFI8_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFI8_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFJ2.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFJ2.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effJ6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effJ6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFJ8_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFJ8_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFJ9_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFJ9_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFK2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFK3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFK4_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK4_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFK5_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK5_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EffK6_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffK6_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFK7_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFK7_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFL1_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFL1_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effL2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effL2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effL3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effL3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFL4_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFL4_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effL7_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effL7_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effM0_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effM0_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFM2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFM2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EffM3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EffM3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\EFFM7_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\EFFM7_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effM8.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effM8.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gill_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gill_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\alex_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\alex_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ryu_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ryu_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yun_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yun_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\dudley_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\dudley_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\necro_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\necro_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\hugo_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\hugo_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ibuki_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ibuki_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\elena_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\elena_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\oro_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\oro_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yang_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yang_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ken_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ken_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sean_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sean_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\urien_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\urien_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki1_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki1_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki2_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki2_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\effect_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\effect_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gill_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gill_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\alex_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\alex_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ryu_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ryu_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yun_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yun_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\dudley_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\dudley_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\necro_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\necro_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\hugo_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\hugo_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ibuki_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ibuki_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\elena_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\elena_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\oro_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\oro_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yang_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yang_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ken_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ken_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sean_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sean_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\urien_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\urien_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki1_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki1_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki2_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki2_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\chun_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\chun_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\makoto_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\makoto_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\q_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\q_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\no12_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\no12_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\remy_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\remy_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\chun_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\chun_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\makoto_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\makoto_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\q_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\q_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\no12_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\no12_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\remy_yuca.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\remy_yuca.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\bonus_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\bonus_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gill_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gill_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\alex_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\alex_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ryu_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ryu_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yun_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yun_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\dudley_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\dudley_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\necro_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\necro_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\hugo_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\hugo_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ibuki_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ibuki_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\elena_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\elena_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\oro_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\oro_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yang_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yang_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ken_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ken_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sean_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sean_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\urien_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\urien_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki1_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki1_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki2_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki2_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\chun_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\chun_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\makoto_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\makoto_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\q_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\q_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\no12_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\no12_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\remy_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\remy_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ef13_hitbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ef13_hitbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gill_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gill_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\alex_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\alex_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ryu_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ryu_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yun_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yun_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\dudley_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\dudley_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\necro_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\necro_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\hugo_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\hugo_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ibuki_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ibuki_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\elena_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\elena_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\oro_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\oro_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yang_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yang_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ken_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ken_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sean_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sean_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\urien_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\urien_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki1_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki1_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki2_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki2_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\chun_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\chun_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\makoto_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\makoto_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\q_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\q_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\no12_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\no12_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\remy_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\remy_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ef13_attbox.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ef13_attbox.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gill_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gill_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\alex_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\alex_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ryu_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ryu_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yun_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yun_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\dudley_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\dudley_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\necro_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\necro_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\hugo_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\hugo_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ibuki_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ibuki_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\elena_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\elena_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\oro_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\oro_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yang_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yang_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ken_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ken_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sean_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sean_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\urien_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\urien_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki1_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki1_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki2_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki2_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\chun_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\chun_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\makoto_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\makoto_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\q_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\q_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\no12_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\no12_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\remy_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\remy_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ef13_attr.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ef13_attr.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ef13_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ef13_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gill_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gill_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\alex_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\alex_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ryu_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ryu_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yun_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yun_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\dudley_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\dudley_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\necro_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\necro_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\hugo_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\hugo_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ibuki_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ibuki_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\elena_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\elena_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\oro_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\oro_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\yang_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\yang_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\ken_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\ken_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sean_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sean_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\urien_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\urien_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki1_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki1_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gouki2_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gouki2_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\chun_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\chun_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\makoto_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\makoto_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\q_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\q_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\no12_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\no12_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\remy_move.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\remy_move.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\stage_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\stage_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\scene_char.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\scene_char.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\scrn_data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\scrn_data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\chr_data.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\chr_data.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLCNT_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNT_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLCNT2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNT2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLCNT3_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLCNT3_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLMAIN_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLMAIN_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLMAIN2_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLMAIN2_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLS00_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS00_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLS01_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS01_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLS02_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS02_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLS03_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLS03_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPNM_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPNM_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPDM_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPDM_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPCA_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPCA_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPCU_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPCU_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPATUNI_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPATUNI_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT00_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT00_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT01_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT01_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT02_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT02_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT03_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT03_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT04_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT04_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT05_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT05_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT06_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT06_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT07_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT07_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT08_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT08_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT09_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT09_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\plpat10_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat10_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT11_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT11_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT12_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT12_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\PLPAT13_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\PLPAT13_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\plpat14_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat14_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\plpat16_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat16_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\plpat17_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat17_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\plpat18_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat18_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\plpat19_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat19_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\plpat20_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\plpat20_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\asstbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\asstbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\gauge.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\gauge.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\buttobi.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\buttobi.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\etc.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\etc.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\exchange.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\exchange.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\BBBSCOM_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\BBBSCOM_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\meta_col_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\meta_col_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sys_test_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sys_test_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\eeprom_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\eeprom_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sys_config_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sys_config_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\textsound_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\textsound_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\sound_voice_tbl.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\sound_voice_tbl.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\vectors.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\vectors.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\work.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\work.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc src\work_b.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\work_b.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\snd_bank.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\snd_bank.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\snd_seq.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\snd_seq.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
shc data\cd_volume.c -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include -optimize=1 -speed -object=obj\cd_volume.obj >obj\shc.log 2>&1
if errorlevel 1 goto fail
del obj\shc.log
lnk -subcommand=sf3.sub
if errorlevel 1 goto fail
rof2bin -s=06000000 -e=07000000 -v=00 sf3.abs
if errorlevel 1 goto fail
python tools\cps3rom.py pack sf3.bin build\cg.bin rom\sfiii3nr1.zip build
if errorlevel 1 goto fail
echo build\prog.bin built
goto end
:fail
if exist obj\shc.log findstr /c:") : " obj\shc.log
echo BUILD FAILED
:end
