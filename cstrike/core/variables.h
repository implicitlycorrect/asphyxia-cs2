#pragma once

#include "config.h"

#pragma region variables_combo_entries
using VisualOverlayBox_t = int;

enum EVisualOverlayBox : VisualOverlayBox_t
{
	VISUAL_OVERLAY_BOX_NONE = 0,
	VISUAL_OVERLAY_BOX_FULL,
	VISUAL_OVERLAY_BOX_CORNERS,
	VISUAL_OVERLAY_BOX_MAX
};


using MiscDpiScale_t = int;

enum EMiscDpiScale : MiscDpiScale_t
{
	MISC_DPISCALE_DEFAULT = 0,
	MISC_DPISCALE_125,
	MISC_DPISCALE_150,
	MISC_DPISCALE_175,
	MISC_DPISCALE_200,
	MISC_DPISCALE_MAX
};

#pragma endregion

#pragma region variables_multicombo_entries
using MenuAddition_t = unsigned int;
enum EMenuAddition : MenuAddition_t
{
	MENU_ADDITION_NONE = 0U,
	MENU_ADDITION_DIM_BACKGROUND = 1 << 0,
	MENU_ADDITION_BACKGROUND_PARTICLE = 1 << 1,
	MENU_ADDITION_GLOW = 1 << 2,
	MENU_ADDITION_ALL = MENU_ADDITION_DIM_BACKGROUND | MENU_ADDITION_BACKGROUND_PARTICLE | MENU_ADDITION_GLOW
};
#pragma endregion

struct Variables_t
{
#pragma region variables_visuals
	C_ADD_VARIABLE(bool, bVisualOverlay, false);

	C_ADD_VARIABLE(FrameOverlayVar_t, overlayBox, FrameOverlayVar_t(false));
	C_ADD_VARIABLE(TextOverlayVar_t, overlayName, TextOverlayVar_t(false));
#pragma endregion

#pragma region variables_misc
	C_ADD_VARIABLE(bool, bAntiUntrusted, true);
	C_ADD_VARIABLE(bool, bWatermark, true);

	C_ADD_VARIABLE(bool, bAutoBHop, false);
	C_ADD_VARIABLE(int, nAutoBHopChance, 100);
#pragma endregion

#pragma region variables_menu
	C_ADD_VARIABLE(unsigned int, nMenuKey, VK_INSERT);
	C_ADD_VARIABLE(unsigned int, nPanicKey, VK_END);
	C_ADD_VARIABLE(int, nDpiScale, 0);

	/*
	 * color navigation:
	 * [definition N][purpose]
	 * 1. primitive:
	 * - primtv 0 (text)
	 * - primtv 1 (background)
	 * - primtv 2 (disabled)
	 * - primtv 3 (control bg)
	 * - primtv 4 (border)
	 * - primtv 5 (hover)
	 *
	 * 2. accents:
	 * - accent 0 (main)
	 * - accent 1 (dark)
	 * - accent 2 (darker)
	 */
	C_ADD_VARIABLE(unsigned int, bMenuAdditional, MENU_ADDITION_ALL);
	C_ADD_VARIABLE(float, flAnimationSpeed, 1.f);


	C_ADD_VARIABLE(ColorPickerVar_t, colPrimtv0, ColorPickerVar_t(255, 255, 255)); // (text)
	C_ADD_VARIABLE(ColorPickerVar_t, colPrimtv1, ColorPickerVar_t(50, 55, 70)); // (background)
	C_ADD_VARIABLE(ColorPickerVar_t, colPrimtv2, ColorPickerVar_t(190, 190, 190)); // (disabled)
	C_ADD_VARIABLE(ColorPickerVar_t, colPrimtv3, ColorPickerVar_t(20, 20, 30)); // (control bg)
	C_ADD_VARIABLE(ColorPickerVar_t, colPrimtv4, ColorPickerVar_t(0, 0, 0)); // (border)

	C_ADD_VARIABLE(ColorPickerVar_t, colAccent0, ColorPickerVar_t(85, 90, 160)); // (main)
	C_ADD_VARIABLE(ColorPickerVar_t, colAccent1, ColorPickerVar_t(100, 105, 175)); // (dark)
	C_ADD_VARIABLE(ColorPickerVar_t, colAccent2, ColorPickerVar_t(115, 120, 190)); // (darker)
#pragma endregion
};

inline Variables_t Vars = {};