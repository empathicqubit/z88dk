include ../../Make.config

TARGET = newbrain

SUBDIRS = fcntl
CLEANDIRS = $(SUBDIRS:%=%-clean)

ASMFILES = 
OBJECTS = $(ASMFILES:.asm=.o)

all: dirs subdirs-all $(addprefix obj/$(TARGET)/,$(OBJECTS))


subdirs-all: $(SUBDIRS)

subdirs-clean: $(SUBDIRS_CLEAN)


clean: subdirs-clean
	$(RM) -r obj
	$(RM) zcc_opt.def *.err *.o

subdirs-clean: $(CLEANDIRS)

obj/$(TARGET)/%.o: %.asm
	@$(ASSEMBLER) -DFOR$(TARGET) -I../..  $^
	@mv $(^:.asm=.o) $@

dirs:
	@mkdir -p obj/$(TARGET)

.PHONY:	subdirs-all $(SUBDIRS) $(SUBDIRS_CLEAN)

$(SUBDIRS):
	$(MAKE) -C $@ all

$(CLEANDIRS):
	$(MAKE) -C $(@:%-clean=%) clean
	$(RM) */*.o
	$(RM) -r obj
	$(RM) zcc_opt.def
