PYTHON       = /usr/bin/python3
BUILD_DIR    = .build
CLANG_FORMAT = /usr/bin/clang-format-15
FLAGS        = -Werror -i

STAGED_FILE_LIST := $(shell git diff --name-only --cached -- '*.h' '*.hpp' '*.c' '*.cpp')

.PHONY: pretty pretty_all

help:
	@echo "make pretty -> prettier code"
	@echo "make readme -> generate readme file"

pretty:
ifneq ($(STAGED_FILE_LIST),)
	@for file in ${STAGED_FILE_LIST}; do \
		${CLANG_FORMAT} ${FLAGS} $$file; \
	done
else
	@echo "No files ready for commit! To execute "make pretty", please stage the files."
endif

pretty_all:
	@find ./ -type f \( -name '*.c' -o -name '*.cpp' \) -exec ${CLANG_FORMAT} ${FLAGS} {} \;

readme: clean
	@${PYTHON} ./${BUILD_DIR}/main.py

clean:
	@find ./ -type f \( -name '*.o' -o -name 'out' -o -name '*output*'  -o -name '*.out' \) -exec rm -rf {} \;
