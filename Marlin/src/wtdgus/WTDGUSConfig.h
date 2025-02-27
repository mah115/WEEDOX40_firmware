/**
* Copyright (C) 2020 Wiibooxtech Perron
*/

/*
* DGus ��������
*/

#ifndef WTDGUSCONFIG_H
#define WTDGUSCONFIG_H

#define UI_VERSION					"2.5"

#define SCREEN_BOOT					0

#define SCREEN_MAIN					1

#define ADDR_MAIN_KEY				0x1100
#define ADDR_MAIN_ICON_NOZZLE		0x1101
#define ADDR_MAIN_TEXT_NOZZLE1		0x1102
#define ADDR_MAIN_TEXT_NOZZLE2		0x1104
#define ADDR_MAIN_ICON_BED			0x1108
#define ADDR_MAIN_TEXT_BED			0x1109
#define ADDR_MAIN_TEXT_IP			0x11A0
#define ADDR_MAIN_ICON_IP			0x111C
#define ADDR_MAIN_TEXT4				0x1180
#define ADDR_MAIN_TEXT3				0x1160
#define ADDR_MAIN_TEXT2				0x1140
#define ADDR_MAIN_TEXT1				0x1120
#define ADDR_MAIN_ICON4				0x1118
#define ADDR_MAIN_ICON2				0x1114
#define ADDR_MAIN_ICON3				0x1116
#define ADDR_MAIN_ICON1				0x1112

#define KEY_MAIN_BUTTON1			0x0001
#define KEY_MAIN_BUTTON2			0x0002
#define KEY_MAIN_BUTTON3			0x0003
#define KEY_MAIN_BUTTON4			0x0004

#define ENUM_MAIN_IP_NOWIFI			0x0
#define ENUM_MAIN_IP_WIFIOFF		0x1
#define ENUM_MAIN_IP_WIFI0			0x2
#define ENUM_MAIN_IP_WIFI1			0x3
#define ENUM_MAIN_IP_WIFI2			0x4
#define ENUM_MAIN_IP_WIFI3			0x5
#define ENUM_MAIN_IP_WIFI4			0x6

#define ENUM_HELP_ICON_NOHELP		0x0
#define ENUM_HELP_ICON_HELP			0x1

#define SCREEN_SDCARD				2

#define ADDR_TF_KEY					0x1200
#define ADDR_TF_FILE1_TEXT			0x12A0
#define ADDR_TF_FILE2_TEXT			0x12D0
#define ADDR_TF_FILE3_TEXT			0x1300
#define ADDR_TF_FILE4_TEXT			0x1330
#define ADDR_TF_FILE5_TEXT			0x1360
#define ADDR_TF_FILE6_TEXT			0x1390
#define ADDR_TF_NEXT_TEXT			0x1280
#define ADDR_TF_PRE_TEXT			0x1260
#define ADDR_TF_BACK_TEXT			0x1240
#define ADDR_TF_TITLE				0x1220
#define ADDR_TF_HELP_ICON			0x111A

#define KEY_TF_RETURN				0x0001
#define KEY_TF_NEXT					0x0003	
#define KEY_TF_PRE					0x0002
#define KEY_TF_FILE1				0x0004
#define KEY_TF_FILE2				0x0005
#define KEY_TF_FILE3				0x0006
#define KEY_TF_FILE4				0x0007
#define KEY_TF_FILE5				0x0008
#define KEY_TF_FILE6				0x0009
#define KEY_TF_HELPBUTTON			0x000F

#define DGUS_SDMENU_FILENAME_ADDR		ADDR_TF_FILE1_TEXT
#define DGUS_SDMENU_FILENAME_INTERVAL	0x30

#define TEXTLEN_TF_TITLE		30
#define TEXTLEN_TF_ITEM			40
#define TEXTLEN_TF_BUTTON		20

#define SCREEN_SETTING				4

#define ADDR_SETTING_KEY			0x1400
#define ADDR_SETTING_ICON_HELP		0x1401
#define ADDR_SETTING_ICON_ITEM1		0x1402
#define ADDR_SETTING_ICON_ITEM2		0x1403
#define ADDR_SETTING_ICON_ITEM3		0x1404
#define ADDR_SETTING_IMG_ITEM1		0x1405
#define ADDR_SETTING_IMG_ITEM2		0x1406
#define ADDR_SETTING_IMG_ITEM3		0x1407
#define ADDR_SETTING_TEXT_TITLE		0x1410
#define ADDR_SETTING_TEXT_RETURN	0x1430
#define ADDR_SETTING_TEXT_PRE		0x1450
#define ADDR_SETTING_TEXT_NEXT		0x1470
#define ADDR_SETTING_TEXT_ITEM1		0x1490
#define ADDR_SETTING_TEXT_ITEM2		0x14B0
#define ADDR_SETTING_TEXT_ITEM3		0x14D0

#define TEXTLEN_SETTING_TITLE		30
#define TEXTLEN_SETTING_ITEM		32
#define TEXTLEN_SETTING_BUTTON		20

#define KEY_SETTING_RETURN			0x0001
#define KEY_SETTING_NEXT			0x0003	
#define KEY_SETTING_PRE				0x0002
#define KEY_SETTING_ITEM1			0x0004
#define KEY_SETTING_ITEM2			0x0005
#define KEY_SETTING_ITEM3			0x0006
#define KEY_SETTING_HELPBUTTON		0x000F

#define ENUM_OPTION_NONE			0x0
#define ENUM_OPTION_OFF				0x1
#define ENUM_OPTION_ON				0x2

