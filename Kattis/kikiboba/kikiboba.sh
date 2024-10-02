#!/bin/bash

read compString
b=0
k=0

for ((i=0;i<"${#compString}";i++)); do
    if [[ ${compString:i:1} == 'b' ]]; then
        ((b++))
    elif [[ ${compString:i:1} == 'k' ]]; then
        ((k++))
    fi
done

if [[ $b -eq 0 && k -eq 0 ]]; then
    echo "none"
elif [[ $b -lt $k ]]; then
    echo "kiki"
elif [[ $k -lt $b ]]; then
    echo "boba"
else
    echo "boki"
fi