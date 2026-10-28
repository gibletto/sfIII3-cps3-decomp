# Street Fighter III 3rd Strike - CPS3 program ROM (same steps as build.bat)
BIN = bin
PYTHON ?= python
# relative: SHC refuses an SHC_LIB longer than 116 characters
export SHC_LIB ?= bin
export SHC_TMP ?= C:\TEMP

# the compiler revision that built 3rd Strike (see README.md, Compiler)
export MDL_EQ_CONST = 3

CFLAGS = -cpu=sh2 -division=cpu -endian=big -pic=0 -extra=m=8,a=8 -nortnext -include=include
OPT = -optimize=1 -speed

# modules compiled with other settings
NOINLINE = entry_2 sel_pl CMD_MAIN EffD8
OPT0 = family sys_test sys_test_2 iotest_out soundtest colortest sys_test_2a sys_test_2b sys_test_2c \
	sys_test_3 sys_test_4 sys_test_5 coin_sw coin_sw_2 eeprom sys_config sys_config_2 sys_config_3 \
	spr_pool spr_pool_2 simmram_slot poly_que spr_list cram_bank
CONSTTBL = entry_2 Com_Pl SYS_sub Game_Main demo00 demo02_code RANKING Manage manage_2 win_2 continue sel_pl \
	next_cpu game_config_main game_config_jp game_config_en CMD_MAIN tate00 bg000 bg020 bg040 BG050 \
	bg090 bg100 bg120 bg130 bg140 bg150 bg160 bg190 bonus_bg bns_bg2 appear win_pl lose_pl end_main \
	end_1 end_2 end_3 end_5 end_6 end_7 end_8 end_9 end_10 end_11 end_12 end_13 end_14 end_16 end_17 \
	end_18 end_19 end_20 end_sub_3 end_sub_4 end_sub_5 end_sub_6 end_sub_7 end_sub_7b end_sub_7c \
	color3rd eff35 EFF48 EFF85 EFF86 eff94 effe6 efff5 efff7 effh5 EFFJ8 effL3 effM0 textsound_2
AGGRESSIVE = Entry

$(NOINLINE:%=obj/%.obj): OPT += -noinline
$(AGGRESSIVE:%=obj/%.obj): OPT += -aggressive=1
$(OPT0:%=obj/%.obj): OPT = -optimize=0 -nospeed
$(CONSTTBL:%=obj/%.obj): CFLAGS += -section=const=CTBL

# the link order is sf3.sub's
SRCS = $(wildcard src/*.c src/*.src data/*.c data/*.src lib/*.src)
OBJS = $(patsubst %,obj/%.obj,$(basename $(notdir $(SRCS))))
vpath %.c src data
vpath %.src src data lib

# the tools take Windows paths (asmsh reads / as an option)
win = '$(subst /,\,$1)'

all: build/prog.bin

# the compiler writes its internal tables to stdout: keep them in a log, show its messages. Each compile gets
# its own temporary directory: two compilers sharing one fail with an internal error under make -j
obj/%.obj: %.c | obj
	@echo $<
	@mkdir -p "$(SHC_TMP)/$(*F)"; SHC_TMP='$(SHC_TMP)\$(*F)' \
		$(BIN)/shc.exe $(call win,$<) $(CFLAGS) $(OPT) -object=$(call win,$@) >$(@:.obj=.log) 2>&1; \
		r=$$?; rm -rf "$(SHC_TMP)/$(*F)"; grep ') : ' $(@:.obj=.log); rm -f $(@:.obj=.log); [ $$r = 0 ]

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
