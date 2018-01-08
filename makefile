# simple make file
SOURCES=FortranCode.f90
PRODUCT=FC.fort


all: $(PRODUCT)

$(PRODUCT) : $(SOURCES)
	gfortran -o $(PRODUCT) $(SOURCES)
