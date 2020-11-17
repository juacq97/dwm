
/*                          __ _         _     
*           ___ ___  _ __  / _(_) __ _  | |__  
*          / __/ _ \| '_ \| |_| |/ _` | | '_ \ 
*         | (_| (_) | | | |  _| | (_| |_| | | |
*          \___\___/|_| |_|_| |_|\__, (_)_| |_|
*                                |___/         
*	dwm's configuration file (yes, config file)
*/

/* appearance */
static const unsigned int borderpx  = 2;       
static const unsigned int snap      = 6;      
static const unsigned int gappih    = 8;      
static const unsigned int gappiv    = 8;      
static const unsigned int gappoh    = 6;      
static const unsigned int gappov    = 6;      
static       int smartgaps          = 0;  /* 1 means no gap with one window */
static const int user_bh            = 25; /* 0 means height equal to font size */
static const int showbar            = 1;  /* 0 means no bar */
static int floatposgrid_x           = 5;  
static int floatposgrid_y           = 5;  
static const int topbar             = 1;  /* 0 means bottom bar */
static const int attachmode         = 2;  /* 0 master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const char *fonts[]          = {"Futura Bk BT:Book:size=10", "Material Design Icons:Regular:pixelsize=16:antialias=true"};

#include "colors/horizon.h" //Colorscheme
static const char spotify[]= "#1FC167"; //Spotify green

/* Here is the color array. Check the 'color.h' file to see the names' */
static const char *colors[][3]      = {
	/*               fg         bg         border           code */
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

/* Here's the alpha array, needed to have nice transparency */
static const unsigned int baralpha = 0xd0; //The alpha channel
static const unsigned int borderalpha = OPAQUE; // The border alpha channel
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
  { "kruler",        NULL,       NULL,       0,            1,         NULL,       -1 },
  { "zoom",          NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Connman-gtk",   NULL,       NULL,       0,            1,         NULL,       -1 },
  { "Alacritty", "calendar.txt", NULL,       0,            1,         NULL,       -1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area */
static const int nmaster     = 1;    /* clients in master */
static const int resizehints = 0;    /* 1 means respect size hints */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

/* Here's the layouts. The count starts with zero */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰙀",           tile }, 
	{ "󱒅",           centeredmaster },
	{ "󰋁",           gaplessgrid },
	{ "[M]",         monocle },
	{ "[D]",         deck },
	{ NULL,          NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,		KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggletag,      {.ui = 1 << TAG} },

/* keybindings! Here's only the dwm-related keybindings. To launch apps I use sxhkd */
#include "movestack.c"
#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */

	/*About windows */
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} }, 
        { MODKEY,                       XK_j,      focusstack,     {.i = +1 } }, 
        { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
        { MODKEY|ControlMask,           XK_j,      inplacerotate,  {.i = +1} }, 
        { MODKEY|ControlMask,           XK_k,      inplacerotate,  {.i = -1} }, 
        { MODKEY|ShiftMask,             XK_g,      zoom,           {0} }, //send window to master
        { MODKEY,                       XK_g,      switchcol,      {0} }, //swap focus between master and stack
        { MODKEY,                       XK_h,      setmfact,       {.f = -0.05} }, // Shrink master
        { MODKEY,                       XK_l,      setmfact,       {.f = +0.05} }, //Grow master
        { MODKEY|ControlMask,           XK_comma,  incnmaster,     {.i = +1 } }, 
        { MODKEY|ControlMask,           XK_period, incnmaster,     {.i = -1 } }, 
        { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } }, 
        { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } }, 

	/* About tags (desktops) */
	{ MODKEY,                       XK_Tab,    view,           {0} }, // Prev tag
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, // View all tags
	{ MODKEY,                       XK_0,      setlayout,      {.v = &layouts[2]} }, // Grid for all tags
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, // Window on all tags
	{ MODKEY|ShiftMask,             XK_o,      winview,        {0} }, //follow window on viewall
	{ MODKEY|ShiftMask,             XK_o,      setlayout,      {.v = &layouts[0]} }, /*tiled*/
	{ MODKEY|ControlMask,           XK_l,      shiftview,      { .i = +1 } }, // Next tag
	{ MODKEY|ControlMask,           XK_h,      shiftview,      { .i = -1 } }, // prev tag
	TAGKEYS(                        XK_1,                      0) /*Activate tag 1*/ 
	TAGKEYS(                        XK_2,                      1) /*Activate tag 2*/
	TAGKEYS(                        XK_3,                      2) /*Activate tag 3*/
	TAGKEYS(                        XK_4,                      3) /*Activate tag 4*/
	TAGKEYS(                        XK_5,                      4) /*Activate tag 5*/
	TAGKEYS(                        XK_6,                      5) /*Activate tag 6*/
	TAGKEYS(                        XK_7,                      6) /*Activate tag 7*/
	TAGKEYS(                        XK_8,                      7) /*Activate tag 8*/
	TAGKEYS(                        XK_9,                      8) /*Activate tag 9*/

	/*About layouts*/
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, /*tiled*/
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[3]} }, /*monocle*/
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[4]} }, /*Deck*/
	{ MODKEY,                       XK_s,      togglefloating, {0} }, 
	{ MODKEY,			XK_F11,    togglefullscreen,  {0} }, 
	{ MODKEY|ShiftMask,	     	XK_F11,    togglefakefullscreen,  {0} }, // Fullscreen on the tile
	{ MODKEY|Mod1Mask,              XK_comma,  cyclelayout,    {.i = -1 } }, 
	{ MODKEY|Mod1Mask,              XK_period, cyclelayout,    {.i = +1 } }, 

	/*About monitors*/
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } }, 
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } }, 
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } }, 
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } }, 
       //{ MODKEY|Mod1Mask|ControlMask,  XK_comma,  tagswapmon,     {.i = +1 } }, // Intercambiar con monitor izquierdo
       //{ MODKEY|Mod1Mask|ControlMask,  XK_period, tagswapmon,     {.i = -1 } }, // intercambiar con monitor derecho

	/* dwm especifico*/
	{ MODKEY,                       XK_b,      togglebar,      {0} }, 
        { MODKEY|Mod1Mask,              XK_l,      setcfact,       {.f = +0.25} }, // Grow stack 
        { MODKEY|Mod1Mask,              XK_h,      setcfact,       {.f = -0.25} }, // Shrink stack
        { MODKEY|Mod1Mask,              XK_o,      setcfact,       {.f =  0.00} }, // Reset stack

	/* About gaps */
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

