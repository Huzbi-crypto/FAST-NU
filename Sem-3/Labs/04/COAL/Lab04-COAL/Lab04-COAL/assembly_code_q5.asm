;Author: Huzefa Saifuddin (Huzbi) - 22K-5125
;TITLE: COAL Lab04

;----------------------------------- QUESTION 5 -----------------------------------
include Irvine32.inc

.code

main PROC

    mov ax,7FF0h          ;CF=?, SF=?, ZF=?, OF=?
    call DumpRegs

    add al,10h            ;CF=?, SF=?, ZF=?, OF=?
    call DumpRegs

    add ah,1              ;CF=?, SF=?, ZF=?, OF=?
    call DumpRegs

    add ax,2
    call DumpRegs

main endp
end main