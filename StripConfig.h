/*-----------------------------------------------------------------------------
 * Copyright (c) 1996 Southeastern Universities Research Association,
 *               Continuous Electron Beam Accelerator Facility
 *
 * This software was developed under a United States Government license
 * described in the NOTICE file included as part of this distribution.
 *
 *-----------------------------------------------------------------------------
 */


#ifndef _StripConfig
#define _StripConfig

#include <X11/Xlib.h>
#include <X11/Intrinsic.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>

#include "StripDefines.h"
#include "StripMisc.h"
#include "cColorManager.h"

/* ======= Default Values ======= */
#define STRIPDEF_TITLE			NULL
#define STRIPDEF_TIME_TIMESPAN		STRIP_DEFAULT_TIMESPAN
#define STRIPDEF_TIME_SAMPLE_INTERVAL	1
#define STRIPDEF_TIME_REFRESH_INTERVAL	1
#define STRIPDEF_COLOR_BACKGROUND_STR	"White"
#define STRIPDEF_COLOR_FOREGROUND_STR	"Black"
#define STRIPDEF_COLOR_GRID_STR		"Grey75"
#define STRIPDEF_COLOR_LEGENDTEXT_STR	"White"
#define STRIPDEF_COLOR_COLOR1_STR	"Blue"
#define STRIPDEF_COLOR_COLOR2_STR	"OliveDrab"
#define STRIPDEF_COLOR_COLOR3_STR	"Brown"
#define STRIPDEF_COLOR_COLOR4_STR	"CadetBlue"
#define STRIPDEF_COLOR_COLOR5_STR	"Orange"
#define STRIPDEF_COLOR_COLOR6_STR	"Purple"
#define STRIPDEF_COLOR_COLOR7_STR	"Red"
#define	STRIPDEF_COLOR_COLOR8_STR	"Gold"
#define STRIPDEF_COLOR_COLOR9_STR	"RosyBrown"
#define STRIPDEF_COLOR_COLOR10_STR	"YellowGreen"
#define STRIPDEF_OPTION_GRID_XON	1
#define STRIPDEF_OPTION_GRID_YON	1
#define STRIPDEF_OPTION_AXIS_XNUMTICS	5
#define STRIPDEF_OPTION_AXIS_YNUMTICS	10
#define STRIPDEF_OPTION_AXIS_YCOLORSTAT	1
#define STRIPDEF_OPTION_GRAPH_LINEWIDTH	2
#define STRIPDEF_OPTION_LEGEND_VISIBLE	1
#define STRIPDEF_CURVE_NAME		"Curve"
#define STRIPDEF_CURVE_EGU		"Undefined"
#define STRIPDEF_CURVE_COMMENT		""
#define STRIPDEF_CURVE_PRECISION	4
#define STRIPDEF_CURVE_MIN		1e-7
#define STRIPDEF_CURVE_MAX		1e+7
#define STRIPDEF_CURVE_SCALE		STRIPSCALE_LINEAR
#define STRIPDEF_CURVE_PENSTAT		STRIPCURVE_PENDOWN
#define STRIPDEF_CURVE_PLOTSTAT		STRIPCURVE_PLOTTED
#define STRIPDEF_CURVE_ID		NULL

/* ====== Min/Max values for all attributes requiring range checking ====== */
#define	STRIPMIN_TIME_TIMESPAN		1
#define STRIPMAX_TIME_TIMESPAN		UINT_MAX
#define STRIPMIN_TIME_SAMPLE_INTERVAL	0.01
#define STRIPMAX_TIME_SAMPLE_INTERVAL	DBL_MAX
#define STRIPMIN_TIME_REFRESH_INTERVAL	0.1
#define STRIPMAX_TIME_REFRESH_INTERVAL	DBL_MAX
#define STRIPMIN_OPTION_AXIS_XNUMTICS	1
#define STRIPMAX_OPTION_AXIS_XNUMTICS	32
#define STRIPMIN_OPTION_AXIS_YNUMTICS	1
#define STRIPMAX_OPTION_AXIS_YNUMTICS	32
#define STRIPMIN_OPTION_GRAPH_LINEWIDTH	0
#define STRIPMAX_OPTION_GRAPH_LINEWIDTH	10
#define STRIPMIN_CURVE_PRECISION	0
#define STRIPMAX_CURVE_PRECISION	12

#define STRIPCONFIG_NUMCOLORS		(STRIP_MAX_CURVES + 4)
#define STRIPCONFIG_MAX_CALLBACKS	10


typedef int	StripConfigMaskElement;
typedef int	StripConfigAttribute;


