# Notas de Clase - Programación 
## Segundo Bimestre
* ### Archivos
  Se agrega la librería "fstream", se utiliza ifstream para leer datos y ofstream para sobreescribirlos.
  ~~~
  #include <iostream>
  #include <cstdlib>  //libreria para crear variables globales
  #include <fstream>

  using namespace std;

  string linea;
  string texto;

  int main()
  {
    ifstream archivo("test.txt");

    while(getline(archivo, linea)){  //leer todas las líneas al guardarse en una variable
      texto = texto+linea+"\n";
    }
    archivo.close();  //eliminar memoria residual de abrir
    cout << texto << endl;

    ofstream archivo2("test.txt");  //crea documento y sobreescribe
    archivo2 << texto <<"Nueva linea de Texto";

    system("pause"); //para seguir trabajando
  }
  ~~~
  #### ***Explicación de las funciones cin, cout, cerr.***
  ![Funciones](http://jbgarcia.webs.uvigo.es/asignaturas/TO/cursilloCpp/iostream.png "Salida y entrada")
  [Página para saber más](http://jbgarcia.webs.uvigo.es/asignaturas/TO/cursilloCpp/14_archivos.html)
* ### Estructuras
  Las estructuras de datos en C++ se pueden entender como un tipo de dato compuesto (no complejo). Las estructuras de datos permiten almacenar de manera ordenada una serie de valores dados en una misma variable. Las estructuras de datos más comunes son los arrays, que pueden ser unidimensionales (de una dimensión) también conocidos como vectores, o multidimensionales (de varias dimensiones) también conocidos como matrices, aunque hay otras un poco más diferentes como son struct, las enumeraciones y los punteros.

  Ejemplo de estructura
  ~~~
  #include <iostream>
 using namespace std;
 struct Mascota
 {
    string tipo;
    string nombre;
 };

 struct Alumno
 {
    int  id;
    int  edad;
    char nombre[20];
    Mascota mascotita;
 };

 // struct perro
 // {
 //     int  id;
 //     int  edad;
 //     char nombre[20];
 // }p1 ={};  lstPerros[3];

 // estructuras con estructuras
 // struct alumno dueno;
    int main()
    {   Alumno a0;
        Alumno a1 = {1,100,"pepe",{"perro","firulais"}};
        Alumno a2 = {2,20,"luis"};
        Alumno lst[]={a1, a2, {3,100,"luisa",{"gato","firulais"} }};
        a0.edad =10;
        a1.edad =10;
        a1.mascotita.nombre ="firulaiza";
        cout<<endl<<"[+]"
            <<endl<<" - "<<"id:"    <<a1.id
            <<endl<<" - "<<"edad:"  <<a1.edad
            <<endl<<" - "<<"nombre:"<<a1.nombre
            <<endl<<" - "<<"Macota.tipo:"<<a1.mascotita.tipo
            <<endl<<" - "<<"Macota.nombre:"<<a1.mascotita.nombre
            <<endl;
    // for (int i = 0; i < 3; i++)
    //     cout<<endl<<"[+]"
    //         <<endl<<" - "<<"id:"    <<lst[i].id
    //         <<endl<<" - "<<"edad:"  <<lst[i].edad
    //         <<endl<<" - "<<"nombre:"<<lst[i].nombre
    //         <<endl;
    for (auto &&a : lst)
        cout<<endl<<"[+]"
            <<endl<<" - "<<"id:"    <<a.id
            <<endl<<" - "<<"edad:"  <<a.edad
            <<endl<<" - "<<"nombre:"<<a.nombre
            <<endl<<" - "<<"Macota.tipo:"<<a.mascotita.tipo
            <<endl<<" - "<<"Macota.nombre:"<<a.mascotita.nombre
            <<endl;


    Alumno *persona = new Alumno[5];
 
    for (int i=0; i<5; i++)
    {
        cout << "Dime el nombre de la persona " << i << endl;
        cin >> persona[i].nombre;
    }
    cout << "La persona 3 es " << persona[2].nombre << endl;
 
    return 0;
 }
  ~~~
  Output:
  ~~~
  [+]
 - id:1
 - edad:10
 - nombre:pepe
 - Macota.tipo:perro
 - Macota.nombre:firulaiza

 [+]
 - id:1
 - edad:100
 - nombre:pepe
 - Macota.tipo:perro
 - Macota.nombre:firulais

 [+]
 - id:2
 - edad:20
 - nombre:luis
 - Macota.tipo:
 - Macota.nombre:

 [+]
 - id:3
 - edad:100
 - nombre:luisa
 - Macota.tipo:gato
 - Macota.nombre:firulais
  ~~~

* ### Punteros
  Se llaman así a los tipos de datos que contienen la direccion de la variable en la memoria &nombre_de_la_variable
  ~~~
  #include <iostream>

  using namespace std;
  int main()
  {
    int age = 19;
    double gpa = 2.7;
    string name = "Mike";

    cout << &age << endl;
    cout << &gpa << endl;
    cout << &name << endl;
    return 0;
  }
  ~~~
  Output:
  ~~~
  0xe2773ff628
  0xe2773ff620
  0xe2773ff600
  ~~~
  >Estas son las direcciones en la memoria de mis variables.

  También se puede usar la dirección como un dato e introducirlo en una variable
  ~~~
  #include <iostream>

  using namespace std;
  int main()
  {
    int age = 19;
    int *pAge = &age;
    double gpa = 2.7;
    double *pGpa = &gpa;
    string name = "Mike";
    string *pName = &name;

    cout << pAge << endl;
    cout << pGpa << endl;
    cout << pName << endl;
    return 0;
  }
  ~~~
  Output:
  ~~~
  0xe2773ff628
  0xe2773ff620
  0xe2773ff600
  ~~~

  Y juguemos con los punteros usando el valor al que apuntan y obteniendo el valor que contienen las variables.

  ~~~
  #include <iostream>

  using namespace std;
  int main()
  {
    int age = 19;
    int *pAge = &age;
    double gpa = 2.7;
    double *pGpa = &gpa;
    string name = "Mike";
    string *pName = &name;

    cout << *pAge << endl;
    cout << *pGpa << endl;
    cout << *pName << endl;
    return 0;
  }
  ~~~
  Output:
  ~~~
  19
  2.7
  Mike
  ~~~
  ---
  Ejemplo en clase:
  ~~~
  #include <iostream>
  using namespace std;

  int * a;
  int sum(int* a, int n) {
    if (n == 0) {
        return 0;
    }
    return sum(a, n - 1) + a[n - 1];
    }

  int main() {
    int n = 0;
    int * a;

    cout<<"Ingresa cantidad de elementos:" <<endl;
    cin >> n;
    if( n <= 0)
        return 0;
    a = new int[n]; //Reserva dinamica de memoria para n enteros

    cout<<"Ingresa elementos:" <<endl;
    for( int i = 0; i < n; i++)
        cin >> a[i]; //Obtienes cada entero
    
    cout<<"La suma es:" <<endl;
    cout << sum(a, n) << endl;
    delete[] a; //Elininas la memoria reservada

    return 0;
  }
 ~~~
  Matriz usándolos:
 ~~~
 #include <iostream>
 using namespace std;

 void showVector(int v[], int c){ //para vectores
    for (int i = 0; i < c; i++)
        cout<<v[i]<<"\t"; 
    cout<<endl;
 } 
 void showPtrVector(int *pv, int c){ //para vectores usando puntero
    for (int i = 0; i < c; i++)
        cout<<pv[i]<<"\t"; 
    cout<<endl;
 }
 void showMatriz(int m[][3], int f, int c){ //para matriz
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout<< m[i][j] <<"\t"; 
        cout<< endl;
    }
 } 
 void showMatrizComoVector(int mv[], int f, int c){ //para matriz
    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < c; j++)
            cout<< mv[i*c+j] <<"\t";    // m[i][j]
        cout<< endl;
    }
 } 
 void showPtrMatriz(int *p, int f,int c)
 {
   for (int i = 0; i < f; i++)
   {
        for (int j = 0; j < c; j++)
            cout<< *(p+i * c+j) <<"\t";   // m[i][j]
        cout<< endl;
   }
 }
 void showVectorPtrMatriz(int *vp[], int f,int c)
 {
   for (int i = 0; i < f; i++)
   {
        for (int j = 0; j < c; j++)
            cout<< vp[i][j] <<"\t";   // m[i][j]
        cout<< endl;
   }
 }
 void showPtrDobleMatriz(int **pd, int f,int c)
 {
   for (int i = 0; i < f; i++)
   {
        for (int j = 0; j < c; j++)
            cout<< pd[i][j] <<"\t";   
        cout<< endl;
   }
 } 

 /// Mas opciones para matrices
 void getMatriz(int **matriz)
 {
    int fil = 3; //(sizeof(matriz)/sizeof(matriz[0]));
    int col = 2; //(sizeof(matriz[0])/sizeof(matriz[0][0]));
    
    cout<<"----"<<endl;
    cout<<(sizeof(**matriz))<<endl;
    cout<<(sizeof(&matriz)/sizeof(&matriz[0]))<<endl;
    cout<<(sizeof(*matriz[0])/sizeof(matriz[0][0]))<<endl;
    cout<<"----"<<endl;

    for (int i=0; i<fil; i++)
    {
        for(int j=0;j<col; j++)
            cout<<matriz[i][j]<<" ";
        cout <<endl;
    }
 }

 void setMatriz(int **&matriz, int fil, int col)
 {
    for (int i=0; i<fil; i++)
        for(int j=0;j<col; j++)
                matriz[i][j]=0;
 }
 void showArrayVector(){
    int ai[]={1,3,5,7,9};
    int *pi;
    pi = ai;
    *(pi+0) = 10;   // cambiar valor
    showPtrVector(pi,5);
 }

 int main(void)
 {   //Todo lo que debes saber de las matrices y punteros
    cout<<endl<<endl<<"Iniciando con vectores y punteros"<<endl;
    showArrayVector();

    const int f=4, c=3;
    int m[f][c] = { {1,2,3},    {4,5,6},   {7,8,9},    {10,11,12}};

    cout<<endl<<endl<<"0. showVector(int a[], int c)"<<endl;
    showVector(m[0] , c) ;      // m[1] : 0 es fila que deseas mostrar
    showVector(m[1] , c) ;      // m[1] : 1 es fila que deseas mostrar

    cout<<endl<<endl<<"1. showMatriz: (int m[][3], int f, int c)"<<endl;
    showMatriz(m ,f, c) ;
    
    cout<<endl<<endl<<"2. showMatrizComoVector: (int mv[], int f, int c)"<<endl;
    showMatrizComoVector(&m[0][0] ,f, c);
    
    cout<<endl<<endl<<"3. showPtrMatriz: (int *p, int f,int c)"<<endl;
    showPtrMatriz(&m[0][0] ,f, c);

    /// array de punteros a las ref de nemoria de las filas de la matriz m 
    int *p[f]; 
    for (int i = 0; i < f; i++)
        p[i] = &m[i][0];

    cout<<endl<<endl<<"4. showVectorPtrMatriz: (int *vp[], int f,int c)"<<endl;
    showVectorPtrMatriz(p,f,c);

    //puntero doble
    int **pd = p;
    cout<<endl<<endl<<"5. showPtrDobleMatriz: (int **pd, int f,int c)"<<endl;
    showPtrDobleMatriz(pd,f,c);

    cout<<endl<<endl<<"6. matriz -> showPtrVector: (int *pv, int c)"<<endl;
    for (int i = 0; i < f; i++) {
        showPtrVector(*pd++, c);

        //int *e = *ptr++;
        //cout << *(e + 0) << endl;     //cout << e[0] << endl;
        //cout << *(e + 1) << endl;     //cout << e[1] << endl;
        //cout << *(e + 2) << endl;     //cout << e[2] << endl;
    }
    
    cout<<endl<<endl<<"7. matriz -> showVector(int a[], int c)"<<endl;
    for (int i = 0; i < f; i++)
        showVector(m[i] , c) ; 

    /* OJO-NOTA:
    int (*arreglo) [n]; //Un puntero a un vector de n enteros.
    int *arreglo[n];    //Un vector de n punteros a enteros
    */

    return 0;
 }
 ~~~
