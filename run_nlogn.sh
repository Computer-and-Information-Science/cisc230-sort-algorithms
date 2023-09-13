#!/bin/bash

# Run a.out with array sizes of 1,000,000 to 25,000,000 in increments of 1,000,000.
# Assumes that a.out exists and is compiled using one of the N log N sort
# algorithms.

for size in $(seq 1000000 1000000 25000000); do
	echo $size,$(./a.out $size | grep seconds | awk '{ print $3; }')
done