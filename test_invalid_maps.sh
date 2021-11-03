#!/bin/bash

for file in maps/invalid/*
do
	echo "$file"
	[ -f "$file" ] || continue
	./lem-in < "$file" > /dev/null
done
