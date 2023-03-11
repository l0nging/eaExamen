# **Hash Table**

Una hash table es una estructura de datos que implementa una matriz asociativa (un diccionario). 

En una matriz asociativa, los datos se almacenan como una colección de pares clave-valor. 
La posición de los datos dentro de la matriz se determina aplicando un algoritmo hash a la clave, un proceso llamado hashing. 
El algoritmo se denomina función hash.

Estas estructuras permiten realizar búsquedas muy eficientes. En el mejor de los casos, los datos pueden recuperarse de una en poco tiempo, por lo que es preferible usarlas siempre que sea necesario realizar búsquedas de alto rendimiento. Mantener (añadir, actualizar y borrar) datos, una hash table es muy eficiente.

* ## _Cómo implementar una_

  Para implementar una hash table, se debe utilizar una matriz porque tienes que poder acceder directamente a cada posición de la matriz. Esto se hace especificando el índice de la posición (dentro de la matriz).

  Las posiciones dentro de una matriz a veces se denominan buckets; cada bucket se utiliza para almacenar datos. Puede tratarse de un único dato o de un objeto más complejo, como un registro. La clave debe almacenarse como parte de los datos o junto a ellos.

  El tamaño de la matriz debe planificarse cuidadosamente. Debe ser lo suficientemente grande como para almacenar todos los datos, pero no tanto como para desperdiciar espacio. Sin embargo, una hash table eficaz siempre debe tener algo de espacio libre.

  El factor de carga de una puede definirse como:

  factor de carga = n/k
  
  donde k es el número de buckets (posiciones) de la matriz y n es el número de buckets ocupados. Lo óptimo es mantener el factor de carga en torno a 0,75.

* ## _Función Hash_
  Una función hash es un algoritmo que convierte una clave hash en un valor. 

  Una buena función hash es esencial para el funcionamiento eficaz de la tabla.

  Los principales requisitos de una función hash son que:

   - Producir siempre el mismo valor hash para la misma clave.

   - Proporcionar una distribución uniforme de los valores hash. Esto significa que cada valor tiene la misma probabilidad de ser generado.

   - Minimizar el agrupamiento, que se produce cuando muchas claves diferentes producen el mismo valor hash. Cuando dos o más claves diferentes producen el mismo valor hash, decimos que se ha producido una "colisión".

   - Ser muy rápida de calcular.

  ***Una función hash sencilla***

   Veamos una función hash sencilla. Supondremos que las claves son números de 5 dígitos y que tenemos una tabla hash con 97 buckets.

   La función hash podría simplemente hacer uso del operador módulo (MOD) para producir los valores. La división asegurará que cada valor caiga dentro del rango válido de índices para el array, porque el resto nunca puede ser mayor que 96.
  
  ~~~
   FUNCION entero_hash(clave_hash, numero_de_espacios)
      // Genera el valor utilizando el operador modulo
      valor = clave_hash MOD numero_de_espacios

      // Retorna el valor 
      RETURN valor
   FINFUNCION
  ~~~

  He aquí el resultado de aplicar el algoritmo a una muestra de posibles claves.

  |  Clave | Función Hashing  | valor  |   
  |---|---|---|
  |  12345 | 12345 MOD 97  | 26  |   
  | 67564  | 67564 MOD 97  | 52  |   
  | 34237  | 34237 MOD 97 | 93  | 
  | 23423  | 23423 MOD 97  | 46  |   
  | 00332  | 00332 MOD 97 | 41  |  
     	   
  Esto significa que los datos asociados a la clave 23423, se almacenarían en la posición 46 de la matriz.
  Para recuperar los datos de la tabla hash, la clave se "hashearía" de nuevo utilizando el mismo algoritmo. 
  
  Esto proporcionará el índice donde se encontrarán los datos asociados.

  ***Hashing de datos de caracteres***
  
  No todos los valores de las claves son simples números enteros, por lo que la función hash tendrá que hacer más procesamientos. Consideremos una clave alfanumérica compuesta por cuatro letras o números cualesquiera. Un código de ejemplo sería A5RD.

  Para hacer el hash del código, los caracteres podrían convertirse a sus códigos numéricos ASCII:

  |  Caracter | ASCII  |  
  |---|--|
  | A| 65 |
  | 5| 53|
  | D| 82|
  | R| 68|

  A continuación, puedes sumar los valores para obtener un total: 65,65 + 53 + 82 + 68 = 268

  Por último, aplica la función módulo: 268 MOD 97 = 74
  Los datos asociados al código A5RD se almacenarán en la posición 74 de la tabla.

  >La función ASC convierte un único carácter en un código ASCII. Por ejemplo, ASC("A") devolvería 65.

  ~~~
  FUNCION cadena(clave, número_de_espacios)
    // Inicializar el total
    total = 0

    // Repetir para cada carácter de la clave
    FOR i = 0 TO LEN(clave) - 1
       codigo_ascii = ASC(clave[i])
       total = total + codigo_ascii
   SIGUIENTE i

    // Genera el valor utilizando el operador módulo
    valor = suma MOD número_de_espacios

    // Devuelve el valor 
    RETURN valor
  ENDFUNCTION
  ~~~
  
