.PHONY = diffs clean

FROM ?= /home/zputrle/Downloads/pforth
TO ?= /home/zputrle/develompent/diploma_dev/diploma/dev/pforth

all: diffs
	
diffs:
	diff -u ${FROM}/build/unix/Makefile ${TO}/build/unix/Makefile \
		> makefile_diff.txt; test $$? -eq 1
	diff -u ${FROM}/csrc/pf_inner.c ${TO}/csrc/pf_inner.c \
		> pf_inner_c_diff.txt; test $$? -eq 1
	diff -u ${FROM}/csrc/pf_core.c ${TO}/csrc/pf_core.c \
		> pf_core_c_diff.txt; test $$? -eq 1
	diff -u ${FROM}/csrc/pf_main.c ${TO}/csrc/pf_main.c \
		> pf_main_c_diff.txt; test $$? -eq 1
	diff -u ${FROM}/csrc/pf_all.h ${TO}/csrc/pf_all.h \
		> pf_all_h_diff.txt; test $$? -eq 1
clean:
	rm *_diff.txt
