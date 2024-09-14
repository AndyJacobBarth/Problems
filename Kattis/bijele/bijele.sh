#!/bin/bash

expected=(1 1 2 2 2 8)

read -a pieces

for i in {0..5}; do
    expected[$i]=$((expected[$i] - pieces[$i]))
done

for i in "${expected[@]}"; do
    echo -n "$i "
done

echo