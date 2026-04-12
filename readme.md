## this is an ARM32 simulator

DO NOT expect an ARM32 interpretor, this simulates the execution of an ARM32 program using high level data structures

hence, the time complexity of said script is very likely to be altered (most probably for the worst)

___

### recognized instructions/syntax and file entry specification: 

- end of instructions are specified by an end of line

- the file must end with an empty line

- empty lines are ignored

- only one instruction per line 

- instructions must be on one line only unless specified below 
---

    register :
        - r0 to r15

___

    MOV dest, val 
        with 
            dest : register 
            val : 
                - register
                - direct value (specified with #value)


___

TODO : 

- add ldr and str support