#define ENUM_SETTING_NONE			0
#define ENUM_SETTING_FILAMENT		1
#define ENUM_SETTING_FEED_IN		2
#define ENUM_SETTING_RETRACT		3
#define ENUM_SETTING_HEAT			4
#define ENUM_SETTING_JOB			5
#define ENUM_SETTING_LEVELBED		6
#define ENUM_SETTING_ZOFFSET		7
#define ENUM_SETTING_TEMP			8
#define ENUM_SETTING_SPEED			9
#define ENUM_SETTING_POWEROFF		10
#define ENUM_SETTING_SAVE			11
#define ENUM_SETTING_SENSOR			12
#define ENUM_SETTING_MOTOROFF		13
#define ENUM_SETTING_WIFI			14
#define ENUM_SETTING_RUNOUT			15
#define ENUM_SETTING_SELFTEST		16
#define ENUM_SETTING_POWERSAVING	17
#define ENUM_SETTING_LANGUAGE		18
#define ENUM_SETTING_INFO			19
#define ENUM_SETTING_RESTORE		20
#define ENUM_SETTING_NOZZLE_X		21
#define ENUM_SETTING_NOZZLE_XY		22
#define ENUM_SETTING_DIAG			23
#define ENUM_SETTING_NOZZLE_Z		24
#define ENUM_SETTING_TFCAED			25
#define ENUM_SETTING_WIFIDISK		26
#define ENUM_SETTING_UPDATE			27
#define ENUM_SETTING_WIFICONFIG		28
#define ENUM_SETTING_CLOUD			29
#define ENUM_SETTING_TF_SAVE		30
#define ENUM_SETTING_TF_LOAD		31
#define ENUM_SETTING_WIKI		    32
#define ENUM_SETTING_CONTACT	    33
#define ENUM_SETTING_NORMAL 	    34
#define ENUM_SETTING_COPY    	    35
#define ENUM_SETTING_MIRROR 	    36


#define SCREEN_2BINFO				5
#define ADDR_2BINFO_KEY				0x1500
#define ADDR_2BINFO_HELP_ICON		0x1501
#define ADDR_2BINFO_TITLE			0x1510
#define ADDR_2BINFO_TEXT_BUTTON1	0x1530
#define ADDR_2BINFO_TEXT_BUTTON2	0x1550
#define ADDR_2BINFO_TEXT_LINE		0x1570

#define KEY_2BINFO_ITEM1			0x0001
#define KEY_2BINFO_ITEM2			0x0002
#define KEY_2BINFO_HELPBUTTON		0x000F

#define TEXTLEN_2BINFO_TITLE		30
#define TEXTLEN_2BINFO_ITEM			400
#define TEXTLEN_2BINFO_BUTTON		20

#define SCREEN_STATUS				7
#define ADDR_STATUS_KEY				0x1700
#define ADDR_STATUS_ICON_HELP		0x1701
#define ADDR_STATUS_ICON1			0x1702
#define ADDR_STATUS_ICON2			0x1703
#define ADDR_STATUS_ICON3			0x1704
#define ADDR_STATUS_ICON4			0x1705
#define ADDR_STATUS_ICON5			0x1706
#define ADDR_STATUS_ICON6			0x1707
#define ADDR_STATUS_PERCENT			0x1708
#define ADDR_STATUS_TEXT_BUTTON1	0x1720
#define ADDR_STATUS_TEXT_BUTTON2	0x1740
#define ADDR_STATUS_TEXT_BUTTON3	0x1760
#define ADDR_STATUS_TEXT_TITLE		0x1780
#define ADDR_STATUS_TEXT_NAME1		0x17A0
#define ADDR_STATUS_TEXT_VALUE1		0x17B0
#define ADDR_STATUS_TEXT_NAME2		0x17E0
#define ADDR_STATUS_TEXT_VALUE2		0x17F0
#define ADDR_STATUS_TEXT_NAME3		0x1800
#define ADDR_STATUS_TEXT_VALUE3		0x1810
#define ADDR_STATUS_TEXT_NAME4		0x1820
#define ADDR_STATUS_TEXT_VALUE4		0x1830
#define ADDR_STATUS_TEXT_NAME5		0x1840
#define ADDR_STATUS_TEXT_VALUE5		0x1850
#define ADDR_STATUS_TEXT_NAME6		0x1860
#define ADDR_STATUS_TEXT_VALUE6		0x1870
#define ADDR_STATUS_TEXT_NAME7		0x1880
#define ADDR_STATUS_TEXT_VALUE7		0x1890

#define KEY_STATUS_RETURN			0x0001
#define KEY_STATUS_PAUSE			0x0002
#define KEY_STATUS_SETTING			0x0003
#define KEY_STATUS_BUTTON_HELP		0x000F

#define ENUM_STATUS_NONE			0
#define ENUM_STATUS_FILE			1
#define ENUM_STATUS_NOZZLE			2
#define ENUM_STATUS_BED				3
#define ENUM_STATUS_SPEED			4
#define ENUM_STATUS_ELAPSED			5
#define ENUM_STATUS_REMAIN			6

#define SCREEN_2OPTION				9

#define ADDR_2OPTION_KEY			0x1900
#define ADDR_2OPTION_ICON_HELP		0x1901
#define ADDR_2OPTION_ICON_BUTTON1	0x1902
#define ADDR_2OPTION_ICON_BUTTON2	0x1903
#define ADDR_2OPTION_TEXT_TITLE		0x1910
#define ADDR_2OPTION_TEXT_RETURN	0x1930
#define ADDR_2OPTION_TEXT_BUTTON1	0x1950
#define ADDR_2OPTION_TEXT_BUTTON2	0x1970

#define KEY_2OPTION_BUTTON_RETURN	0x0001
#define KEY_2OPTION_BUTTON_ITEM1	0x0002
#define KEY_2OPTION_BUTTON_ITEM2	0x0003
#define KEY_2OPTION_BUTTON_HELP		0x000F

#define TEXTLEN_2OPTION_TITLE		30
#define TEXTLEN_2OPTION_ITEM		32
#define TEXTLEN_2OPTION_BUTTON		20

#define SCREEN_TEMP_SETTING			10