* ### Autómata Finito Determinista (AFD)
 Un autómata finito determinista es una quíntupla que denotaremos de manera genérica por M=(Q,Σ,q0,δ,F), donde:
  - Q es un conjunto finito cuyos elementos llamaremos estados. 
  - Σ es un alfabeto que llamamos alfabeto de entrada. 
  - q0∈Q es un estado señalado que llamamos estado inicial. 
  - F es un subconjunto de Q no vacío, cuyos elementos llamamos estados finales. 
  - δ es una aplicación de Q×Σ→Q , que llamamos función de transición. 
 
 Aplicación:
 ~~~
 #include <iostream>
 using namespace std;

 int const TKErr=-1;         // Token de Error
 int const TKFin=-2;         // Token de Fin
 string const ALFA = "abc \\t";

 int **newMatriz(int f, int c)
 {    
    int **m=NULL;
    m = new int*[f];
    for (int i = 0; i < f; i++)
        m[i] = new int[c];

    return m;
 }

 void showMatriz(int **pd, int f,int c)
 {
    for (int i = 0; i < f; i++)
    {
            for (int j = 0; j < c; j++)
                cout<< pd[i][j] <<"\t";   
            cout<< endl;
    }
 }

 int getIndexAlfabeto(char c)
 {
    int index = ALFA.find(c);
    if(index < ALFA.length())
        return index;
    return TKErr;    
 }

 int main(void) 
 {
    int **mt=NULL;         // mt =  matriz de transicion
    int Q=3, L=4;
    mt = newMatriz(Q,L);
    
 /*  Automata finito determinista

    [q0]      --- b  --->   [q2] (c)
     |-- a -->  [q1] -- b -->|
                 (a)

     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ 
     Q     |  { a           b           c           ' '     \t  }
     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ 
     0     |    1           2           r           er
     1     |    1           2           r           er
     2     |    er          er          q2          ok1
     _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ 

 */
    //matriz de transicion [Q][L]
    mt[0][0]=1;         mt[0][1]=2;         mt[0][2]= TKErr;     mt[0][3]= TKErr;
    mt[1][0]=1;         mt[1][1]=2;         mt[1][2]= TKErr;     mt[1][3]= TKErr;
    mt[2][0]=TKErr;     mt[2][1]=TKErr;     mt[2][2]= 2;         mt[2][3]= -1000; 

    string palabra = "aaabcc ";
    int q=0, l=0;
    for (auto &&c : palabra )
    {
        l = getIndexAlfabeto(c);
        q = mt[q][l];
        cout<< c << " " << q <<","<< l <<endl;
        if(q == TKErr || q > Q)
            cout<<" -> Error";
        if(q == -1000)
            cout<<" -> OK";
       // 
    }
     
    
    // for (int i = 0; i <Q; i++)
    //     for (int j = 0; j < L; j++)
    //         mt[i][j] =  'a'; //rand() % 10;  // genera randomicos hasta 10
    
    showMatriz(mt,Q,L);
 }
 ~~~
