#VMD's version of makefile
#Makefile to compile more than one C files with headers, objects, sources and 
#executables in separate folders

#Comment out the unnecessary content

CC				:=		gcc
SRCS			:=		main.c

vmd:  
	gcc ${SRCS} -Wall -L . -ladt  

libadt.a:adt.o
	ar rv $@ $^

adt.o:adt.c
	${CC} -Wall -c $^

clean:
	-rm -f *.exe *~ core *.o $(EXEC_NAME) *.out *.a


				 
