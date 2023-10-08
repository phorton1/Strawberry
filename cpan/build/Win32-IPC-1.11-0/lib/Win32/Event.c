/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.40 from the
 * contents of Event.xs. Do not edit this file, edit Event.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

#line 1 "lib\\\\Win32\\\\Event.xs"
//--------------------------------------------------------------------
//
//   Win32::Event
//   Copyright 1998 by Christopher J. Madsen
//
//   XS file for the Win32::Event IPC module
//
//--------------------------------------------------------------------

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* #include "ppport.h" */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

typedef bool   TRUEFALSE;
typedef LPCSTR LPCSTR_OPT;

#line 32 "lib\\Win32\\Event.c"
#ifndef PERL_UNUSED_VAR
#  define PERL_UNUSED_VAR(var) if (0) var = var
#endif

#ifndef dVAR
#  define dVAR		dNOOP
#endif


/* This stuff is not part of the API! You have been warned. */
#ifndef PERL_VERSION_DECIMAL
#  define PERL_VERSION_DECIMAL(r,v,s) (r*1000000 + v*1000 + s)
#endif
#ifndef PERL_DECIMAL_VERSION
#  define PERL_DECIMAL_VERSION \
	  PERL_VERSION_DECIMAL(PERL_REVISION,PERL_VERSION,PERL_SUBVERSION)
#endif
#ifndef PERL_VERSION_GE
#  define PERL_VERSION_GE(r,v,s) \
	  (PERL_DECIMAL_VERSION >= PERL_VERSION_DECIMAL(r,v,s))
#endif
#ifndef PERL_VERSION_LE
#  define PERL_VERSION_LE(r,v,s) \
	  (PERL_DECIMAL_VERSION <= PERL_VERSION_DECIMAL(r,v,s))
#endif

/* XS_INTERNAL is the explicit static-linkage variant of the default
 * XS macro.
 *
 * XS_EXTERNAL is the same as XS_INTERNAL except it does not include
 * "STATIC", ie. it exports XSUB symbols. You probably don't want that
 * for anything but the BOOT XSUB.
 *
 * See XSUB.h in core!
 */


/* TODO: This might be compatible further back than 5.10.0. */
#if PERL_VERSION_GE(5, 10, 0) && PERL_VERSION_LE(5, 15, 1)
#  undef XS_EXTERNAL
#  undef XS_INTERNAL
#  if defined(__CYGWIN__) && defined(USE_DYNAMIC_LOADING)
#    define XS_EXTERNAL(name) __declspec(dllexport) XSPROTO(name)
#    define XS_INTERNAL(name) STATIC XSPROTO(name)
#  endif
#  if defined(__SYMBIAN32__)
#    define XS_EXTERNAL(name) EXPORT_C XSPROTO(name)
#    define XS_INTERNAL(name) EXPORT_C STATIC XSPROTO(name)
#  endif
#  ifndef XS_EXTERNAL
#    if defined(HASATTRIBUTE_UNUSED) && !defined(__cplusplus)
#      define XS_EXTERNAL(name) void name(pTHX_ CV* cv __attribute__unused__)
#      define XS_INTERNAL(name) STATIC void name(pTHX_ CV* cv __attribute__unused__)
#    else
#      ifdef __cplusplus
#        define XS_EXTERNAL(name) extern "C" XSPROTO(name)
#        define XS_INTERNAL(name) static XSPROTO(name)
#      else
#        define XS_EXTERNAL(name) XSPROTO(name)
#        define XS_INTERNAL(name) STATIC XSPROTO(name)
#      endif
#    endif
#  endif
#endif

/* perl >= 5.10.0 && perl <= 5.15.1 */


/* The XS_EXTERNAL macro is used for functions that must not be static
 * like the boot XSUB of a module. If perl didn't have an XS_EXTERNAL
 * macro defined, the best we can do is assume XS is the same.
 * Dito for XS_INTERNAL.
 */
#ifndef XS_EXTERNAL
#  define XS_EXTERNAL(name) XS(name)
#endif
#ifndef XS_INTERNAL
#  define XS_INTERNAL(name) XS(name)
#endif

/* Now, finally, after all this mess, we want an ExtUtils::ParseXS
 * internal macro that we're free to redefine for varying linkage due
 * to the EXPORT_XSUB_SYMBOLS XS keyword. This is internal, use
 * XS_EXTERNAL(name) or XS_INTERNAL(name) in your code if you need to!
 */

