#!/bin/bash

read userInput

if [[ $userInput == *"COV"* ]]; then
    echo "Veikur!"
else
    echo "Ekki Veikur!"
fi