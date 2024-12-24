#!/bin/bash

# Check if a 4-digit integer is provided
if [ $# -ne 1 ]; then
    echo "Error: Please provide exactly one 4-digit integer as argument"
    echo "Usage: $0 <4-digit-integer>"
    exit 1
fi

# Check if the input is a 4-digit integer
if ! [[ $1 =~ ^[0-9]{4}$ ]]; then
    echo "Error: Input must be a 4-digit integer"
    exit 1
fi

# Generate SHA-512 hash
hash=$(echo -n "$1" | sha512sum | awk '{print $1}')

# Output the hash
echo "Input: $input"
echo "Hash: $hash"

# Save to file
echo "$hash" > hash_output.txt
