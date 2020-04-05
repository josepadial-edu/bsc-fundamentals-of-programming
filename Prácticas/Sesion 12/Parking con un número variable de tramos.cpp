/*Nombre: José Antonio Padial Molina
	Curso: 1ºC
	Sesión 12 Ejercicio 15
	
	Descripción:
Recupere la solución del ejercicio 9 de la relación de problemas III (párking).
Re-escríbalo definiendo la clase TarifadorParking para calcular la tarifa.
La clase debe permitir cualquier número de tramos. Para ello, haga lo siguiente:
 Defina dos vectores como datos miembro de la clase. En uno almacenaremos los
límites de los tramos y en el otro la correspondiente tarifa.
 Defina el siguiente método:
void AniadeTramo(double limite_superior_tramo,
double tarifa_tramo)
Este método se llamará tantas veces como tramos tengamos.
 Defina el método GetTarifa para calcular la tarifa según el número de minutos
de un estacionamiento.
 Cree dos objetos de la clase TarifadorParking (uno para cada parking) y
modifique adecuadamente el programa principal para calcular las tarifas a partir
de los métodos de los objetos.
Mantenga la definición de la función MinutosEntreInstantes para calcular los
minutos que hay entre dos instantes.
*/

#include <iostream>
using namespace std;

class TarifadorParking{
	private:
		static const int MAX = 1000;
		double limites[MAX];
		double tarifas[MAX];
		int cont_limites = 0;
		int cont_tarifas = 0;
	public:
		TarifadorParking(){
			for(int i = 0; i < MAX; i++){
				limites[i] = 0;
				tarifas[i] = 0;
			}
		}
		
		void AniadeTramo(double limite_superior_tramo, double tarifa_tramo){
			limites[cont_limites] = limite_superior_tramo;
			cont_limites++;
			tarifas[cont_tarifas] = tarifa_tramo;
			cont_tarifas++;
		}
		
		int GetLimiteMayor(){
			double mayor = 0;
			for(int i = 0; i < cont_limites; i++){
				if(limites[i] > mayor){
					mayor = i;
				}
			}
			return mayor;
		}
		
		double GetTarifa(int minutos_estacionamiento, double dia_completo){
			bool tiempo_limite_rebasado;
			int indice_limite_mayor = GetLimiteMayor();
			double minutos_tramo[cont_limites];
			double tarifa = 0.0;
			int contador = 0;
			
			tiempo_limite_rebasado  = (minutos_estacionamiento > limites[indice_limite_mayor]);
			
			for(int i = 0; i < cont_limites; i++){
				minutos_tramo[i] = 0;
			}
			
			if(!tiempo_limite_rebasado){
				while(contador <= cont_limites){
					if(contador == 0){
						if(minutos_estacionamiento < limites[contador]){
							minutos_tramo[contador] = minutos_estacionamiento;
							contador = cont_limites + 1;
						}
						else{
							minutos_tramo[contador] = limites[contador];
							contador++;
						}
					}
					else{
						if(minutos_estacionamiento < limites[contador]){
							minutos_tramo[contador] = minutos_estacionamiento - limites[contador-1];
							contador = cont_limites + 1;
						}
						else{
							minutos_tramo[contador] = limites[contador] - limites[contador-1];
							contador++;
						}
					}
				}
			}
			
			if (tiempo_limite_rebasado)
		      tarifa = dia_completo;
		   else
		   	for(int i = 0; i < contador; i++)
		   		tarifa += minutos_tramo[i]*tarifas[i];
		   
		   return tarifa;
		}
};

int MinutosEntreInstantes (int hora_inicial, int minuto_inicial, int segundo_inicial,
                           int hora_final, int minuto_final, int segundo_final){
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60;
   int segundos_iniciales, segundos_finales, segundos_diferencia;
   
   segundos_iniciales = SEGUNDOS_POR_MINUTO * (hora_inicial * MINUTOS_POR_HORA   +
                                               minuto_inicial) +
                        segundo_inicial;

   segundos_finales   = SEGUNDOS_POR_MINUTO * (hora_final * MINUTOS_POR_HORA   +
                                               minuto_final) +
                        segundo_final;

   segundos_diferencia = segundos_finales - segundos_iniciales;

   return segundos_diferencia / SEGUNDOS_POR_MINUTO;
}

               


int main(){   
   const int TERMINADOR_ENTRADA_DATOS = -1;
   
   TarifadorParking parking1;
   TarifadorParking parking2;
   
   double limite = 0.0, tarifa = 0.0;
          
   double tarifa_dia_completo_parking_1, tarifa_dia_completo_parking_2;
   double tarifa_parking_1, tarifa_parking_2;
   double total_recaudado_parking_1, total_recaudado_parking_2;
   
   int hora_inicial, minuto_inicial, segundo_inicial;
   int hora_final, minuto_final, segundo_final;
   int minutos_estacionamiento;

   cout << "Parking.\n\n";
   
   cout << "Introduzca los limites con su tarifa del parking 1, usa -1 como terminador" << endl;
   cout << "No incluir día completo" << endl;
   
   cin >> limite;
   if(limite != -1){
   	cin >> tarifa;
   	parking1.AniadeTramo(limite, tarifa);
	}
	while(limite != -1){
		cin >> limite;
	   if(limite != -1){
	   	cin >> tarifa;
	   	parking1.AniadeTramo(limite, tarifa);
		}
	}
	
	cout << "Introduzca la tarifa de día completo del parking 1" << endl;
	cin >> tarifa_dia_completo_parking_1;
	
	cout << "Introduzca los limites con su tarifa del parking 2, usa -1 como terminador" << endl;
	cout << "No incluir día completo" << endl;
   
   cin >> limite;
   if(limite != -1){
   	cin >> tarifa;
   	parking2.AniadeTramo(limite, tarifa);
	}
	while(limite != -1){
		cin >> limite;
	   if(limite != -1){
	   	cin >> tarifa;
	   	parking2.AniadeTramo(limite, tarifa);
		}
	}
	
	cout << "Introduzca la tarifa de día completo del parking 2" << endl;
	cin >> tarifa_dia_completo_parking_2;
   
   total_recaudado_parking_1 = 0;
   total_recaudado_parking_2 = 0;
   
   cin >> hora_inicial;
   
   while (hora_inicial != TERMINADOR_ENTRADA_DATOS){     
      cin >> minuto_inicial;
      cin >> segundo_inicial;
   
      cin >> hora_final;
      cin >> minuto_final;
      cin >> segundo_final;
      
      minutos_estacionamiento = 
         MinutosEntreInstantes(hora_inicial, minuto_inicial, segundo_inicial,
                               hora_final, minuto_final, segundo_final);
      
      tarifa_parking_1 = parking1.GetTarifa(minutos_estacionamiento, tarifa_dia_completo_parking_1);
                
      tarifa_parking_2 = parking2.GetTarifa(minutos_estacionamiento, tarifa_dia_completo_parking_2);
                                   
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