* ### Lista
  En C++, una lista es una estructura de datos que permite almacenar y acceder a elementos de manera secuencial. A diferencia de los arrays, las listas permiten agregar y eliminar elementos en cualquier posición sin tener que mover los elementos restantes para ajustar el tamaño de la lista.

  La implementación más común de una lista en C++ es la lista doblemente enlazada, donde cada elemento (nodo) de la lista contiene un valor y dos punteros, uno que apunta al nodo anterior y otro que apunta al nodo siguiente. De esta manera, podemos recorrer la lista en ambas direcciones.

  La clase std::list de la biblioteca estándar de C++ implementa una lista doblemente enlazada. Veamos un ejemplo de cómo crear y utilizar una lista en C++:
  ~~~
  #include <iostream>
  #include <list>

  int main() {
    // Crear una lista de números enteros
    std::list<int> numeros = {2, 4, 6, 8, 10};
    
    // Agregar un elemento al final de la lista
    numeros.push_back(12);
    
    // Eliminar un elemento de la lista
    numeros.remove(6);
    
    // Mostrar todos los elementos de la lista
    std::cout << "Lista de números:" << std::endl;
    for (auto& numero : numeros) {
        std::cout << numero << " ";
    }
    std::cout << std::endl;
    
    return 0;
    }
  ~~~
  En este ejemplo, creamos una lista de números enteros utilizando la clase std::list. Luego, utilizamos las funciones push_back() y remove() para agregar un elemento al final de la lista y eliminar un elemento de la lista, respectivamente. Finalmente, recorremos la lista utilizando un bucle for para mostrar todos los elementos de la lista.

