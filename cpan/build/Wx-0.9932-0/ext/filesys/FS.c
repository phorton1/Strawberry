/*
 * This file was generated automatically by ExtUtils::ParseXS version 3.40 from the
 * contents of FS.xs. Do not edit this file, edit FS.xs instead.
 *
 *    ANY CHANGES MADE HERE WILL BE LOST!
 *
 */

/////////////////////////////////////////////////////////////////////////////
// Name:        ext/filesys/FS.xs
// Purpose:     XS for Wx::FileSystem and related classes
// Author:      Mattia Barbon
// Modified by:
// Created:     28/04/2001
// RCS-ID:      $Id: FS.xs 2057 2007-06-18 23:03:00Z mbarbon $
// Copyright:   (c) 2001-2002, 2004, 2006 Mattia Barbon
// Licence:     This program is free software; you can redistribute it and/or
//              modify it under the same terms as Perl itself
/////////////////////////////////////////////////////////////////////////////

#define PERL_NO_GET_CONTEXT

#include "cpp/wxapi.h"
#include "cpp/constants.h"

#undef THIS

#if WXPERL_W_VERSION_GE( 2, 7, 2 )
#include <wx/filesys.h>

double fs_constant( const char* name, int arg )
{
    // !package: Wx
    // !parser: sub { $_[0] =~ m<^\s*r\w*\(\s*(\w+)\s*\);\s*(?://(.*))?$> }
    // !tag: filesystem
#define r( n ) \
    if( strEQ( name, #n ) ) \
        return n;

    WX_PL_CONSTANT_INIT();

    switch( fl )
    {
    case 'F':
        r( wxFS_READ );
        r( wxFS_SEEKABLE );
        break;
    }
#undef r

    WX_PL_CONSTANT_CLEANUP();
}

wxPlConstants fs_module( &fs_constant );
#endif

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


/* INCLUDE:  Including 'XS/FileSystem.xs' from 'FS.xs' */


/* INCLUDE:  Including 'XS/FileSystemHandler.xs' from 'XS/FileSystem.xs' */


/* INCLUDE:  Including 'XS/FSFile.xs' from 'XS/FileSystemHandler.xs' */

#include <wx/filesys.h>

XS_EUPXS(XS_Wx__FSFile_CLONE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FSFile_CLONE)
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


XS_EUPXS(XS_Wx__FSFile_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FSFile_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFSFile *    THIS = (wxFSFile *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FSFile" )
;
    wxPli_thread_sv_unregister( aTHX_ wxPli_get_class( aTHX_ ST(0) ), THIS, ST(0) );
    delete THIS;
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__FSFile_GetAnchor); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FSFile_GetAnchor)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFSFile *    THIS = (wxFSFile *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FSFile" )
;
	wxString	RETVAL;

	RETVAL = THIS->GetAnchor();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FSFile_GetLocation); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FSFile_GetLocation)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFSFile *    THIS = (wxFSFile *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FSFile" )
;
	wxString	RETVAL;

	RETVAL = THIS->GetLocation();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FSFile_GetMimeType); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FSFile_GetMimeType)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFSFile *    THIS = (wxFSFile *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FSFile" )
;
	wxString	RETVAL;

	RETVAL = THIS->GetMimeType();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FSFile_GetStream); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FSFile_GetStream)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFSFile *    THIS = (wxFSFile *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FSFile" )
;
	wxInputStream *	RETVAL;

	RETVAL = THIS->GetStream();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_stream_2_sv( aTHX_ RETVALSV, RETVAL, "Wx::InputStream" );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#include "cpp/fshandler.h"

XS_EUPXS(XS_Wx__FSFile_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FSFile_new)
{
    dVAR; dXSARGS;
    if (items != 5)
       croak_xs_usage(cv,  "CLASS, fh, loc, mimetype, anchor");
    {
	SV*	fh = ST(1)
;
	wxString	loc;
	wxString	mimetype;
	wxString	anchor;
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxPlFSFile *	RETVAL;

    WXSTRING_INPUT( loc, wxString, ST(2) )
;

    WXSTRING_INPUT( mimetype, wxString, ST(3) )
;

    WXSTRING_INPUT( anchor, wxString, ST(4) )
;
    RETVAL = new wxPlFSFile( fh, loc, mimetype, anchor );
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_non_object_2_sv( aTHX_ RETVALSV, RETVAL, "Wx::PlFSFile" );
    wxPli_thread_sv_register( aTHX_ "Wx::PlFSFile", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


/* INCLUDE: Returning to 'XS/FileSystemHandler.xs' from 'XS/FSFile.xs' */

#include <wx/filesys.h>
#include <wx/fs_inet.h>
#include <wx/fs_zip.h>
#include <wx/fs_mem.h>
#undef THIS
#if 0 // protected!
#define XSubPPtmpAAAA 1


XS_EUPXS(XS_Wx__FileSystemHandler_GetAnchor); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystemHandler_GetAnchor)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, location");
    {
	wxString	location;
	wxFileSystemHandler *    THIS = (wxFileSystemHandler *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystemHandler" )
;
	wxString	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	RETVAL = THIS->GetAnchor(location);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FileSystemHandler_GetLeftLocation); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystemHandler_GetLeftLocation)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, location");
    {
	wxString	location;
	wxFileSystemHandler *    THIS = (wxFileSystemHandler *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystemHandler" )
;
	wxString	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	RETVAL = THIS->GetLeftLocation(location);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FileSystemHandler_GetMimeTypeFromExt); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystemHandler_GetMimeTypeFromExt)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, location");
    {
	wxString	location;
	wxFileSystemHandler *    THIS = (wxFileSystemHandler *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystemHandler" )
;
	wxString	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	RETVAL = THIS->GetMimeTypeFromExt(location);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FileSystemHandler_GetProtocol); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystemHandler_GetProtocol)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, location");
    {
	wxString	location;
	wxFileSystemHandler *    THIS = (wxFileSystemHandler *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystemHandler" )
;
	wxString	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	RETVAL = THIS->GetProtocol(location);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FileSystemHandler_GetRightLocation); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystemHandler_GetRightLocation)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, location");
    {
	wxString	location;
	wxFileSystemHandler *    THIS = (wxFileSystemHandler *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystemHandler" )
;
	wxString	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	RETVAL = THIS->GetRightLocation(location);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#endif
#if wxUSE_FS_INET
#define XSubPPtmpAAAB 1


XS_EUPXS(XS_Wx__InternetFSHandler_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__InternetFSHandler_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxInternetFSHandler *	RETVAL;

	RETVAL = new wxInternetFSHandler();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#endif

XS_EUPXS(XS_Wx__ZipFSHandler_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__ZipFSHandler_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxZipFSHandler *	RETVAL;

	RETVAL = new wxZipFSHandler();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#if WXPERL_W_VERSION_GE( 2, 7, 2 )
#define XSubPPtmpAAAC 1


XS_EUPXS(XS_Wx__ArchiveFSHandler_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__ArchiveFSHandler_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxArchiveFSHandler *	RETVAL;

	RETVAL = new wxArchiveFSHandler();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#endif

XS_EUPXS(XS_Wx__MemoryFSHandler_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxMemoryFSHandler *	RETVAL;

	RETVAL = new wxMemoryFSHandler();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__MemoryFSHandler_AddImageFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_AddImageFile)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "name, image, type");
    {
	wxString	name;
	wxImage*    image = (wxImage *) wxPli_sv_2_object( aTHX_ ST(1), "Wx::Image" )
;
	wxBitmapType	type = (wxBitmapType)SvIV(ST(2))
;

    WXSTRING_INPUT( name, wxString, ST(0) )
;
    wxMemoryFSHandler::AddFile( name, *image, type );
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__MemoryFSHandler_AddBitmapFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_AddBitmapFile)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "name, bitmap, type");
    {
	wxString	name;
	wxBitmap*    bitmap = (wxBitmap *) wxPli_sv_2_object( aTHX_ ST(1), "Wx::Bitmap" )
;
	wxBitmapType	type = (wxBitmapType)SvIV(ST(2))
;

    WXSTRING_INPUT( name, wxString, ST(0) )
;
    wxMemoryFSHandler::AddFile( name, *bitmap, type );
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__MemoryFSHandler_AddTextFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_AddTextFile)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "name, string");
    {
	wxString	name;
	wxString	string;

    WXSTRING_INPUT( name, wxString, ST(0) )
;

    WXSTRING_INPUT( string, wxString, ST(1) )
;
    wxMemoryFSHandler::AddFile( name, string );
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__MemoryFSHandler_AddBinaryFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_AddBinaryFile)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "name, scalar");
    {
	wxString	name;
	SV*	scalar = ST(1)
;
    STRLEN len;
    char* data = SvPV( scalar, len );

    WXSTRING_INPUT( name, wxString, ST(0) )
;
    wxMemoryFSHandler::AddFile( name, data, len );
    }
    XSRETURN_EMPTY;
}

#if WXPERL_W_VERSION_GE( 2, 8, 5 )
#define XSubPPtmpAAAD 1


XS_EUPXS(XS_Wx__MemoryFSHandler_AddTextFileWithMimeType); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_AddTextFileWithMimeType)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "name, string, mimetype");
    {
	wxString	name;
	wxString	string;
	wxString	mimetype;

    WXSTRING_INPUT( name, wxString, ST(0) )
;

    WXSTRING_INPUT( string, wxString, ST(1) )
;

    WXSTRING_INPUT( mimetype, wxString, ST(2) )
;
    wxMemoryFSHandler::AddFileWithMimeType( name, string, mimetype );
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__MemoryFSHandler_AddBinaryFileWithMimeType); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_AddBinaryFileWithMimeType)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "name, scalar, mimetype");
    {
	wxString	name;
	SV*	scalar = ST(1)
;
	wxString	mimetype;
    STRLEN len;
    char* data = SvPV( scalar, len );

    WXSTRING_INPUT( name, wxString, ST(0) )
;

    WXSTRING_INPUT( mimetype, wxString, ST(2) )
;
    wxMemoryFSHandler::AddFileWithMimeType( name, data, len, mimetype );
    }
    XSRETURN_EMPTY;
}

