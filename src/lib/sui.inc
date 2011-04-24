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
   SU_S64_T       = cint64;
   pSU_U64_T      = pcuint64;
   SU_U64_T       = cuint64;
   pSU_S32_T      = pcint32;
   SU_S32_T       = cint32;
   pSU_U32_T      = pcuint32;
   SU_U32_T       = cuint32;
   pSU_S16_T      = pcint16;
   SU_S16_T       = cint16;
   pSU_U16_T      = pcuint16;
   SU_U16_T       = cuint16;
   pSU_S8_T       = pcint8;
   SU_S8_T        = cint8;
   pSU_U8_T       = pcuint8;
   SU_U8_T        = cuint8;
   pSU_LEAST64_T  = {$IFDEF CPU64}pclong{$ELSE}pclonglong{$ENDIF};
   SU_LEAST64_T   = {$IFDEF CPU64}clong{$ELSE}clonglong{$ENDIF};
   pSU_LEAST32_T  = pcint32;
   SU_LEAST32_T   = cint32;
   pSU_LEAST16_T  = pcint16;
   SU_LEAST16_T   = cint16;
   pSU_LEAST8_T   = pcint8;
   SU_LEAST8_T    = cint8;











