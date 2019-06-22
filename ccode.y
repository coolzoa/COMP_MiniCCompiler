%{
#include <stdio.h>
#include <stdlib.h>
#define red "\033[0;31m"
#define cyan "\033[1;36m"
#define green "\033[4;32m"
#define blue "\0\33[9;34m"
#define none "\033[0m"

extern FILE *fp;
FILE * f1 /*archivo para codigo intermedio*/;
FILE * f2 /*archivo para codigo asm*/;
void validar_entrada(int argc, char *argv[]);
void yyerror(const char *s);
void push();
void codegen_logical();
void codegen_algebric();
void codegen_assign();
void if_label1();
void if_label2();
void if_label3();
void while_start();
void while_rep();
void while_end();
void switch_start();
void switch_case();
void switch_default();
void switch_break();
void switch_nobreak();
void switch_end();
void check();
void setType();
void STMT_DECLARE();
void intermediateCode();
void inicio_codigo();
void final_codigo();
int string_to_num(char* op1);
void generarVariables();


%}

%define parse.error verbose
%token INT VOID UINT
%token WHILE 
%token IF ELSE SWITCH CASE BREAK DEFAULT
%token NUM ID
%token INCLUDE
%right ASGN 
%left LOR
%left LAND
%left BOR
%left BXOR
%left BAND
%left EQ NE 
%left LE GE LT GT
%left '+' '-' 
%left '*' '/' '@'
%left '~'

%nonassoc IFX IFX1
%nonassoc ELSE
  
%%

/*regla para type funcion main seguido de statements*/
pgmstart 
	: TYPE ID '(' ')' STMTS { printf("Analizando programa...\n");}
	| error ID '(' ')' STMTS { yyerror("ID inesperado, se esperaba void o  int"); }
	| TYPE error '(' ')' STMTS { yyerror("Se esperaba ID"); }
	| TYPE ID error ')' STMTS { yyerror("Falta ("); }
	| TYPE ID '(' error STMTS { yyerror("Falta )"); }
	;

STMTS 	: '{' STMT1 '}'
	| error STMT1 '}' { yyerror("Falta {"); }
	| '{' STMT1 error { yyerror("Falta }"); }
	;



STMT1
	: STMT  STMT1
	|
	;

STMT 
	: STMT_DECLARE
	| STMT_ASSGN
	| STMT_IF
	| STMT_WHILE
	| STMT_SWITCH
	| ';'
	;

				

EXP
	: EXP LT{push();} EXP {codegen_logical();}
	| EXP LE{push();} EXP {codegen_logical();}
	| EXP GT{push();} EXP {codegen_logical();}
	| EXP GE{push();} EXP {codegen_logical();}
	| EXP NE{push();} EXP {codegen_logical();}
	| EXP EQ{push();} EXP {codegen_logical();}
	| EXP '+'{push();} EXP {codegen_algebric();}
	| EXP '-'{push();} EXP {codegen_algebric();}
	| EXP '*'{push();} EXP {codegen_algebric();}
	| EXP '/'{push();} EXP {codegen_algebric();}
        | EXP {push();} LOR EXP {codegen_logical();}
	| EXP {push();} LAND EXP {codegen_logical();}
	| EXP {push();} BOR EXP {codegen_logical();}
	| EXP {push();} BXOR EXP {codegen_logical();}
	| EXP {push();} BAND EXP {codegen_logical();}

	| EXP error EXP { yyerror("Esperaba operador"); }
	| '(' EXP ')'
	| error EXP ')' { yyerror("Falta ("); }
	| '(' EXP error { yyerror("Falta )"); }

	| ID {check();push();}
	| NUM {push();}
	| error { yyerror("Esperaba numero o ID"); }
	;


STMT_IF
	: IF '(' EXP ')'  {if_label1();} STMTS ELSESTMT 
	;

ELSESTMT
	: ELSE {if_label2();} STMTS {if_label3();}
	| {if_label3();}
	;

