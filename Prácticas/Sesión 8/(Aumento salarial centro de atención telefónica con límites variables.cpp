/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 02/11/2016
	Sesión 8 Ejercicio 12
		
Retome la solución del ejercicio 11 de esta Relación de Problemas. Modifíquela para
tener en cuenta que los límites correspondientes a los casos resueltos (20 y 30) y el
grado de satisfacción media (4), así como los porcentajes de incrementos correspondientes
(3%, 4% y 2%) ya no son constantes sino que pueden variar.
Por lo tanto, debe leer desde teclado dichos valores límites (justo después del salario
por hora y en el orden indicado anteriormente) y cambiar la función definida en el
ejercicio 11 para que tenga en cuenta este cambio.

Puede utilizar el fichero de datos
datos_atencion_telefonica_limites_variables.txt
disponible en decsai. La salida correcta para este fichero es
1016.196 118.287 128.893
*/

#include <iostream>
using namespace std;

double SalarioFinal (int casos_resueltos, double horas_trabajadas, double salario_por_hora, double satisfaccion_usuario,
							int LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS, int LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS,
							double PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS, double PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS, double PORC_SUBIDA_SATISFACCION_USUARIOS,
							double LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS){
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
   
   int LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS,
             LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS;
  	double PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS,
                PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS,
                PORC_SUBIDA_SATISFACCION_USUARIOS;
   double LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS;
   
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
   cin >> LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS;
   cin >> LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS;
   cin >> LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS;
   cin >> PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS;
   cin >> PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS;
   cin >> PORC_SUBIDA_SATISFACCION_USUARIOS;
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
      
   salario_1 = SalarioFinal(total_casos_resueltos_empleado_1, total_horas_empleado_1, salario_por_hora, grado_medio_satisf_empleado_1,
									LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS, LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS, PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS, 
									PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS, PORC_SUBIDA_SATISFACCION_USUARIOS, LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS);
   salario_2 = SalarioFinal(total_casos_resueltos_empleado_2, total_horas_empleado_2, salario_por_hora, grado_medio_satisf_empleado_2,
									LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS, LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS, PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS, 
									PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS, PORC_SUBIDA_SATISFACCION_USUARIOS, LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS);
   salario_3 = SalarioFinal(total_casos_resueltos_empleado_3, total_horas_empleado_3, salario_por_hora, grado_medio_satisf_empleado_3,
									LIMITE_INFERIOR_ALGUNOS_CASOS_RESUELTOS, LIMITE_INFERIOR_MUCHOS_CASOS_RESUELTOS, PORC_SUBIDA_ALGUNOS_CASOS_RESUELTOS, 
									PORC_SUBIDA_MUCHOS_CASOS_RESUELTOS, PORC_SUBIDA_SATISFACCION_USUARIOS, LIMITE_INFERIOR_GRADO_SATISFACCION_USUARIOS);
   
   cout << "\n\n" << salario_1 << " " << salario_2 << " " << salario_3;
}
