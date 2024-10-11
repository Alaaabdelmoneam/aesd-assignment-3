#!/bin/bash

if [ $# -ne 2 ]; then
    echo "Error: Two arguments required - writefile and writestr"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"

if ! echo "$writestr" > "$writefile"; then
    echo "Error: Could not write to $writefile"
    exit 1
fi