STMT_SWITCH
	: SWITCH '(' EXP ')' {switch_start();} '{' SWITCHBODY '}'

	| SWITCH '(' EXP error '{' SWITCHBODY '}' { yyerror("Se esperaba )"); }
	| SWITCH '(' error ')' '{' SWITCHBODY '}' { yyerror("Se esperaba exp"); }
				;
SWITCHBODY
	: CASES {switch_end();}    
	| CASES DEFAULTSTMT {switch_end();}
	;

CASES 
	: CASE NUM {switch_case();} ':' SWITCHEXP BREAKSTMT
	| 
	;

BREAKSTMT
	: BREAK {switch_break();} ';' CASES
	|{switch_nobreak();} CASES 
	;

DEFAULTSTMT
	: DEFAULT {switch_default();} ':' SWITCHEXP DE  
	;

DE 
	: BREAK {switch_break();}';'
	|
	;


SWITCHEXP 		
	: STMTS
	| STMT
	;


STMT_WHILE
	:{while_start();} WHILE '(' EXP ')' {while_rep();} WHILEBODY  
	;

WHILEBODY
	: STMTS {while_end();}
	| STMT {while_end();}
	;

STMT_DECLARE 
	: TYPE {setType();}  ID {STMT_DECLARE();} IDS   //vamos a definir tipo para todas las vars de la linea
	;


IDS
	: ';'
	| ','  ID {STMT_DECLARE();} IDS 
	;


STMT_ASSGN
	: ID {check(); push();} ASGN {push();} EXP {codegen_assign();} ';'
	;


TYPE
	: INT
	| VOID
	| UINT
	;

%%

#include <ctype.h>
#include"lex.yy.c"
int count=0;

char st[1000][10]; //stack para guardar nodos
int top=0;
int i=0;
char temp[2]="t";

int label[200]; //para guardar etiquetas
int lnum=0;
int ltop=0;
int switch_stack[1000];
int stop=0;
char type[10];
int numtemps = 0;

struct Table
{
	char id[20];
	char type[10];
}table[10000]; //tabla de simbolos

int tableCount=0;

int huboError = 0; //0 falso, 1 true

void validar_entrada(int argc, char *argv[])
{
	if (argc != 2){
		printf("------Mini compilador de lenguaje C------\n");
		printf("Error en cantidad de argumentos al usar el comando\n");
		printf("Para correr este programa debe primero usar el comando ./programa3 ");
		printf("y luego pasar el nombre del archivo con la extension .c\n");
		exit(0);
	}else{

		yyin = fopen(argv[1], "r");
		if (yyin)
		{
			f1 = fopen("output","w");
			f2 = fopen("salida.asm","w");
			inicio_codigo();
			if (!yyparse())
			{
				printf("Parsing completado\n");
			}else
			{
				printf("Parsing fallado\n");
				exit(0);
			}
			generarVariables();
			final_codigo();			
			fclose(yyin);
			fclose(f1);
			//intermediateCode(); //esto hace print del archivo output
			fclose(f2);
		}else
		{
			printf("Error al abrir el archivo\n");
			huboError = 1;
		}	
	}


}

int main(int argc, char *argv[])
{
	validar_entrada(argc, argv);
	
    	return 0;
}
         
void yyerror(const char *s) {
	printf("%s Error en linea: %s%d%s : %s culpable: %s%s%s\n",red,cyan,yylineno,none,s,cyan,yytext,none);
	huboError = 1;
}

//funcion que hace push en el stack
void push()
{
  	strcpy(st[++top],yytext);
}

