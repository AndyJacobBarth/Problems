#!/bin/bash

read n

if [[ "${n: -1}" -eq '0' ]]; then
    echo "Jebb"
else
    echo "Neibb"
fi