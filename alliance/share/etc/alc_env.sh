# -*- Mode: Shell-script -*-
#             ,,,
#            (o o)
####=====oOO--(_)--OOO=========================================####
#
#  Alliance CAD system environnement
#  Usage (in Bourne-shell) : > . alc_env.sh
#  (C) 1997 Czo  -- <Olivier.Sirol@lip6.fr>
#  $Id: alc_env.sh,v 1.2 1999/08/26 18:47:42 czo Exp $
#  Generated from alc_env.sh.in on Thu Aug 26 20:45:26 CEST 1999

# $MACHINE and $TOP are the only variables you will
# have to modify if something goes wrong

# Which platform for Alliance CAD

# WARNING : if changing this remember to do it on the 3 config files :
# configure.in alc_env.sh.in and alc_env.csh.in

MACHINE=Unknown
 
case `uname` in

  Linux*) case `uname -r` in
           1.*) MACHINE=Linux_aout ;;
          2.0*) MACHINE=Linux_elf  ;;            
             *) MACHINE=Linux  ;;
          esac ;;

  SunOS*) case `uname -r` in
            5*) MACHINE=Solaris ;;
             *) MACHINE=SunOS ;;
          esac ;;

  FreeBSD*)     MACHINE=FreeBSD ;;

  HP-UX*)       MACHINE=HPUX ;;

  OSF1*)        MACHINE=OSF ;;

  *)     MACHINE=Unknown ;;

esac
export MACHINE

# Where the Alliance CAD is installed

 TOP=/alliance/alliance/archi/$MACHINE ;      export TOP

# User def 

         MBK_IN_LO=vst;                   export MBK_IN_LO
        MBK_OUT_LO=vst;                   export MBK_OUT_LO 
         MBK_IN_PH=ap;                    export MBK_IN_PH
        MBK_OUT_PH=ap;                    export MBK_OUT_PH

      MBK_WORK_LIB=.;                     export MBK_WORK_LIB
    MBK_CATAL_NAME=CATAL;                 export MBK_CATAL_NAME

       MBK_SCALE_X=10;                    export MBK_SCALE_X

          VH_MAXERR=10;                   export VH_MAXERR
         VH_BEHSFX=vbe;                   export VH_BEHSFX
         VH_PATSFX=pat;                   export VH_PATSFX

      MBK_CATA_LIB=.:$TOP/cells/sclib;    export MBK_CATA_LIB
    MBK_TARGET_LIB=$TOP/cells/sclib;      export MBK_TARGET_LIB
        MBK_C4_LIB=./cellsC4;             export MBK_C4_LIB

           MBK_VDD=vdd                    export MBK_VDD
           MBK_VSS=vss                    export MBK_VSS

   XPAT_PARAM_NAME=$TOP/etc/xpat.par;     export XPAT_PARAM_NAME
   XFSM_PARAM_NAME=$TOP/etc/xfsm.par;     export XFSM_PARAM_NAME

 DREAL_TECHNO_NAME=$TOP/etc/cmos_7.dreal; export DREAL_TECHNO_NAME
 GRAAL_TECHNO_NAME=$TOP/etc/cmos_7.graal; export GRAAL_TECHNO_NAME

   RDS_TECHNO_NAME=$TOP/etc/cmos_7.rds;   export RDS_TECHNO_NAME
   ELP_TECHNO_NAME=$TOP/etc/prol10.elp;   export ELP_TECHNO_NAME


## Update PATH and MANPATH
#PATH=$HOME/labo/$MACHINE/bin:$TOP/bin:$PATH
PATH=$TOP/bin:$PATH
export PATH
MANPATH=$TOP/man:$MANPATH
export MANPATH

# EOF 


