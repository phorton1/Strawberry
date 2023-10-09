#########################################################################################
# Package       Cava::Packager::Release
# Description:  Runtime Rule Modification
# Created       Tue Oct 26 10:08:44 2010
# SVN Id        $Id: Release.pm 1282 2011-05-11 19:59:48Z Mark Dootson $
# Copyright:    Copyright (c) 2010 Mark Dootson
# Licence:      This program is free software; you can redistribute it 
#               and/or modify it under the same terms as Perl itself
#########################################################################################

package Cava::Packager::Release;

#########################################################################################

use strict;
use warnings;
use Storable;
require Exporter;
use base qw( Exporter );

our $VERSION = '2.10';

our $__sfile;

sub __init {
    $__sfile = $ARGV[1];
    die 'Release data file not available.' if !-f $__sfile;
}

sub new {
    my $class = shift;
    my $self = bless {}, $class;
    $self->{_cp_releasedata} = Storable::lock_retrieve($__sfile);
    return $self;
}

sub get_version_string { $_[0]->{_cp_releasedata}->{version_string}; }
sub get_version_major { $_[0]->{_cp_releasedata}->{version_major}; }
sub get_version_minor { $_[0]->{_cp_releasedata}->{version_minor}; }
sub get_version_release { $_[0]->{_cp_releasedata}->{version_release}; }
sub get_version_build { $_[0]->{_cp_releasedata}->{version_build}; }
sub get_product_name { $_[0]->{_cp_releasedata}->{productname}; }
sub get_vendor { $_[0]->{_cp_releasedata}->{vendor}; }
sub get_copyright { $_[0]->{_cp_releasedata}->{copyright}; }
sub get_comments { $_[0]->{_cp_releasedata}->{comments}; }
sub get_trademarks { $_[0]->{_cp_releasedata}->{trademarks}; }
sub get_release_path { $_[0]->{_cp_releasedata}->{apppath}; }
sub get_bin_path { $_[0]->{_cp_releasedata}->{binpath}; }
sub get_dll_path { $_[0]->{_cp_releasedata}->{dllpath}; }

&__init;

1;