#define ADDR_TEMP_KEY				0x2000
#define ADDR_TEMP_ICON_ITEM1		0x2001
#define ADDR_TEMP_ICON_MINUS1		0x2002
#define ADDR_TEMP_ICON_VALUE1		0x2003
#define ADDR_TEMP_ICON_PLUS1		0x2004
#define ADDR_TEMP_ICON_ITEM2		0x2005
#define ADDR_TEMP_ICON_MINUS2		0x2006
#define ADDR_TEMP_ICON_VALUE2		0x2007
#define ADDR_TEMP_ICON_PLUS2		0x2008
#define ADDR_TEMP_VALUE1			0x2009
#define ADDR_TEMP_VALUE2			0x200A
#define ADDR_TEMP_VALUE3			0x200B
#define ADDR_TEMP_ICON_HELP			0x200F
#define ADDR_TEMP_TEXT_TITLE		0x2010
#define ADDR_TEMP_TEXT_BUTTON1		0x2030
#define ADDR_TEMP_TEXT_BUTTON2		0x2050
#define ADDR_TEMP_TEXT_ITEM1		0x2070
#define ADDR_TEMP_TEXT_ITEM3		0x2080
#define ADDR_TEMP_TEXT_VALUE1		0x2090
#define ADDR_TEMP_TEXT_VALUE3		0x20A0
#define ADDR_TEMP_TEXT_ITEM2		0x20B0
#define ADDR_TEMP_TEXT_VALUE2		0x20D0

#define KEY_TEMP_BUTTON1			0x0001
#define KEY_TEMP_BUTTON2			0x0002
#define KEY_TEMP_RESET1			    0x0003
#define KEY_TEMP_RESET2			    0x0004
#define KEY_TEMP_RESET3			    0x0005
#define KEY_TEMP_BUTTON_HELP		0x000F

#define TEXTLEN_TEMP_TITLE			30
#define TEXTLEN_TEMP_ITEM			16
#define TEXTLEN_TEMP_BUTTON			20

#define SCREEN_ERROR				11
#define ADDR_ERROR_KEY				0x2100
#define ADDR_ERROR_TEXT_TITLE		0x2110
#define ADDR_ERROR_TEXT_TEXT		0x2130

#define TEXTLEN_ERROR_TITLE			30
#define TEXTLEN_ERROR_TEXT			400

#define SCREEN_FILAMENT_TYPE		13
#define ADDR_FILATYPE_KEY			0x2300
#define ADDR_FILATYPE_TEXT_TITLE	0x2310
#define ADDR_FILATYPE_TEXT_RETURN	0x2330
#define ADDR_FILATYPE_TEXT_ITEM1	0x2340
#define ADDR_FILATYPE_TEXT_VAL1		0x2350
#define ADDR_FILATYPE_TEXT_ITEM2	0x2360
#define ADDR_FILATYPE_TEXT_VAL2		0x2370
#define ADDR_FILATYPE_TEXT_ITEM3	0x2380
#define ADDR_FILATYPE_TEXT_VAL3		0x2390

#define KEY_FILATYPE_BUTTON_RETURN	0x0001
#define KEY_FILATYPE_BUTTON_ITEM1	0x0002
#define KEY_FILATYPE_BUTTON_ITEM2	0x0003
#define KEY_FILATYPE_BUTTON_ITEM3	0x0004

#define TEXTLEN_FILATYPE_TITLE			30
#define TEXTLEN_FILATYPE_ITEM			30
#define TEXTLEN_FILATYPE_NUMBER			8
#define TEXTLEN_FILATYPE_BUTTON			20

#define SCREEN_FILAMENT_OPERATION	14
#define ADDR_FILAMENT_KEY			0x2400
#define ADDR_FILAMENT_PROCESS		0x2401
#define ADDR_FILAMENT_TEXT_TITLE	0x2410
#define ADDR_FILAMENT_BUTTON_RETURN	0x2430
#define ADDR_FILAMENT_TEXT_LINE1	0x2450
#define ADDR_FILAMENT_TEXT_LINE2	0x2480
#define ADDR_FILAMENT_TEXT_TEMP		0x24A0

#define KEY_FILAMENT_BUTTON_RETURN	0x0001

#define SCREEN_PREHEAT_HEATING		15
#define ADDR_HEAT_KEY				0x2500
#define ADDR_HEAT_ICON_HELP			0x2501
#define ADDR_HEAT_ICON_ITEM1		0x2502
#define ADDR_HEAT_BAR_ITEM1			0x2503
#define ADDR_HEAT_ICON_ITEM2		0x2504
#define ADDR_HEAT_BAR_ITEM2			0x2505
#define ADDR_HEAT_BAR_ITEM3			0x2506
#define ADDR_HEAT_TEXT_TITLE		0x2510
#define ADDR_HEAT_TEXT_BUTTON1		0x2530
#define ADDR_HEAT_TEXT_BUTTON2		0x2550
#define ADDR_HEAT_TEXT_ITEM1		0x2560
#define ADDR_HEAT_TEXT_TEMP1		0x2570
#define ADDR_HEAT_TEXT_ITEM2		0x2580
#define ADDR_HEAT_TEXT_TEMP2		0x2590
#define ADDR_HEAT_TEXT_ITEM3		0x25A0
#define ADDR_HEAT_TEXT_TEMP3		0x25B0

#define KEY_HEAT_BUTTON1			0x0001
#define KEY_HEAT_BUTTON2			0x0002
#define KEY_HEAT_BUTTON_HELP		0x000F

