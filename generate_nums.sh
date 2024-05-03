#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 3 ]; then
    echo "Usage: $0 <number_of_numbers> <min> <max>"
    exit 1
fi

# Assign arguments to variables
num_numbers=$1
min=$2
max=$3

# Check if min is less than max
if [ "$min" -ge "$max" ]; then
    echo "Minimum must be less than maximum."
    exit 1
fi

# Generate random numbers with a comma and a space as separators
nums=$(for i in $(seq 1 $num_numbers); do echo -n "$((RANDOM % ($max - $min + 1) + $min))"; if [ "$i" -lt "$num_numbers" ]; then echo -n ", "; fi; done)

# Save to file
echo $nums > nums.txt

echo "Generated numbers saved in nums.txt"
