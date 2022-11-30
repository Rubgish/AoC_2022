#!/bin/bash
day="day$1"
day_a="${day}a.cpp"
day_b="${day}b.cpp"
day_input="${day}_input"

cp template.cpp $day_a
cp template.cpp $day_b
cp input_template $day_input

sed -i "s/DAYNNN/${day}/g" $day_a
sed -i "s/DAYNNN/${day}/g" $day_b