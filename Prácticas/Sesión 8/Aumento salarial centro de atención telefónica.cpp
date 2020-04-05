/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 8 Ejercicio 11
		
	Retome la solución de los ejercicios 11 y 28 (servicio atención telefónica) de la Relación
	de Problemas II. Recordemos que el criterio de subida salarial era el siguiente:
	Entre 20 y 30 casos resueltos: +3%
	Más de 30 casos resueltos: +4%
	Grado de satisfacción >= 4: +2%
	Defina una función SalarioFinal que calcule el salario final del trabajador, en función
	de los datos anteriores.
	Al igual que se pedía en el ejercicio 28 debe ir leyendo los datos de tres empleados
	en el siguiente orden:
	7.5 <- Salario de 7.5 euros por hora (el mismo para todos)
	2 124 1 3 <- Empleado 2, 124'', resuelto, grado sat: 3
	1 32 0 0 <- Empleado 1, 32'' , no resuelto, grado sat: 0
	2 26 0 2 <- Empleado 2, 26'' , no resuelto, grado sat: 2
	-1 <- Fin de entrada de datos
	El número de horas trabajadas de cada empleado será un número real y se calculará
	en función de la suma total de segundos dedicados a cada llamada telefónica (la compañía
	no paga por el tiempo de estancia en la empresa sino por el tiempo dedicado a
	resolver casos)
	El programa debe llamar a la función SalarioFinal para calcular el salario final de
	cada uno de los tres empleados y los debe mostrar en pantalla.
	Puede utilizar el fichero de datos datos_atencion_telefonica.txt
	disponible en decsai. La salida correcta para este fichero es
	1016.196 118.287 128.893
*/

#include <iostream>
using namespace std;

double SalarioFinal (int casos_resueltos, double horas_trabajadas, double salario_por_hora, double satisfaccion_usuario){
	const double PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS = 0.03,
                PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS  = 0.04,

                PORC_SUBIDA_SATISFACCION_USUARIOS   = 0.02;

   const int LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS    = 30,
             LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS   = 20;

   const double LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS = 4.0;

   double salario_base, salario_final,
          porcentaje_incremento_salarial;
	
	if (casos_resueltos > LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS)
      porcentaje_incremento_salarial = PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS;
   else if (casos_resueltos >= LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS)
      porcentaje_incremento_salarial = PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS;
   else
      porcentaje_incremento_salarial = 0;            // <- Importante!!

   if (satisfaccion_usuario >= LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS)
      porcentaje_incremento_salarial = porcentaje_incremento_salarial
                                       +
                                       PORC_SUBIDA_SATISFACCION_USUARIOS;

   salario_base  = salario_por_hora * horas_trabajadas;
   salario_final = salario_base * (1 + porcentaje_incremento_salarial);
   
   return salario_final;
}

