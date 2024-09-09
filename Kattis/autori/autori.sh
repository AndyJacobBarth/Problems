#!/bin/bash

read names

echo $names | grep -o '[A-Z]' | tr -d '\n'

echo