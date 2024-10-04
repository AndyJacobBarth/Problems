#!/bin/bash

read n
read -a words

for word in "${words[@]}"; do
    if [[ ${word:0:1} =~ [A-Z] ]]; then
        echo -n ${word:0:1}
    fi
done

echo