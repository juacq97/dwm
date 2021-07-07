static const unsigned int borderpx  = 3;       
static const unsigned int snap      = 6;      
static const unsigned int gappih    = 7;      
static const unsigned int gappiv    = 7;      
static const unsigned int gappoh    = 6;      
static const unsigned int gappov    = 6;      
static const float mfact            = 0.5; 
static const int nmaster            = 1; 
static const int nstack             = 0;
static const int resizehints        = 0; 
static const int user_bh            = 25; 
static const int user_tp            = 1;  
static const int showbar            = 1;  
static const int topbar             = 1;
static const int attachmode         = 1; 
static int smartgaps                = 0;  
static int floatposgrid_x           = 5;  
static int floatposgrid_y           = 5;  
static const char *fonts[]          = {
  "Futura Bk BT:Book:size=10",
  "Material Design Icons:Regular:pixelsize=14:antialias=true"
};

static char back[]   = "#1C1E27";
static char fore[]   = "#CACACC";
static char border[] = "#CACACC";
static char col0[]   = "#6C6F93";
static char col1[]   = "#E4436F";
static char col2[]   = "#24E39D";
static char col3[]   = "#EDA685";
static char col4[]   = "#00A5AF";
static char col5[]   = "#B367CF";
static char col6[]   = "#00A5AF";
static char col7[]   = "#CACACC";
static char col8[]   = "#6C6F93";
static char col9[]   = "#E4436F";
static char col10[]  = "#24E39D";
static char col11[]  = "#EDA685";
static char col12[]  = "#00A5AF";
static char col13[]  = "#B367CF";
static char col14[]  = "#00A5AF";
static char col15[]  = "#CACACC";
static char spotify[]= "#1FC167"; //Spotify green

static char *colors[][3] = {
  /*  Name              fg      bg    border       code */
  [SchemeNorm]     = { fore,    back, back   }, // \x0b
  [SchemeSel]      = { fore,    back, border }, // \x0c
  [SchemeStatus]   = { fore,    back, border }, // \x0d
  [SchemeTagsSel]  = { border,  back, border }, // \x0e
  [SchemeTagsNorm] = { fore,    back, border }, // \x0f
  [SchemeInfoSel]  = { fore,    back, border }, // \x10
  [SchemeInfoNorm] = { fore,    back, border }, // \x11
  [SchemeCol1]     = { col1,    back, col0   }, // \x12 
  [SchemeCol2]     = { col2,    back, col0   }, // \x13
  [SchemeCol3]     = { col3,    back, col0   }, // \x14 
  [SchemeCol4]     = { col4,    back, col0   }, // \x15
  [SchemeCol5]     = { col5,    back, col0   }, // \x16 
  [SchemeCol6]     = { col6,    back, col0   }, // \x17
  [SchemeCol7]     = { col7,    back, col0   }, // \x18
  [SchemeCol8]     = { col8,    back, col0   }, // \x19
  [SchemeCol9]     = { col9,    back, col0   }, // \x1a
  [SchemeCol10]    = { col10,   back, col0   }, // \x1b
  [SchemeCol11]    = { col11,   back, col0   }, // \x1c 
  [SchemeCol12]    = { spotify, back, col0   }, // \x1d
};

ResourcePref resources[] = {
  { "back",        STRING,  &back },
  { "fore",        STRING,  &fore },
  { "cursorColor", STRING,  &border },
  { "col0",	 STRING,  &col0 },
  { "col1",	 STRING,  &col1 },
  { "col2",	 STRING,  &col2 },
  { "col3",	 STRING,  &col3 },
  { "col4",	 STRING,  &col4 },
  { "col5",	 STRING,  &col5 },
  { "col6",	 STRING,  &col6 },
  { "col7",	 STRING,  &col7 },
  { "col8",	 STRING,  &col8 },
  { "col9",	 STRING,  &col9 },
  { "col10",	 STRING,  &col10 },
  { "col11",	 STRING,  &col11 },
  { "col12",	 STRING,  &col12 },
  { "col13",	 STRING,  &col13 },
  { "col14",	 STRING,  &col14 },
  { "col15",	 STRING,  &col15 },
};

