.PHONY: clean clean_create clean_build clean_objects help

PFORTH_REPO_URL = https://github.com/philburk/pforth

OUT_DIR ?= out

PFORTH_NAME = pforth_standalone
MONITOR_NAME = monitor.out
ANALYSER_NAME = analyser.out

all:
	make create
	make build
	make clean_objects

create:
	git clone $(PFORTH_REPO_URL)
	patch pforth/csrc/pf_main.c diffs/pf_main_c_diff.txt
	patch pforth/csrc/pf_core.c diffs/pf_core_c_diff.txt
	patch pforth/csrc/pf_inner.c diffs/pf_inner_c_diff.txt
	patch pforth/csrc/pf_all.h diffs/pf_all_h_diff.txt
	patch pforth/build/unix/Makefile diffs/makefile_diff.txt
	cp monitor/mnt_common.h pforth/csrc/
	cp monitor/mnt_common.c pforth/csrc/
	cp monitor/cmp.h pforth/csrc/
	cp monitor/cmp.c pforth/csrc/

build:
	mkdir -p $(OUT_DIR)
	cd monitor && make
	cp monitor/$(MONITOR_NAME) $(OUT_DIR)
	cd pforth/build/unix/ && make
	cp pforth/build/unix/$(PFORTH_NAME) $(OUT_DIR)
	cd analyser && make
	cp analyser/$(ANALYSER_NAME) $(OUT_DIR)
	cp scrpits/auto_run_analyser.sh $(OUT_DIR)
	cp scrpits/auto_run_monitor.sh $(OUT_DIR)

clean_create:
	rm -rf pforth

clean_build:
	rm -rf $(OUT_DIR)
	make clean_objects

clean_objects:
	cd monitor && make clean
	cd pforth/build/unix/ && make clean
	cd analyser/ && make clean

clean: 
	make clean_objects; make clean_build; make clean_create

help:
	@echo "<<< HELP >>>"
	@echo "make information:"
	@echo "> 'make' or 'make all' => Calls make create and make build."
	@echo "> 'make create' => Creates the modified pforth project."
	@echo "> 'make build' => Builds and stores the executables in the OUT_DIR directory (default 'out')."
	@echo "> 'make clean' => Clears the projects directory."
