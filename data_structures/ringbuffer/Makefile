LOCAL_PATH = $(call my-dir)

INC_DIRS = \
	-I./inc \
	-I../CuTest

SRC_FILES = \
	src/$(ARGUMENT).c \
	test/$(ARGUMENT)_unit_test.c \
	test/output/$(ARGUMENT)_tc_list.c \
	../CuTest/CuTest.c

FLAGS = \

default:
	@gcc -g -Wall -o test/output/$(ARGUMENT).exe $(SRC_FILES) $(INC_DIRS) $(FLAGS)

clean:
	@rm -rf test/output

