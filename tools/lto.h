/*
 * LTO helper functions for the Wine tools
 *
 * Copyright 2025 Konstantin Demin
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#ifndef __WINE_LTO_H
#define __WINE_LTO_H

#ifndef __WINE_TOOLS_H
# error You must include tools.h to use this header
#endif


__attribute__((used))
static void append_lto_flags( struct strarray *args, int with_lto, int prefer_env )
{
    if (with_lto < 0) return;

    while (prefer_env > 0)
    {
        const char *flags;

        if (with_lto > 0)
        {
            static int init_lto = 0;
            static const char* flags_lto;

            if (!init_lto)
            {
                flags_lto = getenv( "WINE_LTO_FLAGS" );
                if (flags_lto) flags_lto = xstrdup( flags_lto );
                init_lto = 1;
            }
            flags = flags_lto;
        }
        else
        {
            static int init_lto_skip = 0;
            static const char* flags_lto_skip;

            if (!init_lto_skip)
            {
                flags_lto_skip = getenv( "WINE_LTO_SKIP_FLAGS" );
                if (flags_lto_skip) flags_lto_skip = xstrdup( flags_lto_skip );
                init_lto_skip = 1;
            }
            flags = flags_lto_skip;
        }

        if (!flags) break;

        strarray_addall( args, strarray_fromstring( flags, " " ) );
        return;
    }

    strarray_add( args, (with_lto > 0) ? "-flto" : "-fno-lto" );
}


static int var_to_bool( const char *var )
{
    if (!var) return 0;
    if (!( var[0] )) return 0;

    switch (var[0])
    {
        /* "1" */
        case '1':
            if (!var[1]) return 1;
            break;

        /* "[Tt]", "[Tt][Rr][Uu][Ee]" */
        case 'T': /* -fallthrough */
        case 't':
            if (!var[1]) return 1;

            if (strlen( var ) != 4) break;
            if ((var[1] != 'R') && (var[1] != 'r')) break;
            if ((var[2] != 'U') && (var[2] != 'u')) break;
            if ((var[3] != 'E') && (var[3] != 'e')) break;
            return 1;

            break;

        /* "[Yy]", "[Yy][Ee][Ss]" */
        case 'Y': /* -fallthrough */
        case 'y':
            if (!var[1]) return 1;

            if (strlen( var ) != 3) break;
            if ((var[1] != 'E') && (var[1] != 'e')) break;
            if ((var[2] != 'S') && (var[2] != 's')) break;
            return 1;

            break;
    }

    return 0;
}


__attribute__((used))
static int adjust_verbose_lto( int with_lto, int verbose )
{
    const char* lto_debug;

    if (with_lto < 1) return verbose;
    if (verbose > 0) return verbose;

    lto_debug = getenv( "WINE_LTO_DEBUG" );
    if (!lto_debug) return verbose;

    return var_to_bool( lto_debug );
}


#endif /* __WINE_LTO_H */
