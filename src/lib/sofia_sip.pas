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

Possible defines:
  - COMPAT_1_12_0 - Make code competible with 1.12.0
  - USE_GLIB      - Link glib as well

}

unit sofia_sip;

{$mode objfpc}{$H+}

interface

uses
  ctypes, OpenSSL
  {$IFDEF Unix}
  //, Unix, unixtype
  {$ENDIF};

const
  LIBSOFIA     = 'libsofia-sip-ua';
{$IFDEF USE_GLIB}
  LIBSOFIAGLIB = 'libsofia-sip-ua-glib';
{$ENDIF}

{$IFDEF COMPAT_1_12_0}
type
  csize_t = cint;
{$ENDIF}

{$include sui.inc}


implementation

end.