* ## _Ingresando datos_
  Para insertar datos, debes utilizar la función hash para generar el índice de la posición en el array que se utilizará para almacenar los datos. Recuerda que la clave debe almacenarse como parte de los datos o junto a ellos.

  Ya has visto un ejemplo de cómo una función hash podría convertir la clave A5RD en el valor hash 74; los datos identificados por esta clave se almacenarán en la posición 74 de la tabla hash.

  | Clave | Funcion | Valor |
  |--|--|--|
  | A5RD | Aplicando la función hash | 74 |

  ![Figura 1](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_a5rd.png)
  
  Si tienes una función hash perfecta, es así de fácil. Sin embargo, como descubrirás cuando leas sobre colisiones, las funciones hash rara vez son perfectas.
  
* ## _Obtención de datos_
  Para recuperar un valor de una tabla hash, se aplica la función hash a la clave para generar el índice de la posición dentro de la matriz.

  La clave R2YJ genera el valor hash 4; ahí se encontrarán los datos asociados a la clave R2YJ.
  | Clave | Funcion | Valor |
  |--|--|--|
  | R2YJ | Aplicando la función hash | 4 |

  ![Figura 2](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_r2yj.png)

  Los datos pueden recuperarse en una sola operación. No es necesario utilizar una búsqueda lineal o binaria, se puede ir directamente a la posición correcta porque un array permite el acceso directo por índice.
  
  **Buscando un término que no existe**

  ¿Y si buscamos un término que no existe? Veamos un ejemplo:
  | Clave | Funcion | Valor |
  |--|--|--|
  | J6TR | Aplicando la función hash | 3 |

  Si no hay ningún dato en la posición 3, sabes que no existe; no tienes que buscar en toda la matriz para demostrarlo.


  ![Figura_3](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_j6tr.png)
  

