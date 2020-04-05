/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Fecha: 16/11/2016
	Sesión 10 Ejercicio 46
*/

#include <iostream>
using namespace std;

const int TERMINADOR_ENTRADA_DATOS = -1;
const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;

class Parking{
	private:
		struct Limites{
			int limite_tramo_1, limite_tramo_2, limite_tramo_3, limite_tramo_4;
		};
		
		struct Tarifa{
			double tarifa_tramo_1, tarifa_tramo_2, tarifa_tramo_3, tarifa_tramo_4;
		};
		
		Limites tramo;
		Tarifa tarifas;
		
      double tarifa_dia_completo;
		
	public:
		Parking(int limite_tramo_1, int limite_tramo_2, int limite_tramo_3, int limite_tramo_4,
					double tarifa_tramo_1, double tarifa_tramo_2, double tarifa_tramo_3, double tarifa_tramo_4,
					double tarifa_dia){
			setLimite(limite_tramo_1, limite_tramo_2, limite_tramo_3, limite_tramo_4);
			setTarifa(tarifa_tramo_1, tarifa_tramo_2, tarifa_tramo_3, tarifa_tramo_4);
			tarifa_dia_completo = tarifa_dia;
		}
		
		void setLimite(int limite_1, int limite_2, int limite_3, int limite_4){
			tramo.limite_tramo_1 = limite_1;
			tramo.limite_tramo_2 = limite_2;
			tramo.limite_tramo_3 = limite_3;
			tramo.limite_tramo_4 = limite_4;
		}
		
		void setTarifa(double tarifa_1, double tarifa_2, double tarifa_3, double tarifa_4){
			tarifas.tarifa_tramo_1 = tarifa_1;
			tarifas.tarifa_tramo_2 = tarifa_2;
			tarifas.tarifa_tramo_3 = tarifa_3;
			tarifas.tarifa_tramo_4 = tarifa_4;
		}
		
		int MinutosEntreInstantes (int hora_entrada, int minuto_entrada, int segundo_entrada,
                               int hora_salida, int minuto_salida, int segundo_salida){
		   int segundos_diferencia, segundos_iniciales, segundos_finales;
		   
		  	segundos_iniciales = SEGUNDOS_POR_MINUTO * (hora_entrada * MINUTOS_POR_HORA   +
		                                               minuto_entrada) +
		                        segundo_entrada;
		
		   segundos_finales   = SEGUNDOS_POR_MINUTO * (hora_salida * MINUTOS_POR_HORA   +
		                                               minuto_salida) +
		                        segundo_salida;
		
		   segundos_diferencia = segundos_finales - segundos_iniciales;
		
		   return segundos_diferencia / SEGUNDOS_POR_MINUTO;
		}
		
		double Tarifa (int minutos_estacionamiento){
                  
			int minutos_tramo_1, minutos_tramo_2, minutos_tramo_3, minutos_tramo_4;
		   double tarifa;
		   bool tiempo_limite_rebasado;
		   
		   minutos_tramo_1 = 0;
		   minutos_tramo_2 = 0;
		   minutos_tramo_3 = 0;
		   minutos_tramo_4 = 0;
		
		   tiempo_limite_rebasado  = (minutos_estacionamiento > tramo.limite_tramo_4);
		
		   if (!tiempo_limite_rebasado){
		      if (minutos_estacionamiento < tramo.limite_tramo_1)
		         minutos_tramo_1 = minutos_estacionamiento;
		      else{
		         minutos_tramo_1 = tramo.limite_tramo_1;
		
		         if (minutos_estacionamiento < tramo.limite_tramo_2)
		            minutos_tramo_2 = minutos_estacionamiento - tramo.limite_tramo_1;
		         else{
		            minutos_tramo_2 = tramo.limite_tramo_2 - tramo.limite_tramo_1;
		
		            if (minutos_estacionamiento < tramo.limite_tramo_3)
		               minutos_tramo_3 = minutos_estacionamiento - tramo.limite_tramo_2;
		            else{
		               minutos_tramo_3 = tramo.limite_tramo_3 - tramo.limite_tramo_2;
		               minutos_tramo_4 = minutos_estacionamiento - tramo.limite_tramo_3;
		            }
		         }
		      }
		   }
		
		   if (tiempo_limite_rebasado)
		      tarifa = tarifa_dia_completo;
		   else
		      tarifa = minutos_tramo_1 * tarifas.tarifa_tramo_1
		               +
		               minutos_tramo_2 * tarifas.tarifa_tramo_2
		               +
		               minutos_tramo_3 * tarifas.tarifa_tramo_3
		               +
		               minutos_tramo_4 * tarifas.tarifa_tramo_4;
		
		   return tarifa;
		}		
};

int main(){   
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
   
   int hora_inicial, minuto_inicial, segundo_inicial;
   int hora_final, minuto_final, segundo_final;
   int minutos_estacionamiento;

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
   
   total_recaudado_parking_1 = 0;
   total_recaudado_parking_2 = 0;
   
   Parking parking1(limite_tramo_1_parking_1, limite_tramo_2_parking_1, limite_tramo_3_parking_1, limite_tramo_4_parking_1,
					tarifa_tramo_1_parking_1, tarifa_tramo_2_parking_1, tarifa_tramo_3_parking_1, tarifa_tramo_4_parking_1,
					tarifa_dia_completo_parking_1);
	Parking parking2(limite_tramo_1_parking_2, limite_tramo_2_parking_2, limite_tramo_3_parking_2, limite_tramo_4_parking_2,
					tarifa_tramo_1_parking_2, tarifa_tramo_2_parking_2, tarifa_tramo_3_parking_2, tarifa_tramo_4_parking_2,
					tarifa_dia_completo_parking_2);
   
   cin >> hora_inicial;
   
   while (hora_inicial != TERMINADOR_ENTRADA_DATOS){     
      cin >> minuto_inicial;
      cin >> segundo_inicial;
   
      cin >> hora_final;
      cin >> minuto_final;
      cin >> segundo_final;
      
      minutos_estacionamiento = parking1.MinutosEntreInstantes(hora_inicial, minuto_inicial, segundo_inicial, hora_final, minuto_final, segundo_final);
      
      tarifa_parking_1 = parking1.Tarifa(minutos_estacionamiento);
                
      tarifa_parking_2 = parking2.Tarifa(minutos_estacionamiento);
                                   
      cout << "\nTarifa resultante con cada parking:\n" 
           << tarifa_parking_1 << "\n" << tarifa_parking_2 << "\n"; 
      
      total_recaudado_parking_1 = total_recaudado_parking_1 + tarifa_parking_1;
      total_recaudado_parking_2 = total_recaudado_parking_2 + tarifa_parking_2;
      
      cin >> hora_inicial;
   }
   
   cout << "\nTotal recaudado en cada parking:\n"
        << total_recaudado_parking_1 << "\n"
        << total_recaudado_parking_2 << "\n";
}
