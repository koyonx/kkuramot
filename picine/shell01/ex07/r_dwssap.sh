#!/bin/bash
cat /etc/passwd | cut -d ':' -f 1,2,3,4,5,6,7 | sed -n 2~2p | cut -d':' -f 1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/\./'