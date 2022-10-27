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

#define ARG_KEY_D 'd'

static int
parse_opt (int key, char *arg, 
	   struct argp_state *state)
{
  switch (key)
    {
    case ARG_KEY_D:
        unsigned int i;
        for (i = 0; i < atoi (arg); i++)
        printf (".");
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
	{ "dot", ARG_KEY_D, "NUM", 0, "Show some dot on the screen"},
	{ 0 }
    };
  struct argp argp = { options, parse_opt };
  return argp_parse (&argp, argc, argv, 0, 0, 0);
}
