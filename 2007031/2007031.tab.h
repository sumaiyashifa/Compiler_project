
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END = 258,
     INT = 259,
     FLOAT = 260,
     STRING = 261,
     MOD = 262,
     CHAR = 263,
     LT = 264,
     GT = 265,
     GEQ = 266,
     LEQ = 267,
     EQ = 268,
     NEQ = 269,
     VARIABLE = 270,
     NUMBER = 271,
     CHAR_LIT = 272,
     STR = 273,
     IMPORT = 274,
     HEADER = 275,
     MAIN = 276,
     INC = 277,
     DEC = 278,
     NOT = 279,
     SIN = 280,
     COS = 281,
     LOG = 282,
     TAN = 283,
     LN = 284,
     ODDEVEN = 285,
     FACTORIAL = 286,
     MAX = 287,
     MIN = 288,
     PRIME = 289,
     DEF = 290,
     DISPLAY = 291,
     IF = 292,
     ELSE_IF = 293,
     ELSE = 294,
     FOR = 295,
     FLINC = 296,
     FLDEC = 297,
     WHILE = 298,
     CASE = 299,
     SWITCH = 300,
     DEFAULT = 301,
     STRCAT = 302,
     STRJOIN = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 134 "2007031.y"

    int num;
    float flt;
    char* string;



/* Line 1676 of yacc.c  */
#line 108 "2007031.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


