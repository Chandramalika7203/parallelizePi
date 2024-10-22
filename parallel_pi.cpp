#include <iostream>
#include <omp.h>
#include <chrono>

#define NUM_THREADS 4
// #define NUM_THREADS 16

double calculate_parallel_pi (int num_steps){

    double pi = 0.0;
    double sum [NUM_THREADS];
    double step = 1.0/(double) num_steps;
    int chunks = num_steps / NUM_THREADS;

    // Set up the parallel loop
    omp_set_num_threads(NUM_THREADS);
    #pragma omp parallel
    {
        // get the thread id
        int i, id;
        double x;
        id = omp_get_thread_num();
        // Each thread sums over its own chunk
        for ( i=id*chunks, sum[id]=0; i < (id+1)*chunks; i++){
            x = (i+0.5)*step;
            // Sum over each's own sum counter
            sum[id] += 4.0/(1.0+x*x);
        }
    }

    // Combine in serial
    for (int i = 0; i < NUM_THREADS; i++) pi += step * sum[i];
    return pi;

}    

int main() {
    int num_steps = 1000000;
    int n_repeat = 500;

    // Calculate and display the value of pi
    double parallel_pi = 0;
    
    // Run timer
    auto start_time = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n_repeat ; i ++) parallel_pi += calculate_parallel_pi(num_steps);
    auto end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> parallel_duration = end_time - start_time;

    // Print average results
    std::cout << "Parallel Calculation of Pi: " << parallel_pi / n_repeat 
              << std::endl << "Duration: " << parallel_duration.count() / n_repeat << " seconds" << std::endl;
    
    return 0;
}
