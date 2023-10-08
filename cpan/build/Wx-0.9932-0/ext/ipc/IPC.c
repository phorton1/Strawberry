/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.40 from the
 * contents of IPC.xs. Do not edit this file, edit IPC.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

/////////////////////////////////////////////////////////////////////////////
// Name:        ext/ipc/IPC.xs
// Purpose:     XS for Inter-Process Communication Framework
// Author:      Mark Dootson
// Modified by:
// Created:     13 April 2013
// SVN-ID:      $Id:$
// Copyright:   (c) 2013 Mattia Barbon
// Licence:     This program is free software; you can redistribute it and/or
//              modify it under the same terms as Perl itself
/////////////////////////////////////////////////////////////////////////////

#define PERL_NO_GET_CONTEXT

#include "cpp/wxapi.h"
#include "cpp/constants.h"
#include "cpp/overload.h"

#undef THIS

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

#if wxPERL_USE_IPC
#define XSubPPtmpAAAA 1


/* INCLUDE_COMMAND:  Including output of 'C:\StrawBerry\perl\bin\perl.exe -I../.. -MExtUtils::XSpp::Cmd -e xspp -- -t ../../typemap.xsp XS/IPC.xsp' from 'IPC.xs' */

#include <exception>

#undef  xsp_constructor_class
#define xsp_constructor_class(c) (c)
#if wxUSE_IPC
#define XSpp_364791ad_027731
#define wxUSE_DDE_FOR_IPC 1
#include <wx/ipc.h>
#include <cpp/ipc.h>
#if WXPERL_W_VERSION_LT( 2, 9, 0 )
#define XSpp_364791ad_044109
#define  wxIPC_UTF16TEXT 13
#define  wxIPC_UTF8TEXT  13
#define  wxIPC_UTF32TEXT 13
#endif
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Wx__Connection_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_new)
{
    dVAR; dXSARGS;
    PERL_UNUSED_VAR(cv); /* -W */
    PERL_UNUSED_VAR(items); /* -W */
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
    BEGIN_OVERLOAD()
        MATCH_VOIDM_REDISP( newDefault )
        MATCH_ANY_REDISP( newBuffer )
    END_OVERLOAD( "Wx::Connection::new" )
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Wx__Connection_newDefault); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_newDefault)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char*	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxConnection *	RETVAL;
    RETVAL = new wxPlConnection( CLASS );
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
    wxPli_thread_sv_register( aTHX_ "Wx::Connection", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    wxPli_object_set_deleteable( aTHX_ ST(0), true );
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_newBuffer); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_newBuffer)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "CLASS, buffer");
    {
	char*	CLASS = (char *)SvPV_nolen(ST(0))
;
	SV*	buffer = ST(1)
;
	wxConnection *	RETVAL;
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    RETVAL = new wxPlConnection( CLASS, (void*)SvPVX(buffer), (size_t)SvCUR(buffer));
#else
    RETVAL = new wxPlConnection( CLASS, (wxChar*)SvPVX(buffer), (int)SvCUR(buffer));
#endif
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
    wxPli_thread_sv_register( aTHX_ "Wx::Connection", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    wxPli_object_set_deleteable( aTHX_ ST(0), true );
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_CLONE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_CLONE)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
    wxPli_thread_sv_clone( aTHX_ CLASS, (wxPliCloneSV)wxPli_detach_object );
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__Connection_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
    wxPli_thread_sv_unregister( aTHX_ wxPli_get_class( aTHX_ ST(0) ), THIS, ST(0) );
    if( wxPli_object_is_deleteable( aTHX_ ST(0) ) )
        delete THIS;    
    }
    XSRETURN_EMPTY;
}

#if WXPERL_W_VERSION_GE( 2, 9, 0 )
#define XSubPPtmpAAAC 1


XS_EUPXS(XS_Wx__Connection_Execute); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_Execute)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, data");
    {
	SV*	data = ST(1)
;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;
    RETVAL = THIS->Execute((void*)SvPVX(data), (size_t)SvLEN(data), wxIPC_TEXT);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}

#else
#define XSubPPtmpAAAD 1


XS_EUPXS(XS_Wx__Connection_Execute); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_Execute)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, data");
    {
	wxString	data;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( data, wxString, ST(1) )
;
    RETVAL = THIS->Execute( data );
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}

#endif

XS_EUPXS(XS_Wx__Connection_Request); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_Request)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "THIS, item, format = wxIPC_TEXT");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	wxString	item;
	wxIPCFormat	format;
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    size_t size;
#else
    int size;
