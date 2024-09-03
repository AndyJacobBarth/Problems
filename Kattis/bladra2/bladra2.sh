#!/bin/bash

read v a t

awk "BEGIN {print $t * ($v + 0.5 * $a * $t)}"