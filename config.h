/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 6;       /* snap pixel */
static const unsigned int gappih    = 8;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 8;       /* vert inner gap between windows */
static const unsigned int gappoh    = 6;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 6;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int user_bh            = 25;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int showbar            = 1;        /* 0 means no bar */
static int floatposgrid_x           = 5;        /* float grid columns */
static int floatposgrid_y           = 5;        /* float grid rows */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int attachmode         = 2;        /* 0 master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const char *fonts[]          = {"Futura Bk BT:Book:size=10", "Material Design Icons:Regular:pixelsize=16:antialias=true"};
static const char dmenufont[]       = "monospace:size=10";

#include "colors/horizon.h"
static const char spotify[]= "#1FC167";


static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]     = { fore,      back,      back   }, // \x0b
	[SchemeSel]      = { fore,      back,      col4   }, // \x0c
	[SchemeStatus]   = { fore,      back,      border }, // \x0d
	[SchemeTagsSel]  = { back,      col6,      border }, // \x0e
        [SchemeTagsNorm] = { fore,      back,      border }, // \x0f
        [SchemeInfoSel]  = { fore,      back,      border }, // \x10
        [SchemeInfoNorm] = { fore,      back,      border }, // \x11
	[SchemeCol1]     = { col1,      back,      col0   }, // \x12 
	[SchemeCol2]     = { col2,      back,      col0   }, // \x13
	[SchemeCol3]     = { col3,      back,      col0   }, // \x14 
	[SchemeCol4]     = { col4,      back,      col0   }, // \x15
	[SchemeCol5]     = { col5,      back,      col0   }, // \x16 
	[SchemeCol6]     = { col6,      back,      col0   }, // \x17
	[SchemeCol7]     = { col7,      back,      col0   }, // \x18
	[SchemeCol8]     = { col8,      back,      col0   }, // \x19
	[SchemeCol9]     = { col9,      back,      col0   }, // \x1a
	[SchemeCol10]    = { col10,     back,      col0   }, // \x1b
	[SchemeCol11]    = { col11,     back,      col0   }, // \x1c 
	[SchemeCol12]    = { spotify,   back,      col0   }, // \x1d
};

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
    [SchemeNorm]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeSel]      = { OPAQUE,    baralpha,   borderalpha },
    [SchemeStatus]   = { OPAQUE,    baralpha,   borderalpha },
    [SchemeTagsSel]  = { OPAQUE,    baralpha,   borderalpha },
    [SchemeTagsNorm] = { OPAQUE,    baralpha,   borderalpha },
    [SchemeInfoSel]  = { OPAQUE,    baralpha,   borderalpha },
    [SchemeInfoNorm] = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol1]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol2]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol3]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol4]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol5]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol6]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol7]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol8]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol9]     = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol10]    = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol11]    = { OPAQUE,    baralpha,   borderalpha },
    [SchemeCol12]    = { OPAQUE,    baralpha,   borderalpha },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask  isfloating  floatpos monitor */
  { "Gimp",          NULL,       NULL,       0,            1,         NULL,       -1 },
  { "mpv",           NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Lxappareance",  NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Pavucontrol",   NULL,       NULL,       0,            1,         NULL,       -1 },
  { "qt5ct",         NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Gucharmap",     NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Sxiv",          NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Toolkit",       NULL,       NULL,       0,            1,         NULL,       -1 },
  { "kruler",        NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Emacs",         NULL,       "agenda",   0,            1,         NULL,       -1 },
  { "zoom",          NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Connman-gtk",   NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Alacritty", "calendar.txt", NULL,       0,            1,         NULL,       -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */



#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰙀",      tile },    /* first entry is default */
	{ "󱒅",      centeredmaster },
	{ "󰋁",      gaplessgrid },
	{ "[M]",      monocle },
	{ "[D]",      deck },
	{ "><>",     NULL },
	{ NULL, NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,		KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggletag,      {.ui = 1 << TAG} },
 


#include "movestack.c"
#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
		     /* Movimiento de ventanas */

		     { MODKEY|ShiftMask,             XK_q,      killclient,     {0} }, /*Matar ventana*/
		     { MODKEY,                       XK_j,      focusstack,     {.i = +1 } }, /*Enfocar siguiente ventana*/
		     { MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, /*Enfocar anterior ventana*/
		     { MODKEY|ControlMask,           XK_j,      inplacerotate,  {.i = +1} }, /*Enfocar siguiente ventana sin cambiar con master (usar con deck)*/
		     { MODKEY|ControlMask,           XK_k,      inplacerotate,  {.i = -1} }, /*Enfocar anterior ventana sin cambiar con master (usar con deck)*/
		     { MODKEY|ShiftMask,             XK_g,      zoom,           {0} }, /*mandar ventana a master*/
		     { MODKEY,                       XK_g,      switchcol,    {0} }, /*Cambiar foco entre stack y master*/
		     { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} }, /*Hacer más pequeño master*/
		     { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} }, /*Hacer más grande master*/
		     { MODKEY|ControlMask,           XK_comma,  incnmaster,     {.i = +1 } }, /*Incrementar master*/
		     { MODKEY|ControlMask,           XK_period, incnmaster,     {.i = -1 } }, /*Disminuir master*/
		     { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } }, /*Mover ventana hacia abajo*/
		     { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } }, /*Mover ventana hacia arriba*/

		     /* Tags*/
		     { MODKEY,                       XK_Tab,    view,           {0} }, /*tag anterior*/
		     { MODKEY,                       XK_0,      view,           {.ui = ~0 } }, /*ver todos los tags a la vez*/
		     { MODKEY,                       XK_0,      setlayout,      {.v = &layouts[2]} }, /*Grid*/
		     { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, /*ventana enfocada en todos los tags*/
		     { MODKEY|ShiftMask,             XK_o,      winview,        {0} }, // Ir al tag de la ventana enfocada
		     { MODKEY|ShiftMask,             XK_o,      setlayout,      {.v = &layouts[0]} }, /*tiled*/
		     { MODKEY|ControlMask,           XK_l,      shiftview,      { .i = +1 } }, /*Ver siguiente tag*/
		     { MODKEY|ControlMask,           XK_h,      shiftview,      { .i = -1 } }, /*Ver tag anterior*/
		     TAGKEYS(                        XK_1,                      0) /*Enfocar tag 1*/ 
		     TAGKEYS(                        XK_2,                      1) /*Enfocar tag 2*/
		     TAGKEYS(                        XK_3,                      2) /*Enfocar tag 3*/
		     TAGKEYS(                        XK_4,                      3) /*Enfocar tag 4*/
		     TAGKEYS(                        XK_5,                      4) /*Enfocar tag 5*/
		     TAGKEYS(                        XK_6,                      5) /*Enfocar tag 6*/
		     TAGKEYS(                        XK_7,                      6) /*Enfocar tag 7*/
		     TAGKEYS(                        XK_8,                      7) /*Enfocar tag 8*/
		     TAGKEYS(                        XK_9,                      8) /*Enfocar tag 9*/

		     /*Layouts*/
		     { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, /*tiled*/
		     { MODKEY|Mod1Mask,              XK_c,      setlayout,      {.v = &layouts[1]} }, /*center*/
		     { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} }, /*monocle*/
		     { MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[4]} }, /*Deck*/
		     { MODKEY,                       XK_s,      togglefloating, {0} }, /*float*/
		     { MODKEY,			     XK_F11,    togglefullscreen,  {0} }, /*Fullscreen*/
		     { MODKEY|ShiftMask,	     XK_F11,    togglefakefullscreen,  {0} }, /*Fullscreen*/
		     { MODKEY|Mod1Mask,              XK_comma,  cyclelayout,    {.i = -1 } }, /*Ciclar layouts*/
		     { MODKEY|Mod1Mask,              XK_period, cyclelayout,    {.i = +1 } }, /*Ciclar layouts*/

		     /*Monitores*/
		     { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } }, /*Enfocar siguiente monitor*/
		     { MODKEY,                       XK_period, focusmon,       {.i = +1 } }, /*Enfocar siguiente monitor*/
		     { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } }, /*Mandar ventana a monitor anterior*/
		     { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } }, /*Mandar ventana a monitor siguiente*/
       // 	     { MODKEY|Mod1Mask|ControlMask,  XK_comma,  tagswapmon,     {.i = +1 } }, // Intercambiar con monitor izquierdo
       // 	     { MODKEY|Mod1Mask|ControlMask,  XK_period, tagswapmon,     {.i = -1 } }, // intercambiar con monitor derecho

		     /* dwm especifico*/
		     { MODKEY,                       XK_b,      togglebar,      {0} }, /*Activar o desactivar panel*/
                     { MODKEY|Mod1Mask,              XK_l,      setcfact,       {.f = +0.25} },
                     { MODKEY|Mod1Mask,              XK_h,      setcfact,       {.f = -0.25} },
                     { MODKEY|Mod1Mask,              XK_o,      setcfact,       {.f =  0.00} },

	{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

	{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },




};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,      {.i = +1 } },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[5]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button3,      dragcfact,      {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkClientWin,		MODKEY,		Button1,	winview,	{0} },
};

