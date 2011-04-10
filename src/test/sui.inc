{%MainUnit sofia_sip.pas}

//su_configure.h

const
  INT_MAX = MaxInt;

type
   SOFIA_ISIZE_T  = csize_t; // Define this as size_t (int when compatible with sofia-sip-ua 1.12.0 binaries).
   SOFIA_ISSIZE_T = csize_t; // Define this as ssize_t (int when compatible with sofia-sip-ua 1.12.0 binaries).


const
   ISIZE_MAX = INT_MAX; // Maximum value of isize_t



