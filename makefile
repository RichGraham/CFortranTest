FCFLAGS = -ffree-form
F90= x86_64-apple-darwin14.3.0-gfortran-5
CFLAGS= -O3
CC= gcc

SOURCES= Example.c FortranCode.f90
OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))
PRODUCT= merged.out


$(PRODUCT): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
%.o: %.f90 
	$(F90) -c $(FCFLAGS) -o $@ $<



clean:
	rm -f *.o