#endif

XS_EUPXS(XS_Wx__MemoryFSHandler_RemoveFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__MemoryFSHandler_RemoveFile)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "name");
    {
	wxString	name;

    WXSTRING_INPUT( name, wxString, ST(0) )
;
    wxMemoryFSHandler::RemoveFile( name );
    }
    XSRETURN_EMPTY;
}

#include "cpp/fshandler.h"

XS_EUPXS(XS_Wx__PlFileSystemHandler_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__PlFileSystemHandler_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxPlFileSystemHandler *	RETVAL;
    RETVAL = new wxPlFileSystemHandler( CLASS );
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


/* INCLUDE: Returning to 'XS/FileSystem.xs' from 'XS/FileSystemHandler.xs' */

#include <wx/filesys.h>

XS_EUPXS(XS_Wx__FileSystem_new); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_new)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "CLASS");
    {
	char *	CLASS = (char *)SvPV_nolen(ST(0))
;
	wxFileSystem *	RETVAL;

	RETVAL = new wxFileSystem();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_object_2_sv( aTHX_ RETVALSV, RETVAL );
    wxPli_thread_sv_register( aTHX_ "Wx::FileSystem", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FileSystem_CLONE); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_CLONE)
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


XS_EUPXS(XS_Wx__FileSystem_DESTROY); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_DESTROY)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;
    wxPli_thread_sv_unregister( aTHX_ "Wx::FileSystem", THIS, ST(0) );
    if( wxPli_object_is_deleteable( aTHX_ ST(0) ) )
        delete THIS;
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__FileSystem_AddHandler); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_AddHandler)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "handler");
    {
	wxFileSystemHandler*    handler = (wxFileSystemHandler *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystemHandler" )
;
    wxFileSystem::AddHandler( handler );
    }
    XSRETURN_EMPTY;
}