#undef XS_EUPXS
#if defined(PERL_EUPXS_ALWAYS_EXPORT)
#  define XS_EUPXS(name) XS_EXTERNAL(name)
#else
   /* default to internal */
#  define XS_EUPXS(name) XS_INTERNAL(name)
#endif

#ifndef PERL_ARGS_ASSERT_CROAK_XS_USAGE
#define PERL_ARGS_ASSERT_CROAK_XS_USAGE assert(cv); assert(params)

/* prototype to pass -Wmissing-prototypes */
STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params);

STATIC void
S_croak_xs_usage(const CV *const cv, const char *const params)
{
    const GV *const gv = CvGV(cv);

    PERL_ARGS_ASSERT_CROAK_XS_USAGE;

    if (gv) {
        const char *const gvname = GvNAME(gv);
        const HV *const stash = GvSTASH(gv);
        const char *const hvname = stash ? HvNAME(stash) : NULL;

        if (hvname)
	    Perl_croak_nocontext("Usage: %s::%s(%s)", hvname, gvname, params);
        else
	    Perl_croak_nocontext("Usage: %s(%s)", gvname, params);
    } else {
        /* Pants. I don't think that it should be possible to get here. */
	Perl_croak_nocontext("Usage: CODE(0x%" UVxf ")(%s)", PTR2UV(cv), params);
    }
}
#undef  PERL_ARGS_ASSERT_CROAK_XS_USAGE

#define croak_xs_usage        S_croak_xs_usage

#endif

/* NOTE: the prototype of newXSproto() is different in versions of perls,
 * so we define a portable version of newXSproto()
 */
#ifdef newXS_flags
#define newXSproto_portable(name, c_impl, file, proto) newXS_flags(name, c_impl, file, proto, 0)
#else
#define newXSproto_portable(name, c_impl, file, proto) (PL_Sv=(SV*)newXS(name, c_impl, file), sv_setpv(PL_Sv, proto), (CV*)PL_Sv)
#endif /* !defined(newXS_flags) */

#if PERL_VERSION_LE(5, 21, 5)
#  define newXS_deffile(a,b) Perl_newXS(aTHX_ a,b,file)
#else
#  define newXS_deffile(a,b) Perl_newXS_deffile(aTHX_ a,b)
#endif

#line 176 "lib\\Win32\\Event.c"

XS_EUPXS(XS_Win32__Event_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Win32__Event_new)
{
    dVAR; dXSARGS;
    if (items < 1 || items > 4)
       croak_xs_usage(cv,  "className, manual=FALSE, initial=FALSE, name=NULL");
    {
	char*	className = (char *)SvPV_nolen(ST(0))
;
	TRUEFALSE	manual;
	TRUEFALSE	initial;
	LPCSTR_OPT	name;
#line 34 "lib\\\\Win32\\\\Event.xs"
    SECURITY_ATTRIBUTES  sec;
#line 192 "lib\\Win32\\Event.c"
	HANDLE	RETVAL;

	if (items < 2)
	    manual = FALSE;
	else {
	    manual = SvTRUE(ST(1))
;
	}

	if (items < 3)
	    initial = FALSE;
	else {
	    initial = SvTRUE(ST(2))
;
	}

	if (items < 4)
	    name = NULL;
	else {
	    name = (LPCSTR_OPT)(SvOK(ST(3)) ? SvPV_nolen(ST(3)) : NULL)
;
	}
#line 36 "lib\\\\Win32\\\\Event.xs"
    sec.nLength = sizeof(SECURITY_ATTRIBUTES);
    sec.bInheritHandle = TRUE;        // allow inheritance
    sec.lpSecurityDescriptor = NULL;  // calling processes' security
    RETVAL = CreateEventA(&sec,manual,initial,name);
    if (RETVAL == INVALID_HANDLE_VALUE)
      XSRETURN_UNDEF;
#line 222 "lib\\Win32\\Event.c"
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
	    sv_setref_pv(RETVALSV, className, (void*)RETVAL);
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Win32__Event_open); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Win32__Event_open)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "className, name");
    {
	char*	className = (char *)SvPV_nolen(ST(0))
;
	LPCSTR	name = (LPCSTR)SvPV_nolen(ST(1))
;
	HANDLE	RETVAL;
#line 51 "lib\\\\Win32\\\\Event.xs"
    RETVAL = OpenEventA(EVENT_ALL_ACCESS, TRUE, name);
    if (RETVAL == INVALID_HANDLE_VALUE)
      XSRETURN_UNDEF;
#line 250 "lib\\Win32\\Event.c"
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
	    sv_setref_pv(RETVALSV, className, (void*)RETVAL);
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Win32__Event_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Win32__Event_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "event");
    {
	HANDLE	event;

	if (SvROK(ST(0))) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    event = INT2PTR(HANDLE,tmp);
	}
	else
	    Perl_croak_nocontext("%s: %s is not a reference",
			"Win32::Event::DESTROY",
			"event")
