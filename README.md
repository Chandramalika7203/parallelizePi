# parallelizePi
Seraial and parallel code for calculating the value of pi using C++ and OpenMP

### output of serial_pi.cpp
Serial Calculation of Pi: 3.14159
Duration: 0.00219134 seconds

### output while using array for storing sum from each thread
##### 4 threads
Parallel Calculation of Pi: 3.14159
Duration: 0.00305163 seconds
##### 16 threads
Parallel Calculation of Pi: 3.14159
Duration: 0.00346577 seconds

#### Command to find cache size: 
cat /proc/cpuinfo| grep cache

### output while using padded array (to optimize the delay caused by false sharing)
##### 4 threads
Parallel Calculation of Pi using padded array: 3.14159
Duration: 0.000993503 seconds
##### 16 threads
Parallel Calculation of Pi using padded array: 3.14159
Duration: 0.00102403 seconds

### output while using locking construct - critical
##### 4 threads
Parallel Calculation of Pi using critical: 3.14159
Duration: 0.000822263 seconds
##### 16 threads
Parallel Calculation of Pi using critical: 3.14159
Duration: 0.000803239 seconds

### output while using a reduction
##### 4 threads
Parallel Calculation of Pi using a reduction: 3.14159
Duration: 0.000767739 seconds
##### 16 threads
Parallel Calculation of Pi using a reduction: 3.14159
Duration: 0.000763791 seconds


## Speedups for the codes w.r.t the serial code => 0.00219134/time

| No. of threads| code      | Time(sec)   | Speed up    |  
| ------------- | ----------| ----------  | ----------- |
| 4             | Array     | 0.00305163  | 0.718088366 |
| 4             | Padded    | 0.000993503 | 2.20567024  |
| 4             | Critical  | 0.000822263 | 2.665011073 |
| 4             | Reduction | 0.000767739 | 2.8542773   |
| 16            | Array     | 0.00346577  | 0.63228085  |
| 16            | Padded    | 0.00102403  | 2.139917776 |
| 16            | Critical  | 0.000803239 | 2.728129486 |
| 16            | Reduction | 0.000763791 | 2.869030926 |


