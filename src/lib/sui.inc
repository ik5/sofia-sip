{%MainUnit sofia_sip.pas}

//////////////////////////////////////////////
/////////////// su_configure.h ///////////////
//////////////////////////////////////////////

const
  INT_MAX   = MaxInt;
  ISIZE_MAX = INT_MAX; // Maximum value of isize_t
  USIZE_MAX = INT_MAX; // Maximum value of usize_t

type
   SOFIA_ISIZE_T  = csize_t; // Define this as size_t (int when compatible with sofia-sip-ua 1.12.0 binaries).
   SOFIA_ISSIZE_T = csize_t; // Define this as ssize_t (int when compatible with sofia-sip-ua 1.12.0 binaries).
   SOFIA_USIZE_T  = csize_t; // Define this as size_t (unsigned int when compatible with sofia-sip-ua 1.12.0 binaries).

///////////////////////////////////////////
/////////////// su_config.h ///////////////
///////////////////////////////////////////
{$IFDEF WINDOWS}
const
 SOFIAPUBFUN = 1; // SOFIAPUBFUN declares an exported function
(*
/** SOFIAPUBVAR declares an exported variable */
#define SOFIAPUBVAR extern
*)
 //SOFIACALL = 1; // SOFIACALL declares the calling convention for exported functions -> not really needed ...

 // I do not really think that this is required ...
 BNF_DLL      = SOFIAPUBFUN;
 HTTP_DLL     = SOFIAPUBFUN;
 IPT_DLL      = SOFIAPUBFUN;
 AUTH_DLL     = SOFIAPUBFUN;
 MSG_DLL      = SOFIAPUBFUN;
 NEA_DLL      = SOFIAPUBFUN;
 NTA_DLL      = SOFIAPUBFUN;
 NTH_DLL      = SOFIAPUBFUN;
 SDP_DLL      = SOFIAPUBFUN;
 SIP_DLL      = SOFIAPUBFUN;
 SU_DLL       = SOFIAPUBFUN;
 TPORT_DLL    = SOFIAPUBFUN;
 URL_DLL      = SOFIAPUBFUN;
 MSG_TEST_DLL = SOFIAPUBFUN;
{$ENDIF}

////////////////////////////////////////////
//////////////// su_types.h ////////////////
////////////////////////////////////////////

type
   pSU_S64_T      = pcint64;
   SU_S64_T       = cint64;   // 64-bit signed integer
   pSU_U64_T      = pcuint64;
   SU_U64_T       = cuint64;  // 64-bit unsigned integer
   pSU_S32_T      = pcint32;
   SU_S32_T       = cint32;   // 32-bit signed integer
   pSU_U32_T      = pcuint32;
   SU_U32_T       = cuint32;  // 32-bit unsigned integer
   pSU_S16_T      = pcint16;
   SU_S16_T       = cint16;   // 16-bit signed integer
   pSU_U16_T      = pcuint16;
   SU_U16_T       = cuint16;  // 16-bit unsigned integer
   pSU_S8_T       = pcint8;
   SU_S8_T        = cint8;    // 8-bit signed integer
   pSU_U8_T       = pcuint8;
   SU_U8_T        = cuint8;   // 8-bit unsigned integer
   pSU_LEAST64_T  = {$IFDEF CPU64}pclong{$ELSE}pclonglong{$ENDIF};
                              // At least 64-bit integer
   SU_LEAST64_T   = {$IFDEF CPU64}clong{$ELSE}clonglong{$ENDIF};
   pSU_LEAST32_T  = pcint32;
   SU_LEAST32_T   = cint32;   // At least 32-bit intege
   pSU_LEAST16_T  = pcint16;
   SU_LEAST16_T   = cint16;   // At least 16-bit integer
   pSU_LEAST8_T   = pcint8;
   SU_LEAST8_T    = cint8;    // At least 8-bit integer

// Integer type large enough to store pointers

   pS_INTPTR_T    = ^S_INTPTR_T;
   S_INTPTR_T     = PtrInt;

// Unsigned integer type large enough to store pointers

   pSU_INTPTR_T   = ^SU_INTPTR_T;
   SU_INTPTR_T    = PtrUInt;

// POSIX type used for a count of bytes or an error indication.
   SOFIA_SSIZE_T  = {$ifdef cpu64}cint64{$else}cint32{$endif};

////////////////////////////////////////////
//////////////// su_errno.h ////////////////
////////////////////////////////////////////