typedef enum	_StripConfigAttributeEnum
{
  STRIPCONFIG_TITLE = 1,		/* (char *)			rw */
  STRIPCONFIG_TIME_TIMESPAN,		/* (unsigned)			rw */
  STRIPCONFIG_TIME_SAMPLE_INTERVAL,	/* (double)			rw */
  STRIPCONFIG_TIME_REFRESH_INTERVAL,	/* (double)			rw */
  STRIPCONFIG_COLOR_BACKGROUND,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_FOREGROUND,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_GRID,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_LEGENDTEXT,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR1,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR2,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR3,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR4,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR5,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR6,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR7,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR8,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR9,		/* (cColor *)		r  */
  STRIPCONFIG_COLOR_COLOR10,		/* (cColor *)		r  */
  STRIPCONFIG_OPTION_GRID_XON,		/* (int)			rw */
  STRIPCONFIG_OPTION_GRID_YON,		/* (int)			rw */
  STRIPCONFIG_OPTION_AXIS_XNUMTICS,	/* (int)			rw */
  STRIPCONFIG_OPTION_AXIS_YNUMTICS,	/* (int)			rw */
  STRIPCONFIG_OPTION_AXIS_YCOLORSTAT,	/* (int)			rw */
  STRIPCONFIG_OPTION_GRAPH_LINEWIDTH,	/* (int)			rw */
  STRIPCONFIG_OPTION_LEGEND_VISIBLE,	/* (int)			rw */

  STRIPCONFIG_TERMINATOR
}
StripConfigAttributeEnum;

#define STRIPCONFIG_FIRST_ATTRIBUTE	1
#define STRIPCONFIG_LAST_ATTRIBUTE	(STRIPCONFIG_TERMINATOR-1)
#define STRIPCONFIG_NUM_ATTRIBUTE	\
(STRIPCONFIG_LAST_ATTRIBUTE - STRIPCONFIG_FIRST_ATTRIBUTE + 1)



/* StripConfigMaskElement
 *
 *	Individual elements which can be set or unset in a StripConfigMask
 *	data structure.  There is a one-to-one correspondance between
 *	StripConfigAttribute values and the related StripConfigMaskElement
 *	values.
 */
typedef enum 	_StripConfigMaskElementEnum
{
  SCFGMASK_TITLE			= STRIPCONFIG_TITLE,

  /* time */
  SCFGMASK_TIME_TIMESPAN		= STRIPCONFIG_TIME_TIMESPAN,
  SCFGMASK_TIME_SAMPLE_INTERVAL		= STRIPCONFIG_TIME_SAMPLE_INTERVAL,
  SCFGMASK_TIME_REFRESH_INTERVAL	= STRIPCONFIG_TIME_REFRESH_INTERVAL,

  /* color */
  SCFGMASK_COLOR_BACKGROUND		= STRIPCONFIG_COLOR_BACKGROUND,
  SCFGMASK_COLOR_FOREGROUND		= STRIPCONFIG_COLOR_FOREGROUND,
  SCFGMASK_COLOR_GRID			= STRIPCONFIG_COLOR_GRID,
  SCFGMASK_COLOR_LEGENDTEXT		= STRIPCONFIG_COLOR_LEGENDTEXT,
  SCFGMASK_COLOR_COLOR1			= STRIPCONFIG_COLOR_COLOR1,
  SCFGMASK_COLOR_COLOR2			= STRIPCONFIG_COLOR_COLOR2,
  SCFGMASK_COLOR_COLOR3			= STRIPCONFIG_COLOR_COLOR3,
  SCFGMASK_COLOR_COLOR4			= STRIPCONFIG_COLOR_COLOR4,
  SCFGMASK_COLOR_COLOR5			= STRIPCONFIG_COLOR_COLOR5,
  SCFGMASK_COLOR_COLOR6			= STRIPCONFIG_COLOR_COLOR6,
  SCFGMASK_COLOR_COLOR7			= STRIPCONFIG_COLOR_COLOR7,
  SCFGMASK_COLOR_COLOR8			= STRIPCONFIG_COLOR_COLOR8,
  SCFGMASK_COLOR_COLOR9			= STRIPCONFIG_COLOR_COLOR9,
  SCFGMASK_COLOR_COLOR10		= STRIPCONFIG_COLOR_COLOR10,

  /* options */
  SCFGMASK_OPTION_GRID_XON		= STRIPCONFIG_OPTION_GRID_XON,
  SCFGMASK_OPTION_GRID_YON		= STRIPCONFIG_OPTION_GRID_YON,
  SCFGMASK_OPTION_AXIS_XNUMTICS		= STRIPCONFIG_OPTION_AXIS_XNUMTICS,
  SCFGMASK_OPTION_AXIS_YNUMTICS		= STRIPCONFIG_OPTION_AXIS_YNUMTICS,
  SCFGMASK_OPTION_AXIS_YCOLORSTAT	= STRIPCONFIG_OPTION_AXIS_YCOLORSTAT,
  SCFGMASK_OPTION_GRAPH_LINEWIDTH	= STRIPCONFIG_OPTION_GRAPH_LINEWIDTH,
  SCFGMASK_OPTION_LEGEND_VISIBLE	= STRIPCONFIG_OPTION_LEGEND_VISIBLE,

  /* curves */
  SCFGMASK_CURVE_NAME,
  SCFGMASK_CURVE_EGU,
  SCFGMASK_CURVE_COMMENT,
  SCFGMASK_CURVE_PRECISION,
  SCFGMASK_CURVE_MIN,
  SCFGMASK_CURVE_MAX,
  SCFGMASK_CURVE_SCALE,
  SCFGMASK_CURVE_PENSTAT,
  SCFGMASK_CURVE_PLOTSTAT,

  SCFGMASK_TERMINATOR
}
StripConfigMaskElementEnum;

