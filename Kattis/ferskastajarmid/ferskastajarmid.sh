#!/bin/bash

read n
memes=()
bestScore=0

while [[ $n -gt 0 ]]; do
    read meme contro cool
    fresh=$((contro*cool))

    if [[ $bestScore -le $fresh ]]; then
        bestScore=$fresh
        memes+=("$meme $fresh")
    fi

    ((n--))
done

# Sorts second field numerically reversed, then first field lexicographically
printf "%s\n" "${memes[@]}" | sort -k2,2nr -k1,1 | awk '{ print $1 }' | head -n 1
