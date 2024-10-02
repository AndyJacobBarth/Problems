#!/bin/bash

read hey
heyLength="${#hey}"

echo -n "h"

for ((i=0;i<heyLength-2;i++)); do
    echo -n "ee"
done

echo "y"