#endif
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;

    WXSTRING_INPUT( item, wxString, ST(1) )
;

	if (items < 3)
	    format = wxIPC_TEXT;
	else {
	    format = (wxIPCFormat)SvIV(ST(2))
;
	}
    void *buffer = (void*)THIS->Request(item, &size, format);
    EXTEND( SP, 1 );
    PUSHs( sv_2mortal( newSVpvn( (char*)buffer, size) ) );
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Wx__Connection_Poke); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_Poke)
{
    dVAR; dXSARGS;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "THIS, item, data, format = wxIPC_TEXT");
    {
	wxString	item;
	SV*	data = ST(2)
;
	wxIPCFormat	format;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( item, wxString, ST(1) )
;

	if (items < 4)
	    format = wxIPC_TEXT;
	else {
	    format = (wxIPCFormat)SvIV(ST(3))
;
	}
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    RETVAL = THIS->Poke(item, (void*)SvPVX(data), (size_t)SvCUR(data), format);
#else
    RETVAL = THIS->Poke(item, (wxChar*)SvPVX(data), (int)SvCUR(data), format);
#endif
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_StartAdvise); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_StartAdvise)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, item");
    {
	wxString	item;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( item, wxString, ST(1) )
;

	RETVAL = THIS->StartAdvise(item);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_StopAdvise); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_StopAdvise)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, item");
    {
	wxString	item;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( item, wxString, ST(1) )
;

	RETVAL = THIS->StopAdvise(item);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_Advise); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_Advise)
{
    dVAR; dXSARGS;
    if (items < 3 || items > 4)
       croak_xs_usage(cv,  "THIS, item, data, format = wxIPC_TEXT");
    {
	wxString	item;
	SV*	data = ST(2)
;
	wxIPCFormat	format;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( item, wxString, ST(1) )
;

	if (items < 4)
	    format = wxIPC_TEXT;
	else {
	    format = (wxIPCFormat)SvIV(ST(3))
;
	}
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    RETVAL = THIS->Advise(item, (void*)SvPVX(data), (size_t)SvCUR(data), format);
#else
    RETVAL = THIS->Advise(item, (wxChar*)SvPVX(data), (int)SvCUR(data), format);
#endif
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_Disconnect); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_Disconnect)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;
    wxPli_object_set_deleteable( aTHX_ ST(0), true );
    RETVAL = THIS->Disconnect();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_GetConnected); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_GetConnected)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

	RETVAL = THIS->GetConnected();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_SetConnected); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_SetConnected)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, connected");
    {
	bool	connected = (bool)SvTRUE(ST(1))
;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;

	THIS->SetConnected(connected);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__Connection_OnStartAdvise); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnStartAdvise)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, topic, item");
    {
	wxString	topic;
	wxString	item;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;

    WXSTRING_INPUT( item, wxString, ST(2) )
;
    RETVAL = ((wxPlConnection*)THIS)->base_OnStartAdvise(topic, item);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_OnStopAdvise); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnStopAdvise)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, topic, item");
    {
	wxString	topic;
	wxString	item;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;

    WXSTRING_INPUT( item, wxString, ST(2) )
;
    RETVAL = ((wxPlConnection*)THIS)->base_OnStopAdvise(topic, item);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_OnDisconnect); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnDisconnect)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;
    RETVAL = ((wxPlConnection*)THIS)->base_OnDisconnect();
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_OnExecute); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnExecute)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "THIS, topic, data, format");
    {
	wxString	topic;
	SV*	data = ST(2)
;
	wxIPCFormat	format = (wxIPCFormat)SvIV(ST(3))
;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    RETVAL = ((wxPlConnection*)THIS)->base_OnExecute(topic, (void*)SvPVX(data), (size_t)SvLEN(data), format);
#else
    RETVAL = ((wxPlConnection*)THIS)->base_OnExecute(topic, (wxChar*)SvPVX(data), (int)SvLEN(data), format);
#endif
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}

#if WXPERL_W_VERSION_GE( 2, 9, 0 )
#define XSubPPtmpAAAE 1


XS_EUPXS(XS_Wx__Connection_OnExec); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnExec)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, topic, data");
    {
	wxString	topic;
	wxString	data;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;

    WXSTRING_INPUT( data, wxString, ST(2) )
;
    RETVAL = ((wxPlConnection*)THIS)->base_OnExec(topic, data);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}

#endif