void codegen_logical()
{
 	sprintf(temp,"$t%d",i);
  	fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
	//ensamblador
	char* operador = st[top-1];
        char* op1= st[top-2]; char* op2= st[top];
	int num1 = string_to_num(op1); int num2 = string_to_num(op2);
	if(strcmp(operador,"<") == 0){  
		// op1 - op2 		si da positivo = 0      si da negativo = 1 
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 < op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rcx \n \tcmovb rax,rdx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rcx \n \tcmovb rax,rdx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio <\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rcx \n \tcmovb rax,rdx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,"<=") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 <= op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovbe rax,rdx \n \tcmova rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio <=\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovbe rax,rdx \n \tcmova rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio <=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovbe rax,rdx \n \tcmova rax,rcx \n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,">") == 0){
		// op1 - op2 		si da negativo = 0      si da positivo = 1 
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 > op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmova rax,rdx \n \t cmovbe rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmova rax,rdx \n \t cmovbe rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio >\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmova rax,rdx \n \t cmovbe rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax\n\n ",temp);
			}
		}
	}
	if(strcmp(operador,">=") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 <= op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rdx \n \t cmovb rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax\n\n ",temp);
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]   ;Inicio >=\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rdx \n \t cmovb rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s   ;Inicio >=\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tsub rax,rbx\n");
				fprintf(f2,"\tmov rcx,0\n");
				fprintf(f2,"\tmov rdx,1\n");
				fprintf(f2,"\tcmovae rax,rdx \n \t cmovb rax,rcx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,"&&") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 && op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio &&\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tAND rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);	
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio &&\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tAND rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s  ;  Inicio &&\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tAND rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax \n\n",temp);
			}
		}
	}
	if(strcmp(operador,"||") == 0){
		if(num1 == 1 && num2 ==1){  
			int resultado = op1 || op2;
			fprintf(f2,"\tmov [%s],%d ",temp,resultado);
		}else{
			if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio ||\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tOR rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax\n\n",temp);	
			}
			else if(!isdigit(num1)){ //op1 es var	
				fprintf(f2,"\tmov rax,[%s]  ;  Inicio ||\n",op1);
				fprintf(f2,"\tmov rbx,%s\n",op2);
				fprintf(f2,"\tOR rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax\n\n",temp);		
			}
			else if(isdigit(num1)){ //op2 es var
				fprintf(f2,"\tmov rax,%s  ;  Inicio ||\n",op1);
				fprintf(f2,"\tmov rbx,[%s]\n",op2);
				fprintf(f2,"\tOR rax,rbx\n");
				fprintf(f2,"\tmov [%s],rax\n \n",temp);
			}
		}
	}
	if(numtemps < temp[2]-48){ numtemps = temp[2]-48;} //contador temps
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}

