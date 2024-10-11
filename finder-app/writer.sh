#!/bin/bash

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required - writefile and writestr"
    exit 1
fi

writefile=$1
writestr=$2

# Attempt to create the directory if it doesn't exist
mkdir -p "$(dirname "$writefile")"

# Try to write to the file, handle any errors
if ! echo "$writestr" > "$writefile"; then
    echo "Error: Could not write to $writefile"
    exit 1
fi