#define SCREEN_JOB					16
#define ADDR_JOB_KEY				0x2600
#define ADDR_JOB_XADD3				0x2610
#define ADDR_JOB_XADD2				0x2611
#define ADDR_JOB_XADD1				0x2612
#define ADDR_JOB_XDEC1				0x2613
#define ADDR_JOB_XDEC2				0x2614
#define ADDR_JOB_XDEC3				0x2615
#define ADDR_JOB_YADD3				0x2625	 //mah115: modified Y and Z buttons to make left/right arrows consistent with coordinate increase/decrease
#define ADDR_JOB_YADD2				0x2624
#define ADDR_JOB_YADD1				0x2623
#define ADDR_JOB_YDEC1				0x2622
#define ADDR_JOB_YDEC2				0x2621
#define ADDR_JOB_YDEC3				0x2620
#define ADDR_JOB_ZADD3				0x2635
#define ADDR_JOB_ZADD2				0x2634
#define ADDR_JOB_ZADD1				0x2633
#define ADDR_JOB_ZDEC1				0x2632
#define ADDR_JOB_ZDEC2				0x2631
#define ADDR_JOB_ZDEC3				0x2630
#define ADDR_JOB_TEXT_TITLE			0x2640
#define ADDR_JOB_TEXT_BUTTON1		0x2660
#define ADDR_JOB_TEXT_BUTTON2		0x2690

#define KEY_JOB_BUTTON1				0x0001
#define KEY_JOB_BUTTON2				0x0002
#define KEY_JOB_BUTTON_HELP			0x000F

#define SCREEN_LEVEL				18
#define ADDR_LEVEL_KEY				0x2800
#define ADDR_LEVEL_ICON				0x2801
#define ADDR_LEVEL_TITLE			0x2810
#define ADDR_LEVEL_TEXT_BUTTON1		0x2830
#define ADDR_LEVEL_TEXT_BUTTON2		0x2850
#define ADDR_LEVEL_TEXT_LINE1		0x2870

#define KEY_LEVEL_BUTTON1			0x0001
#define KEY_LEVEL_BUTTON2			0x0002

#define TEXTLEN_LEVEL_TEXT			300

#define ENUM_LEVEL_BEGIN			0
#define ENUM_LEVEL_POS1				1
#define ENUM_LEVEL_POS2				2
#define ENUM_LEVEL_POS3				3
#define ENUM_LEVEL_POS4				4

#define SCREEN_NOTICE				20
#define ADDR_NOTICE_TEXT_TITLE		0x3010
#define ADDR_NOTICE_TEXT_LINE		0x3030
#define ADDR_NOTICE_TEXT_LINE2		0x3180

#define TEXTLEN_NOTICE_TITLE		30
#define TEXTLEN_NOTICE_ITEM			400
#define TEXTLEN_NOTICE_LINE2		60

#define SCREEN_ZOFFSET				22
#define ADDR_ZOFFSET_KEY			0x3200
#define ADDR_ZOFFSET_TEXT_TITLE		0x3210
#define ADDR_ZOFFSET_TEXT_BUTTON1	0x3230
#define ADDR_ZOFFSET_TEXT_BUTTON2	0x3250
#define ADDR_ZOFFSET_TEXT_LINE		0x3270
#define ADDR_ZOFFSET_TEXT_VALUE		0x3330
#define ADDR_ZOFFSET_TEXT2_VALUE	0x3350

#define KEY_ZOFFSET_RETURN			0x0001
#define KEY_ZOFFSET_SAVE			0x0002
#define KEY_ZOFFSET_ADD				0x0004
#define KEY_ZOFFSET_DEC				0x0003

#define TEXTLEN_ZOFFSET_TITLE		30
#define TEXTLEN_ZOFFSET_LINE		300
#define TEXTLEN_ZOFFSET_BUTTON		20

#define SCREEN_INFO					24
#define ADDR_INFO_KEY				0x3400
#define ADDR_INFO_TITLE				0x3410
#define ADDR_INFO_RETURN			0x3430
#define ADDR_INFO_LINE				0x3450
#define ADDR_INFO_LINE2				0x3580

#define KEY_INFO_RETURN				0x0001

#define TEXTLEN_INFO_TITLE			30
#define TEXTLEN_INFO_ITEM			400
#define TEXTLEN_INFO_LINE2			60
#define TEXTLEN_INFO_BUTTON			20

#define SCREEN_MACHINE_INFO			26
#define ADDR_MACHINE_KEY			0x3600
#define ADDR_MACHINE_ICON_HELP		0x3601
#define ADDR_MACHINE_TITLE			0x3610
#define ADDR_MACHINE_BUTTON1		0x3630
#define ADDR_MACHINE_BUTTON2		0x3650
#define ADDR_MACHINE_ITEM1			0x3670
#define ADDR_MACHINE_ITEM2			0x36B0
#define ADDR_MACHINE_ITEM3			0x36F0
#define ADDR_MACHINE_ITEM4			0x3730
#define ADDR_MACHINE_ITEM5			0x3770
#define ADDR_MACHINE_ITEM6			0x37B0
#define ADDR_MACHINE_VALUE1			0x3690
#define ADDR_MACHINE_VALUE2			0x36D0
#define ADDR_MACHINE_VALUE3			0x3710
#define ADDR_MACHINE_VALUE4			0x3750
#define ADDR_MACHINE_VALUE5			0x3790
#define ADDR_MACHINE_VALUE6			0x37D0
#define ADDR_MACHINE_ERROR1			0x36A0
#define ADDR_MACHINE_ERROR2			0x36E0
#define ADDR_MACHINE_ERROR3			0x3720
#define ADDR_MACHINE_ERROR4			0x3760
#define ADDR_MACHINE_ERROR5			0x37A0
#define ADDR_MACHINE_ERROR6			0x37E0

#define KEY_MACHINE_BUTTON1			0x0001
#define KEY_MACHINE_BUTTON2			0x0002
#define KEY_MACHINE_HELP			0x000F

#define TEXTLEN_MACHINE_TITLE		30
#define TEXTLEN_MACHINE_ITEM		32
#define TEXTLEN_MACHINE_BUTTON		20

