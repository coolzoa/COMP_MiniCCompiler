;=====Inicio de codigo=====
section .text
	global _start

_start:
	mov rax, 2 ;
	mov [b],rax ; Inicio asignacion

	mov rax, 1 ;
	mov [c],rax ; Inicio asignacion

	mov rax, [b]  ; Inicio suma 
	mov rbx, [c]
	add rax,rbx 

	mov [$t2], rax   ; Inicio asignacion

	mov rax, [$t2] ;
	mov [a],rax ; Inicio asignacion

	mov rax,[a]   ;Inicio <=
	mov rbx,[b]
	sub rax,rbx
	mov rcx,0
	mov rdx,1
	cmovbe rax,rdx 
 	cmova rax,rcx
	mov [$t1],rax 

	mov rax,[b]   ;Inicio <=
	mov rbx,[c]
	sub rax,rbx
	mov rcx,0
	mov rdx,1
	cmovbe rax,rdx 
 	cmova rax,rcx
	mov [$t2],rax 

	mov rax,[$t2]  ;  Inicio ||
	mov rbx,[$t1]
	OR rax,rbx
	mov [$t2],rax

	mov rax,[$t1]  ;  Inicio &&
	mov rbx,[$t2]
	AND rax,rbx
	mov [$t3],rax 

	mov rax,[$t3]    ;Inicio if 
	mov rbx, 1 
	cmp rax,rbx 
	jne $L1 
	mov rax,[a]   ;Inicio <=
	mov rbx,[c]
	sub rax,rbx
	mov rcx,0
	mov rdx,1
	cmovbe rax,rdx 
 	cmova rax,rcx
	mov [$t2],rax 

	mov rax,[$t2]    ;Inicio if 
	mov rbx, 1 
	cmp rax,rbx 
	jne $L2 
	mov rax, [b] ;
	mov [a],rax ; Inicio asignacion

	jmp $L3
$L2: 
	mov rax, [b] ;
	mov [c],rax ; Inicio asignacion

$L3: 
$L1: 
; 	Inicio de switch
$L5:
	mov rax,[a]
	mov rbx,0
	cmp rax,rbx
	jne $L6
	mov rax,  5 ; Inicio asignacion 
	mov [$t4], rax 

	mov rax, [$t4] ;
	mov [s],rax ; Inicio asignacion

	jmp $L7
$L6:
	mov rax,[a]
	mov rbx,1
	cmp rax,rbx
	jne $L8
$L7:
	mov rax, [b] ;
	mov [a],rax ; Inicio asignacion

	mov rax, [b]  ; Inicio suma 
	mov rbx, [2]
	add rax,rbx 

	mov [$t1], rax   ; Inicio asignacion

; 	Inicio de switch
$L10:
	mov rax,[$t1]
	mov rbx,2
	cmp rax,rbx
	jne $L11
	mov rax, [b]  ; Inicio suma 
	mov rbx, [c]
	add rax,rbx 

	mov [$t2], rax   ; Inicio asignacion

	mov rax, [$t2] ;
	mov [d],rax ; Inicio asignacion

	jmp $L9
$L11:
	mov rax,[$t1]
	mov rbx,3
	cmp rax,rbx
	jne $L12
	jmp $L13
$L12:
	mov rax,[$t1]
	mov rbx,4
	cmp rax,rbx
	jne $L14
$L13:
	mov rax, [r] ;
	mov [c],rax ; Inicio asignacion

	jmp $L9
$L14:
$L9:
;    Termino switch 
	jmp $L15
$L8:
	mov rax,[a]
	mov rbx,2
	cmp rax,rbx
	jne $L16
$L15:
	mov rax, 2 ;
	mov [s],rax ; Inicio asignacion

	jmp $L4
$L16:
	mov rax,[a]
	mov rbx,3
	cmp rax,rbx
	jne $L17
	mov rax, 3 ;
	mov [s],rax ; Inicio asignacion

	jmp $L4
$L17:
	mov rax,[a]
	mov rbx,4
	cmp rax,rbx
	jne $L18
	mov rax, 7 ;
	mov [s],rax ; Inicio asignacion

	jmp $L19
$L18:
	mov rax,[a]
	mov rbx,5
	cmp rax,rbx
	jne $L20
$L19:
	mov rax, 9 ;
	mov [s],rax ; Inicio asignacion

	jmp $L4
	mov rax, [q] ;
	mov [p],rax ; Inicio asignacion

	jmp $L4
$L21:
$L4:
;    Termino switch 
$L22:    ; Ciclo while
	mov rax, [b]  ; Inicio mul 
	mov rbx, [c] 
	mul rax,rbx 

	mov [$t2], rax ; Inicio asignacion 

	mov rax, [a]  ; Inicio suma 
	mov rbx, [$t2]
	add rax,rbx 

	mov [$t3], rax   ; Inicio asignacion

	mov rax,[$t3]     ;Ver si cumple condicion 
	cmp rax,0
	jne $L23

	mov rax,[a]   ;Inicio >
	mov rbx,[b]
	sub rax,rbx
	mov rcx,0
	mov rdx,1
	cmova rax,rdx 
 	 cmovbe rax,rcx
	mov [$t1],rax 

	mov rax,[$t1]    ;Inicio if 
	mov rbx, 1 
	cmp rax,rbx 
	jne $L24 
	mov rax, [b] ;
	mov [a],rax ; Inicio asignacion

	jmp $L25
$L24: 
	mov rax, [d] ;
	mov [c],rax ; Inicio asignacion

$L25: 
	mov rax, [p]  ; Inicio mul 
	mov rbx, [q] 
	mul rax,rbx 

	mov [$t7], rax ; Inicio asignacion 

	mov rax, [a]  ; Inicio suma 
	mov rbx, [b]
	add rax,rbx 

	mov [$t1], rax   ; Inicio asignacion

	mov rax, [c]  ; Inicio mul 
	mov rbx, [$t1] 
	mul rax,rbx 

	mov [$t2], rax ; Inicio asignacion 

	mov rax, [$t7]  ; Inicio suma 
	mov rbx, [$t2]
	add rax,rbx 

	mov [$t3], rax   ; Inicio asignacion

	mov rax, [$t3] ;
	mov [d],rax ; Inicio asignacion

	mov rax, [r] ;
	mov [q],rax ; Inicio asignacion

	jmp $L22
$L23: 
section .data
	a dq 0
	b dq 0
	c dq 0
	d dq 0
	s dq 0
	r dq 0
	p dq 0
	q dq 0

	$t0 dq 0
	$t1 dq 0
	$t2 dq 0
	$t3 dq 0
	$t4 dq 0
	$t5 dq 0
	$t6 dq 0
	$t7 dq 0

	;   cmovb =  mueve si a es menor que b 
	;   cmovbe =  mueve si a es menor o igual que b 
	;   cmovae =  mueve si a es mayor o igual que b 
	;   cmova =  mueve si a es mayor que b 
