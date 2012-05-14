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
| Tool    :                     XFSM                          |
|                                                             |
| File    :                  XsbParse.c                       |
|                                                             |
| Authors :                Jacomme Ludovic                    |
|                                                             |
| Date    :                   04.12.96                        |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include <stdlib.h>
# include <string.h>
# include "mut.h"
# include "aut.h"
# include "abl.h"
# include "bdd.h"
# include "fsm.h"
# include "XSB.h"
# include "XSB_error.h"
# include "XSB_parse.h"

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
|                       Global Variables                      |
|                                                             |
\------------------------------------------------------------*/

  char *XFSM_PARAM_NAME = (char *)NULL;
  char *XFSM_LAYER_NAME_TABLE[ XFSM_MAX_LAYER ][ 3 ];

/*------------------------------------------------------------\
|                                                             |
|                      Private Variables                      |
|                                                             |
\------------------------------------------------------------*/

  static char *XfsmDefaultTechnoName = XFSM_DEFAULT_PARAM_NAME;

/*------------------------------------------------------------\
|                                                             |
|                       Table variables                       |
|                                                             |
\------------------------------------------------------------*/

  char  *XFSM_CURSOR_COLOR_NAME;
  char  *XFSM_BACKGROUND_COLOR_NAME;
  char  *XFSM_FOREGROUND_COLOR_NAME;
  char  *XFSM_ACCEPT_COLOR_NAME;
  char  *XFSM_CONNECT_COLOR_NAME;

  long   XFSM_CURSOR_SIZE;
  float  XFSM_LOWER_GRID_STEP;
  long   XFSM_UNIT;

  char  *XFSM_NOT_DEFINE = "";

/*------------------------------------------------------------\
|                                                             |
|                      Keywords variables                     |
|                                                             |
\------------------------------------------------------------*/

  static char  KeywordDefined = 0;

  static char *DefineKeyword;
  static char *TableKeyword;
  static char *EndTableKeyword;
  static char *EndRecordKeyword;
  static char *LowerGridStepKeyword;
  static char *CursorColorNameKeyword;
  static char *BackgroundColorNameKeyword;
  static char *ForegroundColorNameKeyword;
  static char *AcceptColorNameKeyword;
  static char *ConnectColorNameKeyword;
  static char *CursorSizeKeyword;
  static char *UnitKeyword;
  static char *LayerNameKeyword;

  static keyword KeywordDefine[ XSB_MAX_KEYWORD ] =

  {
    "None", 0
  };

/*------------------------------------------------------------\
|                                                             |
|                       File variables                        |
|                                                             |
\------------------------------------------------------------*/

  static  FILE *XsbFile;
  static  char  XsbBuffer[ XSB_MAX_BUFFER ];
  static  long  XsbCurrentLine;

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                       Xsb File Get String                   |
|                                                             |
\------------------------------------------------------------*/

char *XsbFileGetString( String, Size )

  char *String;
  int   Size;
{
  register char *RegisterString;
  register       Register;

  autbegin();
 
  RegisterString = String;
 
  while (--Size > 0 && (Register = getc( XsbFile )) != EOF )
  {
    if ((*RegisterString++ = Register) == '\\') 
    {
      if ((Register = getc( XsbFile )) == '\n') 
      {
        *(RegisterString - 1) = ' ';
      } 
      else
      {
        ungetc( Register, XsbFile );
      }
    }
    else
    {
      if ( Register == '\n') break;
    }
  }
 
  *RegisterString = '\0';
 
  autend();
  return ( ( Register       == EOF    ) && 
           ( RegisterString == String ) ) ? (char *)NULL : String;
}

/*------------------------------------------------------------\
|                                                             |
|                       Xsb File Get Line                     |
|                                                             |
\------------------------------------------------------------*/

void XsbGetLine( Buffer )

  char   *Buffer;
{
  char   *Check;
  char   *String;
  char    OneComment;

  autbegin();
 
  do 
  {
    OneComment = 0;
 
    Check = XsbFileGetString( Buffer, XSB_MAX_BUFFER );
 
    if ( Check != (char *)NULL ) 
    {
      XsbCurrentLine++;
    }
    else 
    {
      XsbError( UNEXPECTED_EOF, (char *)NULL, XsbCurrentLine );
    }
 
    if ( String = strchr( Buffer, XSB_COMMENT_CHAR ))
    {
      if ( String == Buffer )
      {
        OneComment = 1;
      }
      else
      {
        *(String - 1) = '\0'; 
      }
    }
  
    while (*Buffer != '\0' && strchr( XSB_SEPARATORS_STRING, *Buffer))
    {
      Buffer = Buffer + 1;;
    }
 
    if (*Buffer == '\0') OneComment = 1;
 
  } 
  while ( OneComment == 1);

  autend();
}      

