#!/bin/bash

read comp_string
comp_string_length=${#comp_string}

for ((i=0;i<comp_string_length;i++)) do
    if [[ "${comp_string:i:1}" == 's' ]]; then
        if [[ "${comp_string:i+1:1}" == 's' ]]; then
            echo "hiss"
            exit
        else
            ((i++))
        fi
    fi
done

echo "no hiss"