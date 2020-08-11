#include <stdio.h>
#include <stdbool.h>


#define MSJ_BIENVENIDA "\nBienvenido aprendiz Padawan, para convertite en un verdadero Jedi, necesitamos informacion sobre de ti:\n"
#define MSJ_RECIBIR_MIDICLORIANOS ">>Ingrese la cantidad de midiclorianos que posees en el rango desde 100.0 y 2999.9 inclusive\n"
#define MSJ_MIDICLORIANOS_ACEPTADO " Ingreso correcto de midiclorianos ;)\n"

#define MSJ_RECIBIR_VOLUNTAD "\n>>Ingresa tu nivel tu voluntad de resistir la tentacion de entrar al lado oscuro de la Fuerza:\n [f]Floja - [b]Buena - [m]Mediana - [a]Alta - [e]Enorme - [p]Peligrosa\n"
#define MSJ_VOLUNTAD_ACEPTADO "Ingreso correcto de voluntad ;)\n"
#define MSJ_VOLUNTAD_FLOJA "\n ->Voluntad del Aprendiz es: FLOJA"
#define MSJ_VOLUNTAD_BUENA "\n ->Voluntad del Aprendiz es: BUENA"
#define MSJ_VOLUNTAD_MEDIANA "\n ->Voluntad del Aprendiz es: MEDIANA"
#define MSJ_VOLUNTAD_ALTA "\n ->Voluntad del Aprendiz es: ALTA"
#define MSJ_VOLUNTAD_ENORME "\n ->Voluntad del Aprendiz es: ENORME"
#define MSJ_VOLUNTAD_PELIGROSA "\n ->Voluntad del Aprendiz es: PELIGROSA"

#define MSJ_RECIBIR_PASADO "\n>>Ingresa como ha sido tu pasado:\n [b]Bueno - [n]Normal - [t]Tragico \n"
#define MSJ_PASADO_ACEPTADO " Ingreso correcto de pasado ;)\n"
#define MSJ_PASADO_BUENO "\n ->El Pasado del Aprendiz fue: BUENO"
#define MSJ_PASADO_NORMAL "\n ->El Pasado del Aprendiz fue: NORMAL"
#define MSJ_PASADO_TRAGICO "\n ->El Pasado del Aprendiz fue: TRAGICO"


#define MSJ_MAL_INGRESO "\nIngreso no valido, verifique el rango de ingreso y vuelva a intentar\n"
#define MSJ_INGRESO_ACEPTADO "Ingreso aceptado\n"

#define MSJ_FIN_ANALISIS "\n<<Querido aprendiz Padawan que termino tu analisis, deberas hablar con tu maestro>>\n"
#define MSJ_RESULTADOS "\n\n Maestro, estos son los resultados obtenidos del aprendiz Padawan:\n"
#define MSJ_ADVERTENCIA "\n Maestro Jedi:\n Transmite lo que has aprendido:fuerza, maestria;\n pero insensatez, debilidad, fracaso tambien.\n Si, fracaso sobre todo! El mejor profesor, el fracaso es.\n   By Master Yoda\n"

const float CANT_MIDICLORIANOS_DEF = 0.0F;
const float MIN_MIDICLORIANOS = 100.0F;
const float MAX_MIDICLORIANOS = 2999.9F;

const bool MIDICLO_VERIFICADO = true;
const bool MIDICLO_NO_VERIFICADO = false;

const char VOLUNTAD_DEF = 'v';
#define VOLUNTAD_FLOJA 'f'
#define VOLUNTAD_BUENA 'b'
#define VOLUNTAD_MEDIANA 'm'
#define VOLUNTAD_ALTA 'a'
#define VOLUNTAD_ENORME 'e'
#define VOLUNTAD_PELIGROSA 'p'


const float VALOR_VOLUNT_FLOJA_BUENA = 10.3F;
const float VALOR_VOLUNT_MED_ALTA = 54.5F;
const float VALOR_VOLUNT_ENORME_PELIG = 103.4F;
const int VALOR_MODIF_VOLUNTAD =20;