#define SCFGMASK_FIRST_ELEMENT	1
#define SCFGMASK_LAST_ELEMENT	(SCFGMASK_TERMINATOR-1)
#define SCFGMASK_NUM_ELEMENTS	\
(SCFGMASK_LAST_ELEMENT - SCFGMASK_FIRST_ELEMENT + 1)



/* StripConfigMask
 *
 *	Structure containing info bits.  Must be accessed through
 *	utility functions.
 */
/*
#define STRIPCFGMASK_NBYTES	\
((SCFGMASK_NUM_ELEMENTS + CHAR_BIT) / CHAR_BIT)
*/
#define STRIPCFGMASK_NBYTES	8

typedef struct _StripConfigMask
{
  char	bytes[STRIPCFGMASK_NBYTES];
}
StripConfigMask;

/* StripConfigMask_clear
 *
 *	Zeroes out all bits.
 */
void	StripConfigMask_clear	(StripConfigMask *);


/* StripConfigMask_set
 *
 *	Sets the specified bit high.
 */
#if 0
void	StripConfigMask_set	(StripConfigMask *, StripConfigMaskElement);
#else
#define StripConfigMask_set(pmask, elem) \
((pmask)->bytes[((elem)-SCFGMASK_FIRST_ELEMENT)/CHAR_BIT] |= \
 (1 << (((elem)-SCFGMASK_FIRST_ELEMENT)%CHAR_BIT)))
#endif

/* StripConfigMask_unset
 *
 *	Sets the specified bit low.
 */
#if 0
void	StripConfigMask_unset	(StripConfigMask *, StripConfigMaskElement);
#else
#define StripConfigMask_unset(pmask, elem) \
((pmask)->bytes[((elem)-SCFGMASK_FIRST_ELEMENT)/CHAR_BIT] &= \
 ~(1 << (((elem)-SCFGMASK_FIRST_ELEMENT)%CHAR_BIT)))
#endif


/* StripConfigMask_stat
 *
 *	Returns the status of the specified bit.
 */
#if 0
int	StripConfigMask_stat	(StripConfigMask *, StripConfigMaskElement);
#else
#define StripConfigMask_stat(pmask, elem) \
((pmask)->bytes[((elem)-SCFGMASK_FIRST_ELEMENT)/CHAR_BIT] & \
 (1 << (((elem)-SCFGMASK_FIRST_ELEMENT)%CHAR_BIT)))
#endif


/* StripConfigMask_test
 *
 *	Takes two masks, A and B.  Returns true if B AND A == B.
 */
int	StripConfigMask_test	(StripConfigMask *A, StripConfigMask *B);


/* StripConfigMask_and
 *
 *	A = A AND B
 */
void	StripConfigMask_and	(StripConfigMask *A, StripConfigMask *B);


/* StripConfigMask_or
 *
 *	A = A OR B
 */
void	StripConfigMask_or	(StripConfigMask *A, StripConfigMask *B);


/* StripConfigMask_xor
 *
 *	A = A XOR B
 */
void	StripConfigMask_xor	(StripConfigMask *A, StripConfigMask *B);


/* StripConfigMask_intersect
 *
 *	returns {A AND B} != {}
 */
int	StripConfigMask_intersect (StripConfigMask *A, StripConfigMask *B);


/* STRIPCFGMASK_XXX
 *
 *	Predefined Masks comprised of related sets of elements.
 */