void codegen_algebric()
{
 	sprintf(temp,"$t%d",i); // converts temp to reqd format
	char* operador = st[top-1];
        char* op1= st[top-2]; char* op2= st[top];
	int num1 = string_to_num(op1); int num2 = string_to_num(op2);
        //ensamblador
	if(strcmp(operador,"+") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) + atoi(op2);
           	//printf("Resultado de suma: %d \n",resultado);
  	        fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
		
	   }else{  	
		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		//hacer suma
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio suma");
			fprintf(f2,"\tmov rbx, [%s]\n",op2);
			fprintf(f2,"%s \n\n","\tadd rax,rbx");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio suma");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op2);
			fprintf(f2,"%s \n\n","\tadd rax,rbx");		
		} 
		else if(isdigit(num1)){ //op2 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op2,"]","; Inicio suma");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op1);
			fprintf(f2,"%s \n\n","\tadd rax,rbx");		
 		}
		// hacer asignacion
		fprintf(f2,"%s%s%s   %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion");
		}
		
	}
	if(strcmp(operador,"*") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) * atoi(op2);
           	//printf("Resultado de mult: %d \n",resultado);
		fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
	   }else{  	
		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		//hacer mul
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio mul");
			fprintf(f2,"%s%s%s \n","\tmov rbx, [",op2,"]");
			fprintf(f2,"%s \n\n","\tmul rax,rbx");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio mul");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op2);
			fprintf(f2,"%s \n\n","\tmul rax,rbx");		
		} 
		else if(isdigit(num1)){ //op2 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op2,"]","; Inicio mul");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op1);
			fprintf(f2,"%s \n\n","\tmul rax,rbx");		
 		}

		// hacer asignacion
		fprintf(f2,"%s%s%s %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion ");
		}
	}

	if(strcmp(operador,"-") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) - atoi(op2);
           	//printf("Resultado de resta: %d \n",resultado);
		fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion ");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
	   }else{ 
 		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		//hacer resta
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio resta");
			fprintf(f2,"%s %s %s \n","\tmov rbx, [",op2,"]");
			fprintf(f2,"%s \n\n","\tsub rax,rbx");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op1,"]","; Inicio resta");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op2);
			fprintf(f2,"%s \n\n","\tsub rax,rbx");		
		} 
		else if(isdigit(num1)){ //op2 es var
			fprintf(f2,"%s%s%s  %s \n","\tmov rax, [",op2,"]","; Inicio resta");
			fprintf(f2,"%s %s  \n","\tmov rbx, ",op1);
			fprintf(f2,"%s \n\n","\tsub rax,rbx");		
 		}

		// hacer asignacion
		fprintf(f2,"%s%s%s   %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion ");
		}
	
	}

	if(strcmp(operador,"/") == 0){
	   if(num1 == 1 && num2 ==1){
		int resultado = atoi(op1) / atoi(op2);
           	//printf("Resultado de division: %d \n",resultado);
		fprintf(f1,"%s\t=\t%d\n",temp,resultado);
		//hacer asignacion
		fprintf(f2,"%s %d %s \n","\tmov rax, ", resultado , "; Inicio asignacion ");
		fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"], rax");
	   }else{  	
		fprintf(f1,"%s\t=\t%s\t%s\t%s\n",temp,st[top-2],st[top-1],st[top]);
		if(!isdigit(num1) && !isdigit(num2)){ //op1 y op2 son variables
			fprintf(f2,"%s %s \n","\txor rdx,rdx","; Inicio div");
			fprintf(f2,"%s %s  \n","\tmov rax,",op1);
			fprintf(f2,"%s %s \n","\tmov rcx,",op2);
			fprintf(f2,"%s\n","\tidiv rcx");
			fprintf(f2,"%s%s%s\n\n","\tmov [",temp,"],rax");
		}
		else if(!isdigit(num1)){ //op1 es var
			fprintf(f2,"%s %s \n","\txor rdx,rdx","; Inicio div");
			fprintf(f2,"%s%s%s \n","\tmov rax, [",op1,"]");
			fprintf(f2,"%s %s\n","\tmov rcx,",op2);
			fprintf(f2,"%s\n","\tidiv rcx");
			fprintf(f2,"%s%s%s \n\n","\tmov [",temp,"],rax");			
		} 
		else if(isdigit(num1)){ //op2 es var	
			fprintf(f2,"%s %s \n","\txor rdx,rdx","; Inicio div");
			fprintf(f2,"%s %s  \n","\tmov rax,",op1);
			fprintf(f2,"%s%s%s\n","\tmov rcx, [",op2,"]");
			fprintf(f2,"%s\n","\tidiv rcx");
			fprintf(f2,"%s%s%s\n\n","\tmov [",temp,"],rax");		
 		}

		// hacer asignacion
		fprintf(f2,"%s%s%s   %s\n\n","\tmov [",temp,"], rax","; Inicio asignacion ");
		}
	}
	if(numtemps < temp[2]-48){ numtemps = temp[2]-48;}	//contador temps
  	top-=2;
 	strcpy(st[top],temp);
 	i++;
}


int string_to_num(char* op1){
	int length = strlen(op1);
	for(int y=0;y<length;y++){
		if(!isdigit(op1[y])){
			//es una var
			return 0;
		   }
	}
	return 1; //es un num
}

