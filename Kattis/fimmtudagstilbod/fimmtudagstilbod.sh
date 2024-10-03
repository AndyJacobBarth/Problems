#!/bin/bash

read y

if [[ $y -lt 2020 ]]; then
    echo 1000
else
    echo $((1000+100*(y-2020)))
fi