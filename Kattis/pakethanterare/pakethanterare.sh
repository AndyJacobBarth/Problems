#!/bin/bash

read t b
read -a stores
declare -A currentVersion

for ((i=0;i<t;i++)); do
    read packageType v
    currentVersion["$packageType"]="$v"
done

for store in "${stores[@]}"; do
    versionDifference=0

    for ((j=0;j<store;j++)); do
        read packageType v
        ((versionDifference+=${currentVersion[$packageType]}-v))
    done

    echo $versionDifference
done