;
#line 62 "lib\\\\Win32\\\\Event.xs"
    if (sv_derived_from(ST(0), "Win32::Event") &&
        (event != INVALID_HANDLE_VALUE))
      CloseHandle(event);
#line 284 "lib\\Win32\\Event.c"
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Win32__Event_pulse); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Win32__Event_pulse)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "event");
    {
	HANDLE	event;
	BOOL	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Win32::Event")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    event = INT2PTR(HANDLE, tmp);
	}
	else
	    croak("event is not of type Win32::Event")
;
#line 71 "lib\\\\Win32\\\\Event.xs"
    RETVAL = PulseEvent(event);
#line 310 "lib\\Win32\\Event.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Win32__Event_reset); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Win32__Event_reset)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "event");
    {
	HANDLE	event;
	BOOL	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Win32::Event")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    event = INT2PTR(HANDLE, tmp);
	}
	else
	    croak("event is not of type Win32::Event")
;
#line 80 "lib\\\\Win32\\\\Event.xs"
    RETVAL = ResetEvent(event);
#line 337 "lib\\Win32\\Event.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Win32__Event_set); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Win32__Event_set)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "event");
    {
	HANDLE	event;
	BOOL	RETVAL;
	dXSTARG;

	if (sv_derived_from(ST(0), "Win32::Event")) {
	    IV tmp = SvIV((SV*)SvRV(ST(0)));
	    event = INT2PTR(HANDLE, tmp);
	}
	else
	    croak("event is not of type Win32::Event")
;
#line 89 "lib\\\\Win32\\\\Event.xs"
    RETVAL = SetEvent(event);
#line 364 "lib\\Win32\\Event.c"
	XSprePUSH; PUSHi((IV)RETVAL);
    }
    XSRETURN(1);
}

#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Win32__Event); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Win32__Event)
{
#if PERL_VERSION_LE(5, 21, 5)
    dVAR; dXSARGS;
#else
    dVAR; dXSBOOTARGSXSAPIVERCHK;
#endif
#if (PERL_REVISION == 5 && PERL_VERSION < 9)
    char* file = __FILE__;
#else
    const char* file = __FILE__;
#endif

    PERL_UNUSED_VAR(file);

    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
#if PERL_VERSION_LE(5, 21, 5)
    XS_VERSION_BOOTCHECK;
#  ifdef XS_APIVERSION_BOOTCHECK
    XS_APIVERSION_BOOTCHECK;
#  endif
#endif

        (void)newXSproto_portable("Win32::Event::new", XS_Win32__Event_new, file, "$;$$$");
        (void)newXSproto_portable("Win32::Event::open", XS_Win32__Event_open, file, "$$");
        (void)newXSproto_portable("Win32::Event::DESTROY", XS_Win32__Event_DESTROY, file, "$");
        (void)newXSproto_portable("Win32::Event::pulse", XS_Win32__Event_pulse, file, "$");
        (void)newXSproto_portable("Win32::Event::reset", XS_Win32__Event_reset, file, "$");
        (void)newXSproto_portable("Win32::Event::set", XS_Win32__Event_set, file, "$");
#if PERL_VERSION_LE(5, 21, 5)
#  if PERL_VERSION_GE(5, 9, 0)
    if (PL_unitcheckav)
        call_list(PL_scopestack_ix, PL_unitcheckav);
#  endif
    XSRETURN_YES;
#else
    Perl_xs_boot_epilog(aTHX_ ax);
#endif
}
