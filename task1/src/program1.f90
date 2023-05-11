PROGRAM MATRIX_MULTIPLICATION
    IMPLICIT NONE
    INTEGER :: i, j, n, invert
    CHARACTER(len = 40) :: n_char
    CHARACTER(len = 1) :: invert_char
    REAL :: start_time, end_time, time_elapsed
    REAL, DIMENSION(:,:), ALLOCATABLE :: A
    REAL, DIMENSION(:), ALLOCATABLE :: b, c
  
    ! Recebe o tamanho da matriz  e se o loop deve ser invertido como parâmetro do usuário
    call getarg(1,n_char)
    call getarg(2,invert_char)

    read(n_char,*) n
    read(invert_char,*) invert

    ALLOCATE(A(n,n))
    ALLOCATE(b(n))
    ALLOCATE(c(n))
  
    ! Inicializa as matrizes com valores aleatórios e o vetor c em 0
    CALL RANDOM_NUMBER(A)
    CALL RANDOM_NUMBER(b)
    c = 0.0

    ! Inicia a contagem de tempo
    CALL CPU_TIME(start_time)
  
    ! Realiza a multiplicação da matriz pelo vetor
    IF (invert == 0) THEN
        DO i = 1, n
            DO j = 1, n
            c(i) = c(i) + A(i,j) * b(j)
            END DO
        END DO
    ELSE
        DO j = 1, n
            DO i = 1, n
                c(i) = c(i) + A(i,j) * b(j)
            END DO
        END DO
    END IF
    ! Finaliza a contagem de tempo
    CALL CPU_TIME(end_time)
    time_elapsed = end_time - start_time

    WRITE(*,*) time_elapsed
  

    DEALLOCATE(A)
    DEALLOCATE(b)
    DEALLOCATE(c)
  
  END PROGRAM MATRIX_MULTIPLICATION