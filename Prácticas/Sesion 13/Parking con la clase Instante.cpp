/*
 Nombre: José Antonio Padial Molina
 Curso: 1ºC
 Sesión: 13 Ejercicio 10
 
 Descripción:
 
Recupere la solución del ejercicio 46 de la relación de
problemas III (Parking con clases y struct)
Re-escríbalo para que los instantes sean objetos de la clase Instante. Por lo tanto,
tiene que eliminar la función que calculaba los minutos entre dos instantes y hacerlo
dentro de la clase Instante.
*/

#include <iostream>  
using namespace std; 


struct InstanteTiempo{
   int hora;
   int minuto;
   int segundo;
};

int MinutosEntreInstantes (InstanteTiempo inicial, InstanteTiempo final){
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
   int segundos_iniciales, segundos_finales, segundos_diferencia;

   segundos_iniciales = SEGUNDOS_POR_MINUTO * (inicial.hora * MINUTOS_POR_HORA   +
                                               inicial.minuto) +
                        inicial.segundo;

   segundos_finales   = SEGUNDOS_POR_MINUTO * (final.hora * MINUTOS_POR_HORA   +
                                               final.minuto) +
                       final.segundo;

   segundos_diferencia = abs(segundos_finales - segundos_iniciales);

   return segundos_diferencia / SEGUNDOS_POR_MINUTO;
}

class Instante{
   private:
      const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
      int segundos_iniciales, segundos_finales, segundos_diferencia;
   public:
      int MinutosEntreInstantes (InstanteTiempo inicial, InstanteTiempo final){
         
         segundos_iniciales = SEGUNDOS_POR_MINUTO * (inicial.hora * MINUTOS_POR_HORA   +
                                                     inicial.minuto) +
                              inicial.segundo;

         segundos_finales   = SEGUNDOS_POR_MINUTO * (final.hora * MINUTOS_POR_HORA   +
                                                     final.minuto) +
                             final.segundo;

         segundos_diferencia = abs(segundos_finales - segundos_iniciales);

         return segundos_diferencia / SEGUNDOS_POR_MINUTO;
      } 
};

class Parking{
private:
   int lim_1, lim_2, lim_3, lim_4;
   double tarifa_1, tarifa_2, tarifa_3, tarifa_4;
   double tarifa_dia;
public:
   Parking  (int limite_tramo_1, int limite_tramo_2,
               int limite_tramo_3, int limite_tramo_4,
               double tarifa_tramo_1, double tarifa_tramo_2,
               double tarifa_tramo_3, double tarifa_tramo_4,
               double tarifa_dia_completo){
      lim_1 = limite_tramo_1;
      lim_2 = limite_tramo_2;
      lim_3 = limite_tramo_3;
      lim_4 = limite_tramo_4;
      tarifa_1 = tarifa_tramo_1;
      tarifa_2 = tarifa_tramo_2;
      tarifa_3 = tarifa_tramo_3;
      tarifa_4 = tarifa_tramo_4;
      tarifa_dia = tarifa_dia_completo;
   }
   
   double Tarifa(int minutos_estacionamiento){
      int minutos_tramo_1, minutos_tramo_2, minutos_tramo_3, minutos_tramo_4;
      double tarifa;
      bool tiempo_limite_rebasado;

      minutos_tramo_1 = 0;
      minutos_tramo_2 = 0;
      minutos_tramo_3 = 0;
      minutos_tramo_4 = 0;

      tiempo_limite_rebasado  = (minutos_estacionamiento > lim_4);

      if (!tiempo_limite_rebasado){
         if (minutos_estacionamiento < lim_1)
            minutos_tramo_1 = minutos_estacionamiento;
         else{
            minutos_tramo_1 = lim_1;

            if (minutos_estacionamiento < lim_2)
               minutos_tramo_2 = minutos_estacionamiento - lim_1;
            else{
               minutos_tramo_2 = lim_2 - lim_1;

               if (minutos_estacionamiento < lim_3)
                  minutos_tramo_3 = minutos_estacionamiento - lim_2;
               else{
                  minutos_tramo_3 = lim_3 - lim_2;
                  minutos_tramo_4 = minutos_estacionamiento - lim_3;
               }
            }
         }
      }

      if (tiempo_limite_rebasado)
         tarifa = tarifa_dia;
      else
         tarifa = minutos_tramo_1 * tarifa_1
                  +
                  minutos_tramo_2 * tarifa_2
                  +
                  minutos_tramo_3 * tarifa_3
                  +
                  minutos_tramo_4 * tarifa_4;

      return tarifa;
   }
};