* ### Cola
  una cola es una estructura de datos que permite almacenar y acceder a elementos de manera secuencial siguiendo una política FIFO (First In, First Out), es decir, el primer elemento que entra en la cola es el primero que sale.

  La implementación más común de una cola en C++ es la cola de la biblioteca estándar, implementada mediante un contenedor deque (double-ended queue). La clase std::queue de la biblioteca estándar de C++ implementa una cola.

  Ejemplo de cómo crear y utilizar una cola en C++:
  ~~~
  #include <iostream>
  #include <queue>

  int main() {
    // Crear una cola de números enteros
    std::queue<int> numeros;
    
    // Agregar elementos a la cola
    numeros.push(2);
    numeros.push(4);
    numeros.push(6);
    numeros.push(8);
    
    // Mostrar el primer elemento de la cola
    std::cout << "El primer elemento de la cola es: " << numeros.front() << std::endl;
    
    // Eliminar el primer elemento de la cola
    numeros.pop();
    
    // Mostrar todos los elementos de la cola
    std::cout << "Elementos de la cola:" << std::endl;
    while (!numeros.empty()) {
        std::cout << numeros.front() << " ";
        numeros.pop();
    }
    std::cout << std::endl;
    
    return 0;
 }

  ~~~
  ---
  Creamos una cola de números enteros utilizando la clase std::queue. Luego, utilizamos la función push() para agregar elementos a la cola y la función front() para obtener el primer elemento de la cola. Utilizamos la función pop() para eliminar el primer elemento de la cola y recorremos la cola utilizando un bucle while y la función empty() para mostrar todos los elementos de la cola.

