#!/bin/sh
#  This file is part of the gf2x library.
#
#  Copyright 2007, 2008, 2009, 2010, 2013
#  Richard Brent, Pierrick Gaudry, Emmanuel Thome', Paul Zimmermann
#
#  This program is free software; you can redistribute it and/or modify it
#  under the terms of either:
#   - If the archive contains a file named toom-gpl.c (not a trivial
#     placeholder), the GNU General Public License as published by the
#     Free Software Foundation; either version 3 of the License, or (at
#     your option) any later version.
#   - If the archive contains a file named toom-gpl.c which is a trivial
#     placeholder, the GNU Lesser General Public License as published by
#     the Free Software Foundation; either version 2.1 of the License, or
#     (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful, but WITHOUT
#  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
#  FITNESS FOR A PARTICULAR PURPOSE.  See the license text for more details.
#  
#  You should have received a copy of the GNU General Public License as
#  well as the GNU Lesser General Public License along with this program;
#  see the files COPYING and COPYING.LIB.  If not, write to the Free
#  Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
#  02110-1301, USA.

echo "## $0 $@"

while [ $# -gt 0 ] ; do
    arg="$1"
    shift
    case "$arg" in
        -m)     magic="$1" ; shift;;
        *)      echo "unexpected test arg: $arg" >&2; exit 1;;
    esac
done

if [ "$magic" ] ; then
    magic_tr=`echo $magic | tr '_.' '  '`
    read check n1 n2 v s mul <<EOF
$magic_tr
EOF
    echo "n1 = $n1 ; n2=$n2 ; v=$v ; s=$s"
    echo "## ./check-mul $n1 $n2"
    expected="$n1 $n2 $v $s"
    echo "## expected output: $expected"
    got=`./check-mul $n1 $n2`
    if [ "$got" != "$expected" ] ; then
        echo "failed check for ${n1}x${n2} : '$got' != '$expected'" >&2
        echo "failed : '$got' != '$expected'"
        exit 1
    fi
else
    echo "No test to run ??" >&2
    exit 1
fi
