import EagleAI, NddAI, Ndd2AI, AI

getAI: unmangled func -> AI {
    return Ndd2AI new()
	//return NddAI new()	
    //return EagleAI new()
}
