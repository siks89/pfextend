## PForth interpreter expansion for observation of a running program

Here you can find PForth expansion that provides a MesagePack compatible interface that support observation of a running program.

---

To build expanded PForth run make in the project's root directory. This will compile PForth and all the support programs. If everything was build successfully, an out directory will be created with the following files:
* pforth_standalone - the modified version of PForth
* monitor.out - a monitor program
* analyser.out - a simple data analyser used for the test cases
* auto_run_monitor.sh - a script that runs everything necessary for monitor to work
* auto_run_analyser.sh - a script that runs everything necessary for analyser to work

---

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

##### Warning:
The expansion was only tested on GNU/Linux OS.