## PForth monitoring interface expansion

This is PForth monitoring interface expansion. It's intended to provide clear
monitoring interface for the PForth interpreter.

To build run:
```sh
> make
```
in the root directory.

This will create the out folder in which there are five files.
* monitor.out - is a monitor program.
* pforth_standalone - is a modified version of PFortha
* analyser.out - simple data analyser used for the test cases.
* auto_run_monitor.sh - script that runs everything necessery for monitor
    to work.
* auto_run_analyser.sh - script that runs everything necessery for analyser
    to work.


To start the monitor run
```sh
> ./auto_run_monitor <path_to_file>
```
where <path_to_file> points to program that you want to monitor.

To start the analyser run
```sh
> ./auto_run_analyser <path_to_file>
```
where <path_to_file> points to program that you want to analyse.

The test cases are located in the example directory.

##### Dependencies:
Known dependencies: git, ed, make, binutils

##### Warning:
The modification was only tested on GNU/Linux. It's not intended to work under
any other OS.