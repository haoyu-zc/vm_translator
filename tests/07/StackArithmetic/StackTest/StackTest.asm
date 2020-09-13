// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE0
D;JEQ
D=0;
@_FALSE0
0;JMP
(_TRUE0)
D=-1
(_FALSE0)
@SP
A=M-1
M=D
// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 16
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
// eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE1
D;JEQ
D=0;
@_FALSE1
0;JMP
(_TRUE1)
D=-1
(_FALSE1)
@SP
A=M-1
M=D
// push constant 16
@16
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 17
@17
D=A
@SP
A=M
M=D
@SP
M=M+1
// eq
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE2
D;JEQ
D=0;
@_FALSE2
0;JMP
(_TRUE2)
D=-1
(_FALSE2)
@SP
A=M-1
M=D
// push constant 892
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// lt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE3
D;JLT
D=0;
@_FALSE3
0;JMP
(_TRUE3)
D=-1
(_FALSE3)
@SP
A=M-1
M=D
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 892
@892
D=A
@SP
A=M
M=D
@SP
M=M+1
// lt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE4
D;JLT
D=0;
@_FALSE4
0;JMP
(_TRUE4)
D=-1
(_FALSE4)
@SP
A=M-1
M=D
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 891
@891
D=A
@SP
A=M
M=D
@SP
M=M+1
// lt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE5
D;JLT
D=0;
@_FALSE5
0;JMP
(_TRUE5)
D=-1
(_FALSE5)
@SP
A=M-1
M=D
// push constant 32767
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// gt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE6
D;JGT
D=0;
@_FALSE6
0;JMP
(_TRUE6)
D=-1
(_FALSE6)
@SP
A=M-1
M=D
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 32767
@32767
D=A
@SP
A=M
M=D
@SP
M=M+1
// gt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE7
D;JGT
D=0;
@_FALSE7
0;JMP
(_TRUE7)
D=-1
(_FALSE7)
@SP
A=M-1
M=D
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 32766
@32766
D=A
@SP
A=M
M=D
@SP
M=M+1
// gt
@SP
AM=M-1
D=M
A=A-1
D=M-D
@_TRUE8
D;JGT
D=0;
@_FALSE8
0;JMP
(_TRUE8)
D=-1
(_FALSE8)
@SP
A=M-1
M=D
// push constant 57
@57
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 31
@31
D=A
@SP
A=M
M=D
@SP
M=M+1
// push constant 53
@53
D=A
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
// push constant 112
@112
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
// neg
@SP
AM=M-1
M=-M
@SP
M=M+1
// and
@SP
AM=M-1
D=M
A=A-1
M=M&D
// push constant 82
@82
D=A
@SP
A=M
M=D
@SP
M=M+1
// or
@SP
AM=M-1
D=M
A=A-1
M=M|D
// not
@SP
AM=M-1
M=!M
@SP
M=M+1
