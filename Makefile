.PHONY: all test

all:
	cd ooc-ai && ooc ooc-ai.ooc -c -v && cd ../ && touch src/game/client/components/controls.cpp && bam -v

test:
	make all && ./teeworlds_d
