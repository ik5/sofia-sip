{%MainUnit sofia_sip.pas}

{$IFDEF SU_HAVE_BSDSOCK}
function su_is_blocking(errcode : cint) : cint;
begin
  Result := cint(errcode in [ ESysEINPROGRESS, ESysEAGAIN
                 {$IF (ESysEWOULDBLOCK <> ESysEAGAIN)} , ESysEWOULDBLOCK{$ENDIF}
                            ]);
end;

{$ENDIF}