int main(){
   const int TERMINADOR = -1;
   const int CODIGO_EMPLEADO_1 = 1, CODIGO_EMPLEADO_2 = 2,
             CODIGO_EMPLEADO_3 = 3;

   double salario_por_hora;
   double grado_medio_satisf_empleado_1,
          grado_medio_satisf_empleado_2,
          grado_medio_satisf_empleado_3;
   int    codigo_empleado, /*codigo_caso_resuelto,*/ satisfaccion_usuario,
          total_casos_empleado_1, total_casos_empleado_2, 
          total_casos_empleado_3, total_casos;
   int    segundos_dedicados_caso;
   bool   hay_al_menos_un_caso, codigo_caso_resuelto;
   int total_seg_empleado_1, total_seg_empleado_2, total_seg_empleado_3;
   double total_horas_empleado_1, total_horas_empleado_2, total_horas_empleado_3;
   double salario_1, salario_2, salario_3;
   int total_casos_resueltos_empleado_1, total_casos_resueltos_empleado_2, total_casos_resueltos_empleado_3;
   
   grado_medio_satisf_empleado_1 = 0;
   grado_medio_satisf_empleado_2 = 0;
   grado_medio_satisf_empleado_3 = 0;
   total_casos_empleado_1 = 0;
   total_casos_empleado_2 = 0;
   total_casos_empleado_3 = 0;
   total_seg_empleado_1 = 0;
   total_seg_empleado_2 = 0;
   total_seg_empleado_3 = 0;
   total_casos_resueltos_empleado_1 = 0;
	total_casos_resueltos_empleado_2 = 0;
	total_casos_resueltos_empleado_3 = 0;
   
   cout << "Centro de atención telefónica\n\n";
   cout << "\n\nIntroduzca los datos -> ";
   cin  >> salario_por_hora;
   cin >> codigo_empleado;
   
   while (codigo_empleado != TERMINADOR){
      cin >> segundos_dedicados_caso;
      cin >> codigo_caso_resuelto;
      cin >> satisfaccion_usuario;

      if (codigo_empleado == CODIGO_EMPLEADO_1){
         if(codigo_caso_resuelto)
				total_casos_resueltos_empleado_1++;
			total_casos_empleado_1++;
         total_seg_empleado_1 += segundos_dedicados_caso;
         grado_medio_satisf_empleado_1 = grado_medio_satisf_empleado_1
                                         +
                                         satisfaccion_usuario;
      }
      else if (codigo_empleado == CODIGO_EMPLEADO_2){
         if(codigo_caso_resuelto)
         	total_casos_resueltos_empleado_2++;
			total_casos_empleado_2++;
         total_seg_empleado_2 += segundos_dedicados_caso;
         grado_medio_satisf_empleado_2 = grado_medio_satisf_empleado_2
                                         +
                                         satisfaccion_usuario;
      }
      else if (codigo_empleado == CODIGO_EMPLEADO_3){
         if(codigo_caso_resuelto)
         	total_casos_resueltos_empleado_3++;
			total_casos_empleado_3++;
         total_seg_empleado_3 += segundos_dedicados_caso;
         grado_medio_satisf_empleado_3 = grado_medio_satisf_empleado_3
                                         +
                                         satisfaccion_usuario;
      }
      
      cin >> codigo_empleado;
   }
   
   total_casos = total_casos_empleado_1 + total_casos_empleado_2 +
                 total_casos_empleado_3;
   
   hay_al_menos_un_caso = total_casos > 0;
   
   if (hay_al_menos_un_caso){
      if (total_casos_empleado_1 == 0)
         grado_medio_satisf_empleado_1 = 0.0;
      else
         grado_medio_satisf_empleado_1 = grado_medio_satisf_empleado_1
                                         /
                                         total_casos_empleado_1;
      if (total_casos_empleado_2 == 0)
         grado_medio_satisf_empleado_2 = 0.0;                                 
      else
         grado_medio_satisf_empleado_2 = grado_medio_satisf_empleado_2
                                         /
                                         total_casos_empleado_2;
                                         
      if (total_casos_empleado_3 == 0)
         grado_medio_satisf_empleado_3 = 0.0;                                 
      else
         grado_medio_satisf_empleado_3 = grado_medio_satisf_empleado_3
                                         /
                                         total_casos_empleado_3;
   }
   
   total_horas_empleado_1 = total_seg_empleado_1/3600.0;
	total_horas_empleado_2 = total_seg_empleado_2/3600.0;
	total_horas_empleado_3 = total_seg_empleado_3/3600.0;
      
   salario_1 = SalarioFinal(total_casos_resueltos_empleado_1, total_horas_empleado_1, salario_por_hora, grado_medio_satisf_empleado_1);
   salario_2 = SalarioFinal(total_casos_resueltos_empleado_2, total_horas_empleado_2, salario_por_hora, grado_medio_satisf_empleado_2);
   salario_3 = SalarioFinal(total_casos_resueltos_empleado_3, total_horas_empleado_3, salario_por_hora, grado_medio_satisf_empleado_3);
   
   cout << "\n\n" << salario_1 << " " << salario_2 << " " << salario_3;
}