extern StripConfigMask	SCFGMASK_TIME;
extern StripConfigMask	SCFGMASK_COLOR;
extern StripConfigMask	SCFGMASK_OPTION;
extern StripConfigMask	SCFGMASK_CURVE;
extern StripConfigMask	SCFGMASK_ALL;




/* ======= Data Types ======= */
typedef void	(*StripConfigUpdateFunc) (StripConfigMask, void *);
  
typedef struct _StripCurveDetail
{
  char			name[STRIP_MAX_NAME_CHAR+1];
  char			egu[STRIP_MAX_EGU_CHAR+1];
  char			comment[STRIP_MAX_COMMENT_CHAR+1];
  int			precision;
  double		min, max;
  int			scale;
  int			penstat, plotstat;
  short			valid;
  cColor		*color;
  void			*id;
  StripConfigMask	update_mask;	/* fields updated since last update */
  StripConfigMask	set_mask;	/* fields without default values */
}
StripCurveDetail;

typedef struct _StripConfig
{
  cColorManager		scm;
  XVisualInfo			xvi;
  char				*title;
  FILE				*logfile;
  
  struct _Time {
    unsigned			timespan;
    double			sample_interval;
    double			refresh_interval;
  } Time;

  struct _Color {
    cColor			background;
    cColor			foreground;
    cColor			grid;
    cColor			legendtext;
    cColor			color[STRIP_MAX_CURVES];
  } Color;

  struct _Option {
    int				grid_xon;
    int				grid_yon;
    int				axis_xnumtics;
    int				axis_ynumtics;
    int				axis_ycolorstat;
    int				graph_linewidth;
    int				legend_visible;
  } Option;

  struct _Curves {
    StripCurveDetail		*Detail[STRIP_MAX_CURVES];
    int				plot_order[STRIP_MAX_CURVES];
  } Curves;

  struct _UpdateInfo {
    StripConfigMask		update_mask;
    struct _Callbacks {
      StripConfigMask		call_event;
      StripConfigUpdateFunc	call_func;
      void			*call_data;
    } Callbacks[STRIPCONFIG_MAX_CALLBACKS];
    int	callback_count;
  } UpdateInfo;
}
StripConfig;


/*
 * StripConfig_preinit
 *
 *	Initializes global constants (SCFGMASK_TIME, etc.)
 */
void	StripConfig_preinit	(void);



/*
 * StripConfig_init
 *
 *	Allocates storage for a StripConfig structure and initializes it
 *	with default values.  Then reads config info from the specified
 *	stdio stream, if it's not null.  See StripConfig_load() below for
 * 	specifics on how the file is read.
 */
StripConfig	*StripConfig_init	(cColorManager,
                                         XVisualInfo *,
					 FILE *,
					 StripConfigMask);


/*
 * StripConfig_delete
 *
 *	Deallocates storage for the StripConfig structure.
 */
void	StripConfig_delete	(StripConfig *);


/*
 * StripConfig_set/getattr
 *
 *	Sets/gets the specified attributes, returning true on success.
 */
int	StripConfig_setattr	(StripConfig *, ...);
int	StripConfig_getattr	(StripConfig *, ...);


/*
 * StripConfig_write
 *
 *	Attempts to write configuration info to the specified stdio stream.
 *	Writing is begun at the current file pointer.  Output format is:
 *	<ascii-attribute-name><whitespace><ascii-attribute-value><end-of-line>
 *	for each selected attribute.  The mask specifies which attributes to
 *	write to the file.
 */
int	StripConfig_write	(StripConfig *, FILE *, StripConfigMask);


/*
 * StripConfig_load
 *
 *	Attempts to read configuration info from the specified stdio stream.
 *	Reading is begun at the current file pointer and continues until an
 *	unrecognized character is encoutered.  When this happens, the ending
 *	character is pushed back into the stream and the function terminates.
 *	The mask specifies which attributes to load from the file.
 */
int	StripConfig_load	(StripConfig *, FILE *, StripConfigMask);


/*
 * StripConfig_addcallback
 *
 *	Causes all update event callbacks which match the mask to be called.
 */
int	StripConfig_addcallback	(StripConfig *,
				 StripConfigMask,
				 StripConfigUpdateFunc,	/* callback function */
				 void *);		/* client data */


/*
 * StripConfig_update
 *
 *	Causes all pending update event callbacks which match the
 *	mask to be called.
 */
void	StripConfig_update	(StripConfig *, StripConfigMask);



/*
 * StripConfig_reset_details
 *
 *	Given a StripCurveDetail pointer, intializes all fields
 *	to defaults.
 */
void	StripConfig_reset_details	(StripConfig *, StripCurveDetail *);

#endif
