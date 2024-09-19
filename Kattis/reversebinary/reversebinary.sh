#!/bin/bash

read N
answer=0

while [ $N -gt 0 ]; do
    answer=$(( answer << 1 ))
    answer=$(( answer + (N & 1) ))
    N=$(( N >> 1 ))
done

echo "$answer"