void codegen_assign()
{
 	fprintf(f1,"%s\t=\t%s\n",st[top-2],st[top]);
	//ensamblador
	char* op = st[top];
	int num1 = string_to_num(op); 
	if(num1 == 1){ //es un num
		fprintf(f2,"\tmov rax, %s ;\n",op);
		fprintf(f2,"\tmov [%s],rax ; Inicio asignacion\n\n",st[top-2]);
	}
	else{
		fprintf(f2,"\tmov rax, [%s] ;\n",op);
		fprintf(f2,"\tmov [%s],rax ; Inicio asignacion\n\n",st[top-2]);
	}
 	top-=3;
}
 
void if_label1()
{
 	lnum++;
 	fprintf(f1,"\tif( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
	//ensamblador
	fprintf(f2,"\tmov rax,[%s]    ;Inicio if \n",st[top]);
	fprintf(f2,"\tmov rbx, 1 \n");
	fprintf(f2,"\tcmp rax,rbx \n");
	fprintf(f2,"\tjne $L%d \n",lnum);

 	label[++ltop]=lnum;
}

void if_label2()
{
	int x;
	lnum++;
	x=label[ltop--]; 
	fprintf(f1,"\t\tgoto $L%d\n",lnum);
	fprintf(f1,"$L%d: \n",x); 
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",lnum);
	fprintf(f2,"$L%d: \n",x); 

	label[++ltop]=lnum;
}

void if_label3()
{
	int y;
	y=label[ltop--];
	fprintf(f1,"$L%d: \n",y);
	//ensamblador
	fprintf(f2,"$L%d: \n",y);

	top--;
}
void while_start()
{
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"$L%d:\n",lnum);
	//ensamblador
	fprintf(f2,"$L%d:    %s\n",lnum,"; Ciclo while");
}
void while_rep()
{
	lnum++;
 	fprintf(f1,"if( not %s)",st[top]);
 	fprintf(f1,"\tgoto $L%d\n",lnum);
	//ensamblador
	fprintf(f2,"\tmov rax,[%s]     ;Ver si cumple condicion \n",st[top]);
	fprintf(f2,"\tcmp rax,0\n");
	fprintf(f2,"\tjne $L%d\n\n",lnum);
 	label[++ltop]=lnum;
}
void while_end()
{
	int x,y;
	y=label[ltop--];
	x=label[ltop--];
	fprintf(f1,"\t\tgoto $L%d\n",x);
	fprintf(f1,"$L%d: \n",y);
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",x);
	fprintf(f2,"$L%d: \n",y);
	top--;
}
void switch_start()
{
	lnum++;
	label[++ltop]=lnum;
	lnum++;
	label[++ltop]=lnum;
	switch_stack[++stop]=1;
	fprintf(f2,"; 	Inicio de switch\n");
}
void switch_case()
{
	int x,y,z;
	z=switch_stack[stop--];
	if(z==1)
	{
		x=label[ltop--];
	}
	else if(z==2)
	{
		y=label[ltop--];
		x=label[ltop--];
	}
	fprintf(f1,"$L%d:\n",x);
	//ensamblador
	fprintf(f2,"$L%d:\n",x);

	lnum++;
	label[++ltop]=lnum;
 	fprintf(f1,"if(%s != %s)",st[top],yytext);
 	fprintf(f1,"\tgoto $L%d\n",label[ltop]);
	//ensamblador
	fprintf(f2,"\tmov rax,[%s]\n",st[top]);
	fprintf(f2,"\tmov rbx,%s\n",yytext);
	fprintf(f2,"\tcmp rax,rbx\n");
	fprintf(f2,"\tjne $L%d\n",label[ltop]);
	
 	if(z==2)
 	{
 		fprintf(f1,"$L%d:\n",y);
		//ensamblador
		fprintf(f2,"$L%d:\n",y);
 	}
}
void switch_default()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	lnum++;
	label[++ltop]=lnum;
}
void switch_break()
{
	switch_stack[++stop]=1;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop-1]);
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",label[ltop-1]);	
}
void switch_nobreak()
{
	switch_stack[++stop]=2;
	lnum++;
	label[++ltop]=lnum;
	fprintf(f1,"\t\tgoto $L%d\n",label[ltop]);
	//ensamblador
	fprintf(f2,"\tjmp $L%d\n",label[ltop]);
}
void switch_end()
{
	int x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	//ensamblador
	fprintf(f2,"$L%d:\n",x);

	x=label[ltop--];
	fprintf(f1,"$L%d:\n",x);
	//ensamblador
	fprintf(f2,"$L%d:\n",x);
	fprintf(f2,";    Termino switch \n");
	top--;
	stop--;
}


