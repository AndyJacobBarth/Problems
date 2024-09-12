#!/bin/bash

read n

echo "$n" | grep -o '[a-zA-Z]' | wc -l