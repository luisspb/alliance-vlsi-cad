/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - Département ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail         : mailto:alliance-users@asim.lip6.fr       |
|                                                             |
| This progam is  free software; you can redistribute it      |
| and/or modify it under the  terms of the GNU General Public |
| License as  published by the Free Software Foundation;      |
| either version 2 of the License, or (at your option) any    |
| later version.                                              |
|                                                             |
| Alliance VLSI  CAD System  is distributed  in the hope that |
| it  will be useful, but WITHOUT  ANY WARRANTY;              |
| without even the  implied warranty of MERCHANTABILITY or    |
| FITNESS FOR A PARTICULAR PURPOSE. See the GNU General       |
| Public License for more details.                            |
|                                                             |
| You should have received a copy  of the GNU General Public  |
| License along with the GNU C Library; see the file COPYING. |
| If not, write to the Free Software Foundation, Inc.,        |
| 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                     |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
| Tool    :                     VASY                          |
|                                                             |
| File    :                  vasy_synth.h                     |
|                                                             |
| Author  :                 Jacomme Ludovic                   |
|                                                             |
| Date    :                   25.08.97                        |
|                                                             |
\------------------------------------------------------------*/

# ifndef VASY_SYNTH_H
# define VASY_SYNTH_H

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# define VASY_TRANS_ASG_DEFINE_MASK    0x01

/*------------------------------------------------------------\
|                                                             |
|                            Macro                            |
|                                                             |
\------------------------------------------------------------*/

# define SetVasyVpnTransAsgDefine( T )   ((T)->FLAGS |=  VASY_TRANS_ASG_DEFINE_MASK)
# define ClearVasyVpnTransAsgDefine( T ) ((T)->FLAGS &= ~VASY_TRANS_ASG_DEFINE_MASK)
# define IsVasyVpnTransAsgDefine( T )    ((T)->FLAGS &   VASY_TRANS_ASG_DEFINE_MASK)

/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/

  extern void VasySynthesisOneWaitVpnProc();
  extern void VasySynthesisMultiWaitVpnProc();
  extern void VasySynthesisCombinatorialVpnProc();
  extern void VasySynthesisVpnDecl();
  extern void VasySynthesisVpnInstance();
  extern void VasySynthesisVpnModel();

# endif