#define SCREEN_WIFI_SETTING			28
#define ADDR_WIFIE_KEY				0x3800
#define ADDR_WIFI_TITLE				0x3810
#define ADDR_WIFI_RETURN			0x3830
#define ADDR_WIFI_ITEM1				0x3850
#define ADDR_WIFI_ITEM2				0x3880
#define ADDR_WIFI_VALUE1			0x3870
#define ADDR_WIFI_VALUE2			0x3890
#define ADDR_WIFI_CONFIG			0x38A0
#define ADDR_WIFI_OTA				0x38D0

#define KEY_WIFI_BUTTON_RETURN		0x0001
#define KEY_WIFI_BUTTON_CONFIG		0x0002
#define KEY_WIFI_BUTTON_OTA			0x0003

#define SCREEN_SPEED_SETTING		30
#define ADDR_SPEED_KEY				0x4000
#define ADDR_SPEED_ICON1			0x4001
#define ADDR_SPEED_ICON2			0x4002
#define ADDR_SPEED_ICON3			0x4003
#define ADDR_SPEED_ICON4			0x4004
#define ADDR_SPEED_ICON5			0x4005
#define ADDR_SPEED_ICON6			0x4006
#define ADDR_SPEED_ICON_HELP		0x400F
#define ADDR_SPEED_TEXT_TITLE		0x4010
#define ADDR_SPEED_TEXT_BUTTON1		0x4030
#define ADDR_SPEED_TEXT_BUTTON2		0x4050
#define ADDR_SPEED_TEXT1			0x4060
#define ADDR_SPEED_TEXT2			0x4070
#define ADDR_SPEED_TEXT3			0x4080
#define ADDR_SPEED_TEXT4			0x4090
#define ADDR_SPEED_TEXT5			0x40A0
#define ADDR_SPEED_TEXT6			0x40B0

#define KEY_SPEED_BUTTON1			0x0001
#define KEY_SPEED_BUTTON2			0x0002
#define KEY_SPEED_BUTTON_ITEM1		0x0003
#define KEY_SPEED_BUTTON_ITEM2		0x0004
#define KEY_SPEED_BUTTON_ITEM3		0x0005
#define KEY_SPEED_BUTTON_ITEM4		0x0006
#define KEY_SPEED_BUTTON_ITEM5		0x0007
#define KEY_SPEED_BUTTON_ITEM6		0x0008
#define KEY_SPEED_BUTTON_HELP		0x000F

#define ENUM_SPEED_ICON_OFF			0
#define ENUM_SPEED_ICON_ON			1

#define SCREEN_PRINTING_END			31
#define ADDR_PRINTEND_KEY			0x4100
#define ADDR_PRINTEND_TEXT_TITLE	0x4110
#define ADDR_PRINTEND_TEXT_AGAIN	0x4130
#define ADDR_PRINTEND_TEXT_BACK		0x4150
#define ADDR_PRINTEND_TEXT_FILENAME	0x4170
#define ADDR_PRINT_VALUE_FILENAME	0x4190
#define ADDR_PRINTEND_TEXT_TIME		0x41A0
#define ADDR_PRINTEND_VALUE_TIME	0x41C0
#define ADDR_PRINTEND_TEXT_FILAMENT	0x41D0
#define ADDR_PRINTEND_VALUE_FILAMENT	0x41F0

#define KEY_PRINTEND_BUTTON_AGAIN	0x0001
#define KEY_PRINTEND_BUTTON_BACK	0x0002

#define SCREEN_POWER_OFF			32
#define ADDR_POWEROFF_KEY			0x4200
#define ADDR_POWEROFF_TEXT_TITLE	0x4210
#define ADDR_POWEROFF_TEXT_CANCEL	0x4230
#define ADDR_POWEROFF_TEXT_LINE1	0x4250
#define ADDR_POWEROFF_TEXT_LINE2	0x4290
#define ADDR_POWEROFF_TEXT_TIME		0x42D0

#define KEY_POWEROFF_BUTTON_CANCEL	0x0001

#define SCREEN_HELP1				33
#define ADDR_HELP1_KEY				0x4300
#define ADDR_HELP1_TEXT_TITLE		0x4310
#define ADDR_HELP1_TEXT_RETURN		0x4330
#define ADDR_HELP1_TEXT_LINE		0x4350

#define KEY_HELP1_BUTTON_RETURN		0x0001

#define TEXTLEN_HELP1_TITLE			30
#define TEXTLEN_HELP1_ITEM			400
#define TEXTLEN_HELP1_BUTTON		20

#define SCREEN_HELP2				36
#define ADDR_HELP2_KEY				0x4600
#define ADDR_HELP2_TEXT_TITLE		0x4610
#define ADDR_HELP2_TEXT_BUTTON1		0x4630
#define ADDR_HELP2_TEXT_BUTTON2		0x4640
#define ADDR_HELP2_TEXT_LINE1		0x4650
#define ADDR_HELP2_TEXT_LINE2		0x4740

#define KEY_HELP2_BUTTON1			0x0001
#define KEY_HELP2_BUTTON2			0x0002

#define TEXTLEN_HELP2_TITLE			50
#define TEXTLEN_HELP2_ITEM			400
#define TEXTLEN_HELP2_BUTTON		32


#define SCREEN_QR					35
#define ADDR_QR_KEY					0x4500
#define ADDR_QR_TEXT_TILE			0x4510
#define ADDR_QR_TEXT_RETURN			0x4530
#define ADDR_QR_CODE				0x4550

#define KEY_QR_BUTTON_RETURN		0x0001

#define TEXTLEN_QR_TITLE			30
#define TEXTLEN_QR_ITEM				60
#define TEXTLEN_QR_BUTTON			20

#define SCREEN_TEST_MODE			38
#define ADDR_TESTMODE_KEY			0x4800
#define ADDR_TESTMODE_ENDSTOP_X		0x4810
#define ADDR_TESTMODE_ENDSTOP_Y		0x4820
#define ADDR_TESTMODE_ENDSTOP_Z		0x4830
#define ADDR_TESTMODE_HALL			0x4840
#define ADDR_TESTMODE_BREAK			0x4850