* ## _Colisiones_
  Se produce una colisión cuando la función hash produce el mismo valor hash para dos o más claves.

  Por ejemplo, la clave B7MF produce el mismo valor(74) que la clave A5RD.

  ![Figura_4](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_a5rd_b7mf.png)

  Las colisiones son un verdadero problema cuando se utiliza una tabla hash porque no se pueden almacenar dos conjuntos de datos en la misma ubicación. No importa lo buena que sea tu función hash, es probable que tengas que lidiar con colisiones.

  Dos métodos para tratar las colisiones son el sondeo lineal y el encadenamiento.

  **Sondeo lineal (también llamado direccionamiento abierto)**

  Cuando una clave crea un valor que hace referencia a una posición que ya está ocupada, debe colocar los datos en la siguiente posición libre de la tabla. Puede sondear secuencialmente o utilizar un intervalo (por ejemplo, comprobar cada 3 espacios) hasta que se encuentre uno vacío.

  En el siguiente diagrama, los datos con la clave A5RD ya se han insertado en la posición 74. Cuando se desea insertar B7MF, se produce el mismo valor hash: 74.

  ![Figura_5](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_collision_linear.png)

  Como la posición 74 ya está ocupada, los datos con la clave B7MF se colocarán en el siguiente lugar libre de la tabla. El intervalo es 1, por lo que se examinará el siguiente espacio (índice 75). Éste ya está ocupado, por lo que se examina el siguiente (índice 76). Está vacío, por lo que los datos se colocarán en esta ubicación.
 
  Si hay muchas colisiones, la tabla hash puede acabar muy desordenada. En el diagrama de abajo, observe cómo G4QB, cuyo hash es 76, ha sido colocado en la posición 77. Esto se debe a que la posición 76 ha sido ocupada por los datos de B7MF como resultado de la colisión anterior.

  ![Figura_6](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_g4qb.png)

  **Recuperación de datos (sondeo lineal)**

  Cuando se ha producido una colisión, los datos no estarán en el lugar correcto. El proceso para recuperar datos en la que las colisiones se han resuelto mediante sondeo lineal es el siguiente:

  - Hashear la clave para generar el valor del índice
  - Examinar la posición indexada para ver si la clave (que se almacena junto con los datos) coincide con la clave de los datos que se buscan
  si no hay coincidencia, comprobar cada posición siguiente (con el intervalo adecuado) hasta encontrar el registro coincidente
  - Si llega a un espacio vacío sin encontrar una clave coincidente, los datos no están en la tabla.
  ---
  Afortunadamente, puedes ver que esto puede reducir significativamente la eficiencia de usar una tabla hash para buscar. En el peor de los casos, puede que tengas que inspeccionar cada posición de la matriz hasta encontrar los datos que buscas. Por eso es importante diseñarla para que tenga capacidad extra; con suerte el algoritmo encontrará una posición libre no demasiado lejos del lugar correcto.

  **Encadenamiento (también llamado direccionamiento cerrado)**

  Otra forma de tratar las colisiones es utilizar listas enlazadas. En lugar de almacenar los datos reales en la hash table, se almacena un puntero a una ubicación donde se almacenan los datos. Cada dato se almacena como un nodo con tres atributos

  - El valor de la clave
  - Los datos
  - Un puntero al nodo siguiente

  El primer valor almacenado tendrá un puntero NULO, ya que es el único elemento de la lista. Cuando se produzca una colisión, el puntero del primer nodo en esa ubicación se actualizará para apuntar al nuevo nodo. Esto creará una cadena de nodos cuyas claves se resuelven con el mismo valor.

  Consideremos de nuevo el proceso de añadir los datos con las claves A5RD y B7MF. Los datos con la clave A5RD se almacenan como un nodo de lista enlazada, y un puntero a ese nodo se almacena en la tabla en la posición 74.

  Cuando se realiza el hash de B7MF, se inspecciona el espacio de su valor (también 74) y se comprueba que está ocupado. El puntero del nodo con la clave A5RD se actualiza para apuntar al nodo con la clave B7MF. El nodo para B7MF tendrá su siguiente puntero de nodo establecido a NULO.

  ![Figura_7](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_collision_chain.png)

  **Obtención de datos (encadenamiento)**

  Cuando las colisiones se han tratado mediante encadenamiento, siempre se accederá a los datos a través de una única ubicación en la tabla hash. El proceso para recuperarlos es el siguiente:

  - Hashear la clave para generar el valor del índice.
  - Examinar la posición indexada para obtener el puntero al nodo que encabeza la lista.
  - Examine la clave del nodo para ver si coincide con la clave del dato que busca.
  - Si no es el nodo buscado, siga la lista enlazada hasta encontrar el nodo buscado.
  - Si llega al final de la lista sin encontrar una clave que coincida (o el puntero de la cabeza era nulo), los datos no están en la tabla.

  En el peor de los casos (cuando todas las claves tienen el mismo valor hash), podrías acabar realizando una búsqueda lineal. Es muy importante que tu función hash esté diseñada y probada para minimizar el número de posibles colisiones.

