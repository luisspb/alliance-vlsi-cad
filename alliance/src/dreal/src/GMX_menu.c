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
| Tool    :                   DREAL                           |
|                                                             |
| File    :                  Menu.c                           |
|                                                             |
| Authors :              Jacomme Ludovic                      |
|                                                             |
| Date    :                  28.03.95                         |
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
# include <Xm/RowColumn.h>

# include "mut.h"
# include "mph.h"
# include "rds.h"
# include "rpr.h"
# include "GTB.h"
# include "GSB.h"
# include "GMF.h"
# include "GME.h"
# include "GMC.h"
# include "GMV.h"
# include "GMT.h"
# include "GMS.h"
# include "GMH.h"
# include "GMX.h"

# include "GMX_menu.h"

/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/

  Widget DrealMenuBar;

  DrealMenuItem DrealMainMenu[] =

         {
           {
             "File",
             'F',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             False,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealFileMenu
           }
           ,
           {
             "Edit",
             'E',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             False,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealEditMenu
           }
           ,
           {
             "Window",
             'W',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             False,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealWindowMenu
           }
           ,
           {
             "Create",
             'C',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             False,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealCreateMenu
           }
           ,
           {
             "View",
             'V',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             False,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealViewMenu
           }
           ,
           {
             "Tools",
             'T',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             False,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealToolsMenu
           }
           ,
           {
             "Setup",
             'S',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             False,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealSetupMenu
           }
           ,
           {
             "Help",
             'H',
             NULL,
             NULL,
             &xmCascadeButtonGadgetClass,
             False,
             False,
             True,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             DrealHelpMenu
           }
           ,
           {
             NULL
           }
         };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      DrealInitializeMenu                    |
|                                                             |
\------------------------------------------------------------*/

void DrealInitializeMenu()

{
  rdsbegin();

  DrealMenuBar = XmCreateMenuBar( DrealMainWindow,
                                 "DrealMenuBar", NULL, 0 );

  DrealBuildMenus( DrealMenuBar, DrealMainMenu );

  XtManageChild( DrealMenuBar );

  rdsend();
}