#define KEY_TESTMODE_X_RUN			0x0000
#define KEY_TESTMODE_X_BACK			0x0001
#define KEY_TESTMODE_Y_RUN			0x0002
#define KEY_TESTMODE_Y_BACK			0x0003
#define KEY_TESTMODE_Z_RUN			0x0004
#define KEY_TESTMODE_Z_BACK			0x0005
#define KEY_TESTMODE_A_RUN			0x0006
#define KEY_TESTMODE_A_BACK			0x0007
#define KEY_TESTMODE_4020_ON		0x0008
#define KEY_TESTMODE_4020_OFF		0x0009
#define KEY_TESTMODE_5015_ON		0x000A
#define KEY_TESTMODE_5015_OFF		0x000B
#define KEY_TESTMODE_POWEROFF		0x000C
#define KEY_TESTMODE_8015_ON		0x000D
#define KEY_TESTMODE_8015_OFF		0x000E
#define KEY_TESTMODE_BACK			0x000F

#define SCREEN_PICHELP				40
#define ADDR_PICHELP_KEY			0x5000
#define ADDR_PICHELP_ICON			0x5001
#define ADDR_PICHELP_TEXT_TITLE		0x5010
#define ADDR_PICHELP_TEXT_BUTTON1	0x5020
#define ADDR_PICHELP_TEXT_BUTTON2	0x5030
#define ADDR_PICHELP_TEXT_LINE1		0x5040

#define KEY_PICHELP_BUTTON1			0x0001
#define KEY_PICHELP_BUTTON2			0x0002

#define TEXTLEN_PICHELP_TITLE		30
#define TEXTLEN_PICHELP_ITEM		400
#define TEXTLEN_PICHELP_BUTTON		32

#define SCREEN_HELPMENU				42
#define ADDR_HELPMENU_KEY			0x5200
#define ADDR_HELPMENU_ICON1			0x5201
#define ADDR_HELPMENU_ICON2			0x5202
#define ADDR_HELPMENU_ICON3			0x5203
#define ADDR_HELPMENU_TEXT_TITLE	0x5210
#define ADDR_HELPMENU_TEXT_RETURN	0x5230
#define ADDR_HELPMENU_ITEM1			0x5250
#define ADDR_HELPMENU_ITEM2			0x5270
#define ADDR_HELPMENU_ITEM3			0x5290

#define KEY_HELPMENU_BUTTON_RETURN	0x0001
#define KEY_HELPMENU_BUTTON_ITEM1	0x0002
#define KEY_HELPMENU_BUTTON_ITEM2	0x0003
#define KEY_HELPMENU_BUTTON_ITEM3	0x0004

#define TEXTLEN_HELPMENU_TITLE		30
#define TEXTLEN_HELPMENU_ITEM		32
#define TEXTLEN_HELPMENU_BUTTON		20

#define SCREEN_LISTMENU				44
#define ADDR_LIST_KEY				0x5400
#define ADDR_LIST_TEXT_TITLE		0x5420
#define ADDR_LIST_BUTTON_TEXT_RETURN	0x5440
#define ADDR_LIST_BUTTON_TEXT_PRE	0x5460
#define ADDR_LIST_BUTTON_TEXT_NEXT	0x5480
#define ADDR_LIST_TEXT_LINE1		0x54A0
#define ADDR_LIST_TEXT_LINE2		0x54D0
#define ADDR_LIST_TEXT_LINE3		0x5500
#define ADDR_LIST_TEXT_LINE4		0x5530

#define KEY_LIST_BUTTON_RETURN		0x0001
#define KEY_LIST_BUTTON_PRE			0x0002
#define KEY_LIST_BUTTON_NEXT		0x0003
#define KEY_LIST_BUTTON_LINE1		0x0004
#define KEY_LIST_BUTTON_LINE2		0x0005
#define KEY_LIST_BUTTON_LINE3		0x0006
#define KEY_LIST_BUTTON_LINE4		0x0007

#define DGUS_START_BYTE_1			0x5A
#define DGUS_START_BYTE_2			0xA5

#define DGUS_CMD_WriteREG			0x80
#define DGUS_CMD_ReadREG			0x81
#define DGUS_CMD_WriteVAR			0x82
#define DGUS_CMD_ReadVAR			0x83

#define DGUS_SYS_Device_ID			0x00
#define DGUS_SYS_System_Reset		0x04
#define DGUS_SYS_Ver				0x0F
#define DGUS_SYS_PIC_Now			0x14
#define DGUS_SYS_GUI_Status			0x15
#define DGUS_SYS_TP_Status			0x16
#define DGUS_SYS_VCC_Now			0x30
#define DGUS_SYS_LED_Now			0x31
#define DGUS_SYS_System_Config		0x80
#define DGUS_SYS_LED_Config			0x82
#define DGUS_SYS_PIC_Set			0x84
#define DGUS_SYS_BMP_Download		0xA2
#define DGUS_SYS_JPEG_Download		0xA6
#define DGUS_SYS_Flash_RW_CMD		0xAA
#define DGUS_SYS_TouchCMDInterface	0xB0
#define DGUS_SYS_TouchScreenEmu		0xD4

#define SCREEN_LANGUAGE_SETTING			46

#define ADDR_LANG_KEY				0x5600
#define ADDR_LANG_ITEM1_TEXT		0x5670
#define ADDR_LANG_ITEM2_TEXT		0x5680
#define ADDR_LANG_ITEM3_TEXT		0x5690
#define ADDR_LANG_ITEM4_TEXT		0x56A0
#define ADDR_LANG_ITEM5_TEXT		0x56B0
#define ADDR_LANG_ITEM6_TEXT		0x56C0
#define ADDR_LANG_NEXT_TEXT			0x5660
#define ADDR_LANG_PRE_TEXT			0x5650
#define ADDR_LANG_BACK_TEXT			0x5640
#define ADDR_LANG_TITLE				0x5620

