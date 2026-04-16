## this is an ARM32 simulator

DO NOT expect an ARM32 interpretor, this simulates the execution of an ARM32 program using high level data structures

hence, the time complexity of said script is very likely to be altered (most probably for the worst)

___

### recognized instructions/syntax and file entry specification: 

- the file must end with an empty line

- empty lines are ignored

- instructions tokens (mov, add) can be writen in both capital letters and undercase letters
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

set dest value as either : 
- the value stored in val (if it's a register)
- the specified direct value

___

    ADD dest, rt, rn
        with
            dest : register
            rt   : register
            rn   : 
                - register
                - direct value (specified with #value)

store in dest the value of rt + rn

___

TODO :

- change the ADD syntax to include ADD rt, rn with rt as dest

- add ldr and str support