XS_EUPXS(XS_Wx__Connection_OnRequest); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnRequest)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "THIS, topic, item, format");
    PERL_UNUSED_VAR(ax); /* -Wall */
    SP -= items;
    {
	wxString	topic;
	wxString	item;
	wxIPCFormat	format = (wxIPCFormat)SvIV(ST(3))
;
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    size_t size;
#else
    int size;
#endif
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;

    WXSTRING_INPUT( item, wxString, ST(2) )
;
    void *buffer = (void*)((wxPlConnection*)THIS)->base_OnRequest(topic, item, &size, format);
    EXTEND( SP, 1 );
    PUSHs( sv_2mortal( newSVpvn( (char*)buffer, size ) ) );
	PUTBACK;
	return;
    }
}


XS_EUPXS(XS_Wx__Connection_OnPoke); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnPoke)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "THIS, topic, item, data, format");
    {
	wxString	topic;
	wxString	item;
	SV*	data = ST(3)
;
	wxIPCFormat	format = (wxIPCFormat)SvIV(ST(4))
;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;

    WXSTRING_INPUT( item, wxString, ST(2) )
;
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    RETVAL = ((wxPlConnection*)THIS)->base_OnPoke(topic, item, (void*)SvPVX(data), (size_t)SvLEN(data), format);
#else
    RETVAL = ((wxPlConnection*)THIS)->base_OnPoke(topic, item, (wxChar*)SvPVX(data), (int)SvLEN(data), format);
#endif
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Connection_OnAdvise); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Connection_OnAdvise)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "THIS, topic, item, data, format");
    {
	wxString	topic;
	wxString	item;
	SV*	data = ST(3)
;
	wxIPCFormat	format = (wxIPCFormat)SvIV(ST(4))
;
	wxConnection *    THIS = (wxConnection *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Connection" )
;
	bool	RETVAL;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;

    WXSTRING_INPUT( item, wxString, ST(2) )
;
#if WXPERL_W_VERSION_GE( 2, 9, 0 )
    RETVAL = ((wxPlConnection*)THIS)->base_OnAdvise(topic, item, (void*)SvPVX(data), (size_t)SvLEN(data), format);
#else
    RETVAL = ((wxPlConnection*)THIS)->base_OnAdvise(topic, item, (wxChar*)SvPVX(data), (int)SvLEN(data), format);
#endif
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Server_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Server_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char*	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxServer *	RETVAL;
    RETVAL = new wxPlServer( CLASS );
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Server_Destroy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Server_Destroy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxServer *    THIS = (wxServer *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Server" )
;
    delete THIS;
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__Server_Create); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Server_Create)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, servicename");
    {
	wxString	servicename;
	wxServer *    THIS = (wxServer *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Server" )
;
	bool	RETVAL;

    WXSTRING_INPUT( servicename, wxString, ST(1) )
;

	RETVAL = THIS->Create(servicename);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Server_OnAcceptConnection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Server_OnAcceptConnection)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, topic");
    {
	wxString	topic;
	wxServer *    THIS = (wxServer *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Server" )
;
	wxConnection *	RETVAL;

    WXSTRING_INPUT( topic, wxString, ST(1) )
;
    RETVAL = (wxConnection*)((wxPlServer*)THIS)->base_OnAcceptConnection(topic);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
    wxPli_thread_sv_register( aTHX_ "Wx::Connection", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Client_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Client_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char*	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxClient *	RETVAL;
    RETVAL = new wxPlClient( CLASS );
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Client_Destroy); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Client_Destroy)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxClient *    THIS = (wxClient *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Client" )
;
    delete THIS;
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__Client_ValidHost); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Client_ValidHost)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, host");
    {
	wxString	host;
	wxClient *    THIS = (wxClient *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Client" )
;
	bool	RETVAL;

    WXSTRING_INPUT( host, wxString, ST(1) )
;

	RETVAL = THIS->ValidHost(host);
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Client_MakeConnection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Client_MakeConnection)
{
    dVAR; dXSARGS;
    if (items != 4)
       croak_xs_usage(cv,  "THIS, host, server, topic");
    {
	wxString	host;
	wxString	server;
	wxString	topic;
	wxClient *    THIS = (wxClient *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Client" )
;
	wxConnection *	RETVAL;

    WXSTRING_INPUT( host, wxString, ST(1) )
;

    WXSTRING_INPUT( server, wxString, ST(2) )
;

    WXSTRING_INPUT( topic, wxString, ST(3) )
;
    RETVAL = (wxConnection*)THIS->MakeConnection(host, server, topic );
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
    wxPli_thread_sv_register( aTHX_ "Wx::Connection", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__Client_OnMakeConnection); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__Client_OnMakeConnection)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxClient *    THIS = (wxClient *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::Client" )
;
	wxConnection *	RETVAL;
    RETVAL = (wxConnection*)((wxPlClient*)THIS)->base_OnMakeConnection();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
    wxPli_thread_sv_register( aTHX_ "Wx::Connection", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#endif
#include "xspp/const_IPC_xsp.h"

/* INCLUDE: Returning to 'IPC.xs' from 'C:\StrawBerry\perl\bin\perl.exe -I../.. -MExtUtils::XSpp::Cmd -e xspp -- -t ../../typemap.xsp XS/IPC.xsp' */

#include "cpp/ovl_const.cpp"
#endif
#if defined(__WXMSW__)
#undef XS
#define XS( name ) WXXS( name )
#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Wx__IPC); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Wx__IPC)
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

#if XSubPPtmpAAAA
#if XSubPPtmpAAAB
        newXS_deffile("Wx::Connection::new", XS_Wx__Connection_new);
        newXS_deffile("Wx::Connection::newDefault", XS_Wx__Connection_newDefault);
        newXS_deffile("Wx::Connection::newBuffer", XS_Wx__Connection_newBuffer);
        newXS_deffile("Wx::Connection::CLONE", XS_Wx__Connection_CLONE);
        newXS_deffile("Wx::Connection::DESTROY", XS_Wx__Connection_DESTROY);
#if XSubPPtmpAAAC
        newXS_deffile("Wx::Connection::Execute", XS_Wx__Connection_Execute);
#endif
#if XSubPPtmpAAAD
        newXS_deffile("Wx::Connection::Execute", XS_Wx__Connection_Execute);
#endif
        newXS_deffile("Wx::Connection::Request", XS_Wx__Connection_Request);
        newXS_deffile("Wx::Connection::Poke", XS_Wx__Connection_Poke);
        newXS_deffile("Wx::Connection::StartAdvise", XS_Wx__Connection_StartAdvise);
        newXS_deffile("Wx::Connection::StopAdvise", XS_Wx__Connection_StopAdvise);
        newXS_deffile("Wx::Connection::Advise", XS_Wx__Connection_Advise);
        newXS_deffile("Wx::Connection::Disconnect", XS_Wx__Connection_Disconnect);
        newXS_deffile("Wx::Connection::GetConnected", XS_Wx__Connection_GetConnected);
        newXS_deffile("Wx::Connection::SetConnected", XS_Wx__Connection_SetConnected);
        newXS_deffile("Wx::Connection::OnStartAdvise", XS_Wx__Connection_OnStartAdvise);
        newXS_deffile("Wx::Connection::OnStopAdvise", XS_Wx__Connection_OnStopAdvise);
        newXS_deffile("Wx::Connection::OnDisconnect", XS_Wx__Connection_OnDisconnect);
        newXS_deffile("Wx::Connection::OnExecute", XS_Wx__Connection_OnExecute);
#if XSubPPtmpAAAE
        newXS_deffile("Wx::Connection::OnExec", XS_Wx__Connection_OnExec);
#endif
        newXS_deffile("Wx::Connection::OnRequest", XS_Wx__Connection_OnRequest);
        newXS_deffile("Wx::Connection::OnPoke", XS_Wx__Connection_OnPoke);
        newXS_deffile("Wx::Connection::OnAdvise", XS_Wx__Connection_OnAdvise);
        newXS_deffile("Wx::Server::new", XS_Wx__Server_new);
        newXS_deffile("Wx::Server::Destroy", XS_Wx__Server_Destroy);
        newXS_deffile("Wx::Server::Create", XS_Wx__Server_Create);
        newXS_deffile("Wx::Server::OnAcceptConnection", XS_Wx__Server_OnAcceptConnection);
        newXS_deffile("Wx::Client::new", XS_Wx__Client_new);
        newXS_deffile("Wx::Client::Destroy", XS_Wx__Client_Destroy);
        newXS_deffile("Wx::Client::ValidHost", XS_Wx__Client_ValidHost);
        newXS_deffile("Wx::Client::MakeConnection", XS_Wx__Client_MakeConnection);
        newXS_deffile("Wx::Client::OnMakeConnection", XS_Wx__Client_OnMakeConnection);
#endif
#endif

    /* Initialisation Section */

  INIT_PLI_HELPERS( wx_pli_helpers );

#if XSubPPtmpAAAA
#if XSubPPtmpAAAB
#if XSubPPtmpAAAC
#endif
#if XSubPPtmpAAAD
#endif
#if XSubPPtmpAAAE
#endif
#endif
#endif

    /* End of Initialisation Section */

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