#define KEY_LANG_RETURN				0x0001
#define KEY_LANG_NEXT				0x0003	
#define KEY_LANG_PRE				0x0002
#define KEY_LANG_ITEM1				0x0004
#define KEY_LANG_ITEM2				0x0005
#define KEY_LANG_ITEM3				0x0006
#define KEY_LANG_ITEM4				0x0007
#define KEY_LANG_ITEM5				0x0008
#define KEY_LANG_ITEM6				0x0009

#define DGUS_LANG_FILENAME_ADDR		ADDR_LANG_ITEM1_TEXT
#define DGUS_LANG_FILENAME_INTERVAL	0x10

#define TEXTLEN_LANGUAGE_TITLE		30
#define TEXTLEN_LANGUAGE_ITEM		32
#define TEXTLEN_LANGUAGE_BUTTON		30

#define SCREEN_PREVIEW				48

#define ADDR_PREVIEW_KEY			0X5800
#define ADDR_PREVIEW_ICON1			0X5802
#define ADDR_PREVIEW_ICON2			0X5803
#define ADDR_PREVIEW_ICON3			0X5804
#define ADDR_PREVIEW_ICON4			0X5805
#define ADDR_PREVIEW_ICON5			0X5806
#define ADDR_PREVIEW_ICON6			0X5807
#define ADDR_PREVIEW_BUTTON1		0X5830
#define ADDR_PREVIEW_BUTTON2		0X5840
#define ADDR_PREVIEW_BUTTON3		0X5850
#define ADDR_PREVIEW_TITLE			0X5860
#define ADDR_PREVIEW_ITEM1			0X5870
#define ADDR_PREVIEW_ITEM2			0X5890
#define ADDR_PREVIEW_ITEM3			0X58A0
#define ADDR_PREVIEW_ITEM4			0X58B0
#define ADDR_PREVIEW_ITEM5			0X58C0
#define ADDR_PREVIEW_ITEM6			0X58D0

#define KEY_PREVIEW_BUTTON1			0X0001
#define KEY_PREVIEW_BUTTON2			0X0002
#define KEY_PREVIEW_BUTTON3			0X0003

#define TEXTLEN_PREVIEW_TITLE		30
#define TEXTLEN_PREVIEW_FILENAME	64
#define TEXTLEN_PREVIEW_DATA		10
#define TEXTLEN_PREVIEW_TEXT		16
#define TEXTLEN_PREVIEW_BUTTON		32

#define SCREEN_PRINTING				50

#define ADDR_PRINTING_KEY			0X6000
#define ADDR_PRINTING_HELP			0x6001
#define ADDR_PRINTING_ICON1			0X6002
#define ADDR_PRINTING_ICON2			0X6003
#define ADDR_PRINTING_ICON3			0X6004
#define ADDR_PRINTING_ICON4			0X6006
#define ADDR_PRINTING_ICON5			0X6007
#define ADDR_PRINTING_PERCENT		0x6008
#define ADDR_PRINTING_BUTTON1		0X6020
#define ADDR_PRINTING_BUTTON2		0X6030
#define ADDR_PRINTING_BUTTON3		0X6040
#define ADDR_PRINTING_TITLE			0X6050
#define ADDR_PRINTING_ITEM1			0X6070
#define ADDR_PRINTING_ITEM2			0X6090
#define ADDR_PRINTING_ITEM3			0X60A0
#define ADDR_PRINTING_ITEM4			0X60B0
#define ADDR_PRINTING_ITEM5			0X60C0
#define ADDR_PRINTING_ITEM6			0X60D0
#define ADDR_PRINTING_ITEM7			0X60E0

#define KEY_PRINTING_BUTTON1		0X0001
#define KEY_PRINTING_BUTTON2		0X0002
#define KEY_PRINTING_BUTTON3		0X0003
#define KEY_PRINTING_HELP			0X000F

#define TEXTLEN_PRINTING_TITLE		30
#define TEXTLEN_PRINTING_FILENAME	64
#define TEXTLEN_PRINTING_DATA		10
#define TEXTLEN_PRINTING_TEXT		16
#define TEXTLEN_PRINTING_BUTTON		32

#define SCREEN_OPTION_EIGHT			52

#define ADDR_OPTEIGHT_KEY			0x6200
#define ADDR_OPTEIGHT_ITEM1_TEXT	0x6220
#define ADDR_OPTEIGHT_ITEM2_TEXT	0x6230
#define ADDR_OPTEIGHT_ITEM3_TEXT	0x6240
#define ADDR_OPTEIGHT_ITEM4_TEXT	0x6250
#define ADDR_OPTEIGHT_ITEM5_TEXT	0x6260
#define ADDR_OPTEIGHT_ITEM6_TEXT	0x6270
#define ADDR_OPTEIGHT_ITEM7_TEXT	0x6280
#define ADDR_OPTEIGHT_ITEM8_TEXT	0x6290
#define ADDR_OPTEIGHT_TITLE			0x6210

#define KEY_OPTEIGHT_ITEM1			0x0000
#define KEY_OPTEIGHT_ITEM2			0x0001
#define KEY_OPTEIGHT_ITEM3			0x0002
#define KEY_OPTEIGHT_ITEM4			0x0003
#define KEY_OPTEIGHT_ITEM5			0x0004
#define KEY_OPTEIGHT_ITEM6			0x0005
#define KEY_OPTEIGHT_ITEM7			0x0006
#define KEY_OPTEIGHT_ITEM8			0x0007

#define TEXTLEN_OPTEIGHT_TITLE		30
#define TEXTLEN_OPTEIGHT_ITEM		30

#define SCREEN_LEVEL_DATA_TWO		54

