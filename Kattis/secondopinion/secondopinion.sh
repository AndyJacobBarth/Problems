#!/bin/bash

read s

hours=$((s/3600))
let s-=3600*$hours
minutes=$((s/60))
let s-=60*minutes

echo "$hours : $minutes : $s"