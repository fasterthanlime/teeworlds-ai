.PHONY: all test

all:
	cd ooc-ai && ooc AI.ooc -c -noclean -outpath=out -v && cd ../ && touch src/game/client/components/controls.cpp && bam -v

test:
	make all && ./teeworlds_d
