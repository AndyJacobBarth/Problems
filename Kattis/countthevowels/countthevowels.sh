#!/bin/bash

read s
vowels="aeiouAEIOU"
total=0

for ((i=0;i<${#s};i++)); do
    for ((j=0;j<10;j++)); do
        if [[ "${s:$i:1}" == "${vowels:$j:1}" ]]; then
            ((total++))
        fi
    done
done

echo $total