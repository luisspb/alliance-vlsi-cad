# -*- Mode: Shell-script -*-
#             ,,,
#            (o o)
####=====oOO--(_)--OOO=========================================####
#
#  Alliance CAD system environnement
#  Usage (in C-shell) : > source alc_env.csh
#  (C) 1997 Czo  -- <Olivier.Sirol@lip6.fr>
#  $Id: alc_env.csh,v 1.2 1999/08/26 18:47:42 czo Exp $
#  Generated from alc_env.csh.in on Thu Aug 26 20:45:26 CEST 1999

# $MACHINE and $TOP are the only variables you will
# have to modify if something goes wrong

# Which platform for Alliance CAD

switch (`uname`)
 case Linux:
  if ( `uname -r` =~ 1.* ) then
      setenv MACHINE Linux_aout
  else
      setenv MACHINE Linux_elf
  endif
 breaksw

 case SunOS:
  if ( `uname -r` =~ 5* ) then
      setenv MACHINE Solaris
  else
      setenv MACHINE SunOS
  endif
 breaksw

 default:
  setenv MACHINE Unknown
 breaksw
endsw

setenv ALLIANCE_OS $MACHINE

# Where the Alliance CAD is installed

setenv TOP /alliance/alliance/archi/$MACHINE
setenv ALLIANCE_TOP $TOP

# User def 

setenv MBK_IN_LO         vst
setenv MBK_OUT_LO        vst
setenv MBK_IN_PH         ap
setenv MBK_OUT_PH        ap

setenv MBK_WORK_LIB      .
setenv MBK_CATAL_NAME    CATAL

setenv MBK_SCALE_X 10

setenv VH_MAXERR 10
setenv VH_BEHSFX vbe
setenv VH_PATSFX pat

setenv MBK_CATA_LIB      .:$TOP/cells/sclib
setenv MBK_TARGET_LIB    $TOP/cells/sclib
setenv MBK_C4_LIB        ./cellsC4 

setenv MBK_VDD           vdd
setenv MBK_VSS           vss

setenv XPAT_PARAM_NAME   $TOP/etc/xpat.par
setenv XFSM_PARAM_NAME   $TOP/etc/xfsm.par

setenv DREAL_TECHNO_NAME $TOP/etc/cmos_7.dreal
setenv GRAAL_TECHNO_NAME $TOP/etc/cmos_7.graal

setenv RDS_TECHNO_NAME   $TOP/etc/cmos_7.rds

setenv RDS_IN cif
setenv RDS_OUT cif

setenv ELP_TECHNO_NAME   $TOP/etc/prol10.elp

# Update PATH and MANPATH
if $?PATH then
 setenv PATH $TOP/bin:$PATH
else
 setenv PATH $TOP/bin
endif


if $?MANPATH then
 setenv MANPATH $TOP/man:$MANPATH
else
 setenv MANPATH $TOP/man
endif

# EOF 

