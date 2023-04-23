#VMD's Version of Makefile

CC				:=	gcc
CCOPTS			:=	-Wall -g
SRCS			:=	Main.c
LIB_SRC			:=	Lib.c
LIB_OP			:=  Lib.o	
LIB_A			:=	libStack
EXEC_NAME		:=	vmd

all: ${LIB_A} ${EXEC_NAME} Remove

${EXEC_NAME} : ${SRCS}
	${CC} ${CCOPTS} $< -L . -lStack -o $@ -g

${LIB_A} : libStack.a
	ranlib $<

libStack.a : ${LIB_OP}
	ar rc $@ $<

${LIB_OP} : ${LIB_SRC}
	${CC} -c $< -o $@

Remove :
	rm -rf *.o

clean: 
	rm -rf a.out *.o *.out *.*~ *~ vmd *.a *.exe


#In the all line, we have to give the dependecies in the order of requirement.
#Here in the very first case, we want the library and then after generating the 
#library, we have to compile the Main program linking the library.
##When we are generating the library, all the requirements for that library are 
#created.

