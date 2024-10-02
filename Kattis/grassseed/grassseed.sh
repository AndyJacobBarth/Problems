#!/bin/bash

read C
read L
totalArea=0

while [[ $L -gt 0 ]]; do
    read l w

    totalArea=$(echo "$totalArea $l $w" | awk '{
        printf "%.6f", $1 + $2 * $3
    }')

    ((L--))
done

echo "$C $totalArea" | awk '{
    printf "%.6f\n", $1*$2 
}'