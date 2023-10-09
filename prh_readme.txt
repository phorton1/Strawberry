Strawberry Perl Install

1. strawberry-perl-5.32.1.1-32bit.msi

	- install to /Strawberry

	later ENV Move System StrawBerry Perl paths above all others

	- but not the /Strawberry/c which stays at end

2. DOS box

	set PATH=C:\Windows\system32;C:\Windows;C:\StrawBerry\c\bin;C:\StrawBerry\perl\site\bin;C:\StrawBerry\perl\bin

3. Modules

	- cpan Error
	- cpan Date::Calc
	- cpan Win32::Mutex
	- cpan Win32::DriveInfo
	- cpan Win32::Process
	- cpan Win32::Process::List
	- cpan Alien::wxWidgets - takes a 30+ minutes, compiles entire library
	- cpan Wx - will fail after about 1 minute

4. Building Wx

	After the above fails, you will find a folder like:

		C:\StrawBerry\cpan\build\Wx-0.9932-0

	Modify C:\StrawBerry\cpan\build\Wx-0.9932-0\cpp\wxapi.h and add the following:

		#undef calloc	// prh - added for Wx build

	around line 136. Then

		> cd C:\StrawBerry\cpan\build\Wx-0.9932-0 and
		> gmake test install

	takes around 10 minutes

5. Manual Changes

	5a. Manually add site/lib/Cava::Packager

	5b. /Strawberry/perl/vendor/lib/Win32/Console.pm

		don't close itself around line 603

		# prh - magic solution to my thread/fork problems
		# comment out the following line
		# _CloseHandle($self->{'handle'});

	5c. /Strawberry/perl/vendor/lib/Win32Api/ComPort.pm

		increase buffer size around line 54

		# prh - increase buffer size
		# our $RBUF_Size = 4096;
		our $RBUF_Size = 15384;


6. /base/Pub/WX/examples/minimum/minimum.pm runs ...

 - No floating frame
 - base WX::NoteBoook::SavePerspective not implemented


7. "perl buddy.pm 3 -arduino -file_server -crlf"

8. fileClient from buddy

	"SerialSession(0) connect timeout" ...

	I think the problem is the baud rate 115200 or other changes
	I made to Win32 on my Perl

	/perl/lib/Win32 stuff is in /perl/vendor/lib/Win32 on Strawberry