* ### Pila
  Es una estructura de datos que permite almacenar y acceder a elementos de manera secuencial siguiendo una política LIFO (Last In, First Out), es decir, el último elemento que entra en la pila es el primero que sale.

  La implementación más común de una pila en C++ es la pila de la biblioteca estándar, implementada mediante un contenedor deque (double-ended queue). La clase std::stack de la biblioteca estándar de C++ implementa una pila.

  ~~~
  #include <iostream>
  #include <stack>

  int main() {
    // Crear una pila de números enteros
    std::stack<int> numeros;
    
    // Agregar elementos a la pila
    numeros.push(2);
    numeros.push(4);
    numeros.push(6);
    numeros.push(8);
    
    // Mostrar el elemento en la cima de la pila
    std::cout << "El elemento en la cima de la pila es: " << numeros.top() << std::endl;
    
    // Eliminar el elemento en la cima de la pila
    numeros.pop();
    
    // Mostrar todos los elementos de la pila
    std::cout << "Elementos de la pila:" << std::endl;
    while (!numeros.empty()) {
        std::cout << numeros.top() << " ";
        numeros.pop();
    }
    std::cout << std::endl;
    
    return 0;
 }
 ~~~
  >Explicación:
  creamos una pila de números enteros utilizando la clase std::stack. Luego, utilizamos la función push() para agregar elementos a la pila y la función top() para obtener el elemento en la cima de la pila. Utilizamos la función pop() para eliminar el elemento en la cima de la pila y recorremos la pila utilizando un bucle while y la función empty() para mostrar todos los elementos de la pila.