* ## _Rehaciendo_
  
  Con el tiempo, se añadirán y eliminarán elementos de la hash table. Si empieza a llenarse, o un gran número de elementos están en el lugar equivocado, el rendimiento se degradará. Para solucionar este problema se puede utilizar el reflash.

  Cuando se rehace, se crea una nueva tabla (más grande si es necesario). La clave de cada elemento existente se rehará y el elemento se insertará en la nueva tabla. Si la nueva tabla es más grande, habrá que modificar el algoritmo, ya que tendrá que generar una gama más amplia de valores. Rehacer también es una oportunidad para revisar la eficacia general de la función y cómo se gestionan las colisiones.

* ## _Bases de datos y Hash Tables_

  Muchos sistemas de gestión de bases de datos utilizan hash tables para acelerar las búsquedas.

  La siguiente tabla muestra datos sobre algunos alumnos de una clase nocturna.
    |  ID | Nombre | Apellido | Fecha de nacimiento |   
  |---|---|---|---|
  |  2389620010 | John  | Pitt | 19/07/2000
  | 2389620011 | Lisa  | Doe | 07/03/1999
  | 2389620012 | Sam | Dee | 12/12/1954
  | 2389620013 | Sandra | Williams  | 01/01/2006
  | 2389620014 | Pepe | Smith | 12/10/1967
  | 2389620015 | David | Deep | 22/10/2000

  Esta se presenta en una vista fácil de usar y no revela nada sobre la forma en que se almacenan realmente los datos. La clave principal es el número de identificación del alumno, que se puede convertir en valor para proporcionar una ubicación física en la que almacenar los datos dentro de una hash table. La recuperación por ID será muy rápida.

  Los sistemas de bases de datos suelen permitir indexar otros campos (además de la clave principal). Las hash tables facilitan la obtención de datos a gran velocidad a partir de cualquier campo indexado.

* ## _Ejemplo de Hash Table_

  Ahora que ya hemos visto toda la teoría atrás de una hash table podemos llevarla a la práctica utilizando los datos del examen:

  ~~~
  #include <iostream>
  #include <string>
  #include <unordered_map>
  using namespace std;

  struct Arsenal 
  {
    string tipo;
  };

  class GPS 
  {
    public:
            string cap;
            string geo;
            Arsenal* arsenal;

    GPS(string cap, string geo, string tipo) 
    {
        this->cap = cap;
        this->geo = geo;
        this->arsenal = new Arsenal{ tipo };
    }

    ~GPS() 
    {
        delete arsenal;
    }
  };

  // Función hash personalizada para la clase GPS
  struct GPSHasher 
  {
    size_t operator()(const GPS* g) const
    {
        hash <string> stringHasher;
        return stringHasher(g->cap + g->geo + g->arsenal->tipo);
    }
  };

  // Función de igualdad personalizada para la clase GPS
  struct GPSEqual 
  {
    bool operator()(const GPS* lhs, const GPS* rhs) const 
    {
        return lhs->cap == rhs->cap &&
               lhs->geo == rhs->geo &&
               lhs->arsenal->tipo == rhs->arsenal->tipo;
    }
  };

  int main() 
  {

    // Crear la tabla 
    unordered_map<GPS*, int, GPSHasher, GPSEqual> gpsHash;

    // LLenarla con los datos proporcionados
    gpsHash.emplace(new GPS("0", "GPS0", "ab"), 0);
    gpsHash.emplace(new GPS("1", "GPS1", "bc"), 1);
    gpsHash.emplace(new GPS("2", "GPS2", "ac"), 2);
    gpsHash.emplace(new GPS("3", "GPS3", "bcd"), 3);
    gpsHash.emplace(new GPS("4", "GPS4", "acd"), 4);
    gpsHash.emplace(new GPS("5", "GPS5", "bct"), 5);
    gpsHash.emplace(new GPS("6", "GPS6", "act"), 6);
    gpsHash.emplace(new GPS("7", "GPS7", "aaabbct"), 7);
    gpsHash.emplace(new GPS("8", "GPS8", "abbccdt"), 8);
    gpsHash.emplace(new GPS("9", "GPS9", "aaabbcd"), 9);

    // Imprimir los valores almacenados en la tabla
    for (const auto& p : gpsHash) 
    {
      cout << "Clave: (" << p.first->cap << ", " << p.first->geo << ", " << p.first->arsenal->tipo << ") ";

      cout << "Valor: " << p.second << endl;
    }

    //Limpiar la memoria reservada para los objetos GPS
    for (const auto& p : gpsHash) 
    {
        delete p.first;
    }

    return 0;
  }
  ~~~

  Aquí se utiliza la estructura de datos "unordered_map" para almacenar objetos de la clase GPS y sus valores asociados.

  "Unordered_map" es una estructura de datos que se utiliza para almacenar y recuperar elementos de manera eficiente. Es similar a un mapa (map), pero no garantiza un orden específico de los elementos almacenados en la tabla.

  Esta clase GPS representa un objeto GPS y tiene tres atributos: cap (capacidad), geo (geolocalización) y arsenal (objeto Arsenal), también tiene un constructor que toma tres argumentos (cap, geo, tipo) y asigna valores a los atributos de la clase. 
  
  La estructura Arsenal tiene un solo atributo llamado "tipo". 

  Además se tiene un destructor que libera la memoria asignada dinámicamente para el objeto arsenal.

  La función hash personalizada "GPSHasher" se utiliza para calcular un valor hash único para cada objeto GPS.
  
  La función de igualdad personalizada "GPSEqual" se utiliza para comparar dos objetos GPS y determinar si son iguales o no. Ambas funciones se utilizan en la definición de la tabla "gpsHash", que es un unordered_map que almacena punteros a objetos GPS y sus valores asociados.

  Se crea 10 objetos GPS y los almacena en la tabla "gpsHash" utilizando la función "emplace". Luego, recorre la tabla e imprime los valores almacenados en ella junto con las claves asociadas a cada valor.

  Finalmente, libera la memoria asignada dinámicamente para los objetos GPS utilizando un bucle for.


