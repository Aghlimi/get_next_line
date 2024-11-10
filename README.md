#!/bin/bash

# Get the system information and display it every 10 minutes on all terminals
while true; do
    wall "
#Architecture: $(uname -a)
#CPU physical: $(lscpu | grep 'Socket(s):' | awk '{print $2}')
#vCPU: $(lscpu | grep '^CPU(s):' | awk '{print $2}')
#Memory Usage: $(free -m | awk 'NR==2{printf "%s/%sMB (%.2f%%)", $3, $2, $3*100/$2}')
#Disk Usage: $(df -h --total | grep 'total' | awk '{print $3 "/" $2 " (" $5 ")"}')
#CPU load: $(top -bn1 | grep "Cpu(s)" | awk '{printf "%.1f%%", $2 + $4}')
#Last boot: $(who -b | awk '{print $3 " " $4}')
#LVM use: $(lsblk | grep -q 'lvm' && echo "yes" || echo "no")
#Connections TCP: $(ss -s | grep 'TCP:' | awk '{print $2}')
#User log: $(who | wc -l)
#Network: IP $(hostname -I | awk '{print $1}') ($(ip link show | awk '/ether/ {print $2}'))
#Sudo: $(grep -c 'COMMAND=' /var/log/sudo/sudo.log) cmd
"
    sleep 600 # Wait for 10 minutes
done
