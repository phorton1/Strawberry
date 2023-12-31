$dbd_oracle_mm_opts = {
                        'clean' => {
                                     'FILES' => 'xstmp.c Oracle.xsi dll.base dll.exp sqlnet.log libOracle.def mk.pm DBD_ORA_OBJ.*'
                                   },
                        'META_MERGE' => {
                                          'resources' => {
                                                           'repository' => {
                                                                             'type' => 'git',
                                                                             'web' => 'http://github.com/yanick/DBD-Oracle/tree',
                                                                             'url' => 'git://github.com/yanick/DBD-Oracle.git'
                                                                           },
                                                           'bugtracker' => 'https://github.com/perl5-dbi/DBD-Oracle/issues',
                                                           'homepage' => 'https://metacpan.org/pod/DBD::Oracle'
                                                         },
                                          'build_requires' => {
                                                                'Test::Simple' => '0.90',
                                                                'ExtUtils::MakeMaker' => 0,
                                                                'DBI' => '1.623'
                                                              },
                                          'configure_requires' => {
                                                                    'DBI' => '1.623'
                                                                  }
                                        },
                        'VERSION_FROM' => 'lib/DBD/Oracle.pm',
                        'OBJECT' => '$(O_FILES)',
                        'DIR' => [],
                        'DEFINE' => ' -Wall -Wno-comment -DUTF8_SUPPORT -DORA_OCI_VERSION=\\"12.2.0.1.0\\" -DORA_OCI_102 -DORA_OCI_112',
                        'INC' => '-IC:/ora122instant32/sdk/include -IC:/ora122instant32/rdbms/demo -IC:\\strawberry\\perl\\vendor\\lib\\auto\\DBI',
                        'PREREQ_PM' => {
                                         'DBI' => '1.623'
                                       },
                        'ABSTRACT_FROM' => 'lib/DBD/Oracle.pm',
                        'LIBS' => [
                                    '-LC:/STRAWB~1/env/USERPR~1/.cpanm/work/1611492600.2704/DBD-Oracle-1.80 -loci'
                                  ],
                        'LICENSE' => 'perl',
                        'NAME' => 'DBD::Oracle',
                        'AUTHOR' => 'Tim Bunce (dbi-users@perl.org)',
                        'dist' => {
                                    'PREOP' => '$(MAKE) -f Makefile.old distdir',
                                    'DIST_DEFAULT' => 'clean distcheck disttest tardist',
                                    'COMPRESS' => 'gzip -v9',
                                    'SUFFIX' => 'gz'
                                  }
                      };
