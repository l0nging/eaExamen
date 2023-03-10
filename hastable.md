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
  
* ## _Ingresando datos_
  Para insertar datos, debes utilizar la función hash para generar el índice de la posición en el array que se utilizará para almacenar los datos. Recuerda que la clave debe almacenarse como parte de los datos o junto a ellos.

  Ya has visto un ejemplo de cómo una función hash podría convertir la clave A5RD en el valor hash 74; los datos identificados por esta clave se almacenarán en la posición 74 de la tabla hash.

  | Clave | Funcion | Valor |
  |--|--|--|
  | A5RD | Aplicando la función hash | valor = 74 |

  ![Figura 1](https://isaaccomputerscience.org/api/v3.5.0/api/images/content/computer_science/data_structures_and_algorithms/data_structures/figures/isaac_cs_dsa_data_struct_hash_a5rd.png)
  
  Si tienes una función hash perfecta, es así de fácil. Sin embargo, como descubrirás cuando leas sobre colisiones, las funciones hash rara vez son perfectas.
  
* ## _Ingresando datos_
  

* ## _Ingresando datos_

* ## _Ingresando datos_

* ## _Ingresando datos_