#if WXPERL_W_VERSION_GE( 2, 7, 2 )
#define XSubPPtmpAAAE 1


XS_EUPXS(XS_Wx__FileSystem_HasHandlerForPath); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_HasHandlerForPath)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "location");
    {
	wxString	location;
	bool	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(0) )
;
    RETVAL = wxFileSystem::HasHandlerForPath( location );
	ST(0) = boolSV(RETVAL);
    }
    XSRETURN(1);
}

#endif

XS_EUPXS(XS_Wx__FileSystem_ChangePathTo); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_ChangePathTo)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "THIS, location, is_dir = false");
    {
	wxString	location;
	bool	is_dir;
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	if (items < 3)
	    is_dir = false;
	else {
	    is_dir = (bool)SvTRUE(ST(2))
;
	}

	THIS->ChangePathTo(location, is_dir);
    }
    XSRETURN_EMPTY;
}


XS_EUPXS(XS_Wx__FileSystem_GetPath); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_GetPath)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;
	wxString	RETVAL;

	RETVAL = THIS->GetPath();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FileSystem_FindFirst); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_FindFirst)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "THIS, wildcard, flags = 0");
    {
	wxString	wildcard;
	int	flags;
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;
	wxString	RETVAL;

    WXSTRING_INPUT( wildcard, wxString, ST(1) )
;

	if (items < 3)
	    flags = 0;
	else {
	    flags = (int)SvIV(ST(2))
;
	}

	RETVAL = THIS->FindFirst(wildcard, flags);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}


