/*
 * WORKUSER.C  Work RAM shared by the whole game
 */

#include "types.h"
#include "structs.h"

u16 Game_timer;  /* 0201136C */
s16 Game_pause;  /* 0201136E */
s16 Game_difficulty;  /* 02011370 */
s16 Control_Time;  /* 02011372 */
s16 Time_in_Time;  /* 02011374 */
s16 Counter_hi;  /* 02011376 */
s16 Counter_low;  /* 02011378 */
s16 Round_Level;  /* 0201137A */
u16 Round_Result;  /* 0201137C */
s8 request_message;  /* 0201137E */
s8 Winner_id;  /* 0201137F */
s8 Loser_id;  /* 02011380 */
s16 PL_Wins[2];  /* 02011382 */
s8 Break_Into;  /* 02011386 */
u8 My_char[2];  /* 02011387 */
u8 Allow_a_battle_f;  /* 02011389 */
u8 Round_num;  /* 0201138A */
s8 Super_Arts[2];  /* 0201138B */
s8 Fade_Flag;  /* 0201138D */
s8 Forbid_Break;  /* 0201138E */
s8 Request_Break[2];  /* 0201138F */
s16 Fade_R_No0;  /* 02011392 */
s16 Fade_R_No1;  /* 02011394 */
u16 Fade_Number;  /* 02011396 */
u8 Fade_Mode;  /* 02011398 */
u32 Score[2][3];  /* 0201139C */
s16 Play_Type;  /* 020113B4 */
s8 Continue_Count[2];  /* 020113B6 */
s8 Personal_Continue_Flag[2];  /* 020113B8 */
s8 Personal_Disp_Flag;  /* 020113BA */
u8 Personal_Disp_Flag_tail[1];  /* after Personal_Disp_Flag; nothing refers to it by name or address */
s8 WINNER;  /* 020113BC */
s8 LOSER;  /* 020113BD */
u8 LOSER_tail[2];  /* after LOSER; nothing refers to it by name or address */
s16 Conclusion_Type;  /* 020113C0 */
s8 Judge_Round_Flag;  /* 020113C2 */
s16 win_type[2][4];  /* 020113C4 */
s8 win_pause_go;  /* 020113D4 */
s16 message_index;  /* 020113D6 */
s16 Conclusion_Flag;  /* 020113D8 */
s8 New_Challenger;  /* 020113DA */
s8 Champion;  /* 020113DB */
s8 Complete_Judgement;  /* 020113DC */
s8 Reserve_Cut;  /* 020113DD */
s8 Perfect_Flag;  /* 020113DE */
s16 DE_X[19];  /* 020113E0 */
u8 DE_X_tail[2];  /* after DE_X; nothing refers to it by name or address */
s16 Fade_Gap_Timer;  /* 02011408 */
s8 Fade_Half_Flag;  /* 0201140A */
u32 Vital_Bonus[2];  /* 0201140C */
u32 Time_Bonus[2];  /* 02011414 */
u8 Time_Bonus_tail[4];  /* after Time_Bonus; nothing refers to it by name or address */
s16 win_mark_new[2];  /* 02011420 */
s8 Next_Step;  /* 02011424 */
s8 judge_flag;  /* 02011425 */
s8 Wipe_Count;  /* 02011426 */
u8 Wipe_Limit;  /* 02011427 */
u8 Wipe_Mode;  /* 02011428 */
u8 Wipe_Kind;  /* 02011429 */
u8 sc_chr_ram[7360];  /* 0201142A */
u8 bcount_mark_chr_w[9024];  /* 020130EA */
s8 Cover_Timer;  /* 0201542A */
s16 Text_Page_Y;  /* 0201542C */
s8 E_07_Flag[2];  /* 0201542E */
s8 Personal_Timer[2];  /* 02015430 */
s8 Request_E_No;  /* 02015432 */
s8 Request_G_No;  /* 02015433 */
s16 G_Timer;  /* 02015434 */
s16 G_No0;  /* 02015436 */
s16 G_No1;
s16 G_No2;
s16 G_No3;
s16 D_Timer;  /* 0201543E */
s16 D_No0;  /* 02015440 */
s16 D_No1;
s16 D_No2;
s16 D_No3;
u8 Present_Rank[2];  /* 02015448 */
s8 Rank_In[2][4];  /* 0201544A */
s8 Request_Disp_Rank[2][4];  /* 02015452 */
s8 Rank_Demo_Loop;  /* 0201545A */
s8 Rank_Type;  /* 0201545B */
s8 Flash_Sign[2];  /* 0201545C */
s8 Flash_Rank_Time;  /* 0201545E */
s8 Flash_Rank_Interval;  /* 0201545F */
s8 Ranking_X;  /* 02015460 */
s8 Rank;  /* 02015461 */
s8 Rank_X;  /* 02015462 */
s16 Rank_Pos_X;  /* 02015464 */
s16 Rank_Pos_Y;  /* 02015466 */
s16 E_Timer;  /* 02015468 */
s16 E_No0;  /* 0201546A */
s16 E_No1;
s16 E_No2;
s16 E_No3;
s16 F_No0[2];  /* 02015472 */
s16 F_No1[2];  /* 02015476 */
s16 F_No2[2];  /* 0201547A */
s16 F_No3[2];  /* 0201547E */
s16 F_Timer[2];  /* 02015482 */
u8 F_Timer_tail[12];  /* after F_Timer; nothing refers to it by name or address */
s16 E_Number[2][4];  /* 02015492 */
s16 ENTRY_X;  /* 020154A2 */
s16 C_Timer;  /* 020154A4 */
s16 C_No0;  /* 020154A6 */
s16 C_No1;
s16 C_No2;
s16 C_No3;
s8 Complete_Victory;  /* 020154AE */
s8 Demo_Flag;  /* 020154AF */
s8 Next_Demo;  /* 020154B0 */
s8 Demo_PL_Index;  /* 020154B1 */
s8 Demo_Stage_Index;  /* 020154B2 */
s16 S_Timer;  /* 020154B4 */
s16 S_No;  /* 020154B6 */
s16 S_Sub_No;  /* 020154B8 */
s16 S_Sub2_No;  /* 020154BA */
s16 S_Sub3_No;  /* 020154BC */
s16 Flash_Complete[2];  /* 020154BE */
s16 Sel_PL_Complete[2];  /* 020154C2 */
s16 Sel_Arts_Complete[2];  /* 020154C6 */
s16 Select_Start[2];  /* 020154CA */
s16 Cursor_X[2];  /* 020154CE */
s16 Arts_Y[2];  /* 020154D2 */
u8 Arts_Y_tail[4];  /* after Arts_Y; nothing refers to it by name or address */
s16 Cursor_Y_Pos[2][3];  /* 020154DA */
s16 Stop_Cursor[2];  /* 020154E6 */
s16 Move_Super_Arts[2];  /* 020154EA */
u8 Move_Super_Arts_tail[6];  /* after Move_Super_Arts; nothing refers to it by name or address */
s16 Battle_Country;  /* 020154F4 */
s16 Face_Status;  /* 020154F6 */
s8 Face_MV_Request;  /* 020154F8 */
s8 Face_Move;  /* 020154F9 */
s8 Appear_Cursor;  /* 020154FA */
s8 Select_Timer;  /* 020154FB */
s8 Time_Stop;  /* 020154FC */
s8 Time_Over;  /* 020154FD */
s16 Unit_Of_Timer;  /* 020154FE */
s8 Player_id;  /* 02015500 */
s8 Last_Player_id;  /* 02015501 */
s8 Player_Number;  /* 02015502 */
s8 COM_id;  /* 02015503 */
s8 EM_id;  /* 02015504 */
s16 VS_Index[2];  /* 02015506 */
u8 VS_Index_tail[2];  /* after VS_Index; nothing refers to it by name or address */
s16 Plate_X[2][3];  /* 0201550C */
s16 Plate_Y[2][3];  /* 02015518 */
u8 Plate_Y_tail[24];  /* after Plate_Y; nothing refers to it by name or address */
s16 SP_No[2][4];  /* 0201553C */
s16 ID;  /* 0201554C */
s16 Face_No[2];  /* 0201554E */
s16 Sel_Sub_No[2];  /* 02015552 */
s16 Arts_Cursor_No[2];  /* 02015556 */
s16 Arts_Cursor_Timer[2];  /* 0201555A */
s16 Exit_No;  /* 0201555E */
u8 Exit_No_tail[4];  /* after Exit_No; nothing refers to it by name or address */
s16 Select_Arts[2];  /* 02015564 */
u8 Select_Arts_tail[4];  /* after Select_Arts; nothing refers to it by name or address */
s8 Select_Status[2];  /* 0201556C */
s8 Select_Demo_Index;  /* 0201556E */
u8 Country;  /* 0201556F */
s16 mes_already;  /* 02015570 */
s16 CP_No[2][4];  /* 02015572 */
s16 CP_Index[2][8];  /* 02015582 */
s16 Pattern_Index[2];  /* 020155A2 */
s16 Timer_00[2];  /* 020155A6 */
s16 Timer_01[2];  /* 020155AA */
s8 Combo_Speed[2];  /* 020155AE */
u8 Combo_Speed_tail[2];  /* after Combo_Speed; nothing refers to it by name or address */
s16 PL_Distance[2];  /* 020155B2 */
s16 Area_Number[2];  /* 020155B6 */
u16 Lever_Buff[2];  /* 020155BA */
u16 Lever_Pool[2];  /* 020155BE */
const_s16_arr Tech_Address[2];  /* 020155C4 */
s16 Tech_Index[2];  /* 020155CC */
u8 Tech_Index_tail[24];  /* after Tech_Index; nothing refers to it by name or address */
s16 Random_ix16_com;  /* 020155E8 */
s16 Random_ix32_com;  /* 020155EA */
s16 M_Timer;  /* 020155EC */
s16 M_No0;  /* 020155EE */
s16 M_No1;  /* 020155F0 */
s16 M_No2;  /* 020155F2 */
s16 M_No3;  /* 020155F4 */
s8 Demo_Time_Stop;  /* 020155F6 */
s16 VS_Tech[2];  /* 020155F8 */
s8 Exec_Wipe;  /* 020155FC */
u16 Guard_Type[2];  /* 020155FE */
s16 Separate_Area[2][3];  /* 02015602 */
u32 * Shell_Address[2];  /* 02015610 */
u16 Free_Lever[2];  /* 02015618 */
s8 Passive_Flag[2];  /* 0201561C */
s8 Flip_Flag[2];  /* 0201561E */
u8 Flip_Flag_tail[4];  /* after Flip_Flag; nothing refers to it by name or address */
s8 Lie_Flag[2];  /* 02015624 */
s16 Term_No[2];  /* 02015626 */
s8 Attack_Flag[2];  /* 0201562A */
s8 Passive_Mode;  /* 0201562C */
s8 Limited_Flag[2];  /* 0201562D */
s8 Shell_Ignore_Timer[2];  /* 0201562F */
s16 Com_Width_Data[2];  /* 02015632 */
s8 Event_Judge_Gals;  /* 02015636 */
u8 EJG_index[4];  /* 02015637 */
s8 Guard_Flag[2];  /* 0201563B */
u16 Lever_Squat[2];  /* 0201563E */
u16 M_Lv[2];  /* 02015642 */
s8 Pierce_Menu[2];  /* 02015646 */
s8 Counter_Attack[2];  /* 02015648 */
s16 zuubun_base_x;  /* 0201564A */
s8 Face_MV_Time;  /* 0201564C */
s8 Before_Jump[2];  /* 0201564D */
u8 Before_Jump_tail[17];  /* after Before_Jump; nothing refers to it by name or address */
s8 Stop_Combo;  /* 02015660 */
u8 Stock_Hit_Flag[2];  /* 02015661 */
s8 Rolling_Flag[2];  /* 02015663 */
u8 Continue_Coin[2];  /* 02015665 */
s8 Ignore_Entry[2];  /* 02015667 */
s16 Cursor_Y[2];  /* 0201566A */
u8 Cursor_Y_tail[12];  /* after Cursor_Y; nothing refers to it by name or address */
s8 Last_Arts_PL;  /* 0201567A */
s8 Moving_Plate[2];  /* 0201567B */
s8 Naming_Cut[2];  /* 0201567D */
s8 Moving_Plate_Counter[2];  /* 0201567F */
s8 OK_Priority[2];  /* 02015681 */
s8 Player_Color[2];  /* 02015683 */
s8 PP_Priority[2][3];  /* 02015685 */
u8 PP_Priority_tail[31];  /* after PP_Priority; nothing refers to it by name or address */
u8 Stock_My_char[2];  /* 020156AA */
s8 Stock_Player_Color[2];  /* 020156AC */
s16 Insert_Y;  /* 020156AE */
u8 Insert_Y_tail[2];  /* after Insert_Y; nothing refers to it by name or address */
u8 Version_Type;  /* 020156B2 */
u8 Version_Type_tail[1];  /* after Version_Type; nothing refers to it by name or address */
s8 BGM_Fade_Out_Flag;  /* 020156B4 */
s16 zoom_request_flag;  /* 020156B6 */
s16 zoom_req_flag_old;  /* 020156B8 */
s16 zoom_request_level;  /* 020156BA */
s16 Stock_Com_Color[2];  /* 020156BC */
s8 Stock_Com_Arts[2];  /* 020156C0 */
u8 Stock_Com_Arts_tail[16];  /* after Stock_Com_Arts; nothing refers to it by name or address */
s8 Stop_SG;  /* 020156D2 */
s16 Last_Selected_ID;  /* 020156D4 */
s16 Last_Called_SE;  /* 020156D6 */
s16 scr_req_x;  /* 020156D8 */
s16 scr_req_y;  /* 020156DA */
u8 scr_req_y_tail[6];  /* after scr_req_y; nothing refers to it by name or address */
s8 Operator_Status[2];  /* 020156E2 */
s8 Round_Operator[2];  /* 020156E4 */
u32 Stock_Score[2];  /* 020156E8 */
s8 another_bg[2];  /* 020156F0 */
s8 another_bg_old[2];  /* 020156F2 */
s8 judge_disp_all;  /* 020156F4 */
u8 judge_disp_all_tail[49];  /* after judge_disp_all; nothing refers to it by name or address */
s8 unused_flag_b;  /* 02015726 */
s8 bg_test_flag;  /* 02015727 */
s8 Last_Super_Arts[2];  /* 02015728 */
s8 Last_My_char[2];  /* 0201572A */
u8 Last_My_char_tail[4];  /* after Last_My_char; nothing refers to it by name or address */
s8 Continue_Menu[2];  /* 02015730 */
s8 Timer_Freeze;  /* 02015732 */
s8 Rapid_No[2][4];  /* 02015733 */
s16 Rapid_Index[2];  /* 0201573C */
s8 Standing_Timer[2];  /* 02015740 */
s8 Before_Look[2];  /* 02015742 */
s16 Shell_Separate_Area[2][3];  /* 02015744 */
s16 Attack_Counter[2];  /* 02015750 */
s16 Last_Attack_Counter[2];  /* 02015754 */
s8 Attack_Count_No0[2];  /* 02015758 */
s16 Com_Color_Shot;  /* 0201575A */
s8 Standing_Master_Timer[2];  /* 0201575C */
s8 unused_flag_c;  /* 0201575E */
s8 test_sw_lock;  /* 0201575F */
s8 PB_Music_Off;  /* 02015760 */
s8 No_Death;  /* 02015761 */
s8 Flash_MT[2];  /* 02015762 */
s8 Squat_Timer[2];  /* 02015764 */
s8 Squat_Master_Timer[2];  /* 02015766 */
s8 Turn_Over[2];  /* 02015768 */
s16 Distance_XX_Index[2];  /* 0201576A */
u16 Resume_Lever[2][20];  /* 0201576E */
s8 Turn_Over_Timer[2];  /* 020157BE */
s8 Jump_Pass_Timer[2][4];  /* 020157C0 */
s8 sa_gauge_flash[2];  /* 020157C8 */
s8 Receive_Flag[2];  /* 020157CA */
s8 Disposal_Again[2];  /* 020157CC */
u16 pcon_timer;  /* 020157CE */
s8 unused_flag_a;  /* 020157D0 */
volatile s8 BGM_Fade_Level;  /* 020157D1 */
u8 Decided_My_char[2];  /* 020157D2 */
s8 Break_Com[2][24];  /* 020157D4 */
s8 Sel_Exit_Flag;  /* 02015804 */
u16 Lever_Store[2][3];  /* 02015806 */
s16 Return_CP_No[2];  /* 02015812 */
s16 Return_CP_Index[2];  /* 02015816 */
s16 Return_Pattern_Index[2];  /* 0201581A */
s8 aiuchi_flag;  /* 0201581E */
u8 paring_counter[2];  /* 0201581F */
u8 paring_bonus_r[2];  /* 02015821 */
u8 paring_ctr_vs[2][2];  /* 02015823 */
u8 paring_ctr_ori[2];  /* 02015827 */
u8 Type_of_Attack[2];  /* 02015829 */
u16 Lever_LR[2];  /* 0201582C */
s16 Last_Eftype[2];  /* 02015830 */
u16 DENJIN_No[2];  /* 02015834 */
u8 DENJIN_Term[2];  /* 02015838 */
u16 SC_Personal_Time[2];  /* 0201583A */
u8 Attack_Count_Buff[2][4];  /* 0201583E */
u8 Attack_Count_Index[2];  /* 02015846 */
s16 Guard_Counter[2];  /* 02015848 */
u8 CC_Type;  /* 0201584C */
u8 CC_Value[2];  /* 0201584D */
u8 CC_Value_tail[2];  /* after CC_Value; nothing refers to it by name or address */
u8 Continue_Coin2[2];  /* 02015851 */
s16 kage_gfx_ofs[64];  /* 02015854 */
s16 kage_gfx_cells[64];  /* 020158D4 */
s16 car_gfx_ofs[288];  /* 02015954 */
s16 car_gfx_cells[288];  /* 02015B94 */
s16 hitmark_gfx_ofs[2][512];  /* 02015DD4 */
s16 hitmark_gfx_cells[512];  /* 020165D4 */
s16 seraph_gfx_ofs[64];  /* 020169D4 */
s16 seraph_gfx_cells[64];  /* 02016A54 */
s16 Limit_Time;  /* 02016AD4 */
u8 Weak_PL;  /* 02016AD6 */
s16 Last_Pattern_Index[2];  /* 02016AD8 */
u8 Bullet_No[2];  /* 02016ADC */
u8 Bullet_Counter[2];  /* 02016ADE */
s16 Random_ix16_ex_com;  /* 02016AE0 */
s16 Random_ix32_ex_com;  /* 02016AE2 */
s16 Entry_Mes_X[2];  /* 02016AE4 */
s16 Entry_Mes_Wide[2];  /* 02016AE8 */
s8 Disp_Win_Name;  /* 02016AEC */
u8 Perfect_Counter[2];  /* 02016AED */
u8 Straight_Counter[2];  /* 02016AEF */
u32 Complete_Bonus;  /* 02016AF4 */
u8 Complete_Bonus_tail[8];  /* after Complete_Bonus; nothing refers to it by name or address */
s8 Break_Into_CPU;  /* 02016B00 */
s8 ID_of_Face[3][7];  /* 02016B01 */
s8 Cursor_Move[2];  /* 02016B16 */
s8 Auto_Cursor[2];  /* 02016B18 */
s8 Auto_No[2];  /* 02016B1A */
s8 Auto_Index[2];  /* 02016B1C */
s8 Auto_Timer[2];  /* 02016B1E */
s8 ID2;  /* 02016B20 */
s8 Explosion;  /* 02016B21 */
s16 Exit_Timer;  /* 02016B22 */
s8 Introduce_Break_Into[2];  /* 02016B24 */
u32 Stage_Stock_Score[2];  /* 02016B28 */
s16 Max_vitality;  /* 02016B30 */
s8 gouki_wins;  /* 02016B32 */
s8 EM_Rank;  /* 02016B33 */
s8 Disp_PERFECT;  /* 02016B34 */
s8 Escape_SS;  /* 02016B35 */
s8 Deley_Shot_No[2];  /* 02016B36 */
s8 Deley_Shot_Timer[2];  /* 02016B38 */
s16 Bonus_Game_Flag;  /* 02016B3A */
s16 Bonus_Game_Work;  /* 02016B3C */
s16 Bonus_Game_result;  /* 02016B3E */
s16 Bonus_Game_ex_result;  /* 02016B40 */
s8 Lost_Round[2];  /* 02016B42 */
s8 Super_Arts_Finish[2];  /* 02016B44 */
s8 Stage_SA_Finish[2];  /* 02016B46 */
s8 Perfect_Finish[2];  /* 02016B48 */
s8 Cheap_Finish[2];  /* 02016B4A */
s8 Last_My_char2[2];  /* 02016B4C */
s8 gouki_app;  /* 02016B4E */
s8 Bonus_Game_Complete;  /* 02016B4F */
s16 Stock_Bonus_Game_Result;  /* 02016B50 */
s16 Gill_Pos_X;  /* 02016B52 */
s16 bs_scrrrl[2][2];  /* 02016B54 */
u32 Bonus_Score;  /* 02016B5C */
u32 Final_Bonus_Score;  /* 02016B60 */
s16 Bonus_Stage_RNO[4];  /* 02016B64 */
u8 Demo_Lever_Play;  /* 02016B6C */
s16 Bonus_Stage_Level;  /* 02016B6E */
s16 Bonus_Stage_Tix;  /* 02016B70 */
u8 Get_Demo_Index;  /* 02016B72 */
u8 Combo_Demo_Flag;  /* 02016B73 */
u8 Stage_Continue[2];  /* 02016B74 */
u8 Pause_Hit_Marks;  /* 02016B76 */
u8 Special_Settle;  /* 02016B77 */
u8 Extra_Break;  /* 02016B78 */
u8 Shin_Gouki_BGM;  /* 02016B79 */
s8 Stage_Lost_Round[2];  /* 02016B7A */
s8 Stage_Perfect_Finish[2];  /* 02016B7C */
s8 Stage_Cheap_Finish[2];  /* 02016B7E */
s8 EXE_obroll;  /* 02016B80 */
u8 End_PL;  /* 02016B81 */
s8 Stage_Judge_Finish[2];  /* 02016B82 */
u8 PB_Status;  /* 02016B84 */
u8 Flip_Counter[2];  /* 02016B85 */
u8 Stage_Time_Finish[2];  /* 02016B87 */
u8 Bonus_Type;  /* 02016B89 */
s8 Completion_Bonus[2][2];  /* 02016B8A */
s8 ichikannkei;  /* 02016B8E */
s16 bs2_floor[3];  /* 02016B90 */
s16 bs2_hosei[3];  /* 02016B96 */
s16 bs2_current_damage;  /* 02016B9C */
u8 WIN_X;  /* 02016B9E */
s8 Complete_Face;  /* 02016B9F */
u8 Plate_Disposal_No[2][3];  /* 02016BA0 */
u8 SO_No[2];  /* 02016BA6 */
u8 Order[100];  /* 02016BA8 */
u8 Order_Dir[100];  /* 02016C0C */
u8 Order_Timer[100];  /* 02016C70 */
u16 Win_Record[2];  /* 02016CD4 */
u16 Stock_Win_Record[2];  /* 02016CD8 */
u8 Disp_Command_Name[2][3];  /* 02016CDC */
u32 * Synchro_Address[2][2];  /* 02016CE4 */
u8 SC_No[4];  /* 02016CF4 */
u8 EM_List[2][2];  /* 02016CF8 */
s8 Sel_EM_Complete[2];  /* 02016CFC */
s8 Temporary_EM[2];  /* 02016CFE */
s8 Suicide[8];  /* 02016D00 */
const u8 * Free_Ptr[2];  /* 02016D08 */
u8 BGM_No[2];  /* 02016D10 */
u8 BGM_Timer[2];  /* 02016D12 */
u16 WGJ_Win;  /* 02016D14 */
u32 WGJ_Score;  /* 02016D18 */
u8 EM_History[2][10];  /* 02016D1C */
u8 Scene_Cut;  /* 02016D30 */
u8 GO_No[4];  /* 02016D31 */
u8 Aborigine;  /* 02016D35 */
s16 Target_BG_X[6];  /* 02016D36 */
s16 Offset_BG_X[6];  /* 02016D42 */
u8 Continue_Count_Down[2];  /* 02016D4E */
u8 WGJ_Target;  /* 02016D50 */
u8 Final_Result_id;  /* 02016D51 */
u8 EM_Candidate[2][2][10];  /* 02016D52 */
u8 Wipe_Panel_Count;  /* 02016D7A */
s8 Last_Selected_EM[2];  /* 02016D7B */
u8 Battle_Round[2];  /* 02016D7D */
u8 Battle_Q[2];  /* 02016D7F */
u8 Q_Country;  /* 02016D81 */
u8 Continue_Cut[2];  /* 02016D82 */
u8 Introduce_Boss[2][2];  /* 02016D84 */
u8 Stage_Intro_Flag;  /* 02016D88 */
u8 Appear_Q;  /* 02016D89 */
u32 Bonus_Score_Plus;  /* 02016D8C */
s8 Cut_Scroll;  /* 02016D90 */
u32 Perfect_Bonus[2];  /* 02016D94 */
s8 OK_Moving_SA_Plate[2];  /* 02016D9C */
u8 Final_Play_Type[2];  /* 02016D9E */
s8 Best_Grade[2];  /* 02016DA0 */
s8 Cursor_Timer[2];  /* 02016DA2 */
s16 Result_Timer[2];  /* 02016DA4 */
u8 Reset_Timer[2];  /* 02016DA8 */
s16 scrl;  /* 02016DAA */
s16 scrr;  /* 02016DAC */
u8 bbbs_type;  /* 02016DAE */
u8 Straight_Flag[2];  /* 02016DAF */
u8 kakushi_on;  /* 02016DB1 */
u8 kakushi_ix;  /* 02016DB2 */
u8 kakushi_op;  /* 02016DB3 */
u8 RO_backup[2];  /* 02016DB4 */
u8 PT_backup;  /* 02016DB6 */
u8 dm17_to_nm23_flag;  /* 02016DB7 */
u8 dm17_to_nm23_flag_tail[148];  /* after dm17_to_nm23_flag; nothing refers to it by name or address */