const float VALOR_VOLUNT_DEF = 0.0F;

const bool VOLUNTAD_VERIFICADO= true;
const bool VOLUNTAD_NO_VERIFICADO = false;


const char PASADO_DEF = 'p';
#define  PASADO_BUENO 'b'
#define  PASADO_NORMAL 'n'
#define  PASADO_TRAGICO 't'

const bool PASADO_VERIFICADO= true;
const bool PASADO_NO_VERIFICADO = false;


const float VALOR_PASADO_NORM_TRAG = 0.4F;
const float VALOR_PASADO_BUENO = 1.5F;

const float VALOR_PASADO_DEF = 0.0F;

const float VALOR_INFLUENCIA = 3.4F;
const float VALOR_INFLUENCIA_DEF = 0.0F;
const int VALOR_MODIF_INFLUENCIA = 75;

const float VALOR_OSCURIDAD = 0.001117684315F;
const float VALOR_PROB_DEF = 0.0F;
const float PROB_MAX = 80.0F;

const int TIEMPO_JEDI_DEF = -1;



/*Pre: -.
 *Post: Anuncia la bienvenida del aprendiz Padawan mediante consola.
*/
void recibir_padawan();



/*Pre: -.
 *Post: Pide la cantidad de midiclorianos al aprendiz, en caso de recibir un valor invalido lo informa 
 *		y vuelve a pedir el ingreso, caso contrario devuelve el valor recibido.
*/
float ingreso_midiclorianos();


/*Pre: "midiclorianos_verificar" debe corresponder al tipo de dato float.
 *Post: Devuelve "MIDICLO_VERIFICADO" si el valor de "midiclorianos_verifica" se encuentra 
 *	   	entre MIN_ANIMO y MAX_MIDICLORIANOS, caso contrario devuelve "MIDICLO_NO_VERIFICADO".
*/
bool verificar_midiclorianos(float midiclorianos_verificar);
	


/*Pre: -.
 *Post: Pide la voluntad al aprendiz, en caso de recibir un valor invalido lo informa  
 *		y vuelve a pedir el ingreso, caso contrario devuelve el valor recibido. 
*/
char ingreso_voluntad();


/*Pre: "voluntad_verificar" debe corresponder al tipo de dato char.
 *Post: Devuelve "VOLUNTAD_VERIFICADO" si el valor de "voluntad_verificar"  corresponda a las opciones válidas
 *      caso contrario devuelve "VOLUNTAD_NO_VERIFICADO.
*/
bool verificar_voluntad(float voluntad_verificar);



/*Pre:  "voluntad_recib_msj" corresponde "voluntad_recibida".
 *Post: Evalua la "voluntad_recib_msj", le asigna un mensaje perdeterminado de "voluntad_recibida" segun los valores válidos
 * 	    y muestra por consola el mensaje de la volunta recibida.
*/
void mostrar_voluntad(char voluntad_recib_msj);



/*Pre:  "nivel_voluntad" corresponde "voluntad_recibida".
 *Post: Evalua la "nivel_voluntad", le asigna un valor numerico, según los valores válidos
 * 		y devuelve el el valor evaluado".
*/
float valor_num_voluntad(char nivel_voluntad);



/*Pre: -.
 *Post: Pide el pasado al aprendiz, en caso de recibir un valor invalido lo informa  
 *		y vuelve a pedir el ingreso, caso contrario devuelve el valor recibido. 
*/
char ingreso_pasado();



/*Pre: "pasado_verificar" debe corresponder al tipo de dato char.
 *Post: Devuelve "PASADO_VERIFICADO" si el valor de "pasado_verificar" si corresponde a valores válidos
 *      caso contrario devuelve "PASADO_NO_VERIFICADO".
*/
bool verificar_pasado(float pasado_verificar);



