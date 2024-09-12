#!/bin/bash

read strings

echo "$strings" | awk '{gsub(/ /, ""); print}'