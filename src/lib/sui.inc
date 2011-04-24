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



