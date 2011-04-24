{ binding of Nokia's Sofia-SIP headers into FreePascal

  Copyright (C) 2011 Ido Kanner idokan at@at gmail.com

  This library is free software; you can redistribute it and/or modify it
  under the terms of the GNU Library General Public License as published by
  the Free Software Foundation; either version 2 of the License, or (at your
  option) any later version.

  This program is distributed in the hope that it will be useful, but WITHOUT
  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE. See the GNU Library General Public License
  for more details.

  You should have received a copy of the GNU Library General Public License
  along with this library; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
}

{

To define symbol to FPC use the -d like so:
  -dUSE_GLIB

To undifne symbol to FPC use the -u like so:
  -uUSE_WINSOCK2

Possible defines:
  - COMPAT_1_12_0   - Make code competible with 1.12.0
  - USE_GLIB        - Link glib as well
  - USE_WINSOCK2    - Link Winsock2 instead of the old winsock. defined by
                      default.
  - SU_HAVE_BSDSOCK - If the library was created with BSD sockets. defined by
                      default for BSD/Linux.

}

unit sofia_sip;
{$IFDEF FPC}
  {$mode fpc}      // no need for object oriented here
  {$PACKRECORDS C} // make it competible with C ABI
  {$MACRO ON}      // ALLOW DEFINE SYMBOLE := VALUE
  {$IFDEF UNIX}
    {$CALLING CDECL} // On Unix we use CDECL calling convention
    {$IF defined(LINUX) or defined(BSD)}
      {$DEFINE SU_HAVE_BSDSOCK}
    {$ENDIF}
  {$ENDIF}
  {$IFDEF WINDOWS}
    {$CALLING STDCALL} // On Windows we use STDCALL calling convention
    {$DEFINE USE_WINSOCK2}
  {$ENDIF}
{$ELSE}
  Unsupported compiler
{$ENDIF}

interface

uses
  ctypes, OpenSSL
  {$IFDEF Unix}
  //, Unix, unixtype
  {$ENDIF}
  {$IFDEF WINDOWS}
    // Use winsock(2) for the constant, not sure that is really needed
    // I might remove it in the feature.
    {$IFDEF USE_WINSOCK2}winsock2{$ELSE}winsock{$ENDIF}
  {$ENDIF};

const
  LIBSOFIA     = 'libsofia-sip-ua';
{$IFDEF USE_GLIB}
  LIBSOFIAGLIB = 'libsofia-sip-ua-glib';
{$ENDIF}

type
{$IFDEF COMPAT_1_12_0}
  csize_t  = cint;
{$ELSE}
{$ENDIF}
  cusize_t = cuint;
  isize_t  = csize_t;
  issize_t = csize_t;
  usize_t  = cuint;

{$include sui.inc}


implementation

end.

