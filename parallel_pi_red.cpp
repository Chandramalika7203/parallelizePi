#include <iostream>
#include <omp.h>
#include <chrono>

#define NUM_THREADS 4
// #define NUM_THREADS 16

double calculate_pi_reduction (int num_steps){

    double pi = 0.0;
    double step = 1.0/(double) num_steps;
    int i;
    double sum = 0;
    double x;

    // Set up the parallel loop
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel for reduction (+:sum) private (x)
    for ( i=0; i < num_steps; i++){
        x = (i+0.5)*step;
        // Sum over each's own sum counter
        sum += 4.0/(1.0+x*x);
    }

    pi = step * sum;

    return pi;

}    


int main() {
    int num_steps = 1000000;
    int n_repeat = 500;

    // Calculate and display the value of pi
    double parallel_pi = 0;
    
    // Run timer
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n_repeat ; i ++) parallel_pi += calculate_pi_reduction(num_steps);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> parallel_duration = end_time - start_time;

    // Print average results
    std::cout << "Parallel Calculation of Pi using a reduction: " << parallel_pi / n_repeat 
              << std::endl << "Duration: " << parallel_duration.count() / n_repeat << " seconds" << std::endl;
    
    return 0;
}
