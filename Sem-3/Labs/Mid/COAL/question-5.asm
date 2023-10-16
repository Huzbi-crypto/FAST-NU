; Question-4 (a)
INCLUDE Irvine32.inc
.data
mode1 byte 9h,5h,3h,2h
.code
main Proc
mov al,[mode1+3]
xchg al,[mode1]
xchg al,[mode1+3]

mov al,[mode1+3]
xchg al,[mode1+2]
xchg al,[mode1+3]

mov al,[mode1+2]
xchg al,[mode1+1]
xchg al,[mode1+2]

call DumpRegs
exit
main ENDP
END main