static const unsigned int baralpha = 255; //The alpha channel
static const unsigned int borderalpha = OPAQUE; // The border alpha channel
static const unsigned int alphas[][3] = {
  /*                    fg       bg        border     */
  [SchemeNorm]     = { OPAQUE, baralpha, borderalpha },
  [SchemeSel]      = { OPAQUE, baralpha, borderalpha },
  [SchemeStatus]   = { OPAQUE, baralpha, borderalpha },
  [SchemeTagsSel]  = { OPAQUE, baralpha, borderalpha },
  [SchemeTagsNorm] = { OPAQUE, baralpha, borderalpha },
  [SchemeInfoSel]  = { OPAQUE, baralpha, borderalpha },
  [SchemeInfoNorm] = { OPAQUE, baralpha, borderalpha },
  [SchemeCol1]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol2]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol3]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol4]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol5]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol6]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol7]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol8]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol9]     = { OPAQUE, baralpha, borderalpha },
  [SchemeCol10]    = { OPAQUE, baralpha, borderalpha },
  [SchemeCol11]    = { OPAQUE, baralpha, borderalpha },
  [SchemeCol12]    = { OPAQUE, baralpha, borderalpha },
};

static const char *tags[NUMTAGS] = { NULL };  /* left for compatibility reasons, i.e. code that checks LENGTH(tags) */
static char *tagicons[][NUMTAGS] = {
  [IconsDefault]  = { "󰧟" },
  [IconsVacant]   = { "" },
  [IconsOccupied] = { "󰧞" },
  [IconsSelected] = { "󰑊" },

};

static const Rule rules[] = {
  /* class        instance       title    tags mask  isfloating  floatpos monitor */
  { "mpv",           NULL,       NULL,       0,         1,         NULL,    -1 },
  { "Lxappareance",  NULL,       NULL,       0,         1,         NULL,    -1 },
  { "Pavucontrol",   NULL,       NULL,       0,         1,         NULL,    -1 },
  { "qt5ct",         NULL,       NULL,       0,         1,         NULL,    -1 },
  { "Gucharmap",     NULL,       NULL,       0,         1,         NULL,    -1 },
  { "Sxiv",          NULL,       NULL,       0,         1,         NULL,    -1 },
  { "kruler",        NULL,       NULL,       0,         1,         NULL,    -1 },
  { "zoom",          NULL,       NULL,       0,         1,         NULL,    -1 },
  { "Connman-gtk",   NULL,       NULL,       0,         1,         NULL,    -1 },
  { "Emacs",         "emacs",    "agenda",   0,          1,        NULL,    -1 },  
  { "Alacritty", "calendar.txt", NULL,       0,         1,         NULL,    -1 },
};