* ### Clases y Objetos
  POO son las siglas de Programación Orientada a Objetos.

  La programación procedimental consiste en escribir procedimientos o funciones que realicen operaciones sobre los datos, mientras que la programación orientada a objetos consiste en crear objetos que contengan tanto datos como funciones.

  La programación orientada a objetos tiene varias ventajas sobre la programación procedimental:

  La programación orientada a objetos es más rápida y fácil de ejecutar.  
  La programación orientada a objetos proporciona una estructura clara a los programas.  
  La programación orientada a objetos ayuda a mantener el código C++ DRY "Don't Repeat Yourself" (no te repitas), y hace que el código sea más fácil de mantener, modificar y depurar.  
  La programación orientada a objetos permite crear aplicaciones totalmente reutilizables con menos código y menos tiempo de desarrollo.   

  ¿Y las clases..?
  
  Una clase es una plantilla para objetos, y un objeto es una instancia de una clase.
  Cuando se crean los objetos individuales, se heredan todas las variables y funciones de la clase.

  ~~~
  #include <iostream>

  using namespace std;
  class Book {
    public:
        string title;
        string author;
        int pages;
  };
  int main()
  {
    Book book1;
    book1.title = "Harry Potter" << endl;
    book1.author = "JK Rowling" << endl;
    book1.pages = 500 << endl;

    cout << book1.author;
    cout << book1.pages;
    cout << book1.title;

    Book book2;
    book2.title = "Emma";
    book2.author = "Jane Austen";
    book2.pages = 400;

    return 0;
  }
  ~~~
  Output:
  ~~~
  JK Rowling
  500
  Harry Potter
  ~~~
  >Se podría decir que la clase es la plantilla para los datos, mientras que el objeto contiene valores que entrarán en esa plantilla
* ### Constructors Functions

  Funciona así:
  ~~~
  #include <iostream>

  using namespace std;
  class Book {
    public:
        string title;
        string author;
        int pages;

        Book(string aTitle, string aAuthor, int aPages){ 
            title = aTitle;
            author = aAuthor;
            pages = aPages;

        }


  };
  int main()
  {
    Book book1("Harry Potter", "JK Rowling", 500);
    Book book2("Emma", "Jane Austen", 400);
    
    cout << book1.title;

     return 0;
  }
  ~~~
  Output:
  ~~~
  Harry Potter
  ~~~
* ### Objects Functions
  ~~~
  #include <iostream>

  using namespace std;
  class Book {
    public:
        string title;
        string author;
        int pages;

        Book(string aTitle, string aAuthor, int aPages){
            title = aTitle;
            author = aAuthor;
            pages = aPages;

        }
        Book(){
            title = "no title";
            author = "no author";
            pages = 0;
        }
        bool easytoread(){
            if(pages < 600){
                return true;
            }
            return false;
        }
  };

  int main()
  {
    Book book1("Harry Potter", "JK Rowling", 500);
    Book book2("Emma", "Jane Austen", 400);
    Book book3;
    cout << book1.easytoread() << endl;
    cout << book2.easytoread();

     return 0;
  }
  ~~~
  Output:
  ~~~
  1
  1
  ~~~
  Porque la condición es cierta.
