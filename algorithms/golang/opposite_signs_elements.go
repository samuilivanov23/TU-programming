package main

import (
    "fmt"
)

func main() {
    numbers := []int {1, -2, 3, 4, 5, -6}
    length := 6
    countOppositeSignElements := 0

    j := 1
    for i := 0; i < length - 1; i++ {
        if ( ( numbers[i] > 0 && numbers[j] < 0 ) || ( numbers[i] < 0 && numbers[j] > 0 ) ) {
            countOppositeSignElements++
        }

        j++
    }

    fmt.Printf( "Count of opposite sign elements: %d\n", countOppositeSignElements )
}