* ## _Otros usos del hashing_

  Has visto que una función hash es un procedimiento que convierte un valor en otro. Esto tiene muchos usos en informática. En este tema se ha visto que la clave de un registro se puede convertir en un dato hash para producir un valor. Otro uso común del hashing es el almacenamiento de contraseñas. Una contraseña nunca debe almacenarse como texto plano; si cayera en las manos equivocadas, alguien podría acceder a valiosos datos.

  El hash de una contraseña es una "función unidireccional". Se trata de una operación fácil de realizar, pero muy difícil -esperemos que casi imposible- de revertir. Actúa como una forma de cifrado, pero no está diseñada para ser descifrada, ya que nadie necesita leer nunca los datos. Cuando se introduce una contraseña por primera vez, se hace un hash y se guarda. Cada vez que el usuario intenta conectarse utilizando la contraseña, el sistema realiza el mismo hash sobre la contraseña que se ha introducido y lo compara con el valor hash almacenado. Si coincide, se autoriza el acceso.

  Si alguien piratea el archivo, sólo podrá obtener el valor. Esto no sirve de nada, ya que el valor original sin hash es necesario para iniciar sesión. Si olvida su contraseña, no se la podrán enviar, ya que sólo existe en forma hash. En su lugar, se le pedirá que cree y guarde una nueva contraseña.

  Su uso en contraseñas no es un método infalible. La mayoría de los algoritmos son bien conocidos y los piratas informáticos pueden utilizar tablas "rainbow" que almacenan valores de todo un diccionario de posibles contraseñas para buscar una coincidencia. Cuando se encuentra una coincidencia, se revela la contraseña asociada.

  Para superar este problema, se puede utilizar un "salt". Un "salt" es un dato aleatorio que se añade a la contraseña antes de aplicar el hash. El valor de "salt" se almacena en texto plano junto con el identificador de usuario y la contraseña cifrada. Cuando un usuario intenta iniciar sesión, se recupera su registro y se añade el valor de "salt" a la contraseña introducida. Los datos combinados se convierten en hash y se comparan con el valor almacenado. Ahora, aunque alguien utilice la misma contraseña para varios sistemas, se almacenarán valores diferentes.
  ```

  

