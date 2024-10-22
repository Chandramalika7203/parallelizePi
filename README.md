# parallelizePi
Seraial and parallel code for calculating the value of pi using C++ and OpenMP

## output of serial_pi.cpp
Serial Calculation of Pi: 3.14159
Duration: 0.00231759 seconds

## output while using array for storing sum from each thread
Parallel Calculation of Pi: 3.14159
Duration: 0.00294671 seconds

### Command to find cache size: 
cat /proc/cpuinfo| grep cache

## output while using padded array (to optimize the delay caused by false sharing)
Parallel Calculation of Pi using padded array: 3.14159
Duration: 0.00140785 seconds

## output while using locking construct - critical
Parallel Calculation of Pi using critical: 3.14159
Duration: 0.00113102 seconds