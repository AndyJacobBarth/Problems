#!/bin/bash

read n m
forecasts=()

for ((i=0;i<n;i++)); do
    read -a line
    forecasts+=("${line[@]}")
done

for ((i=1;i<n-1;i++)); do
    for ((j=1;j<m-1;j++)); do
        currentForecast=${forecasts[i*m+j]}
        if [[ ${forecasts[(i-1)*m+j]} -gt currentForecast &&
              ${forecasts[(i+1)*m+j]} -gt currentForecast &&
              ${forecasts[i*m+(j-1)]} -gt currentForecast &&
              ${forecasts[i*m+(j+1)]} -gt currentForecast ]]; then
            echo "Jebb"
            exit
        fi
    done
done

echo "Neibb"