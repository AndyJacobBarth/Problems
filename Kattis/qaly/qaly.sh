#!/bin/bash

read N
sum=0

while [[ $N -gt 0 ]]; do
    read q y
    sum=$(echo "$q $y $sum" | awk '{
        printf "%.3f", $3 + $1 * $2;
    }')

    ((N--))
done

echo $sum