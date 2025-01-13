%{
#include<stdio.h>
#include <math.h>
#include<stdlib.h>
#include<string.h>
extern FILE *yyin;
extern FILE *yyout;
int yylex();
int yyerror(char *s);

// Symbol Table Arrays
char var_name[1000][100];
int store_int[1000];
float store_float[1000];
char store_String[1000][100];
int type[1000];
int var_type_pointer = 0; // 0 = int, 1 = float, 2 = string, 3 = function, 4 = char
int store_char[1000];

// Conditional Statement Variables
int if_pointer = 0;
int store_if[1000];

// Switch Handling Variables
int switch_var = 0; 
int switch_case = 0;

// Variable Counter
int var_cnt = 0;

// Variable Declaration Check
int checkDeclared(char *s){
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0)
                return 1;
    }
    return 0;
}

// New Variable Declaration
int varAssign(char *s){
    if(checkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store_int[var_cnt] = 0;
    store_float[var_cnt] = 0.0;
    strcpy(store_String[var_cnt], "");
    store_char[var_cnt] = '\0';
    type[var_cnt] = var_type_pointer;
    char name[10];
    if(var_type_pointer == 0) {
        strcpy(name, "Int");
    }
    else if(var_type_pointer == 1) {
        strcpy(name, "Float");
    }
    else if(var_type_pointer == 2) {
        strcpy(name, "String");
    }
    else if(var_type_pointer == 4) {
        strcpy(name, "Char");
    }
    printf("\n>> DECLARATION: Variable '%s' of type '%s' has been declared\n", var_name[var_cnt], name);
    var_cnt++;
    return 1;
}

// New Function Declaration
int functionAssign(char *s){
    if(checkDeclared(s) == 1){
        return 0;
    }
    strcpy(var_name[var_cnt], s);
    store_int[var_cnt] = 0;
    store_float[var_cnt] = 0.0;
    strcpy(store_String[var_cnt], "");
    type[var_cnt] = 3;
    printf("\nNew Function Declared With Name: %s\n", var_name[var_cnt]);
    var_cnt++;
    return 1;
}

// Assigning Value to Variable
int setValue(char *s, char* val){
    if(checkDeclared(s) == 0){
        return 0;
    }
    int ok=0, i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            ok = i;
            break;
        }
    }
    if(type[ok] == 0){
        store_int[ok] = atoi(val);
        printf("\n>> ASSIGNMENT: Integer variable '%s' = %d\n", var_name[ok], store_int[ok]);
    }
    else if(type[ok] == 1){
        store_float[ok] = atof(val);
        printf("\n>> ASSIGNMENT: Float variable '%s' = %f\n", var_name[ok], store_float[ok]);
    }
    else if(type[ok] == 2){
        strcpy(store_String[ok], val);
        printf("\n>> ASSIGNMENT: String variable '%s' = %s\n", var_name[ok], store_String[ok]);
    }
    else if(type[ok] == 4){
        store_char[ok] = val[1];  // Skip the quotes and get the character
        printf("\n>> ASSIGNMENT: Character variable '%s' = %c\n", var_name[ok], store_char[ok]);
    }
    else{
        printf("\nCan't Assign Value as Variable is a Function!\n");
    }
    return 1;
}

// Get Variable Value
int getValue(char *s){
    int pos=-1;
    int i;
    for(i=0; i<var_cnt; i++){
        if(strcmp(var_name[i], s) == 0){
            pos=i;
            break;
        }
    }
    return pos;
}
%}

%union
{
    int num;
    float flt;
    char* string;
};

%token END INT FLOAT STRING MOD CHAR
%token LT GT GEQ LEQ EQ NEQ
%token <string> VARIABLE
%token <string> NUMBER
%token <string> CHAR_LIT
%type <string> expression
%token <string> STR 
%token IMPORT HEADER MAIN
%token INC DEC NOT
%token SIN COS LOG TAN LN
%token ODDEVEN FACTORIAL MAX MIN PRIME
%token DEF DISPLAY
%token IF ELSE_IF ELSE
%token FOR FLINC FLDEC WHILE
%token CASE SWITCH DEFAULT
%token STRCAT
%token STRJOIN

%left LT GT GEQ LEQ EQ NEQ
%left STRCAT
%left '+' '-'
%left '*' '/' MOD
%left '^'
%left STRJOIN

