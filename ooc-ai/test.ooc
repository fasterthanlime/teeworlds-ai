import AI, os/Time

main: func {
	
	"Starting.." println()
	
	ai := getAI()
	
	while(true) {
		
		Time sleepMilli(20)
		printf("Got action ")
		ai step(Time microtime() * 0.000_001) print()
		println()
		
	}
	
}