/* verificar si una variable ya esta definida*/

void check()
{
	char temp[20];
	strcpy(temp,yytext);
	int flag=0;
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,temp))
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		yyerror("Variable no declarada");
		STMT_DECLARE();
		
	}
}

void setType()
{
	strcpy(type,yytext);
}


/*verifica si variable declarada ya ha sido dclarada previamente*/
void STMT_DECLARE()
{
	char temp[20];
	int i,flag;
	flag=0;
	strcpy(temp,yytext);
	for(i=0;i<tableCount;i++)
	{
		if(!strcmp(table[i].id,temp))
			{
			flag=1;
			break;
				}
	}
	if(flag)
	{
		yyerror("Redeclaracion, ");
	}
	else
	{
		strcpy(table[tableCount].id,temp);
		strcpy(table[tableCount].type,type);
		tableCount++;
	}
}

void intermediateCode()
{
	int Labels[100000];
	char buf[100];
	f1=fopen("output","r");
	int flag=0,lineno=1;
	memset(Labels,0,sizeof(Labels));
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		//printf("%s",buf);
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			int k=atoi(&buf[3]);
			//printf("hi %d\n",k);
			Labels[k]=lineno;
		}
		else
		{
			lineno++;
		}
	}
	fclose(f1);
	f1=fopen("output","r");
	lineno=0;

	//printf("\n\n\n*********************InterMediate Code***************************\n\n");
	while(fgets(buf,sizeof(buf),f1)!=NULL)
	{
		//printf("%s",buf);
		if(buf[0]=='$'&&buf[1]=='$'&&buf[2]=='L')
		{
			;
		}
		else
		{
			flag=0;
			lineno++;
			printf("%3d:\t",lineno);
			int len=strlen(buf),i,flag1=0;
			for(i=len-3;i>=0;i--)
			{
				if(buf[i]=='$'&&buf[i+1]=='$'&&buf[i+2]=='L')
				{
					flag1=1;
					break;
				}
			}
			if(flag1)
			{
				buf[i]=='\0';
				int k=atoi(&buf[i+3]),j;
				//printf("%s",buf);
				for(j=0;j<i;j++)
					printf("%c",buf[j]);
				printf(" %d\n",Labels[k]);
			}
			else printf("%s",buf);
		}
	}
	printf("%3d:\tend\n",++lineno);
	fclose(f1);
}

void inicio_codigo()
{
	fprintf(f2,";=====Inicio de codigo=====\n");
	fprintf(f2,"section .text\n");
	fprintf(f2,"\tglobal _start\n\n");
	fprintf(f2,"_start:\n");
}

void final_codigo(){

	fprintf(f2,"\t;   cmovb =  mueve si a es menor que b \n");
	fprintf(f2,"\t;   cmovbe =  mueve si a es menor o igual que b \n");
	fprintf(f2,"\t;   cmovae =  mueve si a es mayor o igual que b \n");
	fprintf(f2,"\t;   cmova =  mueve si a es mayor que b \n");
}

void generarVariables()
{
	fprintf(f2,"section .data\n");
	int cant = 0;
	for (cant = 0; cant < tableCount; cant++){
		//printf("Variable: %s\n",table[cant].id);
		fprintf(f2,"\t%s dq 0\n", table[cant].id);	
	}
	fprintf(f2,"\n");

	for (cant = 0; cant <= numtemps; cant++)
	{
		fprintf(f2,"\t$t%d dq 0\n",cant);
	}
	fprintf(f2,"\n");
}


