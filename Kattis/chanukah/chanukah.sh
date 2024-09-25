#!/bin/bash

read P

while [[ $P -gt 0 ]]; do
    read K N

    echo "$K $((N*(N+3)/2))"

    ((P--))
done