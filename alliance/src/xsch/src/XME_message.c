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
| Tool    :                    XSCH                           |
|                                                             |
| File    :                  Message.c                        |
|                                                             |
| Authors :              Jacomme Ludovic                      |
|                                                             |
| Date    :                   01.06.96                        |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include <stdio.h>
# include <Xm/Xm.h>
# include <Xm/PushBG.h>
# include <Xm/CascadeBG.h>
 
# include "mut.h"
# include "aut.h"
# include "mlo.h"
# include "scl.h"
# include "XSB.h"
# include "XSC.h"
# include "XMX.h"
# include "XTB.h"
# include "XME.h"
# include "XME_edit.h"
# include "XME_message.h"

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/
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
/*------------------------------------------------------------\
|                                                             |
|                    XschPromptEditIdentify                   |
|                                                             |
\------------------------------------------------------------*/

void XschPromptEditIdentify()

{
  autbegin();

  XschDisplayMessage( XSCH_MESSAGE_MODE  , "Identify" );
  XschDisplayMessage( XSCH_MESSAGE_INFO  , "Select object" );
  XschDisplayMessage( XSCH_MESSAGE_PROMPT, "Enter select point" );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    XschPromptEditConnected                  |
|                                                             |
\------------------------------------------------------------*/

void XschPromptEditConnected()

{
  autbegin();

  XschDisplayMessage( XSCH_MESSAGE_MODE  , "Connected" );
  XschDisplayMessage( XSCH_MESSAGE_INFO  , "Select object" );
  XschDisplayMessage( XSCH_MESSAGE_PROMPT, "Enter select point" );

  autend();
}
