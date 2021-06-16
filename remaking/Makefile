.PHONY: clean all


-include module.mk

SRC := foo.c bar.c $(MODULE_SRC)
SRCBUILT := $(foreach f,$(SRC),$(f).built)
$(info restarts = $(MAKE_RESTARTS))
$(info SRC = $(SRC))

all: PRE_MAKE_ALL_HOOK $(SRCBUILT)

$(SRCBUILT): $(SRC)
	@echo built $@
	@touch $@

MODULE_FILES = module.c module.mk

PRE_MAKE_ALL_HOOK: $(MODULE_FILES)

$(MODULE_FILES) &: module.template
	@echo "generating module"
	@touch module.c
	@echo "MODULE_SRC = module.c" > module.mk

clean:
	@echo - module.mk
	@echo - module.c
	@echo - *.built
	@rm -f module.mk 2>/dev/null
	@rm -f module.c 2>/dev/null
	@rm -f *.built 2>/dev/null
