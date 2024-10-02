#!/bin/bash

read n m
numBombs=0
bombLocations=()

for ((i=0;i<n;i++)); do
    read row

    for ((j=0;j<m;j++)); do
        if [[ ${row:j:1} == '*' ]]; then
            ((numBombs++))

            bombLocations+=("$((i+1)) $((j+1))")
        fi
    done
done

echo $numBombs

for location in "${bombLocations[@]}"; do
    echo "$location"
done