VPATH = ./ : ../2Ar_PES # : ../CO2-Ar_PES

FCFLAGS = -O3
F90= gfortran
CFLAGS= -O3
CC= gcc


LIBS_PATH = -L/usr/local/Cellar/gcc/5.1.0/lib/gcc/5

SOURCES= Example.c   2Ar_PES_GP_Symm.f90 #CO2-Ar_PES_GP_Symm.f90
OBJECTS = $(addsuffix .o,$(basename $(SOURCES)))
PRODUCT= merged.out


$(PRODUCT): $(OBJECTS)
	$(CC) $(LIBS_PATH) -lgfortran -o  $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
%.o: %.f90 
	$(F90) -c $(FCFLAGS) -o $@ $<



clean:
	rm -f *.o