(** Return string describing su error code. *)
function su_strerror(e : cint) : PChar;
  external LIBSOFIA;

(** The latest su error. *)
function su_errno : cint;
  external LIBSOFIA;

(** Set the su error. *)
function su_seterrno(aParam : cint) : cint;
  external LIBSOFIA;

{$IFDEF WINDOWS}
const
  EBADMSG = 20005;
  EPROTO  = 20006;
{$ENDIF}

//////////////////////////////////////
/////////////// su.h /////////////////
//////////////////////////////////////

{$IF defined(SU_HAVE_BSDSOCK)}
const
  (** Invalid socket descriptor, error from socket() or accept() *)
  INVALID_SOCKET = -1;
  (** Error from other socket calls *)
  SOCKET_ERROR   = -1;
  (** Return code for a successful call *)
  su_success     = 0;
  (** Return code for an unsuccessful call *)
  su_failure     = -1;

{$ENDIF}

{$IFDEF WINDOWS}
const
  su_success   = 0;
  su_failure   = culong($ffffffff);
  MSG_NOSIGNAL = 0;
{$ENDIF}

const
  (**@HI Maximum size of host name. *)
  SU_MAXHOST  = 1025;
  (**@HI Maximum size of service name. *)
  SU_MAXSERV  = 25;
  (**@HI Maximum size of address in text format. *)
  SU_ADDRSIZE = 48;
  (**@HI Maximum size of port number in text format. *)
  SU_SERVSIZE = 16;

{$IF defined(SU_HAVE_BSDSOCK)}
type
   su_socket_t = cint;
{$ENDIF}
{$IFDEF WINDOWS}
type
   su_socket_t = TSocket;
{$ENDIF}

{$IFNDEF SU_HAVE_SOCKADDR_STORAGE}
(*
 * RFC 2553: protocol-independent placeholder for socket addresses
 *)
const
  _SS_MAXSIZE   = 128;
  _SS_ALIGNSIZE = sizeof(cint64);
  _SS_PAD1SIZE  = (_SS_ALIGNSIZE - sizeof(cchar) * 2);
  _SS_PAD2SIZE  = (_SS_MAXSIZE - sizeof(cchar) * 2 -
                   _SS_PAD1SIZE - _SS_ALIGNSIZE);

type
   Psockaddr_storage = ^sockaddr_storage;
   sockaddr_storage  = record
{$IFDEF SU_HAVE_SOCKADDR_SA_LEN}
                         ss_len     : cuchar;  // address length
	                       ss_family  : cuchar;  // address family
{$ELSE}
                         ss_family  : cushort; // address family
{$ENDIF}
                         __ss_pad1  : array [0.._SS_PAD1SIZE] of cchar;
	                       __ss_align : cint64;  // force desired structure
                                               // storage alignment
	                       __ss_pad2  : array [0.._SS_PAD2SIZE] of cchar;
                       end;
   Tsockaddr_storage = sockaddr_storage;
{$ENDIF}

{$IFDEF SU_HAVE_SOCKADDR_SA_LEN}
// #define               su_len          su_sa.sa_len <- unsupported for now
{$ELSE}
// #define               su_len          su_array[0] <- unsupported for now
{$ENDIF}
// #define               su_family       su_sa.sa_family <- unsupported for now
// #define               su_port         su_sin.sin_port <- unsupported for now
// #define               su_scope_id     su_array32[6] <- unsupported for now

type
  (** Common socket address structure. *)
  Psu_sockaddr_u = ^su_sockaddr_u;
  Psu_sockaddr_t = ^su_sockaddr_u;
  su_sockaddr_u  = record
                     case Byte of
                       0 : (su_dummy   : cshort);                  //< Dummy member to initialize
                       1 : (su_array   : array[0..31] of char);    // Presented as chars
                       2 : (su_array16 : array[0..15] of cuint16); // Presented as 16-bit ints
                       3 : (su_array32 : array[0..8]  of cuint32); // Presented as 32-bit ints
                       4 : (su_sa      : sockaddr);                // Address in struct sockaddr format
                       5 : (su_sin     : sockaddr_in);             // Address in IPv4 format
{$IFDEF SU_HAVE_IN6}
                       6 : (su_sin6    : sockaddr_in6);            // Address in IPv6 format
{$ENDIF}
                   end;
  Tsu_sockaddr_u = su_sockaddr_u;
  su_sockaddr_t  = su_sockaddr_u;


