@rem = '--*-Perl-*--
@set "ErrorLevel="
@if "%OS%" == "Windows_NT" @goto WinNT
@perl -x -S "%0" %1 %2 %3 %4 %5 %6 %7 %8 %9
@set ErrorLevel=%ErrorLevel%
@goto endofperl
:WinNT
@perl -x -S %0 %*
@set ErrorLevel=%ErrorLevel%
@if NOT "%COMSPEC%" == "%SystemRoot%\system32\cmd.exe" @goto endofperl
@if %ErrorLevel% == 9009 @echo You do not have Perl in your PATH.
@goto endofperl
@rem ';
#!C:\StrawBerry\perl\bin\perl.exe -w
#line 16
#############################################################################
## Name:        script/xspp
## Purpose:     XS++ preprocessor
## Author:      Mattia Barbon
## Modified by:
## Created:     01/03/2003
## RCS-ID:      $Id: wxperl_xspp 2334 2008-01-21 22:38:57Z mbarbon $
## Copyright:   (c) 2003-2004, 2006, 2008 Mattia Barbon
## Licence:     This program is free software; you can redistribute it and/or
##              modify it under the same terms as Perl itself
#############################################################################

use strict;

=head1 NAME

xspp - XS++ preprocessor

=head1 SYNOPSIS

    xspp [--typemap=typemap.xsp [--typemap=typemap2.xsp]]
         [--xsubpp[=/path/to/xsubpp] [--xsubpp-args="xsubpp args"]
         Foo.xsp

or

    perl -MExtUtils::XSpp::Cmd -e xspp -- <xspp options and arguments>

=head1 DOCUMENTATION

See L<ExtUtils::XSpp>.

=cut

use ExtUtils::XSpp::Cmd;

exit xspp;
__END__
:endofperl
@set "ErrorLevel=" & @goto _undefined_label_ 2>NUL || @"%COMSPEC%" /d/c @exit %ErrorLevel%
