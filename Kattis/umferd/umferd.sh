#!/bin/bash

read m
read n

totalSpace=$((m*n))
availableSpace=0

traffic=$(cat)

for ((i = 0; i < ${#traffic}; i++ )); do
    if [ "${traffic:$i:1}" == '.' ]; then
        let availableSpace++
    fi
done

echo $availableSpace $totalSpace | awk '{ printf "%.5f", $1 / $2 }'