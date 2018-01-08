module GP_variables
  integer :: nTraining
end module GP_variables

double precision function PES( rab)
  !! Takes in rab in Angstrom
  use GP_variables
  implicit none
  double precision rab

  PES=nTraining*rab**2

end function PES


subroutine setVars
  use GP_variables
  implicit none

  nTraining=3
  write(6,*) 'Hello from setVars'
  
end subroutine setVars
