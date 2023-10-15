#!/bin/bash

# Read and print the maximum process ID (PID) value from /proc/sys/kernel/pid_max
pid_maxval=$(cat /proc/sys/kernel/pid_max)

echo "Maximum value of a Process ID (PID) is: $pid_maxval"