#include "vanitygaps.c"
static const Layout layouts[] = {
/* symbol  arrange,  { nmaster, nstack, layout, master axis, stack axis, secondary stack axis } */
  { " 󰙀 ", flextile,  { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // default tile layout
  { " 󱒅 ", flextile,  { -1, -1, SPLIT_CENTERED_VERTICAL, TOP_TO_BOTTOM, TOP_TO_BOTTOM, 0, NULL } }, // centeredmaster
  { " 󱒎 ", flextile,  { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, GAPPLESSGRID_ALT1, 0, NULL } }, // Grid stack
  { " 󰋁 ", flextile,  { -1, -1, NO_SPLIT, GAPPLESSGRID, 0, 0, NULL } }, // gappless grid
  { NULL,   NULL,    {0} },
};

static const Layout doublestack[] = {
  { "|[D][D]", flextile, { -1, -1, SPLIT_VERTICAL_DUAL_STACK, TOP_TO_BOTTOM, MONOCLE, MONOCLE, NULL } }, // 2 stacks, both monocle
  { "|[|][|]", flextile, { -1, -1, SPLIT_VERTICAL_DUAL_STACK, TOP_TO_BOTTOM, LEFT_TO_RIGHT, LEFT_TO_RIGHT, NULL } }, // two stack, both horizontal
  { "|[D][|]", flextile, { -1, -1, SPLIT_VERTICAL_DUAL_STACK, TOP_TO_BOTTOM, MONOCLE, LEFT_TO_RIGHT, NULL } }, // two stack, monocle and horizontal
  { "|[|][D]", flextile, { -1, -1, SPLIT_VERTICAL_DUAL_STACK, TOP_TO_BOTTOM, LEFT_TO_RIGHT, MONOCLE, NULL } }, // two stack, horizontal and monocle
};

static const Layout full[] = {
  { "[M]", flextile, { -1, -1, NO_SPLIT, MONOCLE, 0, 0, monoclesymbols } }, // monocle
  { "[D]", flextile, { -1, -1, SPLIT_VERTICAL, TOP_TO_BOTTOM, MONOCLE, 0, NULL } }, // deck
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG)\
  { MODKEY,             KEY, view,       {.ui = 1 << TAG} }, \
  { MODKEY|Mod1Mask,	KEY, toggleview, {.ui = 1 << TAG} }, \
  { MODKEY|ShiftMask,   KEY, tag,        {.ui = 1 << TAG} }, \
  { MODKEY|ControlMask, KEY, toggletag,  {.ui = 1 << TAG} },

#include "movestack.c"
#include "shiftview.c"
static Key keys[] = {

{ MODKEY|ShiftMask,   XK_q,      killclient,    {0} }, 
{ MODKEY,             XK_j,      focusstack,    {.i = +1 } }, 
{ MODKEY,             XK_k,      focusstack,    {.i = -1 } },
{ MODKEY|ControlMask, XK_j,      inplacerotate, {.i = +1} }, 
{ MODKEY|ControlMask, XK_k,      inplacerotate, {.i = -1} }, 
{ MODKEY|ShiftMask,   XK_g,      zoom,          {0} }, 
{ MODKEY,             XK_g,      switchcol,     {0} }, 
{ MODKEY,             XK_h,      setmfact,      {.f = -0.02} }, 
{ MODKEY,             XK_l,      setmfact,      {.f = +0.02} }, 
{ MODKEY|ControlMask, XK_comma,  incnmaster,    {.i = +1 } }, 
{ MODKEY|ControlMask, XK_period, incnmaster,    {.i = -1 } }, 

{ MODKEY|ShiftMask,   XK_j,      movestack,     {.i = +1 } }, 
{ MODKEY|ShiftMask,   XK_k,      movestack,     {.i = -1 } }, 
{ MODKEY|ControlMask|Mod1Mask, XK_comma,      incnstack,     {.i = -1 } },
{ MODKEY|ControlMask|Mod1Mask, XK_period,     incnstack,     {.i = +1 } },

{ MODKEY,             XK_Tab, view,        {0} }, 
{ MODKEY,             XK_0,   view,        {.ui = ~0 } }, 
{ MODKEY,             XK_0,   setlayout,   {.v = &layouts[2]} }, 
{ MODKEY|ShiftMask,   XK_0,   tag,         {.ui = ~0 } }, 
{ MODKEY|ShiftMask,   XK_o,   winview,     {0} }, 
{ MODKEY|ShiftMask,   XK_o,   setlayout,   {.v = &layouts[0]} }, 
{ MODKEY|ControlMask, XK_l,   shiftview,   { .i = +1 } }, 
{ MODKEY|ControlMask, XK_h,   shiftview,   { .i = -1 } }, 
  TAGKEYS(            XK_1,                0) 
  TAGKEYS(            XK_2,                1) 
  TAGKEYS(            XK_3,                2) 
  TAGKEYS(            XK_4,                3) 
  TAGKEYS(            XK_5,                4) 
  TAGKEYS(            XK_6,                5)

{ MODKEY,  XK_t,    setlayout,         {.v = &layouts[0]} }, 
{ MODKEY,  XK_bar, mirrorlayout,      {0} },           
{ MODKEY,  XK_m,   setlayout,         {.v = &full[0]} }, 
{ MODKEY,  XK_s,   togglefloating,    {0} }, 
{ MODKEY,  XK_F11, togglefullscreen,  {0} }, 

{ MODKEY|Mod1Mask, XK_comma,  cyclelayout, {.i = -1 } }, 
{ MODKEY|Mod1Mask, XK_period, cyclelayout, {.i = +1 } }, 

{ MODKEY|ShiftMask, XK_m,   setlayout,             {.v = &full[1]} },  
{ MODKEY|ShiftMask, XK_F11,    togglefakefullscreen,  {0} }, 

{ MODKEY|ControlMask,  XK_m,  setlayout,  {.v = &doublestack[0]} }, 
{ MODKEY|ControlMask,  XK_i,  setlayout,  {.v = &doublestack[2]} },
{ MODKEY|ControlMask,  XK_u,  setlayout,  {.v = &doublestack[3]} },
{ MODKEY|ControlMask,  XK_o,  setlayout,  {.v = &doublestack[1]} },

{ MODKEY|ControlMask,           XK_q,          rotatelayoutaxis, {.i = +1 } },  
{ MODKEY|ControlMask|ShiftMask, XK_q,          rotatelayoutaxis, {.i = -1 } },  
{ MODKEY|ControlMask,           XK_plus,       rotatelayoutaxis, {.i = +2 } },  
{ MODKEY|ControlMask,           XK_dead_acute, rotatelayoutaxis, {.i = -2 } },  
{ MODKEY|Mod1Mask,		XK_plus,         rotatelayoutaxis, {.i = +4 } },  
{ MODKEY|Mod1Mask,		XK_dead_acute,   rotatelayoutaxis, {.i = -4 } },

{ MODKEY,                      XK_comma,  focusmon,       {.i = -1 } }, 
{ MODKEY,                      XK_period, focusmon,       {.i = +1 } }, 
{ MODKEY|ShiftMask,            XK_comma,  tagmon,         {.i = -1 } }, 
{ MODKEY|ShiftMask,            XK_period, tagmon,         {.i = +1 } }, 
//{ MODKEY|Mod1Mask|ControlMask, XK_comma,  tagswapmon,     {.i = +1 } }, 
//{ MODKEY|Mod1Mask|ControlMask, XK_period, tagswapmon,     {.i = -1 } },

{ MODKEY,          XK_v,  togglebar, {0} }, 
{ MODKEY|Mod1Mask, XK_l,  setcfact,  {.f = +0.25} }, 
{ MODKEY|Mod1Mask, XK_h,  setcfact,  {.f = -0.25} }, 
{ MODKEY|Mod1Mask, XK_o,  setcfact,  {.f =  0.00} },
{ MODKEY,          XK_F8, xrdb,      {.v = NULL } },

{ MODKEY|ShiftMask, XK_plus,  setborderpx,  {.i = +1 } },
{ MODKEY|ShiftMask, XK_minus,  setborderpx,  {.i = -1 } },
{ MODKEY|ControlMask|ShiftMask, XK_minus,  setborderpx,  {.i = 0 } },

{ MODKEY,	      XK_z, scratchpad_show,    {0} },
{ MODKEY|Mod1Mask,    XK_z, scratchpad_hide,    {0} },
{ MODKEY|ControlMask, XK_z, scratchpad_remove,  {0} },

{ MODKEY|Mod1Mask,              XK_u,      incrgaps,       {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
{ MODKEY|Mod1Mask,              XK_0,      togglegaps,     {0} },
{ MODKEY|Mod1Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },

/*{ MODKEY|Mod1Mask,            XK_i,      incrigaps,      {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
{ MODKEY|Mod1Mask,              XK_o,      incrogaps,      {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },

{ MODKEY|Mod1Mask,              XK_6,      incrihgaps,     {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
{ MODKEY|Mod1Mask,              XK_7,      incrivgaps,     {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
{ MODKEY|Mod1Mask,              XK_8,      incrohgaps,     {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
{ MODKEY|Mod1Mask,              XK_9,      incrovgaps,     {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },*/

};

static Button buttons[] = {
  /* click          event mask         button    function         argument */
  { ClkLtSymbol,    0,                 Button1,  cyclelayout,     {.i = +1 } },
  { ClkLtSymbol,    0,                 Button3,  setlayout,       {.v = &layouts[5]} },
  { ClkWinTitle,    0,                 Button2,  zoom,            {0} },
  { ClkStatusText,  0,                 Button1,  sigdwmblocks,    {.i = 1} },
  { ClkStatusText,  0,                 Button2,  sigdwmblocks,    {.i = 2} },
  { ClkStatusText,  0,                 Button3,  sigdwmblocks,    {.i = 3} },
  { ClkClientWin,   MODKEY,            Button1,  movemouse,       {0} },
  { ClkClientWin,   MODKEY,            Button2,  togglefloating,  {0} },
  { ClkClientWin,   MODKEY,            Button3,  resizemouse,     {0} },
  { ClkClientWin,   MODKEY|ShiftMask,  Button3,  dragcfact,       {0} },
  { ClkTagBar,      0,                 Button1,  view,            {0} },
  { ClkTagBar,      0,                 Button3,  toggleview,      {0} },
  { ClkTagBar,      MODKEY,            Button1,  tag,             {0} },
  { ClkTagBar,      MODKEY,            Button3,  toggletag,       {0} },
  { ClkTagBar,      0,                 Button4,  cycleiconset,    {.i = +1 } },
  { ClkTagBar,      0,                 Button5,  cycleiconset,    {.i = -1 } },
  { ClkClientWin,   MODKEY,	       Button1,	 winview,	  {0} },
};

static  const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,            1,  {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,      1,  {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,             1,  {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,       1,  {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,          1,  {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,        1,  {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,      1,  {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,            1,  {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,      1,  {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,      1,  {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,  1,  {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,        1,  {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,   1,  {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,            1,  {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  xrdb,		  1,  {ARG_TYPE_NONE}   )	    
};
