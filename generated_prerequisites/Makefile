PROJECT := example
CSRCS := main.c
OUTDIR := build
GENDIR := gen_inc
GENDIR_SRC := ini
OBJDIR := .obj
DEPDIR := .deps

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d
COBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(CSRCS))
OUTFILE := $(OUTDIR)/$(PROJECT)

.PHONY: all
all: $(OUTFILE)

$(OUTFILE): $(COBJS)
	@echo "Linking $@"
	@$(CC) $(COBJS) -o $@

$(COBJS) : $(OBJDIR)/%.o : %.c $(DEPDIR)/%.d | $(DEPDIR) $(OBJDIR) $(OUTDIR)
	@echo "Compling $@"
	@$(CC) $(DEPFLAGS) -I$(GENDIR) -I. -c $< -o $@

$(DEPDIR):
	@mkdir -p $@

$(OBJDIR):
	@mkdir -p $@

$(OUTDIR):
	@mkdir -p $@

DEPFILES := $(patsubst %.c,$(DEPDIR)/%.d,$(CSRCS))
$(DEPFILES):

include $(wildcard $(DEPFILES))

$(GENDIR)/config.h : $(GENDIR_SRC)/config.ini
	@echo "Generating $@"
	@mkdir -p $(dir $@) &&\
		cp $< $@

.PHONY: clean gen

gen : $(GENDIR)/config.h

clean:
	@echo "Removing $(GENDIR)/ $(DEPDIR)/ $(OBJDIR)/ $(OUTDIR)/"
	@rm -rf $(GENDIR) $(DEPDIR) $(OBJDIR) $(OUTDIR)
