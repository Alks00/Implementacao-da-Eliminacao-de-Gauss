package main

import (
	"fmt"
	"math/rand"
	"time"
)

const MAXN = 2000

func main() {
	// Parâmetros fixos para compiladores online
	n := 1000             // Tamanho da matriz para exibição dos resultados
	seed := int64(1234) // Semente fixa para aleatoriedade
	fmt.Printf("Matrix dimension N = %d.\n", n)
	fmt.Printf("Random seed = %d.\n", seed)

	rand.Seed(seed)

	// Aloca as matrizes e vetores
	A := make([][]float32, n)
	for i := range A {
		A[i] = make([]float32, n)
	}
	B := make([]float32, n)
	X := make([]float32, n)

	// Inicializa A e B
	for row := 0; row < n; row++ {
		for col := 0; col < n; col++ {
			A[row][col] = rand.Float32() // Gera número aleatório entre 0.0 e 1.0
		}
		B[row] = rand.Float32()
	}

	if n < 10 {
		fmt.Println("Matriz A:")
		for i := 0; i < n; i++ {
			fmt.Println(A[i])
		}
		fmt.Println("Vetor B:", B)
	}

	start := time.Now()
	gauss(A, B, X, n)
	elapsed := time.Since(start)

	fmt.Println("Vetor Resultado X:")
	//if n < 100 {
	fmt.Println(X)
	//}
	fmt.Printf("Tempo decorrido = %d ms\n", elapsed.Milliseconds())
}

func gauss(A [][]float32, B, X []float32, n int) {
	// Eliminação Gaussiana
	for norm := 0; norm < n-1; norm++ {
		for row := norm + 1; row < n; row++ {
			multiplier := A[row][norm] / A[norm][norm]
			for col := norm; col < n; col++ {
				A[row][col] -= A[norm][col] * multiplier
			}
			B[row] -= B[norm] * multiplier
		}
	}
	// Substituição regressiva
	for row := n - 1; row >= 0; row-- {
		X[row] = B[row]
		for col := row + 1; col < n; col++ {
			X[row] -= A[row][col] * X[col]
		}
		X[row] /= A[row][row]
	}
}
