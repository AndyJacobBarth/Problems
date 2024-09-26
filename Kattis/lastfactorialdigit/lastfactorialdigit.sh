#!/bin/bash

read T

while [[ $T -gt 0 ]]; do
    read N

    if [[ $N -eq 1 || $N -eq 2 || $N -eq 4 ]]; then
        echo "$N"
    elif [[ $N -eq 3 ]]; then
        echo 6
    else
        echo 0
    fi

    ((T--))
done