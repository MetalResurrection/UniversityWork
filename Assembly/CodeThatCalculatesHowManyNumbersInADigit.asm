.model small
.stack 100h

.data
   msg db 'Enter line: $'
   result db 13, 10, 'Amount of numbers: $'  
   
   count db 0
   
   .code 
   
   main proc
    
    mov ax, @data
    mov ds, ax
    
    mov ah, 09h
    mov dx, offset msg
    
    int 21h
    
    read_char:
    
    mov ah, 01h
    int 21h
    
    cmp al, 13
    je print_result
    
    cmp al, '0'      
    jb read_char
    
    cmp al, '9'    
    ja read_char
    
    inc count    
    jmp read_char     
    
    
    
    
    print_result:
    
    mov ah, 09h    
    mov dx, offset result   
    int 21h
    
    mov al, count
    cmp al, 10
    jb one_digit
    
    mov ah, 0
    mov bl, 10
    div bl    
    
    mov cl, ah
    mov dl, al  
    
    add dl, '0'    
    mov ah, 02h
    int 21h
    
    mov dl, cl
    add dl, '0'
    mov ah, 02h
    int 21h
    
    jmp exit_program
    
    
    one_digit:
    
    mov dl, al    
    add dl, '0'
    mov ah, 02h
    int 21h      
    
    exit_program:
    
    mov ax, 4C00h
    int 21h
    
    
    main endp   
   end main
   