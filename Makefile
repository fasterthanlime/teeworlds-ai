.PHONY: all test

all:
	cd ooc-ai && rock ooc-ai.ooc -noshit -noclean -driver=sequence -g -c -v && cd ../ && touch src/game/client/components/controls.cpp && bam -v 

test:
	make all && ./teeworlds_d
