#include <stdio.h>
#include <string.h>
#include <time.h>

//---ESTRUCTURA ASCENDENTE---

//------Variables globales------
int CapacidadAvion_Eco = 200;
int CapacidadAvion_Premium = 50;

float ValorDest_America = 2800000;
float ValorDest_Europa = 3500000;
float ValorDest_Asia = 4200000;

float PorcFecha_Eco = 30;
float PorcFecha_Premium = 40;

float PorcAnticipacion = 50;

float Diferencia_EcoPremium = 3000000;

float Serv_EquipAdd = 150000;
float Serv_Asiento = 40000;
float Serv_Comida = 20000; //Solo para clase económica


//---FUNCIONES---

//Validación de fecha desde 1 Enero 2024 hasta 1 de Enero de 2025
int FechaValida(int year, int month, int day) {
    if ((year == 2024 && (month <= 12 && month >= 1) && (day <= 31 && day >= 1)) || (year == 2025 && month == 1 && day == 1)) {
        return 0;
    }
    else{
    	return 1;
	}
}

//Se calcula los meses de diferencia sin tener en cuenta el día
int Calc_MesesDiferencia(struct tm fechaHoy, char nombreDestino[50]){
    struct tm Fecha_Destino = {0};
    int year_dest, month_dest;

    if(strcmp(nombreDestino, "Francia") == 0){
        year_dest = 2024;
        month_dest = 11;
    } else if(strcmp(nombreDestino, "Espania") == 0){
        year_dest = 2024;
        month_dest = 11;
    } else if(strcmp(nombreDestino, "Estados Unidos") == 0){
        year_dest = 2024;
        month_dest = 12;
    } else if(strcmp(nombreDestino, "China") == 0){
        year_dest = 2025;
        month_dest = 1;
    } else {
        year_dest = 2025;
        month_dest = 1;
    }

    Fecha_Destino.tm_year = year_dest - 1900;
    Fecha_Destino.tm_mon = month_dest - 1;

    int year_diff = Fecha_Destino.tm_year - fechaHoy.tm_year;
    int month_diff = Fecha_Destino.tm_mon - fechaHoy.tm_mon;

    int MesesDif = year_diff * 12 + month_diff;

    return MesesDif;
}

// Función para calcular la anticipación del vuelo
float Anticipacion_Vuelo(int MesesDiferencia, float BoletoBase) {
    if (MesesDiferencia >= 5) {
        return (BoletoBase * PorcAnticipacion) / 100;
    } else {
        return 0;
    }
}

//---FUNCIÓN MAIN---

int main(){
	
	//--Variables de entrada
	char nombreDestino[50] = "Francia";
	
    struct tm fechaHoy = {0};
    int year, month, day;

	
	//--Variables de salida
	
	
	//--Variables auxiliares
	
	//RTA
	char RTA[2];
	
	//Valores
	float Valor_Dest, Valor_FechaDest, Valor_TipVuelo = 500;
	float BoletoBase;
	
	//Fechas y Anticipación
	int MesesDiferencia, Valor_AntVuelo;

	
	//--Pregunta
	do{
		printf("¿Desea iniciar sesion? SI/NO: ");
		scanf("%s", &RTA);
		//Limpiar buffer
	}while(strcmp(RTA, "SI")!=0&&strcmp(RTA,"NO")!=0);
	
	
	if(strcmp(RTA,"NO")==0){
		printf("Cerrando Sesión...");
	}
	
	//--Bucle While
	while(strcmp(RTA,"SI")==0){
		//--Se ingresan datos
			//Identificacion y Contraseña
			//Seleccione destino
			
			//Ingrese la fecha de hoy
			do{
			    printf("Ingrese la fecha de hoy (AAAA MM DD): ");
			    scanf("%d %d %d", &year, &month, &day);
			    fechaHoy.tm_year = year - 1900;
			    fechaHoy.tm_mon = month - 1;
			    fechaHoy.tm_mday = day;
				//Limpiar buffer
			}while(FechaValida(fechaHoy.tm_year + 1900, fechaHoy.tm_mon + 1, fechaHoy.tm_mday));
			
			//Tipo de Vuelo
				//Aumentar variable capacidad de vuelo
			
			//Se consulta por los servicios adicionales
				//Un array que permita seleccionar más de un servicio
			
		//--Se procesan datos en variables
		
		MesesDiferencia = Calc_MesesDiferencia(fechaHoy, nombreDestino);
		BoletoBase =  Valor_Dest + Valor_FechaDest + Valor_TipVuelo;
		Valor_AntVuelo = Anticipacion_Vuelo(MesesDiferencia, BoletoBase);
		
		//--Se informan resultados
			printf("\n %d", MesesDiferencia);
			printf("\n %.2f", Valor_AntVuelo);
	}
	
	//--Se muestran resultados finales
	
	return 0;
}
