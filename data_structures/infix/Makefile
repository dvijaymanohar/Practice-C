#VMD's version of makefile
#Makefile to compile more than one C files ..
#..with headers, objects, sources and executables in separate folders
#Comment the unnecessary content

CC				:=		gcc
SRCS			:=		$(wildcard *.c)
#HDRS 			:= 		../HDRS
OBJS			:=		$(SRCS:.c=.o)
EXEC_NAME		:=		vmd
#CFLAGS 		:=		-I${HDRS}
CCFLAGS			:=		-Wall 
TARBALL_NAME	:=		submit.tar

${EXEC_NAME}: ${OBJS} 
	${CC} ${CCFLAGS} $^ -o ${EXEC_NAME} 

${OBJS}:${SRCS}
	${CC} ${CCFLAGS} -c ${SRCS} ${CFLAGS} 
	
$(TARBALL_NAME): Makefile README $(SRCS) $(HDRS)
	tar -cvf $(TARBALL_NAME) Makefile README $(SRCS) $(HDRS)

handin: $(TARBALL_NAME)
	astep -c c201 -p assn1 $(TARBALL_NAME)

clear:
	 -rm -f *.exe *~ core *.o $(EXEC_NAME) *.out *.a

move:
	mv $(SRCS) ./Assign_Submit
#	 mv *.o ../OBJS
#	 mv *.out ../EXES

