## Strawberry Perl Install for Buddy and fileClient

For the **hardcore programmers** out there that might want to try to run
[**Buddy**](https://github.com/phorton1/base-Pub-buddy) or the
[**fileClient**](https://github.com/phorton1/base-Pub-fileClient) with
a somewhat modern available *Perl Distro*, I provide this **repo** and
these **instructions** on how to install a **WX Enabled** version of
**Strawberry Perl** with the bare minimum number of *Perl Modules*
needed to run the two programs.


### 1. Install strawberry-perl-5.32.1.1-32bit.msi

- Obtain the most recent release of [**Strawberry Perl**](https://strawberryperl.com/releases.html)
- install to **/Strawberry** on your Windows machine
- later you may want to move the Strawberry **Paths** to the top in your **ENV**,
  but for now this document does not require that.

### 2. Open a DOS box

Open a **DOS Box** on your Windows machine and set the following *minimal* **PATH**
environment variable.

	set PATH=C:\Windows\system32;C:\Windows;C:\StrawBerry\c\bin;C:\StrawBerry\perl\site\bin;C:\StrawBerry\perl\bin

### 3. Install cpan Perl Modules

These are installed by merly typing **cpan XXXX** from the DOS Box command line

- cpan Error
- cpan Date::Calc
- cpan Win32::Mutex
- cpan Win32::DriveInfo
- cpan Win32::Process
- cpan Win32::Process::List
- cpan Alien::wxWidgets - takes a 30+ minutes, compiles entire library
- cpan Wx - will fail after about 1 minute

The installation of **Wx** (wxPerl == wxWidgets) will fail.  **Don't remove
anything** and proceed to the next step.


### 4.. Building Wx

After the above fails, you will find a folder like the following on your machine:

	C:\StrawBerry\cpan\build\Wx-0.9932-0

Using any available text editor, modify **C:\StrawBerry\cpan\build\Wx-0.9932-0\cpp\wxapi.h**
and add the following around line 136.

	#undef calloc	// prh - added for Wx build

Then change to the build directory, and execute the **WX build/install** by typing the following:

	> cd C:\StrawBerry\cpan\build\Wx-0.9932-0 and
	> gmake test install

This build takes around 10 minutes and should pop up a bunch of little Windows during
the test stage.


### 5. Manual Changes

The following changes must be made manually.

#### 5a. Manually add site/lib/Cava::Packager

Download **this repo** someplace and copy the subfolder
**/Strawberry/perl/site/lib/Cava** into your Perl
installation.


#### 5b. Minor modification to Console.pm

Open **/Strawberry/perl/vendor/lib/Win32/Console.pm** in a text editor
and comment out the line where the Console closes itself in DESTROY.
This is around line 603 in the file.

		# prh - magic solution to my thread/fork problems
		# comment out the following line
		# _CloseHandle($self->{'handle'});

This solved **many** problems when using Win32::Console with
threads and forks, as otherwise, exiting a thread/fork will
**close** the Console stopping all further output to STDOUT.

####  5c. Minor modification to ComPort.pm.

I'm not sure this is abolutely necessary, but from my legacy
code, I modified **/Strawberry/perl/vendor/lib/Win32Api/ComPort.pm**
to increase the buffer buffer size around **line 54**

		# prh - increase buffer size
		# our $RBUF_Size = 4096;
		our $RBUF_Size = 16384;


### 6. Install and test the WX Perl

Download (or clone) my
[**Pub**](https://github.com/phorton1/base-Pub) repository
somewhere on your machine.  You *could* clone it directly
into */Strawbery/perl/site/lib* but I prefer to keep my
source code **out** of the Perl distro folders, so I
put it in a folder called **base** at the root of my
Windows C: drive, and set a **PERLLIB** environment
variable to allow Perl to find it.

	C> mkdir \base
	C> cd \base
	C> git clone https://github.com/phorton1/base-Pub Pub
	C> set PERLLIB=/base

At this point you should be able to test the **mimimum application**
included in **Pub::WX**.

	C> cd \base\Pub\WX\examples\minimum
	C> Perl minimum.pm

A small example WX Gui application should pop up, showing
that the Perl and WxPerl (wxWidgets) are working.

### 7. Install and test Buddy and fileClient

You may now clone or download the **Buddy** and/or
**fileClient** Perl source code into the **Pub** folder

	C> cd \base\Pub
	C> git clone https://github.com/phorton1/base-Pub-buddy buddy
	C> git clone https://github.com/phorton1/base-Pub-fileClient fileClient

Assuming you have an Arduino or something else connected to **COM3** you
can test **Buddy** by typing the following

	C> cd \base\Pub\buddy
	C> perl buddy.pm 3 115200 -arduino -file_server

And you can test fileClient by either hitting **CTRL-E** from the
Buddy window, or by explicitly invoking it as follows

	C> cd \base\Pub\fileClient
	C> perl fileClient.pm


### 8. Summary

Please see the following repos for more information

- [**Pub**](https://github.com/phorton1/base-Pub) - My **Pub** repository, which includes Pub::WX and Pub::FS Perl classes.
- [**Buddy**](https://github.com/phorton1/base-Pub-buddy) - the source code for **Buddy**
- [**fileClient**](https://github.com/phorton1/base-Pub-fileClient) - the source code for the **fileClient**


If you are going to seriously continue using this Strawberry
Perl installation, you will probably want to go to the **ENV**
variables in Windows, and move the following paths towards
the top of the list of PATHS on your machine

- C:\StrawBerry\c\bin;
- C:\StrawBerry\perl\site\bin;
- C:\StrawBerry\perl\bin



### 9. Notes

The ONLY Cava::Packager v2.0.80.693 will NOT WORK with
strawberry-perl-5.32.1.1-32bit.msi, which reports: perl -v

````
   This is perl 5, version 32, subversion 1 (v5.32.1) built for MSWin32-x86-multi-thread-64int
````

Hence, I could not effectively publish how I build and release
the Windows installer for Buddy

Someday I might write a **Perl Packager** to replace **Cava**.
It would be hard.


----- end of readme -----
