!module GP_variables
!  integer :: nTraining=72 
!end module GP_variables




double precision function PES( rab)
  !! Takes in rab in Angstrom
 ! use PES_details
  implicit none
  double precision rab

  PES=rab**2

end function PES