/*------------------------------------------------------------\
|                                                             |
|                        Xsb Check Keyword                    |
|                                                             |
\------------------------------------------------------------*/

char XsbCheckKeyword( Word )

  char *Word;
{
  if ( ( Word == DefineKeyword ) ||
       ( Word == TableKeyword  ) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

/*------------------------------------------------------------\
|                                                             |
|                        Xsb Get First word                   |
|                                                             |
\------------------------------------------------------------*/

char *XsbGetFirstWord( Buffer, IsKeyword, Hash )
 
  char *Buffer;
  char  IsKeyword;
  char  Hash;
{
  char   *String;
  char   *Text;
  int     Index;
 
  autbegin();
 
  if ( String = (char *)strtok( Buffer, XSB_SEPARATORS_STRING )) 
  {
    if ( Hash )
    {
      String = namealloc( String );
    }
    else
    {
      Text = autallocblock( strlen( String ) + 1 );
      strcpy( Text, String );
      String = Text;
 
      for ( Index = 0; Text[ Index ]; Index++ )
      {
        if ( Text[ Index ] == '_' ) Text[ Index ] = ' '; 
      }
    }
 
    if ( ( IsKeyword ) && XsbCheckKeyword( String ) )
    {
      XsbError( UNEXPECTED_LINE, String, XsbCurrentLine );
    }
  }

  autend();
  return( String );
}

/*------------------------------------------------------------\
|                                                             |
|                        Xsb Get Next word                    |
|                                                             |
\------------------------------------------------------------*/

char *XsbGetNextWord( IsKeyword, Hash )
 
  char IsKeyword;
  char Hash;
{
  char   *String;
  char   *Text;
  int     Index;

  autbegin();
 
  if ( String = (char *)strtok( (char *)NULL, XSB_SEPARATORS_STRING )) 
  {
     if ( Hash )
     {
       String = namealloc( String );
     }
     else
     {
       Text = autallocblock( strlen( String ) + 1 );
       strcpy( Text, String );
       String = Text;
 
       for ( Index = 0; Text[ Index ]; Index++ )
       {
         if ( Text[ Index ] == '_' ) Text[ Index ] = ' ';
       }
     }
 
     if ( ( IsKeyword ) && XsbCheckKeyword( String ) )
     {
       XsbError( UNEXPECTED_LINE, String, XsbCurrentLine );
     }
  }
 
  autend();
  return( String );
}

/*------------------------------------------------------------\
|                                                             |
|                      Xsb Keyword Compare                    |
|                                                             |
\------------------------------------------------------------*/

int XsbKeywordCompare( FirstKey, SecondKey )

    keyword *FirstKey;
    keyword *SecondKey;
{
  return strcmp( FirstKey->NAME, SecondKey->NAME );
}

/*------------------------------------------------------------\
|                                                             |
|                      Xsb Get String Value                   |
|                                                             |
\------------------------------------------------------------*/

long XsbGetStringValue( String )

  char     *String;
{
  long      Value;
  keyword  *Keyword;
  keyword   Entry;

  autbegin();
 
  if ( sscanf( String, "%d", &Value) )
  {
    autend();
    return ( Value );
  }

  Entry.NAME = String;
 
  Keyword = (keyword *)bsearch( (char *)(&Entry), 
                                (char *)KeywordDefine, 
                                XSB_MAX_KEYWORD, sizeof( keyword ),
                                XsbKeywordCompare );
 
  if ( Keyword == (keyword *)NULL )
  {
    XsbError( UNEXPECTED_LINE, String, XsbCurrentLine );
  }

  autend();
  return( Keyword->VALUE );
}

/*------------------------------------------------------------\
|                                                             |
|                      Xsb Get String Float                   |
|                                                             |
\------------------------------------------------------------*/

float XsbGetStringFloat( String )

   char     *String;
{
  float     Value;

  autbegin();

  if ( ! sscanf( String, "%g", &Value) )
  {
    XsbError( ILLEGAL_FLOAT, String, XsbCurrentLine );
  }

  autend();
  return ( Value );
}

/*------------------------------------------------------------\
|                                                             |
|                        Xsb Get Number                       |
|                                                             |
\------------------------------------------------------------*/

long XsbGetNumber( String )

     char *String;
{
  long Value;

  autbegin();

  if ( ! sscanf( String, "%d", &Value ))
  {
    XsbError( UNEXPECTED_LINE, "number", XsbCurrentLine );
  }

  autend();
  return Value;
}


/*------------------------------------------------------------\
|                                                             |
|                       Xsb Read Layer Name                   |
|                                                             |
\------------------------------------------------------------*/

void XsbReadLayerName()

{
  char  Layer;
  char  LayerCount;
  char  EndTable;
  char  Field;
  char *FirstWord;

  autbegin();

  EndTable   = 0;
  LayerCount = 0;

  while ( ( EndTable   != 1              ) &&
          ( LayerCount <= XFSM_MAX_LAYER ) )
  {
    XsbGetLine( XsbBuffer );

    FirstWord  = XsbGetFirstWord( XsbBuffer, 1, 1 );

    if ( FirstWord == EndTableKeyword )
    {
      EndTable = 1;
    }
    else
    if ( LayerCount < XFSM_MAX_LAYER )
    {
      Layer = XsbGetStringValue( FirstWord );

      for ( Field = 0; Field < 3; Field++ )
      {
        FirstWord = XsbGetNextWord( 1, 0 );

        if ( FirstWord == EndRecordKeyword )
        {
          XsbError( MISSING_VALUE, (char *)NULL, XsbCurrentLine );
        }
        else
        {
          XFSM_LAYER_NAME_TABLE [ Layer ][ Field ] = FirstWord;
        }
      }

      FirstWord = XsbGetNextWord( 0, 1 );

      if ( FirstWord != EndRecordKeyword )
      {
        XsbError( TOO_MANY_WORDS, FirstWord, XsbCurrentLine );
      }
    }

    LayerCount = LayerCount + 1;
  }

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                      Xsb Read Parameters                    |
|                                                             |
\------------------------------------------------------------*/
 
void XsbReadParam()
 
{
  char *FirstWord;
  char *SecondWord;
  long  Continue;

  autbegin();

  Continue = 0;

  while ( Continue != XSB_ALL_DEFINED_MASK )  
  {
    XsbGetLine( XsbBuffer );

    FirstWord = XsbGetFirstWord( XsbBuffer, 0, 1);

    if ( FirstWord == DefineKeyword ) 
    {
      FirstWord = XsbGetNextWord( 1, 1 );

      if (! FirstWord )
      {
        XsbError( MISSING_NAME, DefineKeyword, XsbCurrentLine );
      }

      SecondWord = XsbGetNextWord( 1, 0 );

      if (! SecondWord ) 
      {
        XsbError( MISSING_VALUE, SecondWord, XsbCurrentLine );
      }

      if ( FirstWord == LowerGridStepKeyword )
      {
        XFSM_LOWER_GRID_STEP = XsbGetStringFloat( SecondWord );

        Continue |= XSB_LOWER_GRID_STEP_MASK;
      }
      else
      if ( FirstWord == CursorColorNameKeyword )
      {
        XFSM_CURSOR_COLOR_NAME = SecondWord;

        Continue |= XSB_CURSOR_COLOR_NAME_MASK;
      }
      else
      if ( FirstWord == BackgroundColorNameKeyword )
      {
        XFSM_BACKGROUND_COLOR_NAME = SecondWord;

        Continue |= XSB_BACKGROUND_COLOR_NAME_MASK;
      }
      else
      if ( FirstWord == ForegroundColorNameKeyword )
      {
        XFSM_FOREGROUND_COLOR_NAME = SecondWord;

        Continue |= XSB_FOREGROUND_COLOR_NAME_MASK;
      }
      else
      if ( FirstWord == AcceptColorNameKeyword )
      {
        XFSM_ACCEPT_COLOR_NAME = SecondWord;

        Continue |= XSB_ACCEPT_COLOR_NAME_MASK;
      }
      else
      if ( FirstWord == ConnectColorNameKeyword )
      {
        XFSM_CONNECT_COLOR_NAME = SecondWord;

        Continue |= XSB_CONNECT_COLOR_NAME_MASK;
      }
      else
      if ( FirstWord == CursorSizeKeyword )
      {
        XFSM_CURSOR_SIZE = XsbGetStringValue( SecondWord );

        Continue |= XSB_CURSOR_SIZE_MASK;
      }
      else
      if ( FirstWord == UnitKeyword )
      {
        XFSM_UNIT = XsbGetStringValue( SecondWord );

        Continue |= XSB_UNIT_MASK;
      }
      else
      {
        XsbError( UNKNOWN_DEFINE, FirstWord, XsbCurrentLine );
      }
    }
    else 
    if ( FirstWord == TableKeyword )
    {
      if (!( FirstWord = XsbGetNextWord(1, 1)))
      {
        XsbError( MISSING_NAME, TableKeyword );
      }

      if ( FirstWord == LayerNameKeyword )
      {
        XsbReadLayerName();

        Continue |= XSB_LAYER_NAME_MASK;
      }
      else
      {
        XsbError( UNKNOWN_TABLE, FirstWord, XsbCurrentLine );
      }
    } 
    else
    { 
      XsbError( SYNTAX_ERROR, FirstWord, XsbCurrentLine );
    } 
  }       

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                      Xsb Load Parameters                    |
|                                                             |
\------------------------------------------------------------*/

void XfsmLoadParameters()

{
  short  Layer;

  autbegin();
  
  XFSM_PARAM_NAME = mbkgetenv( "XFSM_PARAM_NAME" );

  if ( XFSM_PARAM_NAME == (char *)NULL )
  {
    XFSM_PARAM_NAME = XfsmDefaultTechnoName;
  }

  if ( ! KeywordDefined )
  {
    DefineKeyword              = namealloc( DEFINE_KEYWORD                );
    TableKeyword               = namealloc( TABLE_KEYWORD                 );
    EndTableKeyword            = namealloc( END_TABLE_KEYWORD             );
    EndRecordKeyword           = namealloc( END_RECORD_KEYWORD            );
    LowerGridStepKeyword       = namealloc( LOWER_GRID_STEP_KEYWORD       );
    CursorColorNameKeyword     = namealloc( CURSOR_COLOR_NAME_KEYWORD     );
    BackgroundColorNameKeyword = namealloc( BACKGROUND_COLOR_NAME_KEYWORD );
    ForegroundColorNameKeyword = namealloc( FOREGROUND_COLOR_NAME_KEYWORD );
    AcceptColorNameKeyword     = namealloc( ACCEPT_COLOR_NAME_KEYWORD     );
    ConnectColorNameKeyword    = namealloc( CONNECT_COLOR_NAME_KEYWORD    );
    CursorSizeKeyword          = namealloc( CURSOR_SIZE_KEYWORD           );
    UnitKeyword                = namealloc( UNIT_KEYWORD                  );
    LayerNameKeyword           = namealloc( LAYER_NAME_KEYWORD            );
 
    KeywordDefined = 1;
  }

  XFSM_LOWER_GRID_STEP = 0.0;

  XFSM_CURSOR_COLOR_NAME     = (char *)NULL;
  XFSM_BACKGROUND_COLOR_NAME = (char *)NULL;
  XFSM_FOREGROUND_COLOR_NAME = (char *)NULL;
  XFSM_ACCEPT_COLOR_NAME     = (char *)NULL;
  XFSM_CONNECT_COLOR_NAME    = (char *)NULL;

  XFSM_CURSOR_SIZE = 5;
  XFSM_UNIT        = 4;

  for ( Layer = 0; Layer < XFSM_MAX_LAYER; Layer++ )
  {
    XFSM_LAYER_NAME_TABLE[ Layer ][0] = XFSM_NOT_DEFINE;
    XFSM_LAYER_NAME_TABLE[ Layer ][1] = (char *)NULL;
    XFSM_LAYER_NAME_TABLE[ Layer ][2] = (char *)NULL;
  }

  if ( !( XsbFile = fopen( XFSM_PARAM_NAME, "r")))

    XsbError( OPEN_FILE, XFSM_PARAM_NAME, 0);

  XsbReadParam();

  fclose( XsbFile );

  autend();
}
