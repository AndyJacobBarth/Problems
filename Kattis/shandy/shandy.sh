#!/bin/bash

read B
read L

if [[ $B -lt $L ]]; then
    echo $((2*B))
else
    echo $((2*L))
fi