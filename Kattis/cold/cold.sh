#!/bin/bash

read n
read -a temps
total=0

for temp in "${temps[@]}"; do
    if [ $temp -lt 0 ]; then
        let total++
    fi
done

echo $total