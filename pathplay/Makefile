SRC_DIRS = path/to/A/src path/to/B/src path/to/C/src

GEN_DIRNAME = gen

SRC = $(foreach _path,$(SRC_DIRS),$(wildcard $(_path)/*))
$(info SRC = $(SRC))

DIR_SRC := $(dir $(SRC))
$(info DIR_SRC = $(DIR_SRC))

PATSUBST_SRC := $(patsubst %/,%,$(DIR_SRC))
$(info PATSUBST_SRC = $(PATSUBST_SRC))

DIR_PATSUBST_SRC := $(dir $(PATSUBST_SRC))
$(info DIR_PATSUBST_SRC = $(DIR_PATSUBST_SRC))

ADDSUFFIX_DIR_PATSUBST_SRC := $(addsuffix $(GEN_DIRNAME)/,$(DIR_PATSUBST_SRC))
$(info ADDSUFFIX_DIR_PATSUBST_SRC = $(ADDSUFFIX_DIR_PATSUBST_SRC))

SRC_FILENAMES = $(notdir $(SRC))
$(info SRC_FILENAMES = $(SRC_FILENAMES))

GEN_FILENAMES_C = $(patsubst %.xml, %.c, $(SRC_FILENAMES))
GEN_FILENAMES_H = $(patsubst %.xml, %.h, $(SRC_FILENAMES))

GEN_FILES_C = $(join $(ADDSUFFIX_DIR_PATSUBST_SRC), $(GEN_FILENAMES_C))
GEN_FILES_H = $(join $(ADDSUFFIX_DIR_PATSUBST_SRC), $(GEN_FILENAMES_H))
$(info GEN_FILES_C = $(GEN_FILES_C))
$(info GEN_FILES_H = $(GEN_FILES_H))
