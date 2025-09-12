#!/bin/bash
username="$1"
./crackme5 "$username" "$(./keygen5 "$username")"
