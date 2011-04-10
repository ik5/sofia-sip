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
{$ENDDEF}



