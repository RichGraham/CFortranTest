F90= gfortran
CFLAGS= -O3
CC= gcc

OBJS=Example.o  FortranCode.o


cpp-exe: $(OBJS)
	$(CC) -o merged.out $(OBJS)
.c.o:
	$(CC) $(CFLAGS) -c $<

.f.o:
	$(F90) -c  $<	