$dbd_oracle_mm_self = bless( {
                               'INSTALLVENDORMAN3DIR' => '$(INSTALLMAN3DIR)',
                               'USEMAKEFILE' => '-f',
                               'ECHO' => '$(ABSPERLRUN) -l -e "binmode STDOUT, qq{:raw}; print qq{@ARGV}" --',
                               'DEV_NULL' => '> NUL',
                               'INSTALLVENDORARCH' => 'C:\\strawberry\\perl\\vendor\\lib',
                               'MM_REVISION' => 75800,
                               'UMASK_NULL' => 'umask 0',
                               'MOD_INSTALL' => '$(ABSPERLRUN) -MExtUtils::Install -e "install([ from_to => {@ARGV}, verbose => \'$(VERBINST)\', uninstall_shadows => \'$(UNINST)\', dir_mode => \'$(PERM_DIR)\' ]);" --',
                               'POSTOP' => '$(NOECHO) $(NOOP)',
                               'ARGS' => {
                                           'clean' => $dbd_oracle_mm_opts->{'clean'},
                                           'INC' => '-IC:/ora122instant32/sdk/include -IC:/ora122instant32/rdbms/demo -IC:\\strawberry\\perl\\vendor\\lib\\auto\\DBI',
                                           'VERSION_FROM' => 'lib/DBD/Oracle.pm',
                                           'OBJECT' => '$(O_FILES)',
                                           'AUTHOR' => [
                                                         'Tim Bunce (dbi-users@perl.org)'
                                                       ],
                                           'LICENSE' => 'perl',
                                           'LIBS' => $dbd_oracle_mm_opts->{'LIBS'},
                                           'META_MERGE' => $dbd_oracle_mm_opts->{'META_MERGE'},
                                           'DEFINE' => ' -Wall -Wno-comment -DUTF8_SUPPORT -DORA_OCI_VERSION=\\"12.2.0.1.0\\" -DORA_OCI_102 -DORA_OCI_112',
                                           'INSTALLDIRS' => 'vendor',
                                           'DIR' => $dbd_oracle_mm_opts->{'DIR'},
                                           'ABSTRACT_FROM' => 'lib/DBD/Oracle.pm',
                                           'PREREQ_PM' => $dbd_oracle_mm_opts->{'PREREQ_PM'},
                                           'UNINST' => '1',
                                           'dist' => $dbd_oracle_mm_opts->{'dist'},
                                           'NAME' => 'DBD::Oracle'
                                         },
                               'INSTALLMAN1DIR' => 'none',
                               'INSTALLSITEARCH' => 'C:\\strawberry\\perl\\site\\lib',
                               'MAN1EXT' => '1',
                               'DESTINSTALLSITEARCH' => '$(DESTDIR)$(INSTALLSITEARCH)',
                               'UNINSTALL' => '$(ABSPERLRUN) -MExtUtils::Command::MM -e uninstall --',
                               'PERL_LIB' => 'C:\\strawberry\\perl\\lib',
                               'SITEPREFIX' => 'C:\\strawberry\\perl\\site',
                               'PERL_ARCHLIB' => 'C:\\strawberry\\perl\\lib',
                               'MAKE_APERL_FILE' => 'Makefile.aperl',
                               'PERL' => '"C:\\strawberry\\perl\\bin\\perl.exe"',
                               'NOOP' => 'rem',
                               'CP_NONEMPTY' => '$(ABSPERLRUN) -MExtUtils::Command::MM -e cp_nonempty --',
                               'PERLMAINCC' => '$(CC)',
                               'TARFLAGS' => 'cvf',
                               'WARN_IF_OLD_PACKLIST' => '$(ABSPERLRUN) -MExtUtils::Command::MM -e warn_if_old_packlist --',
                               'MAN1SECTION' => 1,
                               'DLBASE' => '$(BASEEXT)',
                               'DESTINSTALLVENDORBIN' => '$(DESTDIR)$(INSTALLVENDORBIN)',
                               'FULLPERL' => '"C:\\strawberry\\perl\\bin\\perl.exe"',
                               'LICENSE' => 'perl',
                               'XS_VERSION_MACRO' => 'XS_VERSION',
                               'OBJ_EXT' => '.o',
                               'TEST_REQUIRES' => {},
                               'INC' => '-IC:/ora122instant32/sdk/include -IC:/ora122instant32/rdbms/demo -IC:\\strawberry\\perl\\vendor\\lib\\auto\\DBI',
                               'SITELIBEXP' => 'C:\\strawberry\\perl\\site\\lib',
                               'DESTINSTALLVENDORARCH' => '$(DESTDIR)$(INSTALLVENDORARCH)',
                               'EXTRALIBS' => '"liboci.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libmoldname.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libkernel32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libuser32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libgdi32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libwinspool.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libcomdlg32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libadvapi32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libshell32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libole32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\liboleaut32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libnetapi32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libuuid.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libws2_32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libmpr.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libwinmm.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libversion.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libodbc32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libodbccp32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libcomctl32.a"',
                               'INSTALLPRIVLIB' => 'C:\\strawberry\\perl\\lib',
                               'TAR' => 'tar',
                               'LD' => 'g++',
                               'VERSION_MACRO' => 'VERSION',
                               'INSTALLDIRS' => 'vendor',
                               'ABSTRACT_FROM' => 'lib/DBD/Oracle.pm',
                               'INST_AUTODIR' => '$(INST_LIB)\\auto\\$(FULLEXT)',
                               'VERSION_SYM' => '1_80',
                               'COMPRESS' => 'gzip --best',
                               'PERM_RWX' => 755,
                               'O_FILES' => [
                                              'Oracle.o',
                                              'dbdimp.o',
                                              'oci8.o'
                                            ],
                               'INST_STATIC' => '$(INST_ARCHAUTODIR)\\$(BASEEXT)$(LIB_EXT)',
                               'DESTINSTALLVENDORMAN3DIR' => '$(DESTDIR)$(INSTALLVENDORMAN3DIR)',
                               'INSTALLARCHLIB' => 'C:\\strawberry\\perl\\lib',
                               'CHMOD' => '$(ABSPERLRUN) -MExtUtils::Command -e chmod --',
                               'FIRST_MAKEFILE' => 'Makefile',
                               'LDFLAGS' => '-s -L"C:\\strawberry\\perl\\lib\\CORE" -L"C:\\strawberry\\c\\lib"',
                               'INST_LIBDIR' => '$(INST_LIB)\\DBD',
                               'DIR' => $dbd_oracle_mm_opts->{'DIR'},
                               'PERLRUN' => '$(PERL)',
                               'INST_ARCHLIB' => 'blib\\arch',
                               'MAN3EXT' => '3',
                               'DIRFILESEP' => '/',
                               'FULLEXT' => 'DBD\\Oracle',
                               'MM_Win32_VERSION' => '7.58',
                               'MAP_TARGET' => 'perl',
                               'DESTINSTALLVENDORLIB' => '$(DESTDIR)$(INSTALLVENDORLIB)',
                               'INST_LIB' => 'blib\\lib',
                               'LIB_EXT' => '.a',
                               'TEST_S' => '$(ABSPERLRUN) -MExtUtils::Command::MM -e test_s --',
                               'DESTINSTALLBIN' => '$(DESTDIR)$(INSTALLBIN)',
                               'MAKEFILE_OLD' => 'Makefile.old',
                               'OSVERS' => '10.0.19042.746',
                               'TRUE' => '$(ABSPERLRUN)  -e "exit 0" --',
                               'LD_RUN_PATH' => '',
                               'MM_VERSION' => '7.58',
                               'XS_DEFINE_VERSION' => '-D$(XS_VERSION_MACRO)=\\"$(XS_VERSION)\\"',
                               'INSTALLSITESCRIPT' => 'C:\\strawberry\\perl\\site\\bin',
                               'DISTVNAME' => 'DBD-Oracle-1.80',
                               'EXPORT_LIST' => '$(BASEEXT).def',
                               'DESTINSTALLSITELIB' => '$(DESTDIR)$(INSTALLSITELIB)',
                               'CCDLFLAGS' => ' ',
                               'INST_DYNAMIC' => '$(INST_ARCHAUTODIR)\\$(DLBASE).$(DLEXT)',
                               'NAME' => 'DBD::Oracle',
                               'TO_UNIX' => '$(NOECHO) $(NOOP)',
                               'DESTINSTALLSITEMAN1DIR' => '$(DESTDIR)$(INSTALLSITEMAN1DIR)',
                               'DESTINSTALLSITEMAN3DIR' => '$(DESTDIR)$(INSTALLSITEMAN3DIR)',
                               'RANLIB' => 'rem',
                               'INST_ARCHLIBDIR' => '$(INST_ARCHLIB)\\DBD',
                               'SHAR' => 'shar',
                               'PERL_CORE' => 0,
                               'DESTINSTALLSITESCRIPT' => '$(DESTDIR)$(INSTALLSITESCRIPT)',
                               'SUFFIX' => '.gz',
                               'PERL_ARCHLIBDEP' => 'C:\\strawberry\\perl\\lib',
                               'BUILD_REQUIRES' => {},
                               'LDLOADLIBS' => '"liboci.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libmoldname.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libkernel32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libuser32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libgdi32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libwinspool.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libcomdlg32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libadvapi32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libshell32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libole32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\liboleaut32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libnetapi32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libuuid.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libws2_32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libmpr.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libwinmm.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libversion.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libodbc32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libodbccp32.a" "C:\\strawberry\\c\\i686-w64-mingw32\\lib\\libcomctl32.a"',
                               'CI' => 'ci -u',
                               'DIST_DEFAULT' => 'tardist',
                               'RM_RF' => '$(ABSPERLRUN) -MExtUtils::Command -e rm_rf --',
                               'VERBINST' => 0,
                               'INST_MAN1DIR' => 'blib\\man1',
                               'OBJECT' => '$(O_FILES)',
                               'VERSION' => '1.80',
                               'PREFIX' => '$(VENDORPREFIX)',
                               'INSTALLMAN3DIR' => 'none',
                               'AUTHOR' => $dbd_oracle_mm_self->{'ARGS'}{'AUTHOR'},
                               'DLSRC' => 'dl_win32.xs',
                               'INSTALLSITEBIN' => 'C:\\strawberry\\perl\\site\\bin',
                               'SO' => 'dll',
                               'DLEXT' => 'xs.dll',
                               'CONFIG' => [
                                             'ar',
                                             'cc',
                                             'cccdlflags',
                                             'ccdlflags',
                                             'dlext',
                                             'dlsrc',
                                             'exe_ext',
                                             'full_ar',
                                             'ld',
                                             'lddlflags',
                                             'ldflags',
                                             'libc',
                                             'lib_ext',
                                             'obj_ext',
                                             'osname',
                                             'osvers',
                                             'ranlib',
                                             'sitelibexp',
                                             'sitearchexp',
                                             'so',
                                             'vendorarchexp',
                                             'vendorlibexp'
                                           ],
                               'DESTINSTALLSCRIPT' => '$(DESTDIR)$(INSTALLSCRIPT)',
                               'MAN3SECTION' => 3,
                               'PERM_DIR' => 755,
                               'PERL_SRC' => undef,
                               'BASEEXT' => 'Oracle',
                               'DIST_CP' => 'best',
                               'PMLIBPARENTDIRS' => [
                                                      'lib'
                                                    ],
                               'PERL_INCDEP' => 'C:\\strawberry\\perl\\lib\\CORE',
                               'INST_SCRIPT' => 'blib\\script',
                               'RM_F' => '$(ABSPERLRUN) -MExtUtils::Command -e rm_f --',
                               'PERLRUNINST' => '$(PERLRUN) "-I$(INST_ARCHLIB)" "-I$(INST_LIB)"',
                               'INSTALLVENDORMAN1DIR' => '$(INSTALLMAN1DIR)',
                               'UNINST' => '1',
                               'MKPATH' => '$(ABSPERLRUN) -MExtUtils::Command -e mkpath --',
                               'PARENT_NAME' => 'DBD',
                               'clean' => $dbd_oracle_mm_opts->{'clean'},
                               'PERLPREFIX' => 'C:\\strawberry\\perl',
                               'INSTALLSCRIPT' => 'C:\\strawberry\\perl\\bin',
                               'VERSION_FROM' => 'lib/DBD/Oracle.pm',
                               'PREOP' => '$(NOECHO) $(NOOP)',
                               'VENDORARCHEXP' => 'C:\\strawberry\\perl\\vendor\\lib',
                               'PERL_ARCHIVE' => '$(PERL_INC)\\libperl532.a',
                               'INSTALLSITELIB' => 'C:\\strawberry\\perl\\site\\lib',
                               'DISTNAME' => 'DBD-Oracle',
                               'DEFINE' => ' -Wall -Wno-comment -DUTF8_SUPPORT -DORA_OCI_VERSION=\\"12.2.0.1.0\\" -DORA_OCI_102 -DORA_OCI_112',
                               'FULL_AR' => '',
                               'AR' => 'ar',
                               'PREREQ_PM' => {
                                                'DBI' => '1.623'
                                              },
                               'INSTALLVENDORLIB' => 'C:\\strawberry\\perl\\vendor\\lib',
                               'FULLPERLRUN' => '$(FULLPERL)',
                               'DESTINSTALLVENDORMAN1DIR' => '$(DESTDIR)$(INSTALLVENDORMAN1DIR)',
                               'MAN3PODS' => {},
                               'BOOTDEP' => '',
                               'H' => [
                                        'Oracle.h',
                                        'dbdimp.h',
                                        'dbivport.h',
                                        'ocitrace.h'
                                      ],
                               'CONFIGURE_REQUIRES' => {},
                               'NAME_SYM' => 'DBD_Oracle',
                               'PL_FILES' => {},
                               'BSLOADLIBS' => '',
                               'META_MERGE' => $dbd_oracle_mm_opts->{'META_MERGE'},
                               'MAKEFILE' => 'Makefile',
                               'PERL_INC' => 'C:\\strawberry\\perl\\lib\\CORE',
                               'LDFROM' => '$(OBJECT)',
                               'DESTDIR' => '',
                               'ABSTRACT' => 'Oracle database driver for the DBI module',
                               'NOECHO' => '@',
                               'PMLIBDIRS' => [
                                                'lib'
                                              ],
                               'LDDLFLAGS' => '-mdll -s -L"C:\\strawberry\\perl\\lib\\CORE" -L"C:\\strawberry\\c\\lib"',
                               'AR_STATIC_ARGS' => 'cr',
                               'SITEARCHEXP' => 'C:\\strawberry\\perl\\site\\lib',
                               'INSTALLBIN' => 'C:\\strawberry\\perl\\bin',
                               'XS_VERSION' => '1.80',
                               'SKIPHASH' => {},
                               'XS' => {
                                         'Oracle.xs' => 'Oracle.c'
                                       },
                               'DESTINSTALLMAN3DIR' => '$(DESTDIR)$(INSTALLMAN3DIR)',
                               'INST_BIN' => 'blib\\bin',
                               'C' => [
                                        'Oracle.c',
                                        'dbdimp.c',
                                        'oci8.c'
                                      ],
                               'LIBS' => $dbd_oracle_mm_opts->{'LIBS'},
                               'ABSPERL' => '$(PERL)',
                               'DOC_INSTALL' => '$(ABSPERLRUN) -MExtUtils::Command::MM -e perllocal_install --',
                               'FALSE' => '$(ABSPERLRUN)  -e "exit 1" --',
                               'RESULT' => [
                                             '# This Makefile is for the DBD::Oracle extension to perl.
#
# It was generated automatically by MakeMaker version
# 7.58 (Revision: 75800) from the contents of
# Makefile.PL. Don\'t edit this file, edit Makefile.PL instead.
#
#       ANY CHANGES MADE HERE WILL BE LOST!
#
#   MakeMaker ARGV: ()
#
',
                                             '#   MakeMaker Parameters:
',
                                             '#     ABSTRACT_FROM => q[lib/DBD/Oracle.pm]',
                                             '#     AUTHOR => [q[Tim Bunce (dbi-users@perl.org)]]',
                                             '#     BUILD_REQUIRES => {  }',
                                             '#     CONFIGURE_REQUIRES => {  }',
                                             '#     DEFINE => q[ -Wall -Wno-comment -DUTF8_SUPPORT -DORA_OCI_VERSION=\\"12.2.0.1.0\\" -DORA_OCI_102 -DORA_OCI_112]',
                                             '#     DIR => []',
                                             '#     INC => q[-IC:/ora122instant32/sdk/include -IC:/ora122instant32/rdbms/demo -IC:\\strawberry\\perl\\vendor\\lib\\auto\\DBI]',
                                             '#     LIBS => [q[-LC:/STRAWB~1/env/USERPR~1/.cpanm/work/1611492600.2704/DBD-Oracle-1.80 -loci]]',
                                             '#     LICENSE => q[perl]',
                                             '#     META_MERGE => { build_requires=>{ DBI=>q[1.623], ExtUtils::MakeMaker=>q[0], Test::Simple=>q[0.90] }, configure_requires=>{ DBI=>q[1.623] }, resources=>{ bugtracker=>q[https://github.com/perl5-dbi/DBD-Oracle/issues], homepage=>q[https://metacpan.org/pod/DBD::Oracle], repository=>{ type=>q[git], url=>q[git://github.com/yanick/DBD-Oracle.git], web=>q[http://github.com/yanick/DBD-Oracle/tree] } } }',
                                             '#     NAME => q[DBD::Oracle]',
                                             '#     OBJECT => q[$(O_FILES)]',
                                             '#     PREREQ_PM => { DBI=>q[1.623] }',
                                             '#     TEST_REQUIRES => {  }',
                                             '#     VERSION_FROM => q[lib/DBD/Oracle.pm]',
                                             '#     clean => { FILES=>q[xstmp.c Oracle.xsi dll.base dll.exp sqlnet.log libOracle.def mk.pm DBD_ORA_OBJ.*] }',
                                             '#     dist => { COMPRESS=>q[gzip -v9], DIST_DEFAULT=>q[clean distcheck disttest tardist], PREOP=>q[$(MAKE) -f Makefile.old distdir], SUFFIX=>q[gz] }',
                                             '
# --- MakeMaker post_initialize section:'
                                           ],
                               'INST_BOOT' => '$(INST_ARCHAUTODIR)\\$(BASEEXT).bs',
                               'DESTINSTALLMAN1DIR' => '$(DESTDIR)$(INSTALLMAN1DIR)',
                               'ABSPERLRUN' => '$(ABSPERL)',
                               'MAKEMAKER' => 'C:/strawberry/perl/lib/ExtUtils/MakeMaker.pm',
                               'EQUALIZE_TIMESTAMP' => '$(ABSPERLRUN) -MExtUtils::Command -e eqtime --',
                               'CC' => 'gcc',
                               'MV' => '$(ABSPERLRUN) -MExtUtils::Command -e mv --',
                               'INSTALLVENDORSCRIPT' => 'C:\\strawberry\\perl\\bin',
                               'RCS_LABEL' => 'rcs -Nv$(VERSION_SYM): -q',
                               'PERM_RW' => 644,
                               'INST_MAN3DIR' => 'blib\\man3',
                               'INSTALLSITEMAN3DIR' => '$(INSTALLMAN3DIR)',
                               'FULLPERLRUNINST' => '$(FULLPERLRUN) "-I$(INST_ARCHLIB)" "-I$(INST_LIB)"',
                               'ABSPERLRUNINST' => '$(ABSPERLRUN) "-I$(INST_ARCHLIB)" "-I$(INST_LIB)"',
                               'DESTINSTALLSITEBIN' => '$(DESTDIR)$(INSTALLSITEBIN)',
                               'FIXIN' => 'pl2bat.bat',
                               'ZIPFLAGS' => '-r',
                               'HAS_LINK_CODE' => 1,
                               'MACROSTART' => '',
                               'PERL_ARCHIVE_AFTER' => '',
                               'DEFINE_VERSION' => '-D$(VERSION_MACRO)=\\"$(VERSION)\\"',
                               'PM' => {
                                         'lib/DBD/Oracle/Troubleshooting.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting.pod',
                                         'lib/DBD/Oracle/Troubleshooting/Vms.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Vms.pod',
                                         'lib/DBD/Oracle/Object.pm' => 'blib\\lib\\DBD\\Oracle\\Object.pm',
                                         'lib/DBD/Oracle/Troubleshooting/Hpux.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Hpux.pod',
                                         'lib/DBD/Oracle/Troubleshooting/Macos.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Macos.pod',
                                         'lib/DBD/Oracle/GetInfo.pm' => 'blib\\lib\\DBD\\Oracle\\GetInfo.pm',
                                         'lib/DBD/Oracle/Troubleshooting/Linux.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Linux.pod',
                                         'mk.pm' => '$(INST_LIB)\\DBD\\mk.pm',
                                         'lib/DBD/Oracle/Troubleshooting/Win32.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Win32.pod',
                                         'lib/DBD/Oracle/Troubleshooting/Cygwin.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Cygwin.pod',
                                         'lib/DBD/Oracle/Troubleshooting/Win64.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Win64.pod',
                                         'lib/DBD/Oracle.pm' => 'blib\\lib\\DBD\\Oracle.pm',
                                         'lib/DBD/Oracle/Troubleshooting/Sun.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Sun.pod',
                                         'lib/DBD/Oracle/Troubleshooting/Aix.pod' => 'blib\\lib\\DBD\\Oracle\\Troubleshooting\\Aix.pod'
                                       },
                               'VENDORPREFIX' => 'C:\\strawberry\\perl\\vendor',
                               'CP' => '$(ABSPERLRUN) -MExtUtils::Command -e cp --',
                               'LINKTYPE' => 'dynamic',
                               'PERL_ARCHIVEDEP' => '$(PERL_INCDEP)\\libperl532.a',
                               'OSNAME' => 'MSWin32',
                               'ECHO_N' => '$(ABSPERLRUN)  -e "print qq{@ARGV}" --',
                               'LIBPERL_A' => 'libperl.a',
                               'MAKE' => 'gmake',
                               'DESTINSTALLARCHLIB' => '$(DESTDIR)$(INSTALLARCHLIB)',
                               'TEST_F' => '$(ABSPERLRUN) -MExtUtils::Command -e test_f --',
                               'dist' => $dbd_oracle_mm_opts->{'dist'},
                               'TOUCH' => '$(ABSPERLRUN) -MExtUtils::Command -e touch --',
                               'DESTINSTALLVENDORSCRIPT' => '$(DESTDIR)$(INSTALLVENDORSCRIPT)',
                               'INSTALLVENDORBIN' => 'C:\\strawberry\\perl\\bin',
                               'INSTALLSITEMAN1DIR' => '$(INSTALLMAN1DIR)',
                               'ZIP' => 'zip',
                               'INST_ARCHAUTODIR' => '$(INST_ARCHLIB)\\auto\\$(FULLEXT)',
                               'VENDORLIBEXP' => 'C:\\strawberry\\perl\\vendor\\lib',
                               'EXE_EXT' => '.exe',
                               'LIBC' => '',
                               'CCCDLFLAGS' => ' ',
                               'DESTINSTALLPRIVLIB' => '$(DESTDIR)$(INSTALLPRIVLIB)',
                               'MACROEND' => '',
                               'MAN1PODS' => {}
                             }, 'PACK001' );
