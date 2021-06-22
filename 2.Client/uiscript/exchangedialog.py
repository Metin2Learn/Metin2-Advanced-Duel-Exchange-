import uiScriptLocale

ROOT = "d:/ymir work/ui/game/"

WIDTH = 282
HEIGHT = 167

import app
if app.__BL_ADVANCED_DUEL__:
    ADVANCED_DUEL_SIZE = 30
else:
	ADVANCED_DUEL_SIZE = 0

WIDTH += ADVANCED_DUEL_SIZE

window = {
	"name" : "ExchangeDialog",

	"x" : 0,
	"y" : 0,

	"style" : ("movable", "float",),

	"width" : WIDTH,
	"height" : HEIGHT,

	"children" :
	(
		{
			"name" : "board",
			"type" : "board",
			"style" : ("attach",),

			"x" : 0,
			"y" : 0,

			"width" : WIDTH,
			"height" : HEIGHT,

			"children" :
			(
				## Title
				{
					"name" : "TitleBar",
					"type" : "titlebar",
					"style" : ("attach",),

					"x" : 8,
					"y" : 8,
 
					"width" : 266 + ADVANCED_DUEL_SIZE,
					"color" : "gray",

					"children" :
					(
						{ "name":"TitleName", "type":"text", "x":133, "y":3, "text":uiScriptLocale.EXCHANGE_TITLE, "text_horizontal_align":"center" },
					),
				},

				## MiddleBar
				{
					"name" : "Middle_Bar",
					"type" : "image",

					"x" : 139 + ADVANCED_DUEL_SIZE / 2,
					"y" : 31,

					"image" : ROOT + "windows/middlebar.sub",
				},
				## Owner
				{
					"name" : "Owner",
					"type" : "window",

					"x" : 144 + ADVANCED_DUEL_SIZE / 2,
					"y" : 33,

					"width" : 130,
					"height" : 130,

					"children" :
					(
						{
							"name" : "Owner_Slot",
							"type" : "grid_table",

							"start_index" : 0,

							"x" : 0,
							"y" : 0,

							"x_count" : 4,
							"y_count" : 3,
							"x_step" : 32,
							"y_step" : 32,
							"x_blank" : 0,
							"y_blank" : 0,

							"image" : "d:/ymir work/ui/public/slot_base.sub",
						},
						{
							"name" : "Owner_Money",
							"type" : "button",

							"x" : 0,
							"y" : 102,

							#"image" : "d:/ymir work/ui/public/parameter_slot_02.sub",

							"default_image" : "d:/ymir work/ui/public/parameter_slot_02.sub",
							"over_image" : "d:/ymir work/ui/public/parameter_slot_02.sub",
							"down_image" : "d:/ymir work/ui/public/parameter_slot_02.sub",

							"children" :
							(
								{
									"name" : "Owner_Money_Value",
									"type" : "text",

									"x" : 59,
									"y" : 2,

									"text" : "1234567",

									"text_horizontal_align" : "right",
								},
							),
						},
						{
							"name" : "Owner_Accept_Light",
							"type" : "button",

							"x" : 62,
							"y" : 101,

							"default_image" : "d:/ymir work/ui/game/windows/accept_button_off.sub",
							"over_image" : "d:/ymir work/ui/game/windows/accept_button_off.sub",
							"down_image" : "d:/ymir work/ui/game/windows/accept_button_on.sub",
						},
						{
							"name" : "Owner_Accept_Button",
							"type" : "toggle_button",

							"x" : 85,
							"y" : 101,

							"text" : uiScriptLocale.EXCHANGE_ACCEPT,

							"default_image" : "d:/ymir work/ui/public/small_button_01.sub",
							"over_image" : "d:/ymir work/ui/public/small_button_02.sub",
							"down_image" : "d:/ymir work/ui/public/small_button_03.sub",
						},
					),
				},

				## Target
				{
					"name" : "Target",
					"type" : "window",

					"x" : 10 + ADVANCED_DUEL_SIZE / 2,
					"y" : 33,

					"width" : 130,
					"height" : 130,

					"children" :
					(
						{
							"name" : "Target_Slot",
							"type" : "grid_table",

							"start_index" : 0,

							"x" : 0,
							"y" : 0,

							"x_count" : 4,
							"y_count" : 3,
							"x_step" : 32,
							"y_step" : 32,
							"x_blank" : 0,
							"y_blank" : 0,

							"image" : "d:/ymir work/ui/public/slot_base.sub",
						},
						{
							"name" : "Target_Money",
							"type" : "image",

							"x" : 0,
							"y" : 102,

							"image" : "d:/ymir work/ui/public/parameter_slot_02.sub",

							"children" :
							(
								{
									"name" : "Target_Money_Value",
									"type" : "text",

									"x" : 59,
									"y" : 2,

									"text" : "1234567",

									"text_horizontal_align" : "right",
								},
							),
						},
						{
							"name" : "Target_Accept_Light",
							"type" : "button",

							"x" : 62,
							"y" : 101,

							"default_image" : "d:/ymir work/ui/game/windows/accept_button_off.sub",
							"over_image" : "d:/ymir work/ui/game/windows/accept_button_off.sub",
							"down_image" : "d:/ymir work/ui/game/windows/accept_button_on.sub",
						},
					),
				},
			),
		},
	),
}

if app.__BL_ADVANCED_DUEL__:
	window["children"][0]["children"] += (
		{
			"name" : "self_advanced_duel",
			"type" : "toggle_button",

			"x" : 288,
			"y" : 40,

			"tooltip_text" : "Advanced Duel",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "self_potion_block",
			"type" : "toggle_button",

			"x" : 288,
			"y" : 40 + 30 * 1,

			"tooltip_text" : "Block Potion",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "self_equip_block",
			"type" : "toggle_button",

			"x" : 288,
			"y" : 40 + 30 * 2,

			"tooltip_text" : "Block Equip Change",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "self_mount_block",
			"type" : "toggle_button",

			"x" : 288,
			"y" : 40 + 30 * 3,

			"tooltip_text" : "Block Mount",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "target_advanced_duel",
			"type" : "toggle_button",

			"x" : 8,
			"y" : 40,

			"tooltip_text" : "Advanced Duel",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "target_potion_block",
			"type" : "toggle_button",

			"x" : 8,
			"y" : 40 + 30 * 1,

			"tooltip_text" : "Block Potion",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "target_equip_block",
			"type" : "toggle_button",

			"x" : 8,
			"y" : 40 + 30 * 2,

			"tooltip_text" : "Block Equip Change",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "target_mount_block",
			"type" : "toggle_button",

			"x" : 8,
			"y" : 40 + 30 * 3,

			"tooltip_text" : "Block Mount",

			"default_image" : "d:/ymir work/ui/public/check_empty.tga",
			"over_image" : "d:/ymir work/ui/public/check_box.tga",
			"down_image" : "d:/ymir work/ui/public/check_box.tga",
		},
		{
			"name" : "AdvancedDuelToolTIpButton",
			"type" : "button",

			"x" : 265,
			"y" : 9,

			"default_image" : "d:/ymir work/ui/pattern/q_mark_01.tga",
			"over_image" : "d:/ymir work/ui/pattern/q_mark_02.tga",
			"down_image" : "d:/ymir work/ui/pattern/q_mark_01.tga",
		},
	)