/*Pre:  "pasado_recib_msj" corresponde "pasado_recibido".
 *Post: Evalua el carácter de "voluntad_recib_msj", le asigna un mensaje a "pasado_recibido" según valores válidos
 * 	    y muestra por consola el mensaje del pasado recibido.
*/
void mostrar_pasado (char pasado_recib_msj);



/*Pre:  "pasado_num" corresponde "pasado_recibido".
 *Post: Evalua el "pasado_num", le asigna un valor numerico, segun los valores correspondientes
 * 		y devuelve el valor numero asignado, según el "pasado_num"
*/
float valor_num_pasado (char pasado_num);



/*Pre: "valor_midiclorianos" corresponde al valor "midiclorianos_recibidos" y "influencia_def" corresponde al valor VALOR_INFLUENCIA_DEF.
 *Post: Calcula la influencia del Aprendiz y devuelve el resultado del cálculo.
*/
float calcular_influencia(float valor_midiclorianos, float influencia_def);


/*Pre: "num_voluntad" corresponde al valor numerico de voluntad, "oscuridad_def" corresponde al valor VALOR_OSCURIDAD,
 *	   "influencia_calc" cooresponde al valor de"calcular_influencia" y "num_pasado" corresponde al valor numerico de pasado.
 *Post: Calcula la probabilidad del Aprendiz de convertirse al lado oscuro y devuelve el resultado del calculo.
*/
float calcular_prob_convertirse(float num_voluntad, float oscuridad_def, float influencia_calc, float num_pasado);



/*Pre: -."nvo_valor_influencia" corresponde a "influencia"  con el nuevo valor de  VALOR_MODIF_INFLUENCIA  
 *		   y "nvo_valor_voluntad" corresponde a "num_voluntad" con el nuevo valor de VALOR_MODIF_VOLUNTAD		 	
 *Post:-. Calcula el tiempo restante para convertirse en jedi y devuelve resultado.
 */
int calcular_tiempo_restante_jedi(int nvo_valor_influencia , int nvo_valor_voluntad);



/*Pre: -.
 *Post: Informar mediante consola al aprendriz Padawan que termino el análisis y que hable con su maestro
*/
void finalizo_analisis();



/*Pre: Ingreso correcto de "midiclorianos", "voluntad", "pasado".
 *     Correcta asignacion de valor numérico a  "valor_voluntad" y "valor_pasado".
 *     "influencia", "probabilidad_convertirse" y "tiempo_restante_jedi" correctamente calculados.
 *Post: Informa al maestro los resultados obtenidos con las unidades, de su aprendriz Padawan
*/
void mostrar_resultados();



int main(){

    float midiclorianos = CANT_MIDICLORIANOS_DEF;
    char voluntad = VOLUNTAD_DEF;
    char pasado = PASADO_DEF;
	
    float valor_voluntad = VALOR_VOLUNT_DEF;
    float valor_pasado = VALOR_PASADO_DEF;
    float valor_influencia = VALOR_INFLUENCIA;
    float influencia = VALOR_INFLUENCIA_DEF;
	
    float probabilidad_convertirse = VALOR_PROB_DEF;
    float valor_oscuridad = VALOR_OSCURIDAD;
    int tiempo_restante_jedi = TIEMPO_JEDI_DEF;

    recibir_padawan();

    midiclorianos = ingreso_midiclorianos();

    voluntad = ingreso_voluntad();
	
    valor_voluntad = valor_num_voluntad(voluntad); 

    pasado = ingreso_pasado();

    valor_pasado = valor_num_pasado(pasado); 

    influencia = calcular_influencia(midiclorianos, valor_influencia);
 
    probabilidad_convertirse = calcular_prob_convertirse(valor_voluntad, valor_oscuridad, influencia, valor_pasado);
   
    tiempo_restante_jedi = calcular_tiempo_restante_jedi((int)influencia, (int)valor_voluntad);

    finalizo_analisis();

    mostrar_resultados();

    printf("\n ->Cantidad de Midiclorianos del Aprendiz: %.1f\n", midiclorianos);

    mostrar_voluntad(voluntad);

    printf("(%c)\n", voluntad);

    printf("\n ->El Valor Numerico de la Voluntad es: %.1f\n", valor_voluntad);
    		
    mostrar_pasado(pasado);
   
    printf("(%c)\n", pasado);

    printf("\n ->El Valor Numerico de su Pasado es: %.1f\n", valor_pasado );

    printf("\n ->El Aprendiz tiene un nivel de: %.1f de fuerza\n", influencia);

    printf("\n ->El Aprendiz tiene una Probalidad de Convertirse al Lado Oscuro de: %.1f%\n", probabilidad_convertirse);

    printf("\n ->El Aprendiz tardara %i meses en convertirse en Jedi\n", tiempo_restante_jedi);

    if (probabilidad_convertirse > PROB_MAX ){
	printf (MSJ_ADVERTENCIA);
	}

    return 0;

}

