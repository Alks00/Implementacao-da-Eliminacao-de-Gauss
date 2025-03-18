use rand::prelude::*;
use std::time::Instant;

const N: usize = 1000; // Dimensão da matriz
static mut A: [[f32; N]; N] = [[0.0; N]; N]; // Matriz A
static mut B: [f32; N] = [0.0; N]; // Vetor B
static mut X: [f32; N] = [0.0; N]; // Vetor solução X

fn initialize(seed: u64) {
    let mut rng = StdRng::seed_from_u64(seed); // Gerador de números aleatórios
    unsafe {
        for i in 0..N {
            for j in 0..N {
                A[i][j] = rng.r#gen::<f32>(); // Gera número aleatório entre 0.0 e 1.0
            }
            B[i] = rng.r#gen::<f32>(); // Gera número aleatório para B[i]
        }
    }
}

fn gauss() {
    unsafe {
        for norm in 0..N - 1 {
            for row in norm + 1..N {
                let multiplier = A[row][norm] / A[norm][norm];
                for col in norm..N {
                    A[row][col] -= A[norm][col] * multiplier;
                }
                B[row] -= B[norm] * multiplier;
            }
        }

        // Substituição para trás
        for row in (0..N).rev() {
            X[row] = B[row];
            for col in row + 1..N {
                X[row] -= A[row][col] * X[col];
            }
            X[row] /= A[row][row];
        }
    }
}

fn main() {
    let start = Instant::now();

    let seed: u64 = 1234; // Semente aleatória
    initialize(seed);

    println!("Executando Gauss...");
    gauss();

    let duration = start.elapsed();
    println!("Tempo decorrido: {:?}", duration);

    
    println!("Finalizado para n = {}", N);
}
