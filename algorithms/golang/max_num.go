package main

import (
    "fmt"
)

func main() {
    var a, b, c int
    fmt.Printf( "a= " )
    fmt.Scanf( "%d", &a );

    fmt.Printf( "b= " )
    fmt.Scanf( "%d", &b )

    fmt.Printf( "c= " )
    fmt.Scanf( "%d", &c )

    fmt.Printf( "Max number is: %d\n", GetMaxNumber( a, b, c ) )
}

func GetMaxNumber( a int, b int, c int ) int {
    var max int

    if ( a > b ) {
        max = a
    } else {
        max = b
    }

    if ( c > max ) {
        max = c
    }

    return max
}
