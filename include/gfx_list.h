#include <Common.h>
#include "plugin_common.h"
const char * rockford_hills = "rockford_hills";
const char* gfx_name_list[] {
"aircraft_dials.gfx",
	"app_job_list.gfx",
	"app_mission_stats_view.gfx",
	"app_numberpad.gfx",
	"app_securoserv_hacking.gfx",
	"app_todo_list.gfx",
	"app_todo_view.gfx",
	"app_trackify.gfx",
	"arcade_business_hub.gfx",
	"arcade_management.gfx",
	"arena_career_wall.gfx",
	"arena_gun_cam_apocalypse.gfx",
	"arena_gun_cam_consumer.gfx",
	"arena_gun_cam_scifi.gfx",
	"arm1_connected_baby.gfx",
	"arm3_connected_lara.gfx",
	"atm.gfx",
	"badger_blank_home.gfx",
	"badger_blank_inprogress.gfx",
	"badger_blank_lamar.gfx",
	"badger_blank_lester.gfx",
	"badger_blank_michael.gfx",
	"badger_dialing_michael.gfx",
	"bank_job_login.gfx",
	"biker_businesses.gfx",
	"biker_mission_wall.gfx",
	"binoculars.gfx",
	"blimp_text.gfx",
	"breaking_news.gfx",
	"camera_gallery.gfx",
	"camera_shutter.gfx",
	"casino_heist_board_finale.gfx",
	"casino_heist_board_prep.gfx",
	"casino_heist_board_setup.gfx",
	"cellphone_alert_popup.gfx",
	"cellphone_badger.gfx",
	"cellphone_cutscene.gfx",
	"cellphone_facade.gfx",
	"cellphone_ifruit.gfx",
	"cellphone_prologue.gfx",
	"clubhouse_name.gfx",
	"colour_switcher_01.gfx",
	"colour_switcher_02.gfx",
	"controller_test.gfx",
	"countdown.gfx",
	"covert_ops.gfx",
	"custom_warning_screen.gfx",
	"dashboard.gfx",
	"desktop_pc.gfx",
	"dials_lazer.gfx",
	"dials_lazer_vintage.gfx",
	"digiscanner.gfx",
	"digital_camera.gfx",
	"disruption_logistics.gfx",
	"dlc_arena_int2.gfx",
	"dlc_sol.gfx",
	"dre1_badger_lj.gfx",
	"drilling.gfx",
	"drone_cam.gfx",
	"ecg_monitor.gfx",
	"epsilon_tract.gfx",
	"exl2_blank_jimmy.gfx",
	"exl2_connected_jimmy.gfx",
	"facade_blank_home.gfx",
	"facade_blank_inprogress.gfx",
	"facade_blank_michael.gfx",
	"facade_computer_desktopwide.gfx",
	"fam2_playmusic.gfx",
	"fam3_01_ncallingmartin.gfx",
	"fam3_02_ncallingmartin.gfx",
	"fam3_03_ncallingmartin.gfx",
	"fam3_04_ncallingmartin.gfx",
	"fam3_05_ncallingmartin.gfx",
	"fam3_all_ncallingmartin.gfx",
	"fame_or_shame_camera.gfx",
	"fib3_daven.gfx",
	"fib3_steveh.gfx",
	"fib4_eyefindmap.gfx",
	"fib5_lestertext.gfx",
	"fib_pc.gfx",
	"finb_connected_amanda.gfx",
	"finc1_eyefind.gfx",
	"finc1_merrysite.gfx",
	"font_lib_efigs.gfx",
	"font_lib_heists.gfx",
	"font_lib_org.gfx",
	"font_lib_slots.gfx",
	"font_lib_taxi.gfx",
	"font_lib_typewriter.gfx",
	"font_lib_web.gfx",
	"grid_layout.gfx",
	"hacker_truck_desktop.gfx",
	"hacking_pc.gfx",
	"hair_colour_card.gfx",
	"hangar_cargo.gfx",
	"heist2_celebration.gfx",
	"heist2_celebration_bg.gfx",
	"heist2_celebration_fg.gfx",
	"heist_agency.gfx",
	"heist_docks.gfx",
	"heist_endscreen.gfx",
	"heist_finale.gfx",
	"heist_jewellery.gfx",
	"heist_paleto.gfx",
	"heli_cam.gfx",
	"hs3f_dir_couple1.gfx",
	"hs3f_dir_couple2.gfx",
	"hud.gfx",
	"hud_area_name.gfx",
	"hud_cash.gfx",
	"hud_cash_change.gfx",
	"hud_district_name.gfx",
	"hud_drugs_purse_01.gfx",
	"hud_drugs_purse_02.gfx",
	"hud_drugs_purse_03.gfx",
	"hud_drugs_purse_04.gfx",
	"hud_mission_passed_message.gfx",
	"hud_mp_cash.gfx",
	"hud_mp_message.gfx",
	"hud_multiplayer_chat.gfx",
	"hud_player_switch_alert.gfx",
	"hud_reticle.gfx",
	"hud_saving.gfx",
	"hud_street_name.gfx",
	"hud_vehicle_name.gfx",
	"iaa_heist_board.gfx",
	"ifruit_blank_email.gfx",
	"ifruit_blank_franklin.gfx",
	"ifruit_blank_home.gfx",
	"ifruit_blank_inprogress.gfx",
	"ifruit_computer_desktopwide.gfx",
	"ifruit_connected_franklin.gfx",
	"import_export_warehouse.gfx",
	"instructional_buttons.gfx",
	"jhpb_01_laptop.gfx",
	"jhpb_02_laptop.gfx",
	"jhpb_03_laptop.gfx",
	"jos2_01_photogallery.gfx",
	"jos2_02_photogallery.gfx",
	"jos2_all_photogallery.gfx",
	"lester_hack_pc.gfx",
	"letter_scraps.gfx",
	"lifeinvader_presentation.gfx",
	"lifeinvader_tablet43.gfx",
	"ls1_lester_eyefind.gfx",
	"ls1_lester_preeyefind.gfx",
	"ls1_lifeinvader_call.gfx",
	"ls1_lifeinvader_home.gfx",
	"ls1_lifeinvader_updates.gfx",
	"mar1_tablet_havier.gfx",
	"mar1_tablet_havierhori.gfx",
	"mic3_lester.gfx",
	"mic4_breakingnews.gfx",
	"midsized_message.gfx",
	"mission_complete.gfx",
	"mission_quit.gfx",
	"mission_target_complete.gfx",
	"morgue_laptop.gfx",
	"mp_award_freemode.gfx",
	"mp_big_message_freemode.gfx",
	"mp_bounty_board.gfx",
	"mp_car_stats.gfx",
	"mp_car_stats_01.gfx",
	"mp_car_stats_02.gfx",
	"mp_car_stats_03.gfx",
	"mp_car_stats_04.gfx",
	"mp_car_stats_05.gfx",
	"mp_car_stats_06.gfx",
	"mp_car_stats_07.gfx",
	"mp_car_stats_08.gfx",
	"mp_car_stats_09.gfx",
	"mp_car_stats_10.gfx",
	"mp_car_stats_11.gfx",
	"mp_car_stats_12.gfx",
	"mp_car_stats_13.gfx",
	"mp_car_stats_14.gfx",
	"mp_car_stats_15.gfx",
	"mp_car_stats_16.gfx",
	"mp_car_stats_17.gfx",
	"mp_car_stats_18.gfx",
	"mp_car_stats_19.gfx",
	"mp_car_stats_20.gfx",
	"mp_celebration.gfx",
	"mp_celebration_bg.gfx",
	"mp_celebration_fg.gfx",
	"mp_crew_tag.gfx",
	"mp_freemode_checkpoint.gfx",
	"mp_freemode_checkpoint_1.gfx",
	"mp_freemode_checkpoint_2.gfx",
	"mp_freemode_checkpoint_3.gfx",
	"mp_freemode_checkpoint_4.gfx",
	"mp_freemode_checkpoint_5.gfx",
	"mp_freemode_checkpoint_6.gfx",
	"mp_freemode_checkpoint_7.gfx",
	"mp_freemode_checkpoint_8.gfx",
	"mp_freemode_checkpoint_9.gfx",
	"mp_freemode_checkpoint_10.gfx",
	"mp_gamer_info.gfx",
	"mp_icons.gfx",
	"mp_matchmaking_card.gfx",
	"mp_matchmaking_selector.gfx",
	"mp_matchmaking_vehicle_info.gfx",
	"mp_medal_freemode.gfx",
	"mp_menu_glare.gfx",
	"mp_mission_details_card.gfx",
	"mp_mission_name_freemode.gfx",
	"mp_mission_name_freemode_1.gfx",
	"mp_mission_name_freemode_2.gfx",
	"mp_mm_card_freemode.gfx",
	"mp_next_job_selection.gfx",
	"mp_online_list_card.gfx",
	"mp_player_card.gfx",
	"mp_results_panel.gfx",
	"mp_spectator_card.gfx",
	"mp_spectator_overlay.gfx",
	"mp_unlock_freemode.gfx",
	"mp_vehicle_info.gfx",
	"mugshot_board_01.gfx",
	"mugshot_board_02.gfx",
	"multiplayer_chat.gfx",
	"new_editor.gfx",
	"nightclub.gfx",
	"observatory_scope.gfx",
	"ome1_powercell.gfx",
	"open_wheel_health_indicator.gfx",
	"orbital_cannon_cam.gfx",
	"orbital_cannon_map.gfx",
	"organisation_name.gfx",
	"party_bus.gfx",
	"pause_menu_pages_awards.gfx",
	"pause_menu_pages_char_mom_dad.gfx",
	"pause_menu_pages_char_select.gfx",
	"pause_menu_pages_corona.gfx",
	"pause_menu_pages_corona_lobby.gfx",
	"pause_menu_pages_corona_players.gfx",
	"pause_menu_pages_corona_race.gfx",
	"pause_menu_pages_crews.gfx",
	"pause_menu_pages_friends.gfx",
	"pause_menu_pages_friends_mp.gfx",
	"pause_menu_pages_gallery.gfx",
	"pause_menu_pages_game.gfx",
	"pause_menu_pages_info.gfx",
	"pause_menu_pages_map.gfx",
	"pause_menu_pages_missioncreator.gfx",
	"pause_menu_pages_save.gfx",
	"pause_menu_pages_stats.gfx",
	"pause_menu_pages_store.gfx",
	"pause_menu_pages_weapons.gfx",
	"pause_menu_shared_components_mp_01.gfx",
	"pause_menu_spchar_overlays.gfx",
	"phi_maxim.gfx",
	"player_name_01.gfx",
	"player_name_02.gfx",
	"player_name_03.gfx",
	"player_name_04.gfx",
	"player_name_05.gfx",
	"player_name_06.gfx",
	"player_name_07.gfx",
	"player_name_08.gfx",
	"player_name_09.gfx",
	"player_name_10.gfx",
	"player_name_11.gfx",
	"player_name_12.gfx",
	"player_name_13.gfx",
	"player_name_14.gfx",
	"player_name_15.gfx",
	"player_switch.gfx",
	"player_switch_prologue.gfx",
	"player_switch_stats_panel.gfx",
	"power_play.gfx",
	"power_play_biker.gfx",
	"power_play_day_night.gfx",
	"power_play_generic.gfx",
	"power_play_special_races.gfx",
	"power_play_turf.gfx",
	"power_play_vehicle.gfx",
	"psychology_report.gfx",
	"race_message.gfx",
	"race_position.gfx",
	"rampage.gfx",
	"rcmaude_laptop.gfx",
	"remote_sniper_hud.gfx",
	"remote_sniper_loading.gfx",
	"rh2a_01_laptop.gfx",
	"rh2a_02_laptop.gfx",
	"rh2a_03_laptop.gfx",
	"rh2a_04_laptop.gfx",
	"rh2a_05_laptop.gfx",
	"rh2a_06_laptop.gfx",
	"rh2a_07_laptop.gfx",
	"saving_footer.gfx",
	"security_cam.gfx",
	"security_camera.gfx",
	"securoserv.gfx",
	"shop_menu.gfx",
	"shop_menu_dlc.gfx",
	"slot_machine.gfx",
	"social_club_tv.gfx",
	"splash_text.gfx",
	"starter_pack_browser.gfx",
	"strength_test_score.gfx",
	"stunt_jumps.gfx",
	"sub_cam.gfx",
	"sub_pc.gfx",
	"tattoo_buttons.gfx",
	"taxi_display.gfx",
	"teeth_pulling.gfx",
	"textcanvas.gfx",
	"textfield.gfx",
	"text_input_box.gfx",
	"traffic_cam.gfx",
	"turret_cam.gfx",
	"tv_frame.gfx",
	"tv_static.gfx",
	"vault_drill.gfx",
	"vault_laser.gfx",
	"warehouse.gfx",
	"watermark.gfx",
	"wind_meter.gfx",
	"yacht_gamername.gfx",
	"yacht_name.gfx",
	"yacht_name_stern.gfx",
	"yoga_buttons.gfx",
	"__template.gfx",
	"auto_shop_board.gfx",
	"auto_shop_crew_name.gfx",
	"bomb_countdown.gfx",
	"daily_vehicle_checklist.gfx",
	"digital_safe_display.gfx",
	"finmcs2drephone.gfx",
	"fixer_app.gfx",
	"fix_agyint3_snap.gfx",
	"fix_wrms_food.gfx",
	"font_lib_heist4.gfx",
	"hs4_casint_elrubio.gfx",
	"hs4_casint_girl.gfx",
	"ifruit_blank_hao.gfx",
	"ifruit_blank_homehi.gfx",
	"ifruit_blank_jguns.gfx",
	"island_heist_board.gfx",
	"music_studio_monitor.gfx",
	"music_studio_monitor_cs.gfx",
	"music_studio_monitor_cs2.gfx",
	"nas_upload.gfx",
	"phone_blank_screen.gfx",
	"scope.gfx",
	"studio_3_ary.gfx",
	"submarine_missiles.gfx",
	"trip3_phone2_1.gfx",
	"trip3_phone4_1.gfx",
	"tun_dj4_blank.gfx",
	"tun_dj4_speaker.gfx",
	"tun_fruitlaptop_dj4.gfx",
	"tun_fruitlaptop_ssas.gfx",
	"busy_spinner.gfx",
	"font_lib_editor.gfx",
	"font_lib_sc.gfx",
	"game_stream.gfx",
	"generic_instructional_buttons.gfx",
	"gtav_online.gfx",
	"landing_page.gfx",
	"loadingscreen_newgame.gfx",
	"loadingscreen_startup.gfx",
	"mouse_pointer.gfx",
	"online_policies.gfx",
	"opening_credits.gfx",
	"pause_menu_calibration.gfx",
	"pause_menu_header.gfx",
	"pause_menu_instructional_buttons.gfx",
	"pause_menu_pages_keymap.gfx",
	"pause_menu_pages_settings.gfx",
	"pause_menu_shared_components.gfx",
	"pause_menu_shared_components_02.gfx",
	"pause_menu_shared_components_03.gfx",
	"pause_menu_sp_content.gfx",
	"pause_menu_store_content.gfx",
	"popup_warning.gfx",
	"social_club2.gfx",
	"store_background.gfx",
	"store_blackout.gfx",
	"store_instructional_buttons.gfx",
	"font_lib_chinese_ps4.gfx",
	"font_lib_japanese_ps4.gfx",
	"font_lib_korean_ps4.gfx",
	"language_select_ps4.gfx",
	"darts_scoreboard.gfx",
	"golf.gfx",
	"golf_floating_ui.gfx",
	"sc_leaderboard.gfx",
	"tennis.gfx",
	"golf_courses.gfx",
	"int18753073.gfx",
	"int29297920.gfx",
	"int45843946.gfx",
	"int87116549.gfx",
	"int100117129.gfx",
	"int100340708.gfx",
	"int101947763.gfx",
	"int169410130.gfx",
	"int222538689.gfx",
	"int223682799.gfx",
	"int225974099.gfx",
	"int325451334.gfx",
	"int395687705.gfx",
	"int396257289.gfx",
	"int551019620.gfx",
	"int604839936.gfx",
	"int607268480.gfx",
	"int672057080.gfx",
	"int720927456.gfx",
	"int755114396.gfx",
	"int760271382.gfx",
	"int877826681.gfx",
	"int1045460371.gfx",
	"int1076883030.gfx",
	"int1126589261.gfx",
	"int1313058309.gfx",
	"int1314234446.gfx",
	"int1338737678.gfx",
	"int1451945473.gfx",
	"int1457285595.gfx",
	"int1477966980.gfx",
	"int1502135388.gfx",
	"int1539880578.gfx",
	"int1575184793.gfx",
	"int1649429645.gfx",
	"int1658711316.gfx",
	"int1667328242.gfx",
	"int1681413451.gfx",
	"int1724779208.gfx",
	"int1753457757.gfx",
	"int1847849587.gfx",
	"int1850662048.gfx",
	"int1911774823.gfx",
	"int1932111343.gfx",
	"int1944407757.gfx",
	"int1947430931.gfx",
	"int2005138720.gfx",
	"int2014101067.gfx",
	"int2060616239.gfx",
	"int2081281344.gfx",
	"int2092539216.gfx",
	"int2243729813.gfx",
	"int2264733808.gfx",
	"int2287809945.gfx",
	"int2309566359.gfx",
	"int2349762459.gfx",
	"int2436346921.gfx",
	"int2445348866.gfx",
	"int2466983751.gfx",
	"int2468983919.gfx",
	"int2471697375.gfx",
	"int2473630971.gfx",
	"int2506843673.gfx",
	"int2510424210.gfx",
	"int2534770801.gfx",
	"int2537665061.gfx",
	"int2556174080.gfx",
	"int2604216443.gfx",
	"int2604928035.gfx",
	"int2614217053.gfx",
	"int2700496377.gfx",
	"int2700932031.gfx",
	"int2707902698.gfx",
	"int2725746152.gfx",
	"int2769004935.gfx",
	"int2785612356.gfx",
	"int2789279894.gfx",
	"int2814402943.gfx",
	"int2825451971.gfx",
	"int2861009345.gfx",
	"int2885533878.gfx",
	"int2959581328.gfx",
	"int3026799998.gfx",
	"int3063328744.gfx",
	"int3224364317.gfx",
	"int3273555063.gfx",
	"int3288659403.gfx",
	"int3399754112.gfx",
	"int3425927872.gfx",
	"int3432762226.gfx",
	"int3611448162.gfx",
	"int3627243541.gfx",
	"int3699881347.gfx",
	"int3713406170.gfx",
	"int3816969092.gfx",
	"int3894793287.gfx",
	"int3923485432.gfx",
	"int3995986907.gfx",
	"int4014505412.gfx",
	"int4187740826.gfx",
	"int4205710902.gfx",
	"int4213851576.gfx",
	"int4215916068.gfx",
	"int4221947581.gfx",
	"int4242268455.gfx",
	"int4268309143.gfx",
	"minimap.gfx",
	"minimap_main_map.gfx",
	"web_browser.gfx",
	"www_abstinentamerica_com.gfx",
	"www_accept_d_the_d_chaos_com.gfx",
	"www_altruistsunite_com.gfx",
	"www_ammunation_net.gfx",
	"www_appropriateassociates_com.gfx",
	"www_bawsaq_com.gfx",
	"www_bedevinweston_com.gfx",
	"www_beseecher_net.gfx",
	"www_bleeter_biz.gfx",
	"www_bullsharktestosterone_com.gfx",
	"www_cashfordeaddreams_com.gfx",
	"www_chainsofintimacy_com.gfx",
	"www_classicvinewood_com.gfx",
	"www_creditcardconsolidationkings_com.gfx",
	"www_cultstoppers_com.gfx",
	"www_docktease_com.gfx",
	"www_dr_d_friedlander_com.gfx",
	"www_dynasty8realestate_com.gfx",
	"www_egochaserenergybar_com.gfx",
	"www_electrotokesystem_com.gfx",
	"www_elitastravel_com.gfx",
	"www_epsilonprogram_com.gfx",
	"www_eyefind_info.gfx",
	"www_fabienlaroucheyoga_com.gfx",
	"www_fameorshame_net.gfx",
	"www_fleeca_com.gfx",
	"www_fruitcomputers_com.gfx",
	"www_grainoftruth_net.gfx",
	"www_hammersteinfaust_com.gfx",
	"www_himplantsenhancementsurgery_com.gfx",
	"www_hushsmush_com.gfx",
	"www_iwillsurviveitall_com.gfx",
	"www_jackhowitzer_com.gfx",
	"www_jockcranley_com.gfx",
	"www_junkenergydrink_com.gfx",
	"www_kungfurainbowlazerforce_com.gfx",
	"www_lcn_d_exchange_com.gfx",
	"www_legendarymotorsport_net.gfx",
	"www_lennyavery_d_realty_com.gfx",
	"www_lifeinvader_com.gfx",
	"www_lossantoscustoms_com.gfx",
	"www_lossantosfreegans_com.gfx",
	"www_manopauseadventures_com.gfx",
	"www_maze_d_bank_com.gfx",
	"www_merryweathersecurity_com.gfx",
	"www_ministerinminutes_com.gfx",
	"www_minotaurfinance_com.gfx",
	"www_monetaryscience_us.gfx",
	"www_mydivinewithin_com.gfx",
	"www_myroomonline_net.gfx",
	"www_pandmcycles_com.gfx",
	"www_preservexskincream_com.gfx",
	"www_princessrobotbubblegum_com.gfx",
	"www_proposition43_org.gfx",
	"www_proposition208_com.gfx",
	"www_psychicshoutout_com.gfx",
	"www_republicanspacerangers_com.gfx",
	"www_righteousslaughter7_com.gfx",
	"www_sanandreasdmv_com.gfx",
	"www_sawaterandpower_com.gfx",
	"www_sixfiguretemps_com.gfx",
	"www_southernsanandreassuperautos_com.gfx",
	"www_stoppayingyourmortgage_net.gfx",
	"www_suemurry_com.gfx",
	"www_swallowco_com.gfx",
	"www_taco_d_bomb_com.gfx",
	"www_thebankofliberty_com.gfx",
	"www_thechildrenofthemountain_com.gfx",
	"www_theinternetisahellhole_com.gfx",
	"www_thepowcleanse_com.gfx",
	"www_therealitymill_com.gfx",
	"www_toeshoesusa_com.gfx",
	"www_toiletcleaneronline_com.gfx",
	"www_universaluniform_net.gfx",
	"www_vanillaunicorn_xxx.gfx",
	"www_vinewoodloglinegenerator_com.gfx",
	"www_visitthealamosea_com.gfx",
	"www_warstock_d_cache_d_and_d_carry_com.gfx",
	"www_whokilledleonorajohnson_com.gfx",
	"www_yourdeadfamily_com.gfx",
	"www_yournewbabysname_com.gfx",
	"font_lib_efigs_ps4.gfx"
	};
