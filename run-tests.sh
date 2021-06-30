#! /bin/bash
mkdir maps/

for (( i=1; i<=9; i++ ))
do  
    perl map_generator.pl 10 10 3 > "maps/map_$i.txt"
done

for (( i=1; i<=9; i++ ))
do  
    echo "=========================[$i]===========================\n\n"
    echo "TEST #$i\n"
    ./my_bsq maps/map_$i.txt > maps/map_$i.solution.txt
    echo "Map ⬇️:\n"
    cat maps/map_$i.txt
    echo "\n----\n"
    echo "Solution ⬇️:\n"
    cat maps/map_$i.solution.txt
    echo "\n----\n"
    echo "Diff ⬇️:\n"
    diff maps/map_$i.txt maps/map_$i.solution.txt
    echo "=========================[$i]===========================\n\n"
done

