cmake_minimum_required(VERSION 3.29)
project(Metodos_Numericos_C___Terminal)

# Especificar la versión de C estándar
set(CMAKE_C_STANDARD 17)

# Incluir directorios adicionales si es necesario
include_directories(
        Metodos/Localizacion\ De\ Raices
        Metodos/Sistemas\ de\ Ecuaciones\ Lineales
        Metodos/Ajuste\ de\ Curvas
        Metodos/Integracion
        Metodos/Diferenciacion\ Numerica
)  # Agrega el directorio de encabezados si tienes archivos .h

# Añadir los archivos fuente aquí
set(SOURCES
        main.c                               # Tu archivo principal
        Metodos/Localizacion\ De\ Raices/localizacion_raices.c  # Implementación de localización de raíces
        Metodos/Localizacion\ De\ Raices/localizacion_raices.h  # Implementación de localización de raíces
        Metodos/Sistemas\ de\ Ecuaciones\ Lineales/sistemas_ecuaciones.c  # Implementación del sistema de ecuaciones
        Metodos/Sistemas\ de\ Ecuaciones\ Lineales/sistemas_ecuaciones.h  # Archivo de encabezado del sistema de ecuaciones
        Metodos/Ajuste\ de\ Curvas/ajuste_curvas.c  # Implementación del ajuste de curvas
        Metodos/Ajuste\ de\ Curvas/ajuste_curvas.h  # Archivo de encabezado del ajuste de curvas
        Metodos/Ajuste\ de\ Curvas/interpolacion_spline.c  # Implementación de interpolación
        Metodos/Ajuste\ de\ Curvas/interpolacion_spline.h  # Archivo de encabezado de interpolación
        Metodos/Integracion/integracion_numerica.c  # Implementación de integración numérica
        Metodos/Integracion/integracion_numerica.h  # Archivo de encabezado de integración numérica
        Metodos/Integracion/cuadratura_gauss.c  # Implementación de cuadratura de Gauss
        Metodos/Integracion/cuadratura_gauss.h  # Archivo de encabezado de cuadratura de Gauss
        Metodos/Diferenciacion\ Numerica/Diferenciacion/diferenciacion_numerica.c  # Implementación de sistemas diferenciales
        Metodos/Diferenciacion\ Numerica/Diferenciacion/diferenciacion_numerica.h  # Archivo de encabezado de sistemas diferenciales
        Metodos/Diferenciacion\ Numerica/Ecuaciones\ Diferenciales/edo.c  # Implementación de sistemas diferenciales
        Metodos/Diferenciacion\ Numerica/Ecuaciones\ Diferenciales/edo.h  # Archivo de encabezado de sistemas diferenciales
        Metodos/Diferenciacion\ Numerica/Ecuaciones\ Diferenciales/runge_kutta.c  # Implementación de sistemas diferenciales
        Metodos/Diferenciacion\ Numerica/Ecuaciones\ Diferenciales/runge_kutta.h  # Archivo de encabezado de sistemas diferenciales
        Metodos/Diferenciacion\ Numerica/sistemas_diferenciales.c  # Implementación de sistemas diferenciales
        Metodos/Diferenciacion\ Numerica/sistemas_diferenciales.h  # Archivo de encabezado de sistemas diferenciales
)

# Crear el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES})

# Si necesitas vincular bibliotecas específicas, puedes hacerlo aquí
# Enlaza la biblioteca matemática
#target_link_libraries(Metodos_Numericos_C___Terminal        -lm        pibot        interpolacionLagrange        interpolacionPolinomica        triangulacionLineal        regresionLineal)
