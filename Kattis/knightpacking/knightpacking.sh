#!/bin/bash

read N

if [[ $(( N & 1 )) -eq 1 ]]; then
    echo "first"
else
    echo "second"
fi