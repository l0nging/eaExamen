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

* ## __
