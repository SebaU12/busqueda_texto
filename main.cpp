#include <iostream> 

//Include files.h 
#include "./node.h"
#include "./pvector.h"
#include "vertex.h"
#include "graph.h"
//#include <ctime>


using namespace std; 


int main(){
  //cout << endl << "INICIANDO PROGRAMA" << endl;

  unsigned t0, t1, t2, t3;
  Graph graph; 
  Graph afd; 
  List<pvector*> *vector_substrings = new DoubleList<pvector*>(); 
  List<pvector*> *vector_test_substrings = new DoubleList<pvector*>(); 
  string getInputAlfabeto = ""; 
  string getInputSubString= ""; 
  string getInputTestSubString= ""; 


  int size_input = 0, size_substring = 0; 
  //cout << "Ingrese el tamaño que tendra el alfabeto: "; 
  cin >> getInputAlfabeto; 
  pvector *input_alfabeto = new pvector(getInputAlfabeto); 
  //cout << endl << "El input ingresado es el siguiente: "; 
  input_alfabeto->display(); 

  //cout << endl << "Ingresar la cantidad de substrings: "; 
  cin >> size_input; 
  size_substring = size_input; 
  for(int i = 0; i < size_input; i++){
    //cout << endl << "Ingresar el tamaño del substrings [" << i+1 << "]: "; 
    cin >> getInputSubString; 
    pvector *input_substring = new pvector(getInputSubString); 
    vector_substrings->push_back(input_substring); 
  }

 // cout << endl << "INICIO DE PROCESAR LOS STRINGS" << endl;
  //cout << endl; 
  for (int i = 0; i < vector_substrings->size(); i++){
    (*vector_substrings)[i+1]->display();
    cout << endl; 
  }
  //cout << endl << "TERMINO DE PROCESAR LOS STRINGS" << endl;

  //----------------------------------------------------------------------------------------------

  //cout << endl << "INICIO DE PROCESAR DE CREACION GRAFO " << endl;
  graph.generateGraphOfString(input_alfabeto, vector_substrings);

  //graph.display(false);

  //cout << endl << "Ingrese la cantidad de substrings para testear: " ;
  cin >> size_input; 
  for(int i = 0; i < size_input; i++){
   // cout << endl << "Ingresar el tamaño del substrings [" << i+1 << "]: "; 
    cin >> getInputTestSubString; 
    pvector *input_substring = new pvector(getInputTestSubString); 
    vector_test_substrings->push_back(input_substring); 
  }
  double time;

  //t0=clock();
  graph.display();
  t0=clock();
  graph.execBFS(vector_test_substrings);
  t1=clock();
  time = (double(t1-t0)/CLOCKS_PER_SEC);  
  cout << "Tiempo de ejecucion del BFS AFN: " << time << endl;
  cout << "Cantidad de cadenas: " << size_substring  << endl;
  cout << "Cantidad de subcadenas: " << size_input << endl;
  //afd = graph.generateAFD(input_alfabeto);
  //afd.display();
  //t1 = clock();
  //time = (double(t1-t0)/CLOCKS_PER_SEC);
  //cout << "Tiempo de ejecucion del recorrido substring con AFN: " << time << endl;

 // cout << endl; 
 // afd = graph.generateAFD(input_alfabeto);
 // cout << endl << endl << "ACABO EL AFD";
  //t2 =clock();
  //afd.execBFS(vector_test_substrings);
  //t3 = clock();
  //time = (double(t3-t2)/CLOCKS_PER_SEC);
  //cout << "Tiempo de ejecucion del recorrido substring con AFD: " << time << endl;

 // cout << endl << endl << "ACABO EL PROGRAMA";
  cout << '\n'; 
  return 0; 
}




