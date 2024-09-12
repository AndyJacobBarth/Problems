#!/bin/bash

read n k
index=1

read -a a1a2an

for i in "${!a1a2an[@]}"; do
    if [ "${a1a2an[$i]}" -eq "$k" ]; then
        if [ "$index" -eq 1 ]; then
            echo "fyrst"
            exit 0
        elif [ "$index" -eq 2 ]; then
            echo "naestfyrst"
            exit 0
        else
            echo "$index fyrst"
            exit 0
        fi
    fi
    let index++
done