void recibir_padawan(){
	printf(MSJ_BIENVENIDA);
}


float ingreso_midiclorianos(){
	float midiclorianos_recibidos = CANT_MIDICLORIANOS_DEF;
	do{
		printf(MSJ_RECIBIR_MIDICLORIANOS);
		scanf("%f", &midiclorianos_recibidos);
		if(!verificar_midiclorianos(midiclorianos_recibidos)){
			printf(MSJ_MAL_INGRESO); 
		}else{
			printf(MSJ_MIDICLORIANOS_ACEPTADO);
		}
	}while(!verificar_midiclorianos(midiclorianos_recibidos));	
	
    return midiclorianos_recibidos;
}


bool verificar_midiclorianos(float midiclorianos_verificar){
	bool verificado = MIDICLO_VERIFICADO;
	if((midiclorianos_verificar < MIN_MIDICLORIANOS)||(midiclorianos_verificar > MAX_MIDICLORIANOS)){
		verificado = MIDICLO_NO_VERIFICADO;
	}
	return verificado;
}


char ingreso_voluntad(){
	char voluntad_recibida = VOLUNTAD_DEF;
	do{
		printf(MSJ_RECIBIR_VOLUNTAD);
		scanf(" %c", &voluntad_recibida);
		if(!verificar_voluntad(voluntad_recibida)){
			printf(MSJ_MAL_INGRESO); 
		}else{
			printf(MSJ_VOLUNTAD_ACEPTADO);
		}
	}while(!verificar_voluntad(voluntad_recibida));
   
     return voluntad_recibida;
}     


bool verificar_voluntad(float voluntad_verificar){
	bool verificado = VOLUNTAD_VERIFICADO;
	if((voluntad_verificar != VOLUNTAD_FLOJA) && (voluntad_verificar != VOLUNTAD_BUENA) && (voluntad_verificar != VOLUNTAD_MEDIANA) && (voluntad_verificar != VOLUNTAD_ALTA ) && (voluntad_verificar != VOLUNTAD_ENORME) && (voluntad_verificar != VOLUNTAD_PELIGROSA)){
		verificado = VOLUNTAD_NO_VERIFICADO;
	}
	return verificado;
}



void mostrar_voluntad(char voluntad_recib_msj){	
	if (voluntad_recib_msj == VOLUNTAD_FLOJA){
		printf (MSJ_VOLUNTAD_FLOJA);
	}else if (voluntad_recib_msj == VOLUNTAD_BUENA){
		printf (MSJ_VOLUNTAD_BUENA);		
	}else if (voluntad_recib_msj == VOLUNTAD_MEDIANA){
		printf (MSJ_VOLUNTAD_MEDIANA);		
	}else if (voluntad_recib_msj== VOLUNTAD_ALTA){
		printf (MSJ_VOLUNTAD_ALTA);
	}else if (voluntad_recib_msj== VOLUNTAD_ENORME){
		printf (MSJ_VOLUNTAD_ENORME);		
	}else{
		printf (MSJ_VOLUNTAD_PELIGROSA);
	}
}


float valor_num_voluntad(char nivel_voluntad){
	float valor_voluntad_evaluar = VALOR_VOLUNT_DEF;
	switch(nivel_voluntad){
		case VOLUNTAD_FLOJA:
			valor_voluntad_evaluar = VALOR_VOLUNT_FLOJA_BUENA;
			break;
		case VOLUNTAD_BUENA:
			valor_voluntad_evaluar = VALOR_VOLUNT_FLOJA_BUENA;
			break;
		case VOLUNTAD_MEDIANA:
			valor_voluntad_evaluar = VALOR_VOLUNT_MED_ALTA;
			break;
		case VOLUNTAD_ALTA:
			valor_voluntad_evaluar = VALOR_VOLUNT_MED_ALTA;
			break;
		case VOLUNTAD_ENORME:
			valor_voluntad_evaluar = VALOR_VOLUNT_ENORME_PELIG;
			break;
		default:
			valor_voluntad_evaluar = VALOR_VOLUNT_ENORME_PELIG;
	}
	return valor_voluntad_evaluar;
}



char ingreso_pasado(){
	char pasado_recibido = PASADO_DEF;
	do{
		printf(MSJ_RECIBIR_PASADO);
		scanf(" %c", &pasado_recibido);
		if(!verificar_pasado(pasado_recibido)){
			printf(MSJ_MAL_INGRESO); 
		}else{
			printf(MSJ_PASADO_ACEPTADO);
		}
	}while(!verificar_pasado(pasado_recibido));

	return pasado_recibido;
}

bool verificar_pasado(float pasado_verificar){
	bool verificado = PASADO_VERIFICADO;
	if((pasado_verificar != PASADO_BUENO) && (pasado_verificar != PASADO_NORMAL) && (pasado_verificar != PASADO_TRAGICO)){
		verificado = PASADO_NO_VERIFICADO;
	}
	return verificado;
}



void mostrar_pasado (char pasado_recib_msj){
    if(pasado_recib_msj == PASADO_BUENO){
		printf(MSJ_PASADO_BUENO);
	}else if(pasado_recib_msj == PASADO_NORMAL){
		printf(MSJ_PASADO_NORMAL);
	}else{
		printf(MSJ_PASADO_TRAGICO);
	}
}


float valor_num_pasado (char pasado_num){
	float valor_pasado_evaluar = VALOR_PASADO_DEF;
	switch(pasado_num){
		case PASADO_BUENO:
			valor_pasado_evaluar = VALOR_PASADO_BUENO;
			break;
		case PASADO_NORMAL:
			valor_pasado_evaluar = VALOR_PASADO_NORM_TRAG;
			break;
		default:
			valor_pasado_evaluar = VALOR_PASADO_NORM_TRAG;
	}
	return valor_pasado_evaluar;
}


float calcular_influencia(float valor_midiclorianos, float influencia_def){
	return (valor_midiclorianos * VALOR_INFLUENCIA);
}

float calcular_prob_convertirse(float num_voluntad, float oscuridad_def, float influencia_calc, float num_pasado){	
	return (num_voluntad + ((VALOR_OSCURIDAD * influencia_calc) / num_pasado));
}


int calcular_tiempo_restante_jedi(int nvo_valor_influencia , int nvo_valor_voluntad){
	int calc_nva_influencia = (nvo_valor_influencia - ((nvo_valor_influencia*VALOR_MODIF_INFLUENCIA)/100));
    int calc_nva_voluntad = (nvo_valor_voluntad + ((nvo_valor_voluntad*VALOR_MODIF_VOLUNTAD)/100));
	
    return (calc_nva_influencia /calc_nva_voluntad);
}


void finalizo_analisis(){
	printf(MSJ_FIN_ANALISIS);
}


void mostrar_resultados(){
	printf(MSJ_RESULTADOS);
}
 




 

 