* ### Getter and Setters
  Permitir que tu código sea modificado o no usando private en la Clase y controlar el acceso a elementos individuales
  ~~~
  #include <iostream>
  using namespace std;

  class Movie {
    private:
        string rating;
    public:
        string title;
        string director;

        Movie(string aTitle, string aDirector, string aRating){
            title = aTitle;
            director = aDirector;
            setRating(aRating);
        }

        void setRating(string aRating){
            if(aRating == "G" || aRating == "PG" || aRating == "PG-13" || aRating == "R")
               rating = aRating;
            else {
                rating = "NR";
            }
        }

        string getRating(){
            return rating;
        }
  };

  int main()
  {
    Movie avengers("The Avengers", "Joss Whedon", "PG-13");
    avengers.setRating("Dog");
    cout << avengers.getRating();
  }
  ~~~
  Output:
  ~~~
  NR
  ~~~
* ### Inheritance -Herencia
  Obtener datos públicos de otra clase, aumentar el numero de funcionalidades o sobreescribir funciones.  

  *SuperClass* Aquella de la que se hereda  

  *SubClass* La que recibe los datos
  ~~~
  #include <iostream>
  using namespace std;

  class Chef{
  public:
    void makeChicken(){
        cout << "The chef makes yummy chicken\n";
    }
     void makeSalad(){
        cout << "The chef makes salad\n";
    }
     void makeSpecialDish(){
        cout << "The chef makes bbq ribs\n";
    }
  };

  class italianChef : public Chef{
    public:
    void makePasta(){
        cout << "The chef makes pasta\n";
    }
    void makeSpecialDish(){
        cout << "The chef makes chicken parm\n";
    }
  };

  int main()
  {
    Chef chef;
    chef.makeSpecialDish();

    italianChef italianchef;
    italianchef.makeSpecialDish();

    return 0;
  }

  ~~~
  Output
  ~~~
  The chef makes bbq ribs
  The chef makes chicken parm
  ~~~
* ### Arboles Binarios
  Un árbol binario es una estructura de datos en la que cada nodo puede tener hasta dos nodos hijos, llamados hijo izquierdo y hijo derecho. Cada nodo en un árbol binario tiene un valor asociado y los nodos se organizan de tal manera que cada nodo puede tener un máximo de dos hijos.

  En C++, podemos implementar un árbol binario utilizando una clase que tenga punteros a los nodos hijo izquierdo y derecho, así como una función de inserción para agregar nuevos nodos al árbol.

  Veamos un ejemplo de cómo crear y utilizar un árbol binario en nuestro lenguaje:
  ~~~
  #include <iostream>

  class Nodo {
   public:
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    
    Nodo(int valor) {
        this->valor = valor;
        izquierdo = nullptr;
        derecho = nullptr;
    }
    
    ~Nodo() {
        delete izquierdo;
        delete derecho;
    }
  };

  class ArbolBinario {
   private:
    Nodo* raiz;

   public:
    ArbolBinario() {
        raiz = nullptr;
    }
    
    ~ArbolBinario() {
        delete raiz;
    }
    
    void insertar(int valor) {
        if (raiz == nullptr) {
            raiz = new Nodo(valor);
        } else {
            Nodo* actual = raiz;
            while (true) {
                if (valor < actual->valor) {
                    if (actual->izquierdo == nullptr) {
                        actual->izquierdo = new Nodo(valor);
                        break;
                    } else {
                        actual = actual->izquierdo;
                    }
                } else {
                    if (actual->derecho == nullptr) {
                        actual->derecho = new Nodo(valor);
                        break;
                    } else {
                        actual = actual->derecho;
                    }
                }
            }
        }
    }
    
    void mostrar() {
        mostrar(raiz);
    }
    
   private:
    void mostrar(Nodo* nodo) {
        if (nodo != nullptr) {
            mostrar(nodo->izquierdo);
            std::cout << nodo->valor << " ";
            mostrar(nodo->derecho);
        }
    }
 };

 int main() {
    ArbolBinario arbol;
    arbol.insertar(8);
    arbol.insertar(3);
    arbol.insertar(10);
    arbol.insertar(1);
    arbol.insertar(6);
    arbol.insertar(14);
    arbol.insertar(4);
    arbol.insertar(7);
    arbol.insertar(13);
    
    arbol.mostrar();
    std::cout << std::endl;
    
    return 0;
 }
 ~~~
 Aquí: 
 La clase Nodo que representa un nodo en el árbol binario y una clase ArbolBinario que representa el árbol binario en sí. La clase Nodo tiene un valor asociado y punteros a los nodos hijo izquierdo y derecho.

 La clase ArbolBinario tiene un puntero a la raíz del árbol y funciones para insertar un nuevo nodo en el árbol y mostrar el árbol en orden. En la función de inserción, se comprueba si la raíz del árbol está vacía y, si es así, se crea un nuevo nodo y se establece como la raíz del árbol. Si la raíz del árbol no está vacía, se busca la ubicación adecuada para el nuevo nodo.

