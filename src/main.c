/*
 Copyright (C) 2010 Ben Asselstine

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 3 of the License, or
 (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Library General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 
  02110-1301, USA.
*/
#include <stdio.h>
#include <stdlib.h>
#include <argp.h>
#include <string.h>

#define ARG_KEY_A 'a'
#define ARG_KEY_D 'd'
#define ARG_KEY_S 's'

static int
parse_opt (int key, char *arg, 
	   struct argp_state *state)
{
  switch (key)
    {
    case ARG_KEY_D:
        if(arg == NULL){
            printf ("arg == NULL");
        }else{
            for (int i = 0; i < atoi (arg); i++){
                printf (".");
            }
        }
        printf ("\n");
        break;
    case ARG_KEY_S:
        if(arg == NULL){
            printf ("smile arg == NULL");
        }else{
            for (int i = 0; i < atoi (arg); i++){
                printf ("^^ ");
            }
        }
        printf ("\n");
        break;
    }
  return 0;
}

int
main (int argc, char **argv)
{
  struct argp_option options[] = 
    {
	{ "dot", ARG_KEY_D, "NUM", OPTION_ARG_OPTIONAL, "Show some dot on the screen"},
	{ "smile", ARG_KEY_S, "number", OPTION_ARG_OPTIONAL, "Show ^^ on the screen"},
	{ "period", ARG_KEY_A, "FOO", OPTION_ALIAS, "Bar" },
    { 0 }
    };
  struct argp argp = { options, parse_opt };
  return argp_parse (&argp, argc, argv, 0, 0, 0);
}
