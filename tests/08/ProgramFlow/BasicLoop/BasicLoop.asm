// push constant 0
@0
D=A
@SP
A=M
M=D
@SP
M=M+1
// pop local 0
@LCL
D=M
@R15
M=D
@SP
AM=M-1
D=M
@R15
A=M
M=D
// label LOOP_START
(BasicLoop.LOOP_START)
// push argument 0
@ARG
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push local 0
@LCL
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1
// add
@SP
AM=M-1
D=M
A=A-1
M=M+D
// pop local 0
@LCL
D=M
@R15
M=D
@SP
AM=M-1
D=M
@R15
A=M
M=D
// push argument 0
@ARG
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 1
@1
D=A
@SP
A=M
M=D
@SP
M=M+1
// sub
@SP
AM=M-1
D=M
A=A-1
M=M-D
// pop argument 0
@ARG
D=M
@R15
M=D
@SP
AM=M-1
D=M
@R15
A=M
M=D
// push argument 0
@ARG
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1
// if-goto LOOP_START
AM=M-1
D=M
@BasicLoop.LOOP_START
D;JGT
// push local 0
@LCL
A=M
D=M
@SP
A=M
M=D
@SP
M=M+1