%%

program:
    import func main '(' ')' '{' statements '}' { printf("\nProgram Successfully executed!\n"); }
    | /* NULL */
    ;

main:
    MAIN { printf("\nMain Function Declared!\n"); }

import: /* NULL */
    | import IMPORT '<' HEADER '>' { printf("\nHeader File Found!\n"); }
    ;

func: 
    func_head '(' param ')' '{' statements '}' {
		printf("\nUser Defined Function Ended!\n");
	}
	| /* NULL */
	;

func_head: 
    DEF VARIABLE {
        if(checkDeclared($2)==1) {
            printf("\nDuplicate Function Name!\n");
        }
        else {
            functionAssign($2);
        }
    }

param:
	param ',' type pid	{ printf("\nValid Function Parameter Declaration!\n"); } 
	| type pid 	{ printf("\nValid Function Parameter Declaration!\n"); } 
	;

pid	:
	 VARIABLE {
		if(checkDeclared($1)==1) {
      		printf("\nDuplicate Declaration!\n");
        }
   		else {
      	    varAssign($1);
		}
    }
	;

statements:
    statements cstatement
	| /* NULL */
	;

cstatement:
    END
	| declare
	| expression END
    | VARIABLE '=' expression END {
		if(checkDeclared($1) == 0) {
			printf("\n%s Not Declared!\n", $1);
		}
		else {
			// Only set value if expression didn't result in error (value not "0")
			if(strcmp($3, "0") != 0) {
				setValue($1, $3);
			}
		}
	}
    | function_call END
    | DISPLAY '(' VARIABLE ')' END {
		if(checkDeclared($3)==0) {
			printf("\nCan't print, Variable is not declared\n");
        }
        else {
            int index = getValue($3);
            if(type[index] == 0){
                printf("\nPrinting Value of the variable %s: %d\n", $3, store_int[index]);
            }
            else if(type[index] == 1){
                printf("\nPrinting Value of the variable %s: %f\n", $3, store_float[index]);
            }
            else if(type[index] == 2){
                printf("\nPrinting Value of the variable %s: %s\n", $3, store_String[index]);
            }
            else if(type[index] == 4){
                printf("\nPrinting Value of the variable %s: '%c'\n", $3, store_char[index]);
            }
            else{
                printf("\nCan't Display Value as Variable is a Function!\n");
            }
        }
	}
    | if_condition '{' statements '}' {
		printf("\nIf Block is Successfully Handled!\n");
	}
	| else_if_condition '{' statements '}' {
		printf("\nElse If Block is Successfully Handled!\n");
	}
	| else_condition '{' statements '}' {
		printf("\nElse Block is Successfully Handled!\n");
	}
    | for_start '(' for_loop ')' '{' statements '}' {
        printf("\nFor Loop Execution Finshed!\n");
    }
    | while_start '(' while_loop ')' '{' statements '}' {
        printf("\nWhile Loop Execution Finshed!\n");
    }
    | switch_start '(' switch_exp ')' '{' switch_statement '}' {
        printf("\nSwitch Execution Finshed!\n");
    }
    ;

switch_start:
    SWITCH {
        printf("\nSwitch Case Started!\n");
    }
    ;

switch_exp :
	expression {
        switch_case = 0;
        switch_var = atoi($1);
    }
	;

switch_statement: /* NULL */
	| switch_statement CASE expression ':' '{' statements '}' {
        int x = atoi($3);
        if(x == switch_var && switch_case == 0 ) {
            printf("\nSwitch Case Executed is %d!\n", x);
            switch_case = 1;
        }
        else {
            printf("\nSwitch Case No: %d is Ignored!\n", x);
        }
    }
	| switch_statement DEFAULT ':' '{' statements '}' {
        if(switch_case == 0) {
            switch_case = 1;
            printf("\nSwitch Default Case is Executed!\n");
        }
    }
	;

while_loop:
    VARIABLE loop_exp loop_assign {
        if(checkDeclared($1) == 0) {
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            printf("\nWhile Loop Variable Declaration is Correct!\n");	
        } 
    }

while_start:
    WHILE {
        printf("\nWhile Loop Started!\n");
    }

for_start:
    FOR {
        printf("\nFor Loop Started!\n");
    }

