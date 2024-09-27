#!/bin/bash

read N
inventory=("keys" "phone" "wallet")

while [[ $N -gt 0 ]]; do
    read item

    for ((i=0;i<3;i++)); do
        if [[ "$item" == "${inventory[$i]}" ]]; then
            unset 'inventory[i]'
        fi
    done

    ((N--))
done

if [[ "${#inventory[@]}" -eq 0 ]]; then
    echo "ready"
else
    for essentials in "${inventory[@]}"; do
        echo "$essentials"
    done
fi