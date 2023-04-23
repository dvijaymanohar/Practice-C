
SRCS			:= $(wildcard *.c)	
EXEC_NAME	:=	vmd
CC				:=	gcc
CC_OPTS		:=	-Wall -g


$(EXEC_NAME):$(SRCS)
	$(CC) $(CC_OPTS) $(SRCS)-o $@		

clean:
	rm -f a.out vmd *.*~ *~ *.o