for_loop:
    | VARIABLE '=' loop_assign ',' VARIABLE loop_exp loop_assign ',' VARIABLE f_state loop_assign {			
        if(checkDeclared($1) == 0) {
            printf("\n%s Not Declared!\n", $1);
        }
        if(strcmp($1, $5) == 0) {
            if(strcmp($1, $9) == 0) {
                printf("\nFor Loop Variable Declaration is Correct!\n");
            }
        }
        else {
            printf("\nDifferent Variables Used: %s %s %s\n", $1, $5, $9);	
        } 			    
    }

loop_assign:
    NUMBER
    | VARIABLE {
        if(checkDeclared($1) == 0) {
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            printf("\nVariable Correctly Assigned to Loop!\n");	
        }
    }
    ;

loop_exp:
    LT
    | GT
    | GEQ
    | LEQ
    | EQ
    | NEQ
    ;

f_state:
    FLINC {
        printf("\nLoop is of Increasing Manner!\n");
    }
    | FLDEC {
        printf("\nLoop is of Decreasing Manner!\n");
    }
    ;

if_condition:
    IF '(' expression ')' {
        int x = atoi($3);
        if( x >= 1 ) {
			store_if[if_pointer] = 1;
			printf("\nIf Block is Executed!\n");
		}
        else {
            printf("\nIf Block is Not Executed!\n");
        }
        if_pointer++;
    }

else_if_condition:
    ELSE_IF '(' expression ')' {
        int x = atoi($3);
        if( x >= 1 && store_if[if_pointer] == 0) {
			store_if[if_pointer] = 1;
			printf("\nElse If Block is Executed!\n");
		}
        else {
            printf("\nElse If Block is Not Executed!\n");
        }
    }

else_condition:
    ELSE {
        if( store_if[if_pointer] == 0) {
			store_if[if_pointer] = 1;
			printf("\nElse Block is Executed!\n");
		}
        else {
            printf("\nElse Block is Not Executed!\n");
        }
    }

function_call: 
    f_var '(' call_param ')' { 
        printf("\nValid Function Call!\n");
    }
    ;

f_var: 
    VARIABLE {
        if(checkDeclared($1) == 0) {
			printf("\n%s Function is Not Declared!\n", $1);
		}
        else {
            printf("\n%s Function is Called!\n", $1);
        }
    }

call_param:
    call_param ',' VARIABLE {
        if(checkDeclared($3) == 0) {
            printf("\n%s Variable is Not Declared\n", $3);
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", $3); 
                
        }
    }
    | VARIABLE {
        if(checkDeclared($1) == 0) {
            printf("\n%s Variable is Not Declared\n", $1);
        }
        else {
            printf("\n%s Passed as Parameter For Function!\n", $1); 
                
        }
    }
	| /* NULL */
    ;

declare:
    type id END { printf("\nValid Syntax For Variable Declaration!\n"); } 
    ;

type:
    INT { var_type_pointer = 0; }
    | FLOAT  { var_type_pointer = 1; }
    | STRING  { var_type_pointer = 2; }
    | CHAR  { var_type_pointer = 4; }
    ;

id:
    id ',' VARIABLE {
        if(checkDeclared($3)==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            varAssign($3);
        }
    }
    | id ',' VARIABLE '=' expression {
        if(checkDeclared($3)==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            varAssign($3);
            setValue($3, $5); 
        }
    }
    | VARIABLE {
        if(checkDeclared($1)==1)
            printf("\nDuplicate Declaration!\n");
        else
            varAssign($1);
    }
    | VARIABLE '=' expression {
        if(checkDeclared($1)==1) {
            printf("\nDuplicate Declaration!\n");
        }
        else {
            varAssign($1);
            setValue($1, $3);
        }
    }
    ;