#define ADDR_LDATAT_KEY				0x6400
#define ADDR_LDATAT_ITEM1_TEXT		0x6450
#define ADDR_LDATAT_ITEM2_TEXT		0x6460
#define ADDR_LDATAT_ITEM3_TEXT		0x6470
#define ADDR_LDATAT_ITEM4_TEXT		0x6480
#define ADDR_LDATAT_ITEM5_TEXT		0x6490
#define ADDR_LDATAT_ITEM6_TEXT		0x64A0
#define ADDR_LDATAT_ITEM7_TEXT		0x64B0
#define ADDR_LDATAT_ITEM8_TEXT		0x64C0
#define ADDR_LDATAT_ITEM9_TEXT		0x64D0
#define ADDR_LDATAT_TEXT		    0x6500
#define ADDR_LDATAT_BUTTON1_TEXT	0x6430
#define ADDR_LDATAT_BUTTON2_TEXT	0x6440
#define ADDR_LDATAT_TITLE			0x6410

#define KEY_LDATAT_BUTTON1			0x0001
#define KEY_LDATAT_BUTTON2			0x0002

#define TEXTLEN_LDATAT_TITLE		50
#define TEXTLEN_LDATAT_BUTTON		32
#define TEXTLEN_LDATAT_ITEM		    10
#define TEXTLEN_LDATAT_TEXT		    150

#define SCREEN_LEVEL_DATA_ONE		56

#define ADDR_LDATAO_KEY				0x6600
#define ADDR_LDATAO_ITEM1_TEXT		0x6650
#define ADDR_LDATAO_ITEM2_TEXT		0x6660
#define ADDR_LDATAO_ITEM3_TEXT		0x6670
#define ADDR_LDATAO_ITEM4_TEXT		0x6680
#define ADDR_LDATAO_ITEM5_TEXT		0x6690
#define ADDR_LDATAO_ITEM6_TEXT		0x66A0
#define ADDR_LDATAO_ITEM7_TEXT		0x66B0
#define ADDR_LDATAO_ITEM8_TEXT		0x66C0
#define ADDR_LDATAO_ITEM9_TEXT		0x66D0
#define ADDR_LDATAO_TEXT		    0x6700
#define ADDR_LDATAO_BUTTON1_TEXT	0x6630
#define ADDR_LDATAO_TITLE			0x6610

#define KEY_LDATAO_BUTTON1			0x0001

#define TEXTLEN_LDATAO_TITLE		50
#define TEXTLEN_LDATAO_BUTTON		32
#define TEXTLEN_LDATAO_ITEM		    10
#define TEXTLEN_LDATAO_TEXT		    150

#define SCREEN_NOZZLE_OFFSET		58

#define ADDR_NOFFSET_KEY			0x6800
#define ADDR_NOFFSET_BUTTON1_ICON  	0x6801
#define ADDR_NOFFSET_BUTTON2_ICON  	0x6802
#define ADDR_NOFFSET_BUTTON3_ICON  	0x6803
#define ADDR_NOFFSET_BUTTON4_ICON  	0x6804
#define ADDR_NOFFSET_BUTTON5_ICON  	0x6805
#define ADDR_NOFFSET_BUTTON6_ICON  	0x6806
#define ADDR_NOFFSET_BUTTON7_ICON  	0x6807
#define ADDR_NOFFSET_BUTTON8_ICON  	0x6808
#define ADDR_NOFFSET_BUTTON9_ICON  	0x6809
#define ADDR_NOFFSET_BUTTON10_ICON 	0x680A
#define ADDR_NOFFSET_TITLE			0x6810
#define ADDR_NOFFSET_RETURN_TEXT	0x6830
#define ADDR_NOFFSET_NEXT_TEXT  	0x6840
#define ADDR_NOFFSET_BUTTON1_TEXT  	0x6850
#define ADDR_NOFFSET_BUTTON2_TEXT  	0x6860
#define ADDR_NOFFSET_BUTTON3_TEXT  	0x6870
#define ADDR_NOFFSET_BUTTON4_TEXT  	0x6880
#define ADDR_NOFFSET_BUTTON5_TEXT  	0x6890
#define ADDR_NOFFSET_BUTTON6_TEXT  	0x68A0
#define ADDR_NOFFSET_BUTTON7_TEXT  	0x68B0
#define ADDR_NOFFSET_BUTTON8_TEXT  	0x68C0
#define ADDR_NOFFSET_BUTTON9_TEXT  	0x68D0
#define ADDR_NOFFSET_BUTTON10_TEXT 	0x68E0
#define ADDR_NOFFSET_TEXT		    0x6900

#define KEY_NOFFSET_RETURN			0x0001
#define KEY_NOFFSET_NEXT			0x0002
#define KEY_NOFFSET_BUTTON1			0x0003
#define KEY_NOFFSET_BUTTON2			0x0004
#define KEY_NOFFSET_BUTTON3			0x0005
#define KEY_NOFFSET_BUTTON4			0x0006
#define KEY_NOFFSET_BUTTON5			0x0007
#define KEY_NOFFSET_BUTTON6			0x0008
#define KEY_NOFFSET_BUTTON7			0x0009
#define KEY_NOFFSET_BUTTON8			0x000A
#define KEY_NOFFSET_BUTTON9			0x000B
#define KEY_NOFFSET_BUTTON10		0x000C

#define TEXTLEN_NOFFSET_TITLE		50
#define TEXTLEN_NOFFSET_BUTTON		32
#define TEXTLEN_NOFFSET_ITEM		10
#define TEXTLEN_NOFFSET_TEXT		200

#define DGUS_JPG_X					10
#define DGUS_JPG_Y					43
#define DGUS_JPG_PAGE_SIZE			40
#define DGUS_JPG_CACHE_ADDR			0x8000


enum FILAMENT_OPERATION_ENUM
{
	FILAMENT_OPERATION_LOAD,
	FILAMENT_OPERATION_UNLOAD
};

#endif