XS_EUPXS(XS_Wx__FileSystem_FindNext); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_FindNext)
{
    dVAR; dXSARGS;
    if (items != 1)
       croak_xs_usage(cv,  "THIS");
    {
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;
	wxString	RETVAL;

	RETVAL = THIS->FindNext();
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#if WXPERL_W_VERSION_GE( 2, 7, 2 )
#define XSubPPtmpAAAF 1


XS_EUPXS(XS_Wx__FileSystem_FindFileInPath); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_FindFileInPath)
{
    dVAR; dXSARGS;
    if (items != 3)
       croak_xs_usage(cv,  "THIS, path, file");
    {
	wxString	path;
	wxString	file;
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;
	wxString	RETVAL;

    WXSTRING_INPUT( path, wxString, ST(1) )
;

    WXSTRING_INPUT( file, wxString, ST(2) )
;
    bool ret = THIS->FindFileInPath( &RETVAL, path, file );
    if( !ret )
        XSRETURN_UNDEF;
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    WXSTRING_OUTPUT( RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#endif
#if WXPERL_W_VERSION_GE( 2, 7, 2 )
#define XSubPPtmpAAAG 1


XS_EUPXS(XS_Wx__FileSystem_OpenFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_OpenFile)
{
    dVAR; dXSARGS;
    if (items < 2 || items > 3)
       croak_xs_usage(cv,  "THIS, location, flags = wxFS_READ");
    {
	wxString	location;
	int	flags;
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;
	wxFSFile *	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	if (items < 3)
	    flags = wxFS_READ;
	else {
	    flags = (int)SvIV(ST(2))
;
	}

	RETVAL = THIS->OpenFile(location, flags);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_non_object_2_sv( aTHX_ RETVALSV, RETVAL, "Wx::FSFile" );
    wxPli_thread_sv_register( aTHX_ "Wx::FSFile", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#else
#define XSubPPtmpAAAH 1


XS_EUPXS(XS_Wx__FileSystem_OpenFile); /* prototype to pass -Wmissing-prototypes */
XS_EUPXS(XS_Wx__FileSystem_OpenFile)
{
    dVAR; dXSARGS;
    if (items != 2)
       croak_xs_usage(cv,  "THIS, location");
    {
	wxString	location;
	wxFileSystem *    THIS = (wxFileSystem *) wxPli_sv_2_object( aTHX_ ST(0), "Wx::FileSystem" )
;
	wxFSFile *	RETVAL;

    WXSTRING_INPUT( location, wxString, ST(1) )
;

	RETVAL = THIS->OpenFile(location);
	{
	    SV * RETVALSV;
	    RETVALSV = sv_newmortal();
    wxPli_non_object_2_sv( aTHX_ RETVALSV, RETVAL, "Wx::FSFile" );
    wxPli_thread_sv_register( aTHX_ "Wx::FSFile", RETVAL, RETVALSV );
	    ST(0) = RETVALSV;
	}
    }
    XSRETURN(1);
}

#endif

/* INCLUDE: Returning to 'FS.xs' from 'XS/FileSystem.xs' */

#if defined(__WXMSW__)
#undef XS
#define XS( name ) WXXS( name )
#endif
#ifdef __cplusplus
extern "C"
#endif
XS_EXTERNAL(boot_Wx__FS); /* prototype to pass -Wmissing-prototypes */
XS_EXTERNAL(boot_Wx__FS)
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

        newXS_deffile("Wx::FSFile::CLONE", XS_Wx__FSFile_CLONE);
        newXS_deffile("Wx::FSFile::DESTROY", XS_Wx__FSFile_DESTROY);
        newXS_deffile("Wx::FSFile::GetAnchor", XS_Wx__FSFile_GetAnchor);
        newXS_deffile("Wx::FSFile::GetLocation", XS_Wx__FSFile_GetLocation);
        newXS_deffile("Wx::FSFile::GetMimeType", XS_Wx__FSFile_GetMimeType);
        newXS_deffile("Wx::FSFile::GetStream", XS_Wx__FSFile_GetStream);
        newXS_deffile("Wx::FSFile::new", XS_Wx__FSFile_new);
#if XSubPPtmpAAAA
        newXS_deffile("Wx::FileSystemHandler::GetAnchor", XS_Wx__FileSystemHandler_GetAnchor);
        newXS_deffile("Wx::FileSystemHandler::GetLeftLocation", XS_Wx__FileSystemHandler_GetLeftLocation);
        newXS_deffile("Wx::FileSystemHandler::GetMimeTypeFromExt", XS_Wx__FileSystemHandler_GetMimeTypeFromExt);
        newXS_deffile("Wx::FileSystemHandler::GetProtocol", XS_Wx__FileSystemHandler_GetProtocol);
        newXS_deffile("Wx::FileSystemHandler::GetRightLocation", XS_Wx__FileSystemHandler_GetRightLocation);
#endif
#if XSubPPtmpAAAB
        newXS_deffile("Wx::InternetFSHandler::new", XS_Wx__InternetFSHandler_new);
#endif
        newXS_deffile("Wx::ZipFSHandler::new", XS_Wx__ZipFSHandler_new);
#if XSubPPtmpAAAC
        newXS_deffile("Wx::ArchiveFSHandler::new", XS_Wx__ArchiveFSHandler_new);
#endif
        newXS_deffile("Wx::MemoryFSHandler::new", XS_Wx__MemoryFSHandler_new);
        newXS_deffile("Wx::MemoryFSHandler::AddImageFile", XS_Wx__MemoryFSHandler_AddImageFile);
        newXS_deffile("Wx::MemoryFSHandler::AddBitmapFile", XS_Wx__MemoryFSHandler_AddBitmapFile);
        newXS_deffile("Wx::MemoryFSHandler::AddTextFile", XS_Wx__MemoryFSHandler_AddTextFile);
        newXS_deffile("Wx::MemoryFSHandler::AddBinaryFile", XS_Wx__MemoryFSHandler_AddBinaryFile);
#if XSubPPtmpAAAD
        newXS_deffile("Wx::MemoryFSHandler::AddTextFileWithMimeType", XS_Wx__MemoryFSHandler_AddTextFileWithMimeType);
        newXS_deffile("Wx::MemoryFSHandler::AddBinaryFileWithMimeType", XS_Wx__MemoryFSHandler_AddBinaryFileWithMimeType);
#endif
        newXS_deffile("Wx::MemoryFSHandler::RemoveFile", XS_Wx__MemoryFSHandler_RemoveFile);
        newXS_deffile("Wx::PlFileSystemHandler::new", XS_Wx__PlFileSystemHandler_new);
        newXS_deffile("Wx::FileSystem::new", XS_Wx__FileSystem_new);
        newXS_deffile("Wx::FileSystem::CLONE", XS_Wx__FileSystem_CLONE);
        newXS_deffile("Wx::FileSystem::DESTROY", XS_Wx__FileSystem_DESTROY);
        newXS_deffile("Wx::FileSystem::AddHandler", XS_Wx__FileSystem_AddHandler);
#if XSubPPtmpAAAE
        newXS_deffile("Wx::FileSystem::HasHandlerForPath", XS_Wx__FileSystem_HasHandlerForPath);
#endif
        newXS_deffile("Wx::FileSystem::ChangePathTo", XS_Wx__FileSystem_ChangePathTo);
        newXS_deffile("Wx::FileSystem::GetPath", XS_Wx__FileSystem_GetPath);
        newXS_deffile("Wx::FileSystem::FindFirst", XS_Wx__FileSystem_FindFirst);
        newXS_deffile("Wx::FileSystem::FindNext", XS_Wx__FileSystem_FindNext);
#if XSubPPtmpAAAF
        newXS_deffile("Wx::FileSystem::FindFileInPath", XS_Wx__FileSystem_FindFileInPath);
#endif
#if XSubPPtmpAAAG
        newXS_deffile("Wx::FileSystem::OpenFile", XS_Wx__FileSystem_OpenFile);
#endif
#if XSubPPtmpAAAH
        newXS_deffile("Wx::FileSystem::OpenFile", XS_Wx__FileSystem_OpenFile);
#endif

    /* Initialisation Section */

  INIT_PLI_HELPERS( wx_pli_helpers );

#if XSubPPtmpAAAA
#endif
#if XSubPPtmpAAAB
#endif
#if XSubPPtmpAAAC
#endif
#if XSubPPtmpAAAD
#endif
#if XSubPPtmpAAAE
#endif
#if XSubPPtmpAAAF
#endif
#if XSubPPtmpAAAG
#endif
#if XSubPPtmpAAAH
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