expression:
    NUMBER {
        $$ = malloc(20);
        // Check if it's a float literal
        if(strchr($1, '.') != NULL) {
            var_type_pointer = 1; // float
        } else {
            var_type_pointer = 0; // int
        }
        strcpy($$, $1); 
    }
    | STR {
        $$ = malloc(20);
        var_type_pointer = 2; // string
        strcpy($$, $1); 
    }
    | CHAR_LIT {
        $$ = malloc(20);
        var_type_pointer = 4; // char
        strcpy($$, $1);
    }
    | VARIABLE {
        $$ = malloc(20);
        if(checkDeclared($1) == 0) {
            sprintf($$, "%d", 0);
            printf("\n%s Not Declared!\n", $1);
        }
        else {
            int index = getValue($1);
            if(type[index] == 0){
                var_type_pointer = 0;
                sprintf($$, "%d", store_int[index]);
            }
            else if(type[index] == 1){
                var_type_pointer = 1;
                sprintf($$, "%f", store_float[index]);
            }
            else if(type[index] == 2){
                var_type_pointer = 2;
                strcpy($$, store_String[index]);
            }
            else if(type[index] == 4){
                var_type_pointer = 4;
                sprintf($$, "'%c'", store_char[index]);
            }
            else{
                printf("\nCan't Process Value as Variable is a Function or Invalid!\n");
            }
        }
    }
    | expression '+' expression { 
        $$ = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue($1);
        int idx2 = getValue($3);
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else if(strchr($1, '"') != NULL) type1 = 2; // string literal
        else if(strchr($1, '\'') != NULL) type1 = 4; // char literal
        else type1 = (strchr($1, '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else if(strchr($3, '"') != NULL) type2 = 2; // string literal
        else if(strchr($3, '\'') != NULL) type2 = 4; // char literal
        else type2 = (strchr($3, '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform addition with string type\n");
            sprintf($$, "0");
        }
        else if(type1 == 4 || type2 == 4) {
            printf("\nType Error: Cannot perform addition with char type\n");
            sprintf($$, "0");
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot add different types. Please use type conversion\n");
            sprintf($$, "0");
        }
        else {
            float num1 = atof($1);
            float num2 = atof($3);
            float num3 = num1 + num2;
            sprintf($$, "%f", num3);	 
            printf("\nAdd Value: %f\n", num3);
        }
    }
    | expression '-' expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        float num3 = num1 - num2;
        sprintf($$, "%f", num3);
        printf("\nSub Value: %f\n", num3);
	}
	| expression '*' expression {
        $$ = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue($1);
        int idx2 = getValue($3);
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr($1, '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr($3, '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform multiplication with string type\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot multiply different types. Please use type conversion\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else {
            float num1 = atof($1);
            float num2 = atof($3);
            float num3 = num1 * num2;
            sprintf($$, "%f", num3);
            printf("\nMul Value: %f\n", num3);
        }
	}
	| expression '/' expression {
        $$ = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue($1);
        int idx2 = getValue($3);
        float num1 = atof($1);
        float num2 = atof($3);
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr($1, '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr($3, '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform division with string type\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot divide different types. Please use type conversion\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else if(num2 == 0.0) {
            printf("\nDiv by Zero is Not Possible!\n");
            sprintf($$, "0");
        }
        else {
            float num3 = num1 / num2;
            sprintf($$, "%f", num3);
            printf("\nDiv Value: %f\n", num3);
        }
	}
	| expression '^' expression {
        $$ = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue($1);
        int idx2 = getValue($3);
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr($1, '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr($3, '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform power operation with string type\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else if(type1 != type2) {
            printf("\nType Error: Cannot use power operation between different types. Please use type conversion\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else {
            float num1 = atof($1);
            float num2 = atof($3);
            float num3 = pow(num1, num2);
            sprintf($$, "%f", num3);
            printf("\nPower Value: %f\n", num3);
        }
	}
	| expression MOD expression {
        $$ = malloc(20);
        int type1 = -1, type2 = -1;
        int idx1 = getValue($1);
        int idx2 = getValue($3);
        
        // Get types for variables
        if(idx1 != -1) type1 = type[idx1];
        else type1 = (strchr($1, '.') != NULL) ? 1 : 0;
        
        if(idx2 != -1) type2 = type[idx2];
        else type2 = (strchr($3, '.') != NULL) ? 1 : 0;
        
        // Check for type mismatch
        if(type1 == 2 || type2 == 2) {
            printf("\nType Error: Cannot perform modulo with string type\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else if(type1 == 1 || type2 == 1) {
            printf("\nType Error: Modulo operation not allowed with float type\n");
            sprintf($$, "0");
            // Don't return, continue execution
        }
        else {
            int num1 = atoi($1);
            int num2 = atoi($3);
            int num3 = num1 % num2;
            sprintf($$, "%d", num3);	 
            printf("\nRemainder Value: %d\n", num3);
        }
	}
	| '(' expression ')' {
        $$ = malloc(20);
        strcpy($$, $2); 
    }
    | expression LT expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 < num2;
        sprintf($$, "%d", num3);
        printf("\nLess Than Value: %d\n", num3);
	}
	| expression GT expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 > num2;
        sprintf($$, "%d", num3);
        printf("\nGreater Than Value: %d\n", num3);
	}
	| expression LEQ expression {
        $$ = malloc(20); 
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 <= num2;
        sprintf($$, "%d", num3);
        printf("\nLess Than or Equal To Value: %d\n", num3); 
	}
	| expression GEQ expression {
        $$ = malloc(20); 
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 >= num2;
        sprintf($$, "%d", num3);
        printf("\nGreater Than or Equal To Value: %d\n", num3);
	}	
	| expression EQ expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 == num2;
        sprintf($$, "%d", num3);
        printf("\nEqual To Value: %d\n", num3);
	}
	| expression NEQ expression {
        $$ = malloc(20);
        float num1 = atof($1);
        float num2 = atof($3);
        int num3 = num1 != num2;
        sprintf($$, "%d", num3);
        printf("\nNot Eqaul To Value: %d\n", num3);
	}
    | VARIABLE INC {
        $$ = malloc(20);
        if( checkDeclared($1) == 0) {
            sprintf($$, "%d", 0);
            printf("\n%s is Not Declared!\n", $1);
        }
        else {
            int index = getValue($1);
            if(type[index] == 0){
                int tmp = store_int[index];
                tmp = tmp+1;
                store_int[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After Increment: %d\n", tmp);
            }
            else if(type[index] == 1){
                float tmp = store_float[index];
                tmp = tmp+1;
                store_float[index] = tmp;
                sprintf($$, "%f", tmp);
                printf("\nValue After Increment: %f\n", tmp);
            }
            else{
                printf("\nCan't Process Increament as Variable is a String or a Function!\n");
            }
        }
    }
	| VARIABLE DEC {
        $$ = malloc(20);
  		if( checkDeclared($1) == 0) {
            sprintf($$, "%d", 0);
     		printf("\n%s Not Declared!\n", $1);
   		}
    	else {
            int index = getValue($1);
            if(type[index] == 0){
                int tmp = store_int[index];
                tmp = tmp-1;
                store_int[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After Decrement: %d\n", tmp);
            }
            else if(type[index] == 1){
                float tmp = store_float[index];
                tmp = tmp-1;
                store_float[index] = tmp;
                sprintf($$, "%f", tmp);
                printf("\nValue After Decrement: %f\n", tmp);
            }
            else{
                printf("\nCan't Process Decrement as Variable is a String or a Function!\n");
            }
        }
	}
    | NOT VARIABLE {
        $$ = malloc(20);
  		if( checkDeclared($2) == 0) {
            sprintf($$, "%d", 0);
            printf("\n%s Not Declared!\n", $2);
   		}
        else {
            int index = getValue($2);
            if(type[index] == 0){
                int tmp = store_int[index];
                tmp = !tmp;
                store_int[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After NOT Operation: %d\n", tmp);
            }
            else if(type[index] == 1){
                int tmp = store_float[index];
                tmp = !tmp;
                store_float[index] = tmp;
                sprintf($$, "%d", tmp);
                printf("\nValue After NOT Operation: %d\n", tmp);
            }
            else{
                printf("\nCan't Process NOT Operation as Variable is a String or a Function!\n");
            }
        }
	}
    | SIN '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Sin(%f): %lf\n", x, sin(x*3.1416/180));
        sprintf($$, "%lf", sin(x*3.1416/180));
	}
	| COS '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Cos(%f): %lf\n", x, cos(x*3.1416/180));
        sprintf($$, "%lf", cos(x*3.1416/180));
	}
	| TAN '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Tan(%f): %lf\n", x, tan(x*3.1416/180));
        sprintf($$, "%lf", tan(x*3.1416/180));
	}
	| LOG '(' expression ')' {
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Log(%f): %lf\n", x, (log(x*1.0)/log(10.0)));
        sprintf($$, "%lf", (log(x*1.0)/log(10.0)));
	}
	| LN '(' expression ')'	{
        $$ = malloc(20);
        float x = atof($3);
		printf("\nValue of Ln(%f): %lf\n", x, (log(x)));
        sprintf($$, "%lf", (log(x)));
	}
    | ODDEVEN '(' expression ')' {
        $$ = malloc(20);
        int x = atoi($3);
        if(x%2==0) {
            sprintf($$, "%d", 0);
            printf("\n%d is An Even Number\n", x);
        } 
        else {
            sprintf($$, "%d", 1);
            printf("\n%d is An Odd Number\n", x);
        }        
    }
	| FACTORIAL '(' expression ')' {
        $$ = malloc(20);
        int ans = 1;
        int i;
        int x = atoi($3);
        for(i=1; i<=x; i++) {
            ans = ans*i;
        }
        printf("\nFactorial of %d is: %d\n", x, ans);
        sprintf($$, "%d", ans);
    }
	| MAX '(' expression ',' expression ')' {
        $$ = malloc(20);
        float num1 = atof($3);
        float num2 = atof($5);
        if( num1 < num2 ) {
            sprintf($$, "%f", num2);
            printf("\nMax Number Between %f and %f is: %f\n", num1, num2, num2);
        }
        else {
            sprintf($$, "%f", num1);
            printf("\nMax Number Between %f and %f is: %f\n", num1, num2, num1);
        }
    }
	| MIN '(' expression ',' expression ')' {
        $$ = malloc(20);
        float num1 = atof($3);
        float num2 = atof($5);
        if( num1 < num2 ) {
            sprintf($$, "%f", num1);
            printf("\nMin Number Between %f and %f is: %f\n", num1, num2, num1);
        }
        else {
            sprintf($$, "%f", num2);
            printf("\nMin Number Between %f and %f is: %f\n", num1, num2, num2);
        }
    }
	| PRIME '(' expression ')' {
        $$ = malloc(20);
        int x = atoi($3);
        int ck = 0;
        int i; 
        for(i=2; i*i<=x; i++) {
            if( x%i == 0 ) {
                ck = 1;
                break;
            }
        }
        if(ck || x==1) {
            sprintf($$, "%d", 0);
            printf("\n%d is Not A Prime Number\n", x);
        }
        else {
            sprintf($$, "%d", 1);
            printf("\n%d is A Prime Number\n", x);
        }
    }
    | STRJOIN '(' expression ',' expression ')' {
        $$ = malloc(1000);
        char temp[1000] = "";
        
        // Handle first string
        if(getValue($3) != -1) {
            int idx1 = getValue($3);
            if(type[idx1] == 2) {
                // Remove quotes from stored string
                char *str1 = store_String[idx1];
                str1++; // Skip first quote
                str1[strlen(str1)-1] = '\0'; // Remove last quote
                strcat(temp, str1);
            } else {
                printf("\nError: First operand must be string for concatenation\n");
                strcpy($$, "");
                return 0;
            }
        } else {
            // Remove quotes from literal string
            char *str1 = strdup($3);
            str1++; // Skip first quote
            str1[strlen(str1)-1] = '\0'; // Remove last quote
            strcat(temp, str1);
        }
        
        // Handle second string
        if(getValue($5) != -1) {
            int idx2 = getValue($5);
            if(type[idx2] == 2) {
                // Remove quotes from stored string
                char *str2 = store_String[idx2];
                str2++; // Skip first quote
                str2[strlen(str2)-1] = '\0'; // Remove last quote
                strcat(temp, str2);
            } else {
                printf("\nError: Second operand must be string for concatenation\n");
                strcpy($$, "");
                return 0;
            }
        } else {
            // Remove quotes from literal string
            char *str2 = strdup($5);
            str2++; // Skip first quote
            str2[strlen(str2)-1] = '\0'; // Remove last quote
            strcat(temp, str2);
        }
        
        sprintf($$, "%s", temp);
        printf("\nConcatenated String: %s\n", $$);
    }
    ;

%%

int yywrap()
{
	return 1;
}

int main()
{	
	yyin = freopen("input.txt","r",stdin);
	yyout = freopen("output.txt","w",stdout);
    yyparse();
	return 0;	
}

