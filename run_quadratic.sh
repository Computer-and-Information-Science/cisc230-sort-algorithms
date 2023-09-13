#!/bin/bash

# Run a.out with array sizes of 5,000 to 125,000 in increments of 5,000.
# Assumes that a.out exists and is compiled using one of the quadratic sort
# algorithms.

for size in $(seq 5000 5000 125000); do
	echo $size,$(./a.out $size | grep seconds | awk '{ print $3; }')
done