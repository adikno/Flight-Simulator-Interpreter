# Flight-Simulator-Interpreter

In order to activate the program you should do the following:
- [ ] Implement two arguments in the flightGear's setting:
1. --generic=socket,out,10,XXX.XXX.XXX.XXX,5400,tcp,generic_small
(when XXXX refers to the IP of the computer that runs the interpreter)
2. --telnet=socket,in,10,XXX.XXX.XXX.XXX,5402,tcp
(when XXXX refers to the IP of the computer that runs the simulator)

- [ ] Put the included "generic_small.xml" file inside the FlightGear installation folder "data/Protocol".

Then, you will be able to run the program and the simulator, in this order.

The interpreter supports both command-line input and file input.

The interpreter will run until "exit" command is sent.

The interpreter lexes the input, then parses it. In case the command and parameters are valid (according to the flightGear), they will be executed immediately
test.txt contains valid script for flying the plane.