* ### Hash Table
  Una Hash Table o Tabla de Hash es una estructura de datos que se utiliza para almacenar y recuperar datos en función de una clave (o key) asociada. La idea básica detrás de una tabla hash es que se puede acceder a los elementos almacenados en ella de manera muy rápida, en promedio, en un tiempo constante O(1), independientemente del tamaño de la tabla o el número de elementos que contenga.

  La implementación de una tabla hash implica utilizar una función hash que toma la clave de un elemento y lo transforma en un índice en el que se almacenará ese elemento dentro de la tabla. Idealmente, esta función hash debe distribuir uniformemente las claves en la tabla, minimizando las colisiones, que se producen cuando dos claves diferentes se asignan al mismo índice.

  En C++, podemos implementar una tabla hash utilizando la clase unordered_map de la biblioteca estándar. Esta clase proporciona una implementación de una tabla hash utilizando el método de encadenamiento, que es una técnica para resolver colisiones mediante la creación de listas enlazadas de elementos que tienen la misma clave.
  ~~~
  #include <iostream>
  #include <unordered_map>

  int main() {
    std::unordered_map<std::string, int> tabla;
    
    tabla["uno"] = 1;
    tabla["dos"] = 2;
    tabla["tres"] = 3;
    
    std::cout << "El valor de 'dos' es: " << tabla["dos"] << std::endl;
    
    if (tabla.find("cuatro") == tabla.end()) {
        std::cout << "La clave 'cuatro' no está en la tabla" << std::endl;
    }
    
    return 0;
 }
  ~~~
  En este ejemplo, creamos una tabla hash utilizando la clase unordered_map, que se define como una plantilla con dos argumentos: el tipo de la clave y el tipo del valor que se almacenará. En este caso, estamos utilizando una clave de tipo std::string y un valor de tipo int.

  Luego, agregamos tres elementos a la tabla utilizando el operador de índice [], que se encarga de buscar la clave dada y devolver el valor asociado. En este caso, estamos asignando los valores 1, 2 y 3 a las claves "uno", "dos" y "tres", respectivamente.

  A continuación, accedemos al valor asociado a la clave "dos" utilizando el operador de índice y lo imprimimos por pantalla.

  Por último, verificamos si la clave "cuatro" está en la tabla utilizando la función find(), que devuelve un iterador al elemento correspondiente si se encuentra en la tabla, o un iterador al final de la tabla si no se encuentra. En este caso, como la clave "cuatro" no está en la tabla, la función find() devuelve un iterador al final de la tabla y lo comparamos con la función end() de la tabla para determinar si la clave está presente o no.

  
* ### Recursos
  [Mike Dane](https://www.mikedane.com/)
  [Giraffe Academy](https://youtu.be/vLnPwxZdW4Y)


