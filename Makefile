# Street Fighter III 3rd Strike - CPS3 program ROM (same steps as build.bat)
BIN = bin
PYTHON ?= python
export SHC_LIB ?= $(CURDIR)/bin
export SHC_TMP ?= C:\TEMP

CFLAGS = -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include
OPT = -optimize=1 -speed

# modules compiled with other settings
NOINLINE = Entry entry_2 SYS_sub sel_pl next_cpu game_config_jp game_config_en CMD_MAIN cmd_main_2 ta_sub \
	end_main end_4 sc_trans VITAL count sc_sub sc_sub_2 EFF15 EFF25 EffD8 effe6 PLCNTSET plcntset_2 \
	PLSGAUGE textsound textsound_2 textsound_3
OPT0 = family sys_test sys_test_2 sys_test_2b sys_test_2c sys_test_3 sys_test_4 sys_test_5 coin_sw eeprom \
	sys_config sys_config_2 sys_config_3 spr_pool spr_pool_2 simmram_slot poly_que spr_list cram_bank

$(NOINLINE:%=obj/%.obj): OPT += -noinline
$(OPT0:%=obj/%.obj): OPT = -optimize=0 -nospeed

# the link order is sf3.sub's
SRCS = $(wildcard src/*.c src/*.src data/*.c data/*.src lib/*.src)
OBJS = $(patsubst %,obj/%.obj,$(basename $(notdir $(SRCS))))
vpath %.c src data
vpath %.src src data lib

# the tools take Windows paths (asmsh reads / as an option)
win = '$(subst /,\,$1)'

all: build/prog.bin

# the compiler writes its internal tables to stdout: keep them in a log, show only errors. Each compile gets
# its own temporary directory: two compilers sharing one fail with an internal error under make -j
obj/%.obj: %.c | obj
	@echo $<
	@mkdir -p "$(SHC_TMP)/$(*F)"; SHC_TMP='$(SHC_TMP)\$(*F)' \
		$(BIN)/shc.exe $(call win,$<) $(CFLAGS) $(OPT) -object=$(call win,$@) >$(@:.obj=.log) 2>&1; \
		r=$$?; rm -rf "$(SHC_TMP)/$(*F)"; [ $$r = 0 ] || { grep ') : ' $(@:.obj=.log); exit 1; }; rm -f $(@:.obj=.log)

obj/%.obj: %.src | obj
	$(BIN)/asmsh.exe $(call win,$<) -object=$(call win,$@)

# shc writes no dependency lists, so a header change rebuilds everything
$(OBJS): $(wildcard include/*.h)

obj:
	mkdir -p obj "$(SHC_TMP)"

sf3.abs: $(OBJS) sf3.sub
	$(BIN)/lnk.exe -subcommand=sf3.sub

sf3.bin: sf3.abs
	$(BIN)/rof2bin.exe -s=06000000 -e=07000000 -v=00 sf3.abs

build/cg.bin: rom/sfiii3nr1.zip
	$(PYTHON) tools/cps3rom.py extract $< $@

build/prog.bin: sf3.bin build/cg.bin
	$(PYTHON) tools/cps3rom.py pack sf3.bin build/cg.bin rom/sfiii3nr1.zip build

clean:
	rm -rf obj build sf3.abs sf3.map sf3.bin

.PHONY: all clean
