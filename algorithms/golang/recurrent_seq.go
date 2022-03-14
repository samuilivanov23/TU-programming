package main

import (
    "fmt"
)

func main() {
    xn := 2
    result := 2*xn + 10
    for result < 100 {
        xn = result
        result = 2*xn + 10
    }

    fmt.Printf( "Result: %d\n", result )
}
