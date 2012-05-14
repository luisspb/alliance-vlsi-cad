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
| Tool    :                   GRAAL                           |
|                                                             |
| File    :                  Tools.h                          |
|                                                             |
| Author  :                Jacomme Ludovic                    |
|                                                             |
| Date    :                  28.03.95                         |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# ifndef GRAAL_TOOLS
# define GRAAL_TOOLS

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# define GRAAL_HIERARCHY_SHOW_MESSAGE_SIZE   4096

/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/

   typedef struct graalhierarchy
   {
     struct graalhierarchy  *NEXT;
     char                   *NAME;
     long                    X;
     long                    Y;
     long                    DX;
     long                    DY;

   } graalhierarchy;

/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/

  extern char GraalToolsFilter[ 10 ];
  extern char GraalToolsExtention[ 10 ];

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/

  extern void GraalToolsUnpeek();
  extern void GraalToolsDelAllHierarchy();
  extern void GraalToolsHierarchyUp();
  extern void GraalToolsHierarchyReload();
  extern void GraalToolsLoadError();
  extern void GraalToolsSavePixmap();

# endif 
