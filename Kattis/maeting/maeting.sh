#!/bin/bash

read n m

read -a monday
read -a tuesday

tuesday=$(printf "%s\n" "${tuesday[@]}" | sort)

for student in "${monday[@]}"; do
    # q for quiet, w to prevent substring matching
    if (echo "$tuesday" | grep "$student" -qw); then
        echo -n "$student "
    fi
done
echo