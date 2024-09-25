#!/bin/bash

read date

if [[ "$date" == "OCT 31" || "$date" == "DEC 25" ]]; then
    echo "yup"
else
    echo "nope"
fi