int main(){   
   const int TERMINADOR_ENTRADA_DATOS = -1;
   Instante calculo_de_tiempo;
   int limite_tramo_1_parking_1, limite_tramo_2_parking_1, 
       limite_tramo_3_parking_1, limite_tramo_4_parking_1,
       limite_tramo_1_parking_2, limite_tramo_2_parking_2, 
       limite_tramo_3_parking_2, limite_tramo_4_parking_2;
       
   double tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1, 
          tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1,
          tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2, 
          tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2;
          
   double tarifa_dia_completo_parking_1, tarifa_dia_completo_parking_2;
   double tarifa_parking_1, tarifa_parking_2;
   double total_recaudado_parking_1, total_recaudado_parking_2;
   
   int minutos_estacionamiento;

   InstanteTiempo instante_inicial, instante_final;
   
   
   cout << "Parking.\n\n";
 
   cin >> limite_tramo_1_parking_1;
   cin >> limite_tramo_2_parking_1;
   cin >> limite_tramo_3_parking_1;
   cin >> limite_tramo_4_parking_1;
   cin >> tarifa_tramo_1_parking_1;
   cin >> tarifa_tramo_2_parking_1;
   cin >> tarifa_tramo_3_parking_1;
   cin >> tarifa_tramo_4_parking_1;
   cin >> tarifa_dia_completo_parking_1;
   cin >> limite_tramo_1_parking_2;
   cin >> limite_tramo_2_parking_2;
   cin >> limite_tramo_3_parking_2;
   cin >> limite_tramo_4_parking_2;
   cin >> tarifa_tramo_1_parking_2;
   cin >> tarifa_tramo_2_parking_2;
   cin >> tarifa_tramo_3_parking_2;
   cin >> tarifa_tramo_4_parking_2;
   cin >> tarifa_dia_completo_parking_2;
   
   Parking parking_1(limite_tramo_1_parking_1, limite_tramo_2_parking_1,
                     limite_tramo_3_parking_1, limite_tramo_4_parking_1,
                     tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1,
                     tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1,
                     tarifa_dia_completo_parking_1);
                     
   Parking parking_2(limite_tramo_1_parking_2, limite_tramo_2_parking_2,
                     limite_tramo_3_parking_2, limite_tramo_4_parking_2,
                     tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2,
                     tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2,
                     tarifa_dia_completo_parking_2);

   
   total_recaudado_parking_1 = 0;
   total_recaudado_parking_2 = 0;

   cin >> instante_inicial.hora;
   
   while (instante_inicial.hora != TERMINADOR_ENTRADA_DATOS){
      cin >> instante_inicial.minuto;
      cin >> instante_inicial.segundo;

      cin >> instante_final.hora;
      cin >> instante_final.minuto;
      cin >> instante_final.segundo;

      minutos_estacionamiento = calculo_de_tiempo.MinutosEntreInstantes(instante_inicial, instante_final);

      tarifa_parking_1 = parking_1.Tarifa(minutos_estacionamiento);
      tarifa_parking_2 = parking_2.Tarifa(minutos_estacionamiento);
                                   
      cout << "\nTarifa resultante con cada parking:\n" 
           << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n"; 
      
      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cin >> instante_inicial.hora;
   }